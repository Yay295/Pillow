from __future__ import annotations

import itertools

import pytest

from PIL import Image


def test_setmode() -> None:
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


@pytest.mark.parametrize("mode", Image.MODES)
def test_equal(mode):
    num_img_bytes = len(Image.new(mode, (2, 2)).tobytes())
    data = bytes(range(ord("A"), ord("A") + num_img_bytes))
    img_a = Image.frombytes(mode, (2, 2), data)
    img_b = Image.frombytes(mode, (2, 2), data)
    assert img_a.tobytes() == img_b.tobytes()
    assert img_a.im == img_b.im


# With mode "1" different bytes can map to the same value,
# so we have to be more specific with the values we use.
@pytest.mark.parametrize(
    "bytes_a, bytes_b",
    itertools.permutations(
        (bytes(x) for x in itertools.product(b"\x00\xff", repeat=4)), 2
    ),
)
def test_not_equal_mode_1(bytes_a, bytes_b):
    # Use rawmode "1;8" so that each full byte is interpreted as a value
    # instead of the bits in the bytes being interpreted as values.
    img_a = Image.frombytes("1", (2, 2), bytes_a, "raw", "1;8")
    img_b = Image.frombytes("1", (2, 2), bytes_b, "raw", "1;8")
    assert img_a.tobytes() != img_b.tobytes()
    assert img_a.im != img_b.im


@pytest.mark.parametrize("mode", [mode for mode in Image.MODES if mode != "1"])
def test_not_equal(mode):
    num_img_bytes = len(Image.new(mode, (2, 2)).tobytes())
    data_a = bytes(range(ord("A"), ord("A") + num_img_bytes))
    data_b = bytes(range(ord("Z"), ord("Z") - num_img_bytes, -1))
    img_a = Image.frombytes(mode, (2, 2), data_a)
    img_b = Image.frombytes(mode, (2, 2), data_b)
    assert img_a.tobytes() != img_b.tobytes()
    assert img_a.im != img_b.im
