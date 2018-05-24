/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CastRay.c
 *
 * Code generation for function 'CastRay'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "CastRay.h"
#include "measurementLikelihood_data.h"

/* Variable Definitions */
static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  68,                                  /* colNo */
  "map.map",                           /* aName */
  "CastRay",                           /* fName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\CastRay.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void CastRay(const emlrtStack *sp, const real_T X[3], real_T map_dx, real_T
             map_dy, real_T map_Nx, real_T map_Ny, const emxArray_real_T
             *map_map, real_T *hx, real_T *hy)
{
  real_T dx;
  real_T dy;
  real_T b_error;
  real_T b;
  real_T xi;
  real_T x;
  real_T yi;
  int32_T xinc;
  int32_T yinc;
  int32_T top_or_side;
  boolean_T exitg1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  emlrtMEXProfilingFunctionEntry(CastRay_complete_name, isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  dx = muDoubleScalarCos(X[2]);
  emlrtMEXProfilingStatement(5, isMexOutdated);
  dy = muDoubleScalarSin(X[2]);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  if ((dy < 1.0E-6) && (dy > -1.0E-6)) {
    emlrtMEXProfilingStatement(7, isMexOutdated);
    dy = 0.0;
    emlrtMEXProfilingStatement(8, isMexOutdated);
  }

  emlrtMEXProfilingStatement(9, isMexOutdated);
  if ((dx < 1.0E-6) && (dx > -1.0E-6)) {
    emlrtMEXProfilingStatement(10, isMexOutdated);
    dx = 0.0;
    emlrtMEXProfilingStatement(11, isMexOutdated);
  }

  emlrtMEXProfilingStatement(12, isMexOutdated);
  b_error = X[0] / map_dx;
  b = muDoubleScalarFloor(b_error);
  xi = muDoubleScalarFloor(b_error) + 1.0;
  emlrtMEXProfilingStatement(13, isMexOutdated);
  b_error = X[1] / map_dy;
  x = muDoubleScalarFloor(b_error);
  yi = muDoubleScalarFloor(b_error) + 1.0;
  emlrtMEXProfilingStatement(14, isMexOutdated);
  if (dx == 0.0) {
    emlrtMEXProfilingStatement(15, isMexOutdated);
    xinc = 0;
    emlrtMEXProfilingStatement(16, isMexOutdated);
    b_error = rtInf;
    emlrtMEXProfilingStatement(23, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(17, isMexOutdated);
    if (dx > 0.0) {
      emlrtMEXProfilingStatement(18, isMexOutdated);
      xinc = 1;
      emlrtMEXProfilingStatement(19, isMexOutdated);
      b_error = (((b + 1.0) - (X[0] / map_dx + 1.0)) + 1.0) * muDoubleScalarAbs
        (dy);
      emlrtMEXProfilingStatement(23, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(20, isMexOutdated);

      /*  dx < 0 */
      emlrtMEXProfilingStatement(21, isMexOutdated);
      xinc = -1;
      emlrtMEXProfilingStatement(22, isMexOutdated);
      b_error = ((X[0] / map_dx + 1.0) - (b + 1.0)) * muDoubleScalarAbs(dy);
      emlrtMEXProfilingStatement(23, isMexOutdated);
    }
  }

  emlrtMEXProfilingStatement(24, isMexOutdated);
  if (dy == 0.0) {
    emlrtMEXProfilingStatement(25, isMexOutdated);
    yinc = 0;
    emlrtMEXProfilingStatement(26, isMexOutdated);
    b_error -= rtInf;
    emlrtMEXProfilingStatement(33, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(27, isMexOutdated);
    if (dy > 0.0) {
      emlrtMEXProfilingStatement(28, isMexOutdated);
      yinc = 1;
      emlrtMEXProfilingStatement(29, isMexOutdated);
      b_error -= (((x + 1.0) - (X[1] / map_dy + 1.0)) + 1.0) * muDoubleScalarAbs
        (dx);
      emlrtMEXProfilingStatement(33, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(30, isMexOutdated);

      /*  dy < 0 */
      emlrtMEXProfilingStatement(31, isMexOutdated);
      yinc = -1;
      emlrtMEXProfilingStatement(32, isMexOutdated);
      b_error -= ((X[1] / map_dx + 1.0) - (x + 1.0)) * muDoubleScalarAbs(dx);
      emlrtMEXProfilingStatement(33, isMexOutdated);
    }
  }

  emlrtMEXProfilingStatement(34, isMexOutdated);
  top_or_side = 0;
  emlrtMEXProfilingStatement(35, isMexOutdated);
  exitg1 = false;
  while ((!exitg1) && ((map_Nx >= xi) && (0.0 < xi) && (map_Ny >= yi) && (0.0 <
           yi))) {
    i2 = map_map->size[0];
    i3 = (int32_T)yi;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &b_emlrtBCI, sp);
    }

    i2 = map_map->size[1];
    i4 = (int32_T)xi;
    if (!((i4 >= 1) && (i4 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i2, &b_emlrtBCI, sp);
    }

    if (map_map->data[(i3 + map_map->size[0] * (i4 - 1)) - 1] != 1.0) {
      emlrtMEXProfilingStatement(36, isMexOutdated);
      if (b_error > 0.0) {
        emlrtMEXProfilingStatement(37, isMexOutdated);
        top_or_side = 1;

        /* Hit top or bottom */
        emlrtMEXProfilingStatement(38, isMexOutdated);
        yi += (real_T)yinc;
        emlrtMEXProfilingStatement(39, isMexOutdated);
        b_error -= muDoubleScalarAbs(dx);
        emlrtMEXProfilingStatement(44, isMexOutdated);
      } else {
        emlrtMEXProfilingStatement(40, isMexOutdated);
        emlrtMEXProfilingStatement(41, isMexOutdated);
        top_or_side = 0;

        /* Hit one of the sides */
        emlrtMEXProfilingStatement(42, isMexOutdated);
        xi += (real_T)xinc;
        emlrtMEXProfilingStatement(43, isMexOutdated);
        b_error += muDoubleScalarAbs(dy);
        emlrtMEXProfilingStatement(44, isMexOutdated);
      }

      /* plot((xi-0.5)*map.dx, (yi-0.5)*map.dy, '.g'); */
      emlrtMEXProfilingStatement(45, isMexOutdated);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = true;
    }
  }

  emlrtMEXProfilingStatement(46, isMexOutdated);
  if (dx != 0.0) {
    emlrtMEXProfilingStatement(47, isMexOutdated);
    b_error = dy / dx;
    emlrtMEXProfilingStatement(50, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(48, isMexOutdated);
    emlrtMEXProfilingStatement(49, isMexOutdated);
    b_error = rtInf;
    emlrtMEXProfilingStatement(50, isMexOutdated);
  }

  emlrtMEXProfilingStatement(51, isMexOutdated);
  b = X[1] - b_error * X[0];
  emlrtMEXProfilingStatement(52, isMexOutdated);
  if (top_or_side == 1) {
    /*  Hit TOP or BOTTOM */
    emlrtMEXProfilingStatement(53, isMexOutdated);
    if (dy > 0.0) {
      emlrtMEXProfilingStatement(54, isMexOutdated);
      *hy = muDoubleScalarFloor(yi - 0.5) * map_dy;
      emlrtMEXProfilingStatement(57, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(55, isMexOutdated);
      emlrtMEXProfilingStatement(56, isMexOutdated);
      *hy = muDoubleScalarCeil(yi - 0.5) * map_dy;
      emlrtMEXProfilingStatement(57, isMexOutdated);
    }

    emlrtMEXProfilingStatement(58, isMexOutdated);
    if (b_error == rtInf) {
      emlrtMEXProfilingStatement(59, isMexOutdated);
      *hx = X[0];
      emlrtMEXProfilingStatement(62, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(60, isMexOutdated);
      emlrtMEXProfilingStatement(61, isMexOutdated);
      *hx = (*hy - b) / b_error;
      emlrtMEXProfilingStatement(62, isMexOutdated);
    }

    emlrtMEXProfilingStatement(70, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(63, isMexOutdated);

    /*  Hit SIDE */
    emlrtMEXProfilingStatement(64, isMexOutdated);
    if (dx > 0.0) {
      emlrtMEXProfilingStatement(65, isMexOutdated);
      *hx = muDoubleScalarFloor(xi - 0.5) * map_dx;
      emlrtMEXProfilingStatement(68, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(66, isMexOutdated);
      emlrtMEXProfilingStatement(67, isMexOutdated);
      *hx = muDoubleScalarCeil(xi - 0.5) * map_dx;
      emlrtMEXProfilingStatement(68, isMexOutdated);
    }

    emlrtMEXProfilingStatement(69, isMexOutdated);
    *hy = b_error * *hx + b;
    emlrtMEXProfilingStatement(70, isMexOutdated);
  }

  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (CastRay.c) */
