#include "ImPlatform.h"

struct ImageFormatBandDataType {
    const char dataType; /* 'u' = unsigned integer, 's' = signed integer, 'f' = floating point */
    const unsigned char numBytes;
};

// Macro to execute another macro using the correct data type for the given ImageFormatBandDataType.
// TODO: UINT64 and INT64 are not supported because they aren't guaranteed to be defined in "ImPlatform.h".
// Usage: `ImageDataTypeMatch(im->format->bands[i].dataType, OTHER_MACRO_NAME, OTHER_DEFINE)`.
// IFBDT == ImageFormatBandDataType
// ACTION == macro that takes the evaluated type
// ERROR == regular define
#define ImageDataTypeMatch(IFBDT,ACTION,ERROR) { \
    if ((IFBDT).dataType == 'u') {               \
        switch ((IFBDT).numBytes) {              \
            case 1:                              \
                {ACTION(UINT8)}                  \
                break;                           \
            case 2:                              \
                {ACTION(UINT16)}                 \
                break;                           \
            case 4:                              \
                {ACTION(UINT32)}                 \
                break;                           \
            default:                             \
                {ERROR}                          \
        }                                        \
    } else if ((IFBDT).dataType == 's') {        \
        switch ((IFBDT).numBytes) {              \
            case 1:                              \
                {ACTION(INT8)}                   \
                break;                           \
            case 2:                              \
                {ACTION(INT16)}                  \
                break;                           \
            case 4:                              \
                {ACTION(INT32)}                  \
                break;                           \
            default:                             \
                {ERROR}                          \
        }                                        \
    } else if ((IFBDT).dataType == 'f') {        \
        if ((IFBDT).numBytes == 4) {             \
            ACTION(FLOAT32)                      \
        } else if ((IFBDT).numBytes == 8) {      \
            ACTION(FLOAT64)                      \
        } else {                                 \
            ERROR                                \
        }                                        \
    } else {                                     \
        ERROR                                    \
    }                                            \
}

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
