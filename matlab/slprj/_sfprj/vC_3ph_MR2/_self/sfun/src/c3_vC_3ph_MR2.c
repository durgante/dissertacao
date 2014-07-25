/* Include files */

#include "blascompat32.h"
#include "vC_3ph_MR2_sfun.h"
#include "c3_vC_3ph_MR2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "vC_3ph_MR2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[80] = { "L1ideal", "L2ideal",
  "Lgideal", "Cideal", "R1ideal", "R2ideal", "Rgideal", "errL1", "errL2",
  "errLg", "errC", "errR1", "errR2", "errRg", "deltaL1", "deltaL2", "deltaLg",
  "deltaC", "deltaR1", "deltaR2", "deltaRg", "L1", "L2", "C", "R1", "R2", "Ts",
  "w", "kp_kd", "Kp", "p1", "p2", "km", "gamaD", "gama", "delta0", "u_k",
  "eta_k", "i2m_k", "e1_k", "v_k", "q_k", "e2_k", "ea_k", "eta2_k", "m2_k",
  "nargin", "nargout", "i2ref_k", "i2_k", "vc_k", "flag", "t", "up_beta",
  "theta_beta", "m", "theta_k", "omega_k", "omega_k_1", "omega_k_2", "omega_k_3",
  "eta_k_1", "eta_k_2", "eta_k_3", "i2m_k_1", "i2m_k_2", "i2m_k_3", "i2ref_k_1",
  "i2ref_k_2", "i2ref_k_3", "v_k_1", "v_k_2", "v_k_3", "rho_k", "m2", "vc_k_1",
  "u_k_1", "u_k_2", "P", "gama2" };

/* Function Declarations */
static void initialize_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static void initialize_params_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static void enable_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void disable_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *
  chartInstance);
static void set_sim_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void sf_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void c3_chartstep_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static void initSimStructsc3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_gama2, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_P, const char_T *c3_identifier, real_T c3_y[36]);
static void c3_d_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[36]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_u_k_2, const char_T *c3_identifier);
static real_T c3_f_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_g_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_u_k_1, const char_T *c3_identifier);
static real_T c3_h_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_i_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_vc_k_1, const char_T *c3_identifier);
static real_T c3_j_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_k_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_m2, const char_T *c3_identifier);
static real_T c3_l_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_m_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_rho_k, const char_T *c3_identifier);
static real_T c3_n_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_o_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_3, const char_T *c3_identifier);
static real_T c3_p_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_q_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_2, const char_T *c3_identifier);
static real_T c3_r_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_s_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_1, const char_T *c3_identifier);
static real_T c3_t_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_u_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_3, const char_T *c3_identifier);
static real_T c3_v_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_w_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_2, const char_T *c3_identifier);
static real_T c3_x_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_y_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_1, const char_T *c3_identifier);
static real_T c3_ab_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_bb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_3, const char_T *c3_identifier);
static real_T c3_cb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_db_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_2, const char_T *c3_identifier);
static real_T c3_eb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_fb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_1, const char_T *c3_identifier);
static real_T c3_gb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_hb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_3, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_ib_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_jb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_2, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_kb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_lb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_1, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_mb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_nb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_3, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_ob_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_pb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_2, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_qb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_rb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_1, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_sb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_tb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_ub_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_vb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_theta_k, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_wb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_xb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_m, const char_T *c3_identifier);
static real_T c3_yb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_ac_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_theta_beta, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_bc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[56]);
static real_T c3_sqrt(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T c3_x);
static void c3_eml_error(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void c3_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void c3_eml_int_forloop_overflow_check(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance);
static void c3_b_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static real_T c3_mpower(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T
  c3_a);
static void c3_c_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static void c3_d_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);
static real_T c3_abs(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T c3_x);
static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_cc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_dc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_vC_3ph_MR2, const char_T
  *c3_identifier);
static uint8_T c3_ec_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sqrt(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T *c3_x);
static void init_dsm_address_info(SFc3_vC_3ph_MR2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_theta_k_not_empty = FALSE;
  chartInstance->c3_omega_k_not_empty = FALSE;
  chartInstance->c3_omega_k_1_not_empty = FALSE;
  chartInstance->c3_omega_k_2_not_empty = FALSE;
  chartInstance->c3_omega_k_3_not_empty = FALSE;
  chartInstance->c3_eta_k_1_not_empty = FALSE;
  chartInstance->c3_eta_k_2_not_empty = FALSE;
  chartInstance->c3_eta_k_3_not_empty = FALSE;
  chartInstance->c3_i2m_k_1_not_empty = FALSE;
  chartInstance->c3_i2m_k_2_not_empty = FALSE;
  chartInstance->c3_i2m_k_3_not_empty = FALSE;
  chartInstance->c3_i2ref_k_1_not_empty = FALSE;
  chartInstance->c3_i2ref_k_2_not_empty = FALSE;
  chartInstance->c3_i2ref_k_3_not_empty = FALSE;
  chartInstance->c3_v_k_1_not_empty = FALSE;
  chartInstance->c3_v_k_2_not_empty = FALSE;
  chartInstance->c3_v_k_3_not_empty = FALSE;
  chartInstance->c3_rho_k_not_empty = FALSE;
  chartInstance->c3_m2_not_empty = FALSE;
  chartInstance->c3_vc_k_1_not_empty = FALSE;
  chartInstance->c3_u_k_1_not_empty = FALSE;
  chartInstance->c3_u_k_2_not_empty = FALSE;
  chartInstance->c3_P_not_empty = FALSE;
  chartInstance->c3_gama2_not_empty = FALSE;
  chartInstance->c3_is_active_c3_vC_3ph_MR2 = 0U;
}

static void initialize_params_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void enable_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  int32_T c3_i0;
  real_T c3_b_u[6];
  const mxArray *c3_c_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i1;
  real_T c3_d_u[36];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i2;
  real_T c3_e_u[6];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i3;
  real_T c3_f_u[6];
  const mxArray *c3_g_y = NULL;
  int32_T c3_i4;
  real_T c3_g_u[6];
  const mxArray *c3_h_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  real_T c3_j_hoistedGlobal;
  real_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  int32_T c3_i5;
  real_T c3_p_u[6];
  const mxArray *c3_q_y = NULL;
  int32_T c3_i6;
  real_T c3_q_u[6];
  const mxArray *c3_r_y = NULL;
  int32_T c3_i7;
  real_T c3_r_u[6];
  const mxArray *c3_s_y = NULL;
  int32_T c3_i8;
  real_T c3_s_u[6];
  const mxArray *c3_t_y = NULL;
  real_T c3_k_hoistedGlobal;
  real_T c3_t_u;
  const mxArray *c3_u_y = NULL;
  int32_T c3_i9;
  real_T c3_u_u[6];
  const mxArray *c3_v_y = NULL;
  real_T c3_l_hoistedGlobal;
  real_T c3_v_u;
  const mxArray *c3_w_y = NULL;
  real_T c3_m_hoistedGlobal;
  real_T c3_w_u;
  const mxArray *c3_x_y = NULL;
  real_T c3_n_hoistedGlobal;
  real_T c3_x_u;
  const mxArray *c3_y_y = NULL;
  real_T c3_o_hoistedGlobal;
  real_T c3_y_u;
  const mxArray *c3_ab_y = NULL;
  real_T c3_p_hoistedGlobal;
  real_T c3_ab_u;
  const mxArray *c3_bb_y = NULL;
  real_T c3_q_hoistedGlobal;
  real_T c3_bb_u;
  const mxArray *c3_cb_y = NULL;
  uint8_T c3_r_hoistedGlobal;
  uint8_T c3_cb_u;
  const mxArray *c3_db_y = NULL;
  real_T *c3_m;
  real_T *c3_up_beta;
  real_T (*c3_theta_beta)[6];
  c3_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_theta_beta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_up_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(28), FALSE);
  c3_hoistedGlobal = *c3_m;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i0 = 0; c3_i0 < 6; c3_i0++) {
    c3_b_u[c3_i0] = (*c3_theta_beta)[c3_i0];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_b_hoistedGlobal = *c3_up_beta;
  c3_c_u = c3_b_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
    c3_d_u[c3_i1] = chartInstance->c3_P[c3_i1];
  }

  c3_e_y = NULL;
  if (!chartInstance->c3_P_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 2, 6, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
    c3_e_u[c3_i2] = chartInstance->c3_eta_k_1[c3_i2];
  }

  c3_f_y = NULL;
  if (!chartInstance->c3_eta_k_1_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
    c3_f_u[c3_i3] = chartInstance->c3_eta_k_2[c3_i3];
  }

  c3_g_y = NULL;
  if (!chartInstance->c3_eta_k_2_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_g_u[c3_i4] = chartInstance->c3_eta_k_3[c3_i4];
  }

  c3_h_y = NULL;
  if (!chartInstance->c3_eta_k_3_not_empty) {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_c_hoistedGlobal = chartInstance->c3_gama2;
  c3_h_u = c3_c_hoistedGlobal;
  c3_i_y = NULL;
  if (!chartInstance->c3_gama2_not_empty) {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_d_hoistedGlobal = chartInstance->c3_i2m_k_1;
  c3_i_u = c3_d_hoistedGlobal;
  c3_j_y = NULL;
  if (!chartInstance->c3_i2m_k_1_not_empty) {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_e_hoistedGlobal = chartInstance->c3_i2m_k_2;
  c3_j_u = c3_e_hoistedGlobal;
  c3_k_y = NULL;
  if (!chartInstance->c3_i2m_k_2_not_empty) {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_f_hoistedGlobal = chartInstance->c3_i2m_k_3;
  c3_k_u = c3_f_hoistedGlobal;
  c3_l_y = NULL;
  if (!chartInstance->c3_i2m_k_3_not_empty) {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_g_hoistedGlobal = chartInstance->c3_i2ref_k_1;
  c3_l_u = c3_g_hoistedGlobal;
  c3_m_y = NULL;
  if (!chartInstance->c3_i2ref_k_1_not_empty) {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_h_hoistedGlobal = chartInstance->c3_i2ref_k_2;
  c3_m_u = c3_h_hoistedGlobal;
  c3_n_y = NULL;
  if (!chartInstance->c3_i2ref_k_2_not_empty) {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_i_hoistedGlobal = chartInstance->c3_i2ref_k_3;
  c3_n_u = c3_i_hoistedGlobal;
  c3_o_y = NULL;
  if (!chartInstance->c3_i2ref_k_3_not_empty) {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_j_hoistedGlobal = chartInstance->c3_m2;
  c3_o_u = c3_j_hoistedGlobal;
  c3_p_y = NULL;
  if (!chartInstance->c3_m2_not_empty) {
    sf_mex_assign(&c3_p_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 14, c3_p_y);
  for (c3_i5 = 0; c3_i5 < 6; c3_i5++) {
    c3_p_u[c3_i5] = chartInstance->c3_omega_k[c3_i5];
  }

  c3_q_y = NULL;
  if (!chartInstance->c3_omega_k_not_empty) {
    sf_mex_assign(&c3_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_q_y, sf_mex_create("y", c3_p_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 15, c3_q_y);
  for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
    c3_q_u[c3_i6] = chartInstance->c3_omega_k_1[c3_i6];
  }

  c3_r_y = NULL;
  if (!chartInstance->c3_omega_k_1_not_empty) {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", c3_q_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 16, c3_r_y);
  for (c3_i7 = 0; c3_i7 < 6; c3_i7++) {
    c3_r_u[c3_i7] = chartInstance->c3_omega_k_2[c3_i7];
  }

  c3_s_y = NULL;
  if (!chartInstance->c3_omega_k_2_not_empty) {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", c3_r_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 17, c3_s_y);
  for (c3_i8 = 0; c3_i8 < 6; c3_i8++) {
    c3_s_u[c3_i8] = chartInstance->c3_omega_k_3[c3_i8];
  }

  c3_t_y = NULL;
  if (!chartInstance->c3_omega_k_3_not_empty) {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", c3_s_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_k_hoistedGlobal = chartInstance->c3_rho_k;
  c3_t_u = c3_k_hoistedGlobal;
  c3_u_y = NULL;
  if (!chartInstance->c3_rho_k_not_empty) {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 19, c3_u_y);
  for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
    c3_u_u[c3_i9] = chartInstance->c3_theta_k[c3_i9];
  }

  c3_v_y = NULL;
  if (!chartInstance->c3_theta_k_not_empty) {
    sf_mex_assign(&c3_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_v_y, sf_mex_create("y", c3_u_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_l_hoistedGlobal = chartInstance->c3_u_k_1;
  c3_v_u = c3_l_hoistedGlobal;
  c3_w_y = NULL;
  if (!chartInstance->c3_u_k_1_not_empty) {
    sf_mex_assign(&c3_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 21, c3_w_y);
  c3_m_hoistedGlobal = chartInstance->c3_u_k_2;
  c3_w_u = c3_m_hoistedGlobal;
  c3_x_y = NULL;
  if (!chartInstance->c3_u_k_2_not_empty) {
    sf_mex_assign(&c3_x_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 22, c3_x_y);
  c3_n_hoistedGlobal = chartInstance->c3_v_k_1;
  c3_x_u = c3_n_hoistedGlobal;
  c3_y_y = NULL;
  if (!chartInstance->c3_v_k_1_not_empty) {
    sf_mex_assign(&c3_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 23, c3_y_y);
  c3_o_hoistedGlobal = chartInstance->c3_v_k_2;
  c3_y_u = c3_o_hoistedGlobal;
  c3_ab_y = NULL;
  if (!chartInstance->c3_v_k_2_not_empty) {
    sf_mex_assign(&c3_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 24, c3_ab_y);
  c3_p_hoistedGlobal = chartInstance->c3_v_k_3;
  c3_ab_u = c3_p_hoistedGlobal;
  c3_bb_y = NULL;
  if (!chartInstance->c3_v_k_3_not_empty) {
    sf_mex_assign(&c3_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_ab_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 25, c3_bb_y);
  c3_q_hoistedGlobal = chartInstance->c3_vc_k_1;
  c3_bb_u = c3_q_hoistedGlobal;
  c3_cb_y = NULL;
  if (!chartInstance->c3_vc_k_1_not_empty) {
    sf_mex_assign(&c3_cb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_bb_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 26, c3_cb_y);
  c3_r_hoistedGlobal = chartInstance->c3_is_active_c3_vC_3ph_MR2;
  c3_cb_u = c3_r_hoistedGlobal;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_cb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 27, c3_db_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[6];
  int32_T c3_i10;
  real_T c3_dv1[36];
  int32_T c3_i11;
  real_T c3_dv2[6];
  int32_T c3_i12;
  real_T c3_dv3[6];
  int32_T c3_i13;
  real_T c3_dv4[6];
  int32_T c3_i14;
  real_T c3_dv5[6];
  int32_T c3_i15;
  real_T c3_dv6[6];
  int32_T c3_i16;
  real_T c3_dv7[6];
  int32_T c3_i17;
  real_T c3_dv8[6];
  int32_T c3_i18;
  real_T c3_dv9[6];
  int32_T c3_i19;
  real_T *c3_m;
  real_T *c3_up_beta;
  real_T (*c3_theta_beta)[6];
  c3_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_theta_beta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_up_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_m = c3_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "m");
  c3_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "theta_beta", c3_dv0);
  for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
    (*c3_theta_beta)[c3_i10] = c3_dv0[c3_i10];
  }

  *c3_up_beta = c3_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 2)), "up_beta");
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)), "P",
                        c3_dv1);
  for (c3_i11 = 0; c3_i11 < 36; c3_i11++) {
    chartInstance->c3_P[c3_i11] = c3_dv1[c3_i11];
  }

  c3_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
    "eta_k_1", c3_dv2);
  for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
    chartInstance->c3_eta_k_1[c3_i12] = c3_dv2[c3_i12];
  }

  c3_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
    "eta_k_2", c3_dv3);
  for (c3_i13 = 0; c3_i13 < 6; c3_i13++) {
    chartInstance->c3_eta_k_2[c3_i13] = c3_dv3[c3_i13];
  }

  c3_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
    "eta_k_3", c3_dv4);
  for (c3_i14 = 0; c3_i14 < 6; c3_i14++) {
    chartInstance->c3_eta_k_3[c3_i14] = c3_dv4[c3_i14];
  }

  chartInstance->c3_gama2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "gama2");
  chartInstance->c3_i2m_k_1 = c3_fb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "i2m_k_1");
  chartInstance->c3_i2m_k_2 = c3_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "i2m_k_2");
  chartInstance->c3_i2m_k_3 = c3_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "i2m_k_3");
  chartInstance->c3_i2ref_k_1 = c3_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "i2ref_k_1");
  chartInstance->c3_i2ref_k_2 = c3_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 12)), "i2ref_k_2");
  chartInstance->c3_i2ref_k_3 = c3_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 13)), "i2ref_k_3");
  chartInstance->c3_m2 = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 14)), "m2");
  c3_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 15)),
    "omega_k", c3_dv5);
  for (c3_i15 = 0; c3_i15 < 6; c3_i15++) {
    chartInstance->c3_omega_k[c3_i15] = c3_dv5[c3_i15];
  }

  c3_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 16)),
    "omega_k_1", c3_dv6);
  for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
    chartInstance->c3_omega_k_1[c3_i16] = c3_dv6[c3_i16];
  }

  c3_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 17)),
    "omega_k_2", c3_dv7);
  for (c3_i17 = 0; c3_i17 < 6; c3_i17++) {
    chartInstance->c3_omega_k_2[c3_i17] = c3_dv7[c3_i17];
  }

  c3_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 18)),
    "omega_k_3", c3_dv8);
  for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
    chartInstance->c3_omega_k_3[c3_i18] = c3_dv8[c3_i18];
  }

  chartInstance->c3_rho_k = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 19)), "rho_k");
  c3_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 20)),
    "theta_k", c3_dv9);
  for (c3_i19 = 0; c3_i19 < 6; c3_i19++) {
    chartInstance->c3_theta_k[c3_i19] = c3_dv9[c3_i19];
  }

  chartInstance->c3_u_k_1 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 21)), "u_k_1");
  chartInstance->c3_u_k_2 = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 22)), "u_k_2");
  chartInstance->c3_v_k_1 = c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 23)), "v_k_1");
  chartInstance->c3_v_k_2 = c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 24)), "v_k_2");
  chartInstance->c3_v_k_3 = c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 25)), "v_k_3");
  chartInstance->c3_vc_k_1 = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 26)), "vc_k_1");
  chartInstance->c3_is_active_c3_vC_3ph_MR2 = c3_dc_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 27)),
     "is_active_c3_vC_3ph_MR2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_vC_3ph_MR2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void sf_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
  int32_T c3_i20;
  real_T *c3_i2ref_k;
  real_T *c3_up_beta;
  real_T *c3_i2_k;
  real_T *c3_vc_k;
  real_T *c3_flag;
  real_T *c3_t;
  real_T *c3_m;
  real_T (*c3_theta_beta)[6];
  c3_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_theta_beta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_up_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_i2ref_k, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_up_beta, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_i2_k, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_vc_k, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_flag, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_t, 5U);
  for (c3_i20 = 0; c3_i20 < 6; c3_i20++) {
    _SFD_DATA_RANGE_CHECK((*c3_theta_beta)[c3_i20], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_m, 7U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_vC_3ph_MR2(chartInstance);
  sf_debug_check_for_state_inconsistency(_vC_3ph_MR2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_i2ref_k;
  real_T c3_i2_k;
  real_T c3_vc_k;
  real_T c3_flag;
  real_T c3_t;
  uint32_T c3_debug_family_var_map[80];
  real_T c3_L1ideal;
  real_T c3_L2ideal;
  real_T c3_Lgideal;
  real_T c3_Cideal;
  real_T c3_R1ideal;
  real_T c3_R2ideal;
  real_T c3_Rgideal;
  real_T c3_errL1;
  real_T c3_errL2;
  real_T c3_errLg;
  real_T c3_errC;
  real_T c3_errR1;
  real_T c3_errR2;
  real_T c3_errRg;
  real_T c3_deltaL1;
  real_T c3_deltaL2;
  real_T c3_deltaLg;
  real_T c3_deltaC;
  real_T c3_deltaR1;
  real_T c3_deltaR2;
  real_T c3_deltaRg;
  real_T c3_L1;
  real_T c3_L2;
  real_T c3_C;
  real_T c3_R1;
  real_T c3_R2;
  real_T c3_Ts;
  real_T c3_w;
  real_T c3_kp_kd;
  real_T c3_Kp;
  real_T c3_p1;
  real_T c3_p2;
  real_T c3_km;
  real_T c3_gamaD;
  real_T c3_gama;
  real_T c3_delta0;
  real_T c3_u_k;
  real_T c3_eta_k[6];
  real_T c3_i2m_k;
  real_T c3_e1_k;
  real_T c3_v_k;
  real_T c3_q_k;
  real_T c3_e2_k;
  real_T c3_ea_k;
  real_T c3_eta2_k[6];
  real_T c3_m2_k;
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 3.0;
  real_T c3_up_beta;
  real_T c3_theta_beta[6];
  real_T c3_m;
  int32_T c3_i21;
  static real_T c3_dv10[6] = { 1.0, -3.39, -0.18, 12.72, 0.0, 1.0 };

  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  static real_T c3_dv11[36] = { 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098 };

  real_T c3_b;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_d_b;
  real_T c3_d_y;
  int32_T c3_i30;
  real_T c3_f_hoistedGlobal[6];
  int32_T c3_i31;
  real_T c3_g_hoistedGlobal[6];
  int32_T c3_i32;
  real_T c3_a[6];
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_f_b;
  real_T c3_f_y;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  real_T c3_j_hoistedGlobal[6];
  int32_T c3_i38;
  int32_T c3_i39;
  real_T c3_k_hoistedGlobal;
  real_T c3_g_b;
  real_T c3_g_y;
  real_T c3_l_hoistedGlobal;
  real_T c3_h_b;
  real_T c3_h_y;
  real_T c3_m_hoistedGlobal;
  real_T c3_i_b;
  real_T c3_i_y;
  real_T c3_n_hoistedGlobal;
  real_T c3_j_b;
  real_T c3_j_y;
  real_T c3_o_hoistedGlobal;
  real_T c3_k_b;
  real_T c3_k_y;
  real_T c3_p_hoistedGlobal;
  real_T c3_l_b;
  real_T c3_l_y;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_c_k;
  int32_T c3_d_k;
  real_T c3_q_hoistedGlobal;
  real_T c3_b_a;
  real_T c3_m_b;
  real_T c3_m_y;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  real_T c3_n_y;
  int32_T c3_e_k;
  int32_T c3_f_k;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  real_T c3_o_y;
  int32_T c3_g_k;
  int32_T c3_h_k;
  int32_T c3_i50;
  real_T c3_r_hoistedGlobal[36];
  int32_T c3_i51;
  real_T c3_s_hoistedGlobal[36];
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  real_T c3_p_y[36];
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  real_T c3_q_y[36];
  int32_T c3_i64;
  int32_T c3_i65;
  real_T c3_B;
  real_T c3_r_y;
  real_T c3_s_y;
  int32_T c3_i66;
  int32_T c3_i67;
  real_T c3_t_hoistedGlobal;
  real_T c3_u_hoistedGlobal;
  real_T c3_c_a;
  real_T c3_n_b;
  real_T c3_t_y;
  real_T c3_A;
  real_T c3_b_B;
  real_T c3_e_x;
  real_T c3_u_y;
  real_T c3_f_x;
  real_T c3_v_y;
  real_T c3_w_y;
  int32_T c3_i68;
  real_T c3_o_b;
  real_T c3_x_y;
  real_T c3_b_A;
  real_T c3_c_B;
  real_T c3_g_x;
  real_T c3_y_y;
  real_T c3_h_x;
  real_T c3_ab_y;
  real_T c3_bb_y;
  real_T c3_d_a;
  int32_T c3_i69;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  real_T c3_v_hoistedGlobal;
  real_T c3_p_b;
  real_T c3_cb_y;
  real_T c3_e_a;
  real_T c3_q_b;
  real_T c3_db_y;
  real_T c3_c_A;
  real_T c3_d_B;
  real_T c3_i_x;
  real_T c3_eb_y;
  real_T c3_j_x;
  real_T c3_fb_y;
  real_T c3_gb_y;
  real_T c3_w_hoistedGlobal;
  real_T c3_r_b;
  real_T c3_hb_y;
  real_T c3_x_hoistedGlobal;
  real_T c3_s_b;
  real_T c3_ib_y;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  real_T c3_t_b;
  real_T c3_jb_y;
  real_T c3_u_b;
  real_T c3_kb_y;
  int32_T c3_i77;
  real_T c3_v_b;
  real_T c3_lb_y;
  real_T c3_w_b;
  real_T c3_mb_y;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  real_T *c3_b_i2ref_k;
  real_T *c3_b_i2_k;
  real_T *c3_b_vc_k;
  real_T *c3_b_flag;
  real_T *c3_b_t;
  real_T *c3_b_up_beta;
  real_T *c3_b_m;
  real_T (*c3_b_theta_beta)[6];
  c3_b_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_theta_beta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_up_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_i2ref_k;
  c3_b_hoistedGlobal = *c3_b_i2_k;
  c3_c_hoistedGlobal = *c3_b_vc_k;
  c3_d_hoistedGlobal = *c3_b_flag;
  c3_e_hoistedGlobal = *c3_b_t;
  c3_i2ref_k = c3_hoistedGlobal;
  c3_i2_k = c3_b_hoistedGlobal;
  c3_vc_k = c3_c_hoistedGlobal;
  c3_flag = c3_d_hoistedGlobal;
  c3_t = c3_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 80U, 80U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_L1ideal, 0U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_L2ideal, 1U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Lgideal, 2U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Cideal, 3U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_R1ideal, 4U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_R2ideal, 5U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Rgideal, 6U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errL1, 7U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errL2, 8U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errLg, 9U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errC, 10U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errR1, 11U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errR2, 12U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_errRg, 13U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_deltaL1, 14U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_deltaL2, 15U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_deltaLg, 16U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_deltaC, 17U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_deltaR1, 18U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_deltaR2, 19U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_deltaRg, 20U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_L1, 21U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_L2, 22U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_C, 23U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_R1, 24U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_R2, 25U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ts, 26U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w, 27U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_kp_kd, 28U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Kp, 29U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_p1, 30U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_p2, 31U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_km, 32U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_gamaD, 33U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_gama, 34U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_delta0, 35U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_u_k, 36U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_eta_k, 37U, c3_ab_sf_marshallOut,
    c3_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_i2m_k, 38U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_e1_k, 39U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v_k, 40U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_q_k, 41U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_e2_k, 42U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ea_k, 43U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_eta2_k, 44U, c3_ab_sf_marshallOut,
    c3_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_m2_k, 45U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 46U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 47U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_i2ref_k, 48U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_i2_k, 49U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_vc_k, 50U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_flag, 51U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_t, 52U, c3_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_up_beta, 53U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_theta_beta, 54U,
    c3_ab_sf_marshallOut, c3_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_m, 55U, c3_y_sf_marshallOut,
    c3_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_theta_k, 56U,
    c3_x_sf_marshallOut, c3_x_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_omega_k, 57U,
    c3_w_sf_marshallOut, c3_w_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_omega_k_1, 58U,
    c3_v_sf_marshallOut, c3_v_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_omega_k_2, 59U,
    c3_u_sf_marshallOut, c3_u_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_omega_k_3, 60U,
    c3_t_sf_marshallOut, c3_t_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_eta_k_1, 61U,
    c3_s_sf_marshallOut, c3_s_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_eta_k_2, 62U,
    c3_r_sf_marshallOut, c3_r_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_eta_k_3, 63U,
    c3_q_sf_marshallOut, c3_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2m_k_1, 64U,
    c3_p_sf_marshallOut, c3_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2m_k_2, 65U,
    c3_o_sf_marshallOut, c3_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2m_k_3, 66U,
    c3_n_sf_marshallOut, c3_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2ref_k_1, 67U,
    c3_m_sf_marshallOut, c3_m_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2ref_k_2, 68U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i2ref_k_3, 69U,
    c3_k_sf_marshallOut, c3_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_v_k_1, 70U,
    c3_j_sf_marshallOut, c3_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_v_k_2, 71U,
    c3_i_sf_marshallOut, c3_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_v_k_3, 72U,
    c3_h_sf_marshallOut, c3_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_rho_k, 73U,
    c3_g_sf_marshallOut, c3_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_m2, 74U,
    c3_f_sf_marshallOut, c3_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_vc_k_1, 75U,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_u_k_1, 76U,
    c3_d_sf_marshallOut, c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_u_k_2, 77U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_P, 78U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_gama2, 79U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_L1ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_L2ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_Lgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_Cideal = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_R1ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_R2ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_Rgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_errL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_errL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_errLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_errC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_errR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_errR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_errRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_deltaL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_deltaL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_deltaLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_deltaC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_deltaR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  c3_deltaR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_deltaRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_L1 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  c3_L2 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_C = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_R1 = c3_R1ideal + c3_deltaR1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  c3_R2 = ((c3_R2ideal + c3_deltaR2) + c3_Rgideal) + c3_deltaRg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  c3_Ts = 8.3333333333333331E-5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  c3_w = 2.4999999999999996E+7;
  c3_b_sqrt(chartInstance, &c3_w);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_kp_kd = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
  c3_Kp = 0.001792815465831;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
  c3_p1 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  c3_p2 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
  c3_km = 0.64000000000000012;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
  c3_gamaD = 0.0098;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
  c3_gama = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
  c3_delta0 = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_theta_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
    for (c3_i21 = 0; c3_i21 < 6; c3_i21++) {
      chartInstance->c3_theta_k[c3_i21] = c3_dv10[c3_i21];
    }

    chartInstance->c3_theta_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 77);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c3_omega_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 79);
    for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
      chartInstance->c3_omega_k[c3_i22] = 0.0;
    }

    chartInstance->c3_omega_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 83);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c3_omega_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
    for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
      chartInstance->c3_omega_k_1[c3_i23] = 0.0;
    }

    chartInstance->c3_omega_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 89);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c3_omega_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 91);
    for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
      chartInstance->c3_omega_k_2[c3_i24] = 0.0;
    }

    chartInstance->c3_omega_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c3_omega_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 97);
    for (c3_i25 = 0; c3_i25 < 6; c3_i25++) {
      chartInstance->c3_omega_k_3[c3_i25] = 0.0;
    }

    chartInstance->c3_omega_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c3_eta_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 103);
    for (c3_i26 = 0; c3_i26 < 6; c3_i26++) {
      chartInstance->c3_eta_k_1[c3_i26] = 0.0;
    }

    chartInstance->c3_eta_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 107);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c3_eta_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
    for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
      chartInstance->c3_eta_k_2[c3_i27] = 0.0;
    }

    chartInstance->c3_eta_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 113);
  if (CV_EML_IF(0, 1, 7, !chartInstance->c3_eta_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
    for (c3_i28 = 0; c3_i28 < 6; c3_i28++) {
      chartInstance->c3_eta_k_3[c3_i28] = 0.0;
    }

    chartInstance->c3_eta_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 119);
  if (CV_EML_IF(0, 1, 8, !chartInstance->c3_i2m_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 120);
    chartInstance->c3_i2m_k_1 = 0.0;
    chartInstance->c3_i2m_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 124);
  if (CV_EML_IF(0, 1, 9, !chartInstance->c3_i2m_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 125);
    chartInstance->c3_i2m_k_2 = 0.0;
    chartInstance->c3_i2m_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 129U);
  if (CV_EML_IF(0, 1, 10, !chartInstance->c3_i2m_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 130U);
    chartInstance->c3_i2m_k_3 = 0.0;
    chartInstance->c3_i2m_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 134U);
  if (CV_EML_IF(0, 1, 11, !chartInstance->c3_i2ref_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 135U);
    chartInstance->c3_i2ref_k_1 = 0.0;
    chartInstance->c3_i2ref_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
  if (CV_EML_IF(0, 1, 12, !chartInstance->c3_i2ref_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 140U);
    chartInstance->c3_i2ref_k_2 = 0.0;
    chartInstance->c3_i2ref_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
  if (CV_EML_IF(0, 1, 13, !chartInstance->c3_i2ref_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 145U);
    chartInstance->c3_i2ref_k_3 = 0.0;
    chartInstance->c3_i2ref_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 149U);
  if (CV_EML_IF(0, 1, 14, !chartInstance->c3_v_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 150U);
    chartInstance->c3_v_k_1 = 0.0;
    chartInstance->c3_v_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 154U);
  if (CV_EML_IF(0, 1, 15, !chartInstance->c3_v_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 155U);
    chartInstance->c3_v_k_2 = 0.0;
    chartInstance->c3_v_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 159U);
  if (CV_EML_IF(0, 1, 16, !chartInstance->c3_v_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 160U);
    chartInstance->c3_v_k_3 = 0.0;
    chartInstance->c3_v_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 164U);
  if (CV_EML_IF(0, 1, 17, !chartInstance->c3_rho_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 165U);
    chartInstance->c3_rho_k = 0.002801274165360937;
    chartInstance->c3_rho_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 169U);
  if (CV_EML_IF(0, 1, 18, !chartInstance->c3_m2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 170U);
    chartInstance->c3_m2 = 1.0;
    chartInstance->c3_m2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 174U);
  if (CV_EML_IF(0, 1, 19, !chartInstance->c3_vc_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 175U);
    chartInstance->c3_vc_k_1 = 0.0;
    chartInstance->c3_vc_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 179U);
  if (CV_EML_IF(0, 1, 20, !chartInstance->c3_u_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 180U);
    chartInstance->c3_u_k_1 = 0.0;
    chartInstance->c3_u_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 184U);
  if (CV_EML_IF(0, 1, 21, !chartInstance->c3_u_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 185U);
    chartInstance->c3_u_k_2 = 0.0;
    chartInstance->c3_u_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 189U);
  if (CV_EML_IF(0, 1, 22, !chartInstance->c3_P_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 201U);
    for (c3_i29 = 0; c3_i29 < 36; c3_i29++) {
      chartInstance->c3_P[c3_i29] = c3_dv11[c3_i29];
    }

    chartInstance->c3_P_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 205U);
  if (CV_EML_IF(0, 1, 23, !chartInstance->c3_gama2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 207U);
    chartInstance->c3_gama2 = c3_gama;
    chartInstance->c3_gama2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 214U);
  chartInstance->c3_omega_k[2] = c3_i2_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 215U);
  chartInstance->c3_omega_k[3] = c3_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 218U);
  c3_b = c3_t;
  c3_y = 376.99111843077515 * c3_b;
  c3_x = c3_y;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarSin(c3_b_x);
  c3_b_b = c3_b_x;
  c3_b_y = 311.0 * c3_b_b;
  chartInstance->c3_omega_k[4] = c3_b_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 219U);
  c3_c_b = c3_t;
  c3_c_y = 376.99111843077515 * c3_c_b;
  c3_c_x = c3_c_y;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_d_b = c3_d_x;
  c3_d_y = 311.0 * c3_d_b;
  chartInstance->c3_omega_k[5] = c3_d_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 223U);
  for (c3_i30 = 0; c3_i30 < 6; c3_i30++) {
    c3_f_hoistedGlobal[c3_i30] = chartInstance->c3_theta_k[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 6; c3_i31++) {
    c3_g_hoistedGlobal[c3_i31] = chartInstance->c3_omega_k[c3_i31];
  }

  for (c3_i32 = 0; c3_i32 < 6; c3_i32++) {
    c3_a[c3_i32] = c3_f_hoistedGlobal[c3_i32];
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  c3_u_k = 0.0;
  c3_eml_int_forloop_overflow_check(chartInstance);
  for (c3_k = 1; c3_k < 7; c3_k++) {
    c3_b_k = c3_k;
    c3_u_k += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_b_k), 1, 6, 1, 0) - 1] *
      c3_g_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 226U);
  c3_e_b = c3_u_k - c3_vc_k;
  c3_e_y = 3.0 * c3_e_b;
  c3_h_hoistedGlobal = chartInstance->c3_u_k_1;
  c3_i_hoistedGlobal = chartInstance->c3_vc_k_1;
  c3_f_b = c3_h_hoistedGlobal - c3_i_hoistedGlobal;
  c3_f_y = 3.0 * c3_f_b;
  c3_up_beta = c3_e_y - c3_f_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 228U);
  for (c3_i33 = 0; c3_i33 < 6; c3_i33++) {
    c3_f_hoistedGlobal[c3_i33] = chartInstance->c3_eta_k_1[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
    c3_f_hoistedGlobal[c3_i34] *= 0.4;
  }

  for (c3_i35 = 0; c3_i35 < 6; c3_i35++) {
    c3_g_hoistedGlobal[c3_i35] = chartInstance->c3_eta_k_2[c3_i35];
  }

  for (c3_i36 = 0; c3_i36 < 6; c3_i36++) {
    c3_g_hoistedGlobal[c3_i36] *= 0.040000000000000008;
  }

  for (c3_i37 = 0; c3_i37 < 6; c3_i37++) {
    c3_j_hoistedGlobal[c3_i37] = chartInstance->c3_omega_k_2[c3_i37];
  }

  for (c3_i38 = 0; c3_i38 < 6; c3_i38++) {
    c3_j_hoistedGlobal[c3_i38] *= 0.64000000000000012;
  }

  for (c3_i39 = 0; c3_i39 < 6; c3_i39++) {
    c3_eta_k[c3_i39] = (c3_f_hoistedGlobal[c3_i39] - c3_g_hoistedGlobal[c3_i39])
      + c3_j_hoistedGlobal[c3_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 230U);
  c3_k_hoistedGlobal = chartInstance->c3_i2m_k_1;
  c3_g_b = c3_k_hoistedGlobal;
  c3_g_y = 0.4 * c3_g_b;
  c3_l_hoistedGlobal = chartInstance->c3_i2m_k_2;
  c3_h_b = c3_l_hoistedGlobal;
  c3_h_y = 0.040000000000000008 * c3_h_b;
  c3_m_hoistedGlobal = chartInstance->c3_i2ref_k_2;
  c3_i_b = c3_m_hoistedGlobal;
  c3_i_y = 0.64000000000000012 * c3_i_b;
  c3_i2m_k = (c3_g_y - c3_h_y) + c3_i_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 232U);
  c3_e1_k = c3_i2_k - c3_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 234U);
  c3_n_hoistedGlobal = chartInstance->c3_v_k_1;
  c3_j_b = c3_n_hoistedGlobal;
  c3_j_y = 0.4 * c3_j_b;
  c3_o_hoistedGlobal = chartInstance->c3_v_k_2;
  c3_k_b = c3_o_hoistedGlobal;
  c3_k_y = 0.040000000000000008 * c3_k_b;
  c3_p_hoistedGlobal = chartInstance->c3_u_k_2;
  c3_l_b = c3_p_hoistedGlobal;
  c3_l_y = 0.64000000000000012 * c3_l_b;
  c3_v_k = (c3_j_y - c3_k_y) + c3_l_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 236U);
  for (c3_i40 = 0; c3_i40 < 6; c3_i40++) {
    c3_f_hoistedGlobal[c3_i40] = chartInstance->c3_theta_k[c3_i40];
  }

  for (c3_i41 = 0; c3_i41 < 6; c3_i41++) {
    c3_a[c3_i41] = c3_f_hoistedGlobal[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 6; c3_i42++) {
    c3_j_hoistedGlobal[c3_i42] = c3_eta_k[c3_i42];
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  c3_q_k = 0.0;
  c3_eml_int_forloop_overflow_check(chartInstance);
  for (c3_c_k = 1; c3_c_k < 7; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_q_k += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_d_k), 1, 6, 1, 0) - 1] *
      c3_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_d_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 238U);
  c3_e2_k = -c3_v_k + c3_q_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 240U);
  c3_q_hoistedGlobal = chartInstance->c3_rho_k;
  c3_b_a = c3_q_hoistedGlobal;
  c3_m_b = c3_e2_k;
  c3_m_y = c3_b_a * c3_m_b;
  c3_ea_k = c3_e1_k + c3_m_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 242U);
  for (c3_i43 = 0; c3_i43 < 6; c3_i43++) {
    c3_eta2_k[c3_i43] = c3_eta_k[c3_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 243U);
  c3_eta2_k[4] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 244U);
  c3_eta2_k[5] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 246U);
  if (CV_EML_IF(0, 1, 24, c3_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 248U);
    for (c3_i44 = 0; c3_i44 < 6; c3_i44++) {
      c3_a[c3_i44] = c3_eta2_k[c3_i44];
    }

    for (c3_i45 = 0; c3_i45 < 6; c3_i45++) {
      c3_a[c3_i45] *= 0.1;
    }

    for (c3_i46 = 0; c3_i46 < 6; c3_i46++) {
      c3_j_hoistedGlobal[c3_i46] = c3_eta2_k[c3_i46];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    c3_n_y = 0.0;
    c3_eml_int_forloop_overflow_check(chartInstance);
    for (c3_e_k = 1; c3_e_k < 7; c3_e_k++) {
      c3_f_k = c3_e_k;
      c3_n_y += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c3_f_k), 1, 6, 1, 0) - 1] *
        c3_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c3_f_k), 1, 6, 1, 0) - 1];
    }

    c3_m2_k = (c3_n_y + c3_mpower(chartInstance, c3_e2_k)) +
      chartInstance->c3_m2;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 251U);
    for (c3_i47 = 0; c3_i47 < 6; c3_i47++) {
      c3_a[c3_i47] = c3_eta2_k[c3_i47];
    }

    for (c3_i48 = 0; c3_i48 < 6; c3_i48++) {
      c3_a[c3_i48] *= 0.01;
    }

    for (c3_i49 = 0; c3_i49 < 6; c3_i49++) {
      c3_j_hoistedGlobal[c3_i49] = c3_eta2_k[c3_i49];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    c3_o_y = 0.0;
    c3_eml_int_forloop_overflow_check(chartInstance);
    for (c3_g_k = 1; c3_g_k < 7; c3_g_k++) {
      c3_h_k = c3_g_k;
      c3_o_y += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c3_h_k), 1, 6, 1, 0) - 1] *
        c3_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c3_h_k), 1, 6, 1, 0) - 1];
    }

    c3_m2_k = (c3_o_y + c3_mpower(chartInstance, c3_e2_k)) +
      chartInstance->c3_m2;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 254U);
  c3_m = c3_m2_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 256);
  for (c3_i50 = 0; c3_i50 < 36; c3_i50++) {
    c3_r_hoistedGlobal[c3_i50] = chartInstance->c3_P[c3_i50];
  }

  for (c3_i51 = 0; c3_i51 < 36; c3_i51++) {
    c3_s_hoistedGlobal[c3_i51] = chartInstance->c3_P[c3_i51];
  }

  for (c3_i52 = 0; c3_i52 < 6; c3_i52++) {
    c3_j_hoistedGlobal[c3_i52] = c3_eta_k[c3_i52];
  }

  c3_c_eml_scalar_eg(chartInstance);
  c3_c_eml_scalar_eg(chartInstance);
  for (c3_i53 = 0; c3_i53 < 6; c3_i53++) {
    c3_g_hoistedGlobal[c3_i53] = 0.0;
    c3_i54 = 0;
    for (c3_i55 = 0; c3_i55 < 6; c3_i55++) {
      c3_g_hoistedGlobal[c3_i53] += c3_s_hoistedGlobal[c3_i54 + c3_i53] *
        c3_j_hoistedGlobal[c3_i55];
      c3_i54 += 6;
    }
  }

  for (c3_i56 = 0; c3_i56 < 6; c3_i56++) {
    c3_a[c3_i56] = c3_eta_k[c3_i56];
  }

  c3_i57 = 0;
  for (c3_i58 = 0; c3_i58 < 6; c3_i58++) {
    for (c3_i59 = 0; c3_i59 < 6; c3_i59++) {
      c3_p_y[c3_i59 + c3_i57] = c3_g_hoistedGlobal[c3_i59] * c3_a[c3_i58];
    }

    c3_i57 += 6;
  }

  for (c3_i60 = 0; c3_i60 < 36; c3_i60++) {
    c3_s_hoistedGlobal[c3_i60] = chartInstance->c3_P[c3_i60];
  }

  c3_d_eml_scalar_eg(chartInstance);
  c3_d_eml_scalar_eg(chartInstance);
  for (c3_i61 = 0; c3_i61 < 6; c3_i61++) {
    c3_i62 = 0;
    for (c3_i63 = 0; c3_i63 < 6; c3_i63++) {
      c3_q_y[c3_i62 + c3_i61] = 0.0;
      c3_i64 = 0;
      for (c3_i65 = 0; c3_i65 < 6; c3_i65++) {
        c3_q_y[c3_i62 + c3_i61] += c3_p_y[c3_i64 + c3_i61] *
          c3_s_hoistedGlobal[c3_i65 + c3_i62];
        c3_i64 += 6;
      }

      c3_i62 += 6;
    }
  }

  c3_B = c3_m2_k;
  c3_r_y = c3_B;
  c3_s_y = c3_r_y;
  for (c3_i66 = 0; c3_i66 < 36; c3_i66++) {
    c3_q_y[c3_i66] /= c3_s_y;
  }

  for (c3_i67 = 0; c3_i67 < 36; c3_i67++) {
    chartInstance->c3_P[c3_i67] = c3_r_hoistedGlobal[c3_i67] - c3_q_y[c3_i67];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 257);
  c3_t_hoistedGlobal = chartInstance->c3_gama2;
  c3_u_hoistedGlobal = chartInstance->c3_gama2;
  c3_c_a = c3_mpower(chartInstance, c3_u_hoistedGlobal);
  c3_n_b = c3_mpower(chartInstance, c3_e2_k);
  c3_t_y = c3_c_a * c3_n_b;
  c3_A = c3_t_y;
  c3_b_B = c3_mpower(chartInstance, c3_m2_k);
  c3_e_x = c3_A;
  c3_u_y = c3_b_B;
  c3_f_x = c3_e_x;
  c3_v_y = c3_u_y;
  c3_w_y = c3_f_x / c3_v_y;
  chartInstance->c3_gama2 = c3_t_hoistedGlobal - c3_w_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 265);
  for (c3_i68 = 0; c3_i68 < 6; c3_i68++) {
    c3_f_hoistedGlobal[c3_i68] = chartInstance->c3_theta_k[c3_i68];
  }

  c3_o_b = c3_ea_k;
  c3_x_y = 0.0098 * c3_o_b;
  c3_b_A = c3_x_y;
  c3_c_B = c3_m2_k;
  c3_g_x = c3_b_A;
  c3_y_y = c3_c_B;
  c3_h_x = c3_g_x;
  c3_ab_y = c3_y_y;
  c3_bb_y = c3_h_x / c3_ab_y;
  c3_d_a = c3_bb_y;
  for (c3_i69 = 0; c3_i69 < 6; c3_i69++) {
    c3_j_hoistedGlobal[c3_i69] = c3_eta_k[c3_i69];
  }

  for (c3_i70 = 0; c3_i70 < 6; c3_i70++) {
    c3_j_hoistedGlobal[c3_i70] *= c3_d_a;
  }

  for (c3_i71 = 0; c3_i71 < 6; c3_i71++) {
    chartInstance->c3_theta_k[c3_i71] = c3_f_hoistedGlobal[c3_i71] -
      c3_j_hoistedGlobal[c3_i71];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 267);
  for (c3_i72 = 0; c3_i72 < 6; c3_i72++) {
    c3_theta_beta[c3_i72] = chartInstance->c3_theta_k[c3_i72];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 270);
  c3_v_hoistedGlobal = chartInstance->c3_rho_k;
  c3_p_b = c3_ea_k;
  c3_cb_y = 0.99 * c3_p_b;
  c3_e_a = c3_cb_y;
  c3_q_b = c3_e2_k;
  c3_db_y = c3_e_a * c3_q_b;
  c3_c_A = c3_db_y;
  c3_d_B = c3_m2_k;
  c3_i_x = c3_c_A;
  c3_eb_y = c3_d_B;
  c3_j_x = c3_i_x;
  c3_fb_y = c3_eb_y;
  c3_gb_y = c3_j_x / c3_fb_y;
  chartInstance->c3_rho_k = c3_v_hoistedGlobal - c3_gb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 272);
  if (CV_EML_IF(0, 1, 25, c3_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 274);
    c3_w_hoistedGlobal = chartInstance->c3_m2;
    c3_r_b = c3_w_hoistedGlobal - 1.0;
    c3_hb_y = 0.8 * c3_r_b;
    chartInstance->c3_m2 = ((c3_hb_y + c3_abs(chartInstance, c3_u_k)) + c3_abs
      (chartInstance, c3_i2_k)) + 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 277);
    c3_x_hoistedGlobal = chartInstance->c3_m2;
    c3_s_b = c3_x_hoistedGlobal - 1.0;
    c3_ib_y = 0.8 * c3_s_b;
    chartInstance->c3_m2 = ((c3_ib_y + c3_abs(chartInstance, c3_u_k)) + c3_abs
      (chartInstance, c3_i2_k)) + 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 280);
  for (c3_i73 = 0; c3_i73 < 6; c3_i73++) {
    chartInstance->c3_omega_k_3[c3_i73] = chartInstance->c3_omega_k_2[c3_i73];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 281);
  for (c3_i74 = 0; c3_i74 < 6; c3_i74++) {
    chartInstance->c3_omega_k_2[c3_i74] = chartInstance->c3_omega_k_1[c3_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 282);
  for (c3_i75 = 0; c3_i75 < 6; c3_i75++) {
    chartInstance->c3_omega_k_1[c3_i75] = chartInstance->c3_omega_k[c3_i75];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 284);
  for (c3_i76 = 0; c3_i76 < 6; c3_i76++) {
    c3_f_hoistedGlobal[c3_i76] = chartInstance->c3_omega_k[c3_i76];
  }

  c3_t_b = c3_f_hoistedGlobal[0];
  c3_jb_y = 0.0 * c3_t_b;
  c3_u_b = c3_u_k;
  c3_kb_y = c3_u_b;
  chartInstance->c3_omega_k[0] = c3_jb_y + c3_kb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 285);
  for (c3_i77 = 0; c3_i77 < 6; c3_i77++) {
    c3_f_hoistedGlobal[c3_i77] = chartInstance->c3_omega_k[c3_i77];
  }

  c3_v_b = c3_f_hoistedGlobal[1];
  c3_lb_y = 0.0 * c3_v_b;
  c3_w_b = c3_i2_k;
  c3_mb_y = c3_w_b;
  chartInstance->c3_omega_k[1] = c3_lb_y + c3_mb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 287);
  for (c3_i78 = 0; c3_i78 < 6; c3_i78++) {
    chartInstance->c3_eta_k_3[c3_i78] = chartInstance->c3_eta_k_2[c3_i78];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 288);
  for (c3_i79 = 0; c3_i79 < 6; c3_i79++) {
    chartInstance->c3_eta_k_2[c3_i79] = chartInstance->c3_eta_k_1[c3_i79];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 289);
  for (c3_i80 = 0; c3_i80 < 6; c3_i80++) {
    chartInstance->c3_eta_k_1[c3_i80] = c3_eta_k[c3_i80];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 291);
  chartInstance->c3_i2ref_k_3 = chartInstance->c3_i2ref_k_2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 292);
  chartInstance->c3_i2ref_k_2 = chartInstance->c3_i2ref_k_1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 293);
  chartInstance->c3_i2ref_k_1 = c3_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 295);
  chartInstance->c3_i2m_k_3 = chartInstance->c3_i2m_k_2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 296);
  chartInstance->c3_i2m_k_2 = chartInstance->c3_i2m_k_1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 297);
  chartInstance->c3_i2m_k_1 = c3_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 299);
  chartInstance->c3_v_k_3 = chartInstance->c3_v_k_2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 300);
  chartInstance->c3_v_k_2 = chartInstance->c3_v_k_1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 301);
  chartInstance->c3_v_k_1 = c3_v_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 303);
  chartInstance->c3_u_k_2 = chartInstance->c3_u_k_1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 304);
  chartInstance->c3_u_k_1 = c3_u_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 306);
  chartInstance->c3_vc_k_1 = c3_vc_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -306);
  sf_debug_symbol_scope_pop();
  *c3_b_up_beta = c3_up_beta;
  for (c3_i81 = 0; c3_i81 < 6; c3_i81++) {
    (*c3_b_theta_beta)[c3_i81] = c3_theta_beta[c3_i81];
  }

  *c3_b_m = c3_m;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_vC_3ph_MR2(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_gama2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_gama2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_gama2), &c3_thisId);
  sf_mex_destroy(&c3_b_gama2);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_gama2_not_empty = FALSE;
  } else {
    chartInstance->c3_gama2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_gama2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_gama2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_gama2), &c3_thisId);
  sf_mex_destroy(&c3_b_gama2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  real_T c3_b_inData[36];
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  real_T c3_u[36];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i82 = 0;
  for (c3_i83 = 0; c3_i83 < 6; c3_i83++) {
    for (c3_i84 = 0; c3_i84 < 6; c3_i84++) {
      c3_b_inData[c3_i84 + c3_i82] = (*(real_T (*)[36])c3_inData)[c3_i84 +
        c3_i82];
    }

    c3_i82 += 6;
  }

  c3_i85 = 0;
  for (c3_i86 = 0; c3_i86 < 6; c3_i86++) {
    for (c3_i87 = 0; c3_i87 < 6; c3_i87++) {
      c3_u[c3_i87 + c3_i85] = c3_b_inData[c3_i87 + c3_i85];
    }

    c3_i85 += 6;
  }

  c3_y = NULL;
  if (!chartInstance->c3_P_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_P, const char_T *c3_identifier, real_T c3_y[36])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_P), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_P);
}

static void c3_d_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[36])
{
  real_T c3_dv12[36];
  int32_T c3_i88;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_P_not_empty = FALSE;
  } else {
    chartInstance->c3_P_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv12, 1, 0, 0U, 1, 0U, 2, 6,
                  6);
    for (c3_i88 = 0; c3_i88 < 36; c3_i88++) {
      c3_y[c3_i88] = c3_dv12[c3_i88];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_P;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[36];
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_P = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_P), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_P);
  c3_i89 = 0;
  for (c3_i90 = 0; c3_i90 < 6; c3_i90++) {
    for (c3_i91 = 0; c3_i91 < 6; c3_i91++) {
      (*(real_T (*)[36])c3_outData)[c3_i91 + c3_i89] = c3_y[c3_i91 + c3_i89];
    }

    c3_i89 += 6;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_u_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_u_k_2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u_k_2), &c3_thisId);
  sf_mex_destroy(&c3_b_u_k_2);
  return c3_y;
}

static real_T c3_f_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_u_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_u_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_u_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u_k_2), &c3_thisId);
  sf_mex_destroy(&c3_b_u_k_2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_u_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_g_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_u_k_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u_k_1), &c3_thisId);
  sf_mex_destroy(&c3_b_u_k_1);
  return c3_y;
}

static real_T c3_h_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_u_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_u_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_u_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u_k_1), &c3_thisId);
  sf_mex_destroy(&c3_b_u_k_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_vc_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_i_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_vc_k_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_vc_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_vc_k_1);
  return c3_y;
}

static real_T c3_j_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d3;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_vc_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_vc_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d3, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d3;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_vc_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_vc_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_vc_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_vc_k_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_m2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_k_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_m2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_m2), &c3_thisId);
  sf_mex_destroy(&c3_b_m2);
  return c3_y;
}

static real_T c3_l_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d4;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_m2_not_empty = FALSE;
  } else {
    chartInstance->c3_m2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d4, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d4;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_m2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_m2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_m2), &c3_thisId);
  sf_mex_destroy(&c3_b_m2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_rho_k_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_m_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_rho_k, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_rho_k), &c3_thisId);
  sf_mex_destroy(&c3_b_rho_k);
  return c3_y;
}

static real_T c3_n_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d5;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_rho_k_not_empty = FALSE;
  } else {
    chartInstance->c3_rho_k_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d5, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d5;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_rho_k;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_rho_k = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_rho_k), &c3_thisId);
  sf_mex_destroy(&c3_b_rho_k);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_v_k_3_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_o_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_3, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_3), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_3);
  return c3_y;
}

static real_T c3_p_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d6;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_v_k_3_not_empty = FALSE;
  } else {
    chartInstance->c3_v_k_3_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d6, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d6;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_v_k_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_v_k_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_3), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_3);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_v_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_q_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_2), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_2);
  return c3_y;
}

static real_T c3_r_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d7;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_v_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_v_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d7, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d7;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_v_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_v_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_2), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_v_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_s_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_v_k_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_1), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_1);
  return c3_y;
}

static real_T c3_t_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d8;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_v_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_v_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d8, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d8;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_v_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_v_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_v_k_1), &c3_thisId);
  sf_mex_destroy(&c3_b_v_k_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2ref_k_3_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_u_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_3, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_3),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_3);
  return c3_y;
}

static real_T c3_v_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d9;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2ref_k_3_not_empty = FALSE;
  } else {
    chartInstance->c3_i2ref_k_3_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d9, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d9;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2ref_k_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2ref_k_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_3),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_3);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2ref_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_w_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_2),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_2);
  return c3_y;
}

static real_T c3_x_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d10;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2ref_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_i2ref_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d10, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d10;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2ref_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2ref_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_2),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2ref_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_y_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_i2ref_k_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_1);
  return c3_y;
}

static real_T c3_ab_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d11;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2ref_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_i2ref_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d11, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d11;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2ref_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2ref_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2ref_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2ref_k_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2m_k_3_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_bb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_3, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_3),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_3);
  return c3_y;
}

static real_T c3_cb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d12;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2m_k_3_not_empty = FALSE;
  } else {
    chartInstance->c3_i2m_k_3_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d12, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d12;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2m_k_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2m_k_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_3),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_3);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2m_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_db_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_2),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_2);
  return c3_y;
}

static real_T c3_eb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d13;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2m_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_i2m_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d13, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d13;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2m_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2m_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_2),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i2m_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_fb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_i2m_k_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_1);
  return c3_y;
}

static real_T c3_gb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d14;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i2m_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_i2m_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d14, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d14;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i2m_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_i2m_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i2m_k_1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_i2m_k_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i92;
  real_T c3_b_inData[6];
  int32_T c3_i93;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i92 = 0; c3_i92 < 6; c3_i92++) {
    c3_b_inData[c3_i92] = (*(real_T (*)[6])c3_inData)[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 6; c3_i93++) {
    c3_u[c3_i93] = c3_b_inData[c3_i93];
  }

  c3_y = NULL;
  if (!chartInstance->c3_eta_k_3_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_hb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_3, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_3), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_3);
}

static void c3_ib_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv13[6];
  int32_T c3_i94;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_eta_k_3_not_empty = FALSE;
  } else {
    chartInstance->c3_eta_k_3_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv13, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i94 = 0; c3_i94 < 6; c3_i94++) {
      c3_y[c3_i94] = c3_dv13[c3_i94];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_eta_k_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i95;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_eta_k_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_3), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_3);
  for (c3_i95 = 0; c3_i95 < 6; c3_i95++) {
    (*(real_T (*)[6])c3_outData)[c3_i95] = c3_y[c3_i95];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i96;
  real_T c3_b_inData[6];
  int32_T c3_i97;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i96 = 0; c3_i96 < 6; c3_i96++) {
    c3_b_inData[c3_i96] = (*(real_T (*)[6])c3_inData)[c3_i96];
  }

  for (c3_i97 = 0; c3_i97 < 6; c3_i97++) {
    c3_u[c3_i97] = c3_b_inData[c3_i97];
  }

  c3_y = NULL;
  if (!chartInstance->c3_eta_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_jb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_2, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_2), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_2);
}

static void c3_kb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv14[6];
  int32_T c3_i98;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_eta_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_eta_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv14, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i98 = 0; c3_i98 < 6; c3_i98++) {
      c3_y[c3_i98] = c3_dv14[c3_i98];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_eta_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i99;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_eta_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_2), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_2);
  for (c3_i99 = 0; c3_i99 < 6; c3_i99++) {
    (*(real_T (*)[6])c3_outData)[c3_i99] = c3_y[c3_i99];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i100;
  real_T c3_b_inData[6];
  int32_T c3_i101;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i100 = 0; c3_i100 < 6; c3_i100++) {
    c3_b_inData[c3_i100] = (*(real_T (*)[6])c3_inData)[c3_i100];
  }

  for (c3_i101 = 0; c3_i101 < 6; c3_i101++) {
    c3_u[c3_i101] = c3_b_inData[c3_i101];
  }

  c3_y = NULL;
  if (!chartInstance->c3_eta_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_lb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_eta_k_1, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_1), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_1);
}

static void c3_mb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv15[6];
  int32_T c3_i102;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_eta_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_eta_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv15, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i102 = 0; c3_i102 < 6; c3_i102++) {
      c3_y[c3_i102] = c3_dv15[c3_i102];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_eta_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i103;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_eta_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_eta_k_1), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_eta_k_1);
  for (c3_i103 = 0; c3_i103 < 6; c3_i103++) {
    (*(real_T (*)[6])c3_outData)[c3_i103] = c3_y[c3_i103];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i104;
  real_T c3_b_inData[6];
  int32_T c3_i105;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i104 = 0; c3_i104 < 6; c3_i104++) {
    c3_b_inData[c3_i104] = (*(real_T (*)[6])c3_inData)[c3_i104];
  }

  for (c3_i105 = 0; c3_i105 < 6; c3_i105++) {
    c3_u[c3_i105] = c3_b_inData[c3_i105];
  }

  c3_y = NULL;
  if (!chartInstance->c3_omega_k_3_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_nb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_3, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_3), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_3);
}

static void c3_ob_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv16[6];
  int32_T c3_i106;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_omega_k_3_not_empty = FALSE;
  } else {
    chartInstance->c3_omega_k_3_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv16, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i106 = 0; c3_i106 < 6; c3_i106++) {
      c3_y[c3_i106] = c3_dv16[c3_i106];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_omega_k_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i107;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_omega_k_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_3), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_3);
  for (c3_i107 = 0; c3_i107 < 6; c3_i107++) {
    (*(real_T (*)[6])c3_outData)[c3_i107] = c3_y[c3_i107];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i108;
  real_T c3_b_inData[6];
  int32_T c3_i109;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i108 = 0; c3_i108 < 6; c3_i108++) {
    c3_b_inData[c3_i108] = (*(real_T (*)[6])c3_inData)[c3_i108];
  }

  for (c3_i109 = 0; c3_i109 < 6; c3_i109++) {
    c3_u[c3_i109] = c3_b_inData[c3_i109];
  }

  c3_y = NULL;
  if (!chartInstance->c3_omega_k_2_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_pb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_2, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_2), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_2);
}

static void c3_qb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv17[6];
  int32_T c3_i110;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_omega_k_2_not_empty = FALSE;
  } else {
    chartInstance->c3_omega_k_2_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv17, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i110 = 0; c3_i110 < 6; c3_i110++) {
      c3_y[c3_i110] = c3_dv17[c3_i110];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_omega_k_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i111;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_omega_k_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_2), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_2);
  for (c3_i111 = 0; c3_i111 < 6; c3_i111++) {
    (*(real_T (*)[6])c3_outData)[c3_i111] = c3_y[c3_i111];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i112;
  real_T c3_b_inData[6];
  int32_T c3_i113;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i112 = 0; c3_i112 < 6; c3_i112++) {
    c3_b_inData[c3_i112] = (*(real_T (*)[6])c3_inData)[c3_i112];
  }

  for (c3_i113 = 0; c3_i113 < 6; c3_i113++) {
    c3_u[c3_i113] = c3_b_inData[c3_i113];
  }

  c3_y = NULL;
  if (!chartInstance->c3_omega_k_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_rb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k_1, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_1), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_1);
}

static void c3_sb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv18[6];
  int32_T c3_i114;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_omega_k_1_not_empty = FALSE;
  } else {
    chartInstance->c3_omega_k_1_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv18, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i114 = 0; c3_i114 < 6; c3_i114++) {
      c3_y[c3_i114] = c3_dv18[c3_i114];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_omega_k_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i115;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_omega_k_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k_1), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k_1);
  for (c3_i115 = 0; c3_i115 < 6; c3_i115++) {
    (*(real_T (*)[6])c3_outData)[c3_i115] = c3_y[c3_i115];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i116;
  real_T c3_b_inData[6];
  int32_T c3_i117;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i116 = 0; c3_i116 < 6; c3_i116++) {
    c3_b_inData[c3_i116] = (*(real_T (*)[6])c3_inData)[c3_i116];
  }

  for (c3_i117 = 0; c3_i117 < 6; c3_i117++) {
    c3_u[c3_i117] = c3_b_inData[c3_i117];
  }

  c3_y = NULL;
  if (!chartInstance->c3_omega_k_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_tb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_omega_k, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k);
}

static void c3_ub_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv19[6];
  int32_T c3_i118;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_omega_k_not_empty = FALSE;
  } else {
    chartInstance->c3_omega_k_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv19, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i118 = 0; c3_i118 < 6; c3_i118++) {
      c3_y[c3_i118] = c3_dv19[c3_i118];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_omega_k;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i119;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_omega_k = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_omega_k), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_omega_k);
  for (c3_i119 = 0; c3_i119 < 6; c3_i119++) {
    (*(real_T (*)[6])c3_outData)[c3_i119] = c3_y[c3_i119];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i120;
  real_T c3_b_inData[6];
  int32_T c3_i121;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i120 = 0; c3_i120 < 6; c3_i120++) {
    c3_b_inData[c3_i120] = (*(real_T (*)[6])c3_inData)[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 6; c3_i121++) {
    c3_u[c3_i121] = c3_b_inData[c3_i121];
  }

  c3_y = NULL;
  if (!chartInstance->c3_theta_k_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_vb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_b_theta_k, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_theta_k), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_theta_k);
}

static void c3_wb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv20[6];
  int32_T c3_i122;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_theta_k_not_empty = FALSE;
  } else {
    chartInstance->c3_theta_k_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv20, 1, 0, 0U, 1, 0U, 1, 6);
    for (c3_i122 = 0; c3_i122 < 6; c3_i122++) {
      c3_y[c3_i122] = c3_dv20[c3_i122];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_theta_k;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i123;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_theta_k = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_theta_k), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_b_theta_k);
  for (c3_i123 = 0; c3_i123 < 6; c3_i123++) {
    (*(real_T (*)[6])c3_outData)[c3_i123] = c3_y[c3_i123];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_xb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_m, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_m), &c3_thisId);
  sf_mex_destroy(&c3_m);
  return c3_y;
}

static real_T c3_yb_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d15;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d15, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d15;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_m;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_m = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_m), &c3_thisId);
  sf_mex_destroy(&c3_m);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i124;
  real_T c3_b_inData[6];
  int32_T c3_i125;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i124 = 0; c3_i124 < 6; c3_i124++) {
    c3_b_inData[c3_i124] = (*(real_T (*)[6])c3_inData)[c3_i124];
  }

  for (c3_i125 = 0; c3_i125 < 6; c3_i125++) {
    c3_u[c3_i125] = c3_b_inData[c3_i125];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_ac_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_theta_beta, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_theta_beta), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_theta_beta);
}

static void c3_bc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv21[6];
  int32_T c3_i126;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv21, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i126 = 0; c3_i126 < 6; c3_i126++) {
    c3_y[c3_i126] = c3_dv21[c3_i126];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_theta_beta;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i127;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_theta_beta = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_theta_beta), &c3_thisId,
    c3_y);
  sf_mex_destroy(&c3_theta_beta);
  for (c3_i127 = 0; c3_i127 < 6; c3_i127++) {
    (*(real_T (*)[6])c3_outData)[c3_i127] = c3_y[c3_i127];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_vC_3ph_MR2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[56];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i128;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 56), FALSE);
  for (c3_i128 = 0; c3_i128 < 56; c3_i128++) {
    c3_r0 = &c3_info[c3_i128];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i128);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i128);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[56])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289523292U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mrdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].fileTimeLo = 1325127738U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 1319737166U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[2].name = "rdivide";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].fileTimeLo = 1286826044U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_div";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[3].fileTimeLo = 1313355010U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "";
  c3_info[4].name = "sqrt";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[4].fileTimeLo = 1286825952U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[5].name = "eml_error";
  c3_info[5].dominantType = "char";
  c3_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[5].fileTimeLo = 1305325200U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[6].name = "eml_scalar_sqrt";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[6].fileTimeLo = 1286825938U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "";
  c3_info[7].name = "eye";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m";
  c3_info[7].fileTimeLo = 1286825888U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[8].name = "eml_assert_valid_size_arg";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[8].fileTimeLo = 1286825894U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c3_info[9].name = "isinf";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[9].fileTimeLo = 1286825960U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c3_info[10].name = "mtimes";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].fileTimeLo = 1289523292U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[11].name = "eml_index_class";
  c3_info[11].dominantType = "";
  c3_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[11].fileTimeLo = 1286825978U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[12].name = "intmax";
  c3_info[12].dominantType = "char";
  c3_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[12].fileTimeLo = 1311262516U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[13].name = "eml_is_float_class";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[13].fileTimeLo = 1286825982U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[14].name = "min";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[14].fileTimeLo = 1311262518U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[15].name = "eml_min_or_max";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[15].fileTimeLo = 1303153412U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[16].name = "eml_scalar_eg";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[16].fileTimeLo = 1286825996U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[17].name = "eml_scalexp_alloc";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[17].fileTimeLo = 1286825996U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[18].name = "eml_index_class";
  c3_info[18].dominantType = "";
  c3_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[18].fileTimeLo = 1286825978U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[19].name = "eml_scalar_eg";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[19].fileTimeLo = 1286825996U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[20].name = "eml_index_class";
  c3_info[20].dominantType = "";
  c3_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[20].fileTimeLo = 1286825978U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[21].name = "eml_int_forloop_overflow_check";
  c3_info[21].dominantType = "";
  c3_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[21].fileTimeLo = 1311262516U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[22].name = "intmax";
  c3_info[22].dominantType = "char";
  c3_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[22].fileTimeLo = 1311262516U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context = "";
  c3_info[23].name = "sin";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[23].fileTimeLo = 1286825950U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[24].name = "eml_scalar_sin";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[24].fileTimeLo = 1286825936U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context = "";
  c3_info[25].name = "cos";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[25].fileTimeLo = 1286825906U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[26].name = "eml_scalar_cos";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[26].fileTimeLo = 1286825922U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[27].name = "eml_index_class";
  c3_info[27].dominantType = "";
  c3_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[27].fileTimeLo = 1286825978U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[28].name = "eml_scalar_eg";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[28].fileTimeLo = 1286825996U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[29].name = "eml_xdotu";
  c3_info[29].dominantType = "int32";
  c3_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[29].fileTimeLo = 1299080372U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[30].name = "eml_blas_inline";
  c3_info[30].dominantType = "";
  c3_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[30].fileTimeLo = 1299080368U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[31].name = "eml_xdot";
  c3_info[31].dominantType = "int32";
  c3_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[31].fileTimeLo = 1299080372U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[32].name = "eml_blas_inline";
  c3_info[32].dominantType = "";
  c3_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[32].fileTimeLo = 1299080368U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[33].name = "eml_refblas_xdot";
  c3_info[33].dominantType = "int32";
  c3_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[33].fileTimeLo = 1299080372U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[34].name = "eml_refblas_xdotx";
  c3_info[34].dominantType = "int32";
  c3_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[34].fileTimeLo = 1299080374U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[35].name = "eml_scalar_eg";
  c3_info[35].dominantType = "double";
  c3_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[35].fileTimeLo = 1286825996U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[36].name = "eml_index_class";
  c3_info[36].dominantType = "";
  c3_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[36].fileTimeLo = 1286825978U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[37].name = "eml_index_minus";
  c3_info[37].dominantType = "int32";
  c3_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[37].fileTimeLo = 1286825978U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[38].name = "eml_index_class";
  c3_info[38].dominantType = "";
  c3_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[38].fileTimeLo = 1286825978U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[39].name = "eml_index_times";
  c3_info[39].dominantType = "int32";
  c3_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[39].fileTimeLo = 1286825980U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[40].name = "eml_index_class";
  c3_info[40].dominantType = "";
  c3_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[40].fileTimeLo = 1286825978U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[41].name = "eml_index_plus";
  c3_info[41].dominantType = "int32";
  c3_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[41].fileTimeLo = 1286825978U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[42].name = "eml_index_class";
  c3_info[42].dominantType = "";
  c3_info[42].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[42].fileTimeLo = 1286825978U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[43].name = "eml_int_forloop_overflow_check";
  c3_info[43].dominantType = "";
  c3_info[43].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[43].fileTimeLo = 1311262516U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context = "";
  c3_info[44].name = "mpower";
  c3_info[44].dominantType = "double";
  c3_info[44].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[44].fileTimeLo = 1286826042U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[45].name = "power";
  c3_info[45].dominantType = "double";
  c3_info[45].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[45].fileTimeLo = 1307658440U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[46].name = "eml_scalar_eg";
  c3_info[46].dominantType = "double";
  c3_info[46].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[46].fileTimeLo = 1286825996U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[47].name = "eml_scalexp_alloc";
  c3_info[47].dominantType = "double";
  c3_info[47].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[47].fileTimeLo = 1286825996U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[48].name = "eml_scalar_floor";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[48].fileTimeLo = 1286825926U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[49].name = "eml_xgemm";
  c3_info[49].dominantType = "int32";
  c3_info[49].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[49].fileTimeLo = 1299080372U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[50].name = "eml_blas_inline";
  c3_info[50].dominantType = "";
  c3_info[50].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[50].fileTimeLo = 1299080368U;
  c3_info[50].fileTimeHi = 0U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[51].name = "mtimes";
  c3_info[51].dominantType = "double";
  c3_info[51].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[51].fileTimeLo = 1289523292U;
  c3_info[51].fileTimeHi = 0U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[52].name = "eml_scalar_eg";
  c3_info[52].dominantType = "double";
  c3_info[52].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[52].fileTimeLo = 1286825996U;
  c3_info[52].fileTimeHi = 0U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[53].name = "eml_refblas_xgemm";
  c3_info[53].dominantType = "int32";
  c3_info[53].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[53].fileTimeLo = 1299080374U;
  c3_info[53].fileTimeHi = 0U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
  c3_info[54].context = "";
  c3_info[54].name = "abs";
  c3_info[54].dominantType = "double";
  c3_info[54].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[54].fileTimeLo = 1286825894U;
  c3_info[54].fileTimeHi = 0U;
  c3_info[54].mFileTimeLo = 0U;
  c3_info[54].mFileTimeHi = 0U;
  c3_info[55].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[55].name = "eml_scalar_abs";
  c3_info[55].dominantType = "double";
  c3_info[55].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[55].fileTimeLo = 1286825912U;
  c3_info[55].fileTimeHi = 0U;
  c3_info[55].mFileTimeLo = 0U;
  c3_info[55].mFileTimeHi = 0U;
}

static real_T c3_sqrt(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sqrt(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_eml_error(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
  int32_T c3_i129;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i129 = 0; c3_i129 < 30; c3_i129++) {
    c3_u[c3_i129] = c3_varargin_1[c3_i129];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static void c3_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void c3_eml_int_forloop_overflow_check(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void c3_b_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c3_mpower(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T
  c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_c_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void c3_d_eml_scalar_eg(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c3_abs(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  return muDoubleScalarAbs(c3_b_x);
}

static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_cc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i130;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i130, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i130;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_cc_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_dc_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_vC_3ph_MR2, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_ec_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_vC_3ph_MR2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_vC_3ph_MR2);
  return c3_y;
}

static uint8_T c3_ec_emlrt_marshallIn(SFc3_vC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sqrt(SFc3_vC_3ph_MR2InstanceStruct *chartInstance, real_T *c3_x)
{
  if (*c3_x < 0.0) {
    c3_eml_error(chartInstance);
  }

  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void init_dsm_address_info(SFc3_vC_3ph_MR2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_vC_3ph_MR2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2638226334U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3734700068U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4277431718U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3003034602U);
}

mxArray *sf_c3_vC_3ph_MR2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aV2dpD36O7GWkaiCZLO6oB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(6);
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

static const mxArray *sf_get_sim_state_info_c3_vC_3ph_MR2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[16],T\"m\",},{M[1],M[15],T\"theta_beta\",},{M[1],M[5],T\"up_beta\",},{M[4],M[0],T\"P\",S'l','i','p'{{M1x2[3359 3360],M[0],}}},{M[4],M[0],T\"eta_k_1\",S'l','i','p'{{M1x2[2284 2291],M[0],}}},{M[4],M[0],T\"eta_k_2\",S'l','i','p'{{M1x2[2373 2380],M[0],}}},{M[4],M[0],T\"eta_k_3\",S'l','i','p'{{M1x2[2462 2469],M[0],}}},{M[4],M[0],T\"gama2\",S'l','i','p'{{M1x2[4562 4567],M[0],}}},{M[4],M[0],T\"i2m_k_1\",S'l','i','p'{{M1x2[2551 2558],M[0],}}},{M[4],M[0],T\"i2m_k_2\",S'l','i','p'{{M1x2[2611 2618],M[0],}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"i2m_k_3\",S'l','i','p'{{M1x2[2671 2678],M[0],}}},{M[4],M[0],T\"i2ref_k_1\",S'l','i','p'{{M1x2[2731 2740],M[0],}}},{M[4],M[0],T\"i2ref_k_2\",S'l','i','p'{{M1x2[2797 2806],M[0],}}},{M[4],M[0],T\"i2ref_k_3\",S'l','i','p'{{M1x2[2863 2872],M[0],}}},{M[4],M[0],T\"m2\",S'l','i','p'{{M1x2[3149 3151],M[0],}}},{M[4],M[0],T\"omega_k\",S'l','i','p'{{M1x2[1910 1917],M[0],}}},{M[4],M[0],T\"omega_k_1\",S'l','i','p'{{M1x2[1999 2008],M[0],}}},{M[4],M[0],T\"omega_k_2\",S'l','i','p'{{M1x2[2094 2103],M[0],}}},{M[4],M[0],T\"omega_k_3\",S'l','i','p'{{M1x2[2189 2198],M[0],}}},{M[4],M[0],T\"rho_k\",S'l','i','p'{{M1x2[3091 3096],M[0],}}}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[4],M[0],T\"theta_k\",S'l','i','p'{{M1x2[1196 1203],M[0],}}},{M[4],M[0],T\"u_k_1\",S'l','i','p'{{M1x2[3251 3256],M[0],}}},{M[4],M[0],T\"u_k_2\",S'l','i','p'{{M1x2[3305 3310],M[0],}}},{M[4],M[0],T\"v_k_1\",S'l','i','p'{{M1x2[2929 2934],M[0],}}},{M[4],M[0],T\"v_k_2\",S'l','i','p'{{M1x2[2983 2988],M[0],}}},{M[4],M[0],T\"v_k_3\",S'l','i','p'{{M1x2[3037 3042],M[0],}}},{M[4],M[0],T\"vc_k_1\",S'l','i','p'{{M1x2[3194 3200],M[0],}}},{M[8],M[0],T\"is_active_c3_vC_3ph_MR2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 28, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_vC_3ph_MR2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
    chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_vC_3ph_MR2MachineNumber_,
           3,
           1,
           1,
           8,
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
          init_script_number_translation(_vC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_vC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_vC_3ph_MR2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"i2ref_k");
          _SFD_SET_DATA_PROPS(1,2,0,1,"up_beta");
          _SFD_SET_DATA_PROPS(2,1,1,0,"i2_k");
          _SFD_SET_DATA_PROPS(3,1,1,0,"vc_k");
          _SFD_SET_DATA_PROPS(4,1,1,0,"flag");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t");
          _SFD_SET_DATA_PROPS(6,2,0,1,"theta_beta");
          _SFD_SET_DATA_PROPS(7,2,0,1,"m");
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
        _SFD_CV_INIT_EML(0,1,1,26,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6449);
        _SFD_CV_INIT_EML_IF(0,1,0,1205,1224,-1,1897);
        _SFD_CV_INIT_EML_IF(0,1,1,1919,1938,-1,1986);
        _SFD_CV_INIT_EML_IF(0,1,2,2010,2031,-1,2081);
        _SFD_CV_INIT_EML_IF(0,1,3,2105,2126,-1,2176);
        _SFD_CV_INIT_EML_IF(0,1,4,2200,2221,-1,2271);
        _SFD_CV_INIT_EML_IF(0,1,5,2293,2312,-1,2360);
        _SFD_CV_INIT_EML_IF(0,1,6,2382,2401,-1,2449);
        _SFD_CV_INIT_EML_IF(0,1,7,2471,2490,-1,2538);
        _SFD_CV_INIT_EML_IF(0,1,8,2560,2579,-1,2598);
        _SFD_CV_INIT_EML_IF(0,1,9,2620,2639,-1,2658);
        _SFD_CV_INIT_EML_IF(0,1,10,2680,2699,-1,2718);
        _SFD_CV_INIT_EML_IF(0,1,11,2742,2763,-1,2784);
        _SFD_CV_INIT_EML_IF(0,1,12,2808,2829,-1,2850);
        _SFD_CV_INIT_EML_IF(0,1,13,2874,2895,-1,2916);
        _SFD_CV_INIT_EML_IF(0,1,14,2936,2953,-1,2970);
        _SFD_CV_INIT_EML_IF(0,1,15,2990,3007,-1,3024);
        _SFD_CV_INIT_EML_IF(0,1,16,3044,3061,-1,3078);
        _SFD_CV_INIT_EML_IF(0,1,17,3098,3115,-1,3136);
        _SFD_CV_INIT_EML_IF(0,1,18,3153,3167,-1,3181);
        _SFD_CV_INIT_EML_IF(0,1,19,3202,3220,-1,3238);
        _SFD_CV_INIT_EML_IF(0,1,20,3258,3275,-1,3292);
        _SFD_CV_INIT_EML_IF(0,1,21,3312,3329,-1,3346);
        _SFD_CV_INIT_EML_IF(0,1,22,3362,3375,-1,4549);
        _SFD_CV_INIT_EML_IF(0,1,23,4569,4586,-1,4636);
        _SFD_CV_INIT_EML_IF(0,1,24,5277,5287,5376,5468);
        _SFD_CV_INIT_EML_IF(0,1,25,5832,5842,5950,6069);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)c3_y_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_ab_sf_marshallOut,(MexInFcnForType)
            c3_ab_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_sf_marshallOut,(MexInFcnForType)c3_y_sf_marshallIn);

        {
          real_T *c3_i2ref_k;
          real_T *c3_up_beta;
          real_T *c3_i2_k;
          real_T *c3_vc_k;
          real_T *c3_flag;
          real_T *c3_t;
          real_T *c3_m;
          real_T (*c3_theta_beta)[6];
          c3_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_theta_beta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            2);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_up_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_i2ref_k);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_up_beta);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_i2_k);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_vc_k);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_flag);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(6U, *c3_theta_beta);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_vC_3ph_MR2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "0VKE0Y6T0nKqoANTiqu15C";
}

static void sf_opaque_initialize_c3_vC_3ph_MR2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_vC_3ph_MR2(void *chartInstanceVar)
{
  enable_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_vC_3ph_MR2(void *chartInstanceVar)
{
  disable_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_vC_3ph_MR2(void *chartInstanceVar)
{
  sf_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_vC_3ph_MR2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_vC_3ph_MR2
    ((SFc3_vC_3ph_MR2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_vC_3ph_MR2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_vC_3ph_MR2(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_vC_3ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_vC_3ph_MR2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_vC_3ph_MR2(S);
}

static void sf_opaque_set_sim_state_c3_vC_3ph_MR2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_vC_3ph_MR2(S, st);
}

static void sf_opaque_terminate_c3_vC_3ph_MR2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_vC_3ph_MR2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_vC_3ph_MR2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_vC_3ph_MR2((SFc3_vC_3ph_MR2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_vC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vC_3ph_MR2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2802527667U));
  ssSetChecksum1(S,(665987887U));
  ssSetChecksum2(S,(1936442399U));
  ssSetChecksum3(S,(1955877507U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_vC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_vC_3ph_MR2(SimStruct *S)
{
  SFc3_vC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc3_vC_3ph_MR2InstanceStruct *)malloc(sizeof
    (SFc3_vC_3ph_MR2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_vC_3ph_MR2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_vC_3ph_MR2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_vC_3ph_MR2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_vC_3ph_MR2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_vC_3ph_MR2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_vC_3ph_MR2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_vC_3ph_MR2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_vC_3ph_MR2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_vC_3ph_MR2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_vC_3ph_MR2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_vC_3ph_MR2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_vC_3ph_MR2;
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

void c3_vC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_vC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_vC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_vC_3ph_MR2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_vC_3ph_MR2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
