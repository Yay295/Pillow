import secrets

import pytest

from PIL import Image

mode_names_not_bgr = (
    "1",
    "L",
    "LA",
    "La",
    "P",
    "PA",
    "F",
    "I",
    "I;16",
    "I;16L",
    "I;16B",
    "I;16N",
    "RGB",
    "RGBA",
    "RGBa",
    "RGBX",
    # Image.frombytes() doesn't work with BGR modes:
    # unknown raw mode for given image mode
    # "BGR;15",
    # "BGR;16",
    # "BGR;24",
    "CMYK",
    "YCbCr",
    "HSV",
    "LAB",
)


def test_setmode():
    im = Image.new("L", (1, 1), 255)
    im.im.setmode("1")
    assert im.im.getpixel((0, 0)) == 255
    im.im.setmode("L")
    assert im.im.getpixel((0, 0)) == 255

    im = Image.new("1", (1, 1), 1)
    im.im.setmode("L")
    assert im.im.getpixel((0, 0)) == 255
    im.im.setmode("1")
    assert im.im.getpixel((0, 0)) == 255

    im = Image.new("RGB", (1, 1), (1, 2, 3))
    im.im.setmode("RGB")
    assert im.im.getpixel((0, 0)) == (1, 2, 3)
    im.im.setmode("RGBA")
    assert im.im.getpixel((0, 0)) == (1, 2, 3, 255)
    im.im.setmode("RGBX")
    assert im.im.getpixel((0, 0)) == (1, 2, 3, 255)
    im.im.setmode("RGB")
    assert im.im.getpixel((0, 0)) == (1, 2, 3)

    with pytest.raises(ValueError):
        im.im.setmode("L")
    with pytest.raises(ValueError):
        im.im.setmode("RGBABCDE")


@pytest.mark.parametrize("mode", mode_names_not_bgr)
def test_equal(mode):
    num_img_bytes = len(Image.new(mode, (2, 2)).tobytes())
    # alternatively, random.randbytes() in Python 3.9
    data = secrets.token_bytes(num_img_bytes)
    img_a = Image.frombytes(mode, (2, 2), data)
    img_b = Image.frombytes(mode, (2, 2), data)
    assert img_a.tobytes() == img_b.tobytes()
    assert img_a.im == img_b.im


# With mode "1" different bytes can map to the same value,
# so we have to be more specific with the values we use.
def test_not_equal_mode_1():
    data_a = data_b = bytes(secrets.choice(b"\x00\xff") for i in range(4))
    while data_a == data_b:
        data_b = bytes(secrets.choice(b"\x00\xff") for i in range(4))
    # We need to use rawmode "1;8" so that each full byte is interpreted as a value
    # instead of the bits in the bytes being interpreted as values.
    img_a = Image.frombytes("1", (2, 2), data_a, "raw", "1;8")
    img_b = Image.frombytes("1", (2, 2), data_b, "raw", "1;8")
    assert img_a.tobytes() != img_b.tobytes()
    assert img_a.im != img_b.im


@pytest.mark.parametrize("mode", [mode for mode in mode_names_not_bgr if mode != "1"])
def test_not_equal(mode):
    num_img_bytes = len(Image.new(mode, (2, 2)).tobytes())
    # alternatively, random.randbytes() in Python 3.9
    data_a = data_b = secrets.token_bytes(num_img_bytes)
    while data_a == data_b:
        data_b = secrets.token_bytes(num_img_bytes)
    img_a = Image.frombytes(mode, (2, 2), data_a)
    img_b = Image.frombytes(mode, (2, 2), data_b)
    assert img_a.tobytes() != img_b.tobytes()
    assert img_a.im != img_b.im


@pytest.mark.parametrize("mode", ("RGB", "YCbCr", "HSV", "LAB"))
def test_equal_three_channels_four_bytes(mode):
    img_a = Image.new(mode, (2, 2))
    img_b = Image.new(mode, (2, 2))
    if mode != "LAB":
        img_a.im.set_internal_pixel_bytes(b"ABC1DEF2GHI3JKL4")
        img_b.im.set_internal_pixel_bytes(b"ABC5DEF6GHI7JKL8")
    else:
        # The "A" and "B" values in LAB images are signed values from -128 to 127,
        # but we store them as unsigned values from 0 to 255.
        img_a.im.set_internal_pixel_bytes(b"A\xc2\xc31D\xc5\xc62G\xc8\xc93J\xcb\xcc4")
        img_b.im.set_internal_pixel_bytes(b"A\xc2\xc35D\xc5\xc66G\xc8\xc97J\xcb\xcc8")
    assert img_a.tobytes() == b"ABCDEFGHIJKL"
    assert img_b.tobytes() == b"ABCDEFGHIJKL"
    assert img_a.im == img_b.im


@pytest.mark.parametrize("mode", ("LA", "La", "PA"))
def test_equal_two_channels_four_bytes(mode):
    img_a = Image.new(mode, (2, 2))
    img_b = Image.new(mode, (2, 2))
    img_a.im.set_internal_pixel_bytes(b"1AB23CD45EF67GH8")
    img_b.im.set_internal_pixel_bytes(b"1IJ23KL45MN67OP8")
    assert img_a.tobytes() == b"12345678"
    assert img_b.tobytes() == b"12345678"
    assert img_a.im == img_b.im
