struct ImageFormatBandDataType {
    const char dataType; /* 'u' = unsigned integer, 's' = signed integer, 'f' = floating point */
    const unsigned char numBytes;
};

/* Normal bands are treated normally */
/* Alpha bands may be treated specially by some calculations */
/* Extra bands are ignored (this could be used for padding, or maybe storing non-image data) */
enum ImageFormatBandType { BAND_TYPE_NORMAL, BAND_TYPE_ALPHA, BAND_TYPE_EXTRA };

struct ImageFormatBand {
    const char *name; /* "R", "G", "B", "Y", "Cb", "Cr", etc. */
    const struct ImageFormatBandDataType dataType;
    const enum ImageFormatBandType type;
};

struct ImageFormat {
    const char *name; /* Format name ("1", "L", "P", "RGB", "RGBA", "CMYK", "YCbCr", "BGR;xy") */
    const unsigned int numBands; /* Number of bands in this format */
    const unsigned int numBytes; /* Total size in bytes of one pixel in this format */
    const struct ImageFormatBand bands[]; /* Array of bands in this format */
};

#define IMAGE_FORMATS_COUNT 28

extern const struct ImageFormat *IMAGE_FORMATS[IMAGE_FORMATS_COUNT];

const struct ImageFormat *
ImageFormatGet(const char * const name);
