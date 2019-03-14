/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter_for_mew.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 12-Mar-2019 10:34:13
 */

/* Include Files */
#include <string.h>
#include "filter_for_mew.h"

/* Function Definitions */

/*
 * UNTITLED Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : short num
 *                const short den[5]
 *                const double x[4096]
 *                double y[4096]
 * Return Type  : void
 */
void filter_for_mew(short num, const short den[5], const double x[4096], double
                    y[4096])
{
  double b;
  int a1;
  double a[5];
  int naxpy;
  double as;
  int j;
  int y_tmp;
  b = num;
  for (a1 = 0; a1 < 5; a1++) {
    a[a1] = den[a1];
  }

  a1 = (int)a[0];
  if ((!(a[0] == 0.0)) && (a[0] != 1.0)) {
    b = (double)num / a[0];
    a[1] /= (double)a1;
    a[2] /= (double)a1;
    a[3] /= (double)a1;
    a[4] /= (double)a1;
    a[0] = 1.0;
  }

  memset(&y[0], 0, sizeof(double) << 12);
  for (a1 = 0; a1 < 4096; a1++) {
    y[a1] += x[a1] * b;
    if (4095 - a1 < 4) {
      naxpy = 4094 - a1;
    } else {
      naxpy = 3;
    }

    as = -y[a1];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (a1 + j) + 1;
      y[y_tmp] += as * a[1 + j];
    }
  }
}

/*
 * File trailer for filter_for_mew.c
 *
 * [EOF]
 */
