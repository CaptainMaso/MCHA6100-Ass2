/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_types.h
 *
 * Code generation for function 'measurementLikelihood'
 *
 */

#ifndef MEASUREMENTLIKELIHOOD_TYPES_H
#define MEASUREMENTLIKELIHOOD_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T dx;
  real_T dy;
  real_T Nx;
  real_T Ny;
  emxArray_real_T *map;
  real_T xmax;
  real_T ymax;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T ymax;
  real_T dymax;
  real_T scanrate;
  real_T dT;
  real_T theta[6];
  real_T Q[9];
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/* End of code generation (measurementLikelihood_types.h) */
