/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_filter_for_mew_api.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 12-Mar-2019 10:34:13
 */

#ifndef _CODER_FILTER_FOR_MEW_API_H
#define _CODER_FILTER_FOR_MEW_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_filter_for_mew_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void filter_for_mew(int16_T num, int16_T den[5], real_T x[4096], real_T
  y[4096]);
extern void filter_for_mew_api(const mxArray * const prhs[3], int32_T nlhs,
  const mxArray *plhs[1]);
extern void filter_for_mew_atexit(void);
extern void filter_for_mew_initialize(void);
extern void filter_for_mew_terminate(void);
extern void filter_for_mew_xil_terminate(void);

#endif

/*
 * File trailer for _coder_filter_for_mew_api.h
 *
 * [EOF]
 */
