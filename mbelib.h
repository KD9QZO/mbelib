/*
 * Copyright (C) 2010 mbelib Author
 * GPG Key ID: 0xEA5EFE2C (9E7A 5527 9CDC EBF7 BF1B  D772 4F98 E863 EA5E FE2C)
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef MBELIB_H_
#define MBELIB_H_


/**
 * \defgroup mbelib mbelib
 *
 * @{
 */


#if (!defined(MBELIB_VERSION) || defined(__DOXGEN__))
/**
 * \brief The version of mbelib, defined as a string
 *
 * \note This can be redefined at compilation time, ie: by passing \c -DMBELIB_VERSION=\"1.3.0a\" in a \c Makefile or a
 *       similar method.
 */
#define MBELIB_VERSION "1.3.0"
#endif


/**
 * \brief Structure to hold all of the parameters for the mbe library
 */
struct mbe_parameters {
	float w0;
	int L;
	int K;
	int Vl[57];
	float Ml[57];
	float log2Ml[57];
	float PHIl[57];
	float PSIl[57];
	float gamma;
	int un;
	int repeat;
};

typedef struct mbe_parameters mbe_parms;


/**
 * \defgroup ecc ECC
 *
 * @{
 */

/*
 * Prototypes from ecc.c
 */
void mbe_checkGolayBlock(long int *block);
int mbe_golay2312(char *in, char *out);
int mbe_hamming1511(char *in, char *out);
int mbe_7100x4400hamming1511(char *in, char *out);

/**
 * @}
 */

/**
 * \defgroup ambe3600x2400 AMBE 3600 baud data 2400 baud voice
 *
 * @{
 */

/*
 * Prototypes from ambe3600x2400.c
 */
int mbe_eccAmbe3600x2400C0(char ambe_fr[4][24]);
int mbe_eccAmbe3600x2400Data(char ambe_fr[4][24], char *ambe_d);
int mbe_decodeAmbe2400Parms(char *ambe_d, mbe_parms *cur_mp, mbe_parms *prev_mp);
void mbe_demodulateAmbe3600x2400Data(char ambe_fr[4][24]);
void mbe_processAmbe2400Dataf(float *aout_buf, int *errs, int *errs2, char *err_str, char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe2400Data(short *aout_buf, int *errs, int *errs2, char *err_str, char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe3600x2400Framef(float *aout_buf, int *errs, int *errs2, char *err_str, char ambe_fr[4][24], char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe3600x2400Frame(short *aout_buf, int *errs, int *errs2, char *err_str, char ambe_fr[4][24], char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);

/**
 * @}
 */

/**
 * \defgroup ambe3600x2450 AMBE 3600 baud data 2450 baud voice
 *
 * @{
 */

/*
 * Prototypes from ambe3600x2450.c
 */
int mbe_eccAmbe3600x2450C0(char ambe_fr[4][24]);
int mbe_eccAmbe3600x2450Data(char ambe_fr[4][24], char *ambe_d);
int mbe_decodeAmbe2450Parms(char *ambe_d, mbe_parms *cur_mp, mbe_parms *prev_mp);
void mbe_demodulateAmbe3600x2450Data(char ambe_fr[4][24]);
void mbe_processAmbe2450Dataf(float *aout_buf, int *errs, int *errs2, char *err_str, char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe2450Data(short *aout_buf, int *errs, int *errs2, char *err_str, char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe3600x2450Framef(float *aout_buf, int *errs, int *errs2, char *err_str, char ambe_fr[4][24], char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processAmbe3600x2450Frame(short *aout_buf, int *errs, int *errs2, char *err_str, char ambe_fr[4][24], char ambe_d[49], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);

/**
 * @}
 */

/**
 * \defgroup imbe7200x4400 IMBE 7200 baud data 4400 baud voice
 *
 * @{
 */

/*
 * Prototypes from imbe7200x4400.c
 */
void mbe_dumpImbe4400Data(char *imbe_d);
void mbe_dumpImbe7200x4400Data(char *imbe_d);
void mbe_dumpImbe7200x4400Frame(char imbe_fr[8][23]);
int mbe_eccImbe7200x4400C0(char imbe_fr[8][23]);
int mbe_eccImbe7200x4400Data(char imbe_fr[8][23], char *imbe_d);
int mbe_decodeImbe4400Parms(char *imbe_d, mbe_parms *cur_mp, mbe_parms *prev_mp);
void mbe_demodulateImbe7200x4400Data(char imbe[8][23]);
void mbe_processImbe4400Dataf(float *aout_buf, int *errs, int *errs2, char *err_str, char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processImbe4400Data(short *aout_buf, int *errs, int *errs2, char *err_str, char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processImbe7200x4400Framef(float *aout_buf, int *errs, int *errs2, char *err_str, char imbe_fr[8][23], char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processImbe7200x4400Frame(short *aout_buf, int *errs, int *errs2, char *err_str, char imbe_fr[8][23], char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);

/**
 * @}
 */

/**
 * \defgroup imbe7100x4400 IMBE 7100 baud data 4400 baud voice
 *
 * @{
 */

/*
 * Prototypes from imbe7100x4400.c
 */
void mbe_dumpImbe7100x4400Data(char *imbe_d);
void mbe_dumpImbe7100x4400Frame(char imbe_fr[7][24]);
int mbe_eccImbe7100x4400C0(char imbe_fr[7][24]);
int mbe_eccImbe7100x4400Data(char imbe_fr[7][24], char *imbe_d);
void mbe_demodulateImbe7100x4400Data(char imbe[7][24]);
void mbe_convertImbe7100to7200(char *imbe_d);
void mbe_processImbe7100x4400Framef(float *aout_buf, int *errs, int *errs2, char *err_str, char imbe_fr[7][24], char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);
void mbe_processImbe7100x4400Frame(short *aout_buf, int *errs, int *errs2, char *err_str, char imbe_fr[7][24], char imbe_d[88], mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced, int uvquality);

/**
 * @}
 */

/**
 * \defgroup mbelib_main mbelib primary functions
 *
 * @{
 */

/*
 * Prototypes from mbelib.c
 */
void mbe_printVersion(char *str);
void mbe_moveMbeParms(mbe_parms *cur_mp, mbe_parms *prev_mp);
void mbe_useLastMbeParms(mbe_parms *cur_mp, mbe_parms *prev_mp);
void mbe_initMbeParms(mbe_parms *cur_mp, mbe_parms *prev_mp, mbe_parms *prev_mp_enhanced);
void mbe_spectralAmpEnhance(mbe_parms *cur_mp);
void mbe_synthesizeSilencef(float *aout_buf);
void mbe_synthesizeSilence(short *aout_buf);
void mbe_synthesizeSpeechf(float *aout_buf, mbe_parms *cur_mp, mbe_parms *prev_mp, int uvquality);
void mbe_synthesizeSpeech(short *aout_buf, mbe_parms *cur_mp, mbe_parms *prev_mp, int uvquality);
void mbe_floattoshort(float *float_buf, short *aout_buf);


/**
 * @}
 */

/**
 * @}
 */


#endif	/* !MBELIB_H_ */
