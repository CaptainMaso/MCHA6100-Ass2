/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_CastRay_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-May-2018 22:32:46
 */

#ifndef _CODER_CASTRAY_API_H
#define _CODER_CASTRAY_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_CastRay_api.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T dx;
  real_T dy;
  real_T Nx;
  real_T Ny;
  real_T map[115926];
  real_T xmax;
  real_T ymax;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CastRay(real_T X[3], struct0_T *map, real_T *hx, real_T *hy);
extern void CastRay_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[2]);
extern void CastRay_atexit(void);
extern void CastRay_initialize(void);
extern void CastRay_terminate(void);
extern void CastRay_xil_terminate(void);

#endif

/*
 * File trailer for _coder_CastRay_api.h
 *
 * [EOF]
 */
