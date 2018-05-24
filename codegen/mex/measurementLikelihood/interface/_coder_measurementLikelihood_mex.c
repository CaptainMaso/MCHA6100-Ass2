/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_measurementLikelihood_mex.c
 *
 * Code generation for function '_coder_measurementLikelihood_mex'
 *
 */

/* Include files */
#include "measurementLikelihood.h"
#include "_coder_measurementLikelihood_mex.h"
#include "measurementLikelihood_terminate.h"
#include "_coder_measurementLikelihood_api.h"
#include "measurementLikelihood_initialize.h"
#include "measurementLikelihood_data.h"

/* Function Declarations */
static void c_measurementLikelihood_mexFunc(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void c_measurementLikelihood_mexFunc(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        21, "measurementLikelihood");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "measurementLikelihood");
  }

  /* Call the function. */
  measurementLikelihood_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  measurementLikelihood_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(measurementLikelihood_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  measurementLikelihood_initialize();

  /* Dispatch the entry-point. */
  c_measurementLikelihood_mexFunc(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_measurementLikelihood_mex.c) */
