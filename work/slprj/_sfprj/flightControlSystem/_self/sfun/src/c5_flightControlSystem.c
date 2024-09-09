/* Include files */

#include "flightControlSystem_sfun.h"
#include "c5_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c5_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c5_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnegative.m"/* pName */
};

static emlrtMCInfo c5_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c5_d_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c5_e_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c5_f_emlrtMCI = { 291,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c5_g_emlrtMCI = { 78,/* lineNo */
  47,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtMCInfo c5_h_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c5_i_emlrtMCI = { 134,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c5_j_emlrtMCI = { 133,/* lineNo */
  5,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtMCInfo c5_k_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtMCInfo c5_l_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c5_m_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtMCInfo c5_n_emlrtMCI = { 76,/* lineNo */
  47,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtMCInfo c5_o_emlrtMCI = { 74,/* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtMCInfo c5_p_emlrtMCI = { 79,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtMCInfo c5_q_emlrtMCI = { 81,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtMCInfo c5_r_emlrtMCI = { 49,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c5_s_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c5_t_emlrtMCI = { 51,/* lineNo */
  19,                                  /* colNo */
  "diff",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtMCInfo c5_u_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtMCInfo c5_v_emlrtMCI = { 288,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRSInfo c5_emlrtRSI = { 2,  /* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 3,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_c_emlrtRSI = { 4,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_d_emlrtRSI = { 5,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_e_emlrtRSI = { 6,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_f_emlrtRSI = { 7,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_g_emlrtRSI = { 8,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_h_emlrtRSI = { 12,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_i_emlrtRSI = { 13,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_j_emlrtRSI = { 16,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_k_emlrtRSI = { 22,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_l_emlrtRSI = { 26,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_m_emlrtRSI = { 32,/* lineNo */
  "Image Processing System1/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2706"          /* pathName */
};

static emlrtRSInfo c5_n_emlrtRSI = { 49,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m"/* pathName */
};

static emlrtRSInfo c5_o_emlrtRSI = { 70,/* lineNo */
  "imbinarize",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c5_p_emlrtRSI = { 104,/* lineNo */
  "imbinarize",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c5_q_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_r_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_s_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_t_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c5_u_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c5_v_emlrtRSI = { 85,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c5_w_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c5_x_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c5_y_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c5_ab_emlrtRSI = { 344,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_bb_emlrtRSI = { 346,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_cb_emlrtRSI = { 350,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_db_emlrtRSI = { 352,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_eb_emlrtRSI = { 45,/* lineNo */
  "bwareaopen",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pathName */
};

static emlrtRSInfo c5_fb_emlrtRSI = { 49,/* lineNo */
  "bwareaopen",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pathName */
};

static emlrtRSInfo c5_gb_emlrtRSI = { 63,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_hb_emlrtRSI = { 199,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_ib_emlrtRSI = { 202,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_jb_emlrtRSI = { 205,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_kb_emlrtRSI = { 217,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_lb_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c5_mb_emlrtRSI = { 211,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c5_nb_emlrtRSI = { 198,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c5_ob_emlrtRSI = { 197,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c5_pb_emlrtRSI = { 91,/* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo c5_qb_emlrtRSI = { 80,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c5_rb_emlrtRSI = { 198,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_sb_emlrtRSI = { 239,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_tb_emlrtRSI = { 249,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_ub_emlrtRSI = { 1051,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_vb_emlrtRSI = { 1018,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_wb_emlrtRSI = { 98,/* lineNo */
  "imdilate",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imdilate.m"/* pathName */
};

static emlrtRSInfo c5_xb_emlrtRSI = { 17,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\morphop.m"/* pathName */
};

static emlrtRSInfo c5_yb_emlrtRSI = { 22,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c5_ac_emlrtRSI = { 491,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c5_bc_emlrtRSI = { 713,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c5_cc_emlrtRSI = { 147,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_dc_emlrtRSI = { 149,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_ec_emlrtRSI = { 158,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_fc_emlrtRSI = { 22,/* lineNo */
  "mustBeConnectivity",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\mustBeConnectivity.m"/* pathName */
};

static emlrtRSInfo c5_gc_emlrtRSI = { 20,/* lineNo */
  "mustBeMember",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\validators\\mustBeMember.m"/* pathName */
};

static emlrtRSInfo c5_hc_emlrtRSI = { 243,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_ic_emlrtRSI = { 239,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_jc_emlrtRSI = { 240,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_kc_emlrtRSI = { 256,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_lc_emlrtRSI = { 257,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c5_mc_emlrtRSI = { 14,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c5_nc_emlrtRSI = { 8,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_oc_emlrtRSI = { 87,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_pc_emlrtRSI = { 100,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_qc_emlrtRSI = { 116,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_rc_emlrtRSI = { 191,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_sc_emlrtRSI = { 224,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_tc_emlrtRSI = { 172,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_uc_emlrtRSI = { 179,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c5_vc_emlrtRSI = { 16,/* lineNo */
  "any",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\any.m"/* pathName */
};

static emlrtRSInfo c5_wc_emlrtRSI = { 57,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c5_xc_emlrtRSI = { 106,/* lineNo */
  "applyToMultipleDims",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyToMultipleDims.m"/* pathName */
};

static emlrtRSInfo c5_yc_emlrtRSI = { 63,/* lineNo */
  "function_handle",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

static emlrtRSInfo c5_ad_emlrtRSI = { 56,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c5_bd_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c5_cd_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_dd_emlrtRSI = { 125,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_ed_emlrtRSI = { 328,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_fd_emlrtRSI = { 308,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_gd_emlrtRSI = { 319,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c5_hd_emlrtRSI = { 29,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_id_emlrtRSI = { 26,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c5_jd_emlrtRSI = { 29,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c5_kd_emlrtRSI = { 40,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c5_ld_emlrtRSI = { 56,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_md_emlrtRSI = { 57,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_nd_emlrtRSI = { 58,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_od_emlrtRSI = { 60,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_pd_emlrtRSI = { 61,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_qd_emlrtRSI = { 71,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_rd_emlrtRSI = { 81,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_sd_emlrtRSI = { 220,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_td_emlrtRSI = { 252,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_ud_emlrtRSI = { 291,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_vd_emlrtRSI = { 192,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c5_wd_emlrtRSI = { 14,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_xd_emlrtRSI = { 19,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_yd_emlrtRSI = { 22,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ae_emlrtRSI = { 28,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_be_emlrtRSI = { 31,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ce_emlrtRSI = { 42,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_de_emlrtRSI = { 93,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ee_emlrtRSI = { 97,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_fe_emlrtRSI = { 110,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ge_emlrtRSI = { 124,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_he_emlrtRSI = { 146,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ie_emlrtRSI = { 82,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_je_emlrtRSI = { 148,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_ke_emlrtRSI = { 176,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_le_emlrtRSI = { 171,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_me_emlrtRSI = { 261,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_ne_emlrtRSI = { 172,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_oe_emlrtRSI = { 180,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_pe_emlrtRSI = { 183,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_qe_emlrtRSI = { 11,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_re_emlrtRSI = { 15,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_se_emlrtRSI = { 22,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_te_emlrtRSI = { 26,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ue_emlrtRSI = { 27,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ve_emlrtRSI = { 32,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_we_emlrtRSI = { 35,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_xe_emlrtRSI = { 44,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ye_emlrtRSI = { 98,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_af_emlrtRSI = { 99,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_bf_emlrtRSI = { 100,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_cf_emlrtRSI = { 101,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_df_emlrtRSI = { 15,/* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo c5_ef_emlrtRSI = { 46,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c5_ff_emlrtRSI = { 92,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c5_gf_emlrtRSI = { 208,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c5_hf_emlrtRSI = { 897,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c5_if_emlrtRSI = { 73,/* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo c5_jf_emlrtRSI = { 65,/* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo c5_kf_emlrtRSI = { 114,/* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo c5_lf_emlrtRSI = { 131,/* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo c5_mf_emlrtRSI = { 15,/* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo c5_nf_emlrtRSI = { 44,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c5_of_emlrtRSI = { 79,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c5_pf_emlrtRSI = { 190,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c5_qf_emlrtRSI = { 901,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c5_rf_emlrtRSI = { 111,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_sf_emlrtRSI = { 133,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_tf_emlrtRSI = { 136,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_uf_emlrtRSI = { 140,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_vf_emlrtRSI = { 182,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_wf_emlrtRSI = { 183,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_xf_emlrtRSI = { 168,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_yf_emlrtRSI = { 167,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ag_emlrtRSI = { 13,/* lineNo */
  "any",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\any.m"/* pathName */
};

static emlrtRSInfo c5_bg_emlrtRSI = { 194,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_cg_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c5_dg_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_eg_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_fg_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_gg_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_hg_emlrtRSI = { 231,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ig_emlrtRSI = { 236,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_jg_emlrtRSI = { 241,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_kg_emlrtRSI = { 245,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_lg_emlrtRSI = { 249,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_mg_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\all.m"/* pathName */
};

static emlrtRSInfo c5_ng_emlrtRSI = { 206,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_og_emlrtRSI = { 39,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_pg_emlrtRSI = { 49,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_qg_emlrtRSI = { 52,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_rg_emlrtRSI = { 103,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_sg_emlrtRSI = { 40,/* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo c5_tg_emlrtRSI = { 108,/* lineNo */
  "diff",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRSInfo c5_ug_emlrtRSI = { 106,/* lineNo */
  "diff",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRSInfo c5_vg_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c5_wg_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c5_xg_emlrtRSI = { 86,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c5_yg_emlrtRSI = { 112,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c5_ah_emlrtRSI = { 173,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c5_bh_emlrtRSI = { 192,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c5_ch_emlrtRSI = { 16,/* lineNo */
  "sqrt",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

static emlrtRSInfo c5_dh_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c5_eh_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c5_fh_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_gh_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_hh_emlrtRSI = { 53,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_ih_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_jh_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_kh_emlrtRSI = { 183,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_lh_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_mh_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_nh_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo c5_oh_emlrtRSI = { 76,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_ph_emlrtRSI = { 79,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_qh_emlrtRSI = { 81,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_rh_emlrtRSI = { 84,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_sh_emlrtRSI = { 87,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_th_emlrtRSI = { 90,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_uh_emlrtRSI = { 55,/* lineNo */
  "prodsize",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\prodsize.m"/* pathName */
};

static emlrtRSInfo c5_vh_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_wh_emlrtRSI = { 301,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_xh_emlrtRSI = { 309,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_yh_emlrtRSI = { 310,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ai_emlrtRSI = { 318,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_bi_emlrtRSI = { 326,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ci_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_di_emlrtRSI = { 381,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ei_emlrtRSI = { 409,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_fi_emlrtRSI = { 416,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_gi_emlrtRSI = { 576,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_hi_emlrtRSI = { 578,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ii_emlrtRSI = { 606,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ji_emlrtRSI = { 488,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ki_emlrtRSI = { 495,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_li_emlrtRSI = { 496,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_mi_emlrtRSI = { 503,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ni_emlrtRSI = { 550,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_oi_emlrtRSI = { 519,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_pi_emlrtRSI = { 347,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_qi_emlrtRSI = { 356,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ri_emlrtRSI = { 41,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_si_emlrtRSI = { 113,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRTEInfo c5_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pName */
};

static emlrtRTEInfo c5_b_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_c_emlrtRTEI = { 11,/* lineNo */
  3,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_d_emlrtRTEI = { 12,/* lineNo */
  3,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_e_emlrtRTEI = { 146,/* lineNo */
  24,                                  /* colNo */
  "blockedSummation",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pName */
};

static emlrtRTEInfo c5_f_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pName */
};

static emlrtRTEInfo c5_g_emlrtRTEI = { 13,/* lineNo */
  3,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_h_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c5_i_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_j_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_k_emlrtRTEI = { 29,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_l_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_m_emlrtRTEI = { 32,/* lineNo */
  14,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_n_emlrtRTEI = { 41,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_o_emlrtRTEI = { 32,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_p_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_q_emlrtRTEI = { 34,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_r_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_s_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_t_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_u_emlrtRTEI = { 22,/* lineNo */
  14,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_v_emlrtRTEI = { 22,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_w_emlrtRTEI = { 22,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_x_emlrtRTEI = { 24,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_y_emlrtRTEI = { 26,/* lineNo */
  14,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_ab_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_bb_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_cb_emlrtRTEI = { 205,/* lineNo */
  13,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_db_emlrtRTEI = { 205,/* lineNo */
  22,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_eb_emlrtRTEI = { 171,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_fb_emlrtRTEI = { 172,/* lineNo */
  26,                                  /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_gb_emlrtRTEI = { 106,/* lineNo */
  30,                                  /* colNo */
  "applyToMultipleDims",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyToMultipleDims.m"/* pName */
};

static emlrtRTEInfo c5_hb_emlrtRTEI = { 178,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_ib_emlrtRTEI = { 179,/* lineNo */
  27,                                  /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_jb_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_kb_emlrtRTEI = { 114,/* lineNo */
  8,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c5_lb_emlrtRTEI = { 320,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c5_mb_emlrtRTEI = { 39,/* lineNo */
  22,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_nb_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_ob_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_pb_emlrtRTEI = { 171,/* lineNo */
  38,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_qb_emlrtRTEI = { 72,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_rb_emlrtRTEI = { 82,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_sb_emlrtRTEI = { 220,/* lineNo */
  30,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_tb_emlrtRTEI = { 290,/* lineNo */
  26,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_ub_emlrtRTEI = { 191,/* lineNo */
  39,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c5_vb_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_wb_emlrtRTEI = { 22,/* lineNo */
  5,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_xb_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_yb_emlrtRTEI = { 204,/* lineNo */
  25,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_ac_emlrtRTEI = { 208,/* lineNo */
  5,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_bc_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_cc_emlrtRTEI = { 43,/* lineNo */
  13,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_dc_emlrtRTEI = { 43,/* lineNo */
  32,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_ec_emlrtRTEI = { 44,/* lineNo */
  13,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_fc_emlrtRTEI = { 44,/* lineNo */
  26,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_gc_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_hc_emlrtRTEI = { 99,/* lineNo */
  6,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ic_emlrtRTEI = { 100,/* lineNo */
  6,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_jc_emlrtRTEI = { 101,/* lineNo */
  6,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_kc_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_lc_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_mc_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_nc_emlrtRTEI = { 261,/* lineNo */
  30,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_oc_emlrtRTEI = { 262,/* lineNo */
  30,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_pc_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_qc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_rc_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_sc_emlrtRTEI = { 75,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_tc_emlrtRTEI = { 76,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_uc_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c5_vc_emlrtRTEI = { 100,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_wc_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_xc_emlrtRTEI = { 124,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_yc_emlrtRTEI = { 175,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_ad_emlrtRTEI = { 182,/* lineNo */
  17,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_bd_emlrtRTEI = { 183,/* lineNo */
  56,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_cd_emlrtRTEI = { 183,/* lineNo */
  70,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_dd_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_ed_emlrtRTEI = { 110,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_fd_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_gd_emlrtRTEI = { 41,/* lineNo */
  29,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_hd_emlrtRTEI = { 241,/* lineNo */
  2,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_id_emlrtRTEI = { 241,/* lineNo */
  16,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_jd_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_kd_emlrtRTEI = { 108,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ld_emlrtRTEI = { 109,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_md_emlrtRTEI = { 111,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_nd_emlrtRTEI = { 133,/* lineNo */
  33,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_od_emlrtRTEI = { 194,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_pd_emlrtRTEI = { 203,/* lineNo */
  31,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_qd_emlrtRTEI = { 204,/* lineNo */
  31,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_rd_emlrtRTEI = { 140,/* lineNo */
  26,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_sd_emlrtRTEI = { 140,/* lineNo */
  5,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_td_emlrtRTEI = { 182,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ud_emlrtRTEI = { 183,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_vd_emlrtRTEI = { 159,/* lineNo */
  42,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_wd_emlrtRTEI = { 160,/* lineNo */
  42,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_xd_emlrtRTEI = { 167,/* lineNo */
  60,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_yd_emlrtRTEI = { 168,/* lineNo */
  60,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ae_emlrtRTEI = { 126,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_be_emlrtRTEI = { 127,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ce_emlrtRTEI = { 123,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_de_emlrtRTEI = { 124,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ee_emlrtRTEI = { 116,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_fe_emlrtRTEI = { 117,/* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ge_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_he_emlrtRTEI = { 144,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_ie_emlrtRTEI = { 280,/* lineNo */
  28,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_je_emlrtRTEI = { 303,/* lineNo */
  32,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ke_emlrtRTEI = { 304,/* lineNo */
  32,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_le_emlrtRTEI = { 332,/* lineNo */
  21,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_me_emlrtRTEI = { 395,/* lineNo */
  20,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ne_emlrtRTEI = { 77,/* lineNo */
  23,                                  /* colNo */
  "diff",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c5_oe_emlrtRTEI = { 78,/* lineNo */
  21,                                  /* colNo */
  "diff",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c5_pe_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "diff",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c5_qe_emlrtRTEI = { 37,/* lineNo */
  9,                                   /* colNo */
  "diff",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c5_re_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_se_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_te_emlrtRTEI = { 561,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ue_emlrtRTEI = { 471,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ve_emlrtRTEI = { 509,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_we_emlrtRTEI = { 398,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_xe_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_ye_emlrtRTEI = { 56,/* lineNo */
  24,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_af_emlrtRTEI = { 75,/* lineNo */
  26,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_bf_emlrtRTEI = { 76,/* lineNo */
  39,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_cf_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_df_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ef_emlrtRTEI = { 298,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ff_emlrtRTEI = { 98,/* lineNo */
  8,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_gf_emlrtRTEI = { 98,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_hf_emlrtRTEI = { 114,/* lineNo */
  28,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_if_emlrtRTEI = { 114,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_jf_emlrtRTEI = { 8,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_kf_emlrtRTEI = { 116,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_lf_emlrtRTEI = { 13,/* lineNo */
  36,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_mf_emlrtRTEI = { 71,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_nf_emlrtRTEI = { 171,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c5_of_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_pf_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_qf_emlrtRTEI = { 22,/* lineNo */
  2,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_rf_emlrtRTEI = { 22,/* lineNo */
  18,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_sf_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_tf_emlrtRTEI = { 93,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_uf_emlrtRTEI = { 97,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_vf_emlrtRTEI = { 131,/* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtRTEInfo c5_wf_emlrtRTEI = { 236,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_xf_emlrtRTEI = { 245,/* lineNo */
  6,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_yf_emlrtRTEI = { 136,/* lineNo */
  6,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_ag_emlrtRTEI = { 106,/* lineNo */
  46,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_bg_emlrtRTEI = { 167,/* lineNo */
  13,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtRTEInfo c5_cg_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_dg_emlrtRTEI = { 298,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_eg_emlrtRTEI = { 10,/* lineNo */
  7,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_fg_emlrtRTEI = { 21,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtECInfo c5_emlrtECI = { 2,  /* nDims */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_gg_emlrtRTEI = { 25,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtECInfo c5_b_emlrtECI = { 2,/* nDims */
  26,                                  /* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtRTEInfo c5_hg_emlrtRTEI = { 31,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtECInfo c5_c_emlrtECI = { 2,/* nDims */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706"          /* pName */
};

static emlrtBCInfo c5_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  20,                                  /* colNo */
  "boundary",                          /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_emlrtDCI = { 11, /* lineNo */
  20,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  18,                                  /* colNo */
  "boundary",                          /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_b_emlrtDCI = { 18,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  18,                                  /* colNo */
  "boundary",                          /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_c_emlrtDCI = { 29,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  18,                                  /* colNo */
  "boundary",                          /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_d_emlrtDCI = { 19,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_e_emlrtDCI = { 49,/* lineNo */
  1,                                   /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  20,                                  /* colNo */
  "n",                                 /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  20,                                  /* colNo */
  "n",                                 /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  20,                                  /* colNo */
  "n",                                 /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  22,                                  /* colNo */
  "ll1",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_f_emlrtDCI = { 32,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  31,                                  /* colNo */
  "ll1",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_g_emlrtDCI = { 32,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  22,                                  /* colNo */
  "ll1",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_h_emlrtDCI = { 22,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  31,                                  /* colNo */
  "ll1",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_i_emlrtDCI = { 22,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  22,                                  /* colNo */
  "ll2",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_j_emlrtDCI = { 26,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  31,                                  /* colNo */
  "ll2",                               /* aName */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_k_emlrtDCI = { 26,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System1/MATLAB Function1",/* fName */
  "#flightControlSystem:2706",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_q_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1055,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_r_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1056,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_s_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1057,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_t_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1058,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_u_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  172,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_v_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  367,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_w_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  370,                                 /* lineNo */
  7,                                   /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_x_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  209,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_y_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  197,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ab_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  198,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  201,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  199,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_db_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  336,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_eb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  204,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  202,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  205,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  358,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ib_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  359,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jb_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  217,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  365,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  366,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mb_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  225,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  218,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ob_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  97,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  219,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  106,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  107,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  135,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  136,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ub_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  124,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  111,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  129,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_xb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  125,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  112,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ac_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  153,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  140,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  126,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_dc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  158,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_ec_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  154,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  141,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  155,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_hc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  117,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ic_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  122,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_jc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  118,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  146,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  119,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_mc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  151,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_nc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  147,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  148,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo c5_ig_emlrtRTEI = { 229,/* lineNo */
  21,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_jg_emlrtRTEI = { 228,/* lineNo */
  17,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtECInfo c5_d_emlrtECI = { -1,/* nDims */
  205,                                 /* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtBCInfo c5_pc_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  724,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_qc_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  230,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rc_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  230,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  230,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_tc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  230,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_l_emlrtDCI = { 114,/* lineNo */
  8,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_uc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  114,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_vc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  114,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_wc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  284,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_xc_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  311,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  307,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ad_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  307,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  308,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cd_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  319,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  245,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ed_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  327,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  320,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  321,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  251,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_id_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  252,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  269,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  256,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ld_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  274,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_md_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  270,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  257,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_od_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  271,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_pd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  262,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  267,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_rd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  263,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  264,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo c5_kg_emlrtRTEI = { 186,/* lineNo */
  25,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtBCInfo c5_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_m_emlrtDCI = { 51,/* lineNo */
  37,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_n_emlrtDCI = { 52,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_vd_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  63,                                  /* lineNo */
  83,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wd_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  64,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ae_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  189,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_be_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  194,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_de_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  191,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ee_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  236,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ge_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  238,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_he_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  213,                                 /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ie_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  215,                                 /* lineNo */
  77,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  193,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_o_emlrtDCI = { 191,/* lineNo */
  45,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c5_e_emlrtECI = { 1,/* nDims */
  98,                                  /* lineNo */
  8,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtECInfo c5_f_emlrtECI = { -1,/* nDims */
  98,                                  /* lineNo */
  8,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtBCInfo c5_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  210,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_te_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  210,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  208,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  6,                                   /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_df_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ef_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ff_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  207,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_of_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  267,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  267,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  267,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_uf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  267,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_g_emlrtECI = { 1,/* nDims */
  114,                                 /* lineNo */
  28,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtECInfo c5_h_emlrtECI = { 1,/* nDims */
  128,                                 /* lineNo */
  30,                                  /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtBCInfo c5_xf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_i_emlrtECI = { -1,/* nDims */
  122,                                 /* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtBCInfo c5_ag_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_j_emlrtECI = { -1,/* nDims */
  136,                                 /* lineNo */
  9,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pName */
};

static emlrtBCInfo c5_cg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  176,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  177,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_eg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  175,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_p_emlrtDCI = { 100,/* lineNo */
  1,                                   /* colNo */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_gg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  174,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ig_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  121,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  189,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "adjacencyMatrix",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_k_emlrtECI = { 1,/* nDims */
  111,                                 /* lineNo */
  9,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtBCInfo c5_ng_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_og_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_l_emlrtECI = { 1,/* nDims */
  133,                                 /* lineNo */
  33,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtBCInfo c5_rg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ug_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_m_emlrtECI = { -1,/* nDims */
  168,                                 /* lineNo */
  13,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtECInfo c5_n_emlrtECI = { -1,/* nDims */
  167,                                 /* lineNo */
  13,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtBCInfo c5_xg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  208,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  197,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_o_emlrtECI = { 1,/* nDims */
  195,                                 /* lineNo */
  25,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pName */
};

static emlrtBCInfo c5_ah_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ch_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_eh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  217,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  218,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  210,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  210,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ih_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ph_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  166,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  169,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_th_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  169,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_uh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  176,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  177,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ai_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  174,                                 /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ci_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  174,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_q_emlrtDCI = { 203,/* lineNo */
  37,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_r_emlrtDCI = { 204,/* lineNo */
  37,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_s_emlrtDCI = { 159,/* lineNo */
  48,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_t_emlrtDCI = { 160,/* lineNo */
  48,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_di_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  283,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ei_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  283,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  284,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  284,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_u_emlrtDCI = { 280,/* lineNo */
  34,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_ii_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  308,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ji_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  308,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ki_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  309,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_li_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  309,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  310,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ni_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  310,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  311,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  311,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ri_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_si_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  315,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ti_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  315,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ui_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  319,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  319,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_v_emlrtDCI = { 303,/* lineNo */
  38,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c5_w_emlrtDCI = { 304,/* lineNo */
  38,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_xi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  363,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yi_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  341,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_aj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  341,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  341,                                 /* lineNo */
  77,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  341,                                 /* lineNo */
  79,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  344,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ej_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  344,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  344,                                 /* lineNo */
  79,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  344,                                 /* lineNo */
  83,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  354,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ij_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  354,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  402,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  402,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  402,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  402,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  403,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oj_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  404,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c5_ti_emlrtRSI = { 61,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ui_emlrtRSI = { 75,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_vi_emlrtRSI = { 76,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_wi_emlrtRSI = { 75,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_xi_emlrtRSI = { 290,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_yi_emlrtRSI = { 56,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_aj_emlrtRSI = { 30,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_bj_emlrtRSI = { 280,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_cj_emlrtRSI = { 117,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_dj_emlrtRSI = { 116,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ej_emlrtRSI = { 124,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_fj_emlrtRSI = { 123,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_gj_emlrtRSI = { 127,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_hj_emlrtRSI = { 126,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_ij_emlrtRSI = { 160,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_jj_emlrtRSI = { 159,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_kj_emlrtRSI = { 44,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_lj_emlrtRSI = { 43,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_mj_emlrtRSI = { 37,/* lineNo */
  "diff",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRSInfo c5_nj_emlrtRSI = { 47,/* lineNo */
  "diff",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRSInfo c5_oj_emlrtRSI = { 78,/* lineNo */
  "diff",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRSInfo c5_pj_emlrtRSI = { 304,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_qj_emlrtRSI = { 303,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_rj_emlrtRSI = { 39,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_sj_emlrtRSI = { 191,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c5_tj_emlrtRSI = { 82,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_uj_emlrtRSI = { 72,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_vj_emlrtRSI = { 51,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_wj_emlrtRSI = { 398,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_xj_emlrtRSI = { 332,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static emlrtRSInfo c5_yj_emlrtRSI = { 101,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ak_emlrtRSI = { 100,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_bk_emlrtRSI = { 52,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c5_ck_emlrtRSI = { 12,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_dk_emlrtRSI = { 117,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_ek_emlrtRSI = { 131,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_fk_emlrtRSI = { 128,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_gk_emlrtRSI = { 114,/* lineNo */
  "adjacencyMatrix",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\+tomex\\adjacencyMatrix.m"/* pathName */
};

static emlrtRSInfo c5_hk_emlrtRSI = { 195,/* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\inpolygon.m"/* pathName */
};

static char_T c5_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

static char_T c5_cv1[39] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'v', 'a', 'l',
  'i', 'd', 'a', 't', 'e', ':', 'u', 'n', 'e', 'q', 'u', 'a', 'l', 'N', 'u', 'm',
  'b', 'e', 'r', 'O', 'f', 'E', 'l', 'e', 'm', 'e', 'n', 't', 's' };

static char_T c5_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c5_cv3[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_', 'm',
  'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

static char_T c5_cv4[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static char_T c5_cv5[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_', 'a',
  'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p',
  'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

/* Function Declarations */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st);
static void c5_imbinarize(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_I[19200], boolean_T c5_BW[19200]);
static void c5_bwlabel(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T c5_c_L[19200],
  real_T *c5_numComponents);
static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp);
static void c5_imfill(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
                      boolean_T c5_I2[19200]);
static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, uint8_T c5_varargin_1[19200], boolean_T
                    c5_varargout_1[19200]);
static real_T c5_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_x[19200], int32_T c5_vstart);
static real_T c5_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_x[19200]);
static void c5_bwboundaries(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  c5_coder_array_cell_wrap_0 *c5_B, real_T c5_c_L[19200], real_T *c5_b_N,
  c5_coder_array_boolean_T_2D *c5_A);
static boolean_T c5_allOrAny_anonFcn1(SFc5_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c5_x_data[]);
static void c5_eml_float_colon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_a, real_T c5_c_b, real_T
  c5_y_data[], int32_T c5_y_size[2]);
static void c5_b_bwlabel(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T c5_c_L[19200],
  real_T *c5_numComponents);
static void c5_BoundaryFinderObjectHoles_findBoundaries
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_images_internal_coder_BoundaryFinderObjectHoles *c5_obj, real_T
   c5_cutoffL, real_T c5_holesN, c5_coder_array_cell_wrap_0 *c5_B);
static void c5_expandScratchSpace(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_scratchIn,
  int32_T c5_scratchLengthIn, c5_coder_array_int32_T *c5_scratch, int32_T
  *c5_scratchLength);
static void c5_BoundaryFinder_copyCoordsToBuf
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_images_internal_coder_BoundaryFinderObjectHoles *c5_obj, int32_T
   c5_numPixels, c5_coder_array_int32_T *c5_linearIndices,
   c5_coder_array_real_T_2D *c5_boundary);
static void c5_adjacencyMatrix(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_cell_wrap_0 *c5_B,
  real_T c5_b_N, c5_coder_array_boolean_T_2D *c5_A);
static void c5_groupBoundariesByTreeLevelCodegen
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_cell_wrap_0 *c5_B, int32_T c5_numObjs, int32_T
   *c5_numLevels, c5_coder_array_int32_T *c5_groupedIndices,
   c5_coder_array_int32_T *c5_numElemsPerGroup);
static void c5_eml_integer_colon_dispatcher
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, int32_T c5_a, int32_T c5_c_b, c5_coder_array_int32_T_2D *c5_y);
static boolean_T c5_inpolygon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_points_x, real_T
  c5_points_y, c5_coder_array_real_T *c5_polygon_x, c5_coder_array_real_T
  *c5_polygon_y);
static real_T c5_minimum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x);
static real_T c5_maximum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x);
static void c5_closeLoops(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_polygon_x,
  c5_coder_array_real_T *c5_polygon_y, c5_coder_array_real_T *c5_closedPolygon_x,
  c5_coder_array_real_T *c5_closedPolygon_y);
static boolean_T c5_any(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x);
static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2]);
static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x,
  c5_coder_array_int32_T *c5_i);
static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp);
static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp);
static void c5_computeScaledEps(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_polygon_x,
  c5_coder_array_real_T *c5_polygon_y, c5_coder_array_real_T *c5_scaledEps);
static void c5_computeCrossAndDotProducts(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_transPoly_x, c5_coder_array_real_T_2D *c5_transPoly_y,
  c5_coder_array_real_T *c5_scaledEps, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd);
static void c5_findInsidePoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_transPolygon_x, c5_coder_array_real_T_2D *c5_transPolygon_y,
  c5_coder_array_real_T_2D *c5_signCrossProd, c5_coder_array_boolean_T *c5_in);
static void c5_findBoundaryPoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd,
  c5_coder_array_boolean_T *c5_in, c5_coder_array_boolean_T *c5_on,
  c5_coder_array_boolean_T *c5_b_in);
static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x);
static void c5_assertValidSizeArg(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_1[2]);
static void c5_diff(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_x,
                    c5_coder_array_real_T_2D *c5_y);
static real_T c5_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, real_T c5_varargin_1);
static real_T c5_sum(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x);
static real_T c5_b_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, int32_T
  c5_vlen);
static real_T c5_b_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_x, int32_T c5_vstart);
static real_T c5_c_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, int32_T
  c5_vlen, int32_T c5_vstart);
static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T *c5_x,
                    c5_coder_array_real_T *c5_b_x, c5_coder_array_int32_T
                    *c5_idx);
static void c5_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, c5_coder_array_int32_T
  *c5_idx, c5_coder_array_real_T *c5_b_x);
static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset, c5_coder_array_int32_T
  *c5_b_idx, c5_coder_array_real_T *c5_b_x);
static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx, c5_coder_array_real_T
  *c5_x, int32_T c5_offset, int32_T c5_n, int32_T c5_preSortLevel,
  c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T *c5_xwork,
  c5_coder_array_int32_T *c5_b_idx, c5_coder_array_real_T *c5_b_x,
  c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork);
static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
                     c5_coder_array_real_T *c5_x, int32_T c5_offset, int32_T
                     c5_np, int32_T c5_nq, c5_coder_array_int32_T *c5_iwork,
                     c5_coder_array_real_T *c5_xwork, c5_coder_array_int32_T
                     *c5_b_idx, c5_coder_array_real_T *c5_b_x,
                     c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T
                     *c5_b_xwork);
static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T c5_y[19200]);
static void c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T c5_y[19200]);
static void c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_nullptr, const
  char_T *c5_identifier, c5_coder_array_real_T_2D *c5_y);
static void c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_u, const
  emlrtMsgIdentifier *c5_parentId, c5_coder_array_real_T_2D *c5_y);
static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig);
static void c5_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, const mxArray *c5_input0, const
                     mxArray *c5_input1, const mxArray *c5_input2);
static const mxArray *c5_assert(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static const mxArray *c5_b_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static void c5_c_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1);
static const mxArray *c5_d_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static void c5_e_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1);
static void c5_b_findBoundaryPoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd,
  c5_coder_array_boolean_T *c5_in, c5_coder_array_boolean_T *c5_on);
static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x,
                      c5_coder_array_int32_T *c5_idx);
static void c5_b_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, c5_coder_array_int32_T
  *c5_idx);
static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset);
static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork);
static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx, c5_coder_array_real_T
  *c5_x, int32_T c5_offset, int32_T c5_np, int32_T c5_nq, c5_coder_array_int32_T
  *c5_iwork, c5_coder_array_real_T *c5_xwork);
static void c5_and(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_in1,
                   c5_coder_array_boolean_T *c5_in2);
static void c5_or(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                  emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_in1,
                  c5_coder_array_boolean_T *c5_in2);
static void c5_array_int32_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_cell_wrap_0_SetSize(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_cell_wrap_0
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_2D_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T_2D *c5_coderArray);
static void c5_array_cell_wrap_0_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_0
   *c5_pStruct);
static void c5_array_cell_wrap_0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_0
   *c5_pStruct);
static void c5_array_real_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray);
static void c5_array_boolean_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_boolean_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_int32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_cell_wrap_0_Constructor1
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_0 *c5_coderArray);
static void c5_array_boolean_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray);
static void c5_array_real_T_Constructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray);
static void c5_array_cell_41_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_cell_41 *c5_pStruct);
static void c5_array_int32_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_int32_T *c5_coderArray);
static void c5_array_cell_wrap_0_Destructor1
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_0 *c5_coderArray);
static void c5_array_boolean_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray);
static void c5_array_real_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray);
static void c5_array_cell_41_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_cell_41 *c5_pStruct);
static void c5_array_int32_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_coderArray);
static void c5_array_boolean_T_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T *c5_coderArray);
static void c5_array_boolean_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_boolean_T *c5_coderArray);
static void c5_array_int32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray);
static void c5_array_int32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray);
static int32_T c5_div_s32_ndbzs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc);
static int32_T c5_div_nzp_s32(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc);
static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c5_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_doneDoubleBufferReInit = false;
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c5_JITStateAnimation[0],
                        &chartInstance->c5_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    62U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 4U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "c5_flightControlSystem", 0, -1, 868);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 455, 462, 673,
                    868, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 673, 693, 812,
                    868, false);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 280, 304, 419);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 527, 546, 591);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 608, 627, 672);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 734, 753, 798);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 458,
    462, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 680,
    693, -1, 1U);
}

static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static real_T c5_dv[6] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static char_T c5_b_cv1[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  static char_T c5_b_cv2[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  static char_T c5_b_cv3[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  static boolean_T c5_nhood[25] = { false, false, true, false, false, false,
    true, true, true, false, true, true, true, true, true, false, true, true,
    true, false, false, false, true, false, false };

  c5_cell_41 c5_reshapes;
  c5_coder_array_boolean_T_2D c5_a__2;
  c5_coder_array_cell_wrap_0 c5_boundary;
  c5_coder_array_int32_T c5_regionLengths;
  c5_coder_array_real_T c5_perimeter;
  c5_coder_array_real_T c5_y;
  c5_coder_array_real_T_2D c5_b_ln1;
  c5_coder_array_real_T_2D c5_b_varargin_1;
  c5_coder_array_real_T_2D c5_bound;
  c5_coder_array_real_T_2D c5_ll2;
  c5_coder_array_real_T_2D c5_ln1;
  c5_coder_array_real_T_2D c5_ln2;
  c5_coder_array_real_T_2D c5_varargin_1;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_g_st;
  emlrtStack c5_h_st;
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  emlrtStack *c5_c_r;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  real_T c5_asizeT[2];
  real_T c5_nsizeT[2];
  real_T c5_b_N;
  real_T c5_b_c;
  real_T c5_b_k;
  real_T c5_b_numComponents;
  real_T c5_b_r;
  real_T c5_b_varargin_2;
  real_T c5_b_varargin_3;
  real_T c5_b_x;
  real_T c5_c_N;
  real_T c5_c_i;
  real_T c5_c_varargin_2;
  real_T c5_c_varargin_3;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d10;
  real_T c5_d11;
  real_T c5_d12;
  real_T c5_d13;
  real_T c5_d14;
  real_T c5_d15;
  real_T c5_d16;
  real_T c5_d17;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d8;
  real_T c5_d9;
  real_T c5_d_k;
  real_T c5_d_varargin_2;
  real_T c5_d_varargin_3;
  real_T c5_e_varargin_2;
  real_T c5_e_varargin_3;
  real_T c5_f_varargin_2;
  real_T c5_f_varargin_3;
  real_T c5_g_varargin_2;
  real_T c5_g_varargin_3;
  real_T c5_h_varargin_2;
  real_T c5_h_varargin_3;
  real_T c5_i_varargin_2;
  real_T c5_i_varargin_3;
  real_T c5_numComponents;
  real_T c5_varargin_2;
  real_T c5_varargin_3;
  real_T c5_x;
  int32_T c5_b_input_sizes[2];
  int32_T c5_input_sizes[2];
  int32_T c5_a;
  int32_T c5_ab_loop_ub;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_pixelIdx;
  int32_T c5_b_xj;
  int32_T c5_bb_loop_ub;
  int32_T c5_c;
  int32_T c5_c_c;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_c_result;
  int32_T c5_c_xj;
  int32_T c5_cb_loop_ub;
  int32_T c5_d_b;
  int32_T c5_d_i;
  int32_T c5_d_loop_ub;
  int32_T c5_e_b;
  int32_T c5_e_i;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_f_loop_ub;
  int32_T c5_f_result;
  int32_T c5_g_b;
  int32_T c5_g_loop_ub;
  int32_T c5_h_b;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i11;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i12;
  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  int32_T c5_i13;
  int32_T c5_i130;
  int32_T c5_i131;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_b;
  int32_T c5_i_loop_ub;
  int32_T c5_i_result;
  int32_T c5_ix;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n_loop_ub;
  int32_T c5_nx;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_pixelIdx;
  int32_T c5_pixelVal;
  int32_T c5_q_loop_ub;
  int32_T c5_r;
  int32_T c5_r_loop_ub;
  int32_T c5_s_loop_ub;
  int32_T c5_t_loop_ub;
  int32_T c5_u_loop_ub;
  int32_T c5_v_loop_ub;
  int32_T c5_vstride;
  int32_T c5_w_loop_ub;
  int32_T c5_x_loop_ub;
  int32_T c5_xj;
  int32_T c5_y_loop_ub;
  uint8_T c5_greyimg[19200];
  boolean_T c5_B[19200];
  boolean_T c5_b_bw[19200];
  boolean_T c5_c_bw[19200];
  boolean_T c5_edg[19200];
  boolean_T c5_b1;
  boolean_T c5_b10;
  boolean_T c5_b11;
  boolean_T c5_b12;
  boolean_T c5_b13;
  boolean_T c5_b14;
  boolean_T c5_b15;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b9;
  boolean_T c5_b_overflow;
  boolean_T c5_b_p;
  boolean_T c5_b_result;
  boolean_T c5_c_b;
  boolean_T c5_c_overflow;
  boolean_T c5_d_result;
  boolean_T c5_e_result;
  boolean_T c5_g_result;
  boolean_T c5_h_result;
  boolean_T c5_overflow;
  boolean_T c5_p;
  boolean_T c5_result;
  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_g_st.prev = &c5_f_st;
  c5_g_st.tls = c5_f_st.tls;
  c5_h_st.prev = &c5_g_st;
  c5_h_st.tls = c5_g_st.tls;
  for (c5_i = 0; c5_i < 57600; c5_i++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U, (real_T)
                      (*chartInstance->c5_imgin)[c5_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  chartInstance->c5_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  c5_b_st.site = &c5_emlrtRSI;
  c5_c_st.site = &c5_n_emlrtRSI;
  rgb2gray_tbb_uint8(&(*chartInstance->c5_imgin)[0], 19200.0, &c5_greyimg[0],
                     true);
  c5_b_st.site = &c5_b_emlrtRSI;
  c5_imbinarize(chartInstance, &c5_b_st, c5_greyimg, c5_b_bw);
  c5_b_st.site = &c5_c_emlrtRSI;
  c5_c_st.site = &c5_eb_emlrtRSI;
  c5_bwlabel(chartInstance, &c5_c_st, c5_b_bw, chartInstance->c5_L,
             &c5_numComponents);
  c5_c_st.site = &c5_fb_emlrtRSI;
  c5_b_numComponents = c5_numComponents;
  c5_array_int32_T_Constructor(chartInstance, &c5_regionLengths);
  if (c5_b_numComponents != (real_T)(int32_T)muDoubleScalarFloor
      (c5_b_numComponents)) {
    emlrtIntegerCheckR2012b(c5_b_numComponents, &c5_e_emlrtDCI, &c5_c_st);
  }

  c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_regionLengths,
    &c5_emlrtRTEI, (int32_T)c5_b_numComponents);
  if (c5_b_numComponents != (real_T)(int32_T)muDoubleScalarFloor
      (c5_b_numComponents)) {
    emlrtIntegerCheckR2012b(c5_b_numComponents, &c5_e_emlrtDCI, &c5_c_st);
  }

  c5_loop_ub = (int32_T)c5_b_numComponents - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_regionLengths.vector.data[c5_i1] = 0;
  }

  for (c5_pixelIdx = 0; c5_pixelIdx < 19200; c5_pixelIdx++) {
    c5_b_pixelIdx = c5_pixelIdx;
    c5_pixelVal = (int32_T)chartInstance->c5_L[c5_b_pixelIdx];
    if (c5_pixelVal > 0) {
      c5_i3 = c5_regionLengths.size[0];
      if ((c5_pixelVal < 1) || (c5_pixelVal > c5_i3)) {
        emlrtDynamicBoundsCheckR2012b(c5_pixelVal, 1, c5_i3, &c5_e_emlrtBCI,
          &c5_c_st);
      }

      c5_a = c5_regionLengths.vector.data[c5_pixelVal - 1] + 1;
      c5_c_c = c5_a;
      c5_i6 = c5_regionLengths.size[0];
      if ((c5_pixelVal < 1) || (c5_pixelVal > c5_i6)) {
        emlrtDynamicBoundsCheckR2012b(c5_pixelVal, 1, c5_i6, &c5_f_emlrtBCI,
          &c5_c_st);
      }

      c5_regionLengths.vector.data[c5_pixelVal - 1] = c5_c_c;
    }
  }

  for (c5_c = 0; c5_c < 160; c5_c++) {
    c5_b_c = (real_T)c5_c + 1.0;
    for (c5_r = 0; c5_r < 120; c5_r++) {
      c5_b_r = (real_T)c5_r + 1.0;
      if (c5_b_bw[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1]) {
        c5_i4 = c5_regionLengths.size[0];
        c5_i5 = (int32_T)chartInstance->c5_L[((int32_T)c5_b_r + 120 * ((int32_T)
          c5_b_c - 1)) - 1];
        if ((c5_i5 < 1) || (c5_i5 > c5_i4)) {
          emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i4, &c5_g_emlrtBCI,
            &c5_b_st);
        }

        if (c5_regionLengths.vector.data[c5_i5 - 1] < 30) {
          c5_b_bw[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] = false;
        }
      }
    }
  }

  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    c5_c_bw[c5_i2] = c5_b_bw[c5_i2];
  }

  c5_b_st.site = &c5_d_emlrtRSI;
  c5_imfill(chartInstance, &c5_b_st, c5_c_bw, c5_b_bw);
  c5_b_st.site = &c5_e_emlrtRSI;
  c5_edge(chartInstance, &c5_b_st, c5_greyimg, c5_edg);
  c5_b_st.site = &c5_f_emlrtRSI;
  c5_c_st.site = &c5_wb_emlrtRSI;
  c5_d_st.site = &c5_xb_emlrtRSI;
  c5_e_st.site = &c5_yb_emlrtRSI;
  c5_f_st.site = &c5_ac_emlrtRSI;
  c5_g_st.site = &c5_bc_emlrtRSI;
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_asizeT[c5_i7] = 120.0 + 40.0 * (real_T)c5_i7;
  }

  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    c5_nsizeT[c5_i8] = 5.0;
  }

  dilate_binary_twod_tbb(&c5_edg[0], &c5_asizeT[0], 2.0, &c5_nhood[0],
    &c5_nsizeT[0], 2.0, &c5_B[0]);
  for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
    c5_edg[c5_i9] = c5_B[c5_i9];
  }

  c5_array_cell_wrap_0_Constructor1(chartInstance, &c5_boundary);
  c5_array_boolean_T_2D_Constructor(chartInstance, &c5_a__2);
  c5_b_st.site = &c5_g_emlrtRSI;
  c5_bwboundaries(chartInstance, &c5_b_st, c5_edg, &c5_boundary,
                  chartInstance->c5_L, &c5_b_N, &c5_a__2);
  c5_array_boolean_T_2D_Destructor(chartInstance, &c5_a__2);
  c5_c_N = c5_b_N;
  c5_array_real_T_Constructor(chartInstance, &c5_perimeter);
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_perimeter, &c5_b_emlrtRTEI,
    0);
  c5_d = (real_T)c5_boundary.size[0];
  c5_i10 = (int32_T)c5_d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d, mxDOUBLE_CLASS, c5_i10,
    &c5_eg_emlrtRTEI, &c5_st);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_bound);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_ll2);
  c5_array_real_T_Constructor(chartInstance, &c5_y);
  for (c5_k = 0; c5_k < c5_i10; c5_k++) {
    c5_b_k = 1.0 + (real_T)c5_k;
    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 1);
    c5_i11 = c5_boundary.size[0] - 1;
    if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
      emlrtIntegerCheckR2012b(c5_b_k, &c5_emlrtDCI, &c5_st);
    }

    c5_i12 = (int32_T)c5_b_k - 1;
    if ((c5_i12 < 0) || (c5_i12 > c5_i11)) {
      emlrtDynamicBoundsCheckR2012b(c5_i12, 0, c5_i11, &c5_emlrtBCI, &c5_st);
    }

    c5_i14 = c5_i12;
    c5_i15 = c5_boundary.vector.data[c5_i14].f1.size[0];
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_bound, &c5_c_emlrtRTEI,
      c5_i15, 2);
    c5_i16 = c5_boundary.size[0] - 1;
    if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
      emlrtIntegerCheckR2012b(c5_b_k, &c5_emlrtDCI, &c5_st);
    }

    c5_i17 = (int32_T)c5_b_k - 1;
    if ((c5_i17 < 0) || (c5_i17 > c5_i16)) {
      emlrtDynamicBoundsCheckR2012b(c5_i17, 0, c5_i16, &c5_emlrtBCI, &c5_st);
    }

    c5_i19 = c5_i17;
    c5_i22 = c5_boundary.size[0] - 1;
    if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
      emlrtIntegerCheckR2012b(c5_b_k, &c5_emlrtDCI, &c5_st);
    }

    c5_i27 = (int32_T)c5_b_k - 1;
    if ((c5_i27 < 0) || (c5_i27 > c5_i22)) {
      emlrtDynamicBoundsCheckR2012b(c5_i27, 0, c5_i22, &c5_emlrtBCI, &c5_st);
    }

    c5_c_loop_ub = (c5_boundary.vector.data[c5_i19].f1.size[0] << 1) - 1;
    for (c5_i30 = 0; c5_i30 <= c5_c_loop_ub; c5_i30++) {
      c5_i32 = c5_boundary.size[0] - 1;
      if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
        emlrtIntegerCheckR2012b(c5_b_k, &c5_emlrtDCI, &c5_st);
      }

      c5_i37 = (int32_T)c5_b_k - 1;
      if ((c5_i37 < 0) || (c5_i37 > c5_i32)) {
        emlrtDynamicBoundsCheckR2012b(c5_i37, 0, c5_i32, &c5_emlrtBCI, &c5_st);
      }

      c5_bound.vector.data[c5_i30] = c5_boundary.vector.data[c5_i37].
        f1.vector.data[c5_i30];
    }

    c5_b_st.site = &c5_h_emlrtRSI;
    c5_diff(chartInstance, &c5_b_st, &c5_bound, &c5_ll2);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_bound, &c5_d_emlrtRTEI,
      c5_ll2.size[0], 2);
    c5_d_loop_ub = (c5_ll2.size[0] << 1) - 1;
    for (c5_i39 = 0; c5_i39 <= c5_d_loop_ub; c5_i39++) {
      c5_bound.vector.data[c5_i39] = c5_function_handle_parenReference
        (chartInstance, c5_ll2.vector.data[c5_i39]);
    }

    c5_b_st.site = &c5_i_emlrtRSI;
    c5_c_st.site = &c5_vg_emlrtRSI;
    c5_d_st.site = &c5_wg_emlrtRSI;
    c5_e_st.site = &c5_xg_emlrtRSI;
    c5_c_b = (c5_bound.size[0] == 0);
    if (c5_c_b) {
      for (c5_i47 = 0; c5_i47 < 2; c5_i47++) {
        c5_asizeT[c5_i47] = (real_T)c5_bound.size[c5_i47];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_e_st, &c5_y, &c5_f_emlrtRTEI,
        (int32_T)c5_asizeT[0]);
      c5_f_loop_ub = (int32_T)c5_asizeT[0] - 1;
      for (c5_i54 = 0; c5_i54 <= c5_f_loop_ub; c5_i54++) {
        c5_y.vector.data[c5_i54] = 0.0;
      }
    } else {
      c5_f_st.site = &c5_yg_emlrtRSI;
      c5_vstride = c5_bound.size[0];
      for (c5_i50 = 0; c5_i50 < 2; c5_i50++) {
        c5_asizeT[c5_i50] = (real_T)c5_bound.size[c5_i50];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_f_st, &c5_y, &c5_e_emlrtRTEI,
        (int32_T)c5_asizeT[0]);
      c5_g_st.site = &c5_ah_emlrtRSI;
      c5_d_b = c5_vstride;
      c5_e_b = c5_d_b;
      if (c5_e_b < 1) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_e_b > 2147483646);
      }

      if (c5_overflow) {
        c5_h_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_h_st);
      }

      for (c5_xj = 0; c5_xj < c5_vstride; c5_xj++) {
        c5_b_xj = c5_xj;
        c5_y.vector.data[c5_b_xj] = c5_bound.vector.data[c5_b_xj];
      }

      c5_g_st.site = &c5_bh_emlrtRSI;
      c5_f_b = c5_vstride;
      c5_g_b = c5_f_b;
      if (c5_g_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_g_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_h_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_h_st);
      }

      for (c5_c_xj = 0; c5_c_xj < c5_vstride; c5_c_xj++) {
        c5_b_xj = c5_c_xj;
        c5_ix = c5_vstride + c5_b_xj;
        c5_y.vector.data[c5_b_xj] += c5_bound.vector.data[c5_ix];
      }
    }

    c5_b_st.site = &c5_i_emlrtRSI;
    c5_p = false;
    c5_d6 = (real_T)c5_y.size[0];
    c5_i62 = (int32_T)c5_d6 - 1;
    for (c5_c_k = 0; c5_c_k <= c5_i62; c5_c_k++) {
      c5_d_k = (real_T)c5_c_k + 1.0;
      if (c5_p || (c5_y.vector.data[(int32_T)c5_d_k - 1] < 0.0)) {
        c5_b_p = true;
      } else {
        c5_b_p = false;
      }

      c5_p = c5_b_p;
    }

    if (c5_p) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                    false);
      sf_mex_call(&c5_b_st, &c5_e_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_b_st, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
    }

    c5_c_st.site = &c5_ch_emlrtRSI;
    c5_nx = c5_y.size[0];
    c5_d_st.site = &c5_dh_emlrtRSI;
    c5_h_b = c5_nx;
    c5_i_b = c5_h_b;
    if (c5_i_b < 1) {
      c5_c_overflow = false;
    } else {
      c5_c_overflow = (c5_i_b > 2147483646);
    }

    if (c5_c_overflow) {
      c5_e_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
    }

    for (c5_e_k = 0; c5_e_k < c5_nx; c5_e_k++) {
      c5_f_k = c5_e_k;
      c5_x = c5_y.vector.data[c5_f_k];
      c5_b_x = c5_x;
      c5_b_x = muDoubleScalarSqrt(c5_b_x);
      c5_y.vector.data[c5_f_k] = c5_b_x;
    }

    c5_b_st.site = &c5_i_emlrtRSI;
    c5_c_r = &c5_b_st;
    c5_d12 = c5_sum(chartInstance, c5_c_r, &c5_y);
    c5_i86 = c5_perimeter.size[0];
    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_perimeter,
      &c5_g_emlrtRTEI, c5_perimeter.size[0] + 1);
    c5_perimeter.vector.data[c5_i86] = c5_d12;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c5_array_real_T_Destructor(chartInstance, &c5_y);
  covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 0);
  c5_b_st.site = &c5_j_emlrtRSI;
  c5_c_st.site = &c5_nh_emlrtRSI;
  c5_b_sort(chartInstance, &c5_c_st, &c5_perimeter, &c5_regionLengths);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_perimeter,
    &c5_h_emlrtRTEI, c5_regionLengths.size[0]);
  c5_b_loop_ub = c5_regionLengths.size[0] - 1;
  for (c5_i13 = 0; c5_i13 <= c5_b_loop_ub; c5_i13++) {
    c5_perimeter.vector.data[c5_i13] = (real_T)
      c5_regionLengths.vector.data[c5_i13];
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_regionLengths);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_ln1);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_ln2);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_ln1);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_varargin_1);
  c5_array_cell_41_Constructor(chartInstance, &c5_reshapes);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_varargin_1);
  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 0U, c5_c_N, 2.0, -1, 5U, c5_c_N >= 2.0))) {
    c5_i18 = c5_boundary.size[0] - 1;
    c5_i21 = c5_perimeter.size[0];
    c5_i25 = 1;
    if ((c5_i25 < 1) || (c5_i25 > c5_i21)) {
      emlrtDynamicBoundsCheckR2012b(c5_i25, 1, c5_i21, &c5_h_emlrtBCI, &c5_st);
    }

    c5_d1 = c5_perimeter.vector.data[c5_i25 - 1];
    if (c5_d1 != (real_T)(int32_T)muDoubleScalarFloor(c5_d1)) {
      emlrtIntegerCheckR2012b(c5_d1, &c5_b_emlrtDCI, &c5_st);
    }

    c5_i29 = (int32_T)c5_d1 - 1;
    if ((c5_i29 < 0) || (c5_i29 > c5_i18)) {
      emlrtDynamicBoundsCheckR2012b(c5_i29, 0, c5_i18, &c5_b_emlrtBCI, &c5_st);
    }

    c5_i33 = c5_i29;
    c5_i35 = c5_boundary.vector.data[c5_i33].f1.size[0];
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_bound, &c5_r_emlrtRTEI,
      c5_i35, 2);
    c5_i38 = c5_boundary.size[0] - 1;
    c5_i41 = c5_perimeter.size[0];
    c5_i43 = 1;
    if ((c5_i43 < 1) || (c5_i43 > c5_i41)) {
      emlrtDynamicBoundsCheckR2012b(c5_i43, 1, c5_i41, &c5_h_emlrtBCI, &c5_st);
    }

    c5_d3 = c5_perimeter.vector.data[c5_i43 - 1];
    if (c5_d3 != (real_T)(int32_T)muDoubleScalarFloor(c5_d3)) {
      emlrtIntegerCheckR2012b(c5_d3, &c5_b_emlrtDCI, &c5_st);
    }

    c5_i46 = (int32_T)c5_d3 - 1;
    if ((c5_i46 < 0) || (c5_i46 > c5_i38)) {
      emlrtDynamicBoundsCheckR2012b(c5_i46, 0, c5_i38, &c5_b_emlrtBCI, &c5_st);
    }

    c5_i51 = c5_i46;
    c5_i53 = c5_boundary.size[0] - 1;
    c5_i56 = c5_perimeter.size[0];
    c5_i58 = 1;
    if ((c5_i58 < 1) || (c5_i58 > c5_i56)) {
      emlrtDynamicBoundsCheckR2012b(c5_i58, 1, c5_i56, &c5_h_emlrtBCI, &c5_st);
    }

    c5_d5 = c5_perimeter.vector.data[c5_i58 - 1];
    if (c5_d5 != (real_T)(int32_T)muDoubleScalarFloor(c5_d5)) {
      emlrtIntegerCheckR2012b(c5_d5, &c5_b_emlrtDCI, &c5_st);
    }

    c5_i63 = (int32_T)c5_d5 - 1;
    if ((c5_i63 < 0) || (c5_i63 > c5_i53)) {
      emlrtDynamicBoundsCheckR2012b(c5_i63, 0, c5_i53, &c5_b_emlrtBCI, &c5_st);
    }

    c5_i_loop_ub = (c5_boundary.vector.data[c5_i51].f1.size[0] << 1) - 1;
    for (c5_i66 = 0; c5_i66 <= c5_i_loop_ub; c5_i66++) {
      c5_i70 = c5_boundary.size[0] - 1;
      c5_i73 = c5_perimeter.size[0];
      c5_i76 = 1;
      if ((c5_i76 < 1) || (c5_i76 > c5_i73)) {
        emlrtDynamicBoundsCheckR2012b(c5_i76, 1, c5_i73, &c5_h_emlrtBCI, &c5_st);
      }

      c5_d10 = c5_perimeter.vector.data[c5_i76 - 1];
      if (c5_d10 != (real_T)(int32_T)muDoubleScalarFloor(c5_d10)) {
        emlrtIntegerCheckR2012b(c5_d10, &c5_b_emlrtDCI, &c5_st);
      }

      c5_i80 = (int32_T)c5_d10 - 1;
      if ((c5_i80 < 0) || (c5_i80 > c5_i70)) {
        emlrtDynamicBoundsCheckR2012b(c5_i80, 0, c5_i70, &c5_b_emlrtBCI, &c5_st);
      }

      c5_bound.vector.data[c5_i66] = c5_boundary.vector.data[c5_i80].
        f1.vector.data[c5_i66];
    }

    c5_i69 = c5_boundary.size[0] - 1;
    c5_i72 = c5_perimeter.size[0];
    c5_i75 = 2;
    if ((c5_i75 < 1) || (c5_i75 > c5_i72)) {
      emlrtDynamicBoundsCheckR2012b(c5_i75, 1, c5_i72, &c5_j_emlrtBCI, &c5_st);
    }

    c5_d9 = c5_perimeter.vector.data[c5_i75 - 1];
    if (c5_d9 != (real_T)(int32_T)muDoubleScalarFloor(c5_d9)) {
      emlrtIntegerCheckR2012b(c5_d9, &c5_d_emlrtDCI, &c5_st);
    }

    c5_i79 = (int32_T)c5_d9 - 1;
    if ((c5_i79 < 0) || (c5_i79 > c5_i69)) {
      emlrtDynamicBoundsCheckR2012b(c5_i79, 0, c5_i69, &c5_d_emlrtBCI, &c5_st);
    }

    c5_i83 = c5_i79;
    c5_i85 = c5_boundary.vector.data[c5_i83].f1.size[0];
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ll2, &c5_s_emlrtRTEI,
      c5_i85, 2);
    c5_i88 = c5_boundary.size[0] - 1;
    c5_i89 = c5_perimeter.size[0];
    c5_i90 = 2;
    if ((c5_i90 < 1) || (c5_i90 > c5_i89)) {
      emlrtDynamicBoundsCheckR2012b(c5_i90, 1, c5_i89, &c5_j_emlrtBCI, &c5_st);
    }

    c5_d13 = c5_perimeter.vector.data[c5_i90 - 1];
    if (c5_d13 != (real_T)(int32_T)muDoubleScalarFloor(c5_d13)) {
      emlrtIntegerCheckR2012b(c5_d13, &c5_d_emlrtDCI, &c5_st);
    }

    c5_i93 = (int32_T)c5_d13 - 1;
    if ((c5_i93 < 0) || (c5_i93 > c5_i88)) {
      emlrtDynamicBoundsCheckR2012b(c5_i93, 0, c5_i88, &c5_d_emlrtBCI, &c5_st);
    }

    c5_i95 = c5_i93;
    c5_i96 = c5_boundary.size[0] - 1;
    c5_i97 = c5_perimeter.size[0];
    c5_i98 = 2;
    if ((c5_i98 < 1) || (c5_i98 > c5_i97)) {
      emlrtDynamicBoundsCheckR2012b(c5_i98, 1, c5_i97, &c5_j_emlrtBCI, &c5_st);
    }

    c5_d14 = c5_perimeter.vector.data[c5_i98 - 1];
    if (c5_d14 != (real_T)(int32_T)muDoubleScalarFloor(c5_d14)) {
      emlrtIntegerCheckR2012b(c5_d14, &c5_d_emlrtDCI, &c5_st);
    }

    c5_i99 = (int32_T)c5_d14 - 1;
    if ((c5_i99 < 0) || (c5_i99 > c5_i96)) {
      emlrtDynamicBoundsCheckR2012b(c5_i99, 0, c5_i96, &c5_d_emlrtBCI, &c5_st);
    }

    c5_n_loop_ub = (c5_boundary.vector.data[c5_i95].f1.size[0] << 1) - 1;
    for (c5_i100 = 0; c5_i100 <= c5_n_loop_ub; c5_i100++) {
      c5_i101 = c5_boundary.size[0] - 1;
      c5_i102 = c5_perimeter.size[0];
      c5_i104 = 2;
      if ((c5_i104 < 1) || (c5_i104 > c5_i102)) {
        emlrtDynamicBoundsCheckR2012b(c5_i104, 1, c5_i102, &c5_j_emlrtBCI,
          &c5_st);
      }

      c5_d16 = c5_perimeter.vector.data[c5_i104 - 1];
      if (c5_d16 != (real_T)(int32_T)muDoubleScalarFloor(c5_d16)) {
        emlrtIntegerCheckR2012b(c5_d16, &c5_d_emlrtDCI, &c5_st);
      }

      c5_i106 = (int32_T)c5_d16 - 1;
      if ((c5_i106 < 0) || (c5_i106 > c5_i101)) {
        emlrtDynamicBoundsCheckR2012b(c5_i106, 0, c5_i101, &c5_d_emlrtBCI,
          &c5_st);
      }

      c5_ll2.vector.data[c5_i100] = c5_boundary.vector.data[c5_i106].
        f1.vector.data[c5_i100];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln1, &c5_t_emlrtRTEI,
      0, 0);
    c5_d15 = (real_T)c5_bound.size[0];
    c5_i103 = (int32_T)c5_d15;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d15, mxDOUBLE_CLASS, c5_i103,
      &c5_fg_emlrtRTEI, &c5_st);
    for (c5_d_i = 0; c5_d_i < c5_i103; c5_d_i++) {
      c5_c_i = 1.0 + (real_T)c5_d_i;
      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 1, 1);
      c5_b_st.site = &c5_k_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_varargin_1,
        &c5_u_emlrtRTEI, c5_ln1.size[0], c5_ln1.size[1]);
      c5_p_loop_ub = c5_ln1.size[0] * c5_ln1.size[1] - 1;
      for (c5_i108 = 0; c5_i108 <= c5_p_loop_ub; c5_i108++) {
        c5_varargin_1.vector.data[c5_i108] = c5_ln1.vector.data[c5_i108];
      }

      c5_i110 = c5_bound.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_h_emlrtDCI, &c5_b_st);
      }

      c5_i111 = (int32_T)c5_c_i;
      if ((c5_i111 < 1) || (c5_i111 > c5_i110)) {
        emlrtDynamicBoundsCheckR2012b(c5_i111, 1, c5_i110, &c5_m_emlrtBCI,
          &c5_b_st);
      }

      c5_d_varargin_2 = c5_bound.vector.data[(c5_i111 + c5_bound.size[0]) - 1];
      c5_i115 = c5_bound.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_i_emlrtDCI, &c5_b_st);
      }

      c5_i118 = (int32_T)c5_c_i;
      if ((c5_i118 < 1) || (c5_i118 > c5_i115)) {
        emlrtDynamicBoundsCheckR2012b(c5_i118, 1, c5_i115, &c5_n_emlrtBCI,
          &c5_b_st);
      }

      c5_d_varargin_3 = c5_bound.vector.data[c5_i118 - 1];
      c5_c_st.site = &c5_ri_emlrtRSI;
      c5_f_varargin_2 = c5_d_varargin_2;
      c5_e_varargin_3 = c5_d_varargin_3;
      c5_d_st.site = &c5_si_emlrtRSI;
      if (c5_varargin_1.size[0] == 1) {
        c5_b7 = true;
      } else {
        c5_b6 = (c5_varargin_1.size[0] == 0);
        c5_b8 = (c5_varargin_1.size[1] == 0);
        c5_d_result = (c5_b6 || c5_b8);
        if (c5_d_result) {
          c5_b7 = true;
        } else {
          c5_b7 = false;
        }
      }

      if (!c5_b7) {
        c5_g_y = NULL;
        sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_h_y = NULL;
        sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c5_d_st, &c5_v_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_h_y)));
      }

      c5_b9 = (c5_varargin_1.size[0] == 0);
      c5_b10 = (c5_varargin_1.size[1] == 0);
      c5_e_result = (c5_b9 || c5_b10);
      if (!c5_e_result) {
        c5_f_result = c5_varargin_1.size[1];
      } else {
        c5_f_result = 0;
      }

      c5_input_sizes[1] = c5_f_result;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes.f1,
        &c5_n_emlrtRTEI, 1, c5_input_sizes[1]);
      c5_u_loop_ub = c5_input_sizes[1] - 1;
      for (c5_i122 = 0; c5_i122 <= c5_u_loop_ub; c5_i122++) {
        c5_reshapes.f1.vector.data[c5_i122] = c5_varargin_1.vector.data[c5_i122];
      }

      c5_reshapes.f2 = c5_f_varargin_2;
      c5_reshapes.f3 = c5_e_varargin_3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_varargin_1,
        &c5_n_emlrtRTEI, 1, c5_reshapes.f1.size[1]);
      c5_v_loop_ub = c5_reshapes.f1.size[1] - 1;
      for (c5_i123 = 0; c5_i123 <= c5_v_loop_ub; c5_i123++) {
        c5_b_varargin_1.vector.data[c5_i123] =
          c5_reshapes.f1.vector.data[c5_i123];
      }

      c5_h_varargin_2 = c5_reshapes.f2;
      c5_h_varargin_3 = c5_reshapes.f3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_ln1,
        &c5_v_emlrtRTEI, 1, c5_b_varargin_1.size[1] + 2);
      c5_x_loop_ub = c5_b_varargin_1.size[1] - 1;
      for (c5_i125 = 0; c5_i125 <= c5_x_loop_ub; c5_i125++) {
        c5_b_ln1.vector.data[c5_i125] = c5_b_varargin_1.vector.data[c5_i125];
      }

      c5_b_ln1.vector.data[c5_b_varargin_1.size[1]] = c5_h_varargin_2;
      c5_b_ln1.vector.data[c5_b_varargin_1.size[1] + 1] = c5_h_varargin_3;
      c5_i127 = c5_b_ln1.size[1];
      if (c5_i127 > 10000) {
        emlrtDimSizeGeqCheckR2012b(10000, c5_i127, &c5_emlrtECI, &c5_st);
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln1, &c5_w_emlrtRTEI,
        1, c5_b_ln1.size[1]);
      c5_bb_loop_ub = c5_b_ln1.size[1] - 1;
      for (c5_i129 = 0; c5_i129 <= c5_bb_loop_ub; c5_i129++) {
        c5_ln1.vector.data[c5_i129] = c5_b_ln1.vector.data[c5_i129];
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 1, 0);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln2, &c5_x_emlrtRTEI,
      0, 0);
    c5_d17 = (real_T)c5_ll2.size[0];
    c5_i107 = (int32_T)c5_d17;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d17, mxDOUBLE_CLASS, c5_i107,
      &c5_gg_emlrtRTEI, &c5_st);
    for (c5_e_i = 0; c5_e_i < c5_i107; c5_e_i++) {
      c5_c_i = 1.0 + (real_T)c5_e_i;
      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 2, 1);
      c5_b_st.site = &c5_l_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_varargin_1,
        &c5_y_emlrtRTEI, c5_ln2.size[0], c5_ln2.size[1]);
      c5_s_loop_ub = c5_ln2.size[0] * c5_ln2.size[1] - 1;
      for (c5_i113 = 0; c5_i113 <= c5_s_loop_ub; c5_i113++) {
        c5_varargin_1.vector.data[c5_i113] = c5_ln2.vector.data[c5_i113];
      }

      c5_i114 = c5_ll2.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_j_emlrtDCI, &c5_b_st);
      }

      c5_i117 = (int32_T)c5_c_i;
      if ((c5_i117 < 1) || (c5_i117 > c5_i114)) {
        emlrtDynamicBoundsCheckR2012b(c5_i117, 1, c5_i114, &c5_o_emlrtBCI,
          &c5_b_st);
      }

      c5_e_varargin_2 = c5_ll2.vector.data[(c5_i117 + c5_ll2.size[0]) - 1];
      c5_i120 = c5_ll2.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_k_emlrtDCI, &c5_b_st);
      }

      c5_i121 = (int32_T)c5_c_i;
      if ((c5_i121 < 1) || (c5_i121 > c5_i120)) {
        emlrtDynamicBoundsCheckR2012b(c5_i121, 1, c5_i120, &c5_p_emlrtBCI,
          &c5_b_st);
      }

      c5_f_varargin_3 = c5_ll2.vector.data[c5_i121 - 1];
      c5_c_st.site = &c5_ri_emlrtRSI;
      c5_g_varargin_2 = c5_e_varargin_2;
      c5_g_varargin_3 = c5_f_varargin_3;
      c5_d_st.site = &c5_si_emlrtRSI;
      if (c5_varargin_1.size[0] == 1) {
        c5_b12 = true;
      } else {
        c5_b11 = (c5_varargin_1.size[0] == 0);
        c5_b13 = (c5_varargin_1.size[1] == 0);
        c5_g_result = (c5_b11 || c5_b13);
        if (c5_g_result) {
          c5_b12 = true;
        } else {
          c5_b12 = false;
        }
      }

      if (!c5_b12) {
        c5_i_y = NULL;
        sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_j_y = NULL;
        sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c5_d_st, &c5_v_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_j_y)));
      }

      c5_b14 = (c5_varargin_1.size[0] == 0);
      c5_b15 = (c5_varargin_1.size[1] == 0);
      c5_h_result = (c5_b14 || c5_b15);
      if (!c5_h_result) {
        c5_i_result = c5_varargin_1.size[1];
      } else {
        c5_i_result = 0;
      }

      c5_b_input_sizes[1] = c5_i_result;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes.f1,
        &c5_n_emlrtRTEI, 1, c5_b_input_sizes[1]);
      c5_w_loop_ub = c5_b_input_sizes[1] - 1;
      for (c5_i124 = 0; c5_i124 <= c5_w_loop_ub; c5_i124++) {
        c5_reshapes.f1.vector.data[c5_i124] = c5_varargin_1.vector.data[c5_i124];
      }

      c5_reshapes.f2 = c5_g_varargin_2;
      c5_reshapes.f3 = c5_g_varargin_3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_varargin_1,
        &c5_n_emlrtRTEI, 1, c5_reshapes.f1.size[1]);
      c5_y_loop_ub = c5_reshapes.f1.size[1] - 1;
      for (c5_i126 = 0; c5_i126 <= c5_y_loop_ub; c5_i126++) {
        c5_b_varargin_1.vector.data[c5_i126] =
          c5_reshapes.f1.vector.data[c5_i126];
      }

      c5_i_varargin_2 = c5_reshapes.f2;
      c5_i_varargin_3 = c5_reshapes.f3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_ln1,
        &c5_ab_emlrtRTEI, 1, c5_b_varargin_1.size[1] + 2);
      c5_ab_loop_ub = c5_b_varargin_1.size[1] - 1;
      for (c5_i128 = 0; c5_i128 <= c5_ab_loop_ub; c5_i128++) {
        c5_b_ln1.vector.data[c5_i128] = c5_b_varargin_1.vector.data[c5_i128];
      }

      c5_b_ln1.vector.data[c5_b_varargin_1.size[1]] = c5_i_varargin_2;
      c5_b_ln1.vector.data[c5_b_varargin_1.size[1] + 1] = c5_i_varargin_3;
      c5_i130 = c5_b_ln1.size[1];
      if (c5_i130 > 10000) {
        emlrtDimSizeGeqCheckR2012b(10000, c5_i130, &c5_b_emlrtECI, &c5_st);
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln2,
        &c5_bb_emlrtRTEI, 1, c5_b_ln1.size[1]);
      c5_cb_loop_ub = c5_b_ln1.size[1] - 1;
      for (c5_i131 = 0; c5_i131 <= c5_cb_loop_ub; c5_i131++) {
        c5_ln2.vector.data[c5_i131] = c5_b_ln1.vector.data[c5_i131];
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 2, 0);
  } else if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1,
              covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance, 4U, 0U,
    1U, (real_T)(c5_perimeter.size[0] == 0), 1.0, -1, 1U, c5_perimeter.size[0]
               != 0))) {
    c5_i20 = c5_boundary.size[0] - 1;
    c5_i24 = c5_perimeter.size[0];
    c5_i26 = 1;
    if ((c5_i26 < 1) || (c5_i26 > c5_i24)) {
      emlrtDynamicBoundsCheckR2012b(c5_i26, 1, c5_i24, &c5_i_emlrtBCI, &c5_st);
    }

    c5_d2 = c5_perimeter.vector.data[c5_i26 - 1];
    if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
      emlrtIntegerCheckR2012b(c5_d2, &c5_c_emlrtDCI, &c5_st);
    }

    c5_i31 = (int32_T)c5_d2 - 1;
    if ((c5_i31 < 0) || (c5_i31 > c5_i20)) {
      emlrtDynamicBoundsCheckR2012b(c5_i31, 0, c5_i20, &c5_c_emlrtBCI, &c5_st);
    }

    c5_i34 = c5_i31;
    c5_i36 = c5_boundary.vector.data[c5_i34].f1.size[0];
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_bound, &c5_k_emlrtRTEI,
      c5_i36, 2);
    c5_i40 = c5_boundary.size[0] - 1;
    c5_i42 = c5_perimeter.size[0];
    c5_i45 = 1;
    if ((c5_i45 < 1) || (c5_i45 > c5_i42)) {
      emlrtDynamicBoundsCheckR2012b(c5_i45, 1, c5_i42, &c5_i_emlrtBCI, &c5_st);
    }

    c5_d4 = c5_perimeter.vector.data[c5_i45 - 1];
    if (c5_d4 != (real_T)(int32_T)muDoubleScalarFloor(c5_d4)) {
      emlrtIntegerCheckR2012b(c5_d4, &c5_c_emlrtDCI, &c5_st);
    }

    c5_i49 = (int32_T)c5_d4 - 1;
    if ((c5_i49 < 0) || (c5_i49 > c5_i40)) {
      emlrtDynamicBoundsCheckR2012b(c5_i49, 0, c5_i40, &c5_c_emlrtBCI, &c5_st);
    }

    c5_i52 = c5_i49;
    c5_i55 = c5_boundary.size[0] - 1;
    c5_i57 = c5_perimeter.size[0];
    c5_i60 = 1;
    if ((c5_i60 < 1) || (c5_i60 > c5_i57)) {
      emlrtDynamicBoundsCheckR2012b(c5_i60, 1, c5_i57, &c5_i_emlrtBCI, &c5_st);
    }

    c5_d7 = c5_perimeter.vector.data[c5_i60 - 1];
    if (c5_d7 != (real_T)(int32_T)muDoubleScalarFloor(c5_d7)) {
      emlrtIntegerCheckR2012b(c5_d7, &c5_c_emlrtDCI, &c5_st);
    }

    c5_i64 = (int32_T)c5_d7 - 1;
    if ((c5_i64 < 0) || (c5_i64 > c5_i55)) {
      emlrtDynamicBoundsCheckR2012b(c5_i64, 0, c5_i55, &c5_c_emlrtBCI, &c5_st);
    }

    c5_k_loop_ub = (c5_boundary.vector.data[c5_i52].f1.size[0] << 1) - 1;
    for (c5_i68 = 0; c5_i68 <= c5_k_loop_ub; c5_i68++) {
      c5_i71 = c5_boundary.size[0] - 1;
      c5_i74 = c5_perimeter.size[0];
      c5_i78 = 1;
      if ((c5_i78 < 1) || (c5_i78 > c5_i74)) {
        emlrtDynamicBoundsCheckR2012b(c5_i78, 1, c5_i74, &c5_i_emlrtBCI, &c5_st);
      }

      c5_d11 = c5_perimeter.vector.data[c5_i78 - 1];
      if (c5_d11 != (real_T)(int32_T)muDoubleScalarFloor(c5_d11)) {
        emlrtIntegerCheckR2012b(c5_d11, &c5_c_emlrtDCI, &c5_st);
      }

      c5_i81 = (int32_T)c5_d11 - 1;
      if ((c5_i81 < 0) || (c5_i81 > c5_i71)) {
        emlrtDynamicBoundsCheckR2012b(c5_i81, 0, c5_i71, &c5_c_emlrtBCI, &c5_st);
      }

      c5_bound.vector.data[c5_i68] = c5_boundary.vector.data[c5_i81].
        f1.vector.data[c5_i68];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln1, &c5_l_emlrtRTEI,
      0, 0);
    c5_d8 = (real_T)c5_bound.size[0];
    c5_i77 = (int32_T)c5_d8;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d8, mxDOUBLE_CLASS, c5_i77,
      &c5_hg_emlrtRTEI, &c5_st);
    for (c5_b_i = 0; c5_b_i < c5_i77; c5_b_i++) {
      c5_c_i = 1.0 + (real_T)c5_b_i;
      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 3, 1);
      c5_b_st.site = &c5_m_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_varargin_1,
        &c5_m_emlrtRTEI, c5_ln1.size[0], c5_ln1.size[1]);
      c5_m_loop_ub = c5_ln1.size[0] * c5_ln1.size[1] - 1;
      for (c5_i84 = 0; c5_i84 <= c5_m_loop_ub; c5_i84++) {
        c5_varargin_1.vector.data[c5_i84] = c5_ln1.vector.data[c5_i84];
      }

      c5_i87 = c5_bound.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_f_emlrtDCI, &c5_b_st);
      }

      c5_i91 = (int32_T)c5_c_i;
      if ((c5_i91 < 1) || (c5_i91 > c5_i87)) {
        emlrtDynamicBoundsCheckR2012b(c5_i91, 1, c5_i87, &c5_k_emlrtBCI,
          &c5_b_st);
      }

      c5_varargin_2 = c5_bound.vector.data[(c5_i91 + c5_bound.size[0]) - 1];
      c5_i92 = c5_bound.size[0];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_g_emlrtDCI, &c5_b_st);
      }

      c5_i94 = (int32_T)c5_c_i;
      if ((c5_i94 < 1) || (c5_i94 > c5_i92)) {
        emlrtDynamicBoundsCheckR2012b(c5_i94, 1, c5_i92, &c5_l_emlrtBCI,
          &c5_b_st);
      }

      c5_varargin_3 = c5_bound.vector.data[c5_i94 - 1];
      c5_c_st.site = &c5_ri_emlrtRSI;
      c5_b_varargin_2 = c5_varargin_2;
      c5_b_varargin_3 = c5_varargin_3;
      c5_d_st.site = &c5_si_emlrtRSI;
      if (c5_varargin_1.size[0] == 1) {
        c5_b2 = true;
      } else {
        c5_b1 = (c5_varargin_1.size[0] == 0);
        c5_b3 = (c5_varargin_1.size[1] == 0);
        c5_result = (c5_b1 || c5_b3);
        if (c5_result) {
          c5_b2 = true;
        } else {
          c5_b2 = false;
        }
      }

      if (!c5_b2) {
        c5_e_y = NULL;
        sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_f_y = NULL;
        sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c5_d_st, &c5_v_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_f_y)));
      }

      c5_b4 = (c5_varargin_1.size[0] == 0);
      c5_b5 = (c5_varargin_1.size[1] == 0);
      c5_b_result = (c5_b4 || c5_b5);
      if (!c5_b_result) {
        c5_c_result = c5_varargin_1.size[1];
      } else {
        c5_c_result = 0;
      }

      c5_input_sizes[1] = c5_c_result;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes.f1,
        &c5_n_emlrtRTEI, 1, c5_input_sizes[1]);
      c5_o_loop_ub = c5_input_sizes[1] - 1;
      for (c5_i105 = 0; c5_i105 <= c5_o_loop_ub; c5_i105++) {
        c5_reshapes.f1.vector.data[c5_i105] = c5_varargin_1.vector.data[c5_i105];
      }

      c5_reshapes.f2 = c5_b_varargin_2;
      c5_reshapes.f3 = c5_b_varargin_3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_varargin_1,
        &c5_n_emlrtRTEI, 1, c5_reshapes.f1.size[1]);
      c5_q_loop_ub = c5_reshapes.f1.size[1] - 1;
      for (c5_i109 = 0; c5_i109 <= c5_q_loop_ub; c5_i109++) {
        c5_b_varargin_1.vector.data[c5_i109] =
          c5_reshapes.f1.vector.data[c5_i109];
      }

      c5_c_varargin_2 = c5_reshapes.f2;
      c5_c_varargin_3 = c5_reshapes.f3;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_ln1,
        &c5_o_emlrtRTEI, 1, c5_b_varargin_1.size[1] + 2);
      c5_r_loop_ub = c5_b_varargin_1.size[1] - 1;
      for (c5_i112 = 0; c5_i112 <= c5_r_loop_ub; c5_i112++) {
        c5_b_ln1.vector.data[c5_i112] = c5_b_varargin_1.vector.data[c5_i112];
      }

      c5_b_ln1.vector.data[c5_b_varargin_1.size[1]] = c5_c_varargin_2;
      c5_b_ln1.vector.data[c5_b_varargin_1.size[1] + 1] = c5_c_varargin_3;
      c5_i116 = c5_b_ln1.size[1];
      if (c5_i116 > 10000) {
        emlrtDimSizeGeqCheckR2012b(10000, c5_i116, &c5_c_emlrtECI, &c5_st);
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln1, &c5_p_emlrtRTEI,
        1, c5_b_ln1.size[1]);
      c5_t_loop_ub = c5_b_ln1.size[1] - 1;
      for (c5_i119 = 0; c5_i119 <= c5_t_loop_ub; c5_i119++) {
        c5_ln1.vector.data[c5_i119] = c5_b_ln1.vector.data[c5_i119];
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 3, 0);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln2, &c5_q_emlrtRTEI,
      c5_ln1.size[0], c5_ln1.size[1]);
    c5_l_loop_ub = c5_ln1.size[0] * c5_ln1.size[1] - 1;
    for (c5_i82 = 0; c5_i82 <= c5_l_loop_ub; c5_i82++) {
      c5_ln2.vector.data[c5_i82] = c5_ln1.vector.data[c5_i82];
    }
  } else {
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln1, &c5_i_emlrtRTEI,
      1, 6);
    for (c5_i23 = 0; c5_i23 < 6; c5_i23++) {
      c5_ln1.vector.data[c5_i23] = c5_dv[c5_i23];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_ln2, &c5_j_emlrtRTEI,
      1, 6);
    for (c5_i28 = 0; c5_i28 < 6; c5_i28++) {
      c5_ln2.vector.data[c5_i28] = c5_dv[c5_i28];
    }
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_varargin_1);
  c5_array_cell_41_Destructor(chartInstance, &c5_reshapes);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_varargin_1);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_ln1);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_ll2);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_bound);
  c5_array_real_T_Destructor(chartInstance, &c5_perimeter);
  c5_array_cell_wrap_0_Destructor1(chartInstance, &c5_boundary);
  for (c5_i44 = 0; c5_i44 < 19200; c5_i44++) {
    (*chartInstance->c5_bw)[c5_i44] = c5_b_bw[c5_i44];
  }

  *chartInstance->c5_N = c5_c_N;
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 0, c5_ln1.size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 1, c5_ln1.size[1]);
  c5_e_loop_ub = c5_ln1.size[0] * c5_ln1.size[1] - 1;
  for (c5_i48 = 0; c5_i48 <= c5_e_loop_ub; c5_i48++) {
    (*chartInstance->c5_ln1_data)[c5_i48] = c5_ln1.vector.data[c5_i48];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_ln1);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 4, 0, c5_ln2.size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 4, 1, c5_ln2.size[1]);
  c5_g_loop_ub = c5_ln2.size[0] * c5_ln2.size[1] - 1;
  for (c5_i59 = 0; c5_i59 <= c5_g_loop_ub; c5_i59++) {
    (*chartInstance->c5_ln2_data)[c5_i59] = c5_ln2.vector.data[c5_i59];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_ln2);
  for (c5_i61 = 0; c5_i61 < 19200; c5_i61++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U, (real_T)
                      (*chartInstance->c5_bw)[c5_i61]);
  }

  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 2U, *chartInstance->c5_N);
  c5_h_loop_ub = (*chartInstance->c5_ln1_sizes)[0] *
    (*chartInstance->c5_ln1_sizes)[1] - 1;
  for (c5_i65 = 0; c5_i65 <= c5_h_loop_ub; c5_i65++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 3U,
                      (*chartInstance->c5_ln1_data)[c5_i65]);
  }

  c5_j_loop_ub = (*chartInstance->c5_ln2_sizes)[0] *
    (*chartInstance->c5_ln2_sizes)[1] - 1;
  for (c5_i67 = 0; c5_i67 <= c5_j_loop_ub; c5_i67++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 4U,
                      (*chartInstance->c5_ln2_data)[c5_i67]);
  }
}

static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(4, 1), false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", chartInstance->c5_N, 0, 0U, 0, 0U, 0),
                false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", *chartInstance->c5_bw, 11, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", chartInstance->c5_ln1_data, 0, 0U, 1,
    0U, 2, (*chartInstance->c5_ln1_sizes)[0], (*chartInstance->c5_ln1_sizes)[1]),
                false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", chartInstance->c5_ln2_data, 0, 0U, 1,
    0U, 2, (*chartInstance->c5_ln2_sizes)[0], (*chartInstance->c5_ln2_sizes)[1]),
                false);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st)
{
  c5_coder_array_real_T_2D c5_r;
  c5_coder_array_real_T_2D c5_r1;
  emlrtStack c5_b_st = { NULL,         /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c5_u;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  boolean_T c5_bv[19200];
  c5_b_st.tls = chartInstance->c5_fEmlrtCtx;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *chartInstance->c5_N = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "N");
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)), "bw",
                        c5_bv);
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    (*chartInstance->c5_bw)[c5_i] = c5_bv[c5_i];
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_r);
  c5_e_emlrt_marshallIn(chartInstance, &c5_b_st, sf_mex_dup(sf_mex_getcell(c5_u,
    2)), "ln1", &c5_r);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 0, c5_r.size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 1, c5_r.size[1]);
  c5_loop_ub = c5_r.size[0] * c5_r.size[1] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    (*chartInstance->c5_ln1_data)[c5_i1] = c5_r.vector.data[c5_i1];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_r);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_r1);
  c5_e_emlrt_marshallIn(chartInstance, &c5_b_st, sf_mex_dup(sf_mex_getcell(c5_u,
    3)), "ln2", &c5_r1);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 4, 0, c5_r1.size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 4, 1, c5_r1.size[1]);
  c5_b_loop_ub = c5_r1.size[0] * c5_r1.size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    (*chartInstance->c5_ln2_data)[c5_i2] = c5_r1.vector.data[c5_i2];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_r1);
  sf_mex_destroy(&c5_u);
  sf_mex_destroy(&c5_st);
}

static void c5_imbinarize(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_I[19200], boolean_T c5_BW[19200])
{
  static char_T c5_b_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv2[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  real_T c5_localBins1[256];
  real_T c5_localBins2[256];
  real_T c5_localBins3[256];
  real_T c5_y[256];
  real_T c5_T;
  real_T c5_b_idx;
  real_T c5_b_k;
  real_T c5_b_p;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d_i;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_k_a;
  real_T c5_k_c;
  real_T c5_l_a;
  real_T c5_m_a;
  real_T c5_maxval;
  real_T c5_mu_t;
  real_T c5_n_a;
  real_T c5_num_elems;
  real_T c5_num_maxval;
  real_T c5_o_a;
  real_T c5_out;
  real_T c5_sigma_b_squared;
  real_T c5_t;
  real_T c5_x;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_c;
  int32_T c5_c_i;
  int32_T c5_c_k;
  int32_T c5_d_a;
  int32_T c5_d_c;
  int32_T c5_e_a;
  int32_T c5_e_c;
  int32_T c5_e_k;
  int32_T c5_f_a;
  int32_T c5_f_c;
  int32_T c5_f_k;
  int32_T c5_g_a;
  int32_T c5_g_c;
  int32_T c5_h_a;
  int32_T c5_h_c;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i_a;
  int32_T c5_i_c;
  int32_T c5_idx;
  int32_T c5_idx1;
  int32_T c5_idx2;
  int32_T c5_idx3;
  int32_T c5_idx4;
  int32_T c5_j_a;
  int32_T c5_j_c;
  int32_T c5_k;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_isfinite_maxval;
  boolean_T c5_p;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_o_emlrtRSI;
  c5_b_st.site = &c5_p_emlrtRSI;
  c5_c_st.site = &c5_q_emlrtRSI;
  c5_d_st.site = &c5_s_emlrtRSI;
  c5_out = 1.0;
  getnumcores(&c5_out);
  c5_d_st.site = &c5_r_emlrtRSI;
  for (c5_i = 0; c5_i < 256; c5_i++) {
    c5_y[c5_i] = 0.0;
  }

  for (c5_i1 = 0; c5_i1 < 256; c5_i1++) {
    c5_localBins1[c5_i1] = 0.0;
  }

  for (c5_i2 = 0; c5_i2 < 256; c5_i2++) {
    c5_localBins2[c5_i2] = 0.0;
  }

  for (c5_i3 = 0; c5_i3 < 256; c5_i3++) {
    c5_localBins3[c5_i3] = 0.0;
  }

  for (c5_b_i = 4; c5_b_i <= 19200; c5_b_i += 4) {
    c5_i4 = c5_b_i - 3;
    if ((c5_i4 < 1) || (c5_i4 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 19200, &c5_q_emlrtBCI, &c5_d_st);
    }

    c5_idx1 = c5_I[c5_i4 - 1];
    c5_i5 = c5_b_i - 2;
    if ((c5_i5 < 1) || (c5_i5 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i5, 1, 19200, &c5_r_emlrtBCI, &c5_d_st);
    }

    c5_idx2 = c5_I[c5_i5 - 1];
    c5_i6 = c5_b_i - 1;
    if ((c5_i6 < 1) || (c5_i6 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i6, 1, 19200, &c5_s_emlrtBCI, &c5_d_st);
    }

    c5_idx3 = c5_I[c5_i6 - 1];
    if ((c5_b_i < 1) || (c5_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_i, 1, 19200, &c5_t_emlrtBCI, &c5_d_st);
    }

    c5_idx4 = c5_I[c5_b_i - 1];
    c5_c_a = c5_idx1 + 1;
    c5_c_c = c5_c_a - 1;
    c5_d_a = c5_idx1 + 1;
    c5_d_c = c5_d_a - 1;
    c5_localBins1[c5_c_c] = c5_localBins1[c5_d_c] + 1.0;
    c5_e_a = c5_idx2 + 1;
    c5_e_c = c5_e_a - 1;
    c5_f_a = c5_idx2 + 1;
    c5_f_c = c5_f_a - 1;
    c5_localBins2[c5_e_c] = c5_localBins2[c5_f_c] + 1.0;
    c5_g_a = c5_idx3 + 1;
    c5_g_c = c5_g_a - 1;
    c5_h_a = c5_idx3 + 1;
    c5_h_c = c5_h_a - 1;
    c5_localBins3[c5_g_c] = c5_localBins3[c5_h_c] + 1.0;
    c5_i_a = c5_idx4 + 1;
    c5_i_c = c5_i_a - 1;
    c5_j_a = c5_idx4 + 1;
    c5_j_c = c5_j_a - 1;
    c5_y[c5_i_c] = c5_y[c5_j_c] + 1.0;
  }

  while (c5_b_i - 3 <= 19200) {
    c5_idx = c5_I[c5_b_i - 4];
    c5_a = c5_idx + 1;
    c5_c = c5_a - 1;
    c5_b_a = c5_idx + 1;
    c5_b_c = c5_b_a - 1;
    c5_y[c5_c] = c5_y[c5_b_c] + 1.0;
    c5_b_i++;
  }

  for (c5_c_i = 0; c5_c_i < 256; c5_c_i++) {
    c5_d_i = (real_T)c5_c_i + 1.0;
    c5_y[(int32_T)c5_d_i - 1] = ((c5_y[(int32_T)c5_d_i - 1] + c5_localBins1
      [(int32_T)c5_d_i - 1]) + c5_localBins2[(int32_T)c5_d_i - 1]) +
      c5_localBins3[(int32_T)c5_d_i - 1];
  }

  c5_b_st.site = &c5_p_emlrtRSI;
  c5_c_st.site = &c5_u_emlrtRSI;
  c5_d_st.site = &c5_w_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 256)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_x = c5_y[(int32_T)c5_b_k - 1];
    c5_b_x = c5_x;
    c5_d_b = muDoubleScalarIsInf(c5_b_x);
    c5_b1 = !c5_d_b;
    c5_e_b = c5_b1;
    if (c5_e_b) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c5_d_st, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
  }

  c5_d_st.site = &c5_w_emlrtRSI;
  c5_num_elems = 0.0;
  for (c5_c_k = 0; c5_c_k < 256; c5_c_k++) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_num_elems += c5_y[(int32_T)c5_d_k - 1];
  }

  c5_localBins1[0] = c5_y[0] / c5_num_elems;
  c5_localBins2[0] = c5_localBins1[0];
  for (c5_e_k = 0; c5_e_k < 255; c5_e_k++) {
    c5_d_k = (real_T)c5_e_k + 2.0;
    c5_b_p = c5_y[(int32_T)c5_d_k - 1] / c5_num_elems;
    c5_localBins1[(int32_T)c5_d_k - 1] = c5_localBins1[(int32_T)(c5_d_k - 1.0) -
      1] + c5_b_p;
    c5_localBins2[(int32_T)c5_d_k - 1] = c5_localBins2[(int32_T)(c5_d_k - 1.0) -
      1] + c5_b_p * c5_d_k;
  }

  c5_mu_t = c5_localBins2[255];
  c5_maxval = rtMinusInf;
  c5_b_idx = 0.0;
  c5_num_maxval = 0.0;
  for (c5_f_k = 0; c5_f_k < 255; c5_f_k++) {
    c5_d_k = (real_T)c5_f_k + 1.0;
    c5_c_st.site = &c5_v_emlrtRSI;
    c5_k_a = c5_mu_t * c5_localBins1[(int32_T)c5_d_k - 1] - c5_localBins2
      [(int32_T)c5_d_k - 1];
    c5_d_st.site = &c5_x_emlrtRSI;
    c5_l_a = c5_k_a;
    c5_m_a = c5_l_a;
    c5_n_a = c5_m_a;
    c5_o_a = c5_n_a;
    c5_k_c = c5_o_a * c5_o_a;
    c5_sigma_b_squared = c5_k_c / (c5_localBins1[(int32_T)c5_d_k - 1] * (1.0 -
      c5_localBins1[(int32_T)c5_d_k - 1]));
    if (c5_sigma_b_squared > c5_maxval) {
      c5_maxval = c5_sigma_b_squared;
      c5_b_idx = c5_d_k;
      c5_num_maxval = 1.0;
    } else if (c5_sigma_b_squared == c5_maxval) {
      c5_b_idx += c5_d_k;
      c5_num_maxval++;
    }
  }

  c5_c_x = c5_maxval;
  c5_d_x = c5_c_x;
  c5_f_b = muDoubleScalarIsInf(c5_d_x);
  c5_b2 = !c5_f_b;
  c5_isfinite_maxval = c5_b2;
  if (c5_isfinite_maxval) {
    c5_b_idx /= c5_num_maxval;
    c5_t = (c5_b_idx - 1.0) / 255.0;
  } else {
    c5_t = 0.0;
  }

  c5_T = c5_t;
  c5_d = 255.0 * c5_T;
  for (c5_i7 = 0; c5_i7 < 19200; c5_i7++) {
    c5_BW[c5_i7] = ((real_T)c5_I[c5_i7] > c5_d);
  }
}

static void c5_bwlabel(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T c5_c_L[19200],
  real_T *c5_numComponents)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  int64_T c5_i7;
  real_T c5_a;
  real_T c5_b_c;
  real_T c5_b_i;
  real_T c5_b_j;
  real_T c5_b_numComponents;
  real_T c5_b_r;
  real_T c5_b_root;
  real_T c5_b_rootj;
  real_T c5_b_thread;
  real_T c5_b_varargin_1;
  real_T c5_b_x;
  real_T c5_c_i;
  real_T c5_c_j;
  real_T c5_c_root;
  real_T c5_c_rootj;
  real_T c5_c_varargin_1;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d10;
  real_T c5_d11;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d8;
  real_T c5_d9;
  real_T c5_d_a;
  real_T c5_d_i;
  real_T c5_d_j;
  real_T c5_d_root;
  real_T c5_d_rootj;
  real_T c5_d_x;
  real_T c5_e_i;
  real_T c5_e_j;
  real_T c5_e_root;
  real_T c5_e_x;
  real_T c5_f_i;
  real_T c5_f_j;
  real_T c5_f_root;
  real_T c5_firstLabel;
  real_T c5_g_i;
  real_T c5_g_j;
  real_T c5_h_i;
  real_T c5_h_j;
  real_T c5_i_i;
  real_T c5_i_j;
  real_T c5_j;
  real_T c5_j_i;
  real_T c5_j_j;
  real_T c5_k_i;
  real_T c5_k_x;
  real_T c5_l_i;
  real_T c5_l_x;
  real_T c5_label;
  real_T c5_m_i;
  real_T c5_minval;
  real_T c5_n_i;
  real_T c5_n_x;
  real_T c5_o_i;
  real_T c5_o_x;
  real_T c5_p_i;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_root;
  real_T c5_rootj;
  real_T c5_startC;
  real_T c5_x;
  real_T c5_y;
  real_T c5_z;
  int32_T c5_chunksSizeAndLabels[168];
  int32_T c5_b_a;
  int32_T c5_b_q0;
  int32_T c5_b_q1;
  int32_T c5_b_qY;
  int32_T c5_b_y;
  int32_T c5_b_z;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_c;
  int32_T c5_c_q0;
  int32_T c5_c_q1;
  int32_T c5_c_qY;
  int32_T c5_c_r;
  int32_T c5_d_b;
  int32_T c5_d_c;
  int32_T c5_d_q0;
  int32_T c5_d_q1;
  int32_T c5_d_qY;
  int32_T c5_d_r;
  int32_T c5_e_a;
  int32_T c5_e_q0;
  int32_T c5_e_q1;
  int32_T c5_e_qY;
  int32_T c5_exitg1;
  int32_T c5_f_a;
  int32_T c5_f_q0;
  int32_T c5_f_q1;
  int32_T c5_f_qY;
  int32_T c5_f_x;
  int32_T c5_g_q0;
  int32_T c5_g_q1;
  int32_T c5_g_qY;
  int32_T c5_g_x;
  int32_T c5_h_q0;
  int32_T c5_h_q1;
  int32_T c5_h_qY;
  int32_T c5_h_x;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_q0;
  int32_T c5_i_q1;
  int32_T c5_i_qY;
  int32_T c5_i_x;
  int32_T c5_j_q0;
  int32_T c5_j_q1;
  int32_T c5_j_qY;
  int32_T c5_j_x;
  int32_T c5_k_q0;
  int32_T c5_k_q1;
  int32_T c5_k_qY;
  int32_T c5_l_q0;
  int32_T c5_l_q1;
  int32_T c5_l_qY;
  int32_T c5_m_x;
  int32_T c5_q0;
  int32_T c5_q1;
  int32_T c5_qY;
  int32_T c5_q_i;
  int32_T c5_r;
  int32_T c5_stripeFirstLabel;
  int32_T c5_thread;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_gb_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  chartInstance->c5_P[0] = 0.0;
  for (c5_thread = 0; c5_thread < 8; c5_thread++) {
    c5_b_thread = (real_T)c5_thread;
    c5_b_c = c5_b_thread * 20.0 + 1.0;
    c5_b_varargin_1 = (c5_b_thread + 1.0) * 20.0 + 1.0;
    c5_x = c5_b_varargin_1;
    c5_b_x = c5_x;
    c5_c_x = c5_b_x;
    c5_a = c5_c_x;
    c5_d_x = c5_a;
    c5_e_x = c5_d_x;
    c5_minval = muDoubleScalarMin(c5_e_x, 161.0);
    c5_d1 = muDoubleScalarRound(c5_minval);
    if (c5_d1 < 2.147483648E+9) {
      if (c5_d1 >= -2.147483648E+9) {
        c5_i = (int32_T)c5_d1;
      } else {
        c5_i = MIN_int32_T;
      }
    } else if (c5_d1 >= 2.147483648E+9) {
      c5_i = MAX_int32_T;
    } else {
      c5_i = 0;
    }

    c5_chunksSizeAndLabels[(int32_T)c5_b_c - 1] = c5_i;
    c5_k_x = c5_b_c / 2.0;
    c5_l_x = c5_k_x;
    c5_y = c5_l_x;
    c5_y = muDoubleScalarFloor(c5_y);
    c5_label = c5_y * 60.0 + 1.0;
    c5_firstLabel = c5_label;
    c5_startC = c5_b_c;
    c5_d6 = c5_b_thread * 20.0 + 1.0;
    c5_c_varargin_1 = (c5_b_thread + 1.0) * 20.0;
    c5_n_x = c5_c_varargin_1;
    c5_o_x = c5_n_x;
    c5_p_x = c5_o_x;
    c5_d_a = c5_p_x;
    c5_q_x = c5_d_a;
    c5_r_x = c5_q_x;
    c5_d7 = muDoubleScalarMin(c5_r_x, 160.0);
    c5_i10 = (int32_T)(c5_d7 + (1.0 - c5_d6)) - 1;
    for (c5_d_c = 0; c5_d_c <= c5_i10; c5_d_c++) {
      c5_b_c = c5_d6 + (real_T)c5_d_c;
      for (c5_d_r = 0; c5_d_r < 120; c5_d_r++) {
        c5_b_r = (real_T)c5_d_r + 1.0;
        c5_i15 = (int32_T)c5_b_c;
        if ((c5_i15 < 1) || (c5_i15 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i15, 1, 160, &c5_ob_emlrtBCI, &c5_st);
        }

        if (c5_varargin_1[((int32_T)c5_b_r + 120 * (c5_i15 - 1)) - 1]) {
          if ((c5_b_c > c5_startC) && c5_varargin_1[((int32_T)c5_b_r + 120 *
               ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1];
          } else if ((c5_b_r < 120.0) && (c5_b_c > c5_startC) && c5_varargin_1
                     [((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)(c5_b_c - 1.0)
                       - 1)) - 1]) {
            if ((c5_b_c > c5_startC) && (c5_b_r > 1.0) && c5_varargin_1
                [((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c - 1.0) - 1))
                - 1]) {
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c - 1.0)
                         - 1)) - 1];
              do {
                c5_exitg1 = 0;
                c5_i23 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                  c5_b_c - 1)) - 1] + 1.0);
                if ((c5_i23 < 1) || (c5_i23 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 9601, &c5_qb_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_P[c5_i23 - 1] < c5_c_L[((int32_T)c5_b_r +
                     120 * ((int32_T)c5_b_c - 1)) - 1]) {
                  c5_i31 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                    c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i31 < 1) || (c5_i31 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i31, 1, 9601,
                      &c5_rb_emlrtBCI, &c5_st);
                  }

                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    chartInstance->c5_P[c5_i31 - 1];
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              if (c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c -
                     1.0) - 1)) - 1] != c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                   ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
                c5_d_rootj = c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)
                  (c5_b_c - 1.0) - 1)) - 1];
                do {
                  c5_exitg1 = 0;
                  c5_i45 = (int32_T)(c5_d_rootj + 1.0);
                  if ((c5_i45 < 1) || (c5_i45 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i45, 1, 9601,
                      &c5_vb_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_P[c5_i45 - 1] < c5_d_rootj) {
                    c5_i51 = (int32_T)(c5_d_rootj + 1.0);
                    if ((c5_i51 < 1) || (c5_i51 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i51, 1, 9601,
                        &c5_yb_emlrtBCI, &c5_st);
                    }

                    c5_d_rootj = chartInstance->c5_P[c5_i51 - 1];
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                if (c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] >
                    c5_d_rootj) {
                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    c5_d_rootj;
                }

                do {
                  c5_exitg1 = 0;
                  c5_i65 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                    ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i65 < 1) || (c5_i65 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i65, 1, 9601,
                      &c5_hc_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_P[c5_i65 - 1] < c5_c_L[((int32_T)(c5_b_r
                        + 1.0) + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
                    c5_i71 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                      ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c5_i71 < 1) || (c5_i71 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i71, 1, 9601,
                        &c5_jc_emlrtBCI, &c5_st);
                    }

                    c5_g_j = chartInstance->c5_P[c5_i71 - 1];
                    c5_i76 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                      ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c5_i76 < 1) || (c5_i76 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i76, 1, 9601,
                        &c5_lc_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_P[c5_i76 - 1] = c5_c_L[((int32_T)c5_b_r +
                      120 * ((int32_T)c5_b_c - 1)) - 1];
                    c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)(c5_b_c -
                              1.0) - 1)) - 1] = c5_g_j;
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                c5_i74 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                  ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c5_i74 < 1) || (c5_i74 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i74, 1, 9601, &c5_ic_emlrtBCI,
                    &c5_st);
                }

                chartInstance->c5_P[c5_i74 - 1] = c5_c_L[((int32_T)c5_b_r + 120 *
                  ((int32_T)c5_b_c - 1)) - 1];
              }

              do {
                c5_exitg1 = 0;
                c5_i44 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                  ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c5_i44 < 1) || (c5_i44 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i44, 1, 9601, &c5_ub_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_P[c5_i44 - 1] < c5_c_L[((int32_T)(c5_b_r -
                      1.0) + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
                  c5_i50 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                    ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i50 < 1) || (c5_i50 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i50, 1, 9601,
                      &c5_xb_emlrtBCI, &c5_st);
                  }

                  c5_g_j = chartInstance->c5_P[c5_i50 - 1];
                  c5_i59 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                    ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i59 < 1) || (c5_i59 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i59, 1, 9601,
                      &c5_cc_emlrtBCI, &c5_st);
                  }

                  chartInstance->c5_P[c5_i59 - 1] = c5_c_L[((int32_T)c5_b_r +
                    120 * ((int32_T)c5_b_c - 1)) - 1];
                  c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c -
                            1.0) - 1)) - 1] = c5_g_j;
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              c5_i57 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
              if ((c5_i57 < 1) || (c5_i57 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i57, 1, 9601, &c5_wb_emlrtBCI,
                  &c5_st);
              }

              chartInstance->c5_P[c5_i57 - 1] = c5_c_L[((int32_T)c5_b_r + 120 *
                ((int32_T)c5_b_c - 1)) - 1];
            } else if ((c5_b_r > 1.0) && c5_varargin_1[((int32_T)(c5_b_r - 1.0)
                        + 120 * ((int32_T)c5_b_c - 1)) - 1]) {
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1)) -
                1];
              do {
                c5_exitg1 = 0;
                c5_i25 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                  c5_b_c - 1)) - 1] + 1.0);
                if ((c5_i25 < 1) || (c5_i25 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i25, 1, 9601, &c5_sb_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_P[c5_i25 - 1] < c5_c_L[((int32_T)c5_b_r +
                     120 * ((int32_T)c5_b_c - 1)) - 1]) {
                  c5_i33 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                    c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i33 < 1) || (c5_i33 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i33, 1, 9601,
                      &c5_tb_emlrtBCI, &c5_st);
                  }

                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    chartInstance->c5_P[c5_i33 - 1];
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              if (c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1))
                  - 1] != c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)
                    (c5_b_c - 1.0) - 1)) - 1]) {
                c5_d_rootj = c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)
                  (c5_b_c - 1.0) - 1)) - 1];
                do {
                  c5_exitg1 = 0;
                  c5_i48 = (int32_T)(c5_d_rootj + 1.0);
                  if ((c5_i48 < 1) || (c5_i48 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i48, 1, 9601,
                      &c5_bc_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_P[c5_i48 - 1] < c5_d_rootj) {
                    c5_i54 = (int32_T)(c5_d_rootj + 1.0);
                    if ((c5_i54 < 1) || (c5_i54 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i54, 1, 9601,
                        &c5_fc_emlrtBCI, &c5_st);
                    }

                    c5_d_rootj = chartInstance->c5_P[c5_i54 - 1];
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                if (c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] >
                    c5_d_rootj) {
                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    c5_d_rootj;
                }

                do {
                  c5_exitg1 = 0;
                  c5_i67 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                    ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i67 < 1) || (c5_i67 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i67, 1, 9601,
                      &c5_kc_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_P[c5_i67 - 1] < c5_c_L[((int32_T)(c5_b_r
                        + 1.0) + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
                    c5_i72 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                      ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c5_i72 < 1) || (c5_i72 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i72, 1, 9601,
                        &c5_nc_emlrtBCI, &c5_st);
                    }

                    c5_g_j = chartInstance->c5_P[c5_i72 - 1];
                    c5_i77 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                      ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c5_i77 < 1) || (c5_i77 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i77, 1, 9601,
                        &c5_oc_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_P[c5_i77 - 1] = c5_c_L[((int32_T)c5_b_r +
                      120 * ((int32_T)c5_b_c - 1)) - 1];
                    c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)(c5_b_c -
                              1.0) - 1)) - 1] = c5_g_j;
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                c5_i75 = (int32_T)(c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 *
                  ((int32_T)(c5_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c5_i75 < 1) || (c5_i75 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i75, 1, 9601, &c5_mc_emlrtBCI,
                    &c5_st);
                }

                chartInstance->c5_P[c5_i75 - 1] = c5_c_L[((int32_T)c5_b_r + 120 *
                  ((int32_T)c5_b_c - 1)) - 1];
              }

              do {
                c5_exitg1 = 0;
                c5_i47 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                  ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                if ((c5_i47 < 1) || (c5_i47 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i47, 1, 9601, &c5_ac_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_P[c5_i47 - 1] < c5_c_L[((int32_T)(c5_b_r -
                      1.0) + 120 * ((int32_T)c5_b_c - 1)) - 1]) {
                  c5_i53 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                    ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i53 < 1) || (c5_i53 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i53, 1, 9601,
                      &c5_ec_emlrtBCI, &c5_st);
                  }

                  c5_g_j = chartInstance->c5_P[c5_i53 - 1];
                  c5_i61 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                    ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i61 < 1) || (c5_i61 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i61, 1, 9601,
                      &c5_gc_emlrtBCI, &c5_st);
                  }

                  chartInstance->c5_P[c5_i61 - 1] = c5_c_L[((int32_T)c5_b_r +
                    120 * ((int32_T)c5_b_c - 1)) - 1];
                  c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1))
                    - 1] = c5_g_j;
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              c5_i58 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                ((int32_T)c5_b_c - 1)) - 1] + 1.0);
              if ((c5_i58 < 1) || (c5_i58 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i58, 1, 9601, &c5_dc_emlrtBCI,
                  &c5_st);
              }

              chartInstance->c5_P[c5_i58 - 1] = c5_c_L[((int32_T)c5_b_r + 120 *
                ((int32_T)c5_b_c - 1)) - 1];
            } else {
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * ((int32_T)(c5_b_c - 1.0)
                         - 1)) - 1];
            }
          } else if ((c5_b_c > c5_startC) && (c5_b_r > 1.0) && c5_varargin_1
                     [((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c - 1.0)
                       - 1)) - 1]) {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)(c5_b_c - 1.0) -
                       1)) - 1];
          } else if ((c5_b_r > 1.0) && c5_varargin_1[((int32_T)(c5_b_r - 1.0) +
                      120 * ((int32_T)c5_b_c - 1)) - 1]) {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1)) - 1];
          } else {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_label;
            c5_i20 = (int32_T)(c5_label + 1.0);
            if ((c5_i20 < 1) || (c5_i20 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i20, 1, 9601, &c5_u_emlrtBCI,
                &c5_st);
            }

            chartInstance->c5_P[c5_i20 - 1] = c5_label;
            c5_label++;
          }
        } else {
          c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] = 0.0;
        }
      }
    }

    c5_d10 = muDoubleScalarRound(c5_label - c5_firstLabel);
    if (c5_d10 < 2.147483648E+9) {
      if (c5_d10 >= -2.147483648E+9) {
        c5_i13 = (int32_T)c5_d10;
      } else {
        c5_i13 = MIN_int32_T;
      }
    } else if (c5_d10 >= 2.147483648E+9) {
      c5_i13 = MAX_int32_T;
    } else {
      c5_i13 = 0;
    }

    c5_chunksSizeAndLabels[(int32_T)(c5_startC + 1.0) - 1] = c5_i13;
  }

  c5_c = c5_chunksSizeAndLabels[0];
  while ((real_T)c5_c <= 160.0) {
    for (c5_r = 0; c5_r < 120; c5_r++) {
      c5_b_r = (real_T)c5_r + 1.0;
      if ((c5_c < 1) || (c5_c > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_c, 1, 160, &c5_y_emlrtBCI, &c5_st);
      }

      c5_d = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
      if (c5_d != 0.0) {
        if (c5_b_r > 1.0) {
          c5_b_q0 = c5_c;
          c5_b_q1 = 1;
          if ((c5_b_q1 < 0) && (c5_b_q0 > c5_b_q1 + MAX_int32_T)) {
            c5_b_qY = MAX_int32_T;
          } else if ((c5_b_q1 > 0) && (c5_b_q0 < c5_b_q1 + MIN_int32_T)) {
            c5_b_qY = MIN_int32_T;
          } else {
            c5_b_qY = c5_b_q0 - c5_b_q1;
          }

          c5_i2 = c5_b_qY;
          if ((c5_i2 < 1) || (c5_i2 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c5_i2, 1, 160, &c5_ab_emlrtBCI, &c5_st);
          }

          c5_d3 = c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * (c5_i2 - 1)) - 1];
          if (c5_d3 != 0.0) {
            c5_b_st.site = &c5_hb_emlrtRSI;
            c5_e_q0 = c5_c;
            c5_e_q1 = 1;
            if ((c5_e_q1 < 0) && (c5_e_q0 > c5_e_q1 + MAX_int32_T)) {
              c5_e_qY = MAX_int32_T;
            } else if ((c5_e_q1 > 0) && (c5_e_q0 < c5_e_q1 + MIN_int32_T)) {
              c5_e_qY = MIN_int32_T;
            } else {
              c5_e_qY = c5_e_q0 - c5_e_q1;
            }

            c5_i6 = c5_e_qY;
            if ((c5_i6 < 1) || (c5_i6 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c5_i6, 1, 160, &c5_cb_emlrtBCI,
                &c5_b_st);
            }

            c5_b_i = c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * (c5_i6 - 1)) - 1];
            c5_j = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
            c5_c_st.site = &c5_ab_emlrtRSI;
            c5_e_i = c5_b_i;
            c5_d8 = c5_e_i;
            do {
              c5_exitg1 = 0;
              c5_i11 = (int32_T)(c5_d8 + 1.0);
              if ((c5_i11 < 1) || (c5_i11 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i11, 1, 9601, &c5_hb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i11 - 1] < c5_d8) {
                c5_i16 = (int32_T)(c5_d8 + 1.0);
                if ((c5_i16 < 1) || (c5_i16 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i16, 1, 9601, &c5_ib_emlrtBCI,
                    &c5_c_st);
                }

                c5_d8 = chartInstance->c5_P[c5_i16 - 1];
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            if (c5_b_i != c5_j) {
              c5_c_st.site = &c5_bb_emlrtRSI;
              c5_h_i = c5_j;
              c5_rootj = c5_h_i;
              do {
                c5_exitg1 = 0;
                c5_i22 = (int32_T)(c5_rootj + 1.0);
                if ((c5_i22 < 1) || (c5_i22 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i22, 1, 9601, &c5_hb_emlrtBCI,
                    &c5_c_st);
                }

                if (chartInstance->c5_P[c5_i22 - 1] < c5_rootj) {
                  c5_i30 = (int32_T)(c5_rootj + 1.0);
                  if ((c5_i30 < 1) || (c5_i30 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i30, 1, 9601,
                      &c5_ib_emlrtBCI, &c5_c_st);
                  }

                  c5_rootj = chartInstance->c5_P[c5_i30 - 1];
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              if (c5_d8 > c5_rootj) {
                c5_d8 = c5_rootj;
              }

              c5_c_st.site = &c5_cb_emlrtRSI;
              c5_n_i = c5_j;
              c5_d_root = c5_d8;
              do {
                c5_exitg1 = 0;
                c5_i49 = (int32_T)(c5_n_i + 1.0);
                if ((c5_i49 < 1) || (c5_i49 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i49, 1, 9601, &c5_kb_emlrtBCI,
                    &c5_c_st);
                }

                if (chartInstance->c5_P[c5_i49 - 1] < c5_n_i) {
                  c5_i56 = (int32_T)(c5_n_i + 1.0);
                  if ((c5_i56 < 1) || (c5_i56 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i56, 1, 9601,
                      &c5_lb_emlrtBCI, &c5_c_st);
                  }

                  c5_h_j = chartInstance->c5_P[c5_i56 - 1];
                  c5_i64 = (int32_T)(c5_n_i + 1.0);
                  if ((c5_i64 < 1) || (c5_i64 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i64, 1, 9601,
                      &c5_v_emlrtBCI, &c5_c_st);
                  }

                  chartInstance->c5_P[c5_i64 - 1] = c5_d_root;
                  c5_n_i = c5_h_j;
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              c5_i63 = (int32_T)(c5_n_i + 1.0);
              if ((c5_i63 < 1) || (c5_i63 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i63, 1, 9601, &c5_w_emlrtBCI,
                  &c5_c_st);
              }

              chartInstance->c5_P[c5_i63 - 1] = c5_d_root;
            }

            c5_c_st.site = &c5_db_emlrtRSI;
            c5_i_i = c5_b_i;
            c5_root = c5_d8;
            do {
              c5_exitg1 = 0;
              c5_i24 = (int32_T)(c5_i_i + 1.0);
              if ((c5_i24 < 1) || (c5_i24 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i24, 1, 9601, &c5_kb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i24 - 1] < c5_i_i) {
                c5_i32 = (int32_T)(c5_i_i + 1.0);
                if ((c5_i32 < 1) || (c5_i32 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i32, 1, 9601, &c5_lb_emlrtBCI,
                    &c5_c_st);
                }

                c5_d_j = chartInstance->c5_P[c5_i32 - 1];
                c5_i40 = (int32_T)(c5_i_i + 1.0);
                if ((c5_i40 < 1) || (c5_i40 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i40, 1, 9601, &c5_v_emlrtBCI,
                    &c5_c_st);
                }

                chartInstance->c5_P[c5_i40 - 1] = c5_root;
                c5_i_i = c5_d_j;
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            c5_i39 = (int32_T)(c5_i_i + 1.0);
            if ((c5_i39 < 1) || (c5_i39 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i39, 1, 9601, &c5_w_emlrtBCI,
                &c5_c_st);
            }

            chartInstance->c5_P[c5_i39 - 1] = c5_root;
            c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1] = c5_d8;
          }
        }

        if (c5_b_r < 120.0) {
          c5_c_q0 = c5_c;
          c5_c_q1 = 1;
          if ((c5_c_q1 < 0) && (c5_c_q0 > c5_c_q1 + MAX_int32_T)) {
            c5_c_qY = MAX_int32_T;
          } else if ((c5_c_q1 > 0) && (c5_c_q0 < c5_c_q1 + MIN_int32_T)) {
            c5_c_qY = MIN_int32_T;
          } else {
            c5_c_qY = c5_c_q0 - c5_c_q1;
          }

          c5_i3 = c5_c_qY;
          if ((c5_i3 < 1) || (c5_i3 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 160, &c5_bb_emlrtBCI, &c5_st);
          }

          c5_d4 = c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * (c5_i3 - 1)) - 1];
          if (c5_d4 != 0.0) {
            c5_b_st.site = &c5_ib_emlrtRSI;
            c5_f_q0 = c5_c;
            c5_f_q1 = 1;
            if ((c5_f_q1 < 0) && (c5_f_q0 > c5_f_q1 + MAX_int32_T)) {
              c5_f_qY = MAX_int32_T;
            } else if ((c5_f_q1 > 0) && (c5_f_q0 < c5_f_q1 + MIN_int32_T)) {
              c5_f_qY = MIN_int32_T;
            } else {
              c5_f_qY = c5_f_q0 - c5_f_q1;
            }

            c5_i8 = c5_f_qY;
            if ((c5_i8 < 1) || (c5_i8 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c5_i8, 1, 160, &c5_fb_emlrtBCI,
                &c5_b_st);
            }

            c5_c_i = c5_c_L[((int32_T)(c5_b_r + 1.0) + 120 * (c5_i8 - 1)) - 1];
            c5_b_j = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
            c5_c_st.site = &c5_ab_emlrtRSI;
            c5_f_i = c5_c_i;
            c5_d9 = c5_f_i;
            do {
              c5_exitg1 = 0;
              c5_i12 = (int32_T)(c5_d9 + 1.0);
              if ((c5_i12 < 1) || (c5_i12 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i12, 1, 9601, &c5_hb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i12 - 1] < c5_d9) {
                c5_i17 = (int32_T)(c5_d9 + 1.0);
                if ((c5_i17 < 1) || (c5_i17 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i17, 1, 9601, &c5_ib_emlrtBCI,
                    &c5_c_st);
                }

                c5_d9 = chartInstance->c5_P[c5_i17 - 1];
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            if (c5_c_i != c5_b_j) {
              c5_c_st.site = &c5_bb_emlrtRSI;
              c5_j_i = c5_b_j;
              c5_b_rootj = c5_j_i;
              do {
                c5_exitg1 = 0;
                c5_i26 = (int32_T)(c5_b_rootj + 1.0);
                if ((c5_i26 < 1) || (c5_i26 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i26, 1, 9601, &c5_hb_emlrtBCI,
                    &c5_c_st);
                }

                if (chartInstance->c5_P[c5_i26 - 1] < c5_b_rootj) {
                  c5_i34 = (int32_T)(c5_b_rootj + 1.0);
                  if ((c5_i34 < 1) || (c5_i34 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i34, 1, 9601,
                      &c5_ib_emlrtBCI, &c5_c_st);
                  }

                  c5_b_rootj = chartInstance->c5_P[c5_i34 - 1];
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              if (c5_d9 > c5_b_rootj) {
                c5_d9 = c5_b_rootj;
              }

              c5_c_st.site = &c5_cb_emlrtRSI;
              c5_o_i = c5_b_j;
              c5_e_root = c5_d9;
              do {
                c5_exitg1 = 0;
                c5_i52 = (int32_T)(c5_o_i + 1.0);
                if ((c5_i52 < 1) || (c5_i52 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i52, 1, 9601, &c5_kb_emlrtBCI,
                    &c5_c_st);
                }

                if (chartInstance->c5_P[c5_i52 - 1] < c5_o_i) {
                  c5_i60 = (int32_T)(c5_o_i + 1.0);
                  if ((c5_i60 < 1) || (c5_i60 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i60, 1, 9601,
                      &c5_lb_emlrtBCI, &c5_c_st);
                  }

                  c5_i_j = chartInstance->c5_P[c5_i60 - 1];
                  c5_i69 = (int32_T)(c5_o_i + 1.0);
                  if ((c5_i69 < 1) || (c5_i69 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i69, 1, 9601,
                      &c5_v_emlrtBCI, &c5_c_st);
                  }

                  chartInstance->c5_P[c5_i69 - 1] = c5_e_root;
                  c5_o_i = c5_i_j;
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              c5_i66 = (int32_T)(c5_o_i + 1.0);
              if ((c5_i66 < 1) || (c5_i66 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i66, 1, 9601, &c5_w_emlrtBCI,
                  &c5_c_st);
              }

              chartInstance->c5_P[c5_i66 - 1] = c5_e_root;
            }

            c5_c_st.site = &c5_db_emlrtRSI;
            c5_l_i = c5_c_i;
            c5_b_root = c5_d9;
            do {
              c5_exitg1 = 0;
              c5_i28 = (int32_T)(c5_l_i + 1.0);
              if ((c5_i28 < 1) || (c5_i28 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i28, 1, 9601, &c5_kb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i28 - 1] < c5_l_i) {
                c5_i36 = (int32_T)(c5_l_i + 1.0);
                if ((c5_i36 < 1) || (c5_i36 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i36, 1, 9601, &c5_lb_emlrtBCI,
                    &c5_c_st);
                }

                c5_e_j = chartInstance->c5_P[c5_i36 - 1];
                c5_i43 = (int32_T)(c5_l_i + 1.0);
                if ((c5_i43 < 1) || (c5_i43 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i43, 1, 9601, &c5_v_emlrtBCI,
                    &c5_c_st);
                }

                chartInstance->c5_P[c5_i43 - 1] = c5_b_root;
                c5_l_i = c5_e_j;
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            c5_i41 = (int32_T)(c5_l_i + 1.0);
            if ((c5_i41 < 1) || (c5_i41 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i41, 1, 9601, &c5_w_emlrtBCI,
                &c5_c_st);
            }

            chartInstance->c5_P[c5_i41 - 1] = c5_b_root;
            c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1] = c5_d9;
          }
        }

        c5_d_q0 = c5_c;
        c5_d_q1 = 1;
        if ((c5_d_q1 < 0) && (c5_d_q0 > c5_d_q1 + MAX_int32_T)) {
          c5_d_qY = MAX_int32_T;
        } else if ((c5_d_q1 > 0) && (c5_d_q0 < c5_d_q1 + MIN_int32_T)) {
          c5_d_qY = MIN_int32_T;
        } else {
          c5_d_qY = c5_d_q0 - c5_d_q1;
        }

        c5_i4 = c5_d_qY;
        if ((c5_i4 < 1) || (c5_i4 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 160, &c5_eb_emlrtBCI, &c5_st);
        }

        c5_d5 = c5_c_L[((int32_T)c5_b_r + 120 * (c5_i4 - 1)) - 1];
        if (c5_d5 != 0.0) {
          c5_b_st.site = &c5_jb_emlrtRSI;
          c5_g_q0 = c5_c;
          c5_g_q1 = 1;
          if ((c5_g_q1 < 0) && (c5_g_q0 > c5_g_q1 + MAX_int32_T)) {
            c5_g_qY = MAX_int32_T;
          } else if ((c5_g_q1 > 0) && (c5_g_q0 < c5_g_q1 + MIN_int32_T)) {
            c5_g_qY = MIN_int32_T;
          } else {
            c5_g_qY = c5_g_q0 - c5_g_q1;
          }

          c5_i9 = c5_g_qY;
          if ((c5_i9 < 1) || (c5_i9 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c5_i9, 1, 160, &c5_gb_emlrtBCI,
              &c5_b_st);
          }

          c5_d_i = c5_c_L[((int32_T)c5_b_r + 120 * (c5_i9 - 1)) - 1];
          c5_c_j = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
          c5_c_st.site = &c5_ab_emlrtRSI;
          c5_g_i = c5_d_i;
          c5_d11 = c5_g_i;
          do {
            c5_exitg1 = 0;
            c5_i14 = (int32_T)(c5_d11 + 1.0);
            if ((c5_i14 < 1) || (c5_i14 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i14, 1, 9601, &c5_hb_emlrtBCI,
                &c5_c_st);
            }

            if (chartInstance->c5_P[c5_i14 - 1] < c5_d11) {
              c5_i19 = (int32_T)(c5_d11 + 1.0);
              if ((c5_i19 < 1) || (c5_i19 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i19, 1, 9601, &c5_ib_emlrtBCI,
                  &c5_c_st);
              }

              c5_d11 = chartInstance->c5_P[c5_i19 - 1];
            } else {
              c5_exitg1 = 1;
            }
          } while (c5_exitg1 == 0);

          if (c5_d_i != c5_c_j) {
            c5_c_st.site = &c5_bb_emlrtRSI;
            c5_k_i = c5_c_j;
            c5_c_rootj = c5_k_i;
            do {
              c5_exitg1 = 0;
              c5_i27 = (int32_T)(c5_c_rootj + 1.0);
              if ((c5_i27 < 1) || (c5_i27 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i27, 1, 9601, &c5_hb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i27 - 1] < c5_c_rootj) {
                c5_i35 = (int32_T)(c5_c_rootj + 1.0);
                if ((c5_i35 < 1) || (c5_i35 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i35, 1, 9601, &c5_ib_emlrtBCI,
                    &c5_c_st);
                }

                c5_c_rootj = chartInstance->c5_P[c5_i35 - 1];
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            if (c5_d11 > c5_c_rootj) {
              c5_d11 = c5_c_rootj;
            }

            c5_c_st.site = &c5_cb_emlrtRSI;
            c5_p_i = c5_c_j;
            c5_f_root = c5_d11;
            do {
              c5_exitg1 = 0;
              c5_i55 = (int32_T)(c5_p_i + 1.0);
              if ((c5_i55 < 1) || (c5_i55 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i55, 1, 9601, &c5_kb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_P[c5_i55 - 1] < c5_p_i) {
                c5_i62 = (int32_T)(c5_p_i + 1.0);
                if ((c5_i62 < 1) || (c5_i62 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i62, 1, 9601, &c5_lb_emlrtBCI,
                    &c5_c_st);
                }

                c5_j_j = chartInstance->c5_P[c5_i62 - 1];
                c5_i70 = (int32_T)(c5_p_i + 1.0);
                if ((c5_i70 < 1) || (c5_i70 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i70, 1, 9601, &c5_v_emlrtBCI,
                    &c5_c_st);
                }

                chartInstance->c5_P[c5_i70 - 1] = c5_f_root;
                c5_p_i = c5_j_j;
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            c5_i68 = (int32_T)(c5_p_i + 1.0);
            if ((c5_i68 < 1) || (c5_i68 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i68, 1, 9601, &c5_w_emlrtBCI,
                &c5_c_st);
            }

            chartInstance->c5_P[c5_i68 - 1] = c5_f_root;
          }

          c5_c_st.site = &c5_db_emlrtRSI;
          c5_m_i = c5_d_i;
          c5_c_root = c5_d11;
          do {
            c5_exitg1 = 0;
            c5_i29 = (int32_T)(c5_m_i + 1.0);
            if ((c5_i29 < 1) || (c5_i29 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i29, 1, 9601, &c5_kb_emlrtBCI,
                &c5_c_st);
            }

            if (chartInstance->c5_P[c5_i29 - 1] < c5_m_i) {
              c5_i38 = (int32_T)(c5_m_i + 1.0);
              if ((c5_i38 < 1) || (c5_i38 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i38, 1, 9601, &c5_lb_emlrtBCI,
                  &c5_c_st);
              }

              c5_f_j = chartInstance->c5_P[c5_i38 - 1];
              c5_i46 = (int32_T)(c5_m_i + 1.0);
              if ((c5_i46 < 1) || (c5_i46 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i46, 1, 9601, &c5_v_emlrtBCI,
                  &c5_c_st);
              }

              chartInstance->c5_P[c5_i46 - 1] = c5_c_root;
              c5_m_i = c5_f_j;
            } else {
              c5_exitg1 = 1;
            }
          } while (c5_exitg1 == 0);

          c5_i42 = (int32_T)(c5_m_i + 1.0);
          if ((c5_i42 < 1) || (c5_i42 > 9601)) {
            emlrtDynamicBoundsCheckR2012b(c5_i42, 1, 9601, &c5_w_emlrtBCI,
              &c5_c_st);
          }

          chartInstance->c5_P[c5_i42 - 1] = c5_c_root;
          c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1] = c5_d11;
        }
      }
    }

    if ((c5_c < 1) || (c5_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_c, 1, 168, &c5_x_emlrtBCI, &c5_st);
    }

    c5_c = c5_chunksSizeAndLabels[c5_c - 1];
  }

  c5_b_numComponents = 1.0;
  c5_c = 1;
  while ((real_T)c5_c <= 160.0) {
    c5_q0 = c5_c;
    c5_q1 = 1;
    if ((c5_q1 < 0) && (c5_q0 > c5_q1 + MAX_int32_T)) {
      c5_qY = MAX_int32_T;
    } else if ((c5_q1 > 0) && (c5_q0 < c5_q1 + MIN_int32_T)) {
      c5_qY = MIN_int32_T;
    } else {
      c5_qY = c5_q0 - c5_q1;
    }

    c5_f_x = c5_qY;
    c5_g_x = c5_f_x;
    c5_h_x = c5_g_x;
    c5_i_x = c5_h_x;
    c5_b_a = c5_i_x;
    c5_j_x = c5_b_a;
    c5_z = (real_T)c5_j_x / 2.0;
    c5_d2 = muDoubleScalarRound(c5_z);
    if (c5_d2 < 2.147483648E+9) {
      if (c5_d2 >= -2.147483648E+9) {
        c5_i5 = (int32_T)c5_d2;
      } else {
        c5_i5 = MIN_int32_T;
      }
    } else if (c5_d2 >= 2.147483648E+9) {
      c5_i5 = MAX_int32_T;
    } else {
      c5_i5 = 0;
    }

    c5_b_z = c5_i5;
    c5_m_x = c5_b_z;
    c5_c_a = c5_m_x;
    c5_i7 = (int64_T)c5_c_a * 60LL;
    if (c5_i7 > 2147483647LL) {
      c5_i7 = 2147483647LL;
    } else if (c5_i7 < -2147483648LL) {
      c5_i7 = -2147483648LL;
    }

    c5_b_y = (int32_T)c5_i7;
    c5_h_q0 = c5_b_y;
    c5_h_q1 = 1;
    if ((c5_h_q1 < 0) && (c5_h_q0 < MIN_int32_T - c5_h_q1)) {
      c5_h_qY = MIN_int32_T;
    } else if ((c5_h_q1 > 0) && (c5_h_q0 > MAX_int32_T - c5_h_q1)) {
      c5_h_qY = MAX_int32_T;
    } else {
      c5_h_qY = c5_h_q0 + c5_h_q1;
    }

    c5_stripeFirstLabel = c5_h_qY;
    c5_i_q0 = c5_stripeFirstLabel;
    c5_i_q1 = 1;
    if ((c5_i_q1 < 0) && (c5_i_q0 < MIN_int32_T - c5_i_q1)) {
      c5_i_qY = MIN_int32_T;
    } else if ((c5_i_q1 > 0) && (c5_i_q0 > MAX_int32_T - c5_i_q1)) {
      c5_i_qY = MAX_int32_T;
    } else {
      c5_i_qY = c5_i_q0 + c5_i_q1;
    }

    c5_i18 = c5_i_qY;
    c5_j_q0 = c5_c;
    c5_j_q1 = 1;
    if ((c5_j_q1 < 0) && (c5_j_q0 < MIN_int32_T - c5_j_q1)) {
      c5_j_qY = MIN_int32_T;
    } else if ((c5_j_q1 > 0) && (c5_j_q0 > MAX_int32_T - c5_j_q1)) {
      c5_j_qY = MAX_int32_T;
    } else {
      c5_j_qY = c5_j_q0 + c5_j_q1;
    }

    c5_i21 = c5_j_qY;
    if ((c5_i21 < 1) || (c5_i21 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 168, &c5_jb_emlrtBCI, &c5_st);
    }

    c5_k_q0 = c5_stripeFirstLabel;
    c5_k_q1 = c5_chunksSizeAndLabels[c5_i21 - 1];
    if ((c5_k_q0 < 0) && (c5_k_q1 < MIN_int32_T - c5_k_q0)) {
      c5_k_qY = MIN_int32_T;
    } else if ((c5_k_q0 > 0) && (c5_k_q1 > MAX_int32_T - c5_k_q0)) {
      c5_k_qY = MAX_int32_T;
    } else {
      c5_k_qY = c5_k_q0 + c5_k_q1;
    }

    c5_i37 = c5_k_qY;
    c5_b_st.site = &c5_kb_emlrtRSI;
    c5_e_a = c5_i18;
    c5_c_b = c5_i37;
    c5_f_a = c5_e_a;
    c5_d_b = c5_c_b;
    if (c5_f_a > c5_d_b) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_q_i = c5_i18; c5_q_i <= c5_i37; c5_q_i++) {
      if ((c5_q_i < 1) || (c5_q_i > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c5_q_i, 1, 9601, &c5_nb_emlrtBCI, &c5_st);
      }

      c5_l_q0 = c5_q_i;
      c5_l_q1 = 1;
      if ((c5_l_q1 < 0) && (c5_l_q0 > c5_l_q1 + MAX_int32_T)) {
        c5_l_qY = MAX_int32_T;
      } else if ((c5_l_q1 > 0) && (c5_l_q0 < c5_l_q1 + MIN_int32_T)) {
        c5_l_qY = MIN_int32_T;
      } else {
        c5_l_qY = c5_l_q0 - c5_l_q1;
      }

      if (chartInstance->c5_P[c5_q_i - 1] < (real_T)c5_l_qY) {
        c5_i73 = (int32_T)(chartInstance->c5_P[c5_q_i - 1] + 1.0);
        if ((c5_i73 < 1) || (c5_i73 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c5_i73, 1, 9601, &c5_pb_emlrtBCI, &c5_st);
        }

        chartInstance->c5_P[c5_q_i - 1] = chartInstance->c5_P[c5_i73 - 1];
      } else {
        chartInstance->c5_P[c5_q_i - 1] = c5_b_numComponents;
        c5_b_numComponents++;
      }
    }

    if ((c5_c < 1) || (c5_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_c, 1, 168, &c5_mb_emlrtBCI, &c5_st);
    }

    c5_c = c5_chunksSizeAndLabels[c5_c - 1];
  }

  c5_b_numComponents--;
  for (c5_c_c = 0; c5_c_c < 160; c5_c_c++) {
    c5_b_c = (real_T)c5_c_c + 1.0;
    for (c5_c_r = 0; c5_c_r < 120; c5_c_r++) {
      c5_b_r = (real_T)c5_c_r + 1.0;
      c5_i1 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) -
                        1] + 1.0);
      if ((c5_i1 < 1) || (c5_i1 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 9601, &c5_db_emlrtBCI, &c5_st);
      }

      c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
        chartInstance->c5_P[c5_i1 - 1];
    }
  }

  *c5_numComponents = c5_b_numComponents;
}

static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp)
{
  static char_T c5_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c5_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c5_sp, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14, sf_mex_call
              (c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c5_sp, NULL,
    "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
}

static void c5_imfill(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
                      boolean_T c5_I2[19200])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_idx[320];
  real_T c5_b_tmp_data[160];
  real_T c5_imSizeT[2];
  real_T c5_M;
  real_T c5_a;
  real_T c5_b_a;
  real_T c5_b_d;
  real_T c5_b_k;
  real_T c5_c_a;
  real_T c5_c_b;
  real_T c5_c_j;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_a;
  real_T c5_d_i;
  real_T c5_e_a;
  real_T c5_f_a;
  real_T c5_g_a;
  real_T c5_g_j;
  real_T c5_h_a;
  real_T c5_h_i;
  real_T c5_idx1;
  real_T c5_idx2;
  real_T c5_j_j;
  real_T c5_k_i;
  int32_T c5_tmp_data[160];
  int32_T c5_b_tmp_size[2];
  int32_T c5_iv[1];
  int32_T c5_iv1[1];
  int32_T c5_tmp_size[1];
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_b_ix;
  int32_T c5_b_j;
  int32_T c5_b_loop_ub;
  int32_T c5_b_nz;
  int32_T c5_b_xoffset;
  int32_T c5_c;
  int32_T c5_c_c;
  int32_T c5_c_i;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_b;
  int32_T c5_d_c;
  int32_T c5_d_j;
  int32_T c5_d_k;
  int32_T c5_e_b;
  int32_T c5_e_c;
  int32_T c5_e_i;
  int32_T c5_e_j;
  int32_T c5_f_c;
  int32_T c5_f_i;
  int32_T c5_f_j;
  int32_T c5_g_c;
  int32_T c5_g_i;
  int32_T c5_h_c;
  int32_T c5_h_j;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_i;
  int32_T c5_i_j;
  int32_T c5_ix;
  int32_T c5_j;
  int32_T c5_j_i;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nz;
  int32_T c5_xoffset;
  uint32_T c5_b_q0;
  uint32_T c5_b_qY;
  uint32_T c5_c_q0;
  uint32_T c5_c_qY;
  uint32_T c5_q0;
  uint32_T c5_qY;
  uint32_T c5_u;
  uint32_T c5_u1;
  uint32_T c5_u2;
  uint8_T c5_markerPad[19764];
  uint8_T c5_maskPad[19764];
  uint8_T c5_mask[19200];
  boolean_T c5_x[160];
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_mask[c5_i] = (uint8_T)c5_varargin_1[c5_i];
  }

  c5_st.site = &c5_ob_emlrtRSI;
  c5_b_st.site = &c5_pb_emlrtRSI;
  for (c5_b_i = 0; c5_b_i < 122; c5_b_i++) {
    c5_d_i = (real_T)c5_b_i + 1.0;
    c5_maskPad[(int32_T)c5_d_i - 1] = 0U;
  }

  for (c5_c_i = 0; c5_c_i < 122; c5_c_i++) {
    c5_d_i = (real_T)c5_c_i + 1.0;
    c5_maskPad[(int32_T)c5_d_i + 19641] = 0U;
  }

  for (c5_j = 0; c5_j < 160; c5_j++) {
    c5_c_j = (real_T)c5_j + 1.0;
    c5_a = c5_c_j;
    c5_c = (int32_T)c5_a;
    c5_maskPad[122 * c5_c] = 0U;
  }

  for (c5_b_j = 0; c5_b_j < 160; c5_b_j++) {
    c5_c_j = (real_T)c5_b_j + 1.0;
    c5_b_a = c5_c_j;
    c5_b_c = (int32_T)c5_b_a;
    c5_maskPad[121 + 122 * c5_b_c] = 0U;
  }

  for (c5_d_j = 0; c5_d_j < 160; c5_d_j++) {
    c5_c_j = (real_T)c5_d_j + 1.0;
    for (c5_e_i = 0; c5_e_i < 120; c5_e_i++) {
      c5_d_i = (real_T)c5_e_i + 1.0;
      c5_c_a = c5_d_i;
      c5_c_c = (int32_T)c5_c_a;
      c5_d_a = c5_c_j;
      c5_d_c = (int32_T)c5_d_a;
      c5_i1 = c5_c_c + 1;
      if ((c5_i1 < 1) || (c5_i1 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 122, &c5_pc_emlrtBCI, &c5_b_st);
      }

      c5_maskPad[(c5_i1 + 122 * c5_d_c) - 1] = c5_mask[((int32_T)c5_d_i + 120 *
        ((int32_T)c5_c_j - 1)) - 1];
    }
  }

  c5_st.site = &c5_nb_emlrtRSI;
  c5_b_st.site = &c5_pb_emlrtRSI;
  for (c5_f_i = 0; c5_f_i < 122; c5_f_i++) {
    c5_h_i = (real_T)c5_f_i + 1.0;
    c5_markerPad[(int32_T)c5_h_i - 1] = 0U;
  }

  for (c5_g_i = 0; c5_g_i < 122; c5_g_i++) {
    c5_h_i = (real_T)c5_g_i + 1.0;
    c5_markerPad[(int32_T)c5_h_i + 19641] = 0U;
  }

  for (c5_e_j = 0; c5_e_j < 160; c5_e_j++) {
    c5_g_j = (real_T)c5_e_j + 1.0;
    c5_e_a = c5_g_j;
    c5_e_c = (int32_T)c5_e_a;
    c5_markerPad[122 * c5_e_c] = 0U;
  }

  for (c5_f_j = 0; c5_f_j < 160; c5_f_j++) {
    c5_g_j = (real_T)c5_f_j + 1.0;
    c5_f_a = c5_g_j;
    c5_f_c = (int32_T)c5_f_a;
    c5_markerPad[121 + 122 * c5_f_c] = 0U;
  }

  for (c5_h_j = 0; c5_h_j < 160; c5_h_j++) {
    c5_g_j = (real_T)c5_h_j + 1.0;
    for (c5_i_i = 0; c5_i_i < 120; c5_i_i++) {
      c5_h_i = (real_T)c5_i_i + 1.0;
      c5_g_a = c5_h_i;
      c5_g_c = (int32_T)c5_g_a;
      c5_h_a = c5_g_j;
      c5_h_c = (int32_T)c5_h_a;
      c5_i6 = c5_g_c + 1;
      if ((c5_i6 < 1) || (c5_i6 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c5_i6, 1, 122, &c5_pc_emlrtBCI, &c5_b_st);
      }

      c5_markerPad[(c5_i6 + 122 * c5_h_c) - 1] = MAX_uint8_T;
    }
  }

  for (c5_i2 = 0; c5_i2 < 320; c5_i2++) {
    c5_idx[c5_i2] = 0.0;
  }

  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_d = (real_T)(122 + 40 * ((int32_T)c5_b_k - 1));
    c5_M = c5_d - 2.0;
    c5_d1 = (real_T)(122 + 40 * ((int32_T)c5_b_k - 1));
    c5_i5 = (int32_T)c5_M - 1;
    c5_tmp_size[0] = c5_i5 + 1;
    c5_loop_ub = c5_i5;
    for (c5_i8 = 0; c5_i8 <= c5_loop_ub; c5_i8++) {
      c5_tmp_data[c5_i8] = c5_i8;
    }

    c5_i10 = (int32_T)c5_b_k;
    c5_b_d = c5_d1 - 1.0;
    c5_c_b = c5_b_d;
    c5_b_tmp_size[0] = 1;
    c5_b_tmp_size[1] = (int32_T)(c5_c_b - 2.0) + 1;
    c5_b_loop_ub = (int32_T)(c5_c_b - 2.0);
    for (c5_i12 = 0; c5_i12 <= c5_b_loop_ub; c5_i12++) {
      c5_b_tmp_data[c5_i12] = 2.0 + (real_T)c5_i12;
    }

    c5_iv[0] = c5_tmp_size[0];
    emlrtSubAssignSizeCheckR2012b(&c5_iv[0], 1, &c5_b_tmp_size[0], 2,
      &c5_d_emlrtECI, (void *)c5_sp);
    c5_iv1[0] = c5_tmp_size[0];
    c5_i14 = c5_i10 - 1;
    c5_c_loop_ub = c5_iv1[0] - 1;
    for (c5_i16 = 0; c5_i16 <= c5_c_loop_ub; c5_i16++) {
      c5_idx[c5_tmp_data[c5_i16] + 160 * c5_i14] = c5_b_tmp_data[c5_i16];
    }
  }

  for (c5_i3 = 0; c5_i3 < 19764; c5_i3++) {
    c5_q0 = 255U;
    c5_qY = c5_q0 - (uint32_T)c5_maskPad[c5_i3];
    if (c5_qY > c5_q0) {
      c5_qY = 0U;
    }

    c5_u = c5_qY;
    if (c5_u > 255U) {
      c5_u = 255U;
    }

    c5_maskPad[c5_i3] = (uint8_T)c5_u;
  }

  for (c5_i4 = 0; c5_i4 < 19764; c5_i4++) {
    c5_b_q0 = 255U;
    c5_b_qY = c5_b_q0 - (uint32_T)c5_markerPad[c5_i4];
    if (c5_b_qY > c5_b_q0) {
      c5_b_qY = 0U;
    }

    c5_u1 = c5_b_qY;
    if (c5_u1 > 255U) {
      c5_u1 = 255U;
    }

    c5_markerPad[c5_i4] = (uint8_T)c5_u1;
  }

  c5_st.site = &c5_mb_emlrtRSI;
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_imSizeT[c5_i7] = 122.0 + 40.0 * (real_T)c5_i7;
  }

  ippreconstruct_uint8(&c5_markerPad[0], &c5_maskPad[0], &c5_imSizeT[0], 1.0);
  for (c5_i9 = 0; c5_i9 < 19764; c5_i9++) {
    c5_c_q0 = 255U;
    c5_c_qY = c5_c_q0 - (uint32_T)c5_markerPad[c5_i9];
    if (c5_c_qY > c5_c_q0) {
      c5_c_qY = 0U;
    }

    c5_u2 = c5_c_qY;
    if (c5_u2 > 255U) {
      c5_u2 = 255U;
    }

    c5_markerPad[c5_i9] = (uint8_T)c5_u2;
  }

  for (c5_i11 = 0; c5_i11 < 160; c5_i11++) {
    c5_x[c5_i11] = (c5_idx[c5_i11] != 0.0);
  }

  c5_nz = (int32_T)c5_x[0];
  for (c5_c_k = 0; c5_c_k < 159; c5_c_k++) {
    c5_xoffset = c5_c_k;
    c5_ix = c5_xoffset;
    c5_d_b = (int32_T)c5_x[c5_ix + 1];
    c5_nz += (c5_d_b != 0);
  }

  c5_idx1 = (real_T)c5_nz;
  for (c5_i13 = 0; c5_i13 < 160; c5_i13++) {
    c5_x[c5_i13] = (c5_idx[c5_i13 + 160] != 0.0);
  }

  c5_b_nz = (int32_T)c5_x[0];
  for (c5_d_k = 0; c5_d_k < 159; c5_d_k++) {
    c5_b_xoffset = c5_d_k;
    c5_b_ix = c5_b_xoffset;
    c5_e_b = (int32_T)c5_x[c5_b_ix + 1];
    c5_b_nz += (c5_e_b != 0);
  }

  c5_idx2 = (real_T)c5_b_nz;
  c5_i15 = (int32_T)c5_idx1;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_idx1, mxDOUBLE_CLASS, c5_i15,
    &c5_jg_emlrtRTEI, (emlrtConstCTX)c5_sp);
  for (c5_j_i = 0; c5_j_i < c5_i15; c5_j_i++) {
    c5_k_i = (real_T)c5_j_i + 1.0;
    c5_i17 = (int32_T)c5_idx2;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_idx2, mxDOUBLE_CLASS, c5_i17,
      &c5_ig_emlrtRTEI, (emlrtConstCTX)c5_sp);
    for (c5_i_j = 0; c5_i_j < c5_i17; c5_i_j++) {
      c5_j_j = (real_T)c5_i_j + 1.0;
      c5_i18 = (int32_T)c5_idx[(int32_T)c5_k_i - 1];
      if ((c5_i18 < 1) || (c5_i18 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c5_i18, 1, 122, &c5_qc_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i19 = (int32_T)c5_idx[(int32_T)c5_j_j + 159];
      if ((c5_i19 < 1) || (c5_i19 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c5_i19, 1, 162, &c5_rc_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i20 = (int32_T)c5_k_i;
      if ((c5_i20 < 1) || (c5_i20 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c5_i20, 1, 120, &c5_sc_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i21 = (int32_T)c5_j_j;
      if ((c5_i21 < 1) || (c5_i21 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 160, &c5_tc_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_I2[(c5_i20 + 120 * (c5_i21 - 1)) - 1] = (c5_markerPad[(c5_i18 + 122 *
        (c5_i19 - 1)) - 1] != 0);
    }
  }
}

static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, uint8_T c5_varargin_1[19200], boolean_T
                    c5_varargout_1[19200])
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  real_T c5_srcSizeT[2];
  real_T c5_b_cutoff;
  real_T c5_b_x;
  real_T c5_c_cutoff;
  real_T c5_c_x;
  real_T c5_cutoff;
  real_T c5_d_x;
  real_T c5_s;
  real_T c5_y;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_ib;
  real32_T c5_x[19200];
  int8_T c5_offset[4];
  boolean_T c5_b_p;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_rb_emlrtRSI;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_srcSizeT[c5_i] = 120.0 + 40.0 * (real_T)c5_i;
  }

  edgesobelprewitt_uint8_tbb(&c5_varargin_1[0], &c5_srcSizeT[0], true, 1.0, 1.0,
    &chartInstance->c5_pGradient1[0], &chartInstance->c5_pGradient2[0],
    &chartInstance->c5_b_b[0]);
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_x[c5_i1] = chartInstance->c5_b_b[c5_i1];
  }

  c5_s = c5_sumColumnB4(chartInstance, c5_x, 1);
  for (c5_ib = 0; c5_ib < 3; c5_ib++) {
    c5_s += c5_sumColumnB4(chartInstance, c5_x, 1 + ((c5_ib + 1) << 12));
  }

  c5_s += c5_sumColumnB(chartInstance, c5_x);
  c5_y = c5_s;
  c5_cutoff = 4.0 * c5_y / 19200.0;
  c5_st.site = &c5_sb_emlrtRSI;
  c5_b_x = c5_cutoff;
  c5_c_x = c5_b_x;
  c5_d_x = c5_c_x;
  if (c5_d_x < 0.0) {
    c5_p = true;
  } else {
    c5_p = false;
  }

  c5_b_p = c5_p;
  if (c5_b_p) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c5_st, &c5_e_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
  }

  c5_st.site = &c5_tb_emlrtRSI;
  c5_b_cutoff = c5_cutoff;
  for (c5_i2 = 0; c5_i2 < 4; c5_i2++) {
    c5_offset[c5_i2] = 0;
  }

  c5_c_cutoff = c5_b_cutoff;
  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_srcSizeT[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
  }

  edgethinning_real32_tbb(&chartInstance->c5_b_b[0],
    &chartInstance->c5_pGradient1[0], &chartInstance->c5_pGradient2[0], 1.0, 1.0,
    &c5_offset[0], 2.2204460492503131E-14, c5_c_cutoff, &c5_varargout_1[0],
    &c5_srcSizeT[0]);
}

static real_T c5_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_x[19200], int32_T c5_vstart)
{
  real_T c5_psum1;
  real_T c5_psum2;
  real_T c5_psum3;
  real_T c5_psum4;
  int32_T c5_b_k;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_k;
  (void)chartInstance;
  c5_i2 = c5_vstart + 1023;
  c5_i3 = c5_vstart + 2047;
  c5_i4 = c5_vstart + 3071;
  c5_psum1 = c5_x[c5_vstart - 1];
  c5_psum2 = c5_x[c5_i2];
  c5_psum3 = c5_x[c5_i3];
  c5_psum4 = c5_x[c5_i4];
  for (c5_k = 0; c5_k < 1023; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_psum1 += (real_T)c5_x[(c5_vstart + c5_b_k) - 1];
    c5_psum2 += (real_T)c5_x[c5_i2 + c5_b_k];
    c5_psum3 += (real_T)c5_x[c5_i3 + c5_b_k];
    c5_psum4 += (real_T)c5_x[c5_i4 + c5_b_k];
  }

  return (c5_psum1 + c5_psum2) + (c5_psum3 + c5_psum4);
}

static real_T c5_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_x[19200])
{
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_b_k;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_k;
  (void)chartInstance;
  c5_y = c5_x[16384];
  for (c5_k = 0; c5_k < 1023; c5_k++) {
    c5_b_k = c5_k;
    c5_y += (real_T)c5_x[c5_b_k + 16385];
  }

  c5_b_y = c5_x[17408];
  for (c5_c_k = 0; c5_c_k < 1023; c5_c_k++) {
    c5_d_k = c5_c_k;
    c5_b_y += (real_T)c5_x[c5_d_k + 17409];
  }

  c5_y += c5_b_y;
  c5_c_y = c5_x[18432];
  for (c5_e_k = 0; c5_e_k < 767; c5_e_k++) {
    c5_f_k = c5_e_k;
    c5_c_y += (real_T)c5_x[c5_f_k + 18433];
  }

  c5_y += c5_c_y;
  return c5_y;
}

static void c5_bwboundaries(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  c5_coder_array_cell_wrap_0 *c5_B, real_T c5_c_L[19200], real_T *c5_b_N,
  c5_coder_array_boolean_T_2D *c5_A)
{
  static real_T c5_b_B[6] = { 1.0, 4.0, 6.0, 8.0, 18.0, 26.0 };

  static real_T c5_dv[6] = { 1.0, 4.0, 6.0, 8.0, 18.0, 26.0 };

  static char_T c5_b_cv1[33] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w',
    'b', 'o', 'u', 'n', 'd', 'a', 'r', 'i', 'e', 's', ':', 'b', 'a', 'd', 'S',
    'c', 'a', 'l', 'a', 'r', 'C', 'o', 'n', 'n' };

  static char_T c5_b_cv[12] = { 'm', 'u', 's', 't', 'B', 'e', 'M', 'e', 'm', 'b',
    'e', 'r' };

  static boolean_T c5_conn[9] = { false, true, false, true, true, true, false,
    true, false };

  c5_cell_wrap_29 c5_args[1];
  c5_cell_wrap_29 c5_r;
  c5_cell_wrap_32 c5_b_connSubs[2];
  c5_cell_wrap_32 c5_connSubs[2];
  c5_cell_wrap_32 c5_subs[2];
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_b_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_c_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_this;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_g_st;
  emlrtStack c5_h_st;
  emlrtStack c5_i_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_imSizeT[2];
  real_T c5_a;
  real_T c5_b_a;
  real_T c5_b_d;
  real_T c5_b_j;
  real_T c5_b_varargin_2;
  real_T c5_b_x;
  real_T c5_b_x2;
  real_T c5_c_N;
  real_T c5_c_a;
  real_T c5_c_b;
  real_T c5_c_d;
  real_T c5_c_i;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_N;
  real_T c5_d_a;
  real_T c5_d_b;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_e_N;
  real_T c5_e_b;
  real_T c5_e_j;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_f_a;
  real_T c5_f_b;
  real_T c5_f_i;
  real_T c5_f_y;
  real_T c5_first;
  real_T c5_g_a;
  real_T c5_h_a;
  real_T c5_holesN;
  real_T c5_i_a;
  real_T c5_last;
  real_T c5_u;
  real_T c5_varargin_2;
  real_T c5_x;
  real_T c5_x2;
  int32_T c5_b_tmp_data[160];
  int32_T c5_tmp_data[120];
  int32_T c5_iv[2];
  int32_T c5_b_tmp_size[1];
  int32_T c5_tmp_size[1];
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_b_varargin_1;
  int32_T c5_c;
  int32_T c5_c_c;
  int32_T c5_c_j;
  int32_T c5_c_loop_ub;
  int32_T c5_d_c;
  int32_T c5_d_i;
  int32_T c5_d_j;
  int32_T c5_d_loop_ub;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_f_j;
  int32_T c5_f_loop_ub;
  int32_T c5_g_i;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_loop_ub;
  int32_T c5_idx;
  int32_T c5_j;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_loop_ub;
  boolean_T c5_BWcomplement[19200];
  boolean_T c5_marker[19200];
  boolean_T c5_b_x_data[3];
  boolean_T c5_varargin_1_data[3];
  boolean_T c5_x_data[3];
  boolean_T c5_b_p;
  boolean_T c5_b_u;
  boolean_T c5_c_p;
  boolean_T c5_d_p;
  boolean_T c5_e_a;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  boolean_T c5_useFirstBorder;
  boolean_T c5_useSecondBorder;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_g_st.prev = &c5_f_st;
  c5_g_st.tls = c5_f_st.tls;
  c5_h_st.prev = &c5_g_st;
  c5_h_st.tls = c5_g_st.tls;
  c5_i_st.prev = &c5_h_st;
  c5_i_st.tls = c5_h_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_r.f1[c5_i] = c5_varargin_1[c5_i];
  }

  c5_args[0] = c5_r;
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_BWcomplement[c5_i1] = c5_args[0].f1[c5_i1];
  }

  c5_st.site = &c5_cc_emlrtRSI;
  c5_bwlabel(chartInstance, &c5_st, c5_BWcomplement, chartInstance->c5_b_L,
             &c5_c_N);
  c5_d_N = c5_c_N;
  c5_st.site = &c5_dc_emlrtRSI;
  c5_e_N = c5_c_N;
  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    c5_BWcomplement[c5_i2] = !c5_BWcomplement[c5_i2];
  }

  c5_b_st.site = &c5_ic_emlrtRSI;
  c5_c_st.site = &c5_mc_emlrtRSI;
  c5_d_st.site = &c5_nc_emlrtRSI;
  c5_e_st.site = &c5_rc_emlrtRSI;
  c5_f_st.site = &c5_sc_emlrtRSI;
  c5_g_st.site = &c5_hc_emlrtRSI;
  c5_h_st.site = &c5_fc_emlrtRSI;
  c5_p = true;
  c5_idx = 0;
  c5_k = 1;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k - 1 < 6)) {
    c5_b_k = c5_k;
    c5_b_varargin_1 = c5_b_k - 1;
    c5_x = c5_dv[c5_b_varargin_1];
    c5_c_b = c5_x;
    c5_varargin_2 = c5_c_b;
    c5_b_varargin_2 = c5_varargin_2;
    c5_b_p = false;
    c5_x2 = c5_b_varargin_2;
    c5_c_p = true;
    c5_b_x2 = c5_x2;
    c5_d_p = (c5_b_x2 == 4.0);
    if (!c5_d_p) {
      c5_c_p = false;
    }

    if (c5_c_p) {
      c5_b_p = true;
    }

    if (c5_b_p) {
      c5_idx = c5_b_k;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (c5_idx == 0) {
    c5_p = false;
  }

  if (!c5_p) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    c5_u = 4.0;
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0, 0U, 0), false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_B, 0, 0U, 1, 0U, 2, 1, 6),
                  false);
    c5_i_st.site = &c5_gc_emlrtRSI;
    c5_feval(chartInstance, &c5_i_st, c5_y, c5_b_y, c5_c_y);
  }

  c5_d_st.site = &c5_oc_emlrtRSI;
  c5_connSubs[0].f1.size[1] = 1;
  c5_connSubs[0].f1.data[0] = 1.0;
  c5_e_st.site = &c5_tc_emlrtRSI;
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    c5_loop_ub = c5_connSubs[0].f1.size[1] - 1;
    for (c5_i4 = 0; c5_i4 <= c5_loop_ub; c5_i4++) {
      c5_x_data[c5_i4 + c5_i3] = c5_conn[((int32_T)c5_connSubs[0].f1.data[c5_i4]
        + 3 * c5_i3) - 1];
    }
  }

  c5_f_st.site = &c5_vc_emlrtRSI;
  c5_g_st.site = &c5_wc_emlrtRSI;
  c5_h_st.site = &c5_xc_emlrtRSI;
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    c5_varargin_1_data[c5_i5] = c5_x_data[c5_i5];
  }

  c5_i_st.site = &c5_yc_emlrtRSI;
  c5_useFirstBorder = c5_allOrAny_anonFcn1(chartInstance, c5_varargin_1_data);
  c5_connSubs[0].f1.size[1] = 1;
  c5_connSubs[0].f1.data[0] = 3.0;
  c5_e_st.site = &c5_uc_emlrtRSI;
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_b_loop_ub = c5_connSubs[0].f1.size[1] - 1;
    for (c5_i7 = 0; c5_i7 <= c5_b_loop_ub; c5_i7++) {
      c5_x_data[c5_i7 + c5_i6] = c5_conn[((int32_T)c5_connSubs[0].f1.data[c5_i7]
        + 3 * c5_i6) - 1];
    }
  }

  c5_f_st.site = &c5_vc_emlrtRSI;
  c5_g_st.site = &c5_wc_emlrtRSI;
  c5_h_st.site = &c5_xc_emlrtRSI;
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_varargin_1_data[c5_i8] = c5_x_data[c5_i8];
  }

  c5_i_st.site = &c5_yc_emlrtRSI;
  c5_useSecondBorder = c5_allOrAny_anonFcn1(chartInstance, c5_varargin_1_data);
  if (c5_useFirstBorder) {
    c5_first = 2.0;
  } else {
    c5_first = 1.0;
  }

  if (c5_useSecondBorder) {
    c5_last = 119.0;
  } else {
    c5_last = 120.0;
  }

  c5_d_st.site = &c5_pc_emlrtRSI;
  c5_a = c5_first;
  c5_d = c5_last;
  c5_e_st.site = &c5_cd_emlrtRSI;
  c5_b_a = c5_a;
  c5_d_b = c5_d;
  c5_b_x = c5_b_a;
  c5_c_x = c5_b_x;
  c5_d_y = c5_c_x;
  c5_d_y = muDoubleScalarFloor(c5_d_y);
  if (c5_d_y == c5_b_a) {
    c5_subs[0].f1.size[1] = (int32_T)(c5_d_b - c5_b_a) + 1;
    c5_c_loop_ub = (int32_T)(c5_d_b - c5_b_a);
    for (c5_i9 = 0; c5_i9 <= c5_c_loop_ub; c5_i9++) {
      c5_subs[0].f1.data[c5_i9] = c5_b_a + (real_T)c5_i9;
    }
  } else {
    c5_f_st.site = &c5_dd_emlrtRSI;
    c5_eml_float_colon(chartInstance, &c5_f_st, c5_b_a, c5_d_b, c5_subs[0].
                       f1.data, c5_subs[0].f1.size);
  }

  c5_d_st.site = &c5_oc_emlrtRSI;
  c5_b_connSubs[1].f1.size[1] = 1;
  c5_b_connSubs[1].f1.data[0] = 1.0;
  c5_e_st.site = &c5_tc_emlrtRSI;
  c5_d_loop_ub = c5_b_connSubs[1].f1.size[1] - 1;
  for (c5_i10 = 0; c5_i10 <= c5_d_loop_ub; c5_i10++) {
    for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
      c5_b_x_data[c5_i11 + 3 * c5_i10] = c5_conn[c5_i11 + 3 * ((int32_T)
        c5_b_connSubs[1].f1.data[c5_i10] - 1)];
    }
  }

  c5_f_st.site = &c5_vc_emlrtRSI;
  c5_g_st.site = &c5_wc_emlrtRSI;
  c5_h_st.site = &c5_xc_emlrtRSI;
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_varargin_1_data[c5_i12] = c5_b_x_data[c5_i12];
  }

  c5_i_st.site = &c5_yc_emlrtRSI;
  c5_useFirstBorder = c5_allOrAny_anonFcn1(chartInstance, c5_varargin_1_data);
  c5_b_connSubs[1].f1.size[1] = 1;
  c5_b_connSubs[1].f1.data[0] = 3.0;
  c5_e_st.site = &c5_uc_emlrtRSI;
  c5_e_loop_ub = c5_b_connSubs[1].f1.size[1] - 1;
  for (c5_i13 = 0; c5_i13 <= c5_e_loop_ub; c5_i13++) {
    for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
      c5_b_x_data[c5_i14 + 3 * c5_i13] = c5_conn[c5_i14 + 3 * ((int32_T)
        c5_b_connSubs[1].f1.data[c5_i13] - 1)];
    }
  }

  c5_f_st.site = &c5_vc_emlrtRSI;
  c5_g_st.site = &c5_wc_emlrtRSI;
  c5_h_st.site = &c5_xc_emlrtRSI;
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    c5_varargin_1_data[c5_i15] = c5_b_x_data[c5_i15];
  }

  c5_i_st.site = &c5_yc_emlrtRSI;
  c5_useSecondBorder = c5_allOrAny_anonFcn1(chartInstance, c5_varargin_1_data);
  if (c5_useFirstBorder) {
    c5_first = 2.0;
  } else {
    c5_first = 1.0;
  }

  if (c5_useSecondBorder) {
    c5_last = 159.0;
  } else {
    c5_last = 160.0;
  }

  c5_d_st.site = &c5_pc_emlrtRSI;
  c5_c_a = c5_first;
  c5_b_d = c5_last;
  c5_e_st.site = &c5_cd_emlrtRSI;
  c5_d_a = c5_c_a;
  c5_e_b = c5_b_d;
  c5_d_x = c5_d_a;
  c5_e_x = c5_d_x;
  c5_e_y = c5_e_x;
  c5_e_y = muDoubleScalarFloor(c5_e_y);
  if (c5_e_y == c5_d_a) {
    c5_subs[1].f1.size[1] = (int32_T)(c5_e_b - c5_d_a) + 1;
    c5_f_loop_ub = (int32_T)(c5_e_b - c5_d_a);
    for (c5_i16 = 0; c5_i16 <= c5_f_loop_ub; c5_i16++) {
      c5_subs[1].f1.data[c5_i16] = c5_d_a + (real_T)c5_i16;
    }
  } else {
    c5_f_st.site = &c5_dd_emlrtRSI;
    c5_eml_float_colon(chartInstance, &c5_f_st, c5_d_a, c5_e_b, c5_subs[1].
                       f1.data, c5_subs[1].f1.size);
  }

  for (c5_i17 = 0; c5_i17 < 19200; c5_i17++) {
    c5_marker[c5_i17] = c5_BWcomplement[c5_i17];
  }

  c5_tmp_size[0] = c5_subs[0].f1.size[1];
  c5_g_loop_ub = c5_subs[0].f1.size[1] - 1;
  for (c5_i18 = 0; c5_i18 <= c5_g_loop_ub; c5_i18++) {
    c5_c_d = c5_subs[0].f1.data[c5_i18];
    if (c5_c_d != (real_T)(int32_T)muDoubleScalarFloor(c5_c_d)) {
      emlrtIntegerCheckR2012b(c5_c_d, &c5_l_emlrtDCI, &c5_c_st);
    }

    c5_i20 = (int32_T)c5_c_d;
    if ((c5_i20 < 1) || (c5_i20 > 120)) {
      emlrtDynamicBoundsCheckR2012b(c5_i20, 1, 120, &c5_uc_emlrtBCI, &c5_c_st);
    }

    c5_tmp_data[c5_i18] = c5_i20;
  }

  c5_b_tmp_size[0] = c5_subs[1].f1.size[1];
  c5_h_loop_ub = c5_subs[1].f1.size[1] - 1;
  for (c5_i19 = 0; c5_i19 <= c5_h_loop_ub; c5_i19++) {
    c5_d1 = c5_subs[1].f1.data[c5_i19];
    if (c5_d1 != (real_T)(int32_T)muDoubleScalarFloor(c5_d1)) {
      emlrtIntegerCheckR2012b(c5_d1, &c5_l_emlrtDCI, &c5_c_st);
    }

    c5_i22 = (int32_T)c5_d1;
    if ((c5_i22 < 1) || (c5_i22 > 160)) {
      emlrtDynamicBoundsCheckR2012b(c5_i22, 1, 160, &c5_vc_emlrtBCI, &c5_c_st);
    }

    c5_b_tmp_data[c5_i19] = c5_i22;
  }

  c5_iv[0] = c5_tmp_size[0];
  c5_iv[1] = c5_b_tmp_size[0];
  c5_i_loop_ub = c5_iv[1] - 1;
  for (c5_i21 = 0; c5_i21 <= c5_i_loop_ub; c5_i21++) {
    c5_j_loop_ub = c5_iv[0] - 1;
    for (c5_i23 = 0; c5_i23 <= c5_j_loop_ub; c5_i23++) {
      c5_marker[(c5_tmp_data[c5_i23] + 120 * (c5_b_tmp_data[c5_i21] - 1)) - 1] =
        false;
    }
  }

  c5_d_st.site = &c5_qc_emlrtRSI;
  c5_e_st.site = &c5_qb_emlrtRSI;
  for (c5_i24 = 0; c5_i24 < 2; c5_i24++) {
    c5_imSizeT[c5_i24] = 120.0 + 40.0 * (real_T)c5_i24;
  }

  ippreconstruct_uint8((uint8_T *)&c5_marker[0], (uint8_T *)&c5_BWcomplement[0],
                       &c5_imSizeT[0], 1.0);
  for (c5_i25 = 0; c5_i25 < 19200; c5_i25++) {
    c5_marker[c5_i25] = !c5_marker[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 19200; c5_i26++) {
    c5_BWcomplement[c5_i26] = (c5_BWcomplement[c5_i26] && c5_marker[c5_i26]);
  }

  c5_b_st.site = &c5_jc_emlrtRSI;
  c5_b_bwlabel(chartInstance, &c5_b_st, c5_BWcomplement,
               chartInstance->c5_labeledHoles, &c5_holesN);
  for (c5_j = 0; c5_j < 160; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_b_i = 0; c5_b_i < 120; c5_b_i++) {
      c5_c_i = (real_T)c5_b_i + 1.0;
      c5_e_a = (chartInstance->c5_labeledHoles[((int32_T)c5_c_i + 120 *
                 ((int32_T)c5_b_j - 1)) - 1] != 0.0);
      c5_f_b = c5_e_N;
      c5_f_y = (real_T)c5_e_a * c5_f_b;
      c5_c_L[((int32_T)c5_c_i + 120 * ((int32_T)c5_b_j - 1)) - 1] =
        (chartInstance->c5_b_L[((int32_T)c5_c_i + 120 * ((int32_T)c5_b_j - 1)) -
         1] + c5_f_y) + chartInstance->c5_labeledHoles[((int32_T)c5_c_i + 120 *
        ((int32_T)c5_b_j - 1)) - 1];
    }
  }

  c5_b_st.site = &c5_kc_emlrtRSI;
  c5_obj = &chartInstance->c5_finder;
  c5_b_obj = c5_obj;
  c5_c_st.site = &c5_hd_emlrtRSI;
  c5_c_obj = c5_b_obj;
  c5_b_obj = c5_c_obj;
  c5_d_st.site = &c5_id_emlrtRSI;
  c5_this = c5_b_obj;
  c5_b_obj = c5_this;
  c5_d_st.site = &c5_jd_emlrtRSI;
  c5_e_st.site = &c5_pb_emlrtRSI;
  for (c5_d_i = 0; c5_d_i < 122; c5_d_i++) {
    c5_f_i = (real_T)c5_d_i + 1.0;
    chartInstance->c5_b[(int32_T)c5_f_i - 1] = 0.0;
  }

  for (c5_e_i = 0; c5_e_i < 122; c5_e_i++) {
    c5_f_i = (real_T)c5_e_i + 1.0;
    chartInstance->c5_b[(int32_T)c5_f_i + 19641] = 0.0;
  }

  for (c5_c_j = 0; c5_c_j < 160; c5_c_j++) {
    c5_e_j = (real_T)c5_c_j + 1.0;
    c5_f_a = c5_e_j;
    c5_c = (int32_T)c5_f_a;
    chartInstance->c5_b[122 * c5_c] = 0.0;
  }

  for (c5_d_j = 0; c5_d_j < 160; c5_d_j++) {
    c5_e_j = (real_T)c5_d_j + 1.0;
    c5_g_a = c5_e_j;
    c5_b_c = (int32_T)c5_g_a;
    chartInstance->c5_b[121 + 122 * c5_b_c] = 0.0;
  }

  for (c5_f_j = 0; c5_f_j < 160; c5_f_j++) {
    c5_e_j = (real_T)c5_f_j + 1.0;
    for (c5_g_i = 0; c5_g_i < 120; c5_g_i++) {
      c5_f_i = (real_T)c5_g_i + 1.0;
      c5_h_a = c5_f_i;
      c5_c_c = (int32_T)c5_h_a;
      c5_i_a = c5_e_j;
      c5_d_c = (int32_T)c5_i_a;
      c5_i28 = c5_c_c + 1;
      if ((c5_i28 < 1) || (c5_i28 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c5_i28, 1, 122, &c5_pc_emlrtBCI, &c5_e_st);
      }

      chartInstance->c5_b[(c5_i28 + 122 * c5_d_c) - 1] = c5_c_L[((int32_T)c5_f_i
        + 120 * ((int32_T)c5_e_j - 1)) - 1];
    }
  }

  for (c5_i27 = 0; c5_i27 < 19764; c5_i27++) {
    c5_b_obj->paddedLabelMatrix[c5_i27] = chartInstance->c5_b[c5_i27];
  }

  c5_b_obj->numRows = 122;
  c5_b_obj->numCols = 162;
  c5_b_u = true;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0, 0U, 0), false);
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                false);
  c5_d_st.site = &c5_kd_emlrtRSI;
  c5_assert(chartInstance, &c5_d_st, c5_g_y, sf_mex_call(&c5_c_st, NULL,
             "message", 1U, 1U, 14, c5_h_y));
  c5_b_obj->conn = 8.0;
  c5_b_obj->ConnectivityHoles = 4.0;
  c5_b_st.site = &c5_lc_emlrtRSI;
  c5_BoundaryFinderObjectHoles_findBoundaries(chartInstance, &c5_b_st,
    &chartInstance->c5_finder, c5_e_N, c5_holesN, c5_B);
  c5_st.site = &c5_ec_emlrtRSI;
  c5_adjacencyMatrix(chartInstance, &c5_st, c5_B, c5_c_N, c5_A);
  *c5_b_N = c5_d_N;
}

static boolean_T c5_allOrAny_anonFcn1(SFc5_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c5_x_data[])
{
  int32_T c5_ix;
  boolean_T c5_c_b;
  boolean_T c5_exitg1;
  boolean_T c5_varargout_1;
  (void)chartInstance;
  c5_varargout_1 = false;
  c5_ix = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ix + 1 < 4)) {
    if (!c5_x_data[c5_ix]) {
      c5_c_b = true;
    } else {
      c5_c_b = false;
    }

    if (!c5_c_b) {
      c5_varargout_1 = true;
      c5_exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_varargout_1;
}

static void c5_eml_float_colon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_a, real_T c5_c_b, real_T
  c5_y_data[], int32_T c5_y_size[2])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_a1;
  real_T c5_apnd;
  real_T c5_b1;
  real_T c5_b_a;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c;
  real_T c5_c_a;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_cdiff;
  real_T c5_d_b;
  real_T c5_d_x;
  real_T c5_e_b;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_kd;
  real_T c5_ndbl;
  real_T c5_thresh;
  real_T c5_x;
  real_T c5_y;
  int32_T c5_b_k;
  int32_T c5_d_a;
  int32_T c5_d_y;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_k;
  int32_T c5_n;
  int32_T c5_nm1;
  int32_T c5_nm1d2;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_a = c5_a;
  c5_d_b = c5_c_b;
  c5_a1 = c5_b_a;
  c5_x = (c5_d_b - c5_b_a) + 0.5;
  c5_b_x = c5_x;
  c5_ndbl = c5_b_x;
  c5_ndbl = muDoubleScalarFloor(c5_ndbl);
  c5_apnd = c5_b_a + c5_ndbl;
  c5_cdiff = c5_apnd - c5_d_b;
  c5_c_a = c5_b_a;
  c5_e_b = c5_d_b;
  c5_c_x = c5_c_a;
  c5_d_x = c5_c_x;
  c5_e_x = c5_d_x;
  c5_y = muDoubleScalarAbs(c5_e_x);
  c5_f_x = c5_e_b;
  c5_g_x = c5_f_x;
  c5_h_x = c5_g_x;
  c5_b_y = muDoubleScalarAbs(c5_h_x);
  c5_c = muDoubleScalarMax(c5_y, c5_b_y);
  c5_thresh = 4.4408920985006262E-16 * c5_c;
  c5_i_x = c5_cdiff;
  c5_j_x = c5_i_x;
  c5_k_x = c5_j_x;
  c5_c_y = muDoubleScalarAbs(c5_k_x);
  if (c5_c_y < c5_thresh) {
    c5_ndbl++;
    c5_b1 = c5_d_b;
  } else if (c5_cdiff > 0.0) {
    c5_b1 = c5_b_a + (c5_ndbl - 1.0);
  } else {
    c5_ndbl++;
    c5_b1 = c5_apnd;
  }

  c5_n = (int32_T)muDoubleScalarFloor(c5_ndbl) - 1;
  c5_y_size[0] = 1;
  c5_y_size[1] = c5_n + 1;
  c5_y_data[0] = c5_a1;
  c5_y_data[c5_n] = c5_b1;
  c5_nm1 = c5_n;
  c5_d_a = c5_nm1;
  c5_nm1d2 = (uint8_T)((uint32_T)(uint8_T)c5_d_a >> 1);
  c5_i = c5_nm1d2 - 1;
  c5_st.site = &c5_ed_emlrtRSI;
  c5_f_b = c5_i;
  c5_g_b = c5_f_b;
  if (c5_g_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_g_b > 2147483646);
  }

  if (c5_overflow) {
    c5_b_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
  }

  c5_i1 = (uint8_T)c5_i - 1;
  for (c5_k = 0; c5_k <= c5_i1; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_kd = (real_T)c5_b_k;
    c5_y_data[c5_b_k] = c5_a1 + c5_kd;
    c5_y_data[c5_n - c5_b_k] = c5_b1 - c5_kd;
  }

  c5_h_b = c5_nm1d2;
  c5_d_y = c5_h_b << 1;
  if (c5_d_y == c5_nm1) {
    c5_y_data[c5_nm1d2] = (c5_a1 + c5_b1) / 2.0;
  } else {
    c5_kd = (real_T)c5_nm1d2;
    c5_y_data[c5_nm1d2] = c5_a1 + c5_kd;
    c5_y_data[c5_nm1d2 + 1] = c5_b1 - c5_kd;
  }
}

static void c5_b_bwlabel(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T c5_c_L[19200],
  real_T *c5_numComponents)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  int64_T c5_i;
  real_T c5_a;
  real_T c5_b_c;
  real_T c5_b_i;
  real_T c5_b_j;
  real_T c5_b_numComponents;
  real_T c5_b_r;
  real_T c5_b_root;
  real_T c5_b_rootj;
  real_T c5_b_thread;
  real_T c5_b_varargin_1;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_i;
  real_T c5_c_j;
  real_T c5_c_varargin_1;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d_a;
  real_T c5_d_i;
  real_T c5_d_j;
  real_T c5_d_x;
  real_T c5_e_i;
  real_T c5_e_x;
  real_T c5_f_i;
  real_T c5_f_x;
  real_T c5_firstLabel;
  real_T c5_h_x;
  real_T c5_j;
  real_T c5_label;
  real_T c5_m_x;
  real_T c5_minval;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_root;
  real_T c5_rootj;
  real_T c5_startC;
  real_T c5_x;
  real_T c5_z;
  int32_T c5_chunksSizeAndLabels[168];
  int32_T c5_b_a;
  int32_T c5_b_q0;
  int32_T c5_b_q1;
  int32_T c5_b_qY;
  int32_T c5_b_z;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_c;
  int32_T c5_c_q0;
  int32_T c5_c_q1;
  int32_T c5_c_qY;
  int32_T c5_c_r;
  int32_T c5_c_y;
  int32_T c5_d_b;
  int32_T c5_d_c;
  int32_T c5_d_q0;
  int32_T c5_d_q1;
  int32_T c5_d_qY;
  int32_T c5_d_r;
  int32_T c5_e_a;
  int32_T c5_e_q0;
  int32_T c5_e_q1;
  int32_T c5_e_qY;
  int32_T c5_exitg1;
  int32_T c5_f_a;
  int32_T c5_f_q0;
  int32_T c5_f_q1;
  int32_T c5_f_qY;
  int32_T c5_g_i;
  int32_T c5_g_q0;
  int32_T c5_g_q1;
  int32_T c5_g_qY;
  int32_T c5_g_x;
  int32_T c5_h_q0;
  int32_T c5_h_q1;
  int32_T c5_h_qY;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_x;
  int32_T c5_j_x;
  int32_T c5_k_x;
  int32_T c5_l_x;
  int32_T c5_q0;
  int32_T c5_q1;
  int32_T c5_qY;
  int32_T c5_r;
  int32_T c5_r_x;
  int32_T c5_stripeFirstLabel;
  int32_T c5_thread;
  int32_T c5_y;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_gb_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  chartInstance->c5_b_P[0] = 0.0;
  for (c5_thread = 0; c5_thread < 8; c5_thread++) {
    c5_b_thread = (real_T)c5_thread;
    c5_b_c = c5_b_thread * 20.0 + 1.0;
    c5_b_varargin_1 = (c5_b_thread + 1.0) * 20.0 + 1.0;
    c5_x = c5_b_varargin_1;
    c5_b_x = c5_x;
    c5_c_x = c5_b_x;
    c5_a = c5_c_x;
    c5_d_x = c5_a;
    c5_e_x = c5_d_x;
    c5_minval = muDoubleScalarMin(c5_e_x, 161.0);
    c5_d1 = muDoubleScalarRound(c5_minval);
    if (c5_d1 < 2.147483648E+9) {
      if (c5_d1 >= -2.147483648E+9) {
        c5_i1 = (int32_T)c5_d1;
      } else {
        c5_i1 = MIN_int32_T;
      }
    } else if (c5_d1 >= 2.147483648E+9) {
      c5_i1 = MAX_int32_T;
    } else {
      c5_i1 = 0;
    }

    c5_chunksSizeAndLabels[(int32_T)c5_b_c - 1] = c5_i1;
    c5_f_x = (c5_b_c - 1.0) * 120.0 / 2.0;
    c5_h_x = c5_f_x;
    c5_b_y = c5_h_x;
    c5_b_y = muDoubleScalarCeil(c5_b_y);
    c5_label = c5_b_y + 1.0;
    c5_firstLabel = c5_label;
    c5_startC = c5_b_c;
    c5_d3 = c5_b_thread * 20.0 + 1.0;
    c5_c_varargin_1 = (c5_b_thread + 1.0) * 20.0;
    c5_m_x = c5_c_varargin_1;
    c5_n_x = c5_m_x;
    c5_o_x = c5_n_x;
    c5_d_a = c5_o_x;
    c5_p_x = c5_d_a;
    c5_q_x = c5_p_x;
    c5_d5 = muDoubleScalarMin(c5_q_x, 160.0);
    c5_i6 = (int32_T)(c5_d5 + (1.0 - c5_d3)) - 1;
    for (c5_d_c = 0; c5_d_c <= c5_i6; c5_d_c++) {
      c5_b_c = c5_d3 + (real_T)c5_d_c;
      for (c5_d_r = 0; c5_d_r < 120; c5_d_r++) {
        c5_b_r = (real_T)c5_d_r + 1.0;
        c5_i10 = (int32_T)c5_b_c;
        if ((c5_i10 < 1) || (c5_i10 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i10, 1, 160, &c5_dd_emlrtBCI, &c5_st);
        }

        if (c5_varargin_1[((int32_T)c5_b_r + 120 * (c5_i10 - 1)) - 1]) {
          if ((c5_b_r > 1.0) && c5_varargin_1[((int32_T)(c5_b_r - 1.0) + 120 *
               ((int32_T)c5_b_c - 1)) - 1]) {
            if ((c5_b_c > c5_startC) && c5_varargin_1[((int32_T)c5_b_r + 120 *
                 ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) -
                1];
              do {
                c5_exitg1 = 0;
                c5_i14 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                  c5_b_c - 1)) - 1] + 1.0);
                if ((c5_i14 < 1) || (c5_i14 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i14, 1, 9601, &c5_hd_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_b_P[c5_i14 - 1] < c5_c_L[((int32_T)c5_b_r
                     + 120 * ((int32_T)c5_b_c - 1)) - 1]) {
                  c5_i18 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                    c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i18 < 1) || (c5_i18 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i18, 1, 9601,
                      &c5_id_emlrtBCI, &c5_st);
                  }

                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    chartInstance->c5_b_P[c5_i18 - 1];
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              if (c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)(c5_b_c - 1.0) - 1))
                  - 1] != c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)
                    c5_b_c - 1)) - 1]) {
                c5_b_rootj = c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)
                  c5_b_c - 1)) - 1];
                do {
                  c5_exitg1 = 0;
                  c5_i24 = (int32_T)(c5_b_rootj + 1.0);
                  if ((c5_i24 < 1) || (c5_i24 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i24, 1, 9601,
                      &c5_kd_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_b_P[c5_i24 - 1] < c5_b_rootj) {
                    c5_i27 = (int32_T)(c5_b_rootj + 1.0);
                    if ((c5_i27 < 1) || (c5_i27 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i27, 1, 9601,
                        &c5_nd_emlrtBCI, &c5_st);
                    }

                    c5_b_rootj = chartInstance->c5_b_P[c5_i27 - 1];
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                if (c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] >
                    c5_b_rootj) {
                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                    c5_b_rootj;
                }

                do {
                  c5_exitg1 = 0;
                  c5_i33 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                    ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                  if ((c5_i33 < 1) || (c5_i33 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i33, 1, 9601,
                      &c5_pd_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_b_P[c5_i33 - 1] < c5_c_L[((int32_T)
                       (c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1)) - 1]) {
                    c5_i34 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                      ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                    if ((c5_i34 < 1) || (c5_i34 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i34, 1, 9601,
                        &c5_rd_emlrtBCI, &c5_st);
                    }

                    c5_c_j = chartInstance->c5_b_P[c5_i34 - 1];
                    c5_i36 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                      ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                    if ((c5_i36 < 1) || (c5_i36 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i36, 1, 9601,
                        &c5_sd_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_b_P[c5_i36 - 1] = c5_c_L[((int32_T)c5_b_r
                      + 120 * ((int32_T)c5_b_c - 1)) - 1];
                    c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1))
                      - 1] = c5_c_j;
                  } else {
                    c5_exitg1 = 1;
                  }
                } while (c5_exitg1 == 0);

                c5_i35 = (int32_T)(c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 *
                  ((int32_T)c5_b_c - 1)) - 1] + 1.0);
                if ((c5_i35 < 1) || (c5_i35 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i35, 1, 9601, &c5_qd_emlrtBCI,
                    &c5_st);
                }

                chartInstance->c5_b_P[c5_i35 - 1] = c5_c_L[((int32_T)c5_b_r +
                  120 * ((int32_T)c5_b_c - 1)) - 1];
              }

              do {
                c5_exitg1 = 0;
                c5_i23 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                  (c5_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c5_i23 < 1) || (c5_i23 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 9601, &c5_jd_emlrtBCI,
                    &c5_st);
                }

                if (chartInstance->c5_b_P[c5_i23 - 1] < c5_c_L[((int32_T)c5_b_r
                     + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
                  c5_i26 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                    (c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i26 < 1) || (c5_i26 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i26, 1, 9601,
                      &c5_md_emlrtBCI, &c5_st);
                  }

                  c5_c_j = chartInstance->c5_b_P[c5_i26 - 1];
                  c5_i30 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                    (c5_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c5_i30 < 1) || (c5_i30 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i30, 1, 9601,
                      &c5_od_emlrtBCI, &c5_st);
                  }

                  chartInstance->c5_b_P[c5_i30 - 1] = c5_c_L[((int32_T)c5_b_r +
                    120 * ((int32_T)c5_b_c - 1)) - 1];
                  c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)(c5_b_c - 1.0) - 1))
                    - 1] = c5_c_j;
                } else {
                  c5_exitg1 = 1;
                }
              } while (c5_exitg1 == 0);

              c5_i29 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)
                (c5_b_c - 1.0) - 1)) - 1] + 1.0);
              if ((c5_i29 < 1) || (c5_i29 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i29, 1, 9601, &c5_ld_emlrtBCI,
                  &c5_st);
              }

              chartInstance->c5_b_P[c5_i29 - 1] = c5_c_L[((int32_T)c5_b_r + 120 *
                ((int32_T)c5_b_c - 1)) - 1];
            } else {
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
                c5_c_L[((int32_T)(c5_b_r - 1.0) + 120 * ((int32_T)c5_b_c - 1)) -
                1];
            }
          } else if ((c5_b_c > c5_startC) && c5_varargin_1[((int32_T)c5_b_r +
                      120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1]) {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)(c5_b_c - 1.0) - 1)) - 1];
          } else {
            c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
              c5_label;
            c5_i12 = (int32_T)(c5_label + 1.0);
            if ((c5_i12 < 1) || (c5_i12 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i12, 1, 9601, &c5_wc_emlrtBCI,
                &c5_st);
            }

            chartInstance->c5_b_P[c5_i12 - 1] = c5_label;
            c5_label++;
          }
        } else {
          c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] = 0.0;
        }
      }
    }

    c5_d7 = muDoubleScalarRound(c5_label - c5_firstLabel);
    if (c5_d7 < 2.147483648E+9) {
      if (c5_d7 >= -2.147483648E+9) {
        c5_i8 = (int32_T)c5_d7;
      } else {
        c5_i8 = MIN_int32_T;
      }
    } else if (c5_d7 >= 2.147483648E+9) {
      c5_i8 = MAX_int32_T;
    } else {
      c5_i8 = 0;
    }

    c5_chunksSizeAndLabels[(int32_T)(c5_startC + 1.0) - 1] = c5_i8;
  }

  c5_c = c5_chunksSizeAndLabels[0];
  while ((real_T)c5_c <= 160.0) {
    for (c5_r = 0; c5_r < 120; c5_r++) {
      c5_b_r = (real_T)c5_r + 1.0;
      if ((c5_c < 1) || (c5_c > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_c, 1, 160, &c5_yc_emlrtBCI, &c5_st);
      }

      c5_d = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
      if (c5_d != 0.0) {
        c5_b_q0 = c5_c;
        c5_b_q1 = 1;
        if ((c5_b_q1 < 0) && (c5_b_q0 > c5_b_q1 + MAX_int32_T)) {
          c5_b_qY = MAX_int32_T;
        } else if ((c5_b_q1 > 0) && (c5_b_q0 < c5_b_q1 + MIN_int32_T)) {
          c5_b_qY = MIN_int32_T;
        } else {
          c5_b_qY = c5_b_q0 - c5_b_q1;
        }

        c5_i3 = c5_b_qY;
        if ((c5_i3 < 1) || (c5_i3 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 160, &c5_ad_emlrtBCI, &c5_st);
        }

        c5_d2 = c5_c_L[((int32_T)c5_b_r + 120 * (c5_i3 - 1)) - 1];
        if (c5_d2 != 0.0) {
          c5_b_st.site = &c5_fd_emlrtRSI;
          c5_c_q0 = c5_c;
          c5_c_q1 = 1;
          if ((c5_c_q1 < 0) && (c5_c_q0 > c5_c_q1 + MAX_int32_T)) {
            c5_c_qY = MAX_int32_T;
          } else if ((c5_c_q1 > 0) && (c5_c_q0 < c5_c_q1 + MIN_int32_T)) {
            c5_c_qY = MIN_int32_T;
          } else {
            c5_c_qY = c5_c_q0 - c5_c_q1;
          }

          c5_i4 = c5_c_qY;
          if ((c5_i4 < 1) || (c5_i4 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 160, &c5_bd_emlrtBCI,
              &c5_b_st);
          }

          c5_b_i = c5_c_L[((int32_T)c5_b_r + 120 * (c5_i4 - 1)) - 1];
          c5_j = c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1];
          c5_c_st.site = &c5_ab_emlrtRSI;
          c5_c_i = c5_b_i;
          c5_d6 = c5_c_i;
          do {
            c5_exitg1 = 0;
            c5_i7 = (int32_T)(c5_d6 + 1.0);
            if ((c5_i7 < 1) || (c5_i7 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i7, 1, 9601, &c5_hb_emlrtBCI,
                &c5_c_st);
            }

            if (chartInstance->c5_b_P[c5_i7 - 1] < c5_d6) {
              c5_i9 = (int32_T)(c5_d6 + 1.0);
              if ((c5_i9 < 1) || (c5_i9 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i9, 1, 9601, &c5_ib_emlrtBCI,
                  &c5_c_st);
              }

              c5_d6 = chartInstance->c5_b_P[c5_i9 - 1];
            } else {
              c5_exitg1 = 1;
            }
          } while (c5_exitg1 == 0);

          if (c5_b_i != c5_j) {
            c5_c_st.site = &c5_bb_emlrtRSI;
            c5_d_i = c5_j;
            c5_rootj = c5_d_i;
            do {
              c5_exitg1 = 0;
              c5_i13 = (int32_T)(c5_rootj + 1.0);
              if ((c5_i13 < 1) || (c5_i13 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i13, 1, 9601, &c5_hb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_b_P[c5_i13 - 1] < c5_rootj) {
                c5_i17 = (int32_T)(c5_rootj + 1.0);
                if ((c5_i17 < 1) || (c5_i17 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i17, 1, 9601, &c5_ib_emlrtBCI,
                    &c5_c_st);
                }

                c5_rootj = chartInstance->c5_b_P[c5_i17 - 1];
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            if (c5_d6 > c5_rootj) {
              c5_d6 = c5_rootj;
            }

            c5_c_st.site = &c5_cb_emlrtRSI;
            c5_f_i = c5_j;
            c5_b_root = c5_d6;
            do {
              c5_exitg1 = 0;
              c5_i25 = (int32_T)(c5_f_i + 1.0);
              if ((c5_i25 < 1) || (c5_i25 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i25, 1, 9601, &c5_kb_emlrtBCI,
                  &c5_c_st);
              }

              if (chartInstance->c5_b_P[c5_i25 - 1] < c5_f_i) {
                c5_i28 = (int32_T)(c5_f_i + 1.0);
                if ((c5_i28 < 1) || (c5_i28 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i28, 1, 9601, &c5_lb_emlrtBCI,
                    &c5_c_st);
                }

                c5_d_j = chartInstance->c5_b_P[c5_i28 - 1];
                c5_i32 = (int32_T)(c5_f_i + 1.0);
                if ((c5_i32 < 1) || (c5_i32 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i32, 1, 9601, &c5_v_emlrtBCI,
                    &c5_c_st);
                }

                chartInstance->c5_b_P[c5_i32 - 1] = c5_b_root;
                c5_f_i = c5_d_j;
              } else {
                c5_exitg1 = 1;
              }
            } while (c5_exitg1 == 0);

            c5_i31 = (int32_T)(c5_f_i + 1.0);
            if ((c5_i31 < 1) || (c5_i31 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i31, 1, 9601, &c5_w_emlrtBCI,
                &c5_c_st);
            }

            chartInstance->c5_b_P[c5_i31 - 1] = c5_b_root;
          }

          c5_c_st.site = &c5_db_emlrtRSI;
          c5_e_i = c5_b_i;
          c5_root = c5_d6;
          do {
            c5_exitg1 = 0;
            c5_i15 = (int32_T)(c5_e_i + 1.0);
            if ((c5_i15 < 1) || (c5_i15 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c5_i15, 1, 9601, &c5_kb_emlrtBCI,
                &c5_c_st);
            }

            if (chartInstance->c5_b_P[c5_i15 - 1] < c5_e_i) {
              c5_i19 = (int32_T)(c5_e_i + 1.0);
              if ((c5_i19 < 1) || (c5_i19 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i19, 1, 9601, &c5_lb_emlrtBCI,
                  &c5_c_st);
              }

              c5_b_j = chartInstance->c5_b_P[c5_i19 - 1];
              c5_i21 = (int32_T)(c5_e_i + 1.0);
              if ((c5_i21 < 1) || (c5_i21 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 9601, &c5_v_emlrtBCI,
                  &c5_c_st);
              }

              chartInstance->c5_b_P[c5_i21 - 1] = c5_root;
              c5_e_i = c5_b_j;
            } else {
              c5_exitg1 = 1;
            }
          } while (c5_exitg1 == 0);

          c5_i20 = (int32_T)(c5_e_i + 1.0);
          if ((c5_i20 < 1) || (c5_i20 > 9601)) {
            emlrtDynamicBoundsCheckR2012b(c5_i20, 1, 9601, &c5_w_emlrtBCI,
              &c5_c_st);
          }

          chartInstance->c5_b_P[c5_i20 - 1] = c5_root;
          c5_c_L[((int32_T)c5_b_r + 120 * (c5_c - 1)) - 1] = c5_d6;
        }
      }
    }

    if ((c5_c < 1) || (c5_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_c, 1, 168, &c5_xc_emlrtBCI, &c5_st);
    }

    c5_c = c5_chunksSizeAndLabels[c5_c - 1];
  }

  c5_b_numComponents = 1.0;
  c5_c = 1;
  while ((real_T)c5_c <= 160.0) {
    c5_q0 = c5_c;
    c5_q1 = 1;
    if ((c5_q1 < 0) && (c5_q0 > c5_q1 + MAX_int32_T)) {
      c5_qY = MAX_int32_T;
    } else if ((c5_q1 > 0) && (c5_q0 < c5_q1 + MIN_int32_T)) {
      c5_qY = MIN_int32_T;
    } else {
      c5_qY = c5_q0 - c5_q1;
    }

    c5_b_a = c5_qY;
    c5_i = (int64_T)c5_b_a * 120LL;
    if (c5_i > 2147483647LL) {
      c5_i = 2147483647LL;
    } else if (c5_i < -2147483648LL) {
      c5_i = -2147483648LL;
    }

    c5_y = (int32_T)c5_i;
    c5_g_x = c5_y;
    c5_i_x = c5_g_x;
    c5_j_x = c5_i_x;
    c5_k_x = c5_j_x;
    c5_c_a = c5_k_x;
    c5_l_x = c5_c_a;
    c5_z = (real_T)c5_l_x / 2.0;
    c5_d4 = muDoubleScalarRound(c5_z);
    if (c5_d4 < 2.147483648E+9) {
      if (c5_d4 >= -2.147483648E+9) {
        c5_i5 = (int32_T)c5_d4;
      } else {
        c5_i5 = MIN_int32_T;
      }
    } else if (c5_d4 >= 2.147483648E+9) {
      c5_i5 = MAX_int32_T;
    } else {
      c5_i5 = 0;
    }

    c5_b_z = c5_i5;
    c5_r_x = c5_b_z;
    c5_c_y = c5_r_x;
    c5_d_q0 = c5_c_y;
    c5_d_q1 = 1;
    if ((c5_d_q1 < 0) && (c5_d_q0 < MIN_int32_T - c5_d_q1)) {
      c5_d_qY = MIN_int32_T;
    } else if ((c5_d_q1 > 0) && (c5_d_q0 > MAX_int32_T - c5_d_q1)) {
      c5_d_qY = MAX_int32_T;
    } else {
      c5_d_qY = c5_d_q0 + c5_d_q1;
    }

    c5_stripeFirstLabel = c5_d_qY;
    c5_e_q0 = c5_stripeFirstLabel;
    c5_e_q1 = 1;
    if ((c5_e_q1 < 0) && (c5_e_q0 < MIN_int32_T - c5_e_q1)) {
      c5_e_qY = MIN_int32_T;
    } else if ((c5_e_q1 > 0) && (c5_e_q0 > MAX_int32_T - c5_e_q1)) {
      c5_e_qY = MAX_int32_T;
    } else {
      c5_e_qY = c5_e_q0 + c5_e_q1;
    }

    c5_i11 = c5_e_qY;
    c5_f_q0 = c5_c;
    c5_f_q1 = 1;
    if ((c5_f_q1 < 0) && (c5_f_q0 < MIN_int32_T - c5_f_q1)) {
      c5_f_qY = MIN_int32_T;
    } else if ((c5_f_q1 > 0) && (c5_f_q0 > MAX_int32_T - c5_f_q1)) {
      c5_f_qY = MAX_int32_T;
    } else {
      c5_f_qY = c5_f_q0 + c5_f_q1;
    }

    c5_i16 = c5_f_qY;
    if ((c5_i16 < 1) || (c5_i16 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_i16, 1, 168, &c5_cd_emlrtBCI, &c5_st);
    }

    c5_g_q0 = c5_stripeFirstLabel;
    c5_g_q1 = c5_chunksSizeAndLabels[c5_i16 - 1];
    if ((c5_g_q0 < 0) && (c5_g_q1 < MIN_int32_T - c5_g_q0)) {
      c5_g_qY = MIN_int32_T;
    } else if ((c5_g_q0 > 0) && (c5_g_q1 > MAX_int32_T - c5_g_q0)) {
      c5_g_qY = MAX_int32_T;
    } else {
      c5_g_qY = c5_g_q0 + c5_g_q1;
    }

    c5_i22 = c5_g_qY;
    c5_b_st.site = &c5_gd_emlrtRSI;
    c5_e_a = c5_i11;
    c5_c_b = c5_i22;
    c5_f_a = c5_e_a;
    c5_d_b = c5_c_b;
    if (c5_f_a > c5_d_b) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_g_i = c5_i11; c5_g_i <= c5_i22; c5_g_i++) {
      if ((c5_g_i < 1) || (c5_g_i > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c5_g_i, 1, 9601, &c5_fd_emlrtBCI, &c5_st);
      }

      c5_h_q0 = c5_g_i;
      c5_h_q1 = 1;
      if ((c5_h_q1 < 0) && (c5_h_q0 > c5_h_q1 + MAX_int32_T)) {
        c5_h_qY = MAX_int32_T;
      } else if ((c5_h_q1 > 0) && (c5_h_q0 < c5_h_q1 + MIN_int32_T)) {
        c5_h_qY = MIN_int32_T;
      } else {
        c5_h_qY = c5_h_q0 - c5_h_q1;
      }

      if (chartInstance->c5_b_P[c5_g_i - 1] < (real_T)c5_h_qY) {
        c5_i37 = (int32_T)(chartInstance->c5_b_P[c5_g_i - 1] + 1.0);
        if ((c5_i37 < 1) || (c5_i37 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c5_i37, 1, 9601, &c5_gd_emlrtBCI, &c5_st);
        }

        chartInstance->c5_b_P[c5_g_i - 1] = chartInstance->c5_b_P[c5_i37 - 1];
      } else {
        chartInstance->c5_b_P[c5_g_i - 1] = c5_b_numComponents;
        c5_b_numComponents++;
      }
    }

    if ((c5_c < 1) || (c5_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c5_c, 1, 168, &c5_ed_emlrtBCI, &c5_st);
    }

    c5_c = c5_chunksSizeAndLabels[c5_c - 1];
  }

  c5_b_numComponents--;
  for (c5_c_c = 0; c5_c_c < 160; c5_c_c++) {
    c5_b_c = (real_T)c5_c_c + 1.0;
    for (c5_c_r = 0; c5_c_r < 120; c5_c_r++) {
      c5_b_r = (real_T)c5_c_r + 1.0;
      c5_i2 = (int32_T)(c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) -
                        1] + 1.0);
      if ((c5_i2 < 1) || (c5_i2 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c5_i2, 1, 9601, &c5_db_emlrtBCI, &c5_st);
      }

      c5_c_L[((int32_T)c5_b_r + 120 * ((int32_T)c5_b_c - 1)) - 1] =
        chartInstance->c5_b_P[c5_i2 - 1];
    }
  }

  *c5_numComponents = c5_b_numComponents;
}

static void c5_BoundaryFinderObjectHoles_findBoundaries
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_images_internal_coder_BoundaryFinderObjectHoles *c5_obj, real_T
   c5_cutoffL, real_T c5_holesN, c5_coder_array_cell_wrap_0 *c5_B)
{
  static int32_T c5_ndl4c[8] = { 1, 2, 3, 0, 0, 0, 0, 0 };

  static int32_T c5_ndl8c[8] = { 1, 2, 3, 4, 5, 6, 7, 0 };

  static int32_T c5_nsdl4c[8] = { 3, 0, 1, 2, 0, 0, 0, 0 };

  static int32_T c5_nsdl8c[8] = { 7, 7, 1, 1, 3, 3, 5, 5 };

  c5_coder_array_boolean_T c5_regionHasBeenTraced;
  c5_coder_array_cell_wrap_0 c5_r;
  c5_coder_array_int32_T c5_b_scratch;
  c5_coder_array_int32_T c5_scratch;
  c5_coder_array_real_T_2D c5_boundary;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_b_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_c_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_d_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_e_obj;
  c5_images_internal_coder_BoundaryFinderObjectHoles *c5_f_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_b_conn;
  real_T c5_conn;
  real_T c5_numRegions;
  real_T c5_previousLabel;
  int32_T c5_iv[2];
  int32_T c5_M;
  int32_T c5_a;
  int32_T c5_b_M;
  int32_T c5_b_N;
  int32_T c5_b_a;
  int32_T c5_b_currentPixel;
  int32_T c5_b_direction;
  int32_T c5_b_idx;
  int32_T c5_b_initDepartureDir;
  int32_T c5_b_k;
  int32_T c5_b_label;
  int32_T c5_b_loop_ub;
  int32_T c5_b_neighbor;
  int32_T c5_b_nextSearchDir;
  int32_T c5_b_numPixels;
  int32_T c5_b_r;
  int32_T c5_b_scratchLength;
  int32_T c5_c;
  int32_T c5_c_M;
  int32_T c5_c_b;
  int32_T c5_c_label;
  int32_T c5_c_loop_ub;
  int32_T c5_c_scratchLength;
  int32_T c5_currentPixel;
  int32_T c5_d_b;
  int32_T c5_d_loop_ub;
  int32_T c5_d_scratchLength;
  int32_T c5_direction;
  int32_T c5_e_b;
  int32_T c5_e_loop_ub;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_idx;
  int32_T c5_initDepartureDir;
  int32_T c5_k;
  int32_T c5_label;
  int32_T c5_linearIdx;
  int32_T c5_loop_ub;
  int32_T c5_neighbor;
  int32_T c5_nextSearchDir;
  int32_T c5_numPixels;
  int32_T c5_scratchLength;
  boolean_T c5_b_foundNextPixel;
  boolean_T c5_b_isDone;
  boolean_T c5_b_overflow;
  boolean_T c5_exitg1;
  boolean_T c5_foundNextPixel;
  boolean_T c5_guard1;
  boolean_T c5_isDone;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_M = c5_obj->numRows;
  c5_b_N = c5_obj->numCols - 1;
  c5_numRegions = c5_cutoffL + c5_holesN;
  if (c5_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c5_numRegions)) {
    emlrtIntegerCheckR2012b(c5_numRegions, &c5_m_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_iv[0] = (int32_T)c5_numRegions;
  c5_array_cell_wrap_0_Constructor1(chartInstance, &c5_r);
  c5_array_cell_wrap_0_SetSize(chartInstance, c5_sp, &c5_r, &c5_mb_emlrtRTEI,
    c5_iv[0]);
  c5_st.site = &c5_vj_emlrtRSI;
  c5_array_cell_wrap_0_SetSize(chartInstance, &c5_st, c5_B, &c5_nb_emlrtRTEI,
    c5_r.size[0]);
  c5_array_cell_wrap_0_Destructor1(chartInstance, &c5_r);
  c5_array_boolean_T_Constructor(chartInstance, &c5_regionHasBeenTraced);
  if (c5_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c5_numRegions)) {
    emlrtIntegerCheckR2012b(c5_numRegions, &c5_n_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_bk_emlrtRSI;
  c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_regionHasBeenTraced,
    &c5_ob_emlrtRTEI, (int32_T)c5_numRegions);
  if (c5_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c5_numRegions)) {
    emlrtIntegerCheckR2012b(c5_numRegions, &c5_n_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_loop_ub = (int32_T)c5_numRegions - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_regionHasBeenTraced.vector.data[c5_i] = false;
  }

  if (c5_numRegions > 0.0) {
    c5_st.site = &c5_ld_emlrtRSI;
    c5_b_obj = c5_obj;
    c5_b_obj->startMarker = -2.0;
    c5_b_obj->boundaryMarker = -3.0;
    c5_b_M = c5_b_obj->numRows;
    if (c5_b_obj->conn == 8.0) {
      c5_b_obj->neighborOffsets[0] = -1;
      c5_b_obj->neighborOffsets[1] = c5_b_M - 1;
      c5_b_obj->neighborOffsets[2] = c5_b_M;
      c5_b_obj->neighborOffsets[3] = c5_b_M + 1;
      c5_b_obj->neighborOffsets[4] = 1;
      c5_b_obj->neighborOffsets[5] = 1 - c5_b_M;
      c5_b_obj->neighborOffsets[6] = -c5_b_M;
      c5_b_obj->neighborOffsets[7] = -c5_b_M - 1;
      c5_b_obj->validationOffsets[0] = -1;
      c5_b_obj->validationOffsets[1] = c5_b_M;
      c5_b_obj->validationOffsets[2] = 1;
      c5_b_obj->validationOffsets[3] = -c5_b_M;
      c5_b_obj->validationOffsets[4] = 0;
      c5_b_obj->validationOffsets[5] = 0;
      c5_b_obj->validationOffsets[6] = 0;
      c5_b_obj->validationOffsets[7] = 0;
    } else {
      c5_b_obj->neighborOffsets[0] = -1;
      c5_b_obj->neighborOffsets[1] = c5_b_M;
      c5_b_obj->neighborOffsets[2] = 1;
      c5_b_obj->neighborOffsets[3] = -c5_b_M;
      c5_b_obj->neighborOffsets[4] = 0;
      c5_b_obj->neighborOffsets[5] = 0;
      c5_b_obj->neighborOffsets[6] = 0;
      c5_b_obj->neighborOffsets[7] = 0;
      c5_b_obj->validationOffsets[0] = -1;
      c5_b_obj->validationOffsets[1] = c5_b_M - 1;
      c5_b_obj->validationOffsets[2] = c5_b_M;
      c5_b_obj->validationOffsets[3] = c5_b_M + 1;
      c5_b_obj->validationOffsets[4] = 1;
      c5_b_obj->validationOffsets[5] = 1 - c5_b_M;
      c5_b_obj->validationOffsets[6] = -c5_b_M;
      c5_b_obj->validationOffsets[7] = -c5_b_M - 1;
    }

    if (c5_b_obj->conn == 8.0) {
      for (c5_i2 = 0; c5_i2 < 8; c5_i2++) {
        c5_b_obj->nextDirectionLut[c5_i2] = c5_ndl8c[c5_i2];
      }

      for (c5_i4 = 0; c5_i4 < 8; c5_i4++) {
        c5_b_obj->nextSearchDirectionLut[c5_i4] = c5_nsdl8c[c5_i4];
      }
    } else {
      for (c5_i1 = 0; c5_i1 < 8; c5_i1++) {
        c5_b_obj->nextDirectionLut[c5_i1] = c5_ndl4c[c5_i1];
      }

      for (c5_i3 = 0; c5_i3 < 8; c5_i3++) {
        c5_b_obj->nextSearchDirectionLut[c5_i3] = c5_nsdl4c[c5_i3];
      }
    }

    c5_st.site = &c5_md_emlrtRSI;
    c5_c_obj = c5_obj;
    c5_c_obj->nextSearchDir = 1;
    c5_st.site = &c5_nd_emlrtRSI;
    c5_d_obj = c5_obj;
    c5_d_obj->startMarkerHoles = -2.0;
    c5_d_obj->boundaryMarkerHoles = -3.0;
    c5_c_M = c5_d_obj->numRows;
    if (c5_d_obj->ConnectivityHoles == 8.0) {
      c5_d_obj->neighborOffsetsHoles[0] = -1;
      c5_d_obj->neighborOffsetsHoles[1] = c5_c_M - 1;
      c5_d_obj->neighborOffsetsHoles[2] = c5_c_M;
      c5_d_obj->neighborOffsetsHoles[3] = c5_c_M + 1;
      c5_d_obj->neighborOffsetsHoles[4] = 1;
      c5_d_obj->neighborOffsetsHoles[5] = 1 - c5_c_M;
      c5_d_obj->neighborOffsetsHoles[6] = -c5_c_M;
      c5_d_obj->neighborOffsetsHoles[7] = -c5_c_M - 1;
      c5_d_obj->validationOffsetsHoles[0] = -1;
      c5_d_obj->validationOffsetsHoles[1] = c5_c_M;
      c5_d_obj->validationOffsetsHoles[2] = 1;
      c5_d_obj->validationOffsetsHoles[3] = -c5_c_M;
      c5_d_obj->validationOffsetsHoles[4] = 0;
      c5_d_obj->validationOffsetsHoles[5] = 0;
      c5_d_obj->validationOffsetsHoles[6] = 0;
      c5_d_obj->validationOffsetsHoles[7] = 0;
    } else {
      c5_d_obj->neighborOffsetsHoles[0] = -1;
      c5_d_obj->neighborOffsetsHoles[1] = c5_c_M;
      c5_d_obj->neighborOffsetsHoles[2] = 1;
      c5_d_obj->neighborOffsetsHoles[3] = -c5_c_M;
      c5_d_obj->neighborOffsetsHoles[4] = 0;
      c5_d_obj->neighborOffsetsHoles[5] = 0;
      c5_d_obj->neighborOffsetsHoles[6] = 0;
      c5_d_obj->neighborOffsetsHoles[7] = 0;
      c5_d_obj->validationOffsetsHoles[0] = -1;
      c5_d_obj->validationOffsetsHoles[1] = c5_c_M - 1;
      c5_d_obj->validationOffsetsHoles[2] = c5_c_M;
      c5_d_obj->validationOffsetsHoles[3] = c5_c_M + 1;
      c5_d_obj->validationOffsetsHoles[4] = 1;
      c5_d_obj->validationOffsetsHoles[5] = 1 - c5_c_M;
      c5_d_obj->validationOffsetsHoles[6] = -c5_c_M;
      c5_d_obj->validationOffsetsHoles[7] = -c5_c_M - 1;
    }

    if (c5_d_obj->ConnectivityHoles == 8.0) {
      for (c5_i6 = 0; c5_i6 < 8; c5_i6++) {
        c5_d_obj->nextDirectionLutHoles[c5_i6] = c5_ndl8c[c5_i6];
      }

      for (c5_i8 = 0; c5_i8 < 8; c5_i8++) {
        c5_d_obj->nextSearchDirectionLutHoles[c5_i8] = c5_nsdl8c[c5_i8];
      }
    } else {
      for (c5_i5 = 0; c5_i5 < 8; c5_i5++) {
        c5_d_obj->nextDirectionLutHoles[c5_i5] = c5_ndl4c[c5_i5];
      }

      for (c5_i7 = 0; c5_i7 < 8; c5_i7++) {
        c5_d_obj->nextSearchDirectionLutHoles[c5_i7] = c5_nsdl4c[c5_i7];
      }
    }

    c5_i9 = c5_b_N;
    c5_st.site = &c5_od_emlrtRSI;
    c5_c_b = c5_i9;
    c5_d_b = c5_c_b;
    if (c5_d_b < 2) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    c5_array_real_T_2D_Constructor(chartInstance, &c5_boundary);
    c5_array_int32_T_Constructor(chartInstance, &c5_scratch);
    c5_array_int32_T_Constructor(chartInstance, &c5_b_scratch);
    for (c5_c = 2; c5_c <= c5_i9; c5_c++) {
      c5_i10 = c5_M - 1;
      c5_st.site = &c5_pd_emlrtRSI;
      c5_e_b = c5_i10;
      c5_f_b = c5_e_b;
      if (c5_f_b < 2) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_f_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_b_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      for (c5_b_r = 2; c5_b_r <= c5_i10; c5_b_r++) {
        c5_linearIdx = c5_M * (c5_c - 1) + c5_b_r;
        if ((c5_linearIdx < 1) || (c5_linearIdx > 19764)) {
          emlrtDynamicBoundsCheckR2012b(c5_linearIdx, 1, 19764, &c5_vd_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_label = (int32_T)c5_obj->paddedLabelMatrix[c5_linearIdx - 1];
        c5_i11 = c5_linearIdx - 1;
        if ((c5_i11 < 1) || (c5_i11 > 19764)) {
          emlrtDynamicBoundsCheckR2012b(c5_i11, 1, 19764, &c5_wd_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_previousLabel = c5_obj->paddedLabelMatrix[c5_i11 - 1];
        if ((c5_label > 0) && ((real_T)c5_label <= c5_cutoffL) &&
            ((c5_previousLabel == 0.0) || (c5_previousLabel > c5_cutoffL))) {
          c5_i12 = c5_regionHasBeenTraced.size[0];
          if ((c5_label < 1) || (c5_label > c5_i12)) {
            emlrtDynamicBoundsCheckR2012b(c5_label, 1, c5_i12, &c5_xd_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          if (!c5_regionHasBeenTraced.vector.data[c5_label - 1]) {
            c5_st.site = &c5_qd_emlrtRSI;
            c5_e_obj = c5_obj;
            c5_idx = c5_linearIdx;
            c5_conn = c5_obj->conn;
            c5_b_label = c5_label;
            c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_scratch,
              &c5_pb_emlrtRTEI, 200);
            c5_scratchLength = 200;
            c5_scratch.vector.data[0] = c5_idx;
            c5_e_obj->paddedLabelMatrix[c5_idx - 1] = c5_e_obj->startMarker;
            c5_isDone = false;
            c5_numPixels = 2;
            c5_currentPixel = c5_idx - 1;
            c5_nextSearchDir = c5_e_obj->nextSearchDir;
            c5_initDepartureDir = -1;
            while (!c5_isDone) {
              c5_direction = c5_nextSearchDir;
              c5_foundNextPixel = false;
              c5_i15 = (int32_T)c5_conn;
              emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_conn, mxDOUBLE_CLASS,
                c5_i15, &c5_kg_emlrtRTEI, &c5_st);
              c5_k = 0;
              c5_guard1 = false;
              c5_exitg1 = false;
              while ((!c5_exitg1) && (c5_k <= c5_i15 - 1)) {
                c5_a = c5_currentPixel + 1;
                c5_i25 = c5_direction + 1;
                if ((c5_i25 < 1) || (c5_i25 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i25, 1, 8, &c5_ae_emlrtBCI,
                    &c5_st);
                }

                c5_g_b = c5_e_obj->neighborOffsets[c5_i25 - 1];
                c5_neighbor = c5_a + c5_g_b;
                if ((c5_neighbor < 1) || (c5_neighbor > 19764)) {
                  emlrtDynamicBoundsCheckR2012b(c5_neighbor, 1, 19764,
                    &c5_be_emlrtBCI, &c5_st);
                }

                if ((c5_e_obj->paddedLabelMatrix[c5_neighbor - 1] == (real_T)
                     c5_b_label) || (c5_e_obj->paddedLabelMatrix[c5_neighbor - 1]
                                     == c5_e_obj->startMarker)) {
                  if ((c5_e_obj->paddedLabelMatrix[c5_currentPixel] ==
                       c5_e_obj->startMarker) && (c5_initDepartureDir == -1)) {
                    c5_initDepartureDir = c5_direction;
                    c5_guard1 = true;
                  } else if ((c5_e_obj->paddedLabelMatrix[c5_currentPixel] ==
                              c5_e_obj->startMarker) && (c5_initDepartureDir ==
                              c5_direction)) {
                    c5_isDone = true;
                    c5_foundNextPixel = true;
                    c5_e_obj->paddedLabelMatrix[c5_currentPixel] = (real_T)
                      c5_b_label;
                  } else {
                    c5_guard1 = true;
                  }

                  c5_exitg1 = true;
                } else {
                  c5_i36 = c5_direction + 1;
                  if ((c5_i36 < 1) || (c5_i36 > 8)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i36, 1, 8, &c5_ee_emlrtBCI,
                      &c5_st);
                  }

                  c5_direction = c5_e_obj->nextDirectionLut[c5_i36 - 1];
                  c5_k++;
                  c5_guard1 = false;
                }
              }

              if (c5_guard1) {
                c5_i24 = c5_direction + 1;
                if ((c5_i24 < 1) || (c5_i24 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i24, 1, 8, &c5_he_emlrtBCI,
                    &c5_st);
                }

                c5_nextSearchDir = c5_e_obj->nextSearchDirectionLut[c5_i24 - 1];
                c5_foundNextPixel = true;
                if (c5_scratchLength <= c5_numPixels) {
                  c5_b_st.site = &c5_sd_emlrtRSI;
                  c5_expandScratchSpace(chartInstance, &c5_b_st, &c5_scratch,
                                        c5_scratchLength, &c5_b_scratch,
                                        &c5_c_scratchLength);
                  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_scratch,
                    &c5_sb_emlrtRTEI, c5_b_scratch.size[0]);
                  c5_b_loop_ub = c5_b_scratch.size[0] - 1;
                  for (c5_i41 = 0; c5_i41 <= c5_b_loop_ub; c5_i41++) {
                    c5_scratch.vector.data[c5_i41] =
                      c5_b_scratch.vector.data[c5_i41];
                  }

                  c5_scratchLength = c5_c_scratchLength;
                }

                c5_i34 = c5_scratch.size[0];
                if ((c5_numPixels < 1) || (c5_numPixels > c5_i34)) {
                  emlrtDynamicBoundsCheckR2012b(c5_numPixels, 1, c5_i34,
                    &c5_je_emlrtBCI, &c5_st);
                }

                c5_scratch.vector.data[c5_numPixels - 1] = c5_neighbor;
                c5_numPixels++;
                if (c5_numPixels - 1 == MAX_int32_T) {
                  c5_isDone = true;
                } else {
                  c5_currentPixel = c5_neighbor - 1;
                }
              }

              if (!c5_foundNextPixel) {
                c5_numPixels = 3;
                c5_scratch.vector.data[1] = c5_scratch.vector.data[0];
                c5_isDone = true;
              }
            }

            c5_b_st.site = &c5_td_emlrtRSI;
            c5_BoundaryFinder_copyCoordsToBuf(chartInstance, &c5_b_st, c5_e_obj,
              c5_numPixels - 1, &c5_scratch, &c5_boundary);
            c5_i14 = c5_B->size[0] - 1;
            c5_i16 = c5_label - 1;
            if ((c5_i16 < 0) || (c5_i16 > c5_i14)) {
              emlrtDynamicBoundsCheckR2012b(c5_i16, 0, c5_i14, &c5_td_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i20 = c5_i16;
            c5_st.site = &c5_uj_emlrtRSI;
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_B->
              vector.data[c5_i20].f1, &c5_qb_emlrtRTEI, c5_boundary.size[0],
              c5_B->vector.data[c5_i20].f1.size[1]);
            c5_i22 = c5_B->size[0] - 1;
            c5_i23 = c5_label - 1;
            if ((c5_i23 < 0) || (c5_i23 > c5_i22)) {
              emlrtDynamicBoundsCheckR2012b(c5_i23, 0, c5_i22, &c5_td_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i30 = c5_i23;
            c5_st.site = &c5_uj_emlrtRSI;
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_B->
              vector.data[c5_i30].f1, &c5_qb_emlrtRTEI, c5_B->vector.data[c5_i30]
              .f1.size[0], 2);
            c5_i32 = c5_B->size[0] - 1;
            c5_i33 = c5_label - 1;
            if ((c5_i33 < 0) || (c5_i33 > c5_i32)) {
              emlrtDynamicBoundsCheckR2012b(c5_i33, 0, c5_i32, &c5_td_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i40 = c5_B->size[0] - 1;
            c5_i42 = c5_label - 1;
            if ((c5_i42 < 0) || (c5_i42 > c5_i40)) {
              emlrtDynamicBoundsCheckR2012b(c5_i42, 0, c5_i40, &c5_td_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_d_loop_ub = (c5_boundary.size[0] << 1) - 1;
            for (c5_i46 = 0; c5_i46 <= c5_d_loop_ub; c5_i46++) {
              c5_i49 = c5_B->size[0] - 1;
              c5_i50 = c5_label - 1;
              if ((c5_i50 < 0) || (c5_i50 > c5_i49)) {
                emlrtDynamicBoundsCheckR2012b(c5_i50, 0, c5_i49, &c5_ke_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_B->vector.data[c5_i50].f1.vector.data[c5_i46] =
                c5_boundary.vector.data[c5_i46];
            }

            c5_i48 = c5_regionHasBeenTraced.size[0];
            if ((c5_label < 1) || (c5_label > c5_i48)) {
              emlrtDynamicBoundsCheckR2012b(c5_label, 1, c5_i48, &c5_ce_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_regionHasBeenTraced.vector.data[c5_label - 1] = true;
          }
        }

        if (((real_T)c5_label > c5_cutoffL) && (c5_previousLabel > 0.0) &&
            (c5_previousLabel <= c5_cutoffL)) {
          c5_i13 = c5_regionHasBeenTraced.size[0];
          if ((c5_label < 1) || (c5_label > c5_i13)) {
            emlrtDynamicBoundsCheckR2012b(c5_label, 1, c5_i13, &c5_yd_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          if (!c5_regionHasBeenTraced.vector.data[c5_label - 1]) {
            c5_st.site = &c5_rd_emlrtRSI;
            c5_f_obj = c5_obj;
            c5_b_idx = c5_linearIdx;
            c5_b_conn = c5_obj->ConnectivityHoles;
            c5_c_label = c5_label;
            c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_scratch,
              &c5_pb_emlrtRTEI, 200);
            c5_b_scratchLength = 200;
            c5_scratch.vector.data[0] = c5_b_idx;
            c5_f_obj->paddedLabelMatrix[c5_b_idx - 1] = c5_f_obj->startMarker;
            c5_b_isDone = false;
            c5_b_numPixels = 2;
            c5_b_currentPixel = c5_b_idx - 1;
            c5_b_nextSearchDir = c5_f_obj->nextSearchDir;
            c5_b_initDepartureDir = -1;
            while (!c5_b_isDone) {
              c5_b_direction = c5_b_nextSearchDir;
              c5_b_foundNextPixel = false;
              c5_i18 = (int32_T)c5_b_conn;
              emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_b_conn, mxDOUBLE_CLASS,
                c5_i18, &c5_kg_emlrtRTEI, &c5_st);
              c5_b_k = 0;
              c5_guard1 = false;
              c5_exitg1 = false;
              while ((!c5_exitg1) && (c5_b_k <= c5_i18 - 1)) {
                c5_b_a = c5_b_currentPixel + 1;
                c5_i29 = c5_b_direction + 1;
                if ((c5_i29 < 1) || (c5_i29 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i29, 1, 8, &c5_de_emlrtBCI,
                    &c5_st);
                }

                c5_h_b = c5_f_obj->neighborOffsetsHoles[c5_i29 - 1];
                c5_b_neighbor = c5_b_a + c5_h_b;
                if ((c5_b_neighbor < 1) || (c5_b_neighbor > 19764)) {
                  emlrtDynamicBoundsCheckR2012b(c5_b_neighbor, 1, 19764,
                    &c5_be_emlrtBCI, &c5_st);
                }

                if ((c5_f_obj->paddedLabelMatrix[c5_b_neighbor - 1] == (real_T)
                     c5_c_label) || (c5_f_obj->paddedLabelMatrix[c5_b_neighbor -
                                     1] == c5_f_obj->startMarker)) {
                  if ((c5_f_obj->paddedLabelMatrix[c5_b_currentPixel] ==
                       c5_f_obj->startMarker) && (c5_b_initDepartureDir == -1))
                  {
                    c5_b_initDepartureDir = c5_b_direction;
                    c5_guard1 = true;
                  } else if ((c5_f_obj->paddedLabelMatrix[c5_b_currentPixel] ==
                              c5_f_obj->startMarker) && (c5_b_initDepartureDir ==
                              c5_b_direction)) {
                    c5_b_isDone = true;
                    c5_b_foundNextPixel = true;
                    c5_f_obj->paddedLabelMatrix[c5_b_currentPixel] = (real_T)
                      c5_c_label;
                  } else {
                    c5_guard1 = true;
                  }

                  c5_exitg1 = true;
                } else {
                  c5_i39 = c5_b_direction + 1;
                  if ((c5_i39 < 1) || (c5_i39 > 8)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i39, 1, 8, &c5_ge_emlrtBCI,
                      &c5_st);
                  }

                  c5_b_direction = c5_f_obj->nextDirectionLutHoles[c5_i39 - 1];
                  c5_b_k++;
                  c5_guard1 = false;
                }
              }

              if (c5_guard1) {
                c5_i28 = c5_b_direction + 1;
                if ((c5_i28 < 1) || (c5_i28 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i28, 1, 8, &c5_ie_emlrtBCI,
                    &c5_st);
                }

                c5_b_nextSearchDir = c5_f_obj->
                  nextSearchDirectionLutHoles[c5_i28 - 1];
                c5_b_foundNextPixel = true;
                if (c5_b_scratchLength <= c5_b_numPixels) {
                  c5_b_st.site = &c5_sd_emlrtRSI;
                  c5_expandScratchSpace(chartInstance, &c5_b_st, &c5_scratch,
                                        c5_b_scratchLength, &c5_b_scratch,
                                        &c5_d_scratchLength);
                  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_scratch,
                    &c5_sb_emlrtRTEI, c5_b_scratch.size[0]);
                  c5_c_loop_ub = c5_b_scratch.size[0] - 1;
                  for (c5_i44 = 0; c5_i44 <= c5_c_loop_ub; c5_i44++) {
                    c5_scratch.vector.data[c5_i44] =
                      c5_b_scratch.vector.data[c5_i44];
                  }

                  c5_b_scratchLength = c5_d_scratchLength;
                }

                c5_i38 = c5_scratch.size[0];
                if ((c5_b_numPixels < 1) || (c5_b_numPixels > c5_i38)) {
                  emlrtDynamicBoundsCheckR2012b(c5_b_numPixels, 1, c5_i38,
                    &c5_je_emlrtBCI, &c5_st);
                }

                c5_scratch.vector.data[c5_b_numPixels - 1] = c5_b_neighbor;
                c5_b_numPixels++;
                if (c5_b_numPixels - 1 == MAX_int32_T) {
                  c5_b_isDone = true;
                } else {
                  c5_b_currentPixel = c5_b_neighbor - 1;
                }
              }

              if (!c5_b_foundNextPixel) {
                c5_b_numPixels = 3;
                c5_scratch.vector.data[1] = c5_scratch.vector.data[0];
                c5_b_isDone = true;
              }
            }

            c5_b_st.site = &c5_td_emlrtRSI;
            c5_BoundaryFinder_copyCoordsToBuf(chartInstance, &c5_b_st, c5_f_obj,
              c5_b_numPixels - 1, &c5_scratch, &c5_boundary);
            c5_i17 = c5_B->size[0] - 1;
            c5_i19 = c5_label - 1;
            if ((c5_i19 < 0) || (c5_i19 > c5_i17)) {
              emlrtDynamicBoundsCheckR2012b(c5_i19, 0, c5_i17, &c5_ud_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i21 = c5_i19;
            c5_st.site = &c5_tj_emlrtRSI;
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_B->
              vector.data[c5_i21].f1, &c5_rb_emlrtRTEI, c5_boundary.size[0],
              c5_B->vector.data[c5_i21].f1.size[1]);
            c5_i26 = c5_B->size[0] - 1;
            c5_i27 = c5_label - 1;
            if ((c5_i27 < 0) || (c5_i27 > c5_i26)) {
              emlrtDynamicBoundsCheckR2012b(c5_i27, 0, c5_i26, &c5_ud_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i31 = c5_i27;
            c5_st.site = &c5_tj_emlrtRSI;
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_B->
              vector.data[c5_i31].f1, &c5_rb_emlrtRTEI, c5_B->vector.data[c5_i31]
              .f1.size[0], 2);
            c5_i35 = c5_B->size[0] - 1;
            c5_i37 = c5_label - 1;
            if ((c5_i37 < 0) || (c5_i37 > c5_i35)) {
              emlrtDynamicBoundsCheckR2012b(c5_i37, 0, c5_i35, &c5_ud_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i43 = c5_B->size[0] - 1;
            c5_i45 = c5_label - 1;
            if ((c5_i45 < 0) || (c5_i45 > c5_i43)) {
              emlrtDynamicBoundsCheckR2012b(c5_i45, 0, c5_i43, &c5_ud_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_e_loop_ub = (c5_boundary.size[0] << 1) - 1;
            for (c5_i47 = 0; c5_i47 <= c5_e_loop_ub; c5_i47++) {
              c5_i52 = c5_B->size[0] - 1;
              c5_i53 = c5_label - 1;
              if ((c5_i53 < 0) || (c5_i53 > c5_i52)) {
                emlrtDynamicBoundsCheckR2012b(c5_i53, 0, c5_i52, &c5_le_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_B->vector.data[c5_i53].f1.vector.data[c5_i47] =
                c5_boundary.vector.data[c5_i47];
            }

            c5_i51 = c5_regionHasBeenTraced.size[0];
            if ((c5_label < 1) || (c5_label > c5_i51)) {
              emlrtDynamicBoundsCheckR2012b(c5_label, 1, c5_i51, &c5_fe_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_regionHasBeenTraced.vector.data[c5_label - 1] = true;
          }
        }
      }
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_b_scratch);
    c5_array_int32_T_Destructor(chartInstance, &c5_scratch);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_boundary);
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_regionHasBeenTraced);
}

static void c5_expandScratchSpace(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_scratchIn,
  int32_T c5_scratchLengthIn, c5_coder_array_int32_T *c5_scratch, int32_T
  *c5_scratchLength)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_b_k;
  int32_T c5_b_scratchLength;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_k;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_b = c5_scratchLengthIn;
  c5_b_scratchLength = c5_c_b << 1;
  c5_st.site = &c5_xi_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_scratch, &c5_tb_emlrtRTEI,
    c5_b_scratchLength);
  c5_st.site = &c5_ud_emlrtRSI;
  c5_d_b = c5_scratchLengthIn;
  c5_e_b = c5_d_b;
  if (c5_e_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_e_b > 2147483646);
  }

  if (c5_overflow) {
    c5_b_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
  }

  for (c5_k = 0; c5_k < c5_scratchLengthIn; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_i = c5_scratchIn->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i, &c5_me_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i1 = c5_scratch->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i1)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i1, &c5_ne_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_scratch->vector.data[c5_b_k - 1] = c5_scratchIn->vector.data[c5_b_k - 1];
  }

  *c5_scratchLength = c5_b_scratchLength;
}

static void c5_BoundaryFinder_copyCoordsToBuf
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_images_internal_coder_BoundaryFinderObjectHoles *c5_obj, int32_T
   c5_numPixels, c5_coder_array_int32_T *c5_linearIndices,
   c5_coder_array_real_T_2D *c5_boundary)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_d;
  int32_T c5_a;
  int32_T c5_b_k;
  int32_T c5_c_b;
  int32_T c5_col;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_k;
  int32_T c5_row;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_d = (real_T)c5_numPixels;
  if (!(c5_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d, &c5_o_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_sj_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_boundary,
    &c5_ub_emlrtRTEI, (int32_T)muDoubleScalarFloor(c5_d), 2);
  c5_st.site = &c5_vd_emlrtRSI;
  c5_c_b = c5_numPixels;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_b_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
  }

  for (c5_k = 0; c5_k < c5_numPixels; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_i = c5_linearIndices->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i, &c5_oe_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_a = c5_linearIndices->vector.data[c5_b_k - 1];
    c5_e_b = c5_obj->numRows;
    c5_col = c5_div_s32_ndbzs(chartInstance, c5_a, c5_e_b, 0, 0U, 0, 0);
    c5_i1 = c5_linearIndices->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i1)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i1, &c5_pe_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_row = c5_linearIndices->vector.data[c5_b_k - 1] - c5_col *
      c5_obj->numRows;
    c5_i2 = c5_boundary->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i2)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i2, &c5_qe_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_boundary->vector.data[c5_b_k - 1] = (real_T)(c5_row - 1);
    c5_i3 = c5_boundary->size[0];
    if ((c5_b_k < 1) || (c5_b_k > c5_i3)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_k, 1, c5_i3, &c5_re_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_boundary->vector.data[(c5_b_k + c5_boundary->size[0]) - 1] = (real_T)
      c5_col;
  }
}

static void c5_adjacencyMatrix(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_cell_wrap_0 *c5_B,
  real_T c5_b_N, c5_coder_array_boolean_T_2D *c5_A)
{
  static char_T c5_b_cv3[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  static char_T c5_b_cv5[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  static char_T c5_b_cv2[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'r', 'e', 's', 'h', 'a', 'p', 'e', '_', 'e', 'm',
    'p', 't', 'y', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'L', 'i', 'm', 'i', 't' };

  static char_T c5_b_cv4[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'r', 'e', 's', 'h', 'a', 'p', 'e', '_', 'e', 'm',
    'p', 't', 'y', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'L', 'i', 'm', 'i', 't' };

  static char_T c5_b_cv[2] = { 'X', 'V' };

  static char_T c5_b_cv1[2] = { 'Y', 'V' };

  c5_coder_array_boolean_T c5_in;
  c5_coder_array_boolean_T c5_mask;
  c5_coder_array_boolean_T c5_on;
  c5_coder_array_boolean_T c5_onMask;
  c5_coder_array_boolean_T_2D c5_isInside;
  c5_coder_array_int32_T c5_childrenIdx;
  c5_coder_array_int32_T c5_groupedIndices;
  c5_coder_array_int32_T c5_ii;
  c5_coder_array_int32_T c5_numElemsPerGroup;
  c5_coder_array_int32_T c5_parentsIdx;
  c5_coder_array_real_T c5_closedPolygon_x;
  c5_coder_array_real_T c5_closedPolygon_y;
  c5_coder_array_real_T c5_inBoundsPointsIdx;
  c5_coder_array_real_T c5_inBoundsPoints_x;
  c5_coder_array_real_T c5_inBoundsPoints_y;
  c5_coder_array_real_T c5_points_x;
  c5_coder_array_real_T c5_points_y;
  c5_coder_array_real_T_2D c5_boundary;
  c5_coder_array_real_T_2D c5_dotProd;
  c5_coder_array_real_T_2D c5_sampChildren;
  c5_coder_array_real_T_2D c5_signCrossProd;
  c5_coder_array_real_T_2D c5_translatedPolygon_x;
  c5_coder_array_real_T_2D c5_translatedPolygon_y;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_inputSize[2];
  real_T c5_b_k;
  real_T c5_b_maxval;
  real_T c5_b_minval;
  real_T c5_b_v;
  real_T c5_c_maxval;
  real_T c5_c_minval;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_m;
  real_T c5_d_maxval;
  real_T c5_d_minval;
  real_T c5_d_p;
  real_T c5_maxval;
  real_T c5_minval;
  real_T c5_numBoundaries;
  real_T c5_numPoints;
  real_T c5_numVertices;
  real_T c5_xRange;
  real_T c5_yRange;
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_sz[2];
  int32_T c5_a;
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_m;
  int32_T c5_b_maxdimlen;
  int32_T c5_b_n;
  int32_T c5_b_nx;
  int32_T c5_b_p;
  int32_T c5_b_partialTrueCount;
  int32_T c5_b_points_x;
  int32_T c5_b_points_y;
  int32_T c5_b_result;
  int32_T c5_b_trueCount;
  int32_T c5_b_varargin_1;
  int32_T c5_c_b;
  int32_T c5_c_i;
  int32_T c5_c_loop_ub;
  int32_T c5_c_m;
  int32_T c5_c_n;
  int32_T c5_c_p;
  int32_T c5_c_varargin_1;
  int32_T c5_childIdx;
  int32_T c5_d_b;
  int32_T c5_d_i;
  int32_T c5_d_loop_ub;
  int32_T c5_d_varargin_1;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_e_m;
  int32_T c5_e_varargin_1;
  int32_T c5_end;
  int32_T c5_f_b;
  int32_T c5_f_loop_ub;
  int32_T c5_f_varargin_1;
  int32_T c5_g_b;
  int32_T c5_g_loop_ub;
  int32_T c5_h_b;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_loop_ub;
  int32_T c5_idx;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m;
  int32_T c5_m_loop_ub;
  int32_T c5_maxdimlen;
  int32_T c5_n;
  int32_T c5_n_loop_ub;
  int32_T c5_numChildren;
  int32_T c5_numElems;
  int32_T c5_numLevels;
  int32_T c5_numObjs;
  int32_T c5_nx;
  int32_T c5_o_loop_ub;
  int32_T c5_p;
  int32_T c5_p_loop_ub;
  int32_T c5_parentIdx;
  int32_T c5_partialTrueCount;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_result;
  int32_T c5_s_loop_ub;
  int32_T c5_t_loop_ub;
  int32_T c5_totalNumElems;
  int32_T c5_trueCount;
  int32_T c5_u_loop_ub;
  int32_T c5_v;
  int32_T c5_v_loop_ub;
  int32_T c5_varargin_1;
  int32_T c5_w_loop_ub;
  int32_T c5_x_loop_ub;
  char_T c5_b_u;
  char_T c5_u;
  boolean_T c5_TF;
  boolean_T c5_b1;
  boolean_T c5_b_overflow;
  boolean_T c5_e_b;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_numObjs = (int32_T)c5_b_N;
  c5_numBoundaries = (real_T)c5_B->size[0];
  c5_i = (int32_T)c5_numBoundaries;
  c5_st.site = &c5_ck_emlrtRSI;
  c5_array_boolean_T_2D_SetSize(chartInstance, &c5_st, c5_A, &c5_vb_emlrtRTEI,
    c5_i, c5_i);
  c5_loop_ub = c5_i * c5_i - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_A->vector.data[c5_i1] = false;
  }

  c5_array_int32_T_Constructor(chartInstance, &c5_groupedIndices);
  c5_array_int32_T_Constructor(chartInstance, &c5_numElemsPerGroup);
  c5_st.site = &c5_wd_emlrtRSI;
  c5_groupBoundariesByTreeLevelCodegen(chartInstance, &c5_st, c5_B, c5_numObjs,
    &c5_numLevels, &c5_groupedIndices, &c5_numElemsPerGroup);
  c5_totalNumElems = 0;
  c5_i2 = c5_numLevels - 2;
  c5_st.site = &c5_xd_emlrtRSI;
  c5_c_b = c5_i2 + 1;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_b_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
  }

  c5_array_int32_T_Constructor(chartInstance, &c5_parentsIdx);
  c5_array_int32_T_Constructor(chartInstance, &c5_childrenIdx);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_sampChildren);
  c5_array_boolean_T_2D_Constructor(chartInstance, &c5_isInside);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_boundary);
  c5_array_real_T_Constructor(chartInstance, &c5_points_x);
  c5_array_real_T_Constructor(chartInstance, &c5_points_y);
  c5_array_boolean_T_Constructor(chartInstance, &c5_mask);
  c5_array_real_T_Constructor(chartInstance, &c5_inBoundsPointsIdx);
  c5_array_real_T_Constructor(chartInstance, &c5_inBoundsPoints_x);
  c5_array_real_T_Constructor(chartInstance, &c5_inBoundsPoints_y);
  c5_array_boolean_T_Constructor(chartInstance, &c5_onMask);
  c5_array_real_T_Constructor(chartInstance, &c5_closedPolygon_x);
  c5_array_real_T_Constructor(chartInstance, &c5_closedPolygon_y);
  c5_array_boolean_T_Constructor(chartInstance, &c5_in);
  c5_array_int32_T_Constructor(chartInstance, &c5_ii);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_translatedPolygon_x);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_translatedPolygon_y);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_signCrossProd);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_dotProd);
  c5_array_boolean_T_Constructor(chartInstance, &c5_on);
  for (c5_p = 0; c5_p <= c5_i2; c5_p++) {
    c5_b_p = c5_p;
    c5_i3 = c5_numElemsPerGroup.size[0];
    c5_i4 = c5_b_p + 1;
    if ((c5_i4 < 1) || (c5_i4 > c5_i3)) {
      emlrtDynamicBoundsCheckR2012b(c5_i4, 1, c5_i3, &c5_df_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_numElems = c5_numElemsPerGroup.vector.data[c5_i4 - 1];
    c5_i5 = c5_totalNumElems + 1;
    c5_i6 = c5_totalNumElems + c5_numElems;
    c5_e_b = (c5_i5 > c5_i6);
    if (c5_e_b) {
      c5_i8 = 0;
      c5_i9 = 0;
    } else {
      c5_i7 = c5_groupedIndices.size[0];
      if ((c5_i5 < 1) || (c5_i5 > c5_i7)) {
        emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i7, &c5_xe_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i8 = c5_i5 - 1;
      c5_i10 = c5_groupedIndices.size[0];
      if ((c5_i6 < 1) || (c5_i6 > c5_i10)) {
        emlrtDynamicBoundsCheckR2012b(c5_i6, 1, c5_i10, &c5_we_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i9 = c5_i6;
    }

    c5_iv[0] = 1;
    c5_iv[1] = c5_i9 - c5_i8;
    c5_st.site = &c5_yd_emlrtRSI;
    c5_indexShapeCheck(chartInstance, &c5_st, c5_groupedIndices.size[0], c5_iv);
    c5_st.site = &c5_yd_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_parentsIdx,
      &c5_wb_emlrtRTEI, c5_i9 - c5_i8);
    c5_b_loop_ub = (c5_i9 - c5_i8) - 1;
    for (c5_i11 = 0; c5_i11 <= c5_b_loop_ub; c5_i11++) {
      c5_parentsIdx.vector.data[c5_i11] = c5_groupedIndices.vector.data[c5_i8 +
        c5_i11];
    }

    c5_a = c5_totalNumElems;
    c5_f_b = c5_numElems;
    c5_totalNumElems = c5_a + c5_f_b;
    c5_i12 = c5_numElemsPerGroup.size[0];
    c5_i13 = c5_b_p + 2;
    if ((c5_i13 < 1) || (c5_i13 > c5_i12)) {
      emlrtDynamicBoundsCheckR2012b(c5_i13, 1, c5_i12, &c5_ef_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_numElems = c5_numElemsPerGroup.vector.data[c5_i13 - 1];
    c5_i14 = c5_totalNumElems + 1;
    c5_i15 = c5_totalNumElems + c5_numElems;
    c5_b1 = (c5_i14 > c5_i15);
    if (c5_b1) {
      c5_i17 = 0;
      c5_i18 = 0;
    } else {
      c5_i16 = c5_groupedIndices.size[0];
      if ((c5_i14 < 1) || (c5_i14 > c5_i16)) {
        emlrtDynamicBoundsCheckR2012b(c5_i14, 1, c5_i16, &c5_ve_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i17 = c5_i14 - 1;
      c5_i19 = c5_groupedIndices.size[0];
      if ((c5_i15 < 1) || (c5_i15 > c5_i19)) {
        emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i19, &c5_ue_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i18 = c5_i15;
    }

    c5_iv1[0] = 1;
    c5_iv1[1] = c5_i18 - c5_i17;
    c5_st.site = &c5_ae_emlrtRSI;
    c5_indexShapeCheck(chartInstance, &c5_st, c5_groupedIndices.size[0], c5_iv1);
    c5_st.site = &c5_ae_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_childrenIdx,
      &c5_xb_emlrtRTEI, c5_i18 - c5_i17);
    c5_c_loop_ub = (c5_i18 - c5_i17) - 1;
    for (c5_i20 = 0; c5_i20 <= c5_c_loop_ub; c5_i20++) {
      c5_childrenIdx.vector.data[c5_i20] = c5_groupedIndices.vector.data[c5_i17
        + c5_i20];
    }

    c5_st.site = &c5_be_emlrtRSI;
    c5_numChildren = c5_childrenIdx.size[0];
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_sampChildren,
      &c5_yb_emlrtRTEI, c5_numChildren, 2);
    c5_b_st.site = &c5_ng_emlrtRSI;
    c5_g_b = c5_numChildren;
    c5_h_b = c5_g_b;
    if (c5_h_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_h_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_m = 0; c5_m < c5_numChildren; c5_m++) {
      c5_b_m = c5_m + 1;
      c5_i22 = c5_childrenIdx.size[0];
      if ((c5_b_m < 1) || (c5_b_m > c5_i22)) {
        emlrtDynamicBoundsCheckR2012b(c5_b_m, 1, c5_i22, &c5_ff_emlrtBCI, &c5_st);
      }

      c5_idx = c5_childrenIdx.vector.data[c5_b_m - 1] - 1;
      c5_i24 = c5_B->size[0] - 1;
      if ((c5_idx < 0) || (c5_idx > c5_i24)) {
        emlrtDynamicBoundsCheckR2012b(c5_idx, 0, c5_i24, &c5_ye_emlrtBCI, &c5_st);
      }

      c5_i26 = c5_idx;
      c5_i27 = c5_B->vector.data[c5_i26].f1.size[0];
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
        &c5_ac_emlrtRTEI, c5_i27, 2);
      c5_i30 = c5_B->size[0] - 1;
      if ((c5_idx < 0) || (c5_idx > c5_i30)) {
        emlrtDynamicBoundsCheckR2012b(c5_idx, 0, c5_i30, &c5_ye_emlrtBCI, &c5_st);
      }

      c5_i32 = c5_idx;
      c5_i34 = c5_B->size[0] - 1;
      if ((c5_idx < 0) || (c5_idx > c5_i34)) {
        emlrtDynamicBoundsCheckR2012b(c5_idx, 0, c5_i34, &c5_ye_emlrtBCI, &c5_st);
      }

      c5_d_loop_ub = (c5_B->vector.data[c5_i32].f1.size[0] << 1) - 1;
      for (c5_i37 = 0; c5_i37 <= c5_d_loop_ub; c5_i37++) {
        c5_i39 = c5_B->size[0] - 1;
        if ((c5_idx < 0) || (c5_idx > c5_i39)) {
          emlrtDynamicBoundsCheckR2012b(c5_idx, 0, c5_i39, &c5_ye_emlrtBCI,
            &c5_st);
        }

        c5_boundary.vector.data[c5_i37] = c5_B->vector.data[c5_idx].
          f1.vector.data[c5_i37];
      }

      c5_i38 = c5_boundary.size[0];
      c5_i41 = 1;
      if ((c5_i41 < 1) || (c5_i41 > c5_i38)) {
        emlrtDynamicBoundsCheckR2012b(c5_i41, 1, c5_i38, &c5_te_emlrtBCI, &c5_st);
      }

      c5_i44 = c5_sampChildren.size[0];
      if ((c5_b_m < 1) || (c5_b_m > c5_i44)) {
        emlrtDynamicBoundsCheckR2012b(c5_b_m, 1, c5_i44, &c5_se_emlrtBCI, &c5_st);
      }

      c5_e_m = c5_b_m - 1;
      for (c5_i46 = 0; c5_i46 < 2; c5_i46++) {
        c5_sampChildren.vector.data[c5_e_m + c5_sampChildren.size[0] * c5_i46] =
          c5_boundary.vector.data[c5_boundary.size[0] * c5_i46];
      }
    }

    c5_d = (real_T)c5_parentsIdx.size[0];
    c5_i21 = (int32_T)c5_d - 1;
    for (c5_c_m = 0; c5_c_m <= c5_i21; c5_c_m++) {
      c5_d_m = (real_T)c5_c_m + 1.0;
      c5_i23 = c5_parentsIdx.size[0];
      c5_i25 = (int32_T)c5_d_m;
      if ((c5_i25 < 1) || (c5_i25 > c5_i23)) {
        emlrtDynamicBoundsCheckR2012b(c5_i25, 1, c5_i23, &c5_gf_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_parentIdx = c5_parentsIdx.vector.data[c5_i25 - 1];
      c5_i28 = c5_B->size[0] - 1;
      c5_i29 = c5_parentIdx - 1;
      if ((c5_i29 < 0) || (c5_i29 > c5_i28)) {
        emlrtDynamicBoundsCheckR2012b(c5_i29, 0, c5_i28, &c5_af_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i31 = c5_i29;
      c5_i33 = c5_B->vector.data[c5_i31].f1.size[0];
      c5_st.site = &c5_rj_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
        &c5_bc_emlrtRTEI, c5_i33, 2);
      c5_i35 = c5_B->size[0] - 1;
      c5_i36 = c5_parentIdx - 1;
      if ((c5_i36 < 0) || (c5_i36 > c5_i35)) {
        emlrtDynamicBoundsCheckR2012b(c5_i36, 0, c5_i35, &c5_af_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i40 = c5_i36;
      c5_i42 = c5_B->size[0] - 1;
      c5_i43 = c5_parentIdx - 1;
      if ((c5_i43 < 0) || (c5_i43 > c5_i42)) {
        emlrtDynamicBoundsCheckR2012b(c5_i43, 0, c5_i42, &c5_af_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_e_loop_ub = (c5_B->vector.data[c5_i40].f1.size[0] << 1) - 1;
      for (c5_i45 = 0; c5_i45 <= c5_e_loop_ub; c5_i45++) {
        c5_i47 = c5_B->size[0] - 1;
        c5_i48 = c5_parentIdx - 1;
        if ((c5_i48 < 0) || (c5_i48 > c5_i47)) {
          emlrtDynamicBoundsCheckR2012b(c5_i48, 0, c5_i47, &c5_af_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_boundary.vector.data[c5_i45] = c5_B->vector.data[c5_i48].
          f1.vector.data[c5_i45];
      }

      c5_st.site = &c5_ce_emlrtRSI;
      c5_b_st.site = &c5_lj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_points_x,
        &c5_cc_emlrtRTEI, c5_sampChildren.size[0]);
      c5_f_loop_ub = c5_sampChildren.size[0] - 1;
      for (c5_i49 = 0; c5_i49 <= c5_f_loop_ub; c5_i49++) {
        c5_points_x.vector.data[c5_i49] = c5_sampChildren.vector.data[c5_i49 +
          c5_sampChildren.size[0]];
      }

      c5_b_st.site = &c5_lj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_points_y,
        &c5_dc_emlrtRTEI, c5_sampChildren.size[0]);
      c5_g_loop_ub = c5_sampChildren.size[0] - 1;
      for (c5_i50 = 0; c5_i50 <= c5_g_loop_ub; c5_i50++) {
        c5_points_y.vector.data[c5_i50] = c5_sampChildren.vector.data[c5_i50];
      }

      c5_b_st.site = &c5_kj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_inBoundsPoints_y,
        &c5_ec_emlrtRTEI, c5_boundary.size[0]);
      c5_h_loop_ub = c5_boundary.size[0] - 1;
      for (c5_i51 = 0; c5_i51 <= c5_h_loop_ub; c5_i51++) {
        c5_inBoundsPoints_y.vector.data[c5_i51] = c5_boundary.vector.data[c5_i51
          + c5_boundary.size[0]];
      }

      c5_b_st.site = &c5_kj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_inBoundsPoints_x,
        &c5_fc_emlrtRTEI, c5_boundary.size[0]);
      c5_i_loop_ub = c5_boundary.size[0] - 1;
      for (c5_i52 = 0; c5_i52 <= c5_i_loop_ub; c5_i52++) {
        c5_inBoundsPoints_x.vector.data[c5_i52] = c5_boundary.vector.data[c5_i52];
      }

      c5_b_st.site = &c5_qe_emlrtRSI;
      if ((real_T)c5_points_x.size[0] != (real_T)c5_points_y.size[0]) {
        c5_y = NULL;
        sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 39),
                      false);
        c5_c_y = NULL;
        sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_u = 'X';
        c5_e_y = NULL;
        sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_u, 10, 0U, 0, 0U, 0),
                      false);
        c5_b_u = 'Y';
        c5_h_y = NULL;
        sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_b_u, 10, 0U, 0, 0U, 0),
                      false);
        sf_mex_call(&c5_b_st, &c5_n_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                    sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_b_st, NULL, "message", 1U, 3U, 14, c5_c_y, 14, c5_e_y,
                      14, c5_h_y)));
      }

      if ((real_T)c5_inBoundsPoints_y.size[0] != (real_T)
          c5_inBoundsPoints_x.size[0]) {
        c5_b_y = NULL;
        sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_d_y = NULL;
        sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c5_f_y = NULL;
        sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
          2), false);
        c5_g_y = NULL;
        sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
          2), false);
        sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                    sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_b_st, NULL, "message", 1U, 3U, 14, c5_d_y, 14, c5_f_y,
                      14, c5_g_y)));
      }

      c5_inputSize[0] = (real_T)c5_points_x.size[0];
      c5_inputSize[1] = 1.0;
      c5_b_st.site = &c5_re_emlrtRSI;
      c5_c_st.site = &c5_ye_emlrtRSI;
      c5_d_st.site = &c5_df_emlrtRSI;
      c5_e_st.site = &c5_ef_emlrtRSI;
      c5_minval = c5_minimum(chartInstance, &c5_e_st, &c5_inBoundsPoints_y);
      c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_mask,
        &c5_gc_emlrtRTEI, c5_points_x.size[0]);
      c5_j_loop_ub = c5_points_x.size[0] - 1;
      for (c5_i53 = 0; c5_i53 <= c5_j_loop_ub; c5_i53++) {
        c5_mask.vector.data[c5_i53] = (c5_points_x.vector.data[c5_i53] >=
          c5_minval);
      }

      c5_c_st.site = &c5_af_emlrtRSI;
      c5_d_st.site = &c5_mf_emlrtRSI;
      c5_e_st.site = &c5_nf_emlrtRSI;
      c5_maxval = c5_maximum(chartInstance, &c5_e_st, &c5_inBoundsPoints_y);
      c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_in,
        &c5_hc_emlrtRTEI, c5_points_x.size[0]);
      c5_k_loop_ub = c5_points_x.size[0] - 1;
      for (c5_i54 = 0; c5_i54 <= c5_k_loop_ub; c5_i54++) {
        c5_in.vector.data[c5_i54] = (c5_points_x.vector.data[c5_i54] <=
          c5_maxval);
      }

      c5_i55 = c5_mask.size[0];
      c5_i56 = c5_in.size[0];
      if (c5_i55 != c5_i56) {
        emlrtSizeEqCheck1DR2012b(c5_i55, c5_i56, &c5_f_emlrtECI, &c5_b_st);
      }

      c5_l_loop_ub = c5_mask.size[0] - 1;
      for (c5_i57 = 0; c5_i57 <= c5_l_loop_ub; c5_i57++) {
        c5_mask.vector.data[c5_i57] = (c5_mask.vector.data[c5_i57] &&
          c5_in.vector.data[c5_i57]);
      }

      c5_c_st.site = &c5_bf_emlrtRSI;
      c5_d_st.site = &c5_df_emlrtRSI;
      c5_e_st.site = &c5_ef_emlrtRSI;
      c5_b_minval = c5_minimum(chartInstance, &c5_e_st, &c5_inBoundsPoints_x);
      c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_in,
        &c5_ic_emlrtRTEI, c5_points_y.size[0]);
      c5_m_loop_ub = c5_points_y.size[0] - 1;
      for (c5_i58 = 0; c5_i58 <= c5_m_loop_ub; c5_i58++) {
        c5_in.vector.data[c5_i58] = (c5_points_y.vector.data[c5_i58] >=
          c5_b_minval);
      }

      c5_i59 = c5_mask.size[0];
      c5_i60 = c5_in.size[0];
      if ((c5_i59 != c5_i60) && ((c5_i59 != 1) && (c5_i60 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c5_i59, c5_i60, &c5_e_emlrtECI, &c5_b_st);
      }

      if (c5_mask.size[0] == c5_in.size[0]) {
        c5_n_loop_ub = c5_mask.size[0] - 1;
        for (c5_i61 = 0; c5_i61 <= c5_n_loop_ub; c5_i61++) {
          c5_mask.vector.data[c5_i61] = (c5_mask.vector.data[c5_i61] &&
            c5_in.vector.data[c5_i61]);
        }
      } else {
        c5_c_st.site = &c5_ye_emlrtRSI;
        c5_and(chartInstance, &c5_c_st, &c5_mask, &c5_in);
      }

      c5_c_st.site = &c5_cf_emlrtRSI;
      c5_d_st.site = &c5_mf_emlrtRSI;
      c5_e_st.site = &c5_nf_emlrtRSI;
      c5_b_maxval = c5_maximum(chartInstance, &c5_e_st, &c5_inBoundsPoints_x);
      c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_in,
        &c5_jc_emlrtRTEI, c5_points_y.size[0]);
      c5_o_loop_ub = c5_points_y.size[0] - 1;
      for (c5_i62 = 0; c5_i62 <= c5_o_loop_ub; c5_i62++) {
        c5_in.vector.data[c5_i62] = (c5_points_y.vector.data[c5_i62] <=
          c5_b_maxval);
      }

      c5_i63 = c5_mask.size[0];
      c5_i64 = c5_in.size[0];
      if ((c5_i63 != c5_i64) && ((c5_i63 != 1) && (c5_i64 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c5_i63, c5_i64, &c5_e_emlrtECI, &c5_b_st);
      }

      if (c5_mask.size[0] == c5_in.size[0]) {
        c5_p_loop_ub = c5_mask.size[0] - 1;
        for (c5_i65 = 0; c5_i65 <= c5_p_loop_ub; c5_i65++) {
          c5_mask.vector.data[c5_i65] = (c5_mask.vector.data[c5_i65] &&
            c5_in.vector.data[c5_i65]);
        }
      } else {
        c5_c_st.site = &c5_ye_emlrtRSI;
        c5_and(chartInstance, &c5_c_st, &c5_mask, &c5_in);
      }

      c5_c_st.site = &c5_rg_emlrtRSI;
      c5_TF = !c5_any(chartInstance, &c5_c_st, &c5_mask);
      if (c5_TF) {
        c5_array_boolean_T_2D_SetSize(chartInstance, &c5_st, &c5_isInside,
          &c5_rc_emlrtRTEI, (int32_T)c5_inputSize[0], 1);
        c5_q_loop_ub = (int32_T)c5_inputSize[0] - 1;
        for (c5_i66 = 0; c5_i66 <= c5_q_loop_ub; c5_i66++) {
          c5_isInside.vector.data[c5_i66] = false;
        }
      } else {
        c5_b_st.site = &c5_se_emlrtRSI;
        c5_closeLoops(chartInstance, &c5_b_st, &c5_inBoundsPoints_y,
                      &c5_inBoundsPoints_x, &c5_closedPolygon_x,
                      &c5_closedPolygon_y);
        c5_b_st.site = &c5_te_emlrtRSI;
        c5_c_st.site = &c5_mf_emlrtRSI;
        c5_d_st.site = &c5_nf_emlrtRSI;
        c5_c_maxval = c5_maximum(chartInstance, &c5_d_st, &c5_closedPolygon_x);
        c5_b_st.site = &c5_te_emlrtRSI;
        c5_c_st.site = &c5_df_emlrtRSI;
        c5_d_st.site = &c5_ef_emlrtRSI;
        c5_c_minval = c5_minimum(chartInstance, &c5_d_st, &c5_closedPolygon_x);
        c5_xRange = c5_c_maxval - c5_c_minval;
        c5_b_st.site = &c5_ue_emlrtRSI;
        c5_c_st.site = &c5_mf_emlrtRSI;
        c5_d_st.site = &c5_nf_emlrtRSI;
        c5_d_maxval = c5_maximum(chartInstance, &c5_d_st, &c5_closedPolygon_y);
        c5_b_st.site = &c5_ue_emlrtRSI;
        c5_c_st.site = &c5_df_emlrtRSI;
        c5_d_st.site = &c5_ef_emlrtRSI;
        c5_d_minval = c5_minimum(chartInstance, &c5_d_st, &c5_closedPolygon_y);
        c5_yRange = c5_d_maxval - c5_d_minval;
        if ((c5_xRange < 1.0E-15) || (c5_yRange < 1.0E-15)) {
          c5_b_st.site = &c5_ve_emlrtRSI;
          c5_warning(chartInstance, &c5_b_st);
        }

        if ((c5_xRange > 1.0E+150) || (c5_yRange > 1.0E+150)) {
          c5_b_st.site = &c5_we_emlrtRSI;
          c5_b_warning(chartInstance, &c5_b_st);
        }

        c5_b_st.site = &c5_og_emlrtRSI;
        c5_c_st.site = &c5_dg_emlrtRSI;
        c5_eml_find(chartInstance, &c5_c_st, &c5_mask, &c5_ii);
        c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_inBoundsPointsIdx,
          &c5_kc_emlrtRTEI, c5_ii.size[0]);
        c5_r_loop_ub = c5_ii.size[0] - 1;
        for (c5_i74 = 0; c5_i74 <= c5_r_loop_ub; c5_i74++) {
          c5_inBoundsPointsIdx.vector.data[c5_i74] = (real_T)
            c5_ii.vector.data[c5_i74];
        }

        c5_b_points_x = c5_points_x.size[0];
        c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_inBoundsPoints_x,
          &c5_lc_emlrtRTEI, c5_inBoundsPointsIdx.size[0]);
        c5_s_loop_ub = c5_inBoundsPointsIdx.size[0] - 1;
        for (c5_i75 = 0; c5_i75 <= c5_s_loop_ub; c5_i75++) {
          c5_i76 = (int32_T)c5_inBoundsPointsIdx.vector.data[c5_i75];
          if ((c5_i76 < 1) || (c5_i76 > c5_b_points_x)) {
            emlrtDynamicBoundsCheckR2012b(c5_i76, 1, c5_b_points_x,
              &c5_lf_emlrtBCI, &c5_st);
          }

          c5_inBoundsPoints_x.vector.data[c5_i75] =
            c5_points_x.vector.data[c5_i76 - 1];
        }

        c5_b_points_y = c5_points_y.size[0];
        c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_inBoundsPoints_y,
          &c5_mc_emlrtRTEI, c5_inBoundsPointsIdx.size[0]);
        c5_t_loop_ub = c5_inBoundsPointsIdx.size[0] - 1;
        for (c5_i77 = 0; c5_i77 <= c5_t_loop_ub; c5_i77++) {
          c5_i78 = (int32_T)c5_inBoundsPointsIdx.vector.data[c5_i77];
          if ((c5_i78 < 1) || (c5_i78 > c5_b_points_y)) {
            emlrtDynamicBoundsCheckR2012b(c5_i78, 1, c5_b_points_y,
              &c5_mf_emlrtBCI, &c5_st);
          }

          c5_inBoundsPoints_y.vector.data[c5_i77] =
            c5_points_y.vector.data[c5_i78 - 1];
        }

        c5_b_st.site = &c5_xe_emlrtRSI;
        c5_c_st.site = &c5_hg_emlrtRSI;
        c5_numPoints = (real_T)c5_inBoundsPoints_x.size[0];
        c5_numVertices = (real_T)c5_closedPolygon_x.size[0];
        c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st,
          &c5_translatedPolygon_x, &c5_nc_emlrtRTEI, (int32_T)c5_numVertices,
          (int32_T)c5_numPoints);
        c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st,
          &c5_translatedPolygon_y, &c5_oc_emlrtRTEI, (int32_T)c5_numVertices,
          (int32_T)c5_numPoints);
        c5_i79 = (int32_T)c5_numPoints - 1;
        for (c5_c_p = 0; c5_c_p <= c5_i79; c5_c_p++) {
          c5_d_p = (real_T)c5_c_p + 1.0;
          c5_i80 = (int32_T)c5_numVertices - 1;
          for (c5_v = 0; c5_v <= c5_i80; c5_v++) {
            c5_b_v = (real_T)c5_v + 1.0;
            c5_i81 = c5_closedPolygon_x.size[0];
            c5_i82 = (int32_T)c5_b_v;
            if ((c5_i82 < 1) || (c5_i82 > c5_i81)) {
              emlrtDynamicBoundsCheckR2012b(c5_i82, 1, c5_i81, &c5_nf_emlrtBCI,
                &c5_c_st);
            }

            c5_i83 = c5_inBoundsPoints_x.size[0];
            c5_i85 = (int32_T)c5_d_p;
            if ((c5_i85 < 1) || (c5_i85 > c5_i83)) {
              emlrtDynamicBoundsCheckR2012b(c5_i85, 1, c5_i83, &c5_of_emlrtBCI,
                &c5_c_st);
            }

            c5_i86 = c5_translatedPolygon_x.size[0];
            c5_i87 = (int32_T)c5_b_v;
            if ((c5_i87 < 1) || (c5_i87 > c5_i86)) {
              emlrtDynamicBoundsCheckR2012b(c5_i87, 1, c5_i86, &c5_pf_emlrtBCI,
                &c5_c_st);
            }

            c5_i88 = c5_translatedPolygon_x.size[1];
            c5_i89 = (int32_T)c5_d_p;
            if ((c5_i89 < 1) || (c5_i89 > c5_i88)) {
              emlrtDynamicBoundsCheckR2012b(c5_i89, 1, c5_i88, &c5_qf_emlrtBCI,
                &c5_c_st);
            }

            c5_translatedPolygon_x.vector.data[(c5_i87 +
              c5_translatedPolygon_x.size[0] * (c5_i89 - 1)) - 1] =
              c5_closedPolygon_x.vector.data[c5_i82 - 1] -
              c5_inBoundsPoints_x.vector.data[c5_i85 - 1];
            c5_i93 = c5_closedPolygon_y.size[0];
            c5_i94 = (int32_T)c5_b_v;
            if ((c5_i94 < 1) || (c5_i94 > c5_i93)) {
              emlrtDynamicBoundsCheckR2012b(c5_i94, 1, c5_i93, &c5_rf_emlrtBCI,
                &c5_c_st);
            }

            c5_i96 = c5_inBoundsPoints_y.size[0];
            c5_i98 = (int32_T)c5_d_p;
            if ((c5_i98 < 1) || (c5_i98 > c5_i96)) {
              emlrtDynamicBoundsCheckR2012b(c5_i98, 1, c5_i96, &c5_sf_emlrtBCI,
                &c5_c_st);
            }

            c5_i99 = c5_translatedPolygon_y.size[0];
            c5_i100 = (int32_T)c5_b_v;
            if ((c5_i100 < 1) || (c5_i100 > c5_i99)) {
              emlrtDynamicBoundsCheckR2012b(c5_i100, 1, c5_i99, &c5_tf_emlrtBCI,
                &c5_c_st);
            }

            c5_i101 = c5_translatedPolygon_y.size[1];
            c5_i102 = (int32_T)c5_d_p;
            if ((c5_i102 < 1) || (c5_i102 > c5_i101)) {
              emlrtDynamicBoundsCheckR2012b(c5_i102, 1, c5_i101, &c5_uf_emlrtBCI,
                &c5_c_st);
            }

            c5_translatedPolygon_y.vector.data[(c5_i100 +
              c5_translatedPolygon_y.size[0] * (c5_i102 - 1)) - 1] =
              c5_closedPolygon_y.vector.data[c5_i94 - 1] -
              c5_inBoundsPoints_y.vector.data[c5_i98 - 1];
          }
        }

        c5_c_st.site = &c5_ig_emlrtRSI;
        c5_computeScaledEps(chartInstance, &c5_c_st, &c5_closedPolygon_x,
                            &c5_closedPolygon_y, &c5_inBoundsPoints_y);
        c5_c_st.site = &c5_jg_emlrtRSI;
        c5_computeCrossAndDotProducts(chartInstance, &c5_c_st,
          &c5_translatedPolygon_x, &c5_translatedPolygon_y, &c5_inBoundsPoints_y,
          &c5_signCrossProd, &c5_dotProd);
        c5_c_st.site = &c5_kg_emlrtRSI;
        c5_findInsidePoints(chartInstance, &c5_c_st, &c5_translatedPolygon_x,
                            &c5_translatedPolygon_y, &c5_signCrossProd, &c5_in);
        c5_c_st.site = &c5_lg_emlrtRSI;
        c5_b_findBoundaryPoints(chartInstance, &c5_c_st, &c5_signCrossProd,
          &c5_dotProd, &c5_in, &c5_on);
        c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_onMask,
          &c5_pc_emlrtRTEI, c5_mask.size[0]);
        c5_u_loop_ub = c5_mask.size[0] - 1;
        for (c5_i84 = 0; c5_i84 <= c5_u_loop_ub; c5_i84++) {
          c5_onMask.vector.data[c5_i84] = c5_mask.vector.data[c5_i84];
        }

        c5_end = c5_on.size[0];
        c5_trueCount = 0;
        for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
          if (!c5_on.vector.data[c5_b_i]) {
            c5_trueCount++;
          }
        }

        c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_ii, &c5_qc_emlrtRTEI,
          c5_trueCount);
        c5_partialTrueCount = 0;
        for (c5_c_i = 0; c5_c_i < c5_end; c5_c_i++) {
          if (!c5_on.vector.data[c5_c_i]) {
            c5_i91 = c5_mask.size[0];
            c5_i92 = c5_inBoundsPointsIdx.size[0] - 1;
            if ((c5_c_i < 0) || (c5_c_i > c5_i92)) {
              emlrtDynamicBoundsCheckR2012b(c5_c_i, 0, c5_i92, &c5_vf_emlrtBCI,
                &c5_st);
            }

            c5_i95 = (int32_T)c5_inBoundsPointsIdx.vector.data[c5_c_i];
            if ((c5_i95 < 1) || (c5_i95 > c5_i91)) {
              emlrtDynamicBoundsCheckR2012b(c5_i95, 1, c5_i91, &c5_bf_emlrtBCI,
                &c5_st);
            }

            c5_ii.vector.data[c5_partialTrueCount] = c5_i95;
            c5_partialTrueCount++;
          }
        }

        c5_v_loop_ub = c5_ii.size[0] - 1;
        for (c5_i90 = 0; c5_i90 <= c5_v_loop_ub; c5_i90++) {
          c5_onMask.vector.data[c5_ii.vector.data[c5_i90] - 1] = false;
        }

        c5_b_st.site = &c5_pg_emlrtRSI;
        c5_nx = c5_onMask.size[0];
        c5_c_st.site = &c5_sg_emlrtRSI;
        c5_assertValidSizeArg(chartInstance, &c5_c_st, c5_inputSize);
        for (c5_i97 = 0; c5_i97 < 2; c5_i97++) {
          c5_sz[c5_i97] = (int32_T)c5_inputSize[c5_i97];
        }

        c5_b_n = c5_onMask.size[0];
        if (c5_b_n < 1) {
          c5_b_n = 1;
        }

        c5_maxdimlen = muIntScalarMax_sint32(c5_nx, c5_b_n);
        if (c5_sz[0] > c5_maxdimlen) {
          c5_i_y = NULL;
          sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2,
            1, 39), false);
          c5_j_y = NULL;
          sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2,
            1, 39), false);
          sf_mex_call(&c5_b_st, &c5_o_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                      sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_j_y)));
        }

        c5_c_varargin_1 = c5_sz[0];
        c5_d_varargin_1 = c5_c_varargin_1;
        c5_result = c5_d_varargin_1;
        if (c5_result != c5_nx) {
          c5_k_y = NULL;
          sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2,
            1, 40), false);
          c5_l_y = NULL;
          sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2,
            1, 40), false);
          sf_mex_call(&c5_b_st, &c5_q_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                      sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_l_y)));
        }

        c5_b_end = c5_in.size[0];
        c5_b_trueCount = 0;
        for (c5_d_i = 0; c5_d_i < c5_b_end; c5_d_i++) {
          if (!c5_in.vector.data[c5_d_i]) {
            c5_b_trueCount++;
          }
        }

        c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_ii, &c5_qc_emlrtRTEI,
          c5_b_trueCount);
        c5_b_partialTrueCount = 0;
        for (c5_e_i = 0; c5_e_i < c5_b_end; c5_e_i++) {
          if (!c5_in.vector.data[c5_e_i]) {
            c5_i104 = c5_mask.size[0];
            c5_i105 = c5_inBoundsPointsIdx.size[0] - 1;
            if ((c5_e_i < 0) || (c5_e_i > c5_i105)) {
              emlrtDynamicBoundsCheckR2012b(c5_e_i, 0, c5_i105, &c5_wf_emlrtBCI,
                &c5_st);
            }

            c5_i106 = (int32_T)c5_inBoundsPointsIdx.vector.data[c5_e_i];
            if ((c5_i106 < 1) || (c5_i106 > c5_i104)) {
              emlrtDynamicBoundsCheckR2012b(c5_i106, 1, c5_i104, &c5_cf_emlrtBCI,
                &c5_st);
            }

            c5_ii.vector.data[c5_b_partialTrueCount] = c5_i106;
            c5_b_partialTrueCount++;
          }
        }

        c5_w_loop_ub = c5_ii.size[0] - 1;
        for (c5_i103 = 0; c5_i103 <= c5_w_loop_ub; c5_i103++) {
          c5_mask.vector.data[c5_ii.vector.data[c5_i103] - 1] = false;
        }

        c5_b_st.site = &c5_qg_emlrtRSI;
        c5_b_nx = c5_mask.size[0];
        c5_c_st.site = &c5_sg_emlrtRSI;
        c5_assertValidSizeArg(chartInstance, &c5_c_st, c5_inputSize);
        for (c5_i107 = 0; c5_i107 < 2; c5_i107++) {
          c5_sz[c5_i107] = (int32_T)c5_inputSize[c5_i107];
        }

        c5_c_n = c5_mask.size[0];
        if (c5_c_n < 1) {
          c5_c_n = 1;
        }

        c5_b_maxdimlen = muIntScalarMax_sint32(c5_b_nx, c5_c_n);
        if (c5_sz[0] > c5_b_maxdimlen) {
          c5_m_y = NULL;
          sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2,
            1, 39), false);
          c5_n_y = NULL;
          sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2,
            1, 39), false);
          sf_mex_call(&c5_b_st, &c5_o_emlrtMCI, "error", 0U, 2U, 14, c5_m_y, 14,
                      sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_n_y)));
        }

        c5_e_varargin_1 = c5_sz[0];
        c5_f_varargin_1 = c5_e_varargin_1;
        c5_b_result = c5_f_varargin_1;
        if (c5_b_result != c5_b_nx) {
          c5_o_y = NULL;
          sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2,
            1, 40), false);
          c5_p_y = NULL;
          sf_mex_assign(&c5_p_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2,
            1, 40), false);
          sf_mex_call(&c5_b_st, &c5_q_emlrtMCI, "error", 0U, 2U, 14, c5_o_y, 14,
                      sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_p_y)));
        }

        c5_array_boolean_T_2D_SetSize(chartInstance, &c5_st, &c5_isInside,
          &c5_rc_emlrtRTEI, (int32_T)c5_inputSize[0], 1);
        c5_x_loop_ub = (int32_T)c5_inputSize[0] - 1;
        for (c5_i108 = 0; c5_i108 <= c5_x_loop_ub; c5_i108++) {
          c5_isInside.vector.data[c5_i108] = c5_mask.vector.data[c5_i108];
        }
      }

      c5_varargin_1 = c5_isInside.size[0];
      c5_b_varargin_1 = c5_varargin_1;
      if (c5_b_varargin_1 == 0) {
        c5_n = 0;
      } else if (c5_b_varargin_1 > 1) {
        c5_n = c5_b_varargin_1;
      } else {
        c5_n = 1;
      }

      c5_d1 = (real_T)c5_n;
      c5_i67 = (int32_T)c5_d1 - 1;
      for (c5_k = 0; c5_k <= c5_i67; c5_k++) {
        c5_b_k = (real_T)c5_k + 1.0;
        c5_i68 = c5_childrenIdx.size[0];
        c5_i69 = (int32_T)c5_b_k;
        if ((c5_i69 < 1) || (c5_i69 > c5_i68)) {
          emlrtDynamicBoundsCheckR2012b(c5_i69, 1, c5_i68, &c5_hf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_childIdx = c5_childrenIdx.vector.data[c5_i69 - 1];
        c5_i70 = c5_isInside.size[0];
        c5_i71 = (int32_T)c5_b_k;
        if ((c5_i71 < 1) || (c5_i71 > c5_i70)) {
          emlrtDynamicBoundsCheckR2012b(c5_i71, 1, c5_i70, &c5_if_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i72 = c5_A->size[0];
        if ((c5_childIdx < 1) || (c5_childIdx > c5_i72)) {
          emlrtDynamicBoundsCheckR2012b(c5_childIdx, 1, c5_i72, &c5_jf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i73 = c5_A->size[1];
        if ((c5_parentIdx < 1) || (c5_parentIdx > c5_i73)) {
          emlrtDynamicBoundsCheckR2012b(c5_parentIdx, 1, c5_i73, &c5_kf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_A->vector.data[(c5_childIdx + c5_A->size[0] * (c5_parentIdx - 1)) - 1]
          = c5_isInside.vector.data[c5_i71 - 1];
      }
    }
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_on);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_dotProd);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_signCrossProd);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_translatedPolygon_y);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_translatedPolygon_x);
  c5_array_int32_T_Destructor(chartInstance, &c5_ii);
  c5_array_boolean_T_Destructor(chartInstance, &c5_in);
  c5_array_real_T_Destructor(chartInstance, &c5_closedPolygon_y);
  c5_array_real_T_Destructor(chartInstance, &c5_closedPolygon_x);
  c5_array_boolean_T_Destructor(chartInstance, &c5_onMask);
  c5_array_real_T_Destructor(chartInstance, &c5_inBoundsPoints_y);
  c5_array_real_T_Destructor(chartInstance, &c5_inBoundsPoints_x);
  c5_array_real_T_Destructor(chartInstance, &c5_inBoundsPointsIdx);
  c5_array_boolean_T_Destructor(chartInstance, &c5_mask);
  c5_array_real_T_Destructor(chartInstance, &c5_points_y);
  c5_array_real_T_Destructor(chartInstance, &c5_points_x);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_boundary);
  c5_array_int32_T_Destructor(chartInstance, &c5_numElemsPerGroup);
  c5_array_int32_T_Destructor(chartInstance, &c5_groupedIndices);
  c5_array_boolean_T_2D_Destructor(chartInstance, &c5_isInside);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_sampChildren);
  c5_array_int32_T_Destructor(chartInstance, &c5_childrenIdx);
  c5_array_int32_T_Destructor(chartInstance, &c5_parentsIdx);
}

static void c5_groupBoundariesByTreeLevelCodegen
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_cell_wrap_0 *c5_B, int32_T c5_numObjs, int32_T
   *c5_numLevels, c5_coder_array_int32_T *c5_groupedIndices,
   c5_coder_array_int32_T *c5_numElemsPerGroup)
{
  c5_coder_array_boolean_T c5_isOutermostObject;
  c5_coder_array_boolean_T c5_skipHoleBoundary;
  c5_coder_array_boolean_T c5_skipObjectBoundary;
  c5_coder_array_int32_T_2D c5_holeIdx;
  c5_coder_array_int32_T_2D c5_objectIdx;
  c5_coder_array_int32_T_2D c5_objectsAtThatLevel;
  c5_coder_array_real_T c5_b_boundary;
  c5_coder_array_real_T c5_c_boundary;
  c5_coder_array_real_T c5_d_boundary;
  c5_coder_array_real_T c5_e_boundary;
  c5_coder_array_real_T_2D c5_boundary;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_st;
  real_T c5_dv[2];
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_d;
  real_T c5_d1;
  real_T c5_x;
  real_T c5_y;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_b_d;
  int32_T c5_b_end;
  int32_T c5_b_endIdx;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_m;
  int32_T c5_b_n;
  int32_T c5_b_numLevels;
  int32_T c5_b_partialTrueCount;
  int32_T c5_b_trueCount;
  int32_T c5_bi;
  int32_T c5_bma;
  int32_T c5_c_P;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_i;
  int32_T c5_c_loop_ub;
  int32_T c5_c_m;
  int32_T c5_c_n;
  int32_T c5_currentGroupIdx;
  int32_T c5_d;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_d_i;
  int32_T c5_d_loop_ub;
  int32_T c5_d_n;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_end;
  int32_T c5_endIdx;
  int32_T c5_f_a;
  int32_T c5_f_b;
  int32_T c5_f_loop_ub;
  int32_T c5_g_a;
  int32_T c5_g_b;
  int32_T c5_g_loop_ub;
  int32_T c5_h_a;
  int32_T c5_h_b;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_a;
  int32_T c5_i_b;
  int32_T c5_i_loop_ub;
  int32_T c5_j_a;
  int32_T c5_j_b;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_a;
  int32_T c5_k_b;
  int32_T c5_k_loop_ub;
  int32_T c5_l_a;
  int32_T c5_l_b;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m;
  int32_T c5_m_a;
  int32_T c5_m_b;
  int32_T c5_m_loop_ub;
  int32_T c5_n;
  int32_T c5_n_a;
  int32_T c5_n_b;
  int32_T c5_n_loop_ub;
  int32_T c5_nm1;
  int32_T c5_numElems;
  int32_T c5_numHoles;
  int32_T c5_o_a;
  int32_T c5_o_b;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_partialTrueCount;
  int32_T c5_q_b;
  int32_T c5_q_loop_ub;
  int32_T c5_r_b;
  int32_T c5_r_loop_ub;
  int32_T c5_s_b;
  int32_T c5_span;
  int32_T c5_startHoleIdx;
  int32_T c5_startIdx;
  int32_T c5_t_b;
  int32_T c5_totalNumElems;
  int32_T c5_trueCount;
  int32_T c5_u_b;
  int32_T c5_yk;
  boolean_T c5_b1;
  boolean_T c5_b_overflow;
  boolean_T c5_b_surrounded;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_done;
  boolean_T c5_e_overflow;
  boolean_T c5_exitg1;
  boolean_T c5_findHole;
  boolean_T c5_overflow;
  boolean_T c5_p_b;
  boolean_T c5_processHoles;
  boolean_T c5_surrounded;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_c_P = c5_B->size[0];
  c5_st.site = &c5_wi_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_groupedIndices,
    &c5_sc_emlrtRTEI, c5_c_P);
  c5_loop_ub = c5_c_P - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_groupedIndices->vector.data[c5_i] = 0;
  }

  c5_st.site = &c5_vi_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_numElemsPerGroup,
    &c5_tc_emlrtRTEI, c5_c_P);
  c5_b_loop_ub = c5_c_P - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_numElemsPerGroup->vector.data[c5_i1] = 0;
  }

  c5_b_numLevels = 0;
  if (c5_c_P >= 1) {
    c5_numHoles = c5_c_P - c5_numObjs;
    c5_processHoles = (c5_numHoles > 0);
    c5_st.site = &c5_de_emlrtRSI;
    c5_d = c5_numObjs;
    c5_b_st.site = &c5_cd_emlrtRSI;
    c5_c_b = c5_d;
    c5_c_st.site = &c5_ie_emlrtRSI;
    c5_d_b = c5_c_b;
    c5_a = c5_d_b;
    c5_bi = c5_a;
    c5_d_st.site = &c5_je_emlrtRSI;
    c5_e_b = c5_bi;
    c5_f_b = c5_e_b;
    c5_g_b = c5_f_b;
    if (c5_g_b < 1) {
      c5_n = 0;
    } else {
      c5_b_a = c5_g_b - 1;
      c5_bma = c5_b_a;
      c5_c_a = c5_bma;
      c5_span = c5_c_a;
      c5_d_a = c5_span;
      c5_nm1 = c5_d_a;
      c5_e_a = c5_nm1;
      c5_h_b = c5_e_a;
      c5_f_a = c5_h_b + 1;
      c5_n = c5_f_a;
    }

    c5_array_int32_T_2D_Constructor(chartInstance, &c5_objectIdx);
    c5_array_int32_T_2D_SetSize(chartInstance, &c5_d_st, &c5_objectIdx,
      &c5_uc_emlrtRTEI, 1, c5_n);
    if (c5_n > 0) {
      c5_objectIdx.vector.data[0] = 1;
      c5_yk = 1;
      c5_e_st.site = &c5_ke_emlrtRSI;
      c5_i_b = c5_n;
      c5_j_b = c5_i_b;
      if (c5_j_b < 2) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_j_b > 2147483646);
      }

      if (c5_overflow) {
        c5_f_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_f_st);
      }

      for (c5_k = 2; c5_k <= c5_n; c5_k++) {
        c5_i_a = c5_yk + 1;
        c5_yk = c5_i_a;
        c5_objectIdx.vector.data[c5_k - 1] = c5_yk;
      }
    }

    c5_startHoleIdx = c5_numObjs + 1;
    c5_st.site = &c5_ee_emlrtRSI;
    c5_g_a = c5_startHoleIdx;
    c5_b_d = c5_c_P;
    c5_b_st.site = &c5_cd_emlrtRSI;
    c5_h_a = c5_g_a;
    c5_k_b = c5_b_d;
    c5_array_int32_T_2D_Constructor(chartInstance, &c5_holeIdx);
    c5_c_st.site = &c5_ie_emlrtRSI;
    c5_eml_integer_colon_dispatcher(chartInstance, &c5_c_st, c5_h_a, c5_k_b,
      &c5_holeIdx);
    c5_array_boolean_T_Constructor(chartInstance, &c5_skipHoleBoundary);
    c5_c_d = (real_T)c5_numHoles;
    if (!(c5_c_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c5_c_d, &c5_p_emlrtDCI, (emlrtConstCTX)c5_sp);
    }

    c5_st.site = &c5_ak_emlrtRSI;
    c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_skipHoleBoundary,
      &c5_vc_emlrtRTEI, (int32_T)muDoubleScalarFloor(c5_c_d));
    c5_d1 = (real_T)c5_numHoles;
    if (!(c5_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c5_d1, &c5_p_emlrtDCI, (emlrtConstCTX)c5_sp);
    }

    c5_c_loop_ub = (int32_T)muDoubleScalarFloor(c5_d1) - 1;
    for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
      c5_skipHoleBoundary.vector.data[c5_i2] = false;
    }

    c5_array_boolean_T_Constructor(chartInstance, &c5_skipObjectBoundary);
    c5_st.site = &c5_yj_emlrtRSI;
    c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_skipObjectBoundary,
      &c5_wc_emlrtRTEI, c5_numObjs);
    c5_d_loop_ub = c5_numObjs - 1;
    for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
      c5_skipObjectBoundary.vector.data[c5_i3] = false;
    }

    c5_done = false;
    c5_findHole = false;
    c5_currentGroupIdx = 1;
    c5_totalNumElems = 0;
    c5_array_boolean_T_Constructor(chartInstance, &c5_isOutermostObject);
    c5_array_int32_T_2D_Constructor(chartInstance, &c5_objectsAtThatLevel);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_boundary);
    c5_array_real_T_Constructor(chartInstance, &c5_b_boundary);
    c5_array_real_T_Constructor(chartInstance, &c5_c_boundary);
    c5_array_real_T_Constructor(chartInstance, &c5_d_boundary);
    c5_array_real_T_Constructor(chartInstance, &c5_e_boundary);
    while (!c5_done) {
      if (c5_findHole) {
        c5_st.site = &c5_fe_emlrtRSI;
        c5_startIdx = c5_startHoleIdx;
        c5_b_endIdx = c5_c_P;
        c5_dv[0] = (real_T)c5_skipHoleBoundary.size[0];
        c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_isOutermostObject,
          &c5_ed_emlrtRTEI, (int32_T)c5_dv[0]);
        c5_f_loop_ub = (int32_T)c5_dv[0] - 1;
        for (c5_i5 = 0; c5_i5 <= c5_f_loop_ub; c5_i5++) {
          c5_isOutermostObject.vector.data[c5_i5] = false;
        }

        c5_b_st.site = &c5_ne_emlrtRSI;
        c5_j_a = c5_startIdx;
        c5_n_b = c5_b_endIdx;
        c5_k_a = c5_j_a;
        c5_o_b = c5_n_b;
        if (c5_k_a > c5_o_b) {
          c5_c_overflow = false;
        } else {
          c5_c_overflow = (c5_o_b > 2147483646);
        }

        if (c5_c_overflow) {
          c5_c_st.site = &c5_lb_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
        }

        for (c5_c_m = c5_startIdx; c5_c_m <= c5_b_endIdx; c5_c_m++) {
          c5_i10 = c5_skipHoleBoundary.size[0];
          c5_i12 = (c5_c_m - c5_startIdx) + 1;
          if ((c5_i12 < 1) || (c5_i12 > c5_i10)) {
            emlrtDynamicBoundsCheckR2012b(c5_i12, 1, c5_i10, &c5_gg_emlrtBCI,
              &c5_st);
          }

          if (!c5_skipHoleBoundary.vector.data[c5_i12 - 1]) {
            c5_i16 = c5_B->size[0] - 1;
            c5_i19 = c5_c_m - 1;
            if ((c5_i19 < 0) || (c5_i19 > c5_i16)) {
              emlrtDynamicBoundsCheckR2012b(c5_i19, 0, c5_i16, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_i22 = c5_i19;
            c5_i24 = c5_B->vector.data[c5_i22].f1.size[0];
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
              &c5_yc_emlrtRTEI, c5_i24, 2);
            c5_i25 = c5_B->size[0] - 1;
            c5_i27 = c5_c_m - 1;
            if ((c5_i27 < 0) || (c5_i27 > c5_i25)) {
              emlrtDynamicBoundsCheckR2012b(c5_i27, 0, c5_i25, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_i32 = c5_i27;
            c5_i33 = c5_B->size[0] - 1;
            c5_i36 = c5_c_m - 1;
            if ((c5_i36 < 0) || (c5_i36 > c5_i33)) {
              emlrtDynamicBoundsCheckR2012b(c5_i36, 0, c5_i33, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_j_loop_ub = (c5_B->vector.data[c5_i32].f1.size[0] << 1) - 1;
            for (c5_i45 = 0; c5_i45 <= c5_j_loop_ub; c5_i45++) {
              c5_i51 = c5_B->size[0] - 1;
              c5_i53 = c5_c_m - 1;
              if ((c5_i53 < 0) || (c5_i53 > c5_i51)) {
                emlrtDynamicBoundsCheckR2012b(c5_i53, 0, c5_i51, &c5_eg_emlrtBCI,
                  &c5_st);
              }

              c5_boundary.vector.data[c5_i45] = c5_B->vector.data[c5_i53].
                f1.vector.data[c5_i45];
            }

            c5_i50 = c5_boundary.size[0];
            c5_i52 = 1;
            if ((c5_i52 < 1) || (c5_i52 > c5_i50)) {
              emlrtDynamicBoundsCheckR2012b(c5_i52, 1, c5_i50, &c5_cg_emlrtBCI,
                &c5_st);
            }

            c5_b_x = c5_boundary.vector.data[c5_boundary.size[0]];
            c5_i63 = c5_boundary.size[0];
            c5_i66 = 1;
            if ((c5_i66 < 1) || (c5_i66 > c5_i63)) {
              emlrtDynamicBoundsCheckR2012b(c5_i66, 1, c5_i63, &c5_dg_emlrtBCI,
                &c5_st);
            }

            c5_b_y = c5_boundary.vector.data[0];
            c5_b_surrounded = false;
            c5_b_st.site = &c5_oe_emlrtRSI;
            c5_m_a = c5_startIdx;
            c5_t_b = c5_b_endIdx;
            c5_o_a = c5_m_a;
            c5_u_b = c5_t_b;
            if (c5_o_a > c5_u_b) {
              c5_e_overflow = false;
            } else {
              c5_e_overflow = (c5_u_b > 2147483646);
            }

            if (c5_e_overflow) {
              c5_c_st.site = &c5_lb_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
            }

            c5_d_n = c5_startIdx;
            c5_exitg1 = false;
            while ((!c5_exitg1) && (c5_d_n <= c5_b_endIdx)) {
              c5_i73 = c5_skipHoleBoundary.size[0];
              c5_i76 = (c5_d_n - c5_startIdx) + 1;
              if ((c5_i76 < 1) || (c5_i76 > c5_i73)) {
                emlrtDynamicBoundsCheckR2012b(c5_i76, 1, c5_i73, &c5_mg_emlrtBCI,
                  &c5_st);
              }

              if ((!c5_skipHoleBoundary.vector.data[c5_i76 - 1]) && (c5_d_n !=
                   c5_c_m)) {
                c5_i79 = c5_B->size[0] - 1;
                c5_i80 = c5_d_n - 1;
                if ((c5_i80 < 0) || (c5_i80 > c5_i79)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i80, 0, c5_i79,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_i83 = c5_i80;
                c5_i84 = c5_B->vector.data[c5_i83].f1.size[0];
                c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
                  &c5_ad_emlrtRTEI, c5_i84, 2);
                c5_i87 = c5_B->size[0] - 1;
                c5_i89 = c5_d_n - 1;
                if ((c5_i89 < 0) || (c5_i89 > c5_i87)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i89, 0, c5_i87,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_i90 = c5_i89;
                c5_i92 = c5_B->size[0] - 1;
                c5_i93 = c5_d_n - 1;
                if ((c5_i93 < 0) || (c5_i93 > c5_i92)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i93, 0, c5_i92,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_o_loop_ub = (c5_B->vector.data[c5_i90].f1.size[0] << 1) - 1;
                for (c5_i97 = 0; c5_i97 <= c5_o_loop_ub; c5_i97++) {
                  c5_i98 = c5_B->size[0] - 1;
                  c5_i100 = c5_d_n - 1;
                  if ((c5_i100 < 0) || (c5_i100 > c5_i98)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i100, 0, c5_i98,
                      &c5_fg_emlrtBCI, &c5_st);
                  }

                  c5_boundary.vector.data[c5_i97] = c5_B->vector.data[c5_i100].
                    f1.vector.data[c5_i97];
                }

                c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_d_boundary,
                  &c5_bd_emlrtRTEI, c5_boundary.size[0]);
                c5_q_loop_ub = c5_boundary.size[0] - 1;
                for (c5_i101 = 0; c5_i101 <= c5_q_loop_ub; c5_i101++) {
                  c5_d_boundary.vector.data[c5_i101] =
                    c5_boundary.vector.data[c5_i101 + c5_boundary.size[0]];
                }

                c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_e_boundary,
                  &c5_cd_emlrtRTEI, c5_boundary.size[0]);
                c5_r_loop_ub = c5_boundary.size[0] - 1;
                for (c5_i102 = 0; c5_i102 <= c5_r_loop_ub; c5_i102++) {
                  c5_e_boundary.vector.data[c5_i102] =
                    c5_boundary.vector.data[c5_i102];
                }

                c5_b_st.site = &c5_pe_emlrtRSI;
                if (c5_inpolygon(chartInstance, &c5_b_st, c5_b_x, c5_b_y,
                                 &c5_d_boundary, &c5_e_boundary)) {
                  c5_b_surrounded = true;
                  c5_exitg1 = true;
                } else {
                  c5_d_n++;
                }
              } else {
                c5_d_n++;
              }
            }

            c5_i72 = c5_isOutermostObject.size[0];
            c5_i75 = (c5_c_m - c5_startIdx) + 1;
            if ((c5_i75 < 1) || (c5_i75 > c5_i72)) {
              emlrtDynamicBoundsCheckR2012b(c5_i75, 1, c5_i72, &c5_lg_emlrtBCI,
                &c5_st);
            }

            c5_isOutermostObject.vector.data[c5_i75 - 1] = !c5_b_surrounded;
          }
        }

        c5_i9 = c5_skipHoleBoundary.size[0];
        c5_i11 = c5_isOutermostObject.size[0];
        if ((c5_i9 != c5_i11) && ((c5_i9 != 1) && (c5_i11 != 1))) {
          emlrtDimSizeImpxCheckR2021b(c5_i9, c5_i11, &c5_g_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_skipHoleBoundary.size[0] == c5_isOutermostObject.size[0]) {
          c5_h_loop_ub = c5_skipHoleBoundary.size[0] - 1;
          for (c5_i18 = 0; c5_i18 <= c5_h_loop_ub; c5_i18++) {
            c5_skipHoleBoundary.vector.data[c5_i18] =
              (c5_skipHoleBoundary.vector.data[c5_i18] ||
               c5_isOutermostObject.vector.data[c5_i18]);
          }
        } else {
          c5_st.site = &c5_gk_emlrtRSI;
          c5_or(chartInstance, &c5_st, &c5_skipHoleBoundary,
                &c5_isOutermostObject);
        }

        c5_b_end = c5_isOutermostObject.size[0];
        c5_b_trueCount = 0;
        for (c5_c_i = 0; c5_c_i < c5_b_end; c5_c_i++) {
          if (c5_isOutermostObject.vector.data[c5_c_i]) {
            c5_b_trueCount++;
          }
        }

        c5_st.site = &c5_dk_emlrtRSI;
        c5_array_int32_T_2D_SetSize(chartInstance, &c5_st,
          &c5_objectsAtThatLevel, &c5_dd_emlrtRTEI, 1, c5_b_trueCount);
        c5_b_partialTrueCount = 0;
        for (c5_e_i = 0; c5_e_i < c5_b_end; c5_e_i++) {
          if (c5_isOutermostObject.vector.data[c5_e_i]) {
            c5_i35 = c5_holeIdx.size[1] - 1;
            if ((c5_e_i < 0) || (c5_e_i > c5_i35)) {
              emlrtDynamicBoundsCheckR2012b(c5_e_i, 0, c5_i35, &c5_kg_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_objectsAtThatLevel.vector.data[c5_b_partialTrueCount] =
              c5_holeIdx.vector.data[c5_e_i];
            c5_b_partialTrueCount++;
          }
        }

        c5_numElems = c5_objectsAtThatLevel.size[1];
        c5_i34 = c5_numElemsPerGroup->size[0];
        if ((c5_currentGroupIdx < 1) || (c5_currentGroupIdx > c5_i34)) {
          emlrtDynamicBoundsCheckR2012b(c5_currentGroupIdx, 1, c5_i34,
            &c5_jg_emlrtBCI, (emlrtConstCTX)c5_sp);
        }

        c5_numElemsPerGroup->vector.data[c5_currentGroupIdx - 1] = c5_numElems;
        c5_i44 = c5_totalNumElems + 1;
        c5_i48 = c5_totalNumElems + c5_numElems;
        c5_b1 = (c5_i44 > c5_i48);
        if (c5_b1) {
          c5_i57 = 0;
          c5_i61 = 0;
        } else {
          c5_i56 = c5_groupedIndices->size[0];
          if ((c5_i44 < 1) || (c5_i44 > c5_i56)) {
            emlrtDynamicBoundsCheckR2012b(c5_i44, 1, c5_i56, &c5_xf_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i57 = c5_i44 - 1;
          c5_i64 = c5_groupedIndices->size[0];
          if ((c5_i48 < 1) || (c5_i48 > c5_i64)) {
            emlrtDynamicBoundsCheckR2012b(c5_i48, 1, c5_i64, &c5_yf_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i61 = c5_i48;
        }

        c5_i62 = c5_i61 - c5_i57;
        c5_i65 = c5_objectsAtThatLevel.size[1];
        if (c5_i62 != c5_i65) {
          emlrtSubAssignSizeCheck1dR2017a(c5_i62, c5_i65, &c5_i_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        c5_l_loop_ub = c5_objectsAtThatLevel.size[1] - 1;
        for (c5_i68 = 0; c5_i68 <= c5_l_loop_ub; c5_i68++) {
          c5_groupedIndices->vector.data[c5_i57 + c5_i68] =
            c5_objectsAtThatLevel.vector.data[c5_i68];
        }
      } else {
        c5_st.site = &c5_ge_emlrtRSI;
        c5_endIdx = c5_numObjs;
        c5_dv[0] = (real_T)c5_skipObjectBoundary.size[0];
        c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_isOutermostObject,
          &c5_xc_emlrtRTEI, (int32_T)c5_dv[0]);
        c5_e_loop_ub = (int32_T)c5_dv[0] - 1;
        for (c5_i4 = 0; c5_i4 <= c5_e_loop_ub; c5_i4++) {
          c5_isOutermostObject.vector.data[c5_i4] = false;
        }

        c5_b_st.site = &c5_ne_emlrtRSI;
        c5_l_b = c5_endIdx;
        c5_m_b = c5_l_b;
        if (c5_m_b < 1) {
          c5_b_overflow = false;
        } else {
          c5_b_overflow = (c5_m_b > 2147483646);
        }

        if (c5_b_overflow) {
          c5_c_st.site = &c5_lb_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
        }

        for (c5_m = 0; c5_m < c5_endIdx; c5_m++) {
          c5_b_m = c5_m + 1;
          c5_i8 = c5_skipObjectBoundary.size[0];
          if ((c5_b_m < 1) || (c5_b_m > c5_i8)) {
            emlrtDynamicBoundsCheckR2012b(c5_b_m, 1, c5_i8, &c5_gg_emlrtBCI,
              &c5_st);
          }

          if (!c5_skipObjectBoundary.vector.data[c5_b_m - 1]) {
            c5_i13 = c5_B->size[0] - 1;
            c5_i15 = c5_b_m - 1;
            if ((c5_i15 < 0) || (c5_i15 > c5_i13)) {
              emlrtDynamicBoundsCheckR2012b(c5_i15, 0, c5_i13, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_i17 = c5_i15;
            c5_i20 = c5_B->vector.data[c5_i17].f1.size[0];
            c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
              &c5_yc_emlrtRTEI, c5_i20, 2);
            c5_i21 = c5_B->size[0] - 1;
            c5_i23 = c5_b_m - 1;
            if ((c5_i23 < 0) || (c5_i23 > c5_i21)) {
              emlrtDynamicBoundsCheckR2012b(c5_i23, 0, c5_i21, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_i26 = c5_i23;
            c5_i28 = c5_B->size[0] - 1;
            c5_i31 = c5_b_m - 1;
            if ((c5_i31 < 0) || (c5_i31 > c5_i28)) {
              emlrtDynamicBoundsCheckR2012b(c5_i31, 0, c5_i28, &c5_eg_emlrtBCI,
                &c5_st);
            }

            c5_i_loop_ub = (c5_B->vector.data[c5_i26].f1.size[0] << 1) - 1;
            for (c5_i38 = 0; c5_i38 <= c5_i_loop_ub; c5_i38++) {
              c5_i41 = c5_B->size[0] - 1;
              c5_i43 = c5_b_m - 1;
              if ((c5_i43 < 0) || (c5_i43 > c5_i41)) {
                emlrtDynamicBoundsCheckR2012b(c5_i43, 0, c5_i41, &c5_eg_emlrtBCI,
                  &c5_st);
              }

              c5_boundary.vector.data[c5_i38] = c5_B->vector.data[c5_i43].
                f1.vector.data[c5_i38];
            }

            c5_i40 = c5_boundary.size[0];
            c5_i42 = 1;
            if ((c5_i42 < 1) || (c5_i42 > c5_i40)) {
              emlrtDynamicBoundsCheckR2012b(c5_i42, 1, c5_i40, &c5_cg_emlrtBCI,
                &c5_st);
            }

            c5_x = c5_boundary.vector.data[c5_boundary.size[0]];
            c5_i55 = c5_boundary.size[0];
            c5_i60 = 1;
            if ((c5_i60 < 1) || (c5_i60 > c5_i55)) {
              emlrtDynamicBoundsCheckR2012b(c5_i60, 1, c5_i55, &c5_dg_emlrtBCI,
                &c5_st);
            }

            c5_y = c5_boundary.vector.data[0];
            c5_surrounded = false;
            c5_b_st.site = &c5_oe_emlrtRSI;
            c5_q_b = c5_endIdx;
            c5_r_b = c5_q_b;
            if (c5_r_b < 1) {
              c5_d_overflow = false;
            } else {
              c5_d_overflow = (c5_r_b > 2147483646);
            }

            if (c5_d_overflow) {
              c5_c_st.site = &c5_lb_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
            }

            c5_b_n = 1;
            c5_exitg1 = false;
            while ((!c5_exitg1) && (c5_b_n - 1 <= c5_endIdx - 1)) {
              c5_c_n = c5_b_n;
              c5_i70 = c5_skipObjectBoundary.size[0];
              if ((c5_c_n < 1) || (c5_c_n > c5_i70)) {
                emlrtDynamicBoundsCheckR2012b(c5_c_n, 1, c5_i70, &c5_mg_emlrtBCI,
                  &c5_st);
              }

              if ((!c5_skipObjectBoundary.vector.data[c5_c_n - 1]) && (c5_c_n !=
                   c5_b_m)) {
                c5_i71 = c5_B->size[0] - 1;
                c5_i74 = c5_c_n - 1;
                if ((c5_i74 < 0) || (c5_i74 > c5_i71)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i74, 0, c5_i71,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_i77 = c5_i74;
                c5_i78 = c5_B->vector.data[c5_i77].f1.size[0];
                c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_boundary,
                  &c5_ad_emlrtRTEI, c5_i78, 2);
                c5_i81 = c5_B->size[0] - 1;
                c5_i82 = c5_c_n - 1;
                if ((c5_i82 < 0) || (c5_i82 > c5_i81)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i82, 0, c5_i81,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_i85 = c5_i82;
                c5_i86 = c5_B->size[0] - 1;
                c5_i88 = c5_c_n - 1;
                if ((c5_i88 < 0) || (c5_i88 > c5_i86)) {
                  emlrtDynamicBoundsCheckR2012b(c5_i88, 0, c5_i86,
                    &c5_fg_emlrtBCI, &c5_st);
                }

                c5_m_loop_ub = (c5_B->vector.data[c5_i85].f1.size[0] << 1) - 1;
                for (c5_i91 = 0; c5_i91 <= c5_m_loop_ub; c5_i91++) {
                  c5_i94 = c5_B->size[0] - 1;
                  c5_i95 = c5_c_n - 1;
                  if ((c5_i95 < 0) || (c5_i95 > c5_i94)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i95, 0, c5_i94,
                      &c5_fg_emlrtBCI, &c5_st);
                  }

                  c5_boundary.vector.data[c5_i91] = c5_B->vector.data[c5_i95].
                    f1.vector.data[c5_i91];
                }

                c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_b_boundary,
                  &c5_bd_emlrtRTEI, c5_boundary.size[0]);
                c5_n_loop_ub = c5_boundary.size[0] - 1;
                for (c5_i96 = 0; c5_i96 <= c5_n_loop_ub; c5_i96++) {
                  c5_b_boundary.vector.data[c5_i96] =
                    c5_boundary.vector.data[c5_i96 + c5_boundary.size[0]];
                }

                c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_c_boundary,
                  &c5_cd_emlrtRTEI, c5_boundary.size[0]);
                c5_p_loop_ub = c5_boundary.size[0] - 1;
                for (c5_i99 = 0; c5_i99 <= c5_p_loop_ub; c5_i99++) {
                  c5_c_boundary.vector.data[c5_i99] =
                    c5_boundary.vector.data[c5_i99];
                }

                c5_b_st.site = &c5_pe_emlrtRSI;
                if (c5_inpolygon(chartInstance, &c5_b_st, c5_x, c5_y,
                                 &c5_b_boundary, &c5_c_boundary)) {
                  c5_surrounded = true;
                  c5_exitg1 = true;
                } else {
                  c5_b_n++;
                }
              } else {
                c5_b_n++;
              }
            }

            c5_i69 = c5_isOutermostObject.size[0];
            if ((c5_b_m < 1) || (c5_b_m > c5_i69)) {
              emlrtDynamicBoundsCheckR2012b(c5_b_m, 1, c5_i69, &c5_lg_emlrtBCI,
                &c5_st);
            }

            c5_isOutermostObject.vector.data[c5_b_m - 1] = !c5_surrounded;
          }
        }

        c5_i6 = c5_skipObjectBoundary.size[0];
        c5_i7 = c5_isOutermostObject.size[0];
        if ((c5_i6 != c5_i7) && ((c5_i6 != 1) && (c5_i7 != 1))) {
          emlrtDimSizeImpxCheckR2021b(c5_i6, c5_i7, &c5_h_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_skipObjectBoundary.size[0] == c5_isOutermostObject.size[0]) {
          c5_g_loop_ub = c5_skipObjectBoundary.size[0] - 1;
          for (c5_i14 = 0; c5_i14 <= c5_g_loop_ub; c5_i14++) {
            c5_skipObjectBoundary.vector.data[c5_i14] =
              (c5_skipObjectBoundary.vector.data[c5_i14] ||
               c5_isOutermostObject.vector.data[c5_i14]);
          }
        } else {
          c5_st.site = &c5_fk_emlrtRSI;
          c5_or(chartInstance, &c5_st, &c5_skipObjectBoundary,
                &c5_isOutermostObject);
        }

        c5_end = c5_isOutermostObject.size[0];
        c5_trueCount = 0;
        for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
          if (c5_isOutermostObject.vector.data[c5_b_i]) {
            c5_trueCount++;
          }
        }

        c5_st.site = &c5_ek_emlrtRSI;
        c5_array_int32_T_2D_SetSize(chartInstance, &c5_st,
          &c5_objectsAtThatLevel, &c5_dd_emlrtRTEI, 1, c5_trueCount);
        c5_partialTrueCount = 0;
        for (c5_d_i = 0; c5_d_i < c5_end; c5_d_i++) {
          if (c5_isOutermostObject.vector.data[c5_d_i]) {
            c5_i30 = c5_objectIdx.size[1] - 1;
            if ((c5_d_i < 0) || (c5_d_i > c5_i30)) {
              emlrtDynamicBoundsCheckR2012b(c5_d_i, 0, c5_i30, &c5_ig_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_objectsAtThatLevel.vector.data[c5_partialTrueCount] =
              c5_objectIdx.vector.data[c5_d_i];
            c5_partialTrueCount++;
          }
        }

        c5_numElems = c5_objectsAtThatLevel.size[1];
        c5_i29 = c5_numElemsPerGroup->size[0];
        if ((c5_currentGroupIdx < 1) || (c5_currentGroupIdx > c5_i29)) {
          emlrtDynamicBoundsCheckR2012b(c5_currentGroupIdx, 1, c5_i29,
            &c5_hg_emlrtBCI, (emlrtConstCTX)c5_sp);
        }

        c5_numElemsPerGroup->vector.data[c5_currentGroupIdx - 1] = c5_numElems;
        c5_i37 = c5_totalNumElems + 1;
        c5_i39 = c5_totalNumElems + c5_numElems;
        c5_p_b = (c5_i37 > c5_i39);
        if (c5_p_b) {
          c5_i47 = 0;
          c5_i49 = 0;
        } else {
          c5_i46 = c5_groupedIndices->size[0];
          if ((c5_i37 < 1) || (c5_i37 > c5_i46)) {
            emlrtDynamicBoundsCheckR2012b(c5_i37, 1, c5_i46, &c5_ag_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i47 = c5_i37 - 1;
          c5_i58 = c5_groupedIndices->size[0];
          if ((c5_i39 < 1) || (c5_i39 > c5_i58)) {
            emlrtDynamicBoundsCheckR2012b(c5_i39, 1, c5_i58, &c5_bg_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i49 = c5_i39;
        }

        c5_i54 = c5_i49 - c5_i47;
        c5_i59 = c5_objectsAtThatLevel.size[1];
        if (c5_i54 != c5_i59) {
          emlrtSubAssignSizeCheck1dR2017a(c5_i54, c5_i59, &c5_j_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        c5_k_loop_ub = c5_objectsAtThatLevel.size[1] - 1;
        for (c5_i67 = 0; c5_i67 <= c5_k_loop_ub; c5_i67++) {
          c5_groupedIndices->vector.data[c5_i47 + c5_i67] =
            c5_objectsAtThatLevel.vector.data[c5_i67];
        }
      }

      c5_l_a = c5_totalNumElems;
      c5_s_b = c5_numElems;
      c5_totalNumElems = c5_l_a + c5_s_b;
      c5_n_a = c5_currentGroupIdx + 1;
      c5_currentGroupIdx = c5_n_a;
      if (c5_processHoles) {
        c5_findHole = !c5_findHole;
      }

      c5_st.site = &c5_he_emlrtRSI;
      if (c5_all(chartInstance, &c5_st, &c5_skipHoleBoundary)) {
        c5_st.site = &c5_he_emlrtRSI;
        if (c5_all(chartInstance, &c5_st, &c5_skipObjectBoundary)) {
          c5_done = true;
        }
      }
    }

    c5_array_real_T_Destructor(chartInstance, &c5_e_boundary);
    c5_array_real_T_Destructor(chartInstance, &c5_d_boundary);
    c5_array_real_T_Destructor(chartInstance, &c5_c_boundary);
    c5_array_real_T_Destructor(chartInstance, &c5_b_boundary);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_boundary);
    c5_array_int32_T_2D_Destructor(chartInstance, &c5_objectsAtThatLevel);
    c5_array_boolean_T_Destructor(chartInstance, &c5_isOutermostObject);
    c5_array_boolean_T_Destructor(chartInstance, &c5_skipObjectBoundary);
    c5_array_boolean_T_Destructor(chartInstance, &c5_skipHoleBoundary);
    c5_array_int32_T_2D_Destructor(chartInstance, &c5_holeIdx);
    c5_array_int32_T_2D_Destructor(chartInstance, &c5_objectIdx);
    c5_b_numLevels = c5_currentGroupIdx - 1;
  }

  *c5_numLevels = c5_b_numLevels;
}

static void c5_eml_integer_colon_dispatcher
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, int32_T c5_a, int32_T c5_c_b, c5_coder_array_int32_T_2D *c5_y)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  int32_T c5_ai;
  int32_T c5_b_a;
  int32_T c5_bi;
  int32_T c5_bma;
  int32_T c5_c_a;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_f_a;
  int32_T c5_f_b;
  int32_T c5_g_a;
  int32_T c5_g_b;
  int32_T c5_h_a;
  int32_T c5_h_b;
  int32_T c5_i_a;
  int32_T c5_i_b;
  int32_T c5_j_a;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_k_a;
  int32_T c5_l_a;
  int32_T c5_n;
  int32_T c5_nm1;
  int32_T c5_span;
  int32_T c5_yk;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_b_a = c5_a;
  c5_ai = c5_b_a;
  c5_c_a = c5_c_b;
  c5_bi = c5_c_a;
  c5_st.site = &c5_je_emlrtRSI;
  c5_d_a = c5_ai;
  c5_d_b = c5_bi;
  c5_b_st.site = &c5_le_emlrtRSI;
  c5_e_a = c5_d_a;
  c5_e_b = c5_d_b;
  c5_c_st.site = &c5_me_emlrtRSI;
  c5_f_a = c5_e_a;
  c5_f_b = c5_e_b;
  if (c5_f_b < c5_f_a) {
    c5_n = 0;
  } else {
    c5_g_a = c5_f_b;
    c5_g_b = c5_f_a;
    c5_bma = c5_g_a - c5_g_b;
    if (c5_bma < 0) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c5_c_st, &c5_f_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
    }

    c5_h_a = c5_bma;
    c5_span = c5_h_a;
    c5_i_a = c5_span;
    c5_nm1 = c5_i_a;
    c5_j_a = c5_nm1;
    c5_j_b = c5_j_a;
    c5_k_a = c5_j_b + 1;
    c5_n = c5_k_a;
  }

  c5_array_int32_T_2D_SetSize(chartInstance, &c5_st, c5_y, &c5_uc_emlrtRTEI, 1,
    c5_n);
  if (c5_n > 0) {
    c5_y->vector.data[0] = c5_d_a;
    c5_yk = c5_d_a;
    c5_b_st.site = &c5_ke_emlrtRSI;
    c5_h_b = c5_n;
    c5_i_b = c5_h_b;
    if (c5_i_b < 2) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_i_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_k = 2; c5_k <= c5_n; c5_k++) {
      c5_l_a = c5_yk + 1;
      c5_yk = c5_l_a;
      c5_y->vector.data[c5_k - 1] = c5_yk;
    }
  }
}

static boolean_T c5_inpolygon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_points_x, real_T
  c5_points_y, c5_coder_array_real_T *c5_polygon_x, c5_coder_array_real_T
  *c5_polygon_y)
{
  static char_T c5_b_cv[2] = { 'X', 'V' };

  static char_T c5_b_cv1[2] = { 'Y', 'V' };

  c5_coder_array_boolean_T c5_b_in;
  c5_coder_array_boolean_T c5_on;
  c5_coder_array_real_T c5_closedPolygon_x;
  c5_coder_array_real_T c5_closedPolygon_y;
  c5_coder_array_real_T c5_scaledEps;
  c5_coder_array_real_T_2D c5_b_dotProd;
  c5_coder_array_real_T_2D c5_b_signCrossProd;
  c5_coder_array_real_T_2D c5_dotProd;
  c5_coder_array_real_T_2D c5_signCrossProd;
  c5_coder_array_real_T_2D c5_translatedPolygon_x;
  c5_coder_array_real_T_2D c5_translatedPolygon_y;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  real_T c5_inBoundsPointsIdx_data[1];
  real_T c5_inBoundsPoints_x_data[1];
  real_T c5_inBoundsPoints_y_data[1];
  real_T c5_b_maxval;
  real_T c5_b_minval;
  real_T c5_b_points_x;
  real_T c5_b_points_y;
  real_T c5_b_v;
  real_T c5_b_x;
  real_T c5_c_maxval;
  real_T c5_c_minval;
  real_T c5_c_points_x;
  real_T c5_c_points_y;
  real_T c5_c_x;
  real_T c5_d_maxval;
  real_T c5_d_minval;
  real_T c5_maxval;
  real_T c5_minval;
  real_T c5_numPoints;
  real_T c5_numVertices;
  real_T c5_x;
  real_T c5_xRange;
  real_T c5_y;
  real_T c5_yRange;
  int32_T c5_ii_size[2];
  int32_T c5_inBoundsPointsIdx_size[2];
  int32_T c5_inBoundsPoints_x_size[2];
  int32_T c5_inBoundsPoints_y_size[2];
  int32_T c5_ii_data[1];
  int32_T c5_tmp_data[1];
  int32_T c5_tmp_size[1];
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_c_i;
  int32_T c5_c_loop_ub;
  int32_T c5_d_i;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_end;
  int32_T c5_f_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_loop_ub;
  int32_T c5_p;
  int32_T c5_partialTrueCount;
  int32_T c5_trueCount;
  int32_T c5_v;
  boolean_T c5_bv[1];
  boolean_T c5_TF;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b_mask;
  boolean_T c5_c_b;
  boolean_T c5_d_x;
  boolean_T c5_e_x;
  boolean_T c5_f_x;
  boolean_T c5_f_y;
  boolean_T c5_fx;
  boolean_T c5_g_x;
  boolean_T c5_h_x;
  boolean_T c5_in;
  boolean_T c5_mask;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_qe_emlrtRSI;
  c5_x = c5_points_x;
  c5_y = c5_points_y;
  if ((real_T)c5_polygon_x->size[0] != (real_T)c5_polygon_y->size[0]) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 2),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 2),
                  false);
    sf_mex_call(&c5_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 3U, 14, c5_c_y, 14, c5_d_y, 14, c5_e_y)));
  }

  c5_b_x = c5_x;
  c5_b_points_x = c5_b_x;
  c5_c_x = c5_y;
  c5_b_points_y = c5_c_x;
  c5_st.site = &c5_re_emlrtRSI;
  c5_c_points_x = c5_b_points_x;
  c5_c_points_y = c5_b_points_y;
  c5_b_st.site = &c5_ye_emlrtRSI;
  c5_c_st.site = &c5_df_emlrtRSI;
  c5_d_st.site = &c5_ef_emlrtRSI;
  c5_minval = c5_minimum(chartInstance, &c5_d_st, c5_polygon_x);
  c5_c_b = (c5_c_points_x >= c5_minval);
  c5_b_st.site = &c5_af_emlrtRSI;
  c5_c_st.site = &c5_mf_emlrtRSI;
  c5_d_st.site = &c5_nf_emlrtRSI;
  c5_maxval = c5_maximum(chartInstance, &c5_d_st, c5_polygon_x);
  c5_b1 = (c5_c_points_x <= c5_maxval);
  c5_b2 = (c5_c_b && c5_b1);
  c5_b_st.site = &c5_bf_emlrtRSI;
  c5_c_st.site = &c5_df_emlrtRSI;
  c5_d_st.site = &c5_ef_emlrtRSI;
  c5_b_minval = c5_minimum(chartInstance, &c5_d_st, c5_polygon_y);
  c5_b3 = (c5_c_points_y >= c5_b_minval);
  c5_b4 = (c5_b2 && c5_b3);
  c5_b_st.site = &c5_cf_emlrtRSI;
  c5_c_st.site = &c5_mf_emlrtRSI;
  c5_d_st.site = &c5_nf_emlrtRSI;
  c5_b_maxval = c5_maximum(chartInstance, &c5_d_st, c5_polygon_y);
  c5_b5 = (c5_c_points_y <= c5_b_maxval);
  c5_mask = (c5_b4 && c5_b5);
  c5_d_x = c5_mask;
  c5_e_x = c5_d_x;
  if (!c5_e_x) {
    c5_b6 = true;
  } else {
    c5_b6 = false;
  }

  c5_f_y = !c5_b6;
  c5_TF = !c5_f_y;
  if (c5_TF) {
    c5_in = false;
  } else {
    c5_array_real_T_Constructor(chartInstance, &c5_closedPolygon_x);
    c5_array_real_T_Constructor(chartInstance, &c5_closedPolygon_y);
    c5_st.site = &c5_se_emlrtRSI;
    c5_closeLoops(chartInstance, &c5_st, c5_polygon_x, c5_polygon_y,
                  &c5_closedPolygon_x, &c5_closedPolygon_y);
    c5_st.site = &c5_te_emlrtRSI;
    c5_b_st.site = &c5_mf_emlrtRSI;
    c5_c_st.site = &c5_nf_emlrtRSI;
    c5_c_maxval = c5_maximum(chartInstance, &c5_c_st, &c5_closedPolygon_x);
    c5_st.site = &c5_te_emlrtRSI;
    c5_b_st.site = &c5_df_emlrtRSI;
    c5_c_st.site = &c5_ef_emlrtRSI;
    c5_c_minval = c5_minimum(chartInstance, &c5_c_st, &c5_closedPolygon_x);
    c5_xRange = c5_c_maxval - c5_c_minval;
    c5_st.site = &c5_ue_emlrtRSI;
    c5_b_st.site = &c5_mf_emlrtRSI;
    c5_c_st.site = &c5_nf_emlrtRSI;
    c5_d_maxval = c5_maximum(chartInstance, &c5_c_st, &c5_closedPolygon_y);
    c5_st.site = &c5_ue_emlrtRSI;
    c5_b_st.site = &c5_df_emlrtRSI;
    c5_c_st.site = &c5_ef_emlrtRSI;
    c5_d_minval = c5_minimum(chartInstance, &c5_c_st, &c5_closedPolygon_y);
    c5_yRange = c5_d_maxval - c5_d_minval;
    if ((c5_xRange < 1.0E-15) || (c5_yRange < 1.0E-15)) {
      c5_st.site = &c5_ve_emlrtRSI;
      c5_warning(chartInstance, &c5_st);
    }

    if ((c5_xRange > 1.0E+150) || (c5_yRange > 1.0E+150)) {
      c5_st.site = &c5_we_emlrtRSI;
      c5_b_warning(chartInstance, &c5_st);
    }

    c5_f_x = c5_mask;
    c5_g_x = c5_f_x;
    c5_h_x = c5_g_x;
    c5_fx = c5_h_x;
    if (c5_fx) {
      c5_ii_size[0] = 1;
      c5_ii_size[1] = 1;
      c5_ii_data[0] = 1;
    } else {
      c5_ii_size[0] = 0;
      c5_ii_size[1] = 0;
    }

    c5_inBoundsPointsIdx_size[0] = c5_ii_size[0];
    c5_inBoundsPointsIdx_size[1] = c5_ii_size[1];
    c5_loop_ub = c5_ii_size[0] * c5_ii_size[1] - 1;
    for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
      c5_inBoundsPointsIdx_data[c5_i] = (real_T)c5_ii_data[c5_i];
    }

    c5_inBoundsPoints_x_size[0] = c5_ii_size[0];
    c5_inBoundsPoints_x_size[1] = c5_ii_size[1];
    c5_b_loop_ub = c5_ii_size[0] * c5_ii_size[1] - 1;
    for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
      c5_inBoundsPoints_x_data[c5_i1] = c5_b_points_x;
    }

    c5_ii_size[0] = c5_inBoundsPointsIdx_size[0];
    c5_ii_size[1] = c5_inBoundsPointsIdx_size[1];
    c5_inBoundsPoints_y_size[0] = c5_ii_size[0];
    c5_inBoundsPoints_y_size[1] = c5_ii_size[1];
    c5_c_loop_ub = c5_ii_size[0] * c5_ii_size[1] - 1;
    for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
      c5_inBoundsPoints_y_data[c5_i2] = c5_b_points_y;
    }

    c5_st.site = &c5_xe_emlrtRSI;
    c5_b_st.site = &c5_hg_emlrtRSI;
    c5_numPoints = (real_T)(c5_inBoundsPoints_x_size[0] *
      c5_inBoundsPoints_x_size[1]);
    c5_numVertices = (real_T)c5_closedPolygon_x.size[0];
    c5_array_real_T_2D_Constructor(chartInstance, &c5_translatedPolygon_x);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_translatedPolygon_x,
      &c5_nc_emlrtRTEI, (int32_T)c5_numVertices, (int32_T)c5_numPoints);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_translatedPolygon_y);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_translatedPolygon_y,
      &c5_oc_emlrtRTEI, (int32_T)c5_numVertices, (int32_T)c5_numPoints);
    c5_i3 = (int32_T)c5_numPoints - 1;
    for (c5_p = 0; c5_p <= c5_i3; c5_p++) {
      c5_i4 = (int32_T)c5_numVertices - 1;
      for (c5_v = 0; c5_v <= c5_i4; c5_v++) {
        c5_b_v = (real_T)c5_v + 1.0;
        c5_i5 = c5_translatedPolygon_x.size[1];
        c5_i6 = 1;
        if ((c5_i6 < 1) || (c5_i6 > c5_i5)) {
          emlrtDynamicBoundsCheckR2012b(c5_i6, 1, c5_i5, &c5_qf_emlrtBCI,
            &c5_b_st);
        }

        c5_i7 = c5_inBoundsPoints_x_size[0] * c5_inBoundsPoints_x_size[1];
        c5_i8 = 1;
        if ((c5_i8 < 1) || (c5_i8 > c5_i7)) {
          emlrtDynamicBoundsCheckR2012b(c5_i8, 1, c5_i7, &c5_of_emlrtBCI,
            &c5_b_st);
        }

        c5_i9 = c5_closedPolygon_x.size[0];
        c5_i11 = (int32_T)c5_b_v;
        if ((c5_i11 < 1) || (c5_i11 > c5_i9)) {
          emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_i9, &c5_nf_emlrtBCI,
            &c5_b_st);
        }

        c5_i12 = c5_translatedPolygon_x.size[0];
        c5_i13 = (int32_T)c5_b_v;
        if ((c5_i13 < 1) || (c5_i13 > c5_i12)) {
          emlrtDynamicBoundsCheckR2012b(c5_i13, 1, c5_i12, &c5_pf_emlrtBCI,
            &c5_b_st);
        }

        c5_translatedPolygon_x.vector.data[c5_i13 - 1] =
          c5_closedPolygon_x.vector.data[c5_i11 - 1] - c5_inBoundsPoints_x_data
          [0];
        c5_i15 = c5_translatedPolygon_y.size[1];
        c5_i16 = 1;
        if ((c5_i16 < 1) || (c5_i16 > c5_i15)) {
          emlrtDynamicBoundsCheckR2012b(c5_i16, 1, c5_i15, &c5_uf_emlrtBCI,
            &c5_b_st);
        }

        c5_i17 = c5_inBoundsPoints_y_size[0] * c5_inBoundsPoints_y_size[1];
        c5_i18 = 1;
        if ((c5_i18 < 1) || (c5_i18 > c5_i17)) {
          emlrtDynamicBoundsCheckR2012b(c5_i18, 1, c5_i17, &c5_sf_emlrtBCI,
            &c5_b_st);
        }

        c5_i19 = c5_closedPolygon_y.size[0];
        c5_i20 = (int32_T)c5_b_v;
        if ((c5_i20 < 1) || (c5_i20 > c5_i19)) {
          emlrtDynamicBoundsCheckR2012b(c5_i20, 1, c5_i19, &c5_rf_emlrtBCI,
            &c5_b_st);
        }

        c5_i21 = c5_translatedPolygon_y.size[0];
        c5_i22 = (int32_T)c5_b_v;
        if ((c5_i22 < 1) || (c5_i22 > c5_i21)) {
          emlrtDynamicBoundsCheckR2012b(c5_i22, 1, c5_i21, &c5_tf_emlrtBCI,
            &c5_b_st);
        }

        c5_translatedPolygon_y.vector.data[c5_i22 - 1] =
          c5_closedPolygon_y.vector.data[c5_i20 - 1] - c5_inBoundsPoints_y_data
          [0];
      }
    }

    c5_array_real_T_Constructor(chartInstance, &c5_scaledEps);
    c5_b_st.site = &c5_ig_emlrtRSI;
    c5_computeScaledEps(chartInstance, &c5_b_st, &c5_closedPolygon_x,
                        &c5_closedPolygon_y, &c5_scaledEps);
    c5_array_real_T_Destructor(chartInstance, &c5_closedPolygon_y);
    c5_array_real_T_Destructor(chartInstance, &c5_closedPolygon_x);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_signCrossProd);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_dotProd);
    c5_b_st.site = &c5_jg_emlrtRSI;
    c5_computeCrossAndDotProducts(chartInstance, &c5_b_st,
      &c5_translatedPolygon_x, &c5_translatedPolygon_y, &c5_scaledEps,
      &c5_signCrossProd, &c5_dotProd);
    c5_array_real_T_Destructor(chartInstance, &c5_scaledEps);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_b_signCrossProd);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_b_signCrossProd,
      &c5_hd_emlrtRTEI, c5_signCrossProd.size[0], c5_signCrossProd.size[1]);
    c5_d_loop_ub = c5_signCrossProd.size[0] * c5_signCrossProd.size[1] - 1;
    for (c5_i10 = 0; c5_i10 <= c5_d_loop_ub; c5_i10++) {
      c5_b_signCrossProd.vector.data[c5_i10] =
        c5_signCrossProd.vector.data[c5_i10];
    }

    c5_array_real_T_2D_Destructor(chartInstance, &c5_signCrossProd);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_b_dotProd);
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_b_dotProd,
      &c5_id_emlrtRTEI, c5_dotProd.size[0], c5_dotProd.size[1]);
    c5_e_loop_ub = c5_dotProd.size[0] * c5_dotProd.size[1] - 1;
    for (c5_i14 = 0; c5_i14 <= c5_e_loop_ub; c5_i14++) {
      c5_b_dotProd.vector.data[c5_i14] = c5_dotProd.vector.data[c5_i14];
    }

    c5_array_real_T_2D_Destructor(chartInstance, &c5_dotProd);
    c5_array_boolean_T_Constructor(chartInstance, &c5_b_in);
    c5_b_st.site = &c5_kg_emlrtRSI;
    c5_findInsidePoints(chartInstance, &c5_b_st, &c5_translatedPolygon_x,
                        &c5_translatedPolygon_y, &c5_b_signCrossProd, &c5_b_in);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_translatedPolygon_y);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_translatedPolygon_x);
    c5_array_boolean_T_Constructor(chartInstance, &c5_on);
    c5_b_st.site = &c5_lg_emlrtRSI;
    c5_b_findBoundaryPoints(chartInstance, &c5_b_st, &c5_b_signCrossProd,
      &c5_b_dotProd, &c5_b_in, &c5_on);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_b_dotProd);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_b_signCrossProd);
    c5_end = c5_on.size[0];
    for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
      if (!c5_on.vector.data[c5_b_i]) {
        c5_i23 = c5_inBoundsPointsIdx_size[0] * c5_inBoundsPointsIdx_size[1] - 1;
        if ((c5_b_i < 0) || (c5_b_i > c5_i23)) {
          emlrtDynamicBoundsCheckR2012b(c5_b_i, 0, c5_i23, &c5_vf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }
      }
    }

    c5_array_boolean_T_Destructor(chartInstance, &c5_on);
    c5_bv[0] = c5_mask;
    c5_b_end = c5_b_in.size[0];
    c5_trueCount = 0;
    for (c5_c_i = 0; c5_c_i < c5_b_end; c5_c_i++) {
      if (!c5_b_in.vector.data[c5_c_i]) {
        c5_trueCount++;
      }
    }

    c5_tmp_size[0] = c5_trueCount;
    c5_partialTrueCount = 0;
    for (c5_d_i = 0; c5_d_i < c5_b_end; c5_d_i++) {
      if (!c5_b_in.vector.data[c5_d_i]) {
        c5_i24 = c5_inBoundsPointsIdx_size[0] * c5_inBoundsPointsIdx_size[1] - 1;
        if ((c5_d_i < 0) || (c5_d_i > c5_i24)) {
          emlrtDynamicBoundsCheckR2012b(c5_d_i, 0, c5_i24, &c5_wf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_tmp_data[c5_partialTrueCount] = (int32_T)
          c5_inBoundsPointsIdx_data[c5_d_i];
        c5_partialTrueCount++;
      }
    }

    c5_array_boolean_T_Destructor(chartInstance, &c5_b_in);
    c5_f_loop_ub = c5_tmp_size[0] - 1;
    for (c5_i25 = 0; c5_i25 <= c5_f_loop_ub; c5_i25++) {
      c5_bv[c5_tmp_data[c5_i25] - 1] = false;
    }

    c5_b_mask = c5_bv[0];
    c5_in = c5_b_mask;
  }

  return c5_in;
}

static real_T c5_minimum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_ex;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_ex;
  real_T c5_f_x;
  real_T c5_g_x;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_b_k;
  int32_T c5_b_last;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_last;
  int32_T c5_first;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i_b;
  int32_T c5_idx;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_last;
  int32_T c5_nx;
  boolean_T c5_b_overflow;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_k_b;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_st.site = &c5_ff_emlrtRSI;
  if ((c5_x->size[0] == 1) || ((real_T)c5_x->size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c5_st, &c5_h_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  if (!((real_T)c5_x->size[0] >= 1.0)) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_st, &c5_i_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_d_y)));
  }

  c5_b_st.site = &c5_gf_emlrtRSI;
  c5_c_st.site = &c5_hf_emlrtRSI;
  c5_last = c5_x->size[0] - 1;
  c5_a = c5_last;
  c5_c = c5_a + 1;
  c5_nx = c5_c;
  if (c5_nx <= 2) {
    if (c5_nx == 1) {
      c5_ex = c5_x->vector.data[0];
    } else if (c5_x->vector.data[0] > c5_x->vector.data[c5_last]) {
      c5_ex = c5_x->vector.data[c5_last];
    } else {
      c5_c_x = c5_x->vector.data[0];
      c5_d_b = muDoubleScalarIsNaN(c5_c_x);
      if (c5_d_b) {
        c5_e_x = c5_x->vector.data[c5_last];
        c5_f_b = muDoubleScalarIsNaN(c5_e_x);
        if (!c5_f_b) {
          c5_ex = c5_x->vector.data[c5_last];
        } else {
          c5_ex = c5_x->vector.data[0];
        }
      } else {
        c5_ex = c5_x->vector.data[0];
      }
    }
  } else {
    c5_d_st.site = &c5_jf_emlrtRSI;
    c5_b_last = c5_last + 1;
    c5_b_x = c5_x->vector.data[0];
    c5_d_x = c5_b_x;
    c5_e_b = muDoubleScalarIsNaN(c5_d_x);
    c5_p = !c5_e_b;
    if (c5_p) {
      c5_idx = 1;
    } else {
      c5_idx = 0;
      c5_e_st.site = &c5_kf_emlrtRSI;
      c5_g_b = c5_b_last;
      c5_h_b = c5_g_b;
      if (c5_h_b < 2) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_h_b > 2147483646);
      }

      if (c5_overflow) {
        c5_f_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_f_st);
      }

      c5_k = 2;
      c5_exitg1 = false;
      while ((!c5_exitg1) && (c5_k <= c5_b_last)) {
        c5_f_x = c5_x->vector.data[c5_k - 1];
        c5_g_x = c5_f_x;
        c5_k_b = muDoubleScalarIsNaN(c5_g_x);
        c5_b_p = !c5_k_b;
        if (c5_b_p) {
          c5_idx = c5_k;
          c5_exitg1 = true;
        } else {
          c5_k++;
        }
      }
    }

    if (c5_idx == 0) {
      c5_ex = c5_x->vector.data[0];
    } else {
      c5_d_st.site = &c5_if_emlrtRSI;
      c5_first = c5_idx - 1;
      c5_c_last = c5_last + 1;
      c5_b_ex = c5_x->vector.data[c5_first];
      c5_i = c5_first + 2;
      c5_e_st.site = &c5_lf_emlrtRSI;
      c5_b_a = c5_i;
      c5_i_b = c5_c_last;
      c5_c_a = c5_b_a;
      c5_j_b = c5_i_b;
      if (c5_c_a > c5_j_b) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_j_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_f_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_f_st);
      }

      for (c5_b_k = c5_i; c5_b_k <= c5_c_last; c5_b_k++) {
        if (c5_b_ex > c5_x->vector.data[c5_b_k - 1]) {
          c5_b_ex = c5_x->vector.data[c5_b_k - 1];
        }
      }

      c5_ex = c5_b_ex;
    }
  }

  return c5_ex;
}

static real_T c5_maximum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_ex;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_ex;
  real_T c5_f_x;
  real_T c5_g_x;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_b_k;
  int32_T c5_b_last;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_last;
  int32_T c5_first;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i_b;
  int32_T c5_idx;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_last;
  int32_T c5_nx;
  boolean_T c5_b_overflow;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_k_b;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_st.site = &c5_of_emlrtRSI;
  if ((c5_x->size[0] == 1) || ((real_T)c5_x->size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c5_st, &c5_h_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  if (!((real_T)c5_x->size[0] >= 1.0)) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_st, &c5_i_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_d_y)));
  }

  c5_b_st.site = &c5_pf_emlrtRSI;
  c5_c_st.site = &c5_qf_emlrtRSI;
  c5_last = c5_x->size[0] - 1;
  c5_a = c5_last;
  c5_c = c5_a + 1;
  c5_nx = c5_c;
  if (c5_nx <= 2) {
    if (c5_nx == 1) {
      c5_ex = c5_x->vector.data[0];
    } else if (c5_x->vector.data[0] < c5_x->vector.data[c5_last]) {
      c5_ex = c5_x->vector.data[c5_last];
    } else {
      c5_c_x = c5_x->vector.data[0];
      c5_d_b = muDoubleScalarIsNaN(c5_c_x);
      if (c5_d_b) {
        c5_e_x = c5_x->vector.data[c5_last];
        c5_f_b = muDoubleScalarIsNaN(c5_e_x);
        if (!c5_f_b) {
          c5_ex = c5_x->vector.data[c5_last];
        } else {
          c5_ex = c5_x->vector.data[0];
        }
      } else {
        c5_ex = c5_x->vector.data[0];
      }
    }
  } else {
    c5_d_st.site = &c5_jf_emlrtRSI;
    c5_b_last = c5_last + 1;
    c5_b_x = c5_x->vector.data[0];
    c5_d_x = c5_b_x;
    c5_e_b = muDoubleScalarIsNaN(c5_d_x);
    c5_p = !c5_e_b;
    if (c5_p) {
      c5_idx = 1;
    } else {
      c5_idx = 0;
      c5_e_st.site = &c5_kf_emlrtRSI;
      c5_g_b = c5_b_last;
      c5_h_b = c5_g_b;
      if (c5_h_b < 2) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_h_b > 2147483646);
      }

      if (c5_overflow) {
        c5_f_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_f_st);
      }

      c5_k = 2;
      c5_exitg1 = false;
      while ((!c5_exitg1) && (c5_k <= c5_b_last)) {
        c5_f_x = c5_x->vector.data[c5_k - 1];
        c5_g_x = c5_f_x;
        c5_k_b = muDoubleScalarIsNaN(c5_g_x);
        c5_b_p = !c5_k_b;
        if (c5_b_p) {
          c5_idx = c5_k;
          c5_exitg1 = true;
        } else {
          c5_k++;
        }
      }
    }

    if (c5_idx == 0) {
      c5_ex = c5_x->vector.data[0];
    } else {
      c5_d_st.site = &c5_if_emlrtRSI;
      c5_first = c5_idx - 1;
      c5_c_last = c5_last + 1;
      c5_b_ex = c5_x->vector.data[c5_first];
      c5_i = c5_first + 2;
      c5_e_st.site = &c5_lf_emlrtRSI;
      c5_b_a = c5_i;
      c5_i_b = c5_c_last;
      c5_c_a = c5_b_a;
      c5_j_b = c5_i_b;
      if (c5_c_a > c5_j_b) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_j_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_f_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_f_st);
      }

      for (c5_b_k = c5_i; c5_b_k <= c5_c_last; c5_b_k++) {
        if (c5_b_ex < c5_x->vector.data[c5_b_k - 1]) {
          c5_b_ex = c5_x->vector.data[c5_b_k - 1];
        }
      }

      c5_ex = c5_b_ex;
    }
  }

  return c5_ex;
}

static void c5_closeLoops(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_polygon_x,
  c5_coder_array_real_T *c5_polygon_y, c5_coder_array_real_T *c5_closedPolygon_x,
  c5_coder_array_real_T *c5_closedPolygon_y)
{
  static char_T c5_b_cv[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 'p',
    'o', 'l', 'y', 'g', 'o', 'n', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'L',
    'o', 'o', 'p', 'D', 'e', 'f' };

  c5_coder_array_boolean_T c5_b_xNaNPositions;
  c5_coder_array_boolean_T c5_c_xNaNPositions;
  c5_coder_array_boolean_T c5_xNaNPositions;
  c5_coder_array_boolean_T c5_yNaNPositions;
  c5_coder_array_int32_T c5_ii;
  c5_coder_array_int32_T_2D c5_r;
  c5_coder_array_real_T c5_NaNLocations;
  c5_coder_array_real_T c5_newPolygon_x;
  c5_coder_array_real_T c5_newPolygon_y;
  c5_coder_array_real_T_2D c5_r1;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_a;
  real_T c5_b_k;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d_a;
  real_T c5_d_k;
  real_T c5_growthLength;
  real_T c5_newLength;
  real_T c5_newNumberOfVertices;
  real_T c5_numLoops;
  real_T c5_numberOfVertices;
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_iv2[2];
  int32_T c5_a;
  int32_T c5_aux_0_0;
  int32_T c5_aux_1_0;
  int32_T c5_b_aux_0_0;
  int32_T c5_b_aux_1_0;
  int32_T c5_b_closedPolygon_x;
  int32_T c5_b_closedPolygon_y;
  int32_T c5_b_d;
  int32_T c5_b_loop_ub;
  int32_T c5_b_stride_0_0;
  int32_T c5_b_stride_1_0;
  int32_T c5_c_a;
  int32_T c5_c_d;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_b;
  int32_T c5_d_loop_ub;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_endIdx;
  int32_T c5_f_a;
  int32_T c5_f_loop_ub;
  int32_T c5_g_a;
  int32_T c5_g_loop_ub;
  int32_T c5_h_a;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_a;
  int32_T c5_i_loop_ub;
  int32_T c5_idxOffset;
  int32_T c5_j_a;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n_loop_ub;
  int32_T c5_o_loop_ub;
  int32_T c5_p;
  int32_T c5_p_loop_ub;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_s_loop_ub;
  int32_T c5_startIdx;
  int32_T c5_stride_0_0;
  int32_T c5_stride_1_0;
  int32_T c5_t_loop_ub;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b_isLoopClosed;
  boolean_T c5_c_b;
  boolean_T c5_guard1;
  boolean_T c5_isLoopClosed;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_array_boolean_T_Constructor(chartInstance, &c5_xNaNPositions);
  c5_array_boolean_T_SetSize(chartInstance, c5_sp, &c5_xNaNPositions,
    &c5_kd_emlrtRTEI, c5_polygon_x->size[0]);
  c5_loop_ub = c5_polygon_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_xNaNPositions.vector.data[c5_i] = muDoubleScalarIsNaN
      (c5_polygon_x->vector.data[c5_i]);
  }

  c5_array_boolean_T_Constructor(chartInstance, &c5_yNaNPositions);
  c5_array_boolean_T_SetSize(chartInstance, c5_sp, &c5_yNaNPositions,
    &c5_ld_emlrtRTEI, c5_polygon_y->size[0]);
  c5_b_loop_ub = c5_polygon_y->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_yNaNPositions.vector.data[c5_i1] = muDoubleScalarIsNaN
      (c5_polygon_y->vector.data[c5_i1]);
  }

  c5_i2 = c5_xNaNPositions.size[0];
  c5_i3 = c5_yNaNPositions.size[0];
  if ((c5_i2 != c5_i3) && ((c5_i2 != 1) && (c5_i3 != 1))) {
    emlrtDimSizeImpxCheckR2021b(c5_i2, c5_i3, &c5_k_emlrtECI, (emlrtConstCTX)
      c5_sp);
  }

  c5_array_boolean_T_Constructor(chartInstance, &c5_b_xNaNPositions);
  c5_st.site = &c5_rf_emlrtRSI;
  if (c5_yNaNPositions.size[0] == 1) {
    c5_i4 = c5_xNaNPositions.size[0];
  } else {
    c5_i4 = c5_yNaNPositions.size[0];
  }

  c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_b_xNaNPositions,
    &c5_md_emlrtRTEI, c5_i4);
  c5_stride_0_0 = (c5_xNaNPositions.size[0] != 1);
  c5_stride_1_0 = (c5_yNaNPositions.size[0] != 1);
  c5_aux_0_0 = 0;
  c5_aux_1_0 = 0;
  if (c5_yNaNPositions.size[0] == 1) {
    c5_i5 = c5_xNaNPositions.size[0];
  } else {
    c5_i5 = c5_yNaNPositions.size[0];
  }

  c5_c_loop_ub = c5_i5 - 1;
  for (c5_i6 = 0; c5_i6 <= c5_c_loop_ub; c5_i6++) {
    c5_b_xNaNPositions.vector.data[c5_i6] =
      (c5_xNaNPositions.vector.data[c5_aux_0_0] ||
       c5_yNaNPositions.vector.data[c5_aux_1_0]);
    c5_aux_1_0 += c5_stride_1_0;
    c5_aux_0_0 += c5_stride_0_0;
  }

  c5_array_real_T_Constructor(chartInstance, &c5_NaNLocations);
  c5_array_real_T_Constructor(chartInstance, &c5_newPolygon_x);
  c5_array_real_T_Constructor(chartInstance, &c5_newPolygon_y);
  c5_array_int32_T_2D_Constructor(chartInstance, &c5_r);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_r1);
  c5_array_int32_T_Constructor(chartInstance, &c5_ii);
  c5_array_boolean_T_Constructor(chartInstance, &c5_c_xNaNPositions);
  c5_st.site = &c5_rf_emlrtRSI;
  if (!c5_any(chartInstance, &c5_st, &c5_b_xNaNPositions)) {
    if ((real_T)c5_polygon_x->size[0] < 3.0) {
      c5_st.site = &c5_dj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_x,
        &c5_ee_emlrtRTEI, c5_polygon_x->size[0]);
      c5_d_loop_ub = c5_polygon_x->size[0] - 1;
      for (c5_i11 = 0; c5_i11 <= c5_d_loop_ub; c5_i11++) {
        c5_closedPolygon_x->vector.data[c5_i11] = c5_polygon_x->
          vector.data[c5_i11];
      }

      c5_st.site = &c5_cj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_y,
        &c5_fe_emlrtRTEI, c5_polygon_y->size[0]);
      c5_e_loop_ub = c5_polygon_y->size[0] - 1;
      for (c5_i15 = 0; c5_i15 <= c5_e_loop_ub; c5_i15++) {
        c5_closedPolygon_y->vector.data[c5_i15] = c5_polygon_y->
          vector.data[c5_i15];
      }
    } else {
      c5_i9 = c5_polygon_x->size[0];
      c5_i10 = 1;
      if ((c5_i10 < 1) || (c5_i10 > c5_i9)) {
        emlrtDynamicBoundsCheckR2012b(c5_i10, 1, c5_i9, &c5_ng_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i12 = c5_polygon_x->size[0];
      c5_i14 = c5_polygon_x->size[0];
      if ((c5_i14 < 1) || (c5_i14 > c5_i12)) {
        emlrtDynamicBoundsCheckR2012b(c5_i14, 1, c5_i12, &c5_ch_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_guard1 = false;
      if (c5_polygon_x->vector.data[0] != c5_polygon_x->vector.data[c5_i14 - 1])
      {
        c5_guard1 = true;
      } else {
        c5_i16 = c5_polygon_y->size[0];
        c5_i17 = 1;
        if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
          emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_og_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i20 = c5_polygon_y->size[0];
        c5_i22 = c5_polygon_y->size[0];
        if ((c5_i22 < 1) || (c5_i22 > c5_i20)) {
          emlrtDynamicBoundsCheckR2012b(c5_i22, 1, c5_i20, &c5_dh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_polygon_y->vector.data[0] != c5_polygon_y->vector.data[c5_i22 - 1])
        {
          c5_guard1 = true;
        } else {
          c5_st.site = &c5_hj_emlrtRSI;
          c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_x,
            &c5_ae_emlrtRTEI, c5_polygon_x->size[0]);
          c5_h_loop_ub = c5_polygon_x->size[0] - 1;
          for (c5_i25 = 0; c5_i25 <= c5_h_loop_ub; c5_i25++) {
            c5_closedPolygon_x->vector.data[c5_i25] = c5_polygon_x->
              vector.data[c5_i25];
          }

          c5_st.site = &c5_gj_emlrtRSI;
          c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_y,
            &c5_be_emlrtRTEI, c5_polygon_y->size[0]);
          c5_i_loop_ub = c5_polygon_y->size[0] - 1;
          for (c5_i31 = 0; c5_i31 <= c5_i_loop_ub; c5_i31++) {
            c5_closedPolygon_y->vector.data[c5_i31] = c5_polygon_y->
              vector.data[c5_i31];
          }
        }
      }

      if (c5_guard1) {
        c5_i19 = c5_polygon_x->size[0];
        c5_i21 = 1;
        if ((c5_i21 < 1) || (c5_i21 > c5_i19)) {
          emlrtDynamicBoundsCheckR2012b(c5_i21, 1, c5_i19, &c5_pg_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_st.site = &c5_fj_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_x,
          &c5_ce_emlrtRTEI, c5_polygon_x->size[0] + 1);
        c5_g_loop_ub = c5_polygon_x->size[0] - 1;
        for (c5_i24 = 0; c5_i24 <= c5_g_loop_ub; c5_i24++) {
          c5_closedPolygon_x->vector.data[c5_i24] = c5_polygon_x->
            vector.data[c5_i24];
        }

        c5_closedPolygon_x->vector.data[c5_polygon_x->size[0]] =
          c5_polygon_x->vector.data[0];
        c5_i26 = c5_polygon_y->size[0];
        c5_i27 = 1;
        if ((c5_i27 < 1) || (c5_i27 > c5_i26)) {
          emlrtDynamicBoundsCheckR2012b(c5_i27, 1, c5_i26, &c5_qg_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_st.site = &c5_ej_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_y,
          &c5_de_emlrtRTEI, c5_polygon_y->size[0] + 1);
        c5_j_loop_ub = c5_polygon_y->size[0] - 1;
        for (c5_i34 = 0; c5_i34 <= c5_j_loop_ub; c5_i34++) {
          c5_closedPolygon_y->vector.data[c5_i34] = c5_polygon_y->
            vector.data[c5_i34];
        }

        c5_closedPolygon_y->vector.data[c5_polygon_y->size[0]] =
          c5_polygon_y->vector.data[0];
      }
    }
  } else {
    c5_i7 = c5_xNaNPositions.size[0];
    c5_i8 = c5_yNaNPositions.size[0];
    if ((c5_i7 != c5_i8) && ((c5_i7 != 1) && (c5_i8 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c5_i7, c5_i8, &c5_l_emlrtECI, (emlrtConstCTX)
        c5_sp);
    }

    c5_st.site = &c5_sf_emlrtRSI;
    if (c5_yNaNPositions.size[0] == 1) {
      c5_i13 = c5_xNaNPositions.size[0];
    } else {
      c5_i13 = c5_yNaNPositions.size[0];
    }

    c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_c_xNaNPositions,
      &c5_nd_emlrtRTEI, c5_i13);
    c5_b_stride_0_0 = (c5_xNaNPositions.size[0] != 1);
    c5_b_stride_1_0 = (c5_yNaNPositions.size[0] != 1);
    c5_b_aux_0_0 = 0;
    c5_b_aux_1_0 = 0;
    if (c5_yNaNPositions.size[0] == 1) {
      c5_i18 = c5_xNaNPositions.size[0];
    } else {
      c5_i18 = c5_yNaNPositions.size[0];
    }

    c5_f_loop_ub = c5_i18 - 1;
    for (c5_i23 = 0; c5_i23 <= c5_f_loop_ub; c5_i23++) {
      c5_c_xNaNPositions.vector.data[c5_i23] = ((int32_T)
        c5_xNaNPositions.vector.data[c5_b_aux_0_0] != (int32_T)
        c5_yNaNPositions.vector.data[c5_b_aux_1_0]);
      c5_b_aux_1_0 += c5_b_stride_1_0;
      c5_b_aux_0_0 += c5_b_stride_0_0;
    }

    c5_st.site = &c5_sf_emlrtRSI;
    if (c5_any(chartInstance, &c5_st, &c5_c_xNaNPositions)) {
      c5_y = NULL;
      sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                    false);
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                    false);
      sf_mex_call(c5_sp, &c5_j_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                  sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c5_sp, NULL, "message", 1U, 1U, 14, c5_b_y)));
    }

    c5_st.site = &c5_tf_emlrtRSI;
    c5_d = (real_T)c5_xNaNPositions.size[0] - 1.0;
    c5_c_b = (c5_d < 1.0);
    if (c5_c_b) {
      c5_i29 = 0;
    } else {
      c5_i28 = c5_xNaNPositions.size[0];
      c5_i30 = 1;
      if ((c5_i30 < 1) || (c5_i30 > c5_i28)) {
        emlrtDynamicBoundsCheckR2012b(c5_i30, 1, c5_i28, &c5_bh_emlrtBCI, &c5_st);
      }

      c5_i32 = c5_xNaNPositions.size[0];
      c5_i33 = (int32_T)c5_d;
      if ((c5_i33 < 1) || (c5_i33 > c5_i32)) {
        emlrtDynamicBoundsCheckR2012b(c5_i33, 1, c5_i32, &c5_ah_emlrtBCI, &c5_st);
      }

      c5_i29 = c5_i33;
    }

    c5_iv[0] = 1;
    c5_iv[1] = c5_i29;
    c5_b_st.site = &c5_bg_emlrtRSI;
    c5_indexShapeCheck(chartInstance, &c5_b_st, c5_xNaNPositions.size[0], c5_iv);
    c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_yNaNPositions,
      &c5_od_emlrtRTEI, 1 + c5_i29);
    c5_yNaNPositions.vector.data[0] = true;
    c5_k_loop_ub = c5_i29 - 1;
    for (c5_i35 = 0; c5_i35 <= c5_k_loop_ub; c5_i35++) {
      c5_yNaNPositions.vector.data[c5_i35 + 1] =
        c5_xNaNPositions.vector.data[c5_i35];
    }

    c5_i36 = c5_xNaNPositions.size[0];
    c5_i37 = c5_yNaNPositions.size[0];
    if ((c5_i36 != c5_i37) && ((c5_i36 != 1) && (c5_i37 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c5_i36, c5_i37, &c5_o_emlrtECI, &c5_st);
    }

    if (c5_xNaNPositions.size[0] == c5_yNaNPositions.size[0]) {
      c5_l_loop_ub = c5_xNaNPositions.size[0] - 1;
      for (c5_i38 = 0; c5_i38 <= c5_l_loop_ub; c5_i38++) {
        c5_xNaNPositions.vector.data[c5_i38] =
          (c5_xNaNPositions.vector.data[c5_i38] &&
           c5_yNaNPositions.vector.data[c5_i38]);
      }
    } else {
      c5_b_st.site = &c5_hk_emlrtRSI;
      c5_and(chartInstance, &c5_b_st, &c5_xNaNPositions, &c5_yNaNPositions);
    }

    c5_i39 = c5_polygon_x->size[0];
    c5_i40 = c5_polygon_x->size[0];
    if ((c5_i40 < 1) || (c5_i40 > c5_i39)) {
      emlrtDynamicBoundsCheckR2012b(c5_i40, 1, c5_i39, &c5_yg_emlrtBCI, &c5_st);
    }

    c5_numberOfVertices = (real_T)c5_polygon_x->size[0];
    c5_newNumberOfVertices = (real_T)c5_polygon_x->size[0] + 1.0;
    if (c5_newNumberOfVertices != (real_T)(int32_T)muDoubleScalarFloor
        (c5_newNumberOfVertices)) {
      emlrtIntegerCheckR2012b(c5_newNumberOfVertices, &c5_q_emlrtDCI, &c5_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_newPolygon_x,
      &c5_pd_emlrtRTEI, (int32_T)c5_newNumberOfVertices);
    if (c5_newNumberOfVertices != (real_T)(int32_T)muDoubleScalarFloor
        (c5_newNumberOfVertices)) {
      emlrtIntegerCheckR2012b(c5_newNumberOfVertices, &c5_r_emlrtDCI, &c5_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_newPolygon_y,
      &c5_qd_emlrtRTEI, (int32_T)c5_newNumberOfVertices);
    c5_p = 1;
    c5_i41 = (int32_T)c5_numberOfVertices - 1;
    for (c5_k = 0; c5_k <= c5_i41; c5_k++) {
      c5_b_k = (real_T)c5_k + 1.0;
      c5_i43 = c5_xNaNPositions.size[0];
      c5_i44 = (int32_T)c5_b_k;
      if ((c5_i44 < 1) || (c5_i44 > c5_i43)) {
        emlrtDynamicBoundsCheckR2012b(c5_i44, 1, c5_i43, &c5_xg_emlrtBCI, &c5_st);
      }

      c5_i46 = c5_polygon_x->size[0];
      c5_i47 = (int32_T)c5_b_k;
      if ((c5_i47 < 1) || (c5_i47 > c5_i46)) {
        emlrtDynamicBoundsCheckR2012b(c5_i47, 1, c5_i46, &c5_gh_emlrtBCI, &c5_st);
      }

      c5_i48 = c5_newPolygon_x.size[0];
      if ((c5_p < 1) || (c5_p > c5_i48)) {
        emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i48, &c5_hh_emlrtBCI, &c5_st);
      }

      c5_newPolygon_x.vector.data[c5_p - 1] = c5_polygon_x->vector.data[c5_i47 -
        1];
      c5_i50 = c5_polygon_y->size[0];
      c5_i51 = (int32_T)c5_b_k;
      if ((c5_i51 < 1) || (c5_i51 > c5_i50)) {
        emlrtDynamicBoundsCheckR2012b(c5_i51, 1, c5_i50, &c5_ih_emlrtBCI, &c5_st);
      }

      c5_i53 = c5_newPolygon_y.size[0];
      if ((c5_p < 1) || (c5_p > c5_i53)) {
        emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i53, &c5_jh_emlrtBCI, &c5_st);
      }

      c5_newPolygon_y.vector.data[c5_p - 1] = c5_polygon_y->vector.data[c5_i51 -
        1];
      c5_a = c5_p + 1;
      c5_p = c5_a;
    }

    c5_i42 = c5_newPolygon_x.size[0];
    if ((c5_p < 1) || (c5_p > c5_i42)) {
      emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i42, &c5_eh_emlrtBCI, &c5_st);
    }

    c5_newPolygon_x.vector.data[c5_p - 1] = rtNaN;
    c5_i45 = c5_newPolygon_y.size[0];
    if ((c5_p < 1) || (c5_p > c5_i45)) {
      emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i45, &c5_fh_emlrtBCI, &c5_st);
    }

    c5_newPolygon_y.vector.data[c5_p - 1] = rtNaN;
    c5_st.site = &c5_uf_emlrtRSI;
    c5_array_boolean_T_SetSize(chartInstance, &c5_st, &c5_yNaNPositions,
      &c5_rd_emlrtRTEI, c5_newPolygon_x.size[0]);
    c5_m_loop_ub = c5_newPolygon_x.size[0] - 1;
    for (c5_i49 = 0; c5_i49 <= c5_m_loop_ub; c5_i49++) {
      c5_yNaNPositions.vector.data[c5_i49] = muDoubleScalarIsNaN
        (c5_newPolygon_x.vector.data[c5_i49]);
    }

    c5_b_st.site = &c5_dg_emlrtRSI;
    c5_eml_find(chartInstance, &c5_b_st, &c5_yNaNPositions, &c5_ii);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_NaNLocations,
      &c5_sd_emlrtRTEI, c5_ii.size[0]);
    c5_n_loop_ub = c5_ii.size[0] - 1;
    for (c5_i52 = 0; c5_i52 <= c5_n_loop_ub; c5_i52++) {
      c5_NaNLocations.vector.data[c5_i52] = (real_T)c5_ii.vector.data[c5_i52];
    }

    c5_startIdx = 1;
    c5_growthLength = 0.0;
    c5_numLoops = (real_T)c5_NaNLocations.size[0];
    c5_i54 = (int32_T)c5_numLoops - 1;
    for (c5_c_k = 0; c5_c_k <= c5_i54; c5_c_k++) {
      c5_d_k = (real_T)c5_c_k + 1.0;
      c5_i55 = c5_NaNLocations.size[0];
      c5_i56 = (int32_T)c5_d_k;
      if ((c5_i56 < 1) || (c5_i56 > c5_i55)) {
        emlrtDynamicBoundsCheckR2012b(c5_i56, 1, c5_i55, &c5_kh_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_b_a = c5_NaNLocations.vector.data[c5_i56 - 1];
      c5_endIdx = (int32_T)c5_b_a - 1;
      c5_i60 = c5_newPolygon_x.size[0];
      if ((c5_startIdx < 1) || (c5_startIdx > c5_i60)) {
        emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i60, &c5_lh_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i61 = c5_newPolygon_x.size[0];
      if ((c5_endIdx < 1) || (c5_endIdx > c5_i61)) {
        emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i61, &c5_mh_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      if (c5_newPolygon_x.vector.data[c5_startIdx - 1] ==
          c5_newPolygon_x.vector.data[c5_endIdx - 1]) {
        c5_i64 = c5_newPolygon_y.size[0];
        if ((c5_startIdx < 1) || (c5_startIdx > c5_i64)) {
          emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i64, &c5_nh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i67 = c5_newPolygon_y.size[0];
        if ((c5_endIdx < 1) || (c5_endIdx > c5_i67)) {
          emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i67, &c5_oh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_newPolygon_y.vector.data[c5_startIdx - 1] ==
            c5_newPolygon_y.vector.data[c5_endIdx - 1]) {
          c5_isLoopClosed = true;
        } else {
          c5_isLoopClosed = false;
        }
      } else {
        c5_isLoopClosed = false;
      }

      c5_growthLength += (real_T)!c5_isLoopClosed;
      c5_c_a = c5_endIdx + 2;
      c5_startIdx = c5_c_a;
    }

    if (c5_growthLength > 0.0) {
      c5_newLength = (real_T)c5_newPolygon_x.size[0] + c5_growthLength;
      if (c5_newLength != (real_T)(int32_T)muDoubleScalarFloor(c5_newLength)) {
        emlrtIntegerCheckR2012b(c5_newLength, &c5_s_emlrtDCI, (emlrtConstCTX)
          c5_sp);
      }

      c5_st.site = &c5_jj_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_x,
        &c5_vd_emlrtRTEI, (int32_T)c5_newLength);
      if (c5_newLength != (real_T)(int32_T)muDoubleScalarFloor(c5_newLength)) {
        emlrtIntegerCheckR2012b(c5_newLength, &c5_t_emlrtDCI, (emlrtConstCTX)
          c5_sp);
      }

      c5_st.site = &c5_ij_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_y,
        &c5_wd_emlrtRTEI, (int32_T)c5_newLength);
      c5_startIdx = 1;
      c5_idxOffset = 0;
      c5_i62 = (int32_T)c5_numLoops - 1;
      for (c5_e_k = 0; c5_e_k <= c5_i62; c5_e_k++) {
        c5_d_k = (real_T)c5_e_k + 1.0;
        c5_i65 = c5_NaNLocations.size[0];
        c5_i66 = (int32_T)c5_d_k;
        if ((c5_i66 < 1) || (c5_i66 > c5_i65)) {
          emlrtDynamicBoundsCheckR2012b(c5_i66, 1, c5_i65, &c5_ph_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_d_a = c5_NaNLocations.vector.data[c5_i66 - 1];
        c5_endIdx = (int32_T)c5_d_a - 1;
        c5_b3 = (c5_startIdx > c5_endIdx);
        if (c5_b3) {
          c5_i72 = 0;
          c5_i73 = -1;
        } else {
          c5_i71 = c5_newPolygon_x.size[0];
          if ((c5_startIdx < 1) || (c5_startIdx > c5_i71)) {
            emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i71,
              &c5_rg_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i72 = c5_startIdx - 1;
          c5_i75 = c5_newPolygon_x.size[0];
          if ((c5_endIdx < 1) || (c5_endIdx > c5_i75)) {
            emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i75, &c5_sg_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i73 = c5_endIdx - 1;
        }

        c5_st.site = &c5_yf_emlrtRSI;
        c5_e_a = c5_startIdx;
        c5_b_d = c5_endIdx;
        c5_b_st.site = &c5_cd_emlrtRSI;
        c5_f_a = c5_e_a;
        c5_d_b = c5_b_d;
        c5_c_st.site = &c5_ie_emlrtRSI;
        c5_eml_integer_colon_dispatcher(chartInstance, &c5_c_st, c5_f_a, c5_d_b,
          &c5_r);
        c5_st.site = &c5_yf_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_r1,
          &c5_xd_emlrtRTEI, 1, (c5_i73 - c5_i72) + 1);
        c5_q_loop_ub = c5_i73 - c5_i72;
        for (c5_i76 = 0; c5_i76 <= c5_q_loop_ub; c5_i76++) {
          c5_r1.vector.data[c5_i76] = c5_newPolygon_x.vector.data[c5_i72 +
            c5_i76];
        }

        c5_i77 = c5_r.size[1];
        c5_i78 = c5_r1.size[1];
        if (c5_i77 != c5_i78) {
          emlrtSubAssignSizeCheck1dR2017a(c5_i77, c5_i78, &c5_n_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        c5_b_closedPolygon_x = c5_closedPolygon_x->size[0];
        c5_r_loop_ub = c5_r1.size[1] - 1;
        for (c5_i79 = 0; c5_i79 <= c5_r_loop_ub; c5_i79++) {
          c5_i80 = c5_r.vector.data[c5_i79] + c5_idxOffset;
          if ((c5_i80 < 1) || (c5_i80 > c5_b_closedPolygon_x)) {
            emlrtDynamicBoundsCheckR2012b(c5_i80, 1, c5_b_closedPolygon_x,
              &c5_qh_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_closedPolygon_x->vector.data[c5_i80 - 1] = c5_r1.vector.data[c5_i79];
        }

        c5_b4 = (c5_startIdx > c5_endIdx);
        if (c5_b4) {
          c5_i82 = 0;
          c5_i83 = -1;
        } else {
          c5_i81 = c5_newPolygon_y.size[0];
          if ((c5_startIdx < 1) || (c5_startIdx > c5_i81)) {
            emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i81,
              &c5_tg_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i82 = c5_startIdx - 1;
          c5_i84 = c5_newPolygon_y.size[0];
          if ((c5_endIdx < 1) || (c5_endIdx > c5_i84)) {
            emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i84, &c5_ug_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i83 = c5_endIdx - 1;
        }

        c5_st.site = &c5_xf_emlrtRSI;
        c5_g_a = c5_startIdx;
        c5_c_d = c5_endIdx;
        c5_b_st.site = &c5_cd_emlrtRSI;
        c5_h_a = c5_g_a;
        c5_e_b = c5_c_d;
        c5_c_st.site = &c5_ie_emlrtRSI;
        c5_eml_integer_colon_dispatcher(chartInstance, &c5_c_st, c5_h_a, c5_e_b,
          &c5_r);
        c5_st.site = &c5_xf_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_r1,
          &c5_yd_emlrtRTEI, 1, (c5_i83 - c5_i82) + 1);
        c5_s_loop_ub = c5_i83 - c5_i82;
        for (c5_i85 = 0; c5_i85 <= c5_s_loop_ub; c5_i85++) {
          c5_r1.vector.data[c5_i85] = c5_newPolygon_y.vector.data[c5_i82 +
            c5_i85];
        }

        c5_i86 = c5_r.size[1];
        c5_i87 = c5_r1.size[1];
        if (c5_i86 != c5_i87) {
          emlrtSubAssignSizeCheck1dR2017a(c5_i86, c5_i87, &c5_m_emlrtECI,
            (emlrtConstCTX)c5_sp);
        }

        c5_b_closedPolygon_y = c5_closedPolygon_y->size[0];
        c5_t_loop_ub = c5_r1.size[1] - 1;
        for (c5_i88 = 0; c5_i88 <= c5_t_loop_ub; c5_i88++) {
          c5_i90 = c5_r.vector.data[c5_i88] + c5_idxOffset;
          if ((c5_i90 < 1) || (c5_i90 > c5_b_closedPolygon_y)) {
            emlrtDynamicBoundsCheckR2012b(c5_i90, 1, c5_b_closedPolygon_y,
              &c5_rh_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_closedPolygon_y->vector.data[c5_i90 - 1] = c5_r1.vector.data[c5_i88];
        }

        c5_i89 = c5_newPolygon_x.size[0];
        if ((c5_startIdx < 1) || (c5_startIdx > c5_i89)) {
          emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i89, &c5_sh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i91 = c5_newPolygon_x.size[0];
        if ((c5_endIdx < 1) || (c5_endIdx > c5_i91)) {
          emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i91, &c5_th_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_newPolygon_x.vector.data[c5_startIdx - 1] ==
            c5_newPolygon_x.vector.data[c5_endIdx - 1]) {
          c5_i92 = c5_newPolygon_y.size[0];
          if ((c5_startIdx < 1) || (c5_startIdx > c5_i92)) {
            emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i92,
              &c5_uh_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i93 = c5_newPolygon_y.size[0];
          if ((c5_endIdx < 1) || (c5_endIdx > c5_i93)) {
            emlrtDynamicBoundsCheckR2012b(c5_endIdx, 1, c5_i93, &c5_vh_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          if (c5_newPolygon_y.vector.data[c5_startIdx - 1] ==
              c5_newPolygon_y.vector.data[c5_endIdx - 1]) {
            c5_b_isLoopClosed = true;
          } else {
            c5_b_isLoopClosed = false;
          }
        } else {
          c5_b_isLoopClosed = false;
        }

        if (!c5_b_isLoopClosed) {
          c5_i_a = c5_idxOffset + 1;
          c5_idxOffset = c5_i_a;
          c5_i96 = c5_newPolygon_x.size[0];
          if ((c5_startIdx < 1) || (c5_startIdx > c5_i96)) {
            emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i96,
              &c5_yh_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i97 = c5_closedPolygon_x->size[0];
          c5_i99 = c5_idxOffset + c5_endIdx;
          if ((c5_i99 < 1) || (c5_i99 > c5_i97)) {
            emlrtDynamicBoundsCheckR2012b(c5_i99, 1, c5_i97, &c5_ai_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_closedPolygon_x->vector.data[c5_i99 - 1] =
            c5_newPolygon_x.vector.data[c5_startIdx - 1];
          c5_i101 = c5_newPolygon_y.size[0];
          if ((c5_startIdx < 1) || (c5_startIdx > c5_i101)) {
            emlrtDynamicBoundsCheckR2012b(c5_startIdx, 1, c5_i101,
              &c5_bi_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i102 = c5_closedPolygon_y->size[0];
          c5_i103 = c5_idxOffset + c5_endIdx;
          if ((c5_i103 < 1) || (c5_i103 > c5_i102)) {
            emlrtDynamicBoundsCheckR2012b(c5_i103, 1, c5_i102, &c5_ci_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_closedPolygon_y->vector.data[c5_i103 - 1] =
            c5_newPolygon_y.vector.data[c5_startIdx - 1];
        }

        c5_i94 = c5_closedPolygon_x->size[0];
        c5_i95 = (c5_idxOffset + c5_endIdx) + 1;
        if ((c5_i95 < 1) || (c5_i95 > c5_i94)) {
          emlrtDynamicBoundsCheckR2012b(c5_i95, 1, c5_i94, &c5_wh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_closedPolygon_x->vector.data[c5_i95 - 1] = rtNaN;
        c5_i98 = c5_closedPolygon_y->size[0];
        c5_i100 = (c5_idxOffset + c5_endIdx) + 1;
        if ((c5_i100 < 1) || (c5_i100 > c5_i98)) {
          emlrtDynamicBoundsCheckR2012b(c5_i100, 1, c5_i98, &c5_xh_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_closedPolygon_y->vector.data[c5_i100 - 1] = rtNaN;
        c5_j_a = c5_endIdx + 2;
        c5_startIdx = c5_j_a;
      }
    } else {
      c5_d1 = (real_T)c5_newPolygon_x.size[0] - 1.0;
      c5_b1 = (c5_d1 < 1.0);
      if (c5_b1) {
        c5_i58 = 0;
      } else {
        c5_i57 = c5_newPolygon_x.size[0];
        c5_i59 = (int32_T)c5_d1;
        if ((c5_i59 < 1) || (c5_i59 > c5_i57)) {
          emlrtDynamicBoundsCheckR2012b(c5_i59, 1, c5_i57, &c5_vg_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i58 = c5_i59;
      }

      c5_iv1[0] = 1;
      c5_iv1[1] = c5_i58;
      c5_st.site = &c5_vf_emlrtRSI;
      c5_indexShapeCheck(chartInstance, &c5_st, c5_newPolygon_x.size[0], c5_iv1);
      c5_st.site = &c5_vf_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_x,
        &c5_td_emlrtRTEI, c5_i58);
      c5_o_loop_ub = c5_i58 - 1;
      for (c5_i63 = 0; c5_i63 <= c5_o_loop_ub; c5_i63++) {
        c5_closedPolygon_x->vector.data[c5_i63] =
          c5_newPolygon_x.vector.data[c5_i63];
      }

      c5_d2 = (real_T)c5_newPolygon_y.size[0] - 1.0;
      c5_b2 = (c5_d2 < 1.0);
      if (c5_b2) {
        c5_i69 = 0;
      } else {
        c5_i68 = c5_newPolygon_y.size[0];
        c5_i70 = (int32_T)c5_d2;
        if ((c5_i70 < 1) || (c5_i70 > c5_i68)) {
          emlrtDynamicBoundsCheckR2012b(c5_i70, 1, c5_i68, &c5_wg_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i69 = c5_i70;
      }

      c5_iv2[0] = 1;
      c5_iv2[1] = c5_i69;
      c5_st.site = &c5_wf_emlrtRSI;
      c5_indexShapeCheck(chartInstance, &c5_st, c5_newPolygon_y.size[0], c5_iv2);
      c5_st.site = &c5_wf_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, c5_closedPolygon_y,
        &c5_ud_emlrtRTEI, c5_i69);
      c5_p_loop_ub = c5_i69 - 1;
      for (c5_i74 = 0; c5_i74 <= c5_p_loop_ub; c5_i74++) {
        c5_closedPolygon_y->vector.data[c5_i74] =
          c5_newPolygon_y.vector.data[c5_i74];
      }
    }
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_c_xNaNPositions);
  c5_array_boolean_T_Destructor(chartInstance, &c5_b_xNaNPositions);
  c5_array_int32_T_Destructor(chartInstance, &c5_ii);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_r1);
  c5_array_int32_T_2D_Destructor(chartInstance, &c5_r);
  c5_array_real_T_Destructor(chartInstance, &c5_newPolygon_y);
  c5_array_real_T_Destructor(chartInstance, &c5_newPolygon_x);
  c5_array_real_T_Destructor(chartInstance, &c5_NaNLocations);
  c5_array_boolean_T_Destructor(chartInstance, &c5_yNaNPositions);
  c5_array_boolean_T_Destructor(chartInstance, &c5_xNaNPositions);
}

static boolean_T c5_any(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_a;
  real_T c5_vlen;
  int32_T c5_b_a;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_f_b;
  int32_T c5_i2;
  int32_T c5_ix;
  int32_T c5_vspread;
  boolean_T c5_b1;
  boolean_T c5_c_b;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  boolean_T c5_y;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_ag_emlrtRSI;
  if ((c5_x->size[0] == 1) || ((real_T)c5_x->size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c5_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_y = false;
  c5_vlen = (real_T)c5_x->size[0];
  c5_a = c5_vlen;
  c5_c = (int32_T)c5_a;
  c5_b_a = c5_c - 1;
  c5_vspread = c5_b_a;
  c5_d_b = c5_vspread;
  c5_i2 = c5_d_b;
  c5_c_a = c5_i2 + 1;
  c5_i2 = c5_c_a;
  c5_b_st.site = &c5_bd_emlrtRSI;
  c5_e_b = c5_i2;
  c5_f_b = c5_e_b;
  if (c5_f_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_f_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_ix = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ix + 1 <= c5_i2)) {
    if (!c5_x->vector.data[c5_ix]) {
      c5_b1 = true;
    } else {
      c5_b1 = false;
    }

    if (!c5_b1) {
      c5_y = true;
      c5_exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_y;
}

static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2])
{
  static char_T c5_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_size1;
  boolean_T c5_b_c;
  boolean_T c5_c;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_nonSingletonDimFound;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_size1 = c5_matrixSize;
  if (c5_size1 != 1) {
    c5_c_b = false;
  } else {
    c5_c_b = true;
  }

  if (c5_c_b) {
    c5_nonSingletonDimFound = false;
    if (c5_indexSize[1] != 1) {
      c5_nonSingletonDimFound = true;
    }

    c5_d_b = c5_nonSingletonDimFound;
    if (c5_d_b) {
      c5_c = true;
    } else {
      c5_c = false;
    }
  } else {
    c5_c = false;
  }

  c5_st.site = &c5_cg_emlrtRSI;
  c5_b_c = c5_c;
  if (c5_b_c) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_b_y)));
  }
}

static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x,
  c5_coder_array_int32_T *c5_i)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_iv[2];
  int32_T c5_b_i;
  int32_T c5_b_ii;
  int32_T c5_b_nx;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_idx;
  int32_T c5_ii;
  int32_T c5_k;
  int32_T c5_nx;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_nx = c5_x->size[0];
  c5_st.site = &c5_eg_emlrtRSI;
  c5_k = c5_nx;
  c5_b_nx = c5_nx;
  c5_idx = 0;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_i, &c5_ge_emlrtRTEI, c5_k);
  c5_b_st.site = &c5_fg_emlrtRSI;
  c5_c_b = c5_b_nx;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_ii = 1;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ii - 1 <= c5_b_nx - 1)) {
    c5_b_ii = c5_ii;
    if (c5_x->vector.data[c5_b_ii - 1]) {
      c5_idx++;
      c5_i->vector.data[c5_idx - 1] = c5_b_ii;
      if (c5_idx >= c5_k) {
        c5_exitg1 = true;
      } else {
        c5_ii++;
      }
    } else {
      c5_ii++;
    }
  }

  if (c5_idx > c5_k) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_st, &c5_m_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_b_y)));
  }

  if (c5_k == 1) {
    if (c5_idx == 0) {
      c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_i, &c5_he_emlrtRTEI, 0);
    }
  } else {
    c5_e_b = (c5_idx < 1);
    if (c5_e_b) {
      c5_b_i = 0;
    } else {
      c5_b_i = c5_idx;
    }

    c5_iv[0] = 1;
    c5_iv[1] = c5_b_i;
    c5_b_st.site = &c5_gg_emlrtRSI;
    c5_indexShapeCheck(chartInstance, &c5_b_st, c5_i->size[0], c5_iv);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_i, &c5_he_emlrtRTEI,
      c5_b_i);
  }
}

static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp)
{
  static char_T c5_msgID[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n',
    'p', 'o', 'l', 'y', 'g', 'o', 'n', ':', 'M', 'o', 'd', 'e', 'l', 'i', 'n',
    'g', 'W', 'o', 'r', 'l', 'd', 'L', 'o', 'w', 'e', 'r' };

  static char_T c5_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c5_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_msgID, 10, 0U, 1, 0U, 2, 1, 35),
                false);
  c5_st.site = &c5_t_emlrtRSI;
  c5_c_feval(chartInstance, &c5_st, c5_y, c5_b_feval(chartInstance, &c5_st,
              c5_b_y, c5_c_y));
}

static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp)
{
  static char_T c5_msgID[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n',
    'p', 'o', 'l', 'y', 'g', 'o', 'n', ':', 'M', 'o', 'd', 'e', 'l', 'i', 'n',
    'g', 'W', 'o', 'r', 'l', 'd', 'U', 'p', 'p', 'e', 'r' };

  static char_T c5_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c5_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_msgID, 10, 0U, 1, 0U, 2, 1, 35),
                false);
  c5_st.site = &c5_t_emlrtRSI;
  c5_e_feval(chartInstance, &c5_st, c5_y, c5_d_feval(chartInstance, &c5_st,
              c5_b_y, c5_c_y));
}

static void c5_computeScaledEps(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_polygon_x,
  c5_coder_array_real_T *c5_polygon_y, c5_coder_array_real_T *c5_scaledEps)
{
  emlrtStack c5_st;
  real_T c5_a;
  real_T c5_avx;
  real_T c5_avy;
  real_T c5_b_a;
  real_T c5_b_k;
  real_T c5_b_varargin_1;
  real_T c5_b_varargin_2;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_b;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_b;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_factor;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_h_x;
  real_T c5_h_y;
  real_T c5_i_x;
  real_T c5_i_y;
  real_T c5_j_x;
  real_T c5_j_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_numVertices;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_varargin_1;
  real_T c5_varargin_2;
  real_T c5_x;
  real_T c5_y;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_numVertices = (real_T)c5_polygon_x->size[0];
  c5_d = c5_numVertices - 1.0;
  if (!(c5_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d, &c5_u_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_bj_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, c5_scaledEps, &c5_ie_emlrtRTEI,
    (int32_T)c5_d);
  c5_d1 = c5_numVertices - 1.0;
  c5_i = (int32_T)c5_d1 - 1;
  for (c5_k = 0; c5_k <= c5_i; c5_k++) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_i1 = c5_polygon_x->size[0];
    c5_i2 = (int32_T)c5_b_k;
    if ((c5_i2 < 1) || (c5_i2 > c5_i1)) {
      emlrtDynamicBoundsCheckR2012b(c5_i2, 1, c5_i1, &c5_di_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i3 = c5_polygon_x->size[0];
    c5_i4 = (int32_T)(c5_b_k + 1.0);
    if ((c5_i4 < 1) || (c5_i4 > c5_i3)) {
      emlrtDynamicBoundsCheckR2012b(c5_i4, 1, c5_i3, &c5_ei_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_x = 0.5 * (c5_polygon_x->vector.data[c5_i2 - 1] +
                  c5_polygon_x->vector.data[c5_i4 - 1]);
    c5_b_x = c5_x;
    c5_c_x = c5_b_x;
    c5_avx = muDoubleScalarAbs(c5_c_x);
    c5_i5 = c5_polygon_y->size[0];
    c5_i6 = (int32_T)c5_b_k;
    if ((c5_i6 < 1) || (c5_i6 > c5_i5)) {
      emlrtDynamicBoundsCheckR2012b(c5_i6, 1, c5_i5, &c5_fi_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i7 = c5_polygon_y->size[0];
    c5_i8 = (int32_T)(c5_b_k + 1.0);
    if ((c5_i8 < 1) || (c5_i8 > c5_i7)) {
      emlrtDynamicBoundsCheckR2012b(c5_i8, 1, c5_i7, &c5_gi_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_d_x = 0.5 * (c5_polygon_y->vector.data[c5_i6 - 1] +
                    c5_polygon_y->vector.data[c5_i8 - 1]);
    c5_e_x = c5_d_x;
    c5_f_x = c5_e_x;
    c5_avy = muDoubleScalarAbs(c5_f_x);
    c5_varargin_1 = c5_avx;
    c5_varargin_2 = c5_avy;
    c5_g_x = c5_varargin_1;
    c5_y = c5_varargin_2;
    c5_h_x = c5_g_x;
    c5_b_y = c5_y;
    c5_i_x = c5_h_x;
    c5_c_y = c5_b_y;
    c5_a = c5_i_x;
    c5_c_b = c5_c_y;
    c5_j_x = c5_a;
    c5_d_y = c5_c_b;
    c5_k_x = c5_j_x;
    c5_e_y = c5_d_y;
    c5_factor = muDoubleScalarMax(c5_k_x, c5_e_y);
    c5_b_varargin_1 = c5_factor;
    c5_b_varargin_2 = c5_avx * c5_avy;
    c5_l_x = c5_b_varargin_1;
    c5_f_y = c5_b_varargin_2;
    c5_m_x = c5_l_x;
    c5_g_y = c5_f_y;
    c5_n_x = c5_m_x;
    c5_h_y = c5_g_y;
    c5_b_a = c5_n_x;
    c5_d_b = c5_h_y;
    c5_o_x = c5_b_a;
    c5_i_y = c5_d_b;
    c5_p_x = c5_o_x;
    c5_j_y = c5_i_y;
    c5_factor = muDoubleScalarMax(c5_p_x, c5_j_y);
    c5_i9 = c5_scaledEps->size[0];
    c5_i10 = (int32_T)c5_b_k;
    if ((c5_i10 < 1) || (c5_i10 > c5_i9)) {
      emlrtDynamicBoundsCheckR2012b(c5_i10, 1, c5_i9, &c5_hi_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_scaledEps->vector.data[c5_i10 - 1] = c5_factor * 2.2204460492503131E-16 *
      3.0;
  }
}

static void c5_computeCrossAndDotProducts(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_transPoly_x, c5_coder_array_real_T_2D *c5_transPoly_y,
  c5_coder_array_real_T *c5_scaledEps, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd)
{
  emlrtStack c5_st;
  real_T c5_b_p;
  real_T c5_b_v;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_crossProd;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_numPoints;
  real_T c5_numVertices;
  real_T c5_x;
  real_T c5_x1;
  real_T c5_x2;
  real_T c5_y;
  real_T c5_y1;
  real_T c5_y2;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_p;
  int32_T c5_v;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_numPoints = (real_T)c5_transPoly_x->size[1];
  c5_numVertices = (real_T)c5_transPoly_x->size[0];
  c5_d = c5_numVertices - 1.0;
  if (!(c5_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d, &c5_v_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_qj_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_signCrossProd,
    &c5_je_emlrtRTEI, (int32_T)c5_d, (int32_T)c5_numPoints);
  c5_d1 = c5_numVertices - 1.0;
  if (!(c5_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d1, &c5_w_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_pj_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_dotProd, &c5_ke_emlrtRTEI,
    (int32_T)c5_d1, (int32_T)c5_numPoints);
  c5_i = (int32_T)c5_numPoints - 1;
  for (c5_p = 0; c5_p <= c5_i; c5_p++) {
    c5_b_p = (real_T)c5_p + 1.0;
    c5_d2 = c5_numVertices - 1.0;
    c5_i1 = (int32_T)c5_d2 - 1;
    for (c5_v = 0; c5_v <= c5_i1; c5_v++) {
      c5_b_v = (real_T)c5_v + 1.0;
      c5_i2 = c5_transPoly_x->size[0];
      c5_i3 = (int32_T)c5_b_v;
      if ((c5_i3 < 1) || (c5_i3 > c5_i2)) {
        emlrtDynamicBoundsCheckR2012b(c5_i3, 1, c5_i2, &c5_ii_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i4 = c5_transPoly_x->size[1];
      c5_i5 = (int32_T)c5_b_p;
      if ((c5_i5 < 1) || (c5_i5 > c5_i4)) {
        emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i4, &c5_ji_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_x1 = c5_transPoly_x->vector.data[(c5_i3 + c5_transPoly_x->size[0] *
        (c5_i5 - 1)) - 1];
      c5_i6 = c5_transPoly_x->size[0];
      c5_i7 = (int32_T)(c5_b_v + 1.0);
      if ((c5_i7 < 1) || (c5_i7 > c5_i6)) {
        emlrtDynamicBoundsCheckR2012b(c5_i7, 1, c5_i6, &c5_ki_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i8 = c5_transPoly_x->size[1];
      c5_i9 = (int32_T)c5_b_p;
      if ((c5_i9 < 1) || (c5_i9 > c5_i8)) {
        emlrtDynamicBoundsCheckR2012b(c5_i9, 1, c5_i8, &c5_li_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_x2 = c5_transPoly_x->vector.data[(c5_i7 + c5_transPoly_x->size[0] *
        (c5_i9 - 1)) - 1];
      c5_i10 = c5_transPoly_y->size[0];
      c5_i11 = (int32_T)c5_b_v;
      if ((c5_i11 < 1) || (c5_i11 > c5_i10)) {
        emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_i10, &c5_mi_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i12 = c5_transPoly_y->size[1];
      c5_i13 = (int32_T)c5_b_p;
      if ((c5_i13 < 1) || (c5_i13 > c5_i12)) {
        emlrtDynamicBoundsCheckR2012b(c5_i13, 1, c5_i12, &c5_ni_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_y1 = c5_transPoly_y->vector.data[(c5_i11 + c5_transPoly_y->size[0] *
        (c5_i13 - 1)) - 1];
      c5_i14 = c5_transPoly_y->size[0];
      c5_i15 = (int32_T)(c5_b_v + 1.0);
      if ((c5_i15 < 1) || (c5_i15 > c5_i14)) {
        emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i14, &c5_oi_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i16 = c5_transPoly_y->size[1];
      c5_i17 = (int32_T)c5_b_p;
      if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
        emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_pi_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_y2 = c5_transPoly_y->vector.data[(c5_i15 + c5_transPoly_y->size[0] *
        (c5_i17 - 1)) - 1];
      c5_i18 = c5_dotProd->size[0];
      c5_i19 = (int32_T)c5_b_v;
      if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
        emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_qi_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i20 = c5_dotProd->size[1];
      c5_i21 = (int32_T)c5_b_p;
      if ((c5_i21 < 1) || (c5_i21 > c5_i20)) {
        emlrtDynamicBoundsCheckR2012b(c5_i21, 1, c5_i20, &c5_ri_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_dotProd->vector.data[(c5_i19 + c5_dotProd->size[0] * (c5_i21 - 1)) - 1]
        = c5_x1 * c5_x2 + c5_y1 * c5_y2;
      c5_crossProd = c5_y2 * c5_x1 - c5_x2 * c5_y1;
      c5_x = c5_crossProd;
      c5_b_x = c5_x;
      c5_b_x = muDoubleScalarSign(c5_b_x);
      c5_i22 = c5_signCrossProd->size[0];
      c5_i23 = (int32_T)c5_b_v;
      if ((c5_i23 < 1) || (c5_i23 > c5_i22)) {
        emlrtDynamicBoundsCheckR2012b(c5_i23, 1, c5_i22, &c5_si_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i24 = c5_signCrossProd->size[1];
      c5_i25 = (int32_T)c5_b_p;
      if ((c5_i25 < 1) || (c5_i25 > c5_i24)) {
        emlrtDynamicBoundsCheckR2012b(c5_i25, 1, c5_i24, &c5_ti_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_signCrossProd->vector.data[(c5_i23 + c5_signCrossProd->size[0] *
        (c5_i25 - 1)) - 1] = c5_b_x;
      c5_c_x = c5_crossProd;
      c5_d_x = c5_c_x;
      c5_e_x = c5_d_x;
      c5_y = muDoubleScalarAbs(c5_e_x);
      c5_i26 = c5_scaledEps->size[0];
      c5_i27 = (int32_T)c5_b_v;
      if ((c5_i27 < 1) || (c5_i27 > c5_i26)) {
        emlrtDynamicBoundsCheckR2012b(c5_i27, 1, c5_i26, &c5_ui_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      if (c5_y < c5_scaledEps->vector.data[c5_i27 - 1]) {
        c5_i28 = c5_signCrossProd->size[0];
        c5_i29 = (int32_T)c5_b_v;
        if ((c5_i29 < 1) || (c5_i29 > c5_i28)) {
          emlrtDynamicBoundsCheckR2012b(c5_i29, 1, c5_i28, &c5_vi_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i30 = c5_signCrossProd->size[1];
        c5_i31 = (int32_T)c5_b_p;
        if ((c5_i31 < 1) || (c5_i31 > c5_i30)) {
          emlrtDynamicBoundsCheckR2012b(c5_i31, 1, c5_i30, &c5_wi_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_signCrossProd->vector.data[(c5_i29 + c5_signCrossProd->size[0] *
          (c5_i31 - 1)) - 1] = 0.0;
      }
    }
  }
}

static void c5_findInsidePoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_transPolygon_x, c5_coder_array_real_T_2D *c5_transPolygon_y,
  c5_coder_array_real_T_2D *c5_signCrossProd, c5_coder_array_boolean_T *c5_in)
{
  emlrtStack c5_st;
  real_T c5_b_p;
  real_T c5_b_v;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_d;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_diffQuad;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_numPoints;
  real_T c5_numVertices;
  real_T c5_quadNum1;
  real_T c5_quadNum2;
  real_T c5_sumDiffQuad;
  real_T c5_x;
  real_T c5_y;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_p;
  int32_T c5_v;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b_isPositive_x;
  boolean_T c5_b_isPositive_y;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_f_b;
  boolean_T c5_g_b;
  boolean_T c5_h_b;
  boolean_T c5_isPositive_x;
  boolean_T c5_isPositive_y;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_numPoints = (real_T)c5_transPolygon_x->size[1];
  c5_numVertices = (real_T)c5_transPolygon_x->size[0];
  c5_st.site = &c5_xj_emlrtRSI;
  c5_array_boolean_T_SetSize(chartInstance, &c5_st, c5_in, &c5_le_emlrtRTEI,
    (int32_T)c5_numPoints);
  c5_i = (int32_T)c5_numPoints - 1;
  for (c5_p = 0; c5_p <= c5_i; c5_p++) {
    c5_b_p = (real_T)c5_p + 1.0;
    c5_sumDiffQuad = 0.0;
    c5_d = c5_numVertices - 1.0;
    c5_i1 = (int32_T)c5_d - 1;
    for (c5_v = 0; c5_v <= c5_i1; c5_v++) {
      c5_b_v = (real_T)c5_v + 1.0;
      c5_i4 = c5_transPolygon_x->size[0];
      c5_i5 = (int32_T)c5_b_v;
      if ((c5_i5 < 1) || (c5_i5 > c5_i4)) {
        emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i4, &c5_yi_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i6 = c5_transPolygon_x->size[1];
      c5_i7 = (int32_T)c5_b_p;
      if ((c5_i7 < 1) || (c5_i7 > c5_i6)) {
        emlrtDynamicBoundsCheckR2012b(c5_i7, 1, c5_i6, &c5_aj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_x = c5_transPolygon_x->vector.data[(c5_i5 + c5_transPolygon_x->size[0] *
        (c5_i7 - 1)) - 1];
      c5_i8 = c5_transPolygon_y->size[0];
      c5_i9 = (int32_T)c5_b_v;
      if ((c5_i9 < 1) || (c5_i9 > c5_i8)) {
        emlrtDynamicBoundsCheckR2012b(c5_i9, 1, c5_i8, &c5_bj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i10 = c5_transPolygon_y->size[1];
      c5_i11 = (int32_T)c5_b_p;
      if ((c5_i11 < 1) || (c5_i11 > c5_i10)) {
        emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_i10, &c5_cj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_y = c5_transPolygon_y->vector.data[(c5_i9 + c5_transPolygon_y->size[0] *
        (c5_i11 - 1)) - 1];
      c5_isPositive_x = (c5_x > 0.0);
      c5_isPositive_y = (c5_y > 0.0);
      c5_c_b = !c5_isPositive_y;
      c5_b1 = !c5_isPositive_x;
      c5_b2 = !c5_isPositive_y;
      c5_b3 = !c5_isPositive_x;
      c5_quadNum1 = ((real_T)(c5_b3 && c5_isPositive_y) + 2.0 * (real_T)(c5_b1 &&
        c5_b2)) + 3.0 * (real_T)(c5_isPositive_x && c5_c_b);
      c5_b_x = c5_x;
      c5_d_b = muDoubleScalarIsNaN(c5_b_x);
      if (c5_d_b) {
        c5_quadNum1 = rtNaN;
      } else {
        c5_c_x = c5_y;
        c5_e_b = muDoubleScalarIsNaN(c5_c_x);
        if (c5_e_b) {
          c5_quadNum1 = rtNaN;
        }
      }

      c5_i12 = c5_transPolygon_x->size[0];
      c5_i13 = (int32_T)(c5_b_v + 1.0);
      if ((c5_i13 < 1) || (c5_i13 > c5_i12)) {
        emlrtDynamicBoundsCheckR2012b(c5_i13, 1, c5_i12, &c5_dj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i14 = c5_transPolygon_x->size[1];
      c5_i15 = (int32_T)c5_b_p;
      if ((c5_i15 < 1) || (c5_i15 > c5_i14)) {
        emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i14, &c5_ej_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_d_x = c5_transPolygon_x->vector.data[(c5_i13 + c5_transPolygon_x->size
        [0] * (c5_i15 - 1)) - 1];
      c5_i16 = c5_transPolygon_y->size[0];
      c5_i17 = (int32_T)(c5_b_v + 1.0);
      if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
        emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_fj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i18 = c5_transPolygon_y->size[1];
      c5_i19 = (int32_T)c5_b_p;
      if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
        emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_gj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_b_y = c5_transPolygon_y->vector.data[(c5_i17 + c5_transPolygon_y->size
        [0] * (c5_i19 - 1)) - 1];
      c5_b_isPositive_x = (c5_d_x > 0.0);
      c5_b_isPositive_y = (c5_b_y > 0.0);
      c5_b4 = !c5_b_isPositive_y;
      c5_b5 = !c5_b_isPositive_x;
      c5_b6 = !c5_b_isPositive_y;
      c5_b7 = !c5_b_isPositive_x;
      c5_quadNum2 = ((real_T)(c5_b7 && c5_b_isPositive_y) + 2.0 * (real_T)(c5_b5
        && c5_b6)) + 3.0 * (real_T)(c5_b_isPositive_x && c5_b4);
      c5_e_x = c5_d_x;
      c5_f_b = muDoubleScalarIsNaN(c5_e_x);
      if (c5_f_b) {
        c5_quadNum2 = rtNaN;
      } else {
        c5_f_x = c5_b_y;
        c5_g_b = muDoubleScalarIsNaN(c5_f_x);
        if (c5_g_b) {
          c5_quadNum2 = rtNaN;
        }
      }

      c5_diffQuad = c5_quadNum2 - c5_quadNum1;
      c5_g_x = c5_diffQuad;
      c5_h_x = c5_g_x;
      c5_i_x = c5_h_x;
      c5_c_y = muDoubleScalarAbs(c5_i_x);
      if (c5_c_y == 3.0) {
        c5_diffQuad = -c5_diffQuad / 3.0;
      } else {
        c5_j_x = c5_diffQuad;
        c5_k_x = c5_j_x;
        c5_l_x = c5_k_x;
        c5_d_y = muDoubleScalarAbs(c5_l_x);
        if (c5_d_y == 2.0) {
          c5_i20 = c5_signCrossProd->size[0];
          c5_i21 = (int32_T)c5_b_v;
          if ((c5_i21 < 1) || (c5_i21 > c5_i20)) {
            emlrtDynamicBoundsCheckR2012b(c5_i21, 1, c5_i20, &c5_hj_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i22 = c5_signCrossProd->size[1];
          c5_i23 = (int32_T)c5_b_p;
          if ((c5_i23 < 1) || (c5_i23 > c5_i22)) {
            emlrtDynamicBoundsCheckR2012b(c5_i23, 1, c5_i22, &c5_ij_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_diffQuad = 2.0 * c5_signCrossProd->vector.data[(c5_i21 +
            c5_signCrossProd->size[0] * (c5_i23 - 1)) - 1];
        } else {
          c5_m_x = c5_diffQuad;
          c5_h_b = muDoubleScalarIsNaN(c5_m_x);
          if (c5_h_b) {
            c5_diffQuad = 0.0;
          }
        }
      }

      c5_sumDiffQuad += c5_diffQuad;
    }

    c5_i2 = c5_in->size[0];
    c5_i3 = (int32_T)c5_b_p;
    if ((c5_i3 < 1) || (c5_i3 > c5_i2)) {
      emlrtDynamicBoundsCheckR2012b(c5_i3, 1, c5_i2, &c5_xi_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_in->vector.data[c5_i3 - 1] = (c5_sumDiffQuad != 0.0);
  }
}

static void c5_findBoundaryPoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd,
  c5_coder_array_boolean_T *c5_in, c5_coder_array_boolean_T *c5_on,
  c5_coder_array_boolean_T *c5_b_in)
{
  c5_coder_array_real_T_2D c5_b_dotProd;
  c5_coder_array_real_T_2D c5_b_signCrossProd;
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  c5_array_boolean_T_SetSize(chartInstance, c5_sp, c5_b_in, &c5_me_emlrtRTEI,
    c5_in->size[0]);
  c5_loop_ub = c5_in->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_in->vector.data[c5_i] = c5_in->vector.data[c5_i];
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_signCrossProd);
  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, &c5_b_signCrossProd,
    &c5_me_emlrtRTEI, c5_signCrossProd->size[0], c5_signCrossProd->size[1]);
  c5_b_loop_ub = c5_signCrossProd->size[0] * c5_signCrossProd->size[1] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_signCrossProd.vector.data[c5_i1] = c5_signCrossProd->vector.data[c5_i1];
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_dotProd);
  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, &c5_b_dotProd,
    &c5_me_emlrtRTEI, c5_dotProd->size[0], c5_dotProd->size[1]);
  c5_c_loop_ub = c5_dotProd->size[0] * c5_dotProd->size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_dotProd.vector.data[c5_i2] = c5_dotProd->vector.data[c5_i2];
  }

  c5_b_findBoundaryPoints(chartInstance, c5_sp, &c5_b_signCrossProd,
    &c5_b_dotProd, c5_b_in, c5_on);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_dotProd);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_signCrossProd);
}

static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_x)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_a;
  real_T c5_vlen;
  int32_T c5_b_a;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_f_b;
  int32_T c5_i2;
  int32_T c5_ix;
  int32_T c5_vspread;
  boolean_T c5_c_b;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  boolean_T c5_y;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_mg_emlrtRSI;
  if ((c5_x->size[0] == 1) || ((real_T)c5_x->size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c5_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_y = true;
  c5_vlen = (real_T)c5_x->size[0];
  c5_a = c5_vlen;
  c5_c = (int32_T)c5_a;
  c5_b_a = c5_c - 1;
  c5_vspread = c5_b_a;
  c5_d_b = c5_vspread;
  c5_i2 = c5_d_b;
  c5_c_a = c5_i2 + 1;
  c5_i2 = c5_c_a;
  c5_b_st.site = &c5_bd_emlrtRSI;
  c5_e_b = c5_i2;
  c5_f_b = c5_e_b;
  if (c5_f_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_f_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_ix = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ix + 1 <= c5_i2)) {
    if (!c5_x->vector.data[c5_ix]) {
      c5_y = false;
      c5_exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_y;
}

static void c5_assertValidSizeArg(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_1[2])
{
  static char_T c5_b_cv[57] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 's', 's', 'e', 'r', 't', '_',
    'v', 'a', 'l', 'i', 'd', '_', 's', 'i', 'z', 'e', '_', 'a', 'r', 'g', '_',
    'i', 'n', 'v', 'a', 'l', 'i', 'd', 'S', 'i', 'z', 'e', 'V', 'e', 'c', 't',
    'o', 'r' };

  static char_T c5_b_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_k;
  real_T c5_d_k;
  real_T c5_n;
  real_T c5_x;
  int32_T c5_b_u;
  int32_T c5_c_k;
  int32_T c5_exitg1;
  int32_T c5_k;
  int32_T c5_u;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_p;
  (void)chartInstance;
  c5_k = 0;
  do {
    c5_exitg1 = 0;
    if (c5_k < 2) {
      c5_b_k = (real_T)c5_k + 1.0;
      if (c5_varargin_1[(int32_T)c5_b_k - 1] != c5_varargin_1[(int32_T)c5_b_k -
          1]) {
        c5_p = false;
        c5_exitg1 = 1;
      } else {
        c5_x = c5_varargin_1[(int32_T)c5_b_k - 1];
        c5_c_b = muDoubleScalarIsInf(c5_x);
        if (c5_c_b) {
          c5_p = false;
          c5_exitg1 = 1;
        } else {
          c5_k++;
        }
      }
    } else {
      c5_p = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  if (c5_p) {
    c5_d_b = true;
  } else {
    c5_d_b = false;
  }

  if (!c5_d_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 57),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 57),
                  false);
    c5_u = MIN_int32_T;
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_u, 6, 0U, 0, 0U, 0), false);
    c5_b_u = MAX_int32_T;
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_b_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(c5_sp, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 3U, 14, c5_b_y, 14, c5_d_y, 14, c5_f_y)));
  }

  c5_n = 1.0;
  for (c5_c_k = 0; c5_c_k < 2; c5_c_k++) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    if (c5_varargin_1[(int32_T)c5_d_k - 1] <= 0.0) {
      c5_n = 0.0;
    } else {
      c5_n *= c5_varargin_1[(int32_T)c5_d_k - 1];
    }
  }

  if (!(c5_n <= 2.147483647E+9)) {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c5_sp, &c5_s_emlrtMCI, "error", 0U, 2U, 14, c5_c_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }
}

static void c5_diff(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_x,
                    c5_coder_array_real_T_2D *c5_y)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_ySize[2];
  real_T c5_work_data[1];
  real_T c5_tmp1;
  real_T c5_tmp2;
  int32_T c5_d_b;
  int32_T c5_dimSize;
  int32_T c5_e_b;
  int32_T c5_i;
  int32_T c5_ixLead;
  int32_T c5_ixStart;
  int32_T c5_iyLead;
  int32_T c5_iyStart;
  int32_T c5_k;
  int32_T c5_m;
  int32_T c5_newDimSize;
  int32_T c5_orderForDim;
  int32_T c5_r;
  boolean_T c5_b1;
  boolean_T c5_c_b;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_dimSize = c5_x->size[0];
  if (c5_dimSize == 0) {
    c5_st.site = &c5_mj_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_y, &c5_qe_emlrtRTEI, 0,
      2);
  } else {
    c5_i = c5_dimSize - 1;
    c5_orderForDim = muIntScalarMin_sint32(c5_i, 1);
    if (c5_orderForDim < 1) {
      c5_st.site = &c5_nj_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_y, &c5_pe_emlrtRTEI,
        0, 2);
    } else {
      if (c5_dimSize != 1) {
        c5_c_b = true;
      } else {
        c5_c_b = false;
      }

      if (!c5_c_b) {
        c5_b_y = NULL;
        sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          36), false);
        c5_c_y = NULL;
        sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          36), false);
        sf_mex_call(c5_sp, &c5_t_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                    sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(c5_sp, NULL, "message", 1U, 1U, 14, c5_c_y)));
      }

      c5_newDimSize = c5_dimSize - 1;
      c5_ySize[0] = (real_T)c5_newDimSize;
      c5_st.site = &c5_oj_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_y, &c5_oe_emlrtRTEI,
        (int32_T)c5_ySize[0], 2);
      c5_b1 = (c5_y->size[0] == 0);
      if (!c5_b1) {
        c5_ixStart = 0;
        c5_iyStart = 1;
        for (c5_r = 0; c5_r < 2; c5_r++) {
          c5_ixLead = c5_ixStart;
          c5_iyLead = c5_iyStart - 1;
          c5_work_data[0] = c5_x->vector.data[c5_ixStart];
          c5_st.site = &c5_ug_emlrtRSI;
          c5_d_b = c5_dimSize;
          c5_e_b = c5_d_b;
          if (c5_e_b < 2) {
            c5_overflow = false;
          } else {
            c5_overflow = (c5_e_b > 2147483646);
          }

          if (c5_overflow) {
            c5_b_st.site = &c5_lb_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
          }

          for (c5_m = 2; c5_m <= c5_dimSize; c5_m++) {
            c5_tmp1 = c5_x->vector.data[c5_ixLead + 1];
            c5_st.site = &c5_tg_emlrtRSI;
            for (c5_k = 0; c5_k < 1; c5_k++) {
              c5_tmp2 = c5_work_data[0];
              c5_work_data[0] = c5_tmp1;
              c5_tmp1 -= c5_tmp2;
            }

            c5_ixLead++;
            c5_y->vector.data[c5_iyLead] = c5_tmp1;
            c5_iyLead++;
          }

          c5_ixStart += c5_dimSize;
          c5_iyStart += c5_newDimSize;
        }
      }
    }
  }
}

static real_T c5_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, real_T c5_varargin_1)
{
  real_T c5_a;
  real_T c5_x;
  (void)chartInstance;
  c5_x = c5_varargin_1;
  c5_a = c5_x;
  return c5_a * c5_a;
}

static real_T c5_sum(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_g_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_s;
  real_T c5_y;
  int32_T c5_a;
  int32_T c5_b_vlen;
  int32_T c5_c_vlen;
  int32_T c5_d_b;
  int32_T c5_d_vlen;
  int32_T c5_e_b;
  int32_T c5_ib;
  int32_T c5_inb;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_vlen;
  boolean_T c5_c_b;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_g_st.prev = &c5_f_st;
  c5_g_st.tls = c5_f_st.tls;
  c5_st.site = &c5_vg_emlrtRSI;
  if ((c5_x->size[0] == 1) || ((real_T)c5_x->size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c5_st, &c5_u_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_b_st.site = &c5_wg_emlrtRSI;
  c5_vlen = c5_x->size[0];
  c5_c_st.site = &c5_xg_emlrtRSI;
  c5_b_vlen = c5_vlen;
  if ((c5_x->size[0] == 0) || (c5_b_vlen == 0)) {
    c5_y = 0.0;
  } else {
    c5_d_st.site = &c5_eh_emlrtRSI;
    c5_c_vlen = c5_b_vlen;
    c5_e_st.site = &c5_fh_emlrtRSI;
    c5_d_vlen = c5_c_vlen;
    if (c5_d_vlen < 4096) {
      c5_f_st.site = &c5_gh_emlrtRSI;
      c5_y = c5_b_sumColumnB(chartInstance, &c5_f_st, c5_x, c5_d_vlen);
    } else {
      c5_a = c5_d_vlen;
      c5_nfb = c5_div_nzp_s32(chartInstance, c5_a, 4096, 0, 0U, 0, 0);
      c5_inb = c5_nfb << 12;
      c5_lidx = c5_inb;
      c5_nleft = c5_d_vlen - c5_inb;
      c5_s = c5_b_sumColumnB4(chartInstance, c5_x, 1);
      c5_f_st.site = &c5_hh_emlrtRSI;
      c5_d_b = c5_nfb;
      c5_e_b = c5_d_b;
      if (c5_e_b < 2) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_e_b > 2147483646);
      }

      if (c5_overflow) {
        c5_g_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_g_st);
      }

      for (c5_ib = 2; c5_ib <= c5_nfb; c5_ib++) {
        c5_s += c5_b_sumColumnB4(chartInstance, c5_x, 1 + ((c5_ib - 1) << 12));
      }

      if (c5_nleft > 0) {
        c5_f_st.site = &c5_ih_emlrtRSI;
        c5_s += c5_c_sumColumnB(chartInstance, &c5_f_st, c5_x, c5_nleft, c5_lidx
          + 1);
      }

      c5_y = c5_s;
    }
  }

  return c5_y;
}

static real_T c5_b_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, int32_T
  c5_vlen)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_a;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_h_b;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_vstart;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_jh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_y = c5_x->vector.data[0];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_mh_emlrtRSI;
    c5_c_b = c5_i;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    c5_i1 = (uint16_T)c5_i - 1;
    for (c5_c_k = 0; c5_c_k <= c5_i1; c5_c_k++) {
      c5_e_k = c5_c_k;
      c5_y += c5_x->vector.data[c5_e_k + 1];
    }
  } else {
    c5_a = c5_vlen;
    c5_nfb = c5_div_nzp_s32(chartInstance, c5_a, 1024, 0, 0U, 0, 0);
    c5_inb = c5_nfb << 10;
    c5_y = c5_x->vector.data[0];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_b_k = c5_k;
      c5_y += c5_x->vector.data[c5_b_k + 1];
    }

    c5_st.site = &c5_kh_emlrtRSI;
    c5_e_b = c5_nfb;
    c5_f_b = c5_e_b;
    if (c5_f_b < 2) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_f_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_d_k = 2; c5_d_k <= c5_nfb; c5_d_k++) {
      c5_vstart = (c5_d_k - 1) << 10;
      c5_b_y = c5_x->vector.data[c5_vstart];
      for (c5_f_k = 0; c5_f_k < 1023; c5_f_k++) {
        c5_g_k = c5_f_k;
        c5_b_y += c5_x->vector.data[(c5_vstart + c5_g_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_inb;
      c5_st.site = &c5_lh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_b_vstart = c5_lidx;
      c5_c_y = c5_x->vector.data[c5_b_vstart];
      c5_i2 = c5_c_vlen;
      c5_b_st.site = &c5_mh_emlrtRSI;
      c5_g_b = c5_i2;
      c5_h_b = c5_g_b;
      if (c5_h_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_h_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_c_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i2; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += c5_x->vector.data[(c5_b_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static real_T c5_b_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_x, int32_T c5_vstart)
{
  real_T c5_psum1;
  real_T c5_psum2;
  real_T c5_psum3;
  real_T c5_psum4;
  int32_T c5_b_k;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_k;
  (void)chartInstance;
  c5_i2 = c5_vstart + 1023;
  c5_i3 = c5_vstart + 2047;
  c5_i4 = c5_vstart + 3071;
  c5_psum1 = c5_x->vector.data[c5_vstart - 1];
  c5_psum2 = c5_x->vector.data[c5_i2];
  c5_psum3 = c5_x->vector.data[c5_i3];
  c5_psum4 = c5_x->vector.data[c5_i4];
  for (c5_k = 0; c5_k < 1023; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_psum1 += c5_x->vector.data[(c5_vstart + c5_b_k) - 1];
    c5_psum2 += c5_x->vector.data[c5_i2 + c5_b_k];
    c5_psum3 += c5_x->vector.data[c5_i3 + c5_b_k];
    c5_psum4 += c5_x->vector.data[c5_i4 + c5_b_k];
  }

  return (c5_psum1 + c5_psum2) + (c5_psum3 + c5_psum4);
}

static real_T c5_c_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, int32_T
  c5_vlen, int32_T c5_vstart)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_a;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_c_vstart;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_d_vstart;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_e_vstart;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_h_b;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_jh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_b_vstart = c5_vstart - 1;
    c5_y = c5_x->vector.data[c5_b_vstart];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_mh_emlrtRSI;
    c5_c_b = c5_i;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_c_k = 0; c5_c_k < c5_i; c5_c_k++) {
      c5_e_k = c5_c_k;
      c5_y += c5_x->vector.data[(c5_b_vstart + c5_e_k) + 1];
    }
  } else {
    c5_a = c5_vlen;
    c5_nfb = c5_div_nzp_s32(chartInstance, c5_a, 1024, 0, 0U, 0, 0);
    c5_inb = c5_nfb << 10;
    c5_c_vstart = c5_vstart - 1;
    c5_y = c5_x->vector.data[c5_c_vstart];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_b_k = c5_k;
      c5_y += c5_x->vector.data[(c5_c_vstart + c5_b_k) + 1];
    }

    c5_st.site = &c5_kh_emlrtRSI;
    c5_e_b = c5_nfb;
    c5_f_b = c5_e_b;
    if (c5_f_b < 2) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_f_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_d_k = 2; c5_d_k <= c5_nfb; c5_d_k++) {
      c5_d_vstart = (c5_vstart + ((c5_d_k - 1) << 10)) - 1;
      c5_b_y = c5_x->vector.data[c5_d_vstart];
      for (c5_f_k = 0; c5_f_k < 1023; c5_f_k++) {
        c5_g_k = c5_f_k;
        c5_b_y += c5_x->vector.data[(c5_d_vstart + c5_g_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_vstart + c5_inb;
      c5_st.site = &c5_lh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_e_vstart = c5_lidx - 1;
      c5_c_y = c5_x->vector.data[c5_e_vstart];
      c5_i1 = c5_c_vlen;
      c5_b_st.site = &c5_mh_emlrtRSI;
      c5_g_b = c5_i1;
      c5_h_b = c5_g_b;
      if (c5_h_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_h_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_c_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i1; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += c5_x->vector.data[(c5_e_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T *c5_x,
                    c5_coder_array_real_T *c5_b_x, c5_coder_array_int32_T
                    *c5_idx)
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_x, &c5_re_emlrtRTEI,
    c5_x->size[0]);
  c5_loop_ub = c5_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x->vector.data[c5_i] = c5_x->vector.data[c5_i];
  }

  c5_b_sort(chartInstance, c5_sp, c5_b_x, c5_idx);
}

static void c5_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, c5_coder_array_int32_T
  *c5_idx, c5_coder_array_real_T *c5_b_x)
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_x, &c5_se_emlrtRTEI,
    c5_x->size[0]);
  c5_loop_ub = c5_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x->vector.data[c5_i] = c5_x->vector.data[c5_i];
  }

  c5_b_sortIdx(chartInstance, c5_sp, c5_b_x, c5_idx);
}

static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset, c5_coder_array_int32_T
  *c5_b_idx, c5_coder_array_real_T *c5_b_x)
{
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_te_emlrtRTEI,
    c5_idx->size[0]);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_x, &c5_te_emlrtRTEI,
    c5_x->size[0]);
  c5_b_loop_ub = c5_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_x->vector.data[c5_i1] = c5_x->vector.data[c5_i1];
  }

  c5_b_merge_pow2_block(chartInstance, c5_sp, c5_b_idx, c5_b_x, c5_offset);
}

static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx, c5_coder_array_real_T
  *c5_x, int32_T c5_offset, int32_T c5_n, int32_T c5_preSortLevel,
  c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T *c5_xwork,
  c5_coder_array_int32_T *c5_b_idx, c5_coder_array_real_T *c5_b_x,
  c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork)
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_ue_emlrtRTEI,
    c5_idx->size[0]);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_x, &c5_ue_emlrtRTEI,
    c5_x->size[0]);
  c5_b_loop_ub = c5_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_x->vector.data[c5_i1] = c5_x->vector.data[c5_i1];
  }

  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_iwork, &c5_ue_emlrtRTEI,
    c5_iwork->size[0]);
  c5_c_loop_ub = c5_iwork->size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_iwork->vector.data[c5_i2] = c5_iwork->vector.data[c5_i2];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_xwork, &c5_ue_emlrtRTEI,
    c5_xwork->size[0]);
  c5_d_loop_ub = c5_xwork->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_b_xwork->vector.data[c5_i3] = c5_xwork->vector.data[c5_i3];
  }

  c5_b_merge_block(chartInstance, c5_sp, c5_b_idx, c5_b_x, c5_offset, c5_n,
                   c5_preSortLevel, c5_b_iwork, c5_b_xwork);
}

static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
                     c5_coder_array_real_T *c5_x, int32_T c5_offset, int32_T
                     c5_np, int32_T c5_nq, c5_coder_array_int32_T *c5_iwork,
                     c5_coder_array_real_T *c5_xwork, c5_coder_array_int32_T
                     *c5_b_idx, c5_coder_array_real_T *c5_b_x,
                     c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T
                     *c5_b_xwork)
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_ve_emlrtRTEI,
    c5_idx->size[0]);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_x, &c5_ve_emlrtRTEI,
    c5_x->size[0]);
  c5_b_loop_ub = c5_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_x->vector.data[c5_i1] = c5_x->vector.data[c5_i1];
  }

  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_iwork, &c5_ve_emlrtRTEI,
    c5_iwork->size[0]);
  c5_c_loop_ub = c5_iwork->size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_iwork->vector.data[c5_i2] = c5_iwork->vector.data[c5_i2];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_xwork, &c5_ve_emlrtRTEI,
    c5_xwork->size[0]);
  c5_d_loop_ub = c5_xwork->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_b_xwork->vector.data[c5_i3] = c5_xwork->vector.data[c5_i3];
  }

  c5_b_merge(chartInstance, c5_sp, c5_b_idx, c5_b_x, c5_offset, c5_np, c5_nq,
             c5_b_iwork, c5_b_xwork);
}

const mxArray *sf_c5_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr), &c5_thisId);
  sf_mex_destroy(&c5_nullptr);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_d;
  real_T c5_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T c5_y[19200])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_nullptr);
}

static void c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T c5_y[19200])
{
  int32_T c5_i;
  boolean_T c5_bv[19200];
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_y[c5_i] = c5_bv[c5_i];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_nullptr, const
  char_T *c5_identifier, c5_coder_array_real_T_2D *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_f_emlrt_marshallIn(chartInstance, c5_sp, sf_mex_dup(c5_nullptr), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_nullptr);
}

static void c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_u, const
  emlrtMsgIdentifier *c5_parentId, c5_coder_array_real_T_2D *c5_y)
{
  c5_coder_array_real_T_2D c5_r;
  int32_T c5_iv[2];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  boolean_T c5_bv[2];
  c5_array_real_T_2D_Constructor(chartInstance, &c5_r);
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_iv[c5_i] = 10000;
  }

  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, &c5_r, (emlrtRTEInfo *)NULL,
    sf_mex_get_dimension(c5_u, 0), sf_mex_get_dimension(c5_u, 1));
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_bv[c5_i1] = true;
  }

  sf_mex_import_vs(c5_parentId, sf_mex_dup(c5_u), c5_r.vector.data, 1, 0, 0U, 1,
                   0U, 2, c5_bv, c5_iv, c5_r.size);
  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_y, (emlrtRTEInfo *)NULL,
    c5_r.size[0], c5_r.size[1]);
  c5_loop_ub = c5_r.size[0] * c5_r.size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_y->vector.data[c5_i2] = c5_r.vector.data[c5_i2];
  }

  sf_mex_destroy(&c5_u);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_r);
}

static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig)
{
  real_T c5_d;
  uint64_T c5_u;
  uint64_T c5_u1;
  int32_T c5_i;
  int32_T c5_i1;
  *c5_mxData = NULL;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 4U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_imgin, 3,
      0U, 1, 0U, 3, 120, 160, 3), false);
    break;

   case 5U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_bw, 11,
      0U, 1, 0U, 2, 120, 160), false);
    break;

   case 6U:
    c5_d = *chartInstance->c5_N;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 11U:
    c5_i = (*chartInstance->c5_ln1_sizes)[0] * (*chartInstance->c5_ln1_sizes)[1];
    if (c5_i <= 0) {
      c5_u = 0ULL;
    } else {
      c5_u = (uint64_T)c5_i << 3;
    }

    if (c5_u <= 150000ULL) {
      sf_mex_assign(c5_mxData, sf_mex_create("mxData",
        chartInstance->c5_ln1_data, 0, 0U, 1, 0U, 2,
        (*chartInstance->c5_ln1_sizes)[0], (*chartInstance->c5_ln1_sizes)[1]),
                    false);
    } else {
      *c5_isValueTooBig = 1U;
    }
    break;

   case 12U:
    c5_i1 = (*chartInstance->c5_ln2_sizes)[0] * (*chartInstance->c5_ln2_sizes)[1];
    if (c5_i1 <= 0) {
      c5_u1 = 0ULL;
    } else {
      c5_u1 = (uint64_T)c5_i1 << 3;
    }

    if (c5_u1 <= 150000ULL) {
      sf_mex_assign(c5_mxData, sf_mex_create("mxData",
        chartInstance->c5_ln2_data, 0, 0U, 1, 0U, 2,
        (*chartInstance->c5_ln2_sizes)[0], (*chartInstance->c5_ln2_sizes)[1]),
                    false);
    } else {
      *c5_isValueTooBig = 1U;
    }
    break;
  }
}

static void c5_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, const mxArray *c5_input0, const
                     mxArray *c5_input1, const mxArray *c5_input2)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 3U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1), 14, sf_mex_dup(c5_input2));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  sf_mex_destroy(&c5_input2);
}

static const mxArray *c5_assert(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "assert", 0U, 2U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static const mxArray *c5_b_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static void c5_c_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
}

static const mxArray *c5_d_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static void c5_e_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
}

static void c5_b_findBoundaryPoints(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_signCrossProd, c5_coder_array_real_T_2D *c5_dotProd,
  c5_coder_array_boolean_T *c5_in, c5_coder_array_boolean_T *c5_on)
{
  emlrtStack c5_st;
  real_T c5_b_k;
  real_T c5_b_p;
  real_T c5_numPoints;
  real_T c5_numProds;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_p;
  boolean_T c5_exitg1;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_numPoints = (real_T)c5_signCrossProd->size[1];
  c5_numProds = (real_T)c5_signCrossProd->size[0];
  c5_st.site = &c5_wj_emlrtRSI;
  c5_array_boolean_T_SetSize(chartInstance, &c5_st, c5_on, &c5_we_emlrtRTEI,
    (int32_T)c5_numPoints);
  c5_loop_ub = (int32_T)c5_numPoints - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_on->vector.data[c5_i] = false;
  }

  c5_i1 = (int32_T)c5_numPoints - 1;
  for (c5_p = 0; c5_p <= c5_i1; c5_p++) {
    c5_b_p = (real_T)c5_p + 1.0;
    c5_i2 = (int32_T)c5_numProds - 1;
    c5_k = 0;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_k <= c5_i2)) {
      c5_b_k = (real_T)c5_k + 1.0;
      c5_i3 = c5_signCrossProd->size[0];
      c5_i4 = (int32_T)c5_b_k;
      if ((c5_i4 < 1) || (c5_i4 > c5_i3)) {
        emlrtDynamicBoundsCheckR2012b(c5_i4, 1, c5_i3, &c5_jj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i5 = c5_signCrossProd->size[1];
      c5_i6 = (int32_T)c5_b_p;
      if ((c5_i6 < 1) || (c5_i6 > c5_i5)) {
        emlrtDynamicBoundsCheckR2012b(c5_i6, 1, c5_i5, &c5_kj_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      if (c5_signCrossProd->vector.data[(c5_i4 + c5_signCrossProd->size[0] *
           (c5_i6 - 1)) - 1] == 0.0) {
        c5_i7 = c5_dotProd->size[0];
        c5_i8 = (int32_T)c5_b_k;
        if ((c5_i8 < 1) || (c5_i8 > c5_i7)) {
          emlrtDynamicBoundsCheckR2012b(c5_i8, 1, c5_i7, &c5_lj_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i9 = c5_dotProd->size[1];
        c5_i10 = (int32_T)c5_b_p;
        if ((c5_i10 < 1) || (c5_i10 > c5_i9)) {
          emlrtDynamicBoundsCheckR2012b(c5_i10, 1, c5_i9, &c5_mj_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        if (c5_dotProd->vector.data[(c5_i8 + c5_dotProd->size[0] * (c5_i10 - 1))
            - 1] <= 0.0) {
          c5_i11 = c5_on->size[0];
          c5_i12 = (int32_T)c5_b_p;
          if ((c5_i12 < 1) || (c5_i12 > c5_i11)) {
            emlrtDynamicBoundsCheckR2012b(c5_i12, 1, c5_i11, &c5_nj_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_on->vector.data[c5_i12 - 1] = true;
          c5_i13 = c5_in->size[0];
          c5_i14 = (int32_T)c5_b_p;
          if ((c5_i14 < 1) || (c5_i14 > c5_i13)) {
            emlrtDynamicBoundsCheckR2012b(c5_i14, 1, c5_i13, &c5_oj_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_in->vector.data[c5_i14 - 1] = true;
          c5_exitg1 = true;
        } else {
          c5_k++;
        }
      } else {
        c5_k++;
      }
    }
  }
}

static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x,
                      c5_coder_array_int32_T *c5_idx)
{
  c5_coder_array_int32_T c5_iidx;
  c5_coder_array_real_T c5_b_x;
  c5_coder_array_real_T c5_vwork;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_dv[2];
  real_T c5_d;
  real_T c5_d1;
  int32_T c5_iv[2];
  int32_T c5_b_dim;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_dim;
  int32_T c5_e_b;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i_b;
  int32_T c5_j;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_upperDim;
  int32_T c5_vlen;
  int32_T c5_vstride;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_array_real_T_Constructor(chartInstance, &c5_b_x);
  c5_st.site = &c5_aj_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_b_x, &c5_xe_emlrtRTEI,
    c5_x->size[0]);
  c5_loop_ub = c5_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x.vector.data[c5_i] = c5_x->vector.data[c5_i];
  }

  c5_dim = 2;
  if ((real_T)c5_b_x.size[0] != 1.0) {
    c5_dim = 1;
  }

  if (c5_dim <= 1) {
    c5_d = (real_T)c5_x->size[0];
  } else {
    c5_d = 1.0;
  }

  c5_vlen = (int32_T)c5_d;
  c5_iv[0] = c5_vlen;
  c5_array_real_T_Constructor(chartInstance, &c5_vwork);
  c5_st.site = &c5_yi_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_vwork, &c5_ye_emlrtRTEI,
    c5_iv[0]);
  c5_dv[0] = (real_T)c5_x->size[0];
  c5_st.site = &c5_ui_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_idx, &c5_af_emlrtRTEI,
    (int32_T)c5_dv[0]);
  c5_st.site = &c5_oh_emlrtRSI;
  c5_b_st.site = &c5_oh_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_x, &c5_bf_emlrtRTEI,
    c5_x->size[0]);
  c5_b_loop_ub = c5_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_x.vector.data[c5_i1] = c5_x->vector.data[c5_i1];
  }

  c5_b_dim = c5_dim - 1;
  c5_vstride = 1;
  c5_upperDim = c5_b_dim;
  c5_b_st.site = &c5_uh_emlrtRSI;
  c5_c_b = c5_upperDim;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_lb_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i2 = (uint8_T)c5_upperDim - 1;
  for (c5_k = 0; c5_k <= c5_i2; c5_k++) {
    c5_d1 = (real_T)c5_b_x.size[0];
    c5_vstride *= (int32_T)c5_d1;
  }

  c5_array_real_T_Destructor(chartInstance, &c5_b_x);
  c5_st.site = &c5_ph_emlrtRSI;
  c5_array_int32_T_Constructor(chartInstance, &c5_iidx);
  for (c5_b_i = 0; c5_b_i < 1; c5_b_i++) {
    c5_st.site = &c5_qh_emlrtRSI;
    c5_e_b = c5_vstride;
    c5_f_b = c5_e_b;
    if (c5_f_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_f_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_vstride; c5_j++) {
      c5_b_j = c5_j;
      c5_st.site = &c5_rh_emlrtRSI;
      c5_g_b = c5_vlen;
      c5_h_b = c5_g_b;
      if (c5_h_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_h_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_b_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      for (c5_b_k = 0; c5_b_k < c5_vlen; c5_b_k++) {
        c5_c_k = c5_b_k;
        c5_vwork.vector.data[c5_c_k] = c5_x->vector.data[c5_b_j + c5_c_k *
          c5_vstride];
      }

      c5_st.site = &c5_sh_emlrtRSI;
      c5_b_sortIdx(chartInstance, &c5_st, &c5_vwork, &c5_iidx);
      c5_st.site = &c5_th_emlrtRSI;
      c5_i_b = c5_vlen;
      c5_j_b = c5_i_b;
      if (c5_j_b < 1) {
        c5_d_overflow = false;
      } else {
        c5_d_overflow = (c5_j_b > 2147483646);
      }

      if (c5_d_overflow) {
        c5_b_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      for (c5_d_k = 0; c5_d_k < c5_vlen; c5_d_k++) {
        c5_c_k = c5_d_k;
        c5_x->vector.data[c5_b_j + c5_c_k * c5_vstride] =
          c5_vwork.vector.data[c5_c_k];
        c5_idx->vector.data[c5_b_j + c5_c_k * c5_vstride] =
          c5_iidx.vector.data[c5_c_k];
      }
    }
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_iidx);
  c5_array_real_T_Destructor(chartInstance, &c5_vwork);
}

static void c5_b_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_x, c5_coder_array_int32_T
  *c5_idx)
{
  c5_coder_array_int32_T c5_iwork;
  c5_coder_array_real_T c5_xwork;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  real_T c5_x4[4];
  real_T c5_dv[2];
  real_T c5_b_x;
  int32_T c5_idx4[4];
  int32_T c5_perm[4];
  int32_T c5_b_i1;
  int32_T c5_b_i2;
  int32_T c5_b_i3;
  int32_T c5_b_i4;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_b_n;
  int32_T c5_b_nNaNs;
  int32_T c5_b_nNonNaN;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_n;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_h_b;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i_b;
  int32_T c5_ib;
  int32_T c5_itmp;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_k_b;
  int32_T c5_l_b;
  int32_T c5_loop_ub;
  int32_T c5_m;
  int32_T c5_m_b;
  int32_T c5_n;
  int32_T c5_nBlocks;
  int32_T c5_nLastBlock;
  int32_T c5_nNaNs;
  int32_T c5_nNonNaN;
  int32_T c5_n_b;
  int32_T c5_o_b;
  int32_T c5_p_b;
  int32_T c5_preSortLevel;
  int32_T c5_q_b;
  int32_T c5_quartetOffset;
  int32_T c5_tailOffset;
  int32_T c5_wOffset;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_e_b;
  boolean_T c5_e_overflow;
  boolean_T c5_f_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_dv[0] = (real_T)c5_x->size[0];
  c5_st.site = &c5_ti_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_idx, &c5_cf_emlrtRTEI,
    (int32_T)c5_dv[0]);
  c5_loop_ub = (int32_T)c5_dv[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_idx->vector.data[c5_i] = 0;
  }

  if (c5_x->size[0] != 0) {
    c5_st.site = &c5_vh_emlrtRSI;
    c5_n = c5_x->size[0];
    c5_array_int32_T_Constructor(chartInstance, &c5_iwork);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_iwork, &c5_df_emlrtRTEI,
      c5_idx->size[0]);
    c5_b_loop_ub = c5_idx->size[0] - 1;
    for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
      c5_iwork.vector.data[c5_i1] = 0;
    }

    c5_dv[0] = (real_T)c5_x->size[0];
    c5_array_real_T_Constructor(chartInstance, &c5_xwork);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_xwork, &c5_ef_emlrtRTEI,
      (int32_T)c5_dv[0]);
    c5_b_st.site = &c5_wh_emlrtRSI;
    c5_b_n = c5_x->size[0];
    for (c5_i2 = 0; c5_i2 < 4; c5_i2++) {
      c5_x4[c5_i2] = 0.0;
    }

    for (c5_i3 = 0; c5_i3 < 4; c5_i3++) {
      c5_idx4[c5_i3] = 0;
    }

    c5_nNaNs = 0;
    c5_ib = 0;
    c5_c_st.site = &c5_di_emlrtRSI;
    c5_c_b = c5_b_n;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_d_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
    }

    for (c5_k = 0; c5_k < c5_b_n; c5_k++) {
      c5_b_k = c5_k;
      c5_b_x = c5_x->vector.data[c5_b_k];
      c5_e_b = muDoubleScalarIsNaN(c5_b_x);
      if (c5_e_b) {
        c5_idx->vector.data[(c5_b_n - c5_nNaNs) - 1] = c5_b_k + 1;
        c5_xwork.vector.data[(c5_b_n - c5_nNaNs) - 1] = c5_x->vector.data[c5_b_k];
        c5_nNaNs++;
      } else {
        c5_ib++;
        c5_idx4[c5_ib - 1] = c5_b_k + 1;
        c5_x4[c5_ib - 1] = c5_x->vector.data[c5_b_k];
        if (c5_ib == 4) {
          c5_quartetOffset = c5_b_k - c5_nNaNs;
          if (c5_x4[0] >= c5_x4[1]) {
            c5_b_i1 = 1;
            c5_b_i2 = 2;
          } else {
            c5_b_i1 = 2;
            c5_b_i2 = 1;
          }

          if (c5_x4[2] >= c5_x4[3]) {
            c5_b_i3 = 3;
            c5_b_i4 = 4;
          } else {
            c5_b_i3 = 4;
            c5_b_i4 = 3;
          }

          if (c5_x4[c5_b_i1 - 1] >= c5_x4[c5_b_i3 - 1]) {
            if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i3 - 1]) {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i2;
              c5_perm[2] = c5_b_i3;
              c5_perm[3] = c5_b_i4;
            } else if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i4 - 1]) {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i3;
              c5_perm[2] = c5_b_i2;
              c5_perm[3] = c5_b_i4;
            } else {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i3;
              c5_perm[2] = c5_b_i4;
              c5_perm[3] = c5_b_i2;
            }
          } else if (c5_x4[c5_b_i1 - 1] >= c5_x4[c5_b_i4 - 1]) {
            if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i4 - 1]) {
              c5_perm[0] = c5_b_i3;
              c5_perm[1] = c5_b_i1;
              c5_perm[2] = c5_b_i2;
              c5_perm[3] = c5_b_i4;
            } else {
              c5_perm[0] = c5_b_i3;
              c5_perm[1] = c5_b_i1;
              c5_perm[2] = c5_b_i4;
              c5_perm[3] = c5_b_i2;
            }
          } else {
            c5_perm[0] = c5_b_i3;
            c5_perm[1] = c5_b_i4;
            c5_perm[2] = c5_b_i1;
            c5_perm[3] = c5_b_i2;
          }

          c5_idx->vector.data[c5_quartetOffset - 3] = c5_idx4[c5_perm[0] - 1];
          c5_idx->vector.data[c5_quartetOffset - 2] = c5_idx4[c5_perm[1] - 1];
          c5_idx->vector.data[c5_quartetOffset - 1] = c5_idx4[c5_perm[2] - 1];
          c5_idx->vector.data[c5_quartetOffset] = c5_idx4[c5_perm[3] - 1];
          c5_x->vector.data[c5_quartetOffset - 3] = c5_x4[c5_perm[0] - 1];
          c5_x->vector.data[c5_quartetOffset - 2] = c5_x4[c5_perm[1] - 1];
          c5_x->vector.data[c5_quartetOffset - 1] = c5_x4[c5_perm[2] - 1];
          c5_x->vector.data[c5_quartetOffset] = c5_x4[c5_perm[3] - 1];
          c5_ib = 0;
        }
      }
    }

    c5_wOffset = (c5_b_n - c5_nNaNs) - 1;
    if (c5_ib > 0) {
      c5_c_n = c5_ib;
      for (c5_i4 = 0; c5_i4 < 4; c5_i4++) {
        c5_perm[c5_i4] = 0;
      }

      if (c5_c_n == 1) {
        c5_perm[0] = 1;
      } else if (c5_c_n == 2) {
        if (c5_x4[0] >= c5_x4[1]) {
          c5_perm[0] = 1;
          c5_perm[1] = 2;
        } else {
          c5_perm[0] = 2;
          c5_perm[1] = 1;
        }
      } else if (c5_x4[0] >= c5_x4[1]) {
        if (c5_x4[1] >= c5_x4[2]) {
          c5_perm[0] = 1;
          c5_perm[1] = 2;
          c5_perm[2] = 3;
        } else if (c5_x4[0] >= c5_x4[2]) {
          c5_perm[0] = 1;
          c5_perm[1] = 3;
          c5_perm[2] = 2;
        } else {
          c5_perm[0] = 3;
          c5_perm[1] = 1;
          c5_perm[2] = 2;
        }
      } else if (c5_x4[0] >= c5_x4[2]) {
        c5_perm[0] = 2;
        c5_perm[1] = 1;
        c5_perm[2] = 3;
      } else if (c5_x4[1] >= c5_x4[2]) {
        c5_perm[0] = 2;
        c5_perm[1] = 3;
        c5_perm[2] = 1;
      } else {
        c5_perm[0] = 3;
        c5_perm[1] = 2;
        c5_perm[2] = 1;
      }

      c5_c_st.site = &c5_ei_emlrtRSI;
      c5_h_b = c5_ib;
      c5_i_b = c5_h_b;
      if (c5_i_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_i_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_d_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
      }

      c5_i5 = (uint8_T)c5_ib - 1;
      for (c5_d_k = 0; c5_d_k <= c5_i5; c5_d_k++) {
        c5_b_k = c5_d_k;
        c5_idx->vector.data[((c5_wOffset - c5_ib) + c5_b_k) + 1] =
          c5_idx4[c5_perm[c5_b_k] - 1];
        c5_x->vector.data[((c5_wOffset - c5_ib) + c5_b_k) + 1] =
          c5_x4[c5_perm[c5_b_k] - 1];
      }
    }

    c5_m = c5_nNaNs >> 1;
    c5_c_st.site = &c5_fi_emlrtRSI;
    c5_f_b = c5_m;
    c5_g_b = c5_f_b;
    if (c5_g_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_g_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_d_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
    }

    for (c5_c_k = 0; c5_c_k < c5_m; c5_c_k++) {
      c5_b_k = c5_c_k + 1;
      c5_itmp = c5_idx->vector.data[c5_wOffset + c5_b_k];
      c5_idx->vector.data[c5_wOffset + c5_b_k] = c5_idx->vector.data[c5_b_n -
        c5_b_k];
      c5_idx->vector.data[c5_b_n - c5_b_k] = c5_itmp;
      c5_x->vector.data[c5_wOffset + c5_b_k] = c5_xwork.vector.data[c5_b_n -
        c5_b_k];
      c5_x->vector.data[c5_b_n - c5_b_k] = c5_xwork.vector.data[c5_wOffset +
        c5_b_k];
    }

    if ((c5_nNaNs & 1) != 0) {
      c5_x->vector.data[(c5_wOffset + c5_m) + 1] = c5_xwork.vector.data
        [(c5_wOffset + c5_m) + 1];
    }

    c5_nNonNaN = c5_n - c5_nNaNs;
    c5_preSortLevel = 2;
    if (c5_nNonNaN > 1) {
      if (c5_n >= 256) {
        c5_nBlocks = c5_nNonNaN >> 8;
        if (c5_nBlocks > 0) {
          c5_b_st.site = &c5_xh_emlrtRSI;
          c5_j_b = c5_nBlocks;
          c5_k_b = c5_j_b;
          if (c5_k_b < 1) {
            c5_d_overflow = false;
          } else {
            c5_d_overflow = (c5_k_b > 2147483646);
          }

          if (c5_d_overflow) {
            c5_c_st.site = &c5_lb_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
          }

          for (c5_n_b = 0; c5_n_b < c5_nBlocks; c5_n_b++) {
            c5_o_b = c5_n_b;
            c5_b_st.site = &c5_yh_emlrtRSI;
            c5_b_merge_pow2_block(chartInstance, &c5_b_st, c5_idx, c5_x, c5_o_b <<
                                  8);
          }

          c5_tailOffset = c5_nBlocks << 8;
          c5_nLastBlock = c5_nNonNaN - c5_tailOffset;
          if (c5_nLastBlock > 0) {
            c5_b_st.site = &c5_ai_emlrtRSI;
            c5_b_merge_block(chartInstance, &c5_b_st, c5_idx, c5_x,
                             c5_tailOffset, c5_nLastBlock, 2, &c5_iwork,
                             &c5_xwork);
          }

          c5_preSortLevel = 8;
        }
      }

      c5_b_st.site = &c5_bi_emlrtRSI;
      c5_b_merge_block(chartInstance, &c5_b_st, c5_idx, c5_x, 0, c5_nNonNaN,
                       c5_preSortLevel, &c5_iwork, &c5_xwork);
    }

    if ((c5_nNaNs > 0) && (c5_nNonNaN > 0)) {
      c5_b_st.site = &c5_ci_emlrtRSI;
      c5_b_nNonNaN = c5_nNonNaN - 1;
      c5_b_nNaNs = c5_nNaNs - 1;
      c5_c_st.site = &c5_pi_emlrtRSI;
      c5_l_b = c5_b_nNaNs + 1;
      c5_m_b = c5_l_b;
      if (c5_m_b < 1) {
        c5_e_overflow = false;
      } else {
        c5_e_overflow = (c5_m_b > 2147483646);
      }

      if (c5_e_overflow) {
        c5_d_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
      }

      for (c5_e_k = 0; c5_e_k <= c5_b_nNaNs; c5_e_k++) {
        c5_g_k = c5_e_k;
        c5_xwork.vector.data[c5_g_k] = c5_x->vector.data[(c5_b_nNonNaN + c5_g_k)
          + 1];
        c5_iwork.vector.data[c5_g_k] = c5_idx->vector.data[(c5_b_nNonNaN +
          c5_g_k) + 1];
      }

      for (c5_f_k = c5_b_nNonNaN + 1; c5_f_k >= 1; c5_f_k--) {
        c5_x->vector.data[c5_b_nNaNs + c5_f_k] = c5_x->vector.data[c5_f_k - 1];
        c5_idx->vector.data[c5_b_nNaNs + c5_f_k] = c5_idx->vector.data[c5_f_k -
          1];
      }

      c5_c_st.site = &c5_qi_emlrtRSI;
      c5_p_b = c5_b_nNaNs + 1;
      c5_q_b = c5_p_b;
      if (c5_q_b < 1) {
        c5_f_overflow = false;
      } else {
        c5_f_overflow = (c5_q_b > 2147483646);
      }

      if (c5_f_overflow) {
        c5_d_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
      }

      for (c5_h_k = 0; c5_h_k <= c5_b_nNaNs; c5_h_k++) {
        c5_g_k = c5_h_k;
        c5_x->vector.data[c5_g_k] = c5_xwork.vector.data[c5_g_k];
        c5_idx->vector.data[c5_g_k] = c5_iwork.vector.data[c5_g_k];
      }
    }

    c5_array_real_T_Destructor(chartInstance, &c5_xwork);
    c5_array_int32_T_Destructor(chartInstance, &c5_iwork);
  }
}

static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_xwork[256];
  int32_T c5_iwork[256];
  int32_T c5_a;
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_a;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_blockOffset;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_exitg1;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i_b;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_k;
  int32_T c5_nPairs;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  for (c5_c_b = 0; c5_c_b < 6; c5_c_b++) {
    c5_bLen = 1 << (c5_c_b + 2);
    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = 256 >> (c5_c_b + 3);
    c5_st.site = &c5_gi_emlrtRSI;
    c5_d_b = c5_nPairs;
    c5_e_b = c5_d_b;
    if (c5_e_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_e_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    c5_i = (uint8_T)c5_nPairs - 1;
    for (c5_k = 0; c5_k <= c5_i; c5_k++) {
      c5_b_k = c5_k;
      c5_blockOffset = (c5_offset + c5_b_k * c5_bLen2) - 1;
      c5_st.site = &c5_hi_emlrtRSI;
      c5_f_b = c5_bLen2;
      c5_g_b = c5_f_b;
      if (c5_g_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_g_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_b_st.site = &c5_lb_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i1 = (uint16_T)c5_bLen2 - 1;
      for (c5_j = 0; c5_j <= c5_i1; c5_j++) {
        c5_b_j = c5_j;
        c5_iwork[c5_b_j] = c5_idx->vector.data[(c5_blockOffset + c5_b_j) + 1];
        c5_xwork[c5_b_j] = c5_x->vector.data[(c5_blockOffset + c5_b_j) + 1];
      }

      c5_p = 0;
      c5_q = c5_bLen;
      c5_iout = c5_blockOffset;
      do {
        c5_exitg1 = 0;
        c5_iout++;
        if (c5_xwork[c5_p] >= c5_xwork[c5_q]) {
          c5_idx->vector.data[c5_iout] = c5_iwork[c5_p];
          c5_x->vector.data[c5_iout] = c5_xwork[c5_p];
          if (c5_p + 1 < c5_bLen) {
            c5_p++;
          } else {
            c5_exitg1 = 1;
          }
        } else {
          c5_idx->vector.data[c5_iout] = c5_iwork[c5_q];
          c5_x->vector.data[c5_iout] = c5_xwork[c5_q];
          if (c5_q + 1 < c5_bLen2) {
            c5_q++;
          } else {
            c5_offset1 = c5_iout - c5_p;
            c5_st.site = &c5_ii_emlrtRSI;
            c5_a = c5_p + 1;
            c5_h_b = c5_bLen;
            c5_b_a = c5_a;
            c5_i_b = c5_h_b;
            if (c5_b_a > c5_i_b) {
              c5_c_overflow = false;
            } else {
              c5_c_overflow = (c5_i_b > 2147483646);
            }

            if (c5_c_overflow) {
              c5_b_st.site = &c5_lb_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
            }

            for (c5_c_j = c5_p + 1; c5_c_j <= c5_bLen; c5_c_j++) {
              c5_idx->vector.data[c5_offset1 + c5_c_j] = c5_iwork[c5_c_j - 1];
              c5_x->vector.data[c5_offset1 + c5_c_j] = c5_xwork[c5_c_j - 1];
            }

            c5_exitg1 = 1;
          }
        }
      } while (c5_exitg1 == 0);
    }
  }
}

static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx,
  c5_coder_array_real_T *c5_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_k;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_k;
  int32_T c5_nBlocks;
  int32_T c5_nPairs;
  int32_T c5_nTail;
  int32_T c5_tailOffset;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_nBlocks = c5_n >> c5_preSortLevel;
  c5_bLen = 1 << c5_preSortLevel;
  while (c5_nBlocks > 1) {
    if ((c5_nBlocks & 1) != 0) {
      c5_nBlocks--;
      c5_tailOffset = c5_bLen * c5_nBlocks;
      c5_nTail = c5_n - c5_tailOffset;
      if (c5_nTail > c5_bLen) {
        c5_st.site = &c5_ji_emlrtRSI;
        c5_b_merge(chartInstance, &c5_st, c5_idx, c5_x, c5_offset +
                   c5_tailOffset, c5_bLen, c5_nTail - c5_bLen, c5_iwork,
                   c5_xwork);
      }
    }

    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = c5_nBlocks >> 1;
    c5_st.site = &c5_ki_emlrtRSI;
    c5_c_b = c5_nPairs;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_k = 0; c5_k < c5_nPairs; c5_k++) {
      c5_b_k = c5_k;
      c5_st.site = &c5_li_emlrtRSI;
      c5_b_merge(chartInstance, &c5_st, c5_idx, c5_x, c5_offset + c5_b_k *
                 c5_bLen2, c5_bLen, c5_bLen, c5_iwork, c5_xwork);
    }

    c5_bLen = c5_bLen2;
    c5_nBlocks = c5_nPairs;
  }

  if (c5_n > c5_bLen) {
    c5_st.site = &c5_mi_emlrtRSI;
    c5_b_merge(chartInstance, &c5_st, c5_idx, c5_x, c5_offset, c5_bLen, c5_n -
               c5_bLen, c5_iwork, c5_xwork);
  }
}

static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_idx, c5_coder_array_real_T
  *c5_x, int32_T c5_offset, int32_T c5_np, int32_T c5_nq, c5_coder_array_int32_T
  *c5_iwork, c5_coder_array_real_T *c5_xwork)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_b_j;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_exitg1;
  int32_T c5_f_b;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_n;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  int32_T c5_qend;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  if (c5_nq != 0) {
    c5_n = c5_np + c5_nq;
    c5_st.site = &c5_oi_emlrtRSI;
    c5_c_b = c5_n;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_lb_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_n; c5_j++) {
      c5_b_j = c5_j;
      c5_iwork->vector.data[c5_b_j] = c5_idx->vector.data[c5_offset + c5_b_j];
      c5_xwork->vector.data[c5_b_j] = c5_x->vector.data[c5_offset + c5_b_j];
    }

    c5_p = 0;
    c5_q = c5_np;
    c5_qend = c5_np + c5_nq;
    c5_iout = c5_offset - 1;
    do {
      c5_exitg1 = 0;
      c5_iout++;
      if (c5_xwork->vector.data[c5_p] >= c5_xwork->vector.data[c5_q]) {
        c5_idx->vector.data[c5_iout] = c5_iwork->vector.data[c5_p];
        c5_x->vector.data[c5_iout] = c5_xwork->vector.data[c5_p];
        if (c5_p + 1 < c5_np) {
          c5_p++;
        } else {
          c5_exitg1 = 1;
        }
      } else {
        c5_idx->vector.data[c5_iout] = c5_iwork->vector.data[c5_q];
        c5_x->vector.data[c5_iout] = c5_xwork->vector.data[c5_q];
        if (c5_q + 1 < c5_qend) {
          c5_q++;
        } else {
          c5_offset1 = c5_iout - c5_p;
          c5_st.site = &c5_ni_emlrtRSI;
          c5_a = c5_p + 1;
          c5_e_b = c5_np;
          c5_b_a = c5_a;
          c5_f_b = c5_e_b;
          if (c5_b_a > c5_f_b) {
            c5_b_overflow = false;
          } else {
            c5_b_overflow = (c5_f_b > 2147483646);
          }

          if (c5_b_overflow) {
            c5_b_st.site = &c5_lb_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
          }

          for (c5_c_j = c5_p + 1; c5_c_j <= c5_np; c5_c_j++) {
            c5_idx->vector.data[c5_offset1 + c5_c_j] = c5_iwork->
              vector.data[c5_c_j - 1];
            c5_x->vector.data[c5_offset1 + c5_c_j] = c5_xwork->
              vector.data[c5_c_j - 1];
          }

          c5_exitg1 = 1;
        }
      }
    } while (c5_exitg1 == 0);
  }
}

static void c5_and(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_in1,
                   c5_coder_array_boolean_T *c5_in2)
{
  c5_coder_array_boolean_T c5_b_in1;
  int32_T c5_aux_0_0;
  int32_T c5_aux_1_0;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_0;
  int32_T c5_stride_1_0;
  c5_array_boolean_T_Constructor(chartInstance, &c5_b_in1);
  if (c5_in2->size[0] == 1) {
    c5_i = c5_in1->size[0];
  } else {
    c5_i = c5_in2->size[0];
  }

  c5_array_boolean_T_SetSize(chartInstance, c5_sp, &c5_b_in1, &c5_ff_emlrtRTEI,
    c5_i);
  c5_stride_0_0 = (c5_in1->size[0] != 1);
  c5_stride_1_0 = (c5_in2->size[0] != 1);
  c5_aux_0_0 = 0;
  c5_aux_1_0 = 0;
  if (c5_in2->size[0] == 1) {
    c5_i1 = c5_in1->size[0];
  } else {
    c5_i1 = c5_in2->size[0];
  }

  c5_loop_ub = c5_i1 - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_b_in1.vector.data[c5_i2] = (c5_in1->vector.data[c5_aux_0_0] &&
      c5_in2->vector.data[c5_aux_1_0]);
    c5_aux_1_0 += c5_stride_1_0;
    c5_aux_0_0 += c5_stride_0_0;
  }

  c5_array_boolean_T_SetSize(chartInstance, c5_sp, c5_in1, &c5_gf_emlrtRTEI,
    c5_b_in1.size[0]);
  c5_b_loop_ub = c5_b_in1.size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_b_loop_ub; c5_i3++) {
    c5_in1->vector.data[c5_i3] = c5_b_in1.vector.data[c5_i3];
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_b_in1);
}

static void c5_or(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                  emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_in1,
                  c5_coder_array_boolean_T *c5_in2)
{
  c5_coder_array_boolean_T c5_b_in1;
  int32_T c5_aux_0_0;
  int32_T c5_aux_1_0;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_0;
  int32_T c5_stride_1_0;
  c5_array_boolean_T_Constructor(chartInstance, &c5_b_in1);
  if (c5_in2->size[0] == 1) {
    c5_i = c5_in1->size[0];
  } else {
    c5_i = c5_in2->size[0];
  }

  c5_array_boolean_T_SetSize(chartInstance, c5_sp, &c5_b_in1, &c5_hf_emlrtRTEI,
    c5_i);
  c5_stride_0_0 = (c5_in1->size[0] != 1);
  c5_stride_1_0 = (c5_in2->size[0] != 1);
  c5_aux_0_0 = 0;
  c5_aux_1_0 = 0;
  if (c5_in2->size[0] == 1) {
    c5_i1 = c5_in1->size[0];
  } else {
    c5_i1 = c5_in2->size[0];
  }

  c5_loop_ub = c5_i1 - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_b_in1.vector.data[c5_i2] = (c5_in1->vector.data[c5_aux_0_0] ||
      c5_in2->vector.data[c5_aux_1_0]);
    c5_aux_1_0 += c5_stride_1_0;
    c5_aux_0_0 += c5_stride_0_0;
  }

  c5_array_boolean_T_SetSize(chartInstance, c5_sp, c5_in1, &c5_if_emlrtRTEI,
    c5_b_in1.size[0]);
  c5_b_loop_ub = c5_b_in1.size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_b_loop_ub; c5_i3++) {
    c5_in1->vector.data[c5_i3] = c5_b_in1.vector.data[c5_i3];
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_b_in1);
}

static void c5_array_int32_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  int32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_cell_wrap_0_SetSize(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_cell_wrap_0
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  c5_cell_wrap_0 *c5_newData;
  int32_T c5_b_i;
  int32_T c5_i;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel < c5_coderArray->vector.numel) {
    for (c5_i = c5_newNumel; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_array_cell_wrap_0_Destructor(chartInstance, &c5_coderArray->
        vector.data[c5_i]);
    }
  }

  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (c5_cell_wrap_0 *)emlrtMallocMex(sizeof(c5_cell_wrap_0) *
      (uint32_T)c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(c5_cell_wrap_0) *
             (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  for (c5_b_i = c5_coderArray->vector.numel; c5_b_i < c5_newNumel; c5_b_i++) {
    c5_array_cell_wrap_0_Constructor(chartInstance, &c5_coderArray->
      vector.data[c5_b_i]);
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_2D_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_cell_wrap_0_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_0
   *c5_pStruct)
{
  c5_array_real_T_2D_Destructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_cell_wrap_0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_0
   *c5_pStruct)
{
  c5_array_real_T_2D_Constructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_real_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_boolean_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  boolean_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_boolean_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  boolean_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_int32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  int32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_cell_wrap_0_Constructor1
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_0 *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (c5_cell_wrap_0 *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_boolean_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (boolean_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_real_T_Constructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_cell_41_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_cell_41 *c5_pStruct)
{
  c5_array_real_T_2D_Constructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_int32_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (int32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_cell_wrap_0_Destructor1
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_0 *c5_coderArray)
{
  int32_T c5_i;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data !=
       (c5_cell_wrap_0 *)NULL)) {
    for (c5_i = 0; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_array_cell_wrap_0_Destructor(chartInstance, &c5_coderArray->
        vector.data[c5_i]);
    }

    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_boolean_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_real_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_cell_41_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_cell_41 *c5_pStruct)
{
  c5_array_real_T_2D_Destructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_int32_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_boolean_T_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (boolean_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_boolean_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_boolean_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_int32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (int32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_int32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static int32_T c5_div_s32_ndbzs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc)
{
  int32_T c5_quotient;
  uint32_T c5_absDenominator;
  uint32_T c5_absNumerator;
  uint32_T c5_tempAbsQuotient;
  boolean_T c5_quotientNeedsNegation;
  (void)chartInstance;
  (void)c5_EMLOvCount_src_loc;
  (void)c5_ssid_src_loc;
  (void)c5_offset_src_loc;
  (void)c5_length_src_loc;
  if (c5_denominator == 0) {
    if (c5_numerator >= 0) {
      c5_quotient = MAX_int32_T;
    } else {
      c5_quotient = MIN_int32_T;
    }
  } else {
    if (c5_numerator < 0) {
      c5_absNumerator = ~(uint32_T)c5_numerator + 1U;
    } else {
      c5_absNumerator = (uint32_T)c5_numerator;
    }

    if (c5_denominator < 0) {
      c5_absDenominator = ~(uint32_T)c5_denominator + 1U;
    } else {
      c5_absDenominator = (uint32_T)c5_denominator;
    }

    c5_quotientNeedsNegation = ((c5_numerator < 0) != (c5_denominator < 0));
    c5_tempAbsQuotient = c5_absNumerator / c5_absDenominator;
    if (c5_quotientNeedsNegation) {
      c5_quotient = -(int32_T)c5_tempAbsQuotient;
    } else {
      c5_quotient = (int32_T)c5_tempAbsQuotient;
    }
  }

  return c5_quotient;
}

static int32_T c5_div_nzp_s32(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc)
{
  int32_T c5_quotient;
  uint32_T c5_absDenominator;
  uint32_T c5_absNumerator;
  uint32_T c5_tempAbsQuotient;
  boolean_T c5_quotientNeedsNegation;
  (void)chartInstance;
  (void)c5_EMLOvCount_src_loc;
  (void)c5_ssid_src_loc;
  (void)c5_offset_src_loc;
  (void)c5_length_src_loc;
  if (c5_numerator < 0) {
    c5_absNumerator = ~(uint32_T)c5_numerator + 1U;
  } else {
    c5_absNumerator = (uint32_T)c5_numerator;
  }

  if (c5_denominator < 0) {
    c5_absDenominator = ~(uint32_T)c5_denominator + 1U;
  } else {
    c5_absDenominator = (uint32_T)c5_denominator;
  }

  c5_quotientNeedsNegation = ((c5_numerator < 0) != (c5_denominator < 0));
  c5_tempAbsQuotient = c5_absNumerator / c5_absDenominator;
  if (c5_quotientNeedsNegation) {
    c5_quotient = -(int32_T)c5_tempAbsQuotient;
  } else {
    c5_quotient = (int32_T)c5_tempAbsQuotient;
  }

  return c5_quotient;
}

static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_imgin = (uint8_T (*)[57600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_bw = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_N = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c5_ln1_data = (real_T (*)[100000000])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c5_ln1_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3);
  chartInstance->c5_ln2_data = (real_T (*)[100000000])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c5_ln2_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 4);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1395699287U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2710552181U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2840034746U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(421249534U);
}

mxArray *sf_c5_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,6);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.EdgeSobelPrewittTbbBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.EdgeThinningTbbBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.Morphop_binary_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c5_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2gray_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCOYGZgYAPSHEDMxAABrFA+IxCzQGmIOAtcXAGISyoLUkHixUXJnilAOi8xF8x"
    "PLK3wzEvLB5tvwYAwnw2L+YxI5nNCxSHggz1l+iUcQPoNkPSzENAvAGT5QcMFFj4D534RotzPhO"
    "J+Joak8sHifjWi3M+M4n5mhpw8w0Hifg0y3W8Edz8AQPAY2g=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sD0UzmdVc2IyOwHPRKwY0p";
}

static void sf_opaque_initialize_c5_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_flightControlSystem(void *chartInstanceVar)
{
  enable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_flightControlSystem(void *chartInstanceVar)
{
  disable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c5_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc5_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c5_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWNuO20QYnmTDqkWlLFIFRUKCK9QbpO2WSlwg6DYHGrHbRHV2Odygif3Hnu547M4h2fQpuOQ",
    "lEO8A74B4DC4RN/CP481mvSHrcUAbaslxxs43/zef/9OE1LqHBI/beH7/LiHbeL2BZ53MjtfycW",
    "3hnN1vkE/zcf91QvyISt0Vo4S4H34SQAjCM6MRO3XEChP3qaSxqmBX0BiegUq40SwRbuSZGIEE4",
    "eMEaSK1k13FYsOZOOkY4VvL6quI+ZEXJYYHj3FCGvQEn/6T3dToPlpsMQm+7gAEOpKJCaMOp+Fq",
    "FaSeNCPwT5SJnbVSoD2T2qWqQ8M1Szm0T8HvCqUpqqCuWK+nqYamPnX2EKa8M3QSp5xRUV7riCo",
    "PUvQODUdpgJ89o1G9knbR3pAJqhPJKG/HvGk9vCS2z5HnIbo1d9ZZx7oFQxOGTIRWXWliELh+9J",
    "MSWo2ayRgkDaEnHGPQrq59mr3guV+Wj8GudctKMWji2VtRlbCZ3fYYFVIV7XZ80aScKzfsIEkPY",
    "Aw8s9+imlbAzuw7gJViwSA5ptJGgWMkGcFeGMixzUQErPwbHhdQWcJ9ismzBJzF1qUgQJnn1OcT",
    "XeWTRukkbmIYtQ4OStq7jO0KDXJEfSid+yRlCpBw5leOdgOm6JBbNKqks1WWngFEZShRIyNak0S",
    "eoMauSfZcKxsJbmgIQmiBhixhtNG7jyk3JTnHCjOcdY8jhRnLzS5ibfxUAvvUjyCw9YRxOARlJ1",
    "Cl8zPWkX1c7ZjpaQuUL1laNpKMggALiVVpME3hSJyIZCI6Mom9vCNY4VcAmDWoFFgWHmNZktMOk",
    "i/HWsKLgfWsKu1ZTDWnQ+sbX4DAymLXaish9TGq2gJbNyS0DtZjL7G0C8WUxnZq2s5iIMj60bs1",
    "t370rXz8YB5LXTWQ+KYolmGBndL+MGv2YMBiyG54FHuK2TA/rN1dcm73Zn213Tp+q1XEkTVxTxZ",
    "wjSX6vL2A28nH/sPvRpyFkU3CWibcm6Lu8WUet0rovYx/EUcu4c51PrveW8DXltglC9d13s+jBd",
    "wbBTuNAm4712x35/mPH//1s/rl16D3058/vLmO/RsNN3++nY/fO+vP5hVsfCnJV/UH1do9ehkHx",
    "/5ed9qbPOk/+3LyzW46m+/rrdV8GwW+Z/c/wFNjgsvypfS7Qb7XsmNqZnsAO/8nC3y3r9Dj5oI/",
    "EfL75+vh7z4qvsfGFfgd/Pa04LfXx/9OKf71C/zrZDjZFP4fluK/dYH/FuHi/obwv1eR/94F/pt",
    "eZ66rrl0nzzJ1r1YR1yD/XZ39N3Hrrs+1nv/ff78qD5DC73c2eB3Fa9W+btPW9Rtx67vez8efzf",
    "9zaUaMB0t2fflj3JiNlj19Rfz7D0f93snHbatf/qfxtw/2BeVT3ObNttH57b60/1fOH0mgavle+",
    "jrqEFmyb1hW528V4tuOJ0wEyUR9dH/v4d46de1vHxAMgg==",
    ""
  };

  static char newstr [1473] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c5_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2909409328U));
  ssSetChecksum1(S,(1942159156U));
  ssSetChecksum2(S,(1332008643U));
  ssSetChecksum3(S,(261683887U));
}

static void mdlRTW_c5_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_flightControlSystem(SimStruct *S)
{
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc5_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c5_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c5_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c5_flightControlSystem(chartInstance);
}

void c5_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
