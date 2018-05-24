/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CastRay.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-May-2018 22:32:46
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "CastRay.h"

/* Function Definitions */

/*
 * Arguments    : const double X[3]
 *                const struct0_T *map
 *                double *hx
 *                double *hy
 * Return Type  : void
 */
void CastRay(const double X[3], const struct0_T *map, double *hx, double *hy)
{
  double dx;
  double dy;
  double error;
  double b;
  double xi;
  double x;
  double yi;
  int xinc;
  int yinc;
  int top_or_side;
  dx = cos(X[2]);
  dy = sin(X[2]);
  if ((dy < 1.0E-6) && (dy > -1.0E-6)) {
    dy = 0.0;
  }

  if ((dx < 1.0E-6) && (dx > -1.0E-6)) {
    dx = 0.0;
  }

  error = X[0] / map->dx;
  b = floor(error);
  xi = floor(error) + 1.0;
  error = X[1] / map->dy;
  x = floor(error);
  yi = floor(error) + 1.0;
  if (dx == 0.0) {
    xinc = 0;
    error = rtInf;
  } else if (dx > 0.0) {
    xinc = 1;
    error = (((b + 1.0) - (X[0] / map->dx + 1.0)) + 1.0) * fabs(dy);
  } else {
    /*  dx < 0 */
    xinc = -1;
    error = ((X[0] / map->dx + 1.0) - (b + 1.0)) * fabs(dy);
  }

  if (dy == 0.0) {
    yinc = 0;
    error -= rtInf;
  } else if (dy > 0.0) {
    yinc = 1;
    error -= (((x + 1.0) - (X[1] / map->dy + 1.0)) + 1.0) * fabs(dx);
  } else {
    /*  dy < 0 */
    yinc = -1;
    error -= ((X[1] / map->dx + 1.0) - (x + 1.0)) * fabs(dx);
  }

  top_or_side = 0;
  while ((map->Nx >= xi) && (0.0 < xi) && (map->Ny >= yi) && (0.0 < yi) &&
         (map->map[((int)yi + 278 * ((int)xi - 1)) - 1] != 1.0)) {
    if (error > 0.0) {
      top_or_side = 1;

      /* Hit top or bottom */
      yi += (double)yinc;
      error -= fabs(dx);
    } else {
      top_or_side = 0;

      /* Hit one of the sides */
      xi += (double)xinc;
      error += fabs(dy);
    }

    /* plot((xi-0.5)*map.dx, (yi-0.5)*map.dy, '.g'); */
  }

  if (dx != 0.0) {
    error = dy / dx;
  } else {
    error = rtInf;
  }

  b = X[1] - error * X[0];
  if (top_or_side == 1) {
    /*  Hit TOP or BOTTOM */
    if (dy > 0.0) {
      *hy = floor(yi - 0.5) * map->dy;
    } else {
      *hy = ceil(yi - 0.5) * map->dy;
    }

    if (error == rtInf) {
      *hx = X[0];
    } else {
      *hx = (*hy - b) / error;
    }
  } else {
    /*  Hit SIDE */
    if (dx > 0.0) {
      *hx = floor(xi - 0.5) * map->dx;
    } else {
      *hx = ceil(xi - 0.5) * map->dx;
    }

    *hy = error * *hx + b;
  }
}

/*
 * File trailer for CastRay.c
 *
 * [EOF]
 */
