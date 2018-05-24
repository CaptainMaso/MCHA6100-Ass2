/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_initialize.c
 *
 * Code generation for function 'measurementLikelihood_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurementLikelihood_mexutil.h"
#include "measurementLikelihood.h"
#include "measurementLikelihood_initialize.h"
#include "_coder_measurementLikelihood_mex.h"
#include "measurementLikelihood_data.h"

/* Function Declarations */
static void measurementLikelihood_once(const emlrtStack *sp);

/* Function Definitions */
static void measurementLikelihood_once(const emlrtStack *sp)
{
  static struct_T r0 = { 120.0,        /* ymax */
    0.01,                              /* dymax */
    10.0,                              /* scanrate */
    0.1,                               /* dT */
    { 0.68, 0.1956, 0.0878, 0.0366, 0.1813, 0.7575 },/* theta */
    { 0.05, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.78539816339744828 }/* Q */
  };

  int32_T i0;
  int32_T iv0[11];
  static const int32_T lineInfo[12] = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 26 };

  static const int32_T b_lineInfo[70] = { 2, 3, 4, 6, 7, 9, 10, 11, 13, 14, 15,
    17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 42, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 55, 57, 58, 59, 60,
    61, 62, 64, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 78, 79, 80, 81, 82,
    83, 84 };

  static const int32_T c_lineInfo[14] = { 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13,
    14, 15, 16 };

  int32_T iv1[8];
  int32_T iv2[6];
  int32_T iv3[7];
  int32_T iv4[2];
  param = r0;
  logSumExp_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\logSumExp.m>logSumExp(codegen)";
  lp_rand_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m>lp_rand(codegen)";
  lp_max_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m>lp_max(codegen)";
  lp_short_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m>lp_short(codegen)";
  lp_hit_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m>lp_hit(codegen)";
  c_LIDARlogLikelihood_complete_n =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m>LIDARlogLikelihood(codegen)";
  CastRay_complete_name =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\CastRay.m>CastRay(codegen)";
  c_checkStateConstraints_complet =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m>checkStateConstraints(codegen)";
  c_measurementLikelihood_complet =
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m>measurementLikelihood(codegen)";
  param_dirty = 1U;
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  for (i0 = 0; i0 < 11; i0++) {
    iv0[i0] = 2 + i0;
  }

  emlrtProfilerRegisterMEXFcn(c_measurementLikelihood_complet,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m",
    "measurementLikelihood", 11, iv0, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(c_checkStateConstraints_complet,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\measurementLikelihood.m",
    "measurementLikelihood>checkStateConstraints", 12, lineInfo, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(CastRay_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\CastRay.m",
    "CastRay", 70, b_lineInfo, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(c_LIDARlogLikelihood_complete_n,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m",
    "LIDARlogLikelihood", 14, c_lineInfo, isMexOutdated);
  for (i0 = 0; i0 < 8; i0++) {
    iv1[i0] = 19 + i0;
  }

  emlrtProfilerRegisterMEXFcn(lp_hit_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m",
    "LIDARlogLikelihood>lp_hit", 8, iv1, isMexOutdated);
  for (i0 = 0; i0 < 6; i0++) {
    iv2[i0] = 29 + i0;
  }

  emlrtProfilerRegisterMEXFcn(lp_short_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m",
    "LIDARlogLikelihood>lp_short", 6, iv2, isMexOutdated);
  for (i0 = 0; i0 < 7; i0++) {
    iv3[i0] = 37 + i0;
  }

  emlrtProfilerRegisterMEXFcn(lp_max_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m",
    "LIDARlogLikelihood>lp_max", 7, iv3, isMexOutdated);
  for (i0 = 0; i0 < 7; i0++) {
    iv3[i0] = 46 + i0;
  }

  emlrtProfilerRegisterMEXFcn(lp_rand_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m",
    "LIDARlogLikelihood>lp_rand", 7, iv3, isMexOutdated);
  for (i0 = 0; i0 < 2; i0++) {
    iv4[i0] = 3 + i0;
  }

  emlrtProfilerRegisterMEXFcn(logSumExp_complete_name,
    "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\logSumExp.m",
    "logSumExp", 2, iv4, isMexOutdated);
  emlrtSetGlobalSyncFcn(sp, (void (*)(const void *))emlrt_synchGlobalsToML);
}

void measurementLikelihood_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Statistics_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    measurementLikelihood_once(&st);
  }
}

/* End of code generation (measurementLikelihood_initialize.c) */
