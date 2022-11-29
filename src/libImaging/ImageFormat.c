#include "ImageFormat.h"

#include <stdlib.h>
#include <string.h>

/* ----------------------------------------- */
/* Band Data Types - ImageFormatBandDataType */
/* ----------------------------------------- */

#define BAND_DATA_TYPE_INT8 { 's', 1 }
#define BAND_DATA_TYPE_UINT8 { 'u', 1 }
#define BAND_DATA_TYPE_INT16 { 's', 2 }
#define BAND_DATA_TYPE_UINT16 { 'u', 2 }
#define BAND_DATA_TYPE_INT32 { 's', 4 }
#define BAND_DATA_TYPE_UINT32 { 'u', 4 }
#define BAND_DATA_TYPE_FLOAT32 { 'f', 4 }


/* ----------------------- */
/* Bands - ImageFormatBand */
/* ----------------------- */

#define BAND_1 { "1", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_L { "L", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_P { "P", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }

#define BAND_F { "F", BAND_DATA_TYPE_FLOAT32, BAND_TYPE_NORMAL }
#define BAND_I16U { "I16U", BAND_DATA_TYPE_UINT16, BAND_TYPE_NORMAL }
#define BAND_I32S { "I32S", BAND_DATA_TYPE_INT32, BAND_TYPE_NORMAL }

#define BAND_R { "R", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_G { "G", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_B { "B", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }

#define BAND_C { "C", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_M { "M", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_Y { "Y", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_K { "K", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }

#define BAND_Cb { "Cb", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_Cr { "Cr", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }

#define BAND_H { "H", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_S { "S", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_V { "V", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }

#define BAND_LAB_L { "L", BAND_DATA_TYPE_UINT8, BAND_TYPE_NORMAL }
#define BAND_LAB_A { "A", BAND_DATA_TYPE_INT8, BAND_TYPE_NORMAL }
#define BAND_LAB_B { "B", BAND_DATA_TYPE_INT8, BAND_TYPE_NORMAL }

#define BAND_A { "A", BAND_DATA_TYPE_UINT8, BAND_TYPE_ALPHA }
// TODO What band type should "a" be?
#define BAND_a { "a", BAND_DATA_TYPE_UINT8, BAND_TYPE_ALPHA }
#define BAND_X { "X", BAND_DATA_TYPE_UINT8, BAND_TYPE_EXTRA }


/* ------------- */
/* Image Formats */
/* ------------- */

const struct ImageFormat FORMAT_1 = { "1", 1, 1, { BAND_1 } };

const struct ImageFormat FORMAT_L = { "L", 1, 1, { BAND_L } };
const struct ImageFormat FORMAT_LA = { "LA", 4, 4, { BAND_L, BAND_X, BAND_X, BAND_A } };
const struct ImageFormat FORMAT_La = { "La", 4, 4, { BAND_L, BAND_X, BAND_X, BAND_a } };

const struct ImageFormat FORMAT_P = { "P", 1, 1, { BAND_P } };
const struct ImageFormat FORMAT_PA = { "PA", 4, 4, { BAND_P, BAND_X, BAND_X, BAND_A } };

const struct ImageFormat FORMAT_F = { "F", 1, 4, { BAND_F } };

const struct ImageFormat FORMAT_I = { "I", 1, 4, { BAND_I32S } };
const struct ImageFormat FORMAT_I16 = { "I;16", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_I16L = { "I;16L", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_I16B = { "I;16B", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_I16N = { "I;16N", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_I32 = { "I;32", 1, 4, { BAND_I32S } };
const struct ImageFormat FORMAT_I32L = { "I;32L", 1, 4, { BAND_I32S } };
const struct ImageFormat FORMAT_I32B = { "I;32B", 1, 4, { BAND_I32S } };
const struct ImageFormat FORMAT_I32N = { "I;32N", 1, 4, { BAND_I32S } };

const struct ImageFormat FORMAT_BGR15 = { "BGR;15", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_BGR16 = { "BGR;16", 1, 2, { BAND_I16U } };
const struct ImageFormat FORMAT_BGR24 = { "BGR;24", 3, 3, { BAND_B, BAND_G, BAND_R } };
const struct ImageFormat FORMAT_BGR32 = { "BGR;32", 4, 4, { BAND_B, BAND_G, BAND_R } };

const struct ImageFormat FORMAT_RGB = { "RGB", 4, 4, { BAND_R, BAND_G, BAND_B, BAND_X } };
const struct ImageFormat FORMAT_RGBA = { "RGBA", 4, 4, { BAND_R, BAND_G, BAND_B, BAND_A } };
const struct ImageFormat FORMAT_RGBa = { "RGBa", 4, 4, { BAND_R, BAND_G, BAND_B, BAND_a } };
const struct ImageFormat FORMAT_RGBX = { "RGBX", 4, 4, { BAND_R, BAND_G, BAND_B, BAND_X } };

const struct ImageFormat FORMAT_CMYK = { "CMYK", 4, 4, { BAND_C, BAND_M, BAND_Y, BAND_K } };
const struct ImageFormat FORMAT_YCbCr = { "YCbCr", 4, 4, { BAND_Y, BAND_Cb, BAND_Cr, BAND_X } };
const struct ImageFormat FORMAT_HSV = { "HSV", 4, 4, { BAND_H, BAND_S, BAND_V, BAND_X } };
const struct ImageFormat FORMAT_LAB = { "LAB", 4, 4, { BAND_LAB_L, BAND_LAB_A, BAND_LAB_B, BAND_X } };

const struct ImageFormat *IMAGE_FORMATS[IMAGE_FORMATS_COUNT] = {
    &FORMAT_1,
    &FORMAT_L,
    &FORMAT_LA,
    &FORMAT_La,
    &FORMAT_P,
    &FORMAT_PA,
    &FORMAT_F,
    &FORMAT_I,
    &FORMAT_I16,
    &FORMAT_I16L,
    &FORMAT_I16B,
    &FORMAT_I16N,
    &FORMAT_I32,
    &FORMAT_I32L,
    &FORMAT_I32B,
    &FORMAT_I32N,
    &FORMAT_BGR15,
    &FORMAT_BGR16,
    &FORMAT_BGR24,
    &FORMAT_BGR32,
    &FORMAT_RGB,
    &FORMAT_RGBA,
    &FORMAT_RGBa,
    &FORMAT_RGBX,
    &FORMAT_CMYK,
    &FORMAT_YCbCr,
    &FORMAT_HSV,
    &FORMAT_LAB
};


/* --------- */
/* Functions */
/* --------- */

const struct ImageFormat *
ImageFormatGet(const char * const name) {
    int i;
    for (i = 0; i < IMAGE_FORMATS_COUNT; i++) {
        if (strcmp(name, IMAGE_FORMATS[i]->name) == 0) {
            return IMAGE_FORMATS[i];
        }
    }
    return NULL;
}
