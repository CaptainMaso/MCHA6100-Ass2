/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_mexutil.c
 *
 * Code generation for function 'measurementLikelihood_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "measurementLikelihood_mexutil.h"
#include "measurementLikelihood_data.h"

/* Function Declarations */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);

/* Function Definitions */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[6] = { "ymax", "dymax", "scanrate", "dT",
    "theta", "Q" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "ymax";
  y->ymax = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "ymax")), &thisId);
  thisId.fIdentifier = "dymax";
  y->dymax = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "dymax")), &thisId);
  thisId.fIdentifier = "scanrate";
  y->scanrate = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    2, "scanrate")), &thisId);
  thisId.fIdentifier = "dT";
  y->dT = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "dT")), &thisId);
  thisId.fIdentifier = "theta";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "theta")),
                     &thisId, y->theta);
  thisId.fIdentifier = "Q";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "Q")),
                     &thisId, y->Q);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[1] = { 6 };

  int32_T i7;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i7 = 0; i7 < 6; i7++) {
    ret[i7] = (*(real_T (*)[6])emlrtMxGetData(src))[i7];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 3, 3 };

  int32_T i8;
  int32_T i9;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i8 = 0; i8 < 3; i8++) {
    for (i9 = 0; i9 < 3; i9++) {
      ret[i9 + 3 * i8] = (*(real_T (*)[9])emlrtMxGetData(src))[i9 + 3 * i8];
    }
  }

  emlrtDestroyArray(&src);
}

const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

const mxArray *emlrt_marshallOut(const struct_T *u)
{
  const mxArray *y;
  static const char * sv0[6] = { "ymax", "dymax", "scanrate", "dT", "theta", "Q"
  };

  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv5[1] = { 6 };

  real_T *pData;
  int32_T i5;
  int32_T i;
  static const int32_T iv6[2] = { 3, 3 };

  int32_T b_i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 6, sv0));
  emlrtSetFieldR2017b(y, 0, "ymax", b_emlrt_marshallOut(u->ymax), 0);
  emlrtSetFieldR2017b(y, 0, "dymax", b_emlrt_marshallOut(u->dymax), 1);
  emlrtSetFieldR2017b(y, 0, "scanrate", b_emlrt_marshallOut(u->scanrate), 2);
  emlrtSetFieldR2017b(y, 0, "dT", b_emlrt_marshallOut(u->dT), 3);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i5 = 0;
  for (i = 0; i < 6; i++) {
    pData[i5] = u->theta[i];
    i5++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "theta", b_y, 4);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i5 = 0;
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < 3; b_i++) {
      pData[i5] = u->Q[b_i + 3 * i];
      i5++;
    }
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "Q", b_y, 5);
  return y;
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  const mxArray *m2;
  m2 = emlrtGetGlobalVariable("param");
  if (m2 != NULL) {
    i_emlrt_marshallIn(sp, m2, "param", &param);
  }

  param_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  if (param_dirty & 1U) {
    emlrtPutGlobalVariable("param", emlrt_marshallOut(&param));
    param_dirty &= 2U;
  }
}

real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_param, const
  char_T *identifier, struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(b_param), &thisId, y);
  emlrtDestroyArray(&b_param);
}

/* End of code generation (measurementLikelihood_mexutil.c) */
