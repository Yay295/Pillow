/*
 * The Python Imaging Library
 * $Id$
 *
 * fill image with constant pixel value
 *
 * history:
 * 95-11-26 fl moved from Imaging.c
 * 96-05-17 fl added radial fill, renamed wedge to linear
 * 98-06-23 fl changed ImageFill signature
 *
 * Copyright (c) Secret Labs AB 1997-98.  All rights reserved.
 * Copyright (c) Fredrik Lundh 1995-96.
 *
 * See the README file for information on usage and redistribution.
 */

#include "Imaging.h"

#include "math.h"

Imaging
ImagingFill(Imaging im, const void *colour) {
    int x, y;

    // Check if every byte in the given colour is the same.
    // If they are, we can use memset.
    UINT8 allSame = 1;
    const UINT8 b = *(UINT8 *)colour;
    for (x = 1; x < im->format->numBytes; ++x) {
        if (((UINT8 *)colour)[x] != b) {
            allSame = 0;
            break;
        }
    }

    ImagingSectionCookie cookie;
    ImagingSectionEnter(&cookie);
    if (allSame) {
        for (y = 0; y < im->ysize; y++) {
            memset(im->image[y], b, im->linesize);
        }
    } else {
        for (y = 0; y < im->ysize; ++y) {
            UINT8 *out = (UINT8 *)im->image[y];
            for (x = 0; x < im->xsize; ++x) {
                memcpy(out, colour, im->format->numBytes);
                out += im->format->numBytes;
            }
        }
    }
    ImagingSectionLeave(&cookie);

    return im;
}

Imaging
ImagingFillLinearGradient(const struct ImageFormat *format) {
    if (format->numBands != 1) {
        return (Imaging)ImagingError_ModeError();
    }

    const Imaging im = ImagingNewDirty(format->name, 256, 256);
    if (!im) {
        return NULL;
    }

    int x, y;

#define ACTION(TYPE) {                                \
    if (sizeof(TYPE) == 1) {                          \
        for (y = 0; y < 256; y++) {                   \
            memset(im->image[y], (TYPE)y, 256);       \
        }                                             \
    } else {                                          \
        for (y = 0; y < 256; y++) {                   \
            for (x = 0; x < 256; x++) {               \
                ((TYPE **)im->image)[y][x] = (TYPE)y; \
            }                                         \
        }                                             \
    }                                                 \
}

#define ERROR return (Imaging)ImagingError_BandDataTypeError();

    ImageDataTypeMatch(im->format->bands[0].dataType, ACTION, ERROR);

#undef ERROR
#undef ACTION

    return im;
}

Imaging
ImagingFillRadialGradient(const struct ImageFormat *format) {
    if (format->numBands != 1) {
        return (Imaging)ImagingError_ModeError();
    }

    const Imaging im = ImagingNewDirty(format->name, 256, 256);
    if (!im) {
        return NULL;
    }

    int x, y;

#define ACTION(TYPE) {                                                        \
    for (y = 0; y < 256; y++) {                                               \
        for (x = 0; x < 256; x++) {                                           \
            const UINT8 d = (UINT8)sqrt(                                      \
                (double)((x - 128) * (x - 128) + (y - 128) * (y - 128)) * 2.0 \
            );                                                                \
            ((TYPE **)im->image)[y][x] = d;                                   \
        }                                                                     \
    }                                                                         \
    /* The first value gets calculated as 256, so we need to adjust it */     \
    ((TYPE **)im->image)[0][0] = 255;                                         \
}

#define ERROR return (Imaging)ImagingError_BandDataTypeError();

    ImageDataTypeMatch(im->format->bands[0].dataType, ACTION, ERROR);

#undef ERROR
#undef ACTION

    return im;
}
