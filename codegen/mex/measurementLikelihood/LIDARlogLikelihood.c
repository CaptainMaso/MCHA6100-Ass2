/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LIDARlogLikelihood.c
 *
 * Code generation for function 'LIDARlogLikelihood'
 *
 */

/* Include files */
#include <math.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "LIDARlogLikelihood.h"
#include "error.h"
#include "measurementLikelihood_data.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 3,   /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 10,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 11,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 12,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 13,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 14,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 21,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 22,  /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 30, /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 39, /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 48, /* lineNo */
  "LIDARlogLikelihood",                /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\LIDARlogLikelihood.m"/* pathName */
};

/* Function Declarations */
static real_T lp_hit(const emlrtStack *sp, real_T y, real_T yhat, real_T sigma);

/* Function Definitions */
static real_T lp_hit(const emlrtStack *sp, real_T y, real_T yhat, real_T sigma)
{
  real_T lp;
  real_T eta;
  real_T x;
  real_T S;
  real_T absx;
  real_T R;
  int32_T eint;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtMEXProfilingFunctionEntry(lp_hit_complete_name, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  if ((y > 0.0) && (y < param.ymax - param.dymax)) {
    emlrtMEXProfilingStatement(3, isMexOutdated);
    st.site = &o_emlrtRSI;
    if (sigma == 0.0) {
      eta = !(param.ymax < yhat);
    } else if (sigma > 0.0) {
      x = -((param.ymax - yhat) / sigma) / 1.4142135623730951;

      /* ========================== COPYRIGHT NOTICE ============================ */
      /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
      /*  from FDLIBM, which has the following notice:                            */
      /*                                                                          */
      /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
      /*                                                                          */
      /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
      /*  Permission to use, copy, modify, and distribute this                    */
      /*  software is freely granted, provided that this notice                   */
      /*  is preserved.                                                           */
      /* =============================    END    ================================ */
      absx = muDoubleScalarAbs(x);
      if (muDoubleScalarIsNaN(x)) {
        eta = x;
      } else if (muDoubleScalarIsInf(x)) {
        if (x < 0.0) {
          eta = 2.0;
        } else {
          eta = 0.0;
        }
      } else if (absx < 0.84375) {
        if (absx < 1.3877787807814457E-17) {
          eta = 1.0 - x;
        } else {
          eta = x * x;
          eta = (0.12837916709551256 + eta * (-0.3250421072470015 + eta *
                  (-0.02848174957559851 + eta * (-0.0057702702964894416 + eta *
                    -2.3763016656650163E-5)))) / (1.0 + eta *
            (0.39791722395915535 + eta * (0.0650222499887673 + eta *
            (0.0050813062818757656 + eta * (0.00013249473800432164 + eta *
            -3.9602282787753681E-6)))));
          if (x < 0.25) {
            eta = 1.0 - (x + x * eta);
          } else {
            eta = 0.5 - (x * eta + (x - 0.5));
          }
        }
      } else if (absx < 1.25) {
        S = -0.0023621185607526594 + (absx - 1.0) * (0.41485611868374833 + (absx
          - 1.0) * (-0.37220787603570132 + (absx - 1.0) * (0.31834661990116175 +
          (absx - 1.0) * (-0.11089469428239668 + (absx - 1.0) *
                          (0.035478304325618236 + (absx - 1.0) *
                           -0.0021663755948687908)))));
        eta = 1.0 + (absx - 1.0) * (0.10642088040084423 + (absx - 1.0) *
          (0.540397917702171 + (absx - 1.0) * (0.071828654414196266 + (absx -
          1.0) * (0.12617121980876164 + (absx - 1.0) * (0.013637083912029051 +
          (absx - 1.0) * 0.011984499846799107)))));
        if (x >= 0.0) {
          eta = 0.15493708848953247 - S / eta;
        } else {
          eta = 1.0 + (0.84506291151046753 + S / eta);
        }
      } else if (x < -6.0) {
        eta = 2.0;
      } else if (x >= 28.0) {
        eta = 0.0;
      } else {
        eta = 1.0 / (absx * absx);
        if (absx < 2.8571414947509766) {
          R = -0.0098649440348471482 + eta * (-0.69385857270718176 + eta *
            (-10.558626225323291 + eta * (-62.375332450326006 + eta *
            (-162.39666946257347 + eta * (-184.60509290671104 + eta *
            (-81.2874355063066 + eta * -9.8143293441691455))))));
          S = 1.0 + eta * (19.651271667439257 + eta * (137.65775414351904 + eta *
            (434.56587747522923 + eta * (645.38727173326788 + eta *
            (429.00814002756783 + eta * (108.63500554177944 + eta *
            (6.5702497703192817 + eta * -0.0604244152148581)))))));
        } else {
          R = -0.0098649429247001 + eta * (-0.799283237680523 + eta *
            (-17.757954917754752 + eta * (-160.63638485582192 + eta *
            (-637.56644336838963 + eta * (-1025.0951316110772 + eta *
            -483.5191916086514)))));
          S = 1.0 + eta * (30.338060743482458 + eta * (325.79251299657392 + eta *
            (1536.729586084437 + eta * (3199.8582195085955 + eta *
            (2553.0504064331644 + eta * (474.52854120695537 + eta *
            -22.440952446585818))))));
        }

        if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
          eta = frexp(absx, &eint);
        } else {
          eta = absx;
          eint = 0;
        }

        eta = muDoubleScalarFloor(eta * 2.097152E+6) / 2.097152E+6 *
          muDoubleScalarPower(2.0, eint);
        eta = muDoubleScalarExp(-eta * eta - 0.5625) * muDoubleScalarExp((eta -
          absx) * (eta + absx) + R / S) / absx;
        if (x < 0.0) {
          eta = 2.0 - eta;
        }
      }

      eta *= 0.5;
    } else {
      eta = rtNaN;
    }

    emlrtMEXProfilingStatement(4, isMexOutdated);
    S = (y - yhat) / sigma;
    st.site = &p_emlrtRSI;
    st.site = &p_emlrtRSI;
    x = 6.2831853071795862 * (sigma * sigma);
    if (x < 0.0) {
      b_st.site = &n_emlrtRSI;
      error(&b_st);
    }

    st.site = &p_emlrtRSI;
    st.site = &p_emlrtRSI;
    if (eta < 0.0) {
      b_st.site = &n_emlrtRSI;
      error(&b_st);
    }

    lp = (-muDoubleScalarLog(x) - S * S) / 2.0 - muDoubleScalarLog(eta);
    emlrtMEXProfilingStatement(7, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    emlrtMEXProfilingStatement(6, isMexOutdated);
    lp = 0.0;
    emlrtMEXProfilingStatement(7, isMexOutdated);
  }

  emlrtMEXProfilingStatement(8, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  return lp;
}

void LIDARlogLikelihood(const emlrtStack *sp, const real_T y[91], const real_T
  yhat[91], real_T lp_any[91])
{
  boolean_T p;
  int32_T k;
  real_T lW[4];
  real_T Sigma;
  real_T Lambda;
  int32_T ii;
  real_T le[4];
  real_T lp;
  int32_T idx;
  boolean_T exitg1;
  real_T xstar;
  real_T x[4];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtMEXProfilingFunctionEntry(c_LIDARlogLikelihood_complete_n, isMexOutdated);
  emlrtMEXProfilingStatement(0, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  st.site = &h_emlrtRSI;
  p = false;
  for (k = 0; k < 4; k++) {
    lW[k] = param.theta[k];
    if (p || (param.theta[k] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  }

  if (p) {
    b_st.site = &n_emlrtRSI;
    error(&b_st);
  }

  for (k = 0; k < 4; k++) {
    lW[k] = muDoubleScalarLog(lW[k]);
  }

  emlrtMEXProfilingStatement(3, isMexOutdated);
  Sigma = param.theta[4];
  emlrtMEXProfilingStatement(4, isMexOutdated);
  Lambda = param.theta[5];
  emlrtMEXProfilingStatement(7, isMexOutdated);
  ii = 0;
  while (ii < 91) {
    emlrtMEXProfilingStatement(8, isMexOutdated);
    st.site = &i_emlrtRSI;
    le[0] = lW[0] + lp_hit(&st, y[ii], yhat[ii], Sigma);
    emlrtMEXProfilingStatement(9, isMexOutdated);
    st.site = &j_emlrtRSI;
    emlrtMEXProfilingFunctionEntry(lp_short_complete_name, isMexOutdated);
    emlrtMEXProfilingStatement(1, isMexOutdated);
    if ((y[ii] >= 0.0) && (y[ii] <= yhat[ii])) {
      emlrtMEXProfilingStatement(2, isMexOutdated);
      b_st.site = &db_emlrtRSI;
      if (Lambda < 0.0) {
        c_st.site = &n_emlrtRSI;
        error(&c_st);
      }

      lp = -Lambda * yhat[ii];
      b_st.site = &db_emlrtRSI;
      if (1.0 - muDoubleScalarExp(lp) < 0.0) {
        c_st.site = &n_emlrtRSI;
        error(&c_st);
      }

      lp = (muDoubleScalarLog(Lambda) - Lambda * y[ii]) - muDoubleScalarLog(1.0
        - muDoubleScalarExp(lp));
      emlrtMEXProfilingStatement(5, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(3, isMexOutdated);
      emlrtMEXProfilingStatement(4, isMexOutdated);
      lp = rtMinusInf;
      emlrtMEXProfilingStatement(5, isMexOutdated);
    }

    emlrtMEXProfilingStatement(6, isMexOutdated);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    le[1] = lW[1] + lp;
    emlrtMEXProfilingStatement(10, isMexOutdated);
    st.site = &k_emlrtRSI;
    emlrtMEXProfilingFunctionEntry(lp_max_complete_name, isMexOutdated);
    emlrtMEXProfilingStatement(2, isMexOutdated);
    if ((y[ii] > param.ymax - param.dymax) && (y[ii] <= param.ymax + param.dymax))
    {
      emlrtMEXProfilingStatement(3, isMexOutdated);
      b_st.site = &eb_emlrtRSI;
      lp = 2.0 * param.dymax;
      if (lp < 0.0) {
        c_st.site = &n_emlrtRSI;
        error(&c_st);
      }

      lp = -muDoubleScalarLog(lp);
      emlrtMEXProfilingStatement(6, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(4, isMexOutdated);
      emlrtMEXProfilingStatement(5, isMexOutdated);
      lp = rtMinusInf;
      emlrtMEXProfilingStatement(6, isMexOutdated);
    }

    emlrtMEXProfilingStatement(7, isMexOutdated);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    le[2] = lW[2] + lp;
    emlrtMEXProfilingStatement(11, isMexOutdated);
    st.site = &l_emlrtRSI;
    emlrtMEXProfilingFunctionEntry(lp_rand_complete_name, isMexOutdated);
    emlrtMEXProfilingStatement(2, isMexOutdated);
    if ((y[ii] >= 0.0) && (y[ii] <= param.ymax - param.dymax)) {
      emlrtMEXProfilingStatement(3, isMexOutdated);
      b_st.site = &fb_emlrtRSI;
      lp = param.ymax;
      if (param.ymax < 0.0) {
        c_st.site = &n_emlrtRSI;
        error(&c_st);
      }

      lp = -muDoubleScalarLog(lp);
      emlrtMEXProfilingStatement(6, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(4, isMexOutdated);
      emlrtMEXProfilingStatement(5, isMexOutdated);
      lp = rtMinusInf;
      emlrtMEXProfilingStatement(6, isMexOutdated);
    }

    emlrtMEXProfilingStatement(7, isMexOutdated);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    le[3] = lW[3] + lp;
    emlrtMEXProfilingStatement(12, isMexOutdated);
    st.site = &m_emlrtRSI;
    emlrtMEXProfilingFunctionEntry(logSumExp_complete_name, isMexOutdated);
    emlrtMEXProfilingStatement(1, isMexOutdated);
    if (!muDoubleScalarIsNaN(le[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!muDoubleScalarIsNaN(le[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      xstar = le[0];
    } else {
      xstar = le[idx - 1];
      while (idx + 1 < 5) {
        if (xstar < le[idx]) {
          xstar = le[idx];
        }

        idx++;
      }
    }

    emlrtMEXProfilingStatement(2, isMexOutdated);
    for (k = 0; k < 4; k++) {
      x[k] = muDoubleScalarExp(le[k] - xstar);
    }

    lp = x[0];
    for (k = 0; k < 3; k++) {
      lp += x[k + 1];
    }

    b_st.site = &gb_emlrtRSI;
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    lp_any[ii] = xstar + muDoubleScalarLog(lp);
    emlrtMEXProfilingStatement(13, isMexOutdated);
    ii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtMEXProfilingStatement(14, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (LIDARlogLikelihood.c) */
