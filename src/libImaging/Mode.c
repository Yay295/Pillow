#include "Mode.h"
#include <string.h>


#define CREATE_MODE(TYPE, NAME, INIT) \
const TYPE IMAGING_##NAME##_VAL = INIT;\
const TYPE * const IMAGING_##NAME = &IMAGING_##NAME##_VAL;


CREATE_MODE(Mode, MODE_1, {"1"})
CREATE_MODE(Mode, MODE_CMYK, {"CMYK"})
CREATE_MODE(Mode, MODE_F, {"F"})
CREATE_MODE(Mode, MODE_HSV, {"HSV"})
CREATE_MODE(Mode, MODE_I, {"I"})
CREATE_MODE(Mode, MODE_L, {"L"})
CREATE_MODE(Mode, MODE_LA, {"LA"})
CREATE_MODE(Mode, MODE_LAB, {"LAB"})
CREATE_MODE(Mode, MODE_La, {"La"})
CREATE_MODE(Mode, MODE_P, {"P"})
CREATE_MODE(Mode, MODE_PA, {"PA"})
CREATE_MODE(Mode, MODE_RGB, {"RGB"})
CREATE_MODE(Mode, MODE_RGBA, {"RGBA"})
CREATE_MODE(Mode, MODE_RGBX, {"RGBX"})
CREATE_MODE(Mode, MODE_RGBa, {"RGBa"})
CREATE_MODE(Mode, MODE_YCbCr, {"YCbCr"})

CREATE_MODE(Mode, MODE_BGR_15, {"BGR;15"})
CREATE_MODE(Mode, MODE_BGR_16, {"BGR;16"})
CREATE_MODE(Mode, MODE_BGR_24, {"BGR;24"})

CREATE_MODE(Mode, MODE_I_16, {"I;16"})
CREATE_MODE(Mode, MODE_I_16L, {"I;16L"})
CREATE_MODE(Mode, MODE_I_16B, {"I;16B"})
CREATE_MODE(Mode, MODE_I_16N, {"I;16N"})
CREATE_MODE(Mode, MODE_I_32L, {"I;32L"})
CREATE_MODE(Mode, MODE_I_32B, {"I;32B"})

const Mode * const MODES[] = {
    IMAGING_MODE_1,
    IMAGING_MODE_CMYK,
    IMAGING_MODE_F,
    IMAGING_MODE_HSV,
    IMAGING_MODE_I,
    IMAGING_MODE_L,
    IMAGING_MODE_LA,
    IMAGING_MODE_LAB,
    IMAGING_MODE_La,
    IMAGING_MODE_P,
    IMAGING_MODE_PA,
    IMAGING_MODE_RGB,
    IMAGING_MODE_RGBA,
    IMAGING_MODE_RGBX,
    IMAGING_MODE_RGBa,
    IMAGING_MODE_YCbCr,

    IMAGING_MODE_BGR_15,
    IMAGING_MODE_BGR_16,
    IMAGING_MODE_BGR_24,

    IMAGING_MODE_I_16,
    IMAGING_MODE_I_16L,
    IMAGING_MODE_I_16B,
    IMAGING_MODE_I_16N,
    IMAGING_MODE_I_32L,
    IMAGING_MODE_I_32B,

    NULL
};

const Mode * findMode(const char * const name) {
    int i = 0;
    const Mode * mode;
    while ((mode = MODES[i++]) != NULL) {
        if (!strcmp(mode->name, name)) {
            return mode;
        }
    }
    return NULL;
}


// Alias all of the modes as rawmodes so that the addresses are the same.
#define ALIAS_MODE_AS_RAWMODE(NAME) const RawMode * const IMAGING_RAWMODE_##NAME = (const RawMode * const)IMAGING_MODE_##NAME;
ALIAS_MODE_AS_RAWMODE(1)
ALIAS_MODE_AS_RAWMODE(CMYK)
ALIAS_MODE_AS_RAWMODE(F)
ALIAS_MODE_AS_RAWMODE(HSV)
ALIAS_MODE_AS_RAWMODE(I)
ALIAS_MODE_AS_RAWMODE(L)
ALIAS_MODE_AS_RAWMODE(LA)
ALIAS_MODE_AS_RAWMODE(LAB)
ALIAS_MODE_AS_RAWMODE(La)
ALIAS_MODE_AS_RAWMODE(P)
ALIAS_MODE_AS_RAWMODE(PA)
ALIAS_MODE_AS_RAWMODE(RGB)
ALIAS_MODE_AS_RAWMODE(RGBA)
ALIAS_MODE_AS_RAWMODE(RGBX)
ALIAS_MODE_AS_RAWMODE(RGBa)
ALIAS_MODE_AS_RAWMODE(YCbCr)

ALIAS_MODE_AS_RAWMODE(BGR_15)
ALIAS_MODE_AS_RAWMODE(BGR_16)
ALIAS_MODE_AS_RAWMODE(BGR_24)

ALIAS_MODE_AS_RAWMODE(I_16)
ALIAS_MODE_AS_RAWMODE(I_16L)
ALIAS_MODE_AS_RAWMODE(I_16B)
ALIAS_MODE_AS_RAWMODE(I_16N)
ALIAS_MODE_AS_RAWMODE(I_32L)
ALIAS_MODE_AS_RAWMODE(I_32B)

CREATE_MODE(RawMode, RAWMODE_1_8, {"1;8"})
CREATE_MODE(RawMode, RAWMODE_1_I, {"1;I"})
CREATE_MODE(RawMode, RAWMODE_1_IR, {"1;IR"})
CREATE_MODE(RawMode, RAWMODE_1_R, {"1;R"})
CREATE_MODE(RawMode, RAWMODE_A, {"A"})
CREATE_MODE(RawMode, RAWMODE_ABGR, {"ABGR"})
CREATE_MODE(RawMode, RAWMODE_ARGB, {"ARGB"})
CREATE_MODE(RawMode, RAWMODE_A_16B, {"A;16B"})
CREATE_MODE(RawMode, RAWMODE_A_16L, {"A;16L"})
CREATE_MODE(RawMode, RAWMODE_A_16N, {"A;16N"})
CREATE_MODE(RawMode, RAWMODE_B, {"B"})
CREATE_MODE(RawMode, RAWMODE_BGAR, {"BGAR"})
CREATE_MODE(RawMode, RAWMODE_BGR, {"BGR"})
CREATE_MODE(RawMode, RAWMODE_BGRA, {"BGRA"})
CREATE_MODE(RawMode, RAWMODE_BGRA_15, {"BGRA;15"})
CREATE_MODE(RawMode, RAWMODE_BGRA_15Z, {"BGRA;15Z"})
CREATE_MODE(RawMode, RAWMODE_BGRA_16B, {"BGRA;16B"})
CREATE_MODE(RawMode, RAWMODE_BGRA_16L, {"BGRA;16L"})
CREATE_MODE(RawMode, RAWMODE_BGRX, {"BGRX"})
CREATE_MODE(RawMode, RAWMODE_BGR_5, {"BGR;5"})
CREATE_MODE(RawMode, RAWMODE_BGRa, {"BGRa"})
CREATE_MODE(RawMode, RAWMODE_BGXR, {"BGXR"})
CREATE_MODE(RawMode, RAWMODE_B_16B, {"B;16B"})
CREATE_MODE(RawMode, RAWMODE_B_16L, {"B;16L"})
CREATE_MODE(RawMode, RAWMODE_B_16N, {"B;16N"})
CREATE_MODE(RawMode, RAWMODE_C, {"C"})
CREATE_MODE(RawMode, RAWMODE_CMYKX, {"CMYKX"})
CREATE_MODE(RawMode, RAWMODE_CMYKXX, {"CMYKXX"})
CREATE_MODE(RawMode, RAWMODE_CMYK_16B, {"CMYK;16B"})
CREATE_MODE(RawMode, RAWMODE_CMYK_16L, {"CMYK;16L"})
CREATE_MODE(RawMode, RAWMODE_CMYK_16N, {"CMYK;16N"})
CREATE_MODE(RawMode, RAWMODE_CMYK_I, {"CMYK;I"})
CREATE_MODE(RawMode, RAWMODE_CMYK_L, {"CMYK;L"})
CREATE_MODE(RawMode, RAWMODE_C_I, {"C;I"})
CREATE_MODE(RawMode, RAWMODE_Cb, {"Cb"})
CREATE_MODE(RawMode, RAWMODE_Cr, {"Cr"})
CREATE_MODE(RawMode, RAWMODE_F_16, {"F;16"})
CREATE_MODE(RawMode, RAWMODE_F_16B, {"F;16B"})
CREATE_MODE(RawMode, RAWMODE_F_16BS, {"F;16BS"})
CREATE_MODE(RawMode, RAWMODE_F_16N, {"F;16N"})
CREATE_MODE(RawMode, RAWMODE_F_16NS, {"F;16NS"})
CREATE_MODE(RawMode, RAWMODE_F_16S, {"F;16S"})
CREATE_MODE(RawMode, RAWMODE_F_32, {"F;32"})
CREATE_MODE(RawMode, RAWMODE_F_32B, {"F;32B"})
CREATE_MODE(RawMode, RAWMODE_F_32BF, {"F;32BF"})
CREATE_MODE(RawMode, RAWMODE_F_32BS, {"F;32BS"})
CREATE_MODE(RawMode, RAWMODE_F_32F, {"F;32F"})
CREATE_MODE(RawMode, RAWMODE_F_32N, {"F;32N"})
CREATE_MODE(RawMode, RAWMODE_F_32NF, {"F;32NF"})
CREATE_MODE(RawMode, RAWMODE_F_32NS, {"F;32NS"})
CREATE_MODE(RawMode, RAWMODE_F_32S, {"F;32S"})
CREATE_MODE(RawMode, RAWMODE_F_64BF, {"F;64BF"})
CREATE_MODE(RawMode, RAWMODE_F_64F, {"F;64F"})
CREATE_MODE(RawMode, RAWMODE_F_64NF, {"F;64NF"})
CREATE_MODE(RawMode, RAWMODE_F_8, {"F;8"})
CREATE_MODE(RawMode, RAWMODE_F_8S, {"F;8S"})
CREATE_MODE(RawMode, RAWMODE_G, {"G"})
CREATE_MODE(RawMode, RAWMODE_G_16B, {"G;16B"})
CREATE_MODE(RawMode, RAWMODE_G_16L, {"G;16L"})
CREATE_MODE(RawMode, RAWMODE_G_16N, {"G;16N"})
CREATE_MODE(RawMode, RAWMODE_H, {"H"})
CREATE_MODE(RawMode, RAWMODE_I_12, {"I;12"})
CREATE_MODE(RawMode, RAWMODE_I_16BS, {"I;16BS"})
CREATE_MODE(RawMode, RAWMODE_I_16NS, {"I;16NS"})
CREATE_MODE(RawMode, RAWMODE_I_16R, {"I;16R"})
CREATE_MODE(RawMode, RAWMODE_I_16S, {"I;16S"})
CREATE_MODE(RawMode, RAWMODE_I_32, {"I;32"})
CREATE_MODE(RawMode, RAWMODE_I_32BS, {"I;32BS"})
CREATE_MODE(RawMode, RAWMODE_I_32N, {"I;32N"})
CREATE_MODE(RawMode, RAWMODE_I_32NS, {"I;32NS"})
CREATE_MODE(RawMode, RAWMODE_I_32S, {"I;32S"})
CREATE_MODE(RawMode, RAWMODE_I_8, {"I;8"})
CREATE_MODE(RawMode, RAWMODE_I_8S, {"I;8S"})
CREATE_MODE(RawMode, RAWMODE_K, {"K"})
CREATE_MODE(RawMode, RAWMODE_K_I, {"K;I"})
CREATE_MODE(RawMode, RAWMODE_LA_16B, {"LA;16B"})
CREATE_MODE(RawMode, RAWMODE_LA_L, {"LA;L"})
CREATE_MODE(RawMode, RAWMODE_L_16, {"L;16"})
CREATE_MODE(RawMode, RAWMODE_L_16B, {"L;16B"})
CREATE_MODE(RawMode, RAWMODE_L_2, {"L;2"})
CREATE_MODE(RawMode, RAWMODE_L_2I, {"L;2I"})
CREATE_MODE(RawMode, RAWMODE_L_2IR, {"L;2IR"})
CREATE_MODE(RawMode, RAWMODE_L_2R, {"L;2R"})
CREATE_MODE(RawMode, RAWMODE_L_4, {"L;4"})
CREATE_MODE(RawMode, RAWMODE_L_4I, {"L;4I"})
CREATE_MODE(RawMode, RAWMODE_L_4IR, {"L;4IR"})
CREATE_MODE(RawMode, RAWMODE_L_4R, {"L;4R"})
CREATE_MODE(RawMode, RAWMODE_L_I, {"L;I"})
CREATE_MODE(RawMode, RAWMODE_L_R, {"L;R"})
CREATE_MODE(RawMode, RAWMODE_M, {"M"})
CREATE_MODE(RawMode, RAWMODE_M_I, {"M;I"})
CREATE_MODE(RawMode, RAWMODE_PA_L, {"PA;L"})
CREATE_MODE(RawMode, RAWMODE_PX, {"PX"})
CREATE_MODE(RawMode, RAWMODE_P_1, {"P;1"})
CREATE_MODE(RawMode, RAWMODE_P_2, {"P;2"})
CREATE_MODE(RawMode, RAWMODE_P_2L, {"P;2L"})
CREATE_MODE(RawMode, RAWMODE_P_4, {"P;4"})
CREATE_MODE(RawMode, RAWMODE_P_4L, {"P;4L"})
CREATE_MODE(RawMode, RAWMODE_P_R, {"P;R"})
CREATE_MODE(RawMode, RAWMODE_R, {"R"})
CREATE_MODE(RawMode, RAWMODE_RGBAX, {"RGBAX"})
CREATE_MODE(RawMode, RAWMODE_RGBAXX, {"RGBAXX"})
CREATE_MODE(RawMode, RAWMODE_RGBA_15, {"RGBA;15"})
CREATE_MODE(RawMode, RAWMODE_RGBA_16B, {"RGBA;16B"})
CREATE_MODE(RawMode, RAWMODE_RGBA_16L, {"RGBA;16L"})
CREATE_MODE(RawMode, RAWMODE_RGBA_16N, {"RGBA;16N"})
CREATE_MODE(RawMode, RAWMODE_RGBA_4B, {"RGBA;4B"})
CREATE_MODE(RawMode, RAWMODE_RGBA_I, {"RGBA;I"})
CREATE_MODE(RawMode, RAWMODE_RGBA_L, {"RGBA;L"})
CREATE_MODE(RawMode, RAWMODE_RGBXX, {"RGBXX"})
CREATE_MODE(RawMode, RAWMODE_RGBXXX, {"RGBXXX"})
CREATE_MODE(RawMode, RAWMODE_RGBX_16B, {"RGBX;16B"})
CREATE_MODE(RawMode, RAWMODE_RGBX_16L, {"RGBX;16L"})
CREATE_MODE(RawMode, RAWMODE_RGBX_16N, {"RGBX;16N"})
CREATE_MODE(RawMode, RAWMODE_RGBX_L, {"RGBX;L"})
CREATE_MODE(RawMode, RAWMODE_RGB_15, {"RGB;15"})
CREATE_MODE(RawMode, RAWMODE_RGB_16, {"RGB;16"})
CREATE_MODE(RawMode, RAWMODE_RGB_16B, {"RGB;16B"})
CREATE_MODE(RawMode, RAWMODE_RGB_16L, {"RGB;16L"})
CREATE_MODE(RawMode, RAWMODE_RGB_16N, {"RGB;16N"})
CREATE_MODE(RawMode, RAWMODE_RGB_4B, {"RGB;4B"})
CREATE_MODE(RawMode, RAWMODE_RGB_L, {"RGB;L"})
CREATE_MODE(RawMode, RAWMODE_RGB_R, {"RGB;R"})
CREATE_MODE(RawMode, RAWMODE_RGBaX, {"RGBaX"})
CREATE_MODE(RawMode, RAWMODE_RGBaXX, {"RGBaXX"})
CREATE_MODE(RawMode, RAWMODE_RGBa_16B, {"RGBa;16B"})
CREATE_MODE(RawMode, RAWMODE_RGBa_16L, {"RGBa;16L"})
CREATE_MODE(RawMode, RAWMODE_RGBa_16N, {"RGBa;16N"})
CREATE_MODE(RawMode, RAWMODE_R_16B, {"R;16B"})
CREATE_MODE(RawMode, RAWMODE_R_16L, {"R;16L"})
CREATE_MODE(RawMode, RAWMODE_R_16N, {"R;16N"})
CREATE_MODE(RawMode, RAWMODE_S, {"S"})
CREATE_MODE(RawMode, RAWMODE_V, {"V"})
CREATE_MODE(RawMode, RAWMODE_X, {"X"})
CREATE_MODE(RawMode, RAWMODE_XBGR, {"XBGR"})
CREATE_MODE(RawMode, RAWMODE_XRGB, {"XRGB"})
CREATE_MODE(RawMode, RAWMODE_Y, {"Y"})
CREATE_MODE(RawMode, RAWMODE_YCCA_P, {"YCCA;P"})
CREATE_MODE(RawMode, RAWMODE_YCC_P, {"YCC;P"})
CREATE_MODE(RawMode, RAWMODE_YCbCrK, {"YCbCrK"})
CREATE_MODE(RawMode, RAWMODE_YCbCrX, {"YCbCrX"})
CREATE_MODE(RawMode, RAWMODE_YCbCr_L, {"YCbCr;L"})
CREATE_MODE(RawMode, RAWMODE_Y_I, {"Y;I"})
CREATE_MODE(RawMode, RAWMODE_aBGR, {"aBGR"})
CREATE_MODE(RawMode, RAWMODE_aRGB, {"aRGB"})

const RawMode * const RAWMODES[] = {
    IMAGING_RAWMODE_1,
    IMAGING_RAWMODE_CMYK,
    IMAGING_RAWMODE_F,
    IMAGING_RAWMODE_HSV,
    IMAGING_RAWMODE_I,
    IMAGING_RAWMODE_L,
    IMAGING_RAWMODE_LA,
    IMAGING_RAWMODE_LAB,
    IMAGING_RAWMODE_La,
    IMAGING_RAWMODE_P,
    IMAGING_RAWMODE_PA,
    IMAGING_RAWMODE_RGB,
    IMAGING_RAWMODE_RGBA,
    IMAGING_RAWMODE_RGBX,
    IMAGING_RAWMODE_RGBa,
    IMAGING_RAWMODE_YCbCr,

    IMAGING_RAWMODE_BGR_15,
    IMAGING_RAWMODE_BGR_16,
    IMAGING_RAWMODE_BGR_24,

    IMAGING_RAWMODE_I_16,
    IMAGING_RAWMODE_I_16L,
    IMAGING_RAWMODE_I_16B,
    IMAGING_RAWMODE_I_16N,
    IMAGING_RAWMODE_I_32L,
    IMAGING_RAWMODE_I_32B,

    IMAGING_RAWMODE_1_8,
    IMAGING_RAWMODE_1_I,
    IMAGING_RAWMODE_1_IR,
    IMAGING_RAWMODE_1_R,
    IMAGING_RAWMODE_A,
    IMAGING_RAWMODE_ABGR,
    IMAGING_RAWMODE_ARGB,
    IMAGING_RAWMODE_A_16B,
    IMAGING_RAWMODE_A_16L,
    IMAGING_RAWMODE_A_16N,
    IMAGING_RAWMODE_B,
    IMAGING_RAWMODE_BGAR,
    IMAGING_RAWMODE_BGR,
    IMAGING_RAWMODE_BGRA,
    IMAGING_RAWMODE_BGRA_15,
    IMAGING_RAWMODE_BGRA_15Z,
    IMAGING_RAWMODE_BGRA_16B,
    IMAGING_RAWMODE_BGRA_16L,
    IMAGING_RAWMODE_BGRX,
    IMAGING_RAWMODE_BGR_5,
    IMAGING_RAWMODE_BGRa,
    IMAGING_RAWMODE_BGXR,
    IMAGING_RAWMODE_B_16B,
    IMAGING_RAWMODE_B_16L,
    IMAGING_RAWMODE_B_16N,
    IMAGING_RAWMODE_C,
    IMAGING_RAWMODE_CMYKX,
    IMAGING_RAWMODE_CMYKXX,
    IMAGING_RAWMODE_CMYK_16B,
    IMAGING_RAWMODE_CMYK_16L,
    IMAGING_RAWMODE_CMYK_16N,
    IMAGING_RAWMODE_CMYK_I,
    IMAGING_RAWMODE_CMYK_L,
    IMAGING_RAWMODE_C_I,
    IMAGING_RAWMODE_Cb,
    IMAGING_RAWMODE_Cr,
    IMAGING_RAWMODE_F_16,
    IMAGING_RAWMODE_F_16B,
    IMAGING_RAWMODE_F_16BS,
    IMAGING_RAWMODE_F_16N,
    IMAGING_RAWMODE_F_16NS,
    IMAGING_RAWMODE_F_16S,
    IMAGING_RAWMODE_F_32,
    IMAGING_RAWMODE_F_32B,
    IMAGING_RAWMODE_F_32BF,
    IMAGING_RAWMODE_F_32BS,
    IMAGING_RAWMODE_F_32F,
    IMAGING_RAWMODE_F_32N,
    IMAGING_RAWMODE_F_32NF,
    IMAGING_RAWMODE_F_32NS,
    IMAGING_RAWMODE_F_32S,
    IMAGING_RAWMODE_F_64BF,
    IMAGING_RAWMODE_F_64F,
    IMAGING_RAWMODE_F_64NF,
    IMAGING_RAWMODE_F_8,
    IMAGING_RAWMODE_F_8S,
    IMAGING_RAWMODE_G,
    IMAGING_RAWMODE_G_16B,
    IMAGING_RAWMODE_G_16L,
    IMAGING_RAWMODE_G_16N,
    IMAGING_RAWMODE_H,
    IMAGING_RAWMODE_I_12,
    IMAGING_RAWMODE_I_16BS,
    IMAGING_RAWMODE_I_16NS,
    IMAGING_RAWMODE_I_16R,
    IMAGING_RAWMODE_I_16S,
    IMAGING_RAWMODE_I_32,
    IMAGING_RAWMODE_I_32BS,
    IMAGING_RAWMODE_I_32N,
    IMAGING_RAWMODE_I_32NS,
    IMAGING_RAWMODE_I_32S,
    IMAGING_RAWMODE_I_8,
    IMAGING_RAWMODE_I_8S,
    IMAGING_RAWMODE_K,
    IMAGING_RAWMODE_K_I,
    IMAGING_RAWMODE_LA_16B,
    IMAGING_RAWMODE_LA_L,
    IMAGING_RAWMODE_L_16,
    IMAGING_RAWMODE_L_16B,
    IMAGING_RAWMODE_L_2,
    IMAGING_RAWMODE_L_2I,
    IMAGING_RAWMODE_L_2IR,
    IMAGING_RAWMODE_L_2R,
    IMAGING_RAWMODE_L_4,
    IMAGING_RAWMODE_L_4I,
    IMAGING_RAWMODE_L_4IR,
    IMAGING_RAWMODE_L_4R,
    IMAGING_RAWMODE_L_I,
    IMAGING_RAWMODE_L_R,
    IMAGING_RAWMODE_M,
    IMAGING_RAWMODE_M_I,
    IMAGING_RAWMODE_PA_L,
    IMAGING_RAWMODE_PX,
    IMAGING_RAWMODE_P_1,
    IMAGING_RAWMODE_P_2,
    IMAGING_RAWMODE_P_2L,
    IMAGING_RAWMODE_P_4,
    IMAGING_RAWMODE_P_4L,
    IMAGING_RAWMODE_P_R,
    IMAGING_RAWMODE_R,
    IMAGING_RAWMODE_RGBAX,
    IMAGING_RAWMODE_RGBAXX,
    IMAGING_RAWMODE_RGBA_15,
    IMAGING_RAWMODE_RGBA_16B,
    IMAGING_RAWMODE_RGBA_16L,
    IMAGING_RAWMODE_RGBA_16N,
    IMAGING_RAWMODE_RGBA_4B,
    IMAGING_RAWMODE_RGBA_I,
    IMAGING_RAWMODE_RGBA_L,
    IMAGING_RAWMODE_RGBXX,
    IMAGING_RAWMODE_RGBXXX,
    IMAGING_RAWMODE_RGBX_16B,
    IMAGING_RAWMODE_RGBX_16L,
    IMAGING_RAWMODE_RGBX_16N,
    IMAGING_RAWMODE_RGBX_L,
    IMAGING_RAWMODE_RGB_15,
    IMAGING_RAWMODE_RGB_16,
    IMAGING_RAWMODE_RGB_16B,
    IMAGING_RAWMODE_RGB_16L,
    IMAGING_RAWMODE_RGB_16N,
    IMAGING_RAWMODE_RGB_4B,
    IMAGING_RAWMODE_RGB_L,
    IMAGING_RAWMODE_RGB_R,
    IMAGING_RAWMODE_RGBaX,
    IMAGING_RAWMODE_RGBaXX,
    IMAGING_RAWMODE_RGBa_16B,
    IMAGING_RAWMODE_RGBa_16L,
    IMAGING_RAWMODE_RGBa_16N,
    IMAGING_RAWMODE_R_16B,
    IMAGING_RAWMODE_R_16L,
    IMAGING_RAWMODE_R_16N,
    IMAGING_RAWMODE_S,
    IMAGING_RAWMODE_V,
    IMAGING_RAWMODE_X,
    IMAGING_RAWMODE_XBGR,
    IMAGING_RAWMODE_XRGB,
    IMAGING_RAWMODE_Y,
    IMAGING_RAWMODE_YCCA_P,
    IMAGING_RAWMODE_YCC_P,
    IMAGING_RAWMODE_YCbCrK,
    IMAGING_RAWMODE_YCbCrX,
    IMAGING_RAWMODE_YCbCr_L,
    IMAGING_RAWMODE_Y_I,
    IMAGING_RAWMODE_aBGR,
    IMAGING_RAWMODE_aRGB,

    NULL
};

const RawMode * findRawMode(const char * const name) {
    int i = 0;
    const RawMode * rawmode;
    while ((rawmode = RAWMODES[i++]) != NULL) {
        const RawMode * const rawmode = RAWMODES[i];
        if (!strcmp(rawmode->name, name)) {
            return rawmode;
        }
    }
    return NULL;
}

int isModeI16(const Mode * const mode) {
    return mode == IMAGING_MODE_I_16
    || mode == IMAGING_MODE_I_16L
    || mode == IMAGING_MODE_I_16B
    || mode == IMAGING_MODE_I_16N;
}
