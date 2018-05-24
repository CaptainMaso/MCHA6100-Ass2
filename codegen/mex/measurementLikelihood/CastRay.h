/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CastRay.h
 *
 * Code generation for function 'CastRay'
 *
 */

#ifndef CASTRAY_H
#define CASTRAY_H

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
extern void CastRay(const emlrtStack *sp, const real_T X[3], real_T map_dx,
                    real_T map_dy, real_T map_Nx, real_T map_Ny, const
                    emxArray_real_T *map_map, real_T *hx, real_T *hy);

#endif

/* End of code generation (CastRay.h) */
