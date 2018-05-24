/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_mexutil.h
 *
 * Code generation for function 'measurementLikelihood_mexutil'
 *
 */

#ifndef MEASUREMENTLIKELIHOOD_MEXUTIL_H
#define MEASUREMENTLIKELIHOOD_MEXUTIL_H

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
extern const mxArray *b_emlrt_marshallOut(const real_T u);
extern const mxArray *emlrt_marshallOut(const struct_T *u);
extern void emlrt_synchGlobalsFromML(const emlrtStack *sp);
extern void emlrt_synchGlobalsToML(const emlrtStack *sp);
extern real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
extern void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_param,
  const char_T *identifier, struct_T *y);

#endif

/* End of code generation (measurementLikelihood_mexutil.h) */
