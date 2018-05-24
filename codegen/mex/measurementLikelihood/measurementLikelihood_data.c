/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * measurementLikelihood_data.c
 *
 * Code generation for function 'measurementLikelihood_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurementLikelihood.h"
#include "measurementLikelihood_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
struct_T param;
boolean_T isMexOutdated;
const char * c_measurementLikelihood_complet;
const char * c_checkStateConstraints_complet;
const char * CastRay_complete_name;
const char * c_LIDARlogLikelihood_complete_n;
const char * lp_hit_complete_name;
const char * lp_short_complete_name;
const char * lp_max_complete_name;
const char * lp_rand_complete_name;
const char * logSumExp_complete_name;
uint32_T param_dirty;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "measurementLikelihood",             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2433290357U, 2237796540U, 4066813863U, 833189415U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo d_emlrtRSI = { 9,          /* lineNo */
  "CastRay",                           /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\CastRay.m"/* pathName */
};

emlrtRSInfo e_emlrtRSI = { 13,         /* lineNo */
  "CastRay",                           /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\CastRay.m"/* pathName */
};

emlrtRSInfo f_emlrtRSI = { 40,         /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

emlrtRSInfo g_emlrtRSI = { 49,         /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 13,         /* lineNo */
  "log",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pathName */
};

emlrtRSInfo q_emlrtRSI = { 79,         /* lineNo */
  "normcdf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\stats\\eml\\normcdf.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 9,          /* lineNo */
  "erfc",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\specfun\\erfc.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 15,         /* lineNo */
  "eml_erfcore",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\specfun\\private\\eml_erfcore.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 48,         /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 56,         /* lineNo */
  "eml_erfcore",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\specfun\\private\\eml_erfcore.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 236,        /* lineNo */
  "eml_erfcore",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\specfun\\private\\eml_erfcore.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 238,        /* lineNo */
  "eml_erfcore",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\specfun\\private\\eml_erfcore.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 16,         /* lineNo */
  "log2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 46,         /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 8,         /* lineNo */
  "log2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\log2.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 11,        /* lineNo */
  "pow2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elfun\\pow2.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 8,         /* lineNo */
  "pow2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\pow2.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 4,         /* lineNo */
  "logSumExp",                         /* fcnName */
  "D:\\Google Drive\\Uni\\Year 4\\MCHA6100\\Assignments\\Assignment 2\\logSumExp.m"/* pathName */
};

/* End of code generation (measurementLikelihood_data.c) */
