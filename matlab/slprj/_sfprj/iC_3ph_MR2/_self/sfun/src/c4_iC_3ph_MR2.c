/* Include files */

#include "blascompat32.h"
#include "iC_3ph_MR2_sfun.h"
#include "c4_iC_3ph_MR2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "iC_3ph_MR2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[9] = { "abc", "nargin", "nargout",
  "up_alpha", "up_beta", "up_0", "up_a", "up_b", "up_c" };

/* Function Declarations */
static void initialize_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initialize_params_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void enable_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);
static void disable_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *
  chartInstance);
static void set_sim_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);
static void sf_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);
static void c4_chartstep_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initSimStructsc4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_up_c, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[14]);
static void c4_eml_scalar_eg(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_iC_3ph_MR2, const char_T
  *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_iC_3ph_MR2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_iC_3ph_MR2 = 0U;
}

static void initialize_params_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void enable_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *
  chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  uint8_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T *c4_up_a;
  real_T *c4_up_b;
  real_T *c4_up_c;
  c4_up_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_up_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_up_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(4), FALSE);
  c4_hoistedGlobal = *c4_up_a;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_up_b;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_up_c;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_is_active_c4_iC_3ph_MR2;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_up_a;
  real_T *c4_up_b;
  real_T *c4_up_c;
  c4_up_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_up_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_up_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_up_a = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "up_a");
  *c4_up_b = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    1)), "up_b");
  *c4_up_c = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    2)), "up_c");
  chartInstance->c4_is_active_c4_iC_3ph_MR2 = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
     "is_active_c4_iC_3ph_MR2");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_iC_3ph_MR2(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void sf_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
  real_T *c4_up_a;
  real_T *c4_up_alpha;
  real_T *c4_up_b;
  real_T *c4_up_c;
  real_T *c4_up_beta;
  real_T *c4_up_0;
  c4_up_0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_up_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_up_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_up_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_up_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_up_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_up_a, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_up_alpha, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_up_b, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_up_c, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_up_beta, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_up_0, 5U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_iC_3ph_MR2(chartInstance);
  sf_debug_check_for_state_inconsistency(_iC_3ph_MR2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_up_alpha;
  real_T c4_up_beta;
  real_T c4_up_0;
  uint32_T c4_debug_family_var_map[9];
  real_T c4_abc[3];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 3.0;
  real_T c4_up_a;
  real_T c4_up_b;
  real_T c4_up_c;
  real_T c4_b[3];
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  real_T c4_C[3];
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  static real_T c4_a[9] = { 1.0, -0.5, -0.5, 0.0, 0.8660254037844386,
    -0.8660254037844386, 1.0, 1.0, 1.0 };

  real_T *c4_b_up_alpha;
  real_T *c4_b_up_beta;
  real_T *c4_b_up_0;
  real_T *c4_b_up_a;
  real_T *c4_b_up_b;
  real_T *c4_b_up_c;
  c4_b_up_0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_up_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_up_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_up_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_up_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_up_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_up_alpha;
  c4_b_hoistedGlobal = *c4_b_up_beta;
  c4_c_hoistedGlobal = *c4_b_up_0;
  c4_up_alpha = c4_hoistedGlobal;
  c4_up_beta = c4_b_hoistedGlobal;
  c4_up_0 = c4_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c4_abc, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_up_alpha, 3U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_up_beta, 4U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_up_0, 5U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_up_a, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_up_b, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_up_c, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_b[0] = c4_up_alpha;
  c4_b[1] = c4_up_beta;
  c4_b[2] = c4_up_0;
  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_abc[c4_i0] = 0.0;
  }

  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    c4_abc[c4_i1] = 0.0;
  }

  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    c4_C[c4_i2] = c4_abc[c4_i2];
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_abc[c4_i3] = c4_C[c4_i3];
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_C[c4_i4] = c4_abc[c4_i4];
  }

  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_abc[c4_i5] = c4_C[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_abc[c4_i6] = 0.0;
    c4_i7 = 0;
    for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
      c4_abc[c4_i6] += c4_a[c4_i7 + c4_i6] * c4_b[c4_i8];
      c4_i7 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_up_a = c4_abc[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_up_b = c4_abc[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_up_c = c4_abc[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c4_b_up_a = c4_up_a;
  *c4_b_up_b = c4_up_b;
  *c4_b_up_c = c4_up_c;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_iC_3ph_MR2(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_up_c, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_up_c), &c4_thisId);
  sf_mex_destroy(&c4_up_c);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_up_c;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_up_c = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_up_c), &c4_thisId);
  sf_mex_destroy(&c4_up_c);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i9;
  real_T c4_b_inData[3];
  int32_T c4_i10;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_b_inData[c4_i9] = (*(real_T (*)[3])c4_inData)[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_u[c4_i10] = c4_b_inData[c4_i10];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv0[3];
  int32_T c4_i11;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_y[c4_i11] = c4_dv0[c4_i11];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_abc;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i12;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_abc = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_abc), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_abc);
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    (*(real_T (*)[3])c4_outData)[c4_i12] = c4_y[c4_i12];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_iC_3ph_MR2_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[14];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i13;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c4_i13 = 0; c4_i13 < 14; c4_i13++) {
    c4_r0 = &c4_info[c4_i13];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i13);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[14])
{
  c4_info[0].context = "";
  c4_info[0].name = "mrdivide";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[0].fileTimeLo = 1325127738U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 1319737166U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[1].name = "rdivide";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[1].fileTimeLo = 1286826044U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[2].name = "eml_div";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[2].fileTimeLo = 1313355010U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "";
  c4_info[3].name = "sqrt";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[3].fileTimeLo = 1286825952U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[4].name = "eml_error";
  c4_info[4].dominantType = "char";
  c4_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[4].fileTimeLo = 1305325200U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[5].name = "eml_scalar_sqrt";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[5].fileTimeLo = 1286825938U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context = "";
  c4_info[6].name = "mtimes";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[6].fileTimeLo = 1289523292U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[7].name = "eml_index_class";
  c4_info[7].dominantType = "";
  c4_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[7].fileTimeLo = 1286825978U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[8].name = "eml_scalar_eg";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[8].fileTimeLo = 1286825996U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[9].name = "eml_xgemm";
  c4_info[9].dominantType = "int32";
  c4_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[9].fileTimeLo = 1299080372U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[10].name = "eml_blas_inline";
  c4_info[10].dominantType = "";
  c4_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c4_info[10].fileTimeLo = 1299080368U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c4_info[11].name = "mtimes";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[11].fileTimeLo = 1289523292U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[12].name = "eml_scalar_eg";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[12].fileTimeLo = 1286825996U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[13].name = "eml_refblas_xgemm";
  c4_info[13].dominantType = "int32";
  c4_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[13].fileTimeLo = 1299080374U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
}

static void c4_eml_scalar_eg(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i14;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i14, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i14;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_iC_3ph_MR2, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_iC_3ph_MR2), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_iC_3ph_MR2);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_iC_3ph_MR2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4242144356U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2006001335U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(853032848U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2481710197U);
}

mxArray *sf_c4_iC_3ph_MR2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wC0aoH41z4Hf04oPhwme1B");
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

static const mxArray *sf_get_sim_state_info_c4_iC_3ph_MR2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[4],T\"up_a\",},{M[1],M[6],T\"up_b\",},{M[1],M[7],T\"up_c\",},{M[8],M[0],T\"is_active_c4_iC_3ph_MR2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_iC_3ph_MR2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
    chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_iC_3ph_MR2MachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"up_a");
          _SFD_SET_DATA_PROPS(1,1,1,0,"up_alpha");
          _SFD_SET_DATA_PROPS(2,2,0,1,"up_b");
          _SFD_SET_DATA_PROPS(3,2,0,1,"up_c");
          _SFD_SET_DATA_PROPS(4,1,1,0,"up_beta");
          _SFD_SET_DATA_PROPS(5,1,1,0,"up_0");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,390);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_up_a;
          real_T *c4_up_alpha;
          real_T *c4_up_b;
          real_T *c4_up_c;
          real_T *c4_up_beta;
          real_T *c4_up_0;
          c4_up_0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_up_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_up_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_up_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_up_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_up_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_up_a);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_up_alpha);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_up_b);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_up_c);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_up_beta);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_up_0);
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
  return "Ygbz80cIeB0XLea4vtK2BC";
}

static void sf_opaque_initialize_c4_iC_3ph_MR2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*)
    chartInstanceVar);
  initialize_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_iC_3ph_MR2(void *chartInstanceVar)
{
  enable_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_iC_3ph_MR2(void *chartInstanceVar)
{
  disable_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_iC_3ph_MR2(void *chartInstanceVar)
{
  sf_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_iC_3ph_MR2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_iC_3ph_MR2
    ((SFc4_iC_3ph_MR2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_iC_3ph_MR2();/* state var info */
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

extern void sf_internal_set_sim_state_c4_iC_3ph_MR2(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_iC_3ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_iC_3ph_MR2(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_iC_3ph_MR2(S);
}

static void sf_opaque_set_sim_state_c4_iC_3ph_MR2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_iC_3ph_MR2(S, st);
}

static void sf_opaque_terminate_c4_iC_3ph_MR2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_iC_3ph_MR2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_iC_3ph_MR2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_iC_3ph_MR2((SFc4_iC_3ph_MR2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_iC_3ph_MR2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1632116575U));
  ssSetChecksum1(S,(3628615593U));
  ssSetChecksum2(S,(1068255107U));
  ssSetChecksum3(S,(1745927270U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_iC_3ph_MR2(SimStruct *S)
{
  SFc4_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc4_iC_3ph_MR2InstanceStruct *)malloc(sizeof
    (SFc4_iC_3ph_MR2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_iC_3ph_MR2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_iC_3ph_MR2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_iC_3ph_MR2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_iC_3ph_MR2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_iC_3ph_MR2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_iC_3ph_MR2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_iC_3ph_MR2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_iC_3ph_MR2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_iC_3ph_MR2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_iC_3ph_MR2;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_iC_3ph_MR2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_iC_3ph_MR2;
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

void c4_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_iC_3ph_MR2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_iC_3ph_MR2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
