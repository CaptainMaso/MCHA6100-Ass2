/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood.c
 *
 * Code generation for function 'measurementLikelihood'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "CastRay.h"
#include "error.h"
#include "LIDARlogLikelihood.h"
#include "measurementLikelihood_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 2,     /* lineNo */
  "measurementLikelihood",             /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 5,   /* lineNo */
  "measurementLikelihood",             /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 8,   /* lineNo */
  "measurementLikelihood",             /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  13,                                  /* colNo */
  "map.map",                           /* aName */
  "measurementLikelihood",             /* fName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 19,    /* lineNo */
  13,                                  /* colNo */
  "measurementLikelihood",             /* fName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
real_T measurementLikelihood(const emlrtStack *sp, const real_T yt[91], const
  real_T x_t[3], const struct0_T *map)
{
  real_T lp_x;
  real_T scale;
  real_T xstar;
  int32_T idx;
  int32_T k;
  int32_T i1;
  real_T b_x_t[3];
  real_T yhat[91];
  real_T dv0[91];
  real_T x[2];
  boolean_T exitg1;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtMEXProfilingFunctionEntry(c_measurementLikelihood_complet, isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  st.site = &emlrtRSI;
  emlrtMEXProfilingFunctionEntry(c_checkStateConstraints_complet, isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  scale = muDoubleScalarFloor(x_t[0] / map->dx);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  xstar = muDoubleScalarFloor(x_t[1] / map->dy);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  if ((scale + 1.0 > map->Nx) || (scale + 1.0 <= 0.0) || (xstar + 1.0 > map->Ny)
      || (xstar + 1.0 <= 0.0)) {
    emlrtMEXProfilingStatement(4, isMexOutdated);
    idx = 1;
    emlrtMEXProfilingStatement(11, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    emlrtMEXProfilingStatement(6, isMexOutdated);
    idx = map->map->size[0];
    if (xstar + 1.0 != (int32_T)(xstar + 1.0)) {
      emlrtIntegerCheckR2012b(xstar + 1.0, &emlrtDCI, &st);
    }

    k = (int32_T)(xstar + 1.0);
    if (!((k >= 1) && (k <= idx))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, idx, &emlrtBCI, &st);
    }

    idx = map->map->size[1];
    if (scale + 1.0 != (int32_T)(scale + 1.0)) {
      emlrtIntegerCheckR2012b(scale + 1.0, &emlrtDCI, &st);
    }

    i1 = (int32_T)(scale + 1.0);
    if (!((i1 >= 1) && (i1 <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, idx, &emlrtBCI, &st);
    }

    if (map->map->data[(k + map->map->size[0] * (i1 - 1)) - 1] == 1.0) {
      emlrtMEXProfilingStatement(7, isMexOutdated);
      idx = 1;
      emlrtMEXProfilingStatement(10, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(8, isMexOutdated);
      emlrtMEXProfilingStatement(9, isMexOutdated);
      idx = 0;
      emlrtMEXProfilingStatement(10, isMexOutdated);
    }

    emlrtMEXProfilingStatement(11, isMexOutdated);
  }

  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  st.site = &emlrtRSI;
  if (!(idx != 0)) {
    emlrtMEXProfilingStatement(3, isMexOutdated);
    idx = 0;
    while (idx < 91) {
      emlrtMEXProfilingStatement(4, isMexOutdated);
      b_x_t[0] = x_t[0];
      b_x_t[1] = x_t[1];
      b_x_t[2] = x_t[2] + 0.017453292519943295 * (((1.0 + (real_T)idx) - 45.0) -
        1.0);
      st.site = &b_emlrtRSI;
      CastRay(&st, b_x_t, map->dx, map->dy, map->Nx, map->Ny, map->map, &xstar,
              &scale);
      emlrtMEXProfilingStatement(0, isMexOutdated);
      emlrtMEXProfilingStatement(5, isMexOutdated);
      x[0] = xstar - x_t[0];
      x[1] = scale - x_t[1];
      xstar = 0.0;
      scale = 3.3121686421112381E-170;
      for (k = 0; k < 2; k++) {
        absxk = muDoubleScalarAbs(x[k]);
        if (absxk > scale) {
          t = scale / absxk;
          xstar = 1.0 + xstar * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          xstar += t * t;
        }
      }

      xstar = scale * muDoubleScalarSqrt(xstar);
      yhat[idx] = xstar;
      emlrtMEXProfilingStatement(6, isMexOutdated);
      idx++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emlrtMEXProfilingStatement(7, isMexOutdated);
    st.site = &c_emlrtRSI;
    b_st.site = &c_emlrtRSI;
    LIDARlogLikelihood(&b_st, yt, yhat, dv0);
    memcpy(&yhat[0], &dv0[0], 91U * sizeof(real_T));
    emlrtMEXProfilingFunctionEntry(logSumExp_complete_name, isMexOutdated);
    emlrtMEXProfilingStatement(1, isMexOutdated);
    if (!muDoubleScalarIsNaN(yhat[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 92)) {
        if (!muDoubleScalarIsNaN(yhat[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      xstar = yhat[0];
    } else {
      xstar = yhat[idx - 1];
      while (idx + 1 < 92) {
        if (xstar < yhat[idx]) {
          xstar = yhat[idx];
        }

        idx++;
      }
    }

    emlrtMEXProfilingStatement(2, isMexOutdated);
    for (k = 0; k < 91; k++) {
      yhat[k] = muDoubleScalarExp(yhat[k] - xstar);
    }

    scale = yhat[0];
    for (k = 0; k < 90; k++) {
      scale += yhat[k + 1];
    }

    b_st.site = &gb_emlrtRSI;
    if (scale < 0.0) {
      c_st.site = &n_emlrtRSI;
      error(&c_st);
    }

    lp_x = xstar + muDoubleScalarLog(scale);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    emlrtMEXProfilingStatement(10, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(8, isMexOutdated);
    emlrtMEXProfilingStatement(9, isMexOutdated);
    lp_x = rtMinusInf;
    emlrtMEXProfilingStatement(10, isMexOutdated);
  }

  emlrtMEXProfilingStatement(11, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  return lp_x;
}

/* End of code generation (measurementLikelihood.c) */
