/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_terminate.c
 *
 * Code generation for function 'measurementLikelihood_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "measurementLikelihood_terminate.h"
#include "measurementLikelihood_mexutil.h"
#include "_coder_measurementLikelihood_mex.h"
#include "measurementLikelihood_data.h"

/* Function Definitions */
void measurementLikelihood_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrt_synchGlobalsFromML(&st);
  emlrtProfilerUnregisterMEXFcn(c_measurementLikelihood_complet, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(c_checkStateConstraints_complet, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(CastRay_complete_name, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(c_LIDARlogLikelihood_complete_n, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(lp_hit_complete_name, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(lp_short_complete_name, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(lp_max_complete_name, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(lp_rand_complete_name, isMexOutdated);
  emlrtProfilerUnregisterMEXFcn(logSumExp_complete_name, isMexOutdated);
  emlrt_synchGlobalsToML(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void measurementLikelihood_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (measurementLikelihood_terminate.c) */
