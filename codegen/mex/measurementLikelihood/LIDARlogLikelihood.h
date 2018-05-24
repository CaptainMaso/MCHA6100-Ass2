/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LIDARlogLikelihood.h
 *
 * Code generation for function 'LIDARlogLikelihood'
 *
 */

#ifndef LIDARLOGLIKELIHOOD_H
#define LIDARLOGLIKELIHOOD_H

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
extern void LIDARlogLikelihood(const emlrtStack *sp, const real_T y[91], const
  real_T yhat[91], real_T lp_any[91]);

#endif

/* End of code generation (LIDARlogLikelihood.h) */
