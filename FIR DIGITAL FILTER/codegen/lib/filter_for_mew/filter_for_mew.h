/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter_for_mew.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 12-Mar-2019 10:34:13
 */

#ifndef FILTER_FOR_MEW_H
#define FILTER_FOR_MEW_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "filter_for_mew_types.h"

/* Function Declarations */
extern void filter_for_mew(short num, const short den[5], const double x[4096],
  double y[4096]);

#endif

/*
 * File trailer for filter_for_mew.h
 *
 * [EOF]
 */
