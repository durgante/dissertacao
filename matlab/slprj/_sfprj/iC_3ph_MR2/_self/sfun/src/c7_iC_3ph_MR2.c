/* Include files */

#include "blascompat32.h"
#include "iC_3ph_MR2_sfun.h"
#include "c7_iC_3ph_MR2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "iC_3ph_MR2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[9] = { "alpha_beta_zero", "nargin",
  "nargout", "iC_a", "iC_b", "iC_c", "iC_alpha", "iC_beta", "iC_0" };

/* Function Declarations */
static void initialize_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initialize_params_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void enable_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);
static void disable_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *
  chartInstance);
static void set_sim_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);
static void sf_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);
static void c7_chartstep_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initSimStructsc7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_iC_0, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_c_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[14]);
static void c7_eml_scalar_eg(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_iC_3ph_MR2, const char_T
  *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_iC_3ph_MR2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_iC_3ph_MR2 = 0U;
}

static void initialize_params_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void enable_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *
  chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T *c7_iC_0;
  real_T *c7_iC_alpha;
  real_T *c7_iC_beta;
  c7_iC_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_iC_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_iC_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(4), FALSE);
  c7_hoistedGlobal = *c7_iC_0;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_iC_alpha;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *c7_iC_beta;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_iC_3ph_MR2;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_iC_0;
  real_T *c7_iC_alpha;
  real_T *c7_iC_beta;
  c7_iC_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_iC_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_iC_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_iC_0 = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    0)), "iC_0");
  *c7_iC_alpha = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 1)), "iC_alpha");
  *c7_iC_beta = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 2)), "iC_beta");
  chartInstance->c7_is_active_c7_iC_3ph_MR2 = c7_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 3)),
     "is_active_c7_iC_3ph_MR2");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_iC_3ph_MR2(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void sf_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
  real_T *c7_iC_a;
  real_T *c7_iC_alpha;
  real_T *c7_iC_b;
  real_T *c7_iC_c;
  real_T *c7_iC_beta;
  real_T *c7_iC_0;
  c7_iC_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_iC_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_iC_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_iC_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_iC_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_iC_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_iC_a, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_iC_alpha, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_iC_b, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_iC_c, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_iC_beta, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_iC_0, 5U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_iC_3ph_MR2(chartInstance);
  sf_debug_check_for_state_inconsistency(_iC_3ph_MR2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_chartstep_c7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_iC_a;
  real_T c7_iC_b;
  real_T c7_iC_c;
  uint32_T c7_debug_family_var_map[9];
  real_T c7_alpha_beta_zero[3];
  real_T c7_nargin = 3.0;
  real_T c7_nargout = 3.0;
  real_T c7_iC_alpha;
  real_T c7_iC_beta;
  real_T c7_iC_0;
  real_T c7_b[3];
  int32_T c7_i0;
  int32_T c7_i1;
  int32_T c7_i2;
  real_T c7_C[3];
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  static real_T c7_a[9] = { 0.66666666666666663, 0.0, 0.33333333333333331,
    -0.33333333333333331, 0.57735026918962584, 0.33333333333333331,
    -0.33333333333333331, -0.57735026918962584, 0.33333333333333331 };

  real_T *c7_b_iC_a;
  real_T *c7_b_iC_b;
  real_T *c7_b_iC_c;
  real_T *c7_b_iC_alpha;
  real_T *c7_b_iC_beta;
  real_T *c7_b_iC_0;
  c7_b_iC_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_b_iC_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_b_iC_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_iC_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_iC_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_iC_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_b_iC_a;
  c7_b_hoistedGlobal = *c7_b_iC_b;
  c7_c_hoistedGlobal = *c7_b_iC_c;
  c7_iC_a = c7_hoistedGlobal;
  c7_iC_b = c7_b_hoistedGlobal;
  c7_iC_c = c7_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c7_alpha_beta_zero, 0U,
    c7_b_sf_marshallOut, c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 2U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_iC_a, 3U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_iC_b, 4U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_iC_c, 5U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_iC_alpha, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_iC_beta, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_iC_0, 8U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_b[0] = c7_iC_a;
  c7_b[1] = c7_iC_b;
  c7_b[2] = c7_iC_c;
  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_alpha_beta_zero[c7_i0] = 0.0;
  }

  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    c7_alpha_beta_zero[c7_i1] = 0.0;
  }

  for (c7_i2 = 0; c7_i2 < 3; c7_i2++) {
    c7_C[c7_i2] = c7_alpha_beta_zero[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
    c7_alpha_beta_zero[c7_i3] = c7_C[c7_i3];
  }

  for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
    c7_C[c7_i4] = c7_alpha_beta_zero[c7_i4];
  }

  for (c7_i5 = 0; c7_i5 < 3; c7_i5++) {
    c7_alpha_beta_zero[c7_i5] = c7_C[c7_i5];
  }

  for (c7_i6 = 0; c7_i6 < 3; c7_i6++) {
    c7_alpha_beta_zero[c7_i6] = 0.0;
    c7_i7 = 0;
    for (c7_i8 = 0; c7_i8 < 3; c7_i8++) {
      c7_alpha_beta_zero[c7_i6] += c7_a[c7_i7 + c7_i6] * c7_b[c7_i8];
      c7_i7 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_iC_alpha = c7_alpha_beta_zero[0];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_iC_beta = c7_alpha_beta_zero[1];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_iC_0 = c7_alpha_beta_zero[2];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c7_b_iC_alpha = c7_iC_alpha;
  *c7_b_iC_beta = c7_iC_beta;
  *c7_b_iC_0 = c7_iC_0;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_iC_3ph_MR2(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_iC_0, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_iC_0), &c7_thisId);
  sf_mex_destroy(&c7_iC_0);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_iC_0;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_iC_0 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_iC_0), &c7_thisId);
  sf_mex_destroy(&c7_iC_0);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i9;
  real_T c7_b_inData[3];
  int32_T c7_i10;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    c7_b_inData[c7_i9] = (*(real_T (*)[3])c7_inData)[c7_i9];
  }

  for (c7_i10 = 0; c7_i10 < 3; c7_i10++) {
    c7_u[c7_i10] = c7_b_inData[c7_i10];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_c_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv0[3];
  int32_T c7_i11;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    c7_y[c7_i11] = c7_dv0[c7_i11];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_alpha_beta_zero;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i12;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_alpha_beta_zero = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_alpha_beta_zero),
                        &c7_thisId, c7_y);
  sf_mex_destroy(&c7_alpha_beta_zero);
  for (c7_i12 = 0; c7_i12 < 3; c7_i12++) {
    (*(real_T (*)[3])c7_outData)[c7_i12] = c7_y[c7_i12];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_iC_3ph_MR2_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[14];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i13;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c7_i13 = 0; c7_i13 < 14; c7_i13++) {
    c7_r0 = &c7_info[c7_i13];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i13);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[14])
{
  c7_info[0].context = "";
  c7_info[0].name = "mrdivide";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[0].fileTimeLo = 1325127738U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 1319737166U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[1].name = "rdivide";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[1].fileTimeLo = 1286826044U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[2].name = "eml_div";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[2].fileTimeLo = 1313355010U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context = "";
  c7_info[3].name = "sqrt";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[3].fileTimeLo = 1286825952U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[4].name = "eml_error";
  c7_info[4].dominantType = "char";
  c7_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[4].fileTimeLo = 1305325200U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[5].name = "eml_scalar_sqrt";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[5].fileTimeLo = 1286825938U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context = "";
  c7_info[6].name = "mtimes";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[6].fileTimeLo = 1289523292U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[7].name = "eml_index_class";
  c7_info[7].dominantType = "";
  c7_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[7].fileTimeLo = 1286825978U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[8].name = "eml_scalar_eg";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[8].fileTimeLo = 1286825996U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[9].name = "eml_xgemm";
  c7_info[9].dominantType = "int32";
  c7_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[9].fileTimeLo = 1299080372U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[10].name = "eml_blas_inline";
  c7_info[10].dominantType = "";
  c7_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[10].fileTimeLo = 1299080368U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c7_info[11].name = "mtimes";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[11].fileTimeLo = 1289523292U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[12].name = "eml_scalar_eg";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[12].fileTimeLo = 1286825996U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[13].name = "eml_refblas_xgemm";
  c7_info[13].dominantType = "int32";
  c7_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c7_info[13].fileTimeLo = 1299080374U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
}

static void c7_eml_scalar_eg(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i14;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i14, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i14;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_iC_3ph_MR2, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_iC_3ph_MR2), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_iC_3ph_MR2);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_iC_3ph_MR2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4173737309U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4041911179U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2193139525U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1030171326U);
}

mxArray *sf_c7_iC_3ph_MR2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1i3xevnbVGVuyl2s7HesvD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c7_iC_3ph_MR2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"iC_0\",},{M[1],M[5],T\"iC_alpha\",},{M[1],M[8],T\"iC_beta\",},{M[8],M[0],T\"is_active_c7_iC_3ph_MR2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_iC_3ph_MR2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
    chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_iC_3ph_MR2MachineNumber_,
           7,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_iC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_iC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_iC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"iC_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"iC_alpha");
          _SFD_SET_DATA_PROPS(2,1,1,0,"iC_b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"iC_c");
          _SFD_SET_DATA_PROPS(4,2,0,1,"iC_beta");
          _SFD_SET_DATA_PROPS(5,2,0,1,"iC_0");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,437);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_iC_a;
          real_T *c7_iC_alpha;
          real_T *c7_iC_b;
          real_T *c7_iC_c;
          real_T *c7_iC_beta;
          real_T *c7_iC_0;
          c7_iC_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_iC_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c7_iC_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_iC_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_iC_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_iC_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_iC_a);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_iC_alpha);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_iC_b);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_iC_c);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_iC_beta);
          _SFD_SET_DATA_VALUE_PTR(5U, c7_iC_0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_iC_3ph_MR2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "hRNCCsHHE7yE4C1nwahGU";
}

static void sf_opaque_initialize_c7_iC_3ph_MR2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*)
    chartInstanceVar);
  initialize_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_iC_3ph_MR2(void *chartInstanceVar)
{
  enable_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_iC_3ph_MR2(void *chartInstanceVar)
{
  disable_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_iC_3ph_MR2(void *chartInstanceVar)
{
  sf_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_iC_3ph_MR2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_iC_3ph_MR2
    ((SFc7_iC_3ph_MR2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_iC_3ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c7_iC_3ph_MR2(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_iC_3ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_iC_3ph_MR2(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_iC_3ph_MR2(S);
}

static void sf_opaque_set_sim_state_c7_iC_3ph_MR2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c7_iC_3ph_MR2(S, st);
}

static void sf_opaque_terminate_c7_iC_3ph_MR2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_iC_3ph_MR2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_iC_3ph_MR2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_iC_3ph_MR2((SFc7_iC_3ph_MR2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_iC_3ph_MR2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2844951932U));
  ssSetChecksum1(S,(1703100670U));
  ssSetChecksum2(S,(1245272493U));
  ssSetChecksum3(S,(3245408769U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_iC_3ph_MR2(SimStruct *S)
{
  SFc7_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc7_iC_3ph_MR2InstanceStruct *)malloc(sizeof
    (SFc7_iC_3ph_MR2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_iC_3ph_MR2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_iC_3ph_MR2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_iC_3ph_MR2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_iC_3ph_MR2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_iC_3ph_MR2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_iC_3ph_MR2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_iC_3ph_MR2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_iC_3ph_MR2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_iC_3ph_MR2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_iC_3ph_MR2;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_iC_3ph_MR2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_iC_3ph_MR2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c7_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_iC_3ph_MR2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_iC_3ph_MR2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
