/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 12-Mar-2019 10:34:13
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "filter_for_mew.h"
#include "main.h"
#include "filter_for_mew_terminate.h"
#include "filter_for_mew_initialize.h"

/* Function Declarations */
static void argInit_1x4096_real_T(double result[4096]);
static void argInit_1x5_int16_T(short result[5]);
static short argInit_int16_T(void);
static double argInit_real_T(void);
static void main_filter_for_mew(void);

/* Function Definitions */

/*
 * Arguments    : double result[4096]
 * Return Type  : void
 */
static void argInit_1x4096_real_T(double result[4096])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 4096; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : short result[5]
 * Return Type  : void
 */
static void argInit_1x5_int16_T(short result[5])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_int16_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : short
 */
static short argInit_int16_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_filter_for_mew(void)
{
  short iv0[5];
  double dv0[4096];
  double y[4096];

  /* Initialize function 'filter_for_mew' input arguments. */
  /* Initialize function input argument 'den'. */
  /* Initialize function input argument 'x'. */
  /* Call the entry-point 'filter_for_mew'. */
  argInit_1x5_int16_T(iv0);
  argInit_1x4096_real_T(dv0);
  filter_for_mew(argInit_int16_T(), iv0, dv0, y);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  filter_for_mew_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_filter_for_mew();

  /* Terminate the application.
     You do not need to do this more than one time. */
  filter_for_mew_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
