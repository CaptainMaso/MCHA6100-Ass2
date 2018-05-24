/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood.h
 *
 * Code generation for function 'measurementLikelihood'
 *
 */

#ifndef MEASUREMENTLIKELIHOOD_H
#define MEASUREMENTLIKELIHOOD_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "measurementLikelihood_types.h"

/* Function Declarations */
extern real_T measurementLikelihood(const emlrtStack *sp, const real_T yt[91],
  const real_T x_t[3], const struct0_T *map);

#endif

/* End of code generation (measurementLikelihood.h) */
