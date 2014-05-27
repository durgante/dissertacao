/* Include files */

#include "blascompat32.h"
#include "iC_3ph_MR2_sfun.h"
#include "c6_iC_3ph_MR2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "iC_3ph_MR2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[77] = { "L1ideal", "L2ideal",
  "Lgideal", "Cideal", "R1ideal", "R2ideal", "Rgideal", "errL1", "errL2",
  "errLg", "errC", "errR1", "errR2", "errRg", "deltaL1", "deltaL2", "deltaLg",
  "deltaC", "deltaR1", "deltaR2", "deltaRg", "L1", "L2", "C", "R1", "R2", "Ts",
  "w", "kp", "Kp", "p1", "p2", "km", "gamaD", "gama", "delta0", "u_k", "eta_k",
  "i2m_k", "e1_k", "v_k", "q_k", "e2_k", "ea_k", "m2_k", "nargin", "nargout",
  "i2ref_k", "i2_k", "ic_k", "flag", "t", "up_0", "theta_O", "theta_k",
  "omega_k", "omega_k_1", "omega_k_2", "omega_k_3", "eta_k_1", "eta_k_2",
  "eta_k_3", "i2m_k_1", "i2m_k_2", "i2m_k_3", "i2ref_k_1", "i2ref_k_2",
  "i2ref_k_3", "v_k_1", "v_k_2", "v_k_3", "rho_k", "m2", "u_k_1", "u_k_2", "P",
  "gama2" };

/* Function Declarations */
static void initialize_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initialize_params_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void enable_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void disable_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *
  chartInstance);
static void set_sim_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void sf_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void c6_chartstep_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void initSimStructsc6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_gama2, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_P, const char_T *c6_identifier, real_T c6_y[36]);
static void c6_d_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[36]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_e_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_u_k_2, const char_T *c6_identifier);
static real_T c6_f_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_g_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_u_k_1, const char_T *c6_identifier);
static real_T c6_h_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_i_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_m2, const char_T *c6_identifier);
static real_T c6_j_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_k_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_rho_k, const char_T *c6_identifier);
static real_T c6_l_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_m_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_3, const char_T *c6_identifier);
static real_T c6_n_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_o_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_2, const char_T *c6_identifier);
static real_T c6_p_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_q_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_1, const char_T *c6_identifier);
static real_T c6_r_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_s_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_3, const char_T *c6_identifier);
static real_T c6_t_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_u_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_2, const char_T *c6_identifier);
static real_T c6_v_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_w_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_1, const char_T *c6_identifier);
static real_T c6_x_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_m_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_y_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2m_k_3, const char_T *c6_identifier);
static real_T c6_ab_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_n_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_bb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_i2m_k_2, const char_T *c6_identifier);
static real_T c6_cb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_o_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_db_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_i2m_k_1, const char_T *c6_identifier);
static real_T c6_eb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_p_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_fb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_3, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_gb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_q_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_hb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_2, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_ib_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_r_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_jb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_1, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_kb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_s_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_lb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_3, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_mb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_t_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_nb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_2, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_ob_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_u_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_pb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_1, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_qb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_v_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_rb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_sb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_w_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_tb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_theta_k, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_ub_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_x_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_vb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_theta_O, const char_T *c6_identifier, real_T c6_y[6]);
static void c6_wb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6]);
static void c6_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_y_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_xb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_up_0, const char_T *c6_identifier);
static real_T c6_yb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[56]);
static real_T c6_sqrt(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T c6_x);
static void c6_eml_error(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void c6_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void c6_eml_int_forloop_overflow_check(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static real_T c6_mpower(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T
  c6_a);
static void c6_c_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static void c6_d_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);
static real_T c6_abs(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T c6_x);
static const mxArray *c6_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_ac_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_bc_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_iC_3ph_MR2, const char_T
  *c6_identifier);
static uint8_T c6_cc_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sqrt(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T *c6_x);
static void init_dsm_address_info(SFc6_iC_3ph_MR2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_theta_k_not_empty = FALSE;
  chartInstance->c6_omega_k_not_empty = FALSE;
  chartInstance->c6_omega_k_1_not_empty = FALSE;
  chartInstance->c6_omega_k_2_not_empty = FALSE;
  chartInstance->c6_omega_k_3_not_empty = FALSE;
  chartInstance->c6_eta_k_1_not_empty = FALSE;
  chartInstance->c6_eta_k_2_not_empty = FALSE;
  chartInstance->c6_eta_k_3_not_empty = FALSE;
  chartInstance->c6_i2m_k_1_not_empty = FALSE;
  chartInstance->c6_i2m_k_2_not_empty = FALSE;
  chartInstance->c6_i2m_k_3_not_empty = FALSE;
  chartInstance->c6_i2ref_k_1_not_empty = FALSE;
  chartInstance->c6_i2ref_k_2_not_empty = FALSE;
  chartInstance->c6_i2ref_k_3_not_empty = FALSE;
  chartInstance->c6_v_k_1_not_empty = FALSE;
  chartInstance->c6_v_k_2_not_empty = FALSE;
  chartInstance->c6_v_k_3_not_empty = FALSE;
  chartInstance->c6_rho_k_not_empty = FALSE;
  chartInstance->c6_m2_not_empty = FALSE;
  chartInstance->c6_u_k_1_not_empty = FALSE;
  chartInstance->c6_u_k_2_not_empty = FALSE;
  chartInstance->c6_P_not_empty = FALSE;
  chartInstance->c6_gama2_not_empty = FALSE;
  chartInstance->c6_is_active_c6_iC_3ph_MR2 = 0U;
}

static void initialize_params_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void enable_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *
  chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[6];
  const mxArray *c6_b_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  int32_T c6_i1;
  real_T c6_c_u[36];
  const mxArray *c6_d_y = NULL;
  int32_T c6_i2;
  real_T c6_d_u[6];
  const mxArray *c6_e_y = NULL;
  int32_T c6_i3;
  real_T c6_e_u[6];
  const mxArray *c6_f_y = NULL;
  int32_T c6_i4;
  real_T c6_f_u[6];
  const mxArray *c6_g_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  real_T c6_c_hoistedGlobal;
  real_T c6_h_u;
  const mxArray *c6_i_y = NULL;
  real_T c6_d_hoistedGlobal;
  real_T c6_i_u;
  const mxArray *c6_j_y = NULL;
  real_T c6_e_hoistedGlobal;
  real_T c6_j_u;
  const mxArray *c6_k_y = NULL;
  real_T c6_f_hoistedGlobal;
  real_T c6_k_u;
  const mxArray *c6_l_y = NULL;
  real_T c6_g_hoistedGlobal;
  real_T c6_l_u;
  const mxArray *c6_m_y = NULL;
  real_T c6_h_hoistedGlobal;
  real_T c6_m_u;
  const mxArray *c6_n_y = NULL;
  real_T c6_i_hoistedGlobal;
  real_T c6_n_u;
  const mxArray *c6_o_y = NULL;
  int32_T c6_i5;
  real_T c6_o_u[6];
  const mxArray *c6_p_y = NULL;
  int32_T c6_i6;
  real_T c6_p_u[6];
  const mxArray *c6_q_y = NULL;
  int32_T c6_i7;
  real_T c6_q_u[6];
  const mxArray *c6_r_y = NULL;
  int32_T c6_i8;
  real_T c6_r_u[6];
  const mxArray *c6_s_y = NULL;
  real_T c6_j_hoistedGlobal;
  real_T c6_s_u;
  const mxArray *c6_t_y = NULL;
  int32_T c6_i9;
  real_T c6_t_u[6];
  const mxArray *c6_u_y = NULL;
  real_T c6_k_hoistedGlobal;
  real_T c6_u_u;
  const mxArray *c6_v_y = NULL;
  real_T c6_l_hoistedGlobal;
  real_T c6_v_u;
  const mxArray *c6_w_y = NULL;
  real_T c6_m_hoistedGlobal;
  real_T c6_w_u;
  const mxArray *c6_x_y = NULL;
  real_T c6_n_hoistedGlobal;
  real_T c6_x_u;
  const mxArray *c6_y_y = NULL;
  real_T c6_o_hoistedGlobal;
  real_T c6_y_u;
  const mxArray *c6_ab_y = NULL;
  uint8_T c6_p_hoistedGlobal;
  uint8_T c6_ab_u;
  const mxArray *c6_bb_y = NULL;
  real_T *c6_up_0;
  real_T (*c6_theta_O)[6];
  c6_theta_O = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_up_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(26), FALSE);
  for (c6_i0 = 0; c6_i0 < 6; c6_i0++) {
    c6_u[c6_i0] = (*c6_theta_O)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = *c6_up_0;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  for (c6_i1 = 0; c6_i1 < 36; c6_i1++) {
    c6_c_u[c6_i1] = chartInstance->c6_P[c6_i1];
  }

  c6_d_y = NULL;
  if (!chartInstance->c6_P_not_empty) {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 2, 6, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 2, c6_d_y);
  for (c6_i2 = 0; c6_i2 < 6; c6_i2++) {
    c6_d_u[c6_i2] = chartInstance->c6_eta_k_1[c6_i2];
  }

  c6_e_y = NULL;
  if (!chartInstance->c6_eta_k_1_not_empty) {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_d_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 3, c6_e_y);
  for (c6_i3 = 0; c6_i3 < 6; c6_i3++) {
    c6_e_u[c6_i3] = chartInstance->c6_eta_k_2[c6_i3];
  }

  c6_f_y = NULL;
  if (!chartInstance->c6_eta_k_2_not_empty) {
    sf_mex_assign(&c6_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_e_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 4, c6_f_y);
  for (c6_i4 = 0; c6_i4 < 6; c6_i4++) {
    c6_f_u[c6_i4] = chartInstance->c6_eta_k_3[c6_i4];
  }

  c6_g_y = NULL;
  if (!chartInstance->c6_eta_k_3_not_empty) {
    sf_mex_assign(&c6_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_f_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_b_hoistedGlobal = chartInstance->c6_gama2;
  c6_g_u = c6_b_hoistedGlobal;
  c6_h_y = NULL;
  if (!chartInstance->c6_gama2_not_empty) {
    sf_mex_assign(&c6_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_c_hoistedGlobal = chartInstance->c6_i2m_k_1;
  c6_h_u = c6_c_hoistedGlobal;
  c6_i_y = NULL;
  if (!chartInstance->c6_i2m_k_1_not_empty) {
    sf_mex_assign(&c6_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_i_y, sf_mex_create("y", &c6_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 7, c6_i_y);
  c6_d_hoistedGlobal = chartInstance->c6_i2m_k_2;
  c6_i_u = c6_d_hoistedGlobal;
  c6_j_y = NULL;
  if (!chartInstance->c6_i2m_k_2_not_empty) {
    sf_mex_assign(&c6_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_j_y, sf_mex_create("y", &c6_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 8, c6_j_y);
  c6_e_hoistedGlobal = chartInstance->c6_i2m_k_3;
  c6_j_u = c6_e_hoistedGlobal;
  c6_k_y = NULL;
  if (!chartInstance->c6_i2m_k_3_not_empty) {
    sf_mex_assign(&c6_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_k_y, sf_mex_create("y", &c6_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 9, c6_k_y);
  c6_f_hoistedGlobal = chartInstance->c6_i2ref_k_1;
  c6_k_u = c6_f_hoistedGlobal;
  c6_l_y = NULL;
  if (!chartInstance->c6_i2ref_k_1_not_empty) {
    sf_mex_assign(&c6_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_l_y, sf_mex_create("y", &c6_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 10, c6_l_y);
  c6_g_hoistedGlobal = chartInstance->c6_i2ref_k_2;
  c6_l_u = c6_g_hoistedGlobal;
  c6_m_y = NULL;
  if (!chartInstance->c6_i2ref_k_2_not_empty) {
    sf_mex_assign(&c6_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_m_y, sf_mex_create("y", &c6_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 11, c6_m_y);
  c6_h_hoistedGlobal = chartInstance->c6_i2ref_k_3;
  c6_m_u = c6_h_hoistedGlobal;
  c6_n_y = NULL;
  if (!chartInstance->c6_i2ref_k_3_not_empty) {
    sf_mex_assign(&c6_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_n_y, sf_mex_create("y", &c6_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 12, c6_n_y);
  c6_i_hoistedGlobal = chartInstance->c6_m2;
  c6_n_u = c6_i_hoistedGlobal;
  c6_o_y = NULL;
  if (!chartInstance->c6_m2_not_empty) {
    sf_mex_assign(&c6_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_o_y, sf_mex_create("y", &c6_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 13, c6_o_y);
  for (c6_i5 = 0; c6_i5 < 6; c6_i5++) {
    c6_o_u[c6_i5] = chartInstance->c6_omega_k[c6_i5];
  }

  c6_p_y = NULL;
  if (!chartInstance->c6_omega_k_not_empty) {
    sf_mex_assign(&c6_p_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_p_y, sf_mex_create("y", c6_o_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 14, c6_p_y);
  for (c6_i6 = 0; c6_i6 < 6; c6_i6++) {
    c6_p_u[c6_i6] = chartInstance->c6_omega_k_1[c6_i6];
  }

  c6_q_y = NULL;
  if (!chartInstance->c6_omega_k_1_not_empty) {
    sf_mex_assign(&c6_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_q_y, sf_mex_create("y", c6_p_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 15, c6_q_y);
  for (c6_i7 = 0; c6_i7 < 6; c6_i7++) {
    c6_q_u[c6_i7] = chartInstance->c6_omega_k_2[c6_i7];
  }

  c6_r_y = NULL;
  if (!chartInstance->c6_omega_k_2_not_empty) {
    sf_mex_assign(&c6_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_r_y, sf_mex_create("y", c6_q_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 16, c6_r_y);
  for (c6_i8 = 0; c6_i8 < 6; c6_i8++) {
    c6_r_u[c6_i8] = chartInstance->c6_omega_k_3[c6_i8];
  }

  c6_s_y = NULL;
  if (!chartInstance->c6_omega_k_3_not_empty) {
    sf_mex_assign(&c6_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_s_y, sf_mex_create("y", c6_r_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 17, c6_s_y);
  c6_j_hoistedGlobal = chartInstance->c6_rho_k;
  c6_s_u = c6_j_hoistedGlobal;
  c6_t_y = NULL;
  if (!chartInstance->c6_rho_k_not_empty) {
    sf_mex_assign(&c6_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_t_y, sf_mex_create("y", &c6_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 18, c6_t_y);
  for (c6_i9 = 0; c6_i9 < 6; c6_i9++) {
    c6_t_u[c6_i9] = chartInstance->c6_theta_k[c6_i9];
  }

  c6_u_y = NULL;
  if (!chartInstance->c6_theta_k_not_empty) {
    sf_mex_assign(&c6_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_u_y, sf_mex_create("y", c6_t_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c6_y, 19, c6_u_y);
  c6_k_hoistedGlobal = chartInstance->c6_u_k_1;
  c6_u_u = c6_k_hoistedGlobal;
  c6_v_y = NULL;
  if (!chartInstance->c6_u_k_1_not_empty) {
    sf_mex_assign(&c6_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_v_y, sf_mex_create("y", &c6_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 20, c6_v_y);
  c6_l_hoistedGlobal = chartInstance->c6_u_k_2;
  c6_v_u = c6_l_hoistedGlobal;
  c6_w_y = NULL;
  if (!chartInstance->c6_u_k_2_not_empty) {
    sf_mex_assign(&c6_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_w_y, sf_mex_create("y", &c6_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 21, c6_w_y);
  c6_m_hoistedGlobal = chartInstance->c6_v_k_1;
  c6_w_u = c6_m_hoistedGlobal;
  c6_x_y = NULL;
  if (!chartInstance->c6_v_k_1_not_empty) {
    sf_mex_assign(&c6_x_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_x_y, sf_mex_create("y", &c6_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 22, c6_x_y);
  c6_n_hoistedGlobal = chartInstance->c6_v_k_2;
  c6_x_u = c6_n_hoistedGlobal;
  c6_y_y = NULL;
  if (!chartInstance->c6_v_k_2_not_empty) {
    sf_mex_assign(&c6_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_y_y, sf_mex_create("y", &c6_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 23, c6_y_y);
  c6_o_hoistedGlobal = chartInstance->c6_v_k_3;
  c6_y_u = c6_o_hoistedGlobal;
  c6_ab_y = NULL;
  if (!chartInstance->c6_v_k_3_not_empty) {
    sf_mex_assign(&c6_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c6_ab_y, sf_mex_create("y", &c6_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c6_y, 24, c6_ab_y);
  c6_p_hoistedGlobal = chartInstance->c6_is_active_c6_iC_3ph_MR2;
  c6_ab_u = c6_p_hoistedGlobal;
  c6_bb_y = NULL;
  sf_mex_assign(&c6_bb_y, sf_mex_create("y", &c6_ab_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 25, c6_bb_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[6];
  int32_T c6_i10;
  real_T c6_dv1[36];
  int32_T c6_i11;
  real_T c6_dv2[6];
  int32_T c6_i12;
  real_T c6_dv3[6];
  int32_T c6_i13;
  real_T c6_dv4[6];
  int32_T c6_i14;
  real_T c6_dv5[6];
  int32_T c6_i15;
  real_T c6_dv6[6];
  int32_T c6_i16;
  real_T c6_dv7[6];
  int32_T c6_i17;
  real_T c6_dv8[6];
  int32_T c6_i18;
  real_T c6_dv9[6];
  int32_T c6_i19;
  real_T *c6_up_0;
  real_T (*c6_theta_O)[6];
  c6_theta_O = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_up_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "theta_O", c6_dv0);
  for (c6_i10 = 0; c6_i10 < 6; c6_i10++) {
    (*c6_theta_O)[c6_i10] = c6_dv0[c6_i10];
  }

  *c6_up_0 = c6_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 1)), "up_0");
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)), "P",
                        c6_dv1);
  for (c6_i11 = 0; c6_i11 < 36; c6_i11++) {
    chartInstance->c6_P[c6_i11] = c6_dv1[c6_i11];
  }

  c6_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
    "eta_k_1", c6_dv2);
  for (c6_i12 = 0; c6_i12 < 6; c6_i12++) {
    chartInstance->c6_eta_k_1[c6_i12] = c6_dv2[c6_i12];
  }

  c6_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
    "eta_k_2", c6_dv3);
  for (c6_i13 = 0; c6_i13 < 6; c6_i13++) {
    chartInstance->c6_eta_k_2[c6_i13] = c6_dv3[c6_i13];
  }

  c6_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 5)),
    "eta_k_3", c6_dv4);
  for (c6_i14 = 0; c6_i14 < 6; c6_i14++) {
    chartInstance->c6_eta_k_3[c6_i14] = c6_dv4[c6_i14];
  }

  chartInstance->c6_gama2 = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 6)), "gama2");
  chartInstance->c6_i2m_k_1 = c6_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 7)), "i2m_k_1");
  chartInstance->c6_i2m_k_2 = c6_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 8)), "i2m_k_2");
  chartInstance->c6_i2m_k_3 = c6_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 9)), "i2m_k_3");
  chartInstance->c6_i2ref_k_1 = c6_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 10)), "i2ref_k_1");
  chartInstance->c6_i2ref_k_2 = c6_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 11)), "i2ref_k_2");
  chartInstance->c6_i2ref_k_3 = c6_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 12)), "i2ref_k_3");
  chartInstance->c6_m2 = c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 13)), "m2");
  c6_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 14)),
    "omega_k", c6_dv5);
  for (c6_i15 = 0; c6_i15 < 6; c6_i15++) {
    chartInstance->c6_omega_k[c6_i15] = c6_dv5[c6_i15];
  }

  c6_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 15)),
    "omega_k_1", c6_dv6);
  for (c6_i16 = 0; c6_i16 < 6; c6_i16++) {
    chartInstance->c6_omega_k_1[c6_i16] = c6_dv6[c6_i16];
  }

  c6_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 16)),
    "omega_k_2", c6_dv7);
  for (c6_i17 = 0; c6_i17 < 6; c6_i17++) {
    chartInstance->c6_omega_k_2[c6_i17] = c6_dv7[c6_i17];
  }

  c6_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 17)),
    "omega_k_3", c6_dv8);
  for (c6_i18 = 0; c6_i18 < 6; c6_i18++) {
    chartInstance->c6_omega_k_3[c6_i18] = c6_dv8[c6_i18];
  }

  chartInstance->c6_rho_k = c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 18)), "rho_k");
  c6_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 19)),
    "theta_k", c6_dv9);
  for (c6_i19 = 0; c6_i19 < 6; c6_i19++) {
    chartInstance->c6_theta_k[c6_i19] = c6_dv9[c6_i19];
  }

  chartInstance->c6_u_k_1 = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 20)), "u_k_1");
  chartInstance->c6_u_k_2 = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 21)), "u_k_2");
  chartInstance->c6_v_k_1 = c6_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 22)), "v_k_1");
  chartInstance->c6_v_k_2 = c6_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 23)), "v_k_2");
  chartInstance->c6_v_k_3 = c6_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 24)), "v_k_3");
  chartInstance->c6_is_active_c6_iC_3ph_MR2 = c6_bc_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 25)),
     "is_active_c6_iC_3ph_MR2");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_iC_3ph_MR2(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void sf_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
  int32_T c6_i20;
  real_T *c6_i2ref_k;
  real_T *c6_up_0;
  real_T *c6_i2_k;
  real_T *c6_ic_k;
  real_T *c6_flag;
  real_T *c6_t;
  real_T (*c6_theta_O)[6];
  c6_theta_O = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_ic_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_up_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_i2ref_k, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_up_0, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_i2_k, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_ic_k, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_flag, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_t, 5U);
  for (c6_i20 = 0; c6_i20 < 6; c6_i20++) {
    _SFD_DATA_RANGE_CHECK((*c6_theta_O)[c6_i20], 6U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_iC_3ph_MR2(chartInstance);
  sf_debug_check_for_state_inconsistency(_iC_3ph_MR2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_e_hoistedGlobal;
  real_T c6_i2ref_k;
  real_T c6_i2_k;
  real_T c6_ic_k;
  real_T c6_flag;
  real_T c6_t;
  uint32_T c6_debug_family_var_map[77];
  real_T c6_L1ideal;
  real_T c6_L2ideal;
  real_T c6_Lgideal;
  real_T c6_Cideal;
  real_T c6_R1ideal;
  real_T c6_R2ideal;
  real_T c6_Rgideal;
  real_T c6_errL1;
  real_T c6_errL2;
  real_T c6_errLg;
  real_T c6_errC;
  real_T c6_errR1;
  real_T c6_errR2;
  real_T c6_errRg;
  real_T c6_deltaL1;
  real_T c6_deltaL2;
  real_T c6_deltaLg;
  real_T c6_deltaC;
  real_T c6_deltaR1;
  real_T c6_deltaR2;
  real_T c6_deltaRg;
  real_T c6_L1;
  real_T c6_L2;
  real_T c6_C;
  real_T c6_R1;
  real_T c6_R2;
  real_T c6_Ts;
  real_T c6_w;
  real_T c6_kp;
  real_T c6_Kp;
  real_T c6_p1;
  real_T c6_p2;
  real_T c6_km;
  real_T c6_gamaD;
  real_T c6_gama;
  real_T c6_delta0;
  real_T c6_u_k;
  real_T c6_eta_k[6];
  real_T c6_i2m_k;
  real_T c6_e1_k;
  real_T c6_v_k;
  real_T c6_q_k;
  real_T c6_e2_k;
  real_T c6_ea_k;
  real_T c6_m2_k;
  real_T c6_nargin = 5.0;
  real_T c6_nargout = 2.0;
  real_T c6_up_0;
  real_T c6_theta_O[6];
  int32_T c6_i21;
  static real_T c6_dv10[6] = { -0.03, -0.36, -0.57, -0.01, 0.16, 0.02 };

  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  static real_T c6_dv11[36] = { 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098 };

  real_T c6_b;
  real_T c6_y;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_b_b;
  real_T c6_b_y;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_d_b;
  real_T c6_d_y;
  int32_T c6_i30;
  real_T c6_f_hoistedGlobal[6];
  int32_T c6_i31;
  real_T c6_g_hoistedGlobal[6];
  int32_T c6_i32;
  real_T c6_a[6];
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_e_b;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  real_T c6_h_hoistedGlobal[6];
  int32_T c6_i38;
  int32_T c6_i39;
  real_T c6_i_hoistedGlobal;
  real_T c6_f_b;
  real_T c6_e_y;
  real_T c6_j_hoistedGlobal;
  real_T c6_g_b;
  real_T c6_f_y;
  real_T c6_k_hoistedGlobal;
  real_T c6_h_b;
  real_T c6_g_y;
  real_T c6_l_hoistedGlobal;
  real_T c6_i_b;
  real_T c6_h_y;
  real_T c6_m_hoistedGlobal;
  real_T c6_j_b;
  real_T c6_i_y;
  real_T c6_n_hoistedGlobal;
  real_T c6_k_b;
  real_T c6_j_y;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  int32_T c6_c_k;
  int32_T c6_d_k;
  real_T c6_o_hoistedGlobal;
  real_T c6_b_a;
  real_T c6_l_b;
  real_T c6_k_y;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  real_T c6_l_y;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  real_T c6_m_y;
  int32_T c6_g_k;
  int32_T c6_h_k;
  int32_T c6_i49;
  real_T c6_p_hoistedGlobal[36];
  int32_T c6_i50;
  real_T c6_q_hoistedGlobal[36];
  int32_T c6_i51;
  int32_T c6_i52;
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  real_T c6_n_y[36];
  int32_T c6_i59;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  real_T c6_o_y[36];
  int32_T c6_i63;
  int32_T c6_i64;
  real_T c6_B;
  real_T c6_p_y;
  real_T c6_q_y;
  int32_T c6_i65;
  int32_T c6_i66;
  real_T c6_r_hoistedGlobal;
  real_T c6_s_hoistedGlobal;
  real_T c6_c_a;
  real_T c6_m_b;
  real_T c6_r_y;
  real_T c6_A;
  real_T c6_b_B;
  real_T c6_e_x;
  real_T c6_s_y;
  real_T c6_f_x;
  real_T c6_t_y;
  real_T c6_u_y;
  int32_T c6_i67;
  real_T c6_n_b;
  real_T c6_v_y;
  real_T c6_b_A;
  real_T c6_c_B;
  real_T c6_g_x;
  real_T c6_w_y;
  real_T c6_h_x;
  real_T c6_x_y;
  real_T c6_y_y;
  real_T c6_d_a;
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i70;
  int32_T c6_i71;
  real_T c6_t_hoistedGlobal;
  real_T c6_o_b;
  real_T c6_ab_y;
  real_T c6_e_a;
  real_T c6_p_b;
  real_T c6_bb_y;
  real_T c6_c_A;
  real_T c6_d_B;
  real_T c6_i_x;
  real_T c6_cb_y;
  real_T c6_j_x;
  real_T c6_db_y;
  real_T c6_eb_y;
  real_T c6_u_hoistedGlobal;
  real_T c6_q_b;
  real_T c6_fb_y;
  real_T c6_v_hoistedGlobal;
  real_T c6_r_b;
  real_T c6_gb_y;
  int32_T c6_i72;
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  real_T c6_s_b;
  real_T c6_hb_y;
  real_T c6_t_b;
  real_T c6_ib_y;
  int32_T c6_i76;
  real_T c6_u_b;
  real_T c6_jb_y;
  real_T c6_v_b;
  real_T c6_kb_y;
  int32_T c6_i77;
  int32_T c6_i78;
  int32_T c6_i79;
  int32_T c6_i80;
  real_T *c6_b_i2ref_k;
  real_T *c6_b_i2_k;
  real_T *c6_b_ic_k;
  real_T *c6_b_flag;
  real_T *c6_b_t;
  real_T *c6_b_up_0;
  real_T (*c6_b_theta_O)[6];
  c6_b_theta_O = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_ic_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_up_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_i2ref_k;
  c6_b_hoistedGlobal = *c6_b_i2_k;
  c6_c_hoistedGlobal = *c6_b_ic_k;
  c6_d_hoistedGlobal = *c6_b_flag;
  c6_e_hoistedGlobal = *c6_b_t;
  c6_i2ref_k = c6_hoistedGlobal;
  c6_i2_k = c6_b_hoistedGlobal;
  c6_ic_k = c6_c_hoistedGlobal;
  c6_flag = c6_d_hoistedGlobal;
  c6_t = c6_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 77U, 77U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_L1ideal, 0U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_L2ideal, 1U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Lgideal, 2U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Cideal, 3U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_R1ideal, 4U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_R2ideal, 5U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Rgideal, 6U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errL1, 7U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errL2, 8U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errLg, 9U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errC, 10U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errR1, 11U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errR2, 12U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_errRg, 13U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_deltaL1, 14U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_deltaL2, 15U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_deltaLg, 16U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_deltaC, 17U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_deltaR1, 18U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_deltaR2, 19U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_deltaRg, 20U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_L1, 21U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_L2, 22U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_C, 23U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_R1, 24U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_R2, 25U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_Ts, 26U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_w, 27U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_kp, 28U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Kp, 29U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_p1, 30U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_p2, 31U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_km, 32U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_gamaD, 33U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_gama, 34U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_delta0, 35U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_u_k, 36U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_eta_k, 37U, c6_x_sf_marshallOut,
    c6_x_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_i2m_k, 38U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_e1_k, 39U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_v_k, 40U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_q_k, 41U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_e2_k, 42U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_ea_k, 43U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_m2_k, 44U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 45U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 46U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_i2ref_k, 47U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_i2_k, 48U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_ic_k, 49U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_flag, 50U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_t, 51U, c6_y_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_up_0, 52U, c6_y_sf_marshallOut,
    c6_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_theta_O, 53U, c6_x_sf_marshallOut,
    c6_x_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_theta_k, 54U,
    c6_w_sf_marshallOut, c6_w_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_omega_k, 55U,
    c6_v_sf_marshallOut, c6_v_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_omega_k_1, 56U,
    c6_u_sf_marshallOut, c6_u_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_omega_k_2, 57U,
    c6_t_sf_marshallOut, c6_t_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_omega_k_3, 58U,
    c6_s_sf_marshallOut, c6_s_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_eta_k_1, 59U,
    c6_r_sf_marshallOut, c6_r_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_eta_k_2, 60U,
    c6_q_sf_marshallOut, c6_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_eta_k_3, 61U,
    c6_p_sf_marshallOut, c6_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2m_k_1, 62U,
    c6_o_sf_marshallOut, c6_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2m_k_2, 63U,
    c6_n_sf_marshallOut, c6_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2m_k_3, 64U,
    c6_m_sf_marshallOut, c6_m_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2ref_k_1, 65U,
    c6_l_sf_marshallOut, c6_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2ref_k_2, 66U,
    c6_k_sf_marshallOut, c6_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_i2ref_k_3, 67U,
    c6_j_sf_marshallOut, c6_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_v_k_1, 68U,
    c6_i_sf_marshallOut, c6_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_v_k_2, 69U,
    c6_h_sf_marshallOut, c6_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_v_k_3, 70U,
    c6_g_sf_marshallOut, c6_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_rho_k, 71U,
    c6_f_sf_marshallOut, c6_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_m2, 72U,
    c6_e_sf_marshallOut, c6_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_u_k_1, 73U,
    c6_d_sf_marshallOut, c6_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_u_k_2, 74U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c6_P, 75U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c6_gama2, 76U,
    c6_sf_marshallOut, c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_L1ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_L2ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_Lgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_Cideal = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_R1ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_R2ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_Rgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  c6_errL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  c6_errL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  c6_errLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 18);
  c6_errC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 19);
  c6_errR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 20);
  c6_errR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_errRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  c6_deltaL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 23);
  c6_deltaL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  c6_deltaLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  c6_deltaC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
  c6_deltaR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  c6_deltaR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
  c6_deltaRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 32);
  c6_L1 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 33);
  c6_L2 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 34);
  c6_C = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 35);
  c6_R1 = c6_R1ideal + c6_deltaR1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 36);
  c6_R2 = ((c6_R2ideal + c6_deltaR2) + c6_Rgideal) + c6_deltaRg;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 39);
  c6_Ts = 8.3333333333333331E-5;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 40);
  c6_w = 2.4999999999999996E+7;
  c6_b_sqrt(chartInstance, &c6_w);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 44);
  c6_kp = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 46);
  c6_Kp = 0.004780841242217;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 49);
  c6_p1 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 50);
  c6_p2 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 52);
  c6_km = 0.64000000000000012;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 55);
  c6_gamaD = 0.0098;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 56);
  c6_gama = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 58);
  c6_delta0 = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 66);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c6_theta_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 74);
    for (c6_i21 = 0; c6_i21 < 6; c6_i21++) {
      chartInstance->c6_theta_k[c6_i21] = c6_dv10[c6_i21];
    }

    chartInstance->c6_theta_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 78);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c6_omega_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 80);
    for (c6_i22 = 0; c6_i22 < 6; c6_i22++) {
      chartInstance->c6_omega_k[c6_i22] = 0.0;
    }

    chartInstance->c6_omega_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 84);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c6_omega_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 86);
    for (c6_i23 = 0; c6_i23 < 6; c6_i23++) {
      chartInstance->c6_omega_k_1[c6_i23] = 0.0;
    }

    chartInstance->c6_omega_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 90);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c6_omega_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 92);
    for (c6_i24 = 0; c6_i24 < 6; c6_i24++) {
      chartInstance->c6_omega_k_2[c6_i24] = 0.0;
    }

    chartInstance->c6_omega_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 96);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c6_omega_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 98);
    for (c6_i25 = 0; c6_i25 < 6; c6_i25++) {
      chartInstance->c6_omega_k_3[c6_i25] = 0.0;
    }

    chartInstance->c6_omega_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 102);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c6_eta_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 104);
    for (c6_i26 = 0; c6_i26 < 6; c6_i26++) {
      chartInstance->c6_eta_k_1[c6_i26] = 0.0;
    }

    chartInstance->c6_eta_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 108);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c6_eta_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 110);
    for (c6_i27 = 0; c6_i27 < 6; c6_i27++) {
      chartInstance->c6_eta_k_2[c6_i27] = 0.0;
    }

    chartInstance->c6_eta_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 114);
  if (CV_EML_IF(0, 1, 7, !chartInstance->c6_eta_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 116);
    for (c6_i28 = 0; c6_i28 < 6; c6_i28++) {
      chartInstance->c6_eta_k_3[c6_i28] = 0.0;
    }

    chartInstance->c6_eta_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 120);
  if (CV_EML_IF(0, 1, 8, !chartInstance->c6_i2m_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 121);
    chartInstance->c6_i2m_k_1 = 0.0;
    chartInstance->c6_i2m_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 125);
  if (CV_EML_IF(0, 1, 9, !chartInstance->c6_i2m_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 126);
    chartInstance->c6_i2m_k_2 = 0.0;
    chartInstance->c6_i2m_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 130U);
  if (CV_EML_IF(0, 1, 10, !chartInstance->c6_i2m_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 131U);
    chartInstance->c6_i2m_k_3 = 0.0;
    chartInstance->c6_i2m_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 135U);
  if (CV_EML_IF(0, 1, 11, !chartInstance->c6_i2ref_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 136U);
    chartInstance->c6_i2ref_k_1 = 0.0;
    chartInstance->c6_i2ref_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 140U);
  if (CV_EML_IF(0, 1, 12, !chartInstance->c6_i2ref_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 141U);
    chartInstance->c6_i2ref_k_2 = 0.0;
    chartInstance->c6_i2ref_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 145U);
  if (CV_EML_IF(0, 1, 13, !chartInstance->c6_i2ref_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 146U);
    chartInstance->c6_i2ref_k_3 = 0.0;
    chartInstance->c6_i2ref_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 150U);
  if (CV_EML_IF(0, 1, 14, !chartInstance->c6_v_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 151U);
    chartInstance->c6_v_k_1 = 0.0;
    chartInstance->c6_v_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 155U);
  if (CV_EML_IF(0, 1, 15, !chartInstance->c6_v_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 156U);
    chartInstance->c6_v_k_2 = 0.0;
    chartInstance->c6_v_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 160U);
  if (CV_EML_IF(0, 1, 16, !chartInstance->c6_v_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 161U);
    chartInstance->c6_v_k_3 = 0.0;
    chartInstance->c6_v_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 165U);
  if (CV_EML_IF(0, 1, 17, !chartInstance->c6_rho_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 166U);
    chartInstance->c6_rho_k = 0.0074700644409640615;
    chartInstance->c6_rho_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 170U);
  if (CV_EML_IF(0, 1, 18, !chartInstance->c6_m2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 171U);
    chartInstance->c6_m2 = 1.0;
    chartInstance->c6_m2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 175U);
  if (CV_EML_IF(0, 1, 19, !chartInstance->c6_u_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 176U);
    chartInstance->c6_u_k_1 = 0.0;
    chartInstance->c6_u_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 180U);
  if (CV_EML_IF(0, 1, 20, !chartInstance->c6_u_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 181U);
    chartInstance->c6_u_k_2 = 0.0;
    chartInstance->c6_u_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 185U);
  if (CV_EML_IF(0, 1, 21, !chartInstance->c6_P_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 197U);
    for (c6_i29 = 0; c6_i29 < 36; c6_i29++) {
      chartInstance->c6_P[c6_i29] = c6_dv11[c6_i29];
    }

    chartInstance->c6_P_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 201U);
  if (CV_EML_IF(0, 1, 22, !chartInstance->c6_gama2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 203U);
    chartInstance->c6_gama2 = c6_gama;
    chartInstance->c6_gama2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 236U);
  chartInstance->c6_omega_k[2] = c6_i2_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 237U);
  chartInstance->c6_omega_k[3] = c6_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 253U);
  c6_b = c6_t;
  c6_y = 376.99111843077515 * c6_b;
  c6_x = c6_y;
  c6_b_x = c6_x;
  c6_b_x = muDoubleScalarSin(c6_b_x);
  c6_b_b = c6_b_x;
  c6_b_y = 311.0 * c6_b_b;
  chartInstance->c6_omega_k[4] = c6_b_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 254U);
  c6_c_b = c6_t;
  c6_c_y = 376.99111843077515 * c6_c_b;
  c6_c_x = c6_c_y;
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarCos(c6_d_x);
  c6_d_b = c6_d_x;
  c6_d_y = 311.0 * c6_d_b;
  chartInstance->c6_omega_k[5] = c6_d_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 256);
  for (c6_i30 = 0; c6_i30 < 6; c6_i30++) {
    c6_f_hoistedGlobal[c6_i30] = chartInstance->c6_theta_k[c6_i30];
  }

  for (c6_i31 = 0; c6_i31 < 6; c6_i31++) {
    c6_g_hoistedGlobal[c6_i31] = chartInstance->c6_omega_k[c6_i31];
  }

  for (c6_i32 = 0; c6_i32 < 6; c6_i32++) {
    c6_a[c6_i32] = c6_f_hoistedGlobal[c6_i32];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  c6_u_k = 0.0;
  c6_eml_int_forloop_overflow_check(chartInstance);
  for (c6_k = 1; c6_k < 7; c6_k++) {
    c6_b_k = c6_k;
    c6_u_k += c6_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_b_k), 1, 6, 1, 0) - 1] *
      c6_g_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 260);
  c6_e_b = c6_u_k - c6_ic_k;
  c6_up_0 = 8.0 * c6_e_b;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 262);
  for (c6_i33 = 0; c6_i33 < 6; c6_i33++) {
    c6_f_hoistedGlobal[c6_i33] = chartInstance->c6_eta_k_1[c6_i33];
  }

  for (c6_i34 = 0; c6_i34 < 6; c6_i34++) {
    c6_f_hoistedGlobal[c6_i34] *= 0.4;
  }

  for (c6_i35 = 0; c6_i35 < 6; c6_i35++) {
    c6_g_hoistedGlobal[c6_i35] = chartInstance->c6_eta_k_2[c6_i35];
  }

  for (c6_i36 = 0; c6_i36 < 6; c6_i36++) {
    c6_g_hoistedGlobal[c6_i36] *= 0.040000000000000008;
  }

  for (c6_i37 = 0; c6_i37 < 6; c6_i37++) {
    c6_h_hoistedGlobal[c6_i37] = chartInstance->c6_omega_k_2[c6_i37];
  }

  for (c6_i38 = 0; c6_i38 < 6; c6_i38++) {
    c6_h_hoistedGlobal[c6_i38] *= 0.64000000000000012;
  }

  for (c6_i39 = 0; c6_i39 < 6; c6_i39++) {
    c6_eta_k[c6_i39] = (c6_f_hoistedGlobal[c6_i39] - c6_g_hoistedGlobal[c6_i39])
      + c6_h_hoistedGlobal[c6_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 264);
  c6_i_hoistedGlobal = chartInstance->c6_i2m_k_1;
  c6_f_b = c6_i_hoistedGlobal;
  c6_e_y = 0.4 * c6_f_b;
  c6_j_hoistedGlobal = chartInstance->c6_i2m_k_2;
  c6_g_b = c6_j_hoistedGlobal;
  c6_f_y = 0.040000000000000008 * c6_g_b;
  c6_k_hoistedGlobal = chartInstance->c6_i2ref_k_2;
  c6_h_b = c6_k_hoistedGlobal;
  c6_g_y = 0.64000000000000012 * c6_h_b;
  c6_i2m_k = (c6_e_y - c6_f_y) + c6_g_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 266);
  c6_e1_k = c6_i2_k - c6_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 268);
  c6_l_hoistedGlobal = chartInstance->c6_v_k_1;
  c6_i_b = c6_l_hoistedGlobal;
  c6_h_y = 0.4 * c6_i_b;
  c6_m_hoistedGlobal = chartInstance->c6_v_k_2;
  c6_j_b = c6_m_hoistedGlobal;
  c6_i_y = 0.040000000000000008 * c6_j_b;
  c6_n_hoistedGlobal = chartInstance->c6_u_k_2;
  c6_k_b = c6_n_hoistedGlobal;
  c6_j_y = 0.64000000000000012 * c6_k_b;
  c6_v_k = (c6_h_y - c6_i_y) + c6_j_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 270);
  for (c6_i40 = 0; c6_i40 < 6; c6_i40++) {
    c6_f_hoistedGlobal[c6_i40] = chartInstance->c6_theta_k[c6_i40];
  }

  for (c6_i41 = 0; c6_i41 < 6; c6_i41++) {
    c6_a[c6_i41] = c6_f_hoistedGlobal[c6_i41];
  }

  for (c6_i42 = 0; c6_i42 < 6; c6_i42++) {
    c6_h_hoistedGlobal[c6_i42] = c6_eta_k[c6_i42];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  c6_q_k = 0.0;
  c6_eml_int_forloop_overflow_check(chartInstance);
  for (c6_c_k = 1; c6_c_k < 7; c6_c_k++) {
    c6_d_k = c6_c_k;
    c6_q_k += c6_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_d_k), 1, 6, 1, 0) - 1] *
      c6_h_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_d_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 272);
  c6_e2_k = -c6_v_k + c6_q_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 274);
  c6_o_hoistedGlobal = chartInstance->c6_rho_k;
  c6_b_a = c6_o_hoistedGlobal;
  c6_l_b = c6_e2_k;
  c6_k_y = c6_b_a * c6_l_b;
  c6_ea_k = c6_e1_k + c6_k_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 276);
  if (CV_EML_IF(0, 1, 23, c6_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 277);
    for (c6_i43 = 0; c6_i43 < 6; c6_i43++) {
      c6_a[c6_i43] = c6_eta_k[c6_i43];
    }

    for (c6_i44 = 0; c6_i44 < 6; c6_i44++) {
      c6_a[c6_i44] *= 0.1;
    }

    for (c6_i45 = 0; c6_i45 < 6; c6_i45++) {
      c6_h_hoistedGlobal[c6_i45] = c6_eta_k[c6_i45];
    }

    c6_b_eml_scalar_eg(chartInstance);
    c6_b_eml_scalar_eg(chartInstance);
    c6_l_y = 0.0;
    c6_eml_int_forloop_overflow_check(chartInstance);
    for (c6_e_k = 1; c6_e_k < 7; c6_e_k++) {
      c6_f_k = c6_e_k;
      c6_l_y += c6_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c6_f_k), 1, 6, 1, 0) - 1] *
        c6_h_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_f_k), 1, 6, 1, 0) - 1];
    }

    c6_m2_k = (c6_l_y + c6_mpower(chartInstance, c6_e2_k)) +
      chartInstance->c6_m2;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 279);
    for (c6_i46 = 0; c6_i46 < 6; c6_i46++) {
      c6_a[c6_i46] = c6_eta_k[c6_i46];
    }

    for (c6_i47 = 0; c6_i47 < 6; c6_i47++) {
      c6_a[c6_i47] *= 0.01;
    }

    for (c6_i48 = 0; c6_i48 < 6; c6_i48++) {
      c6_h_hoistedGlobal[c6_i48] = c6_eta_k[c6_i48];
    }

    c6_b_eml_scalar_eg(chartInstance);
    c6_b_eml_scalar_eg(chartInstance);
    c6_m_y = 0.0;
    c6_eml_int_forloop_overflow_check(chartInstance);
    for (c6_g_k = 1; c6_g_k < 7; c6_g_k++) {
      c6_h_k = c6_g_k;
      c6_m_y += c6_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c6_h_k), 1, 6, 1, 0) - 1] *
        c6_h_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_h_k), 1, 6, 1, 0) - 1];
    }

    c6_m2_k = (c6_m_y + c6_mpower(chartInstance, c6_e2_k)) +
      chartInstance->c6_m2;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 283);
  for (c6_i49 = 0; c6_i49 < 36; c6_i49++) {
    c6_p_hoistedGlobal[c6_i49] = chartInstance->c6_P[c6_i49];
  }

  for (c6_i50 = 0; c6_i50 < 36; c6_i50++) {
    c6_q_hoistedGlobal[c6_i50] = chartInstance->c6_P[c6_i50];
  }

  for (c6_i51 = 0; c6_i51 < 6; c6_i51++) {
    c6_h_hoistedGlobal[c6_i51] = c6_eta_k[c6_i51];
  }

  c6_c_eml_scalar_eg(chartInstance);
  c6_c_eml_scalar_eg(chartInstance);
  for (c6_i52 = 0; c6_i52 < 6; c6_i52++) {
    c6_g_hoistedGlobal[c6_i52] = 0.0;
    c6_i53 = 0;
    for (c6_i54 = 0; c6_i54 < 6; c6_i54++) {
      c6_g_hoistedGlobal[c6_i52] += c6_q_hoistedGlobal[c6_i53 + c6_i52] *
        c6_h_hoistedGlobal[c6_i54];
      c6_i53 += 6;
    }
  }

  for (c6_i55 = 0; c6_i55 < 6; c6_i55++) {
    c6_a[c6_i55] = c6_eta_k[c6_i55];
  }

  c6_i56 = 0;
  for (c6_i57 = 0; c6_i57 < 6; c6_i57++) {
    for (c6_i58 = 0; c6_i58 < 6; c6_i58++) {
      c6_n_y[c6_i58 + c6_i56] = c6_g_hoistedGlobal[c6_i58] * c6_a[c6_i57];
    }

    c6_i56 += 6;
  }

  for (c6_i59 = 0; c6_i59 < 36; c6_i59++) {
    c6_q_hoistedGlobal[c6_i59] = chartInstance->c6_P[c6_i59];
  }

  c6_d_eml_scalar_eg(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_i60 = 0; c6_i60 < 6; c6_i60++) {
    c6_i61 = 0;
    for (c6_i62 = 0; c6_i62 < 6; c6_i62++) {
      c6_o_y[c6_i61 + c6_i60] = 0.0;
      c6_i63 = 0;
      for (c6_i64 = 0; c6_i64 < 6; c6_i64++) {
        c6_o_y[c6_i61 + c6_i60] += c6_n_y[c6_i63 + c6_i60] *
          c6_q_hoistedGlobal[c6_i64 + c6_i61];
        c6_i63 += 6;
      }

      c6_i61 += 6;
    }
  }

  c6_B = c6_m2_k;
  c6_p_y = c6_B;
  c6_q_y = c6_p_y;
  for (c6_i65 = 0; c6_i65 < 36; c6_i65++) {
    c6_o_y[c6_i65] /= c6_q_y;
  }

  for (c6_i66 = 0; c6_i66 < 36; c6_i66++) {
    chartInstance->c6_P[c6_i66] = c6_p_hoistedGlobal[c6_i66] - c6_o_y[c6_i66];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 284);
  c6_r_hoistedGlobal = chartInstance->c6_gama2;
  c6_s_hoistedGlobal = chartInstance->c6_gama2;
  c6_c_a = c6_mpower(chartInstance, c6_s_hoistedGlobal);
  c6_m_b = c6_mpower(chartInstance, c6_e2_k);
  c6_r_y = c6_c_a * c6_m_b;
  c6_A = c6_r_y;
  c6_b_B = c6_mpower(chartInstance, c6_m2_k);
  c6_e_x = c6_A;
  c6_s_y = c6_b_B;
  c6_f_x = c6_e_x;
  c6_t_y = c6_s_y;
  c6_u_y = c6_f_x / c6_t_y;
  chartInstance->c6_gama2 = c6_r_hoistedGlobal - c6_u_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 292);
  for (c6_i67 = 0; c6_i67 < 6; c6_i67++) {
    c6_f_hoistedGlobal[c6_i67] = chartInstance->c6_theta_k[c6_i67];
  }

  c6_n_b = c6_ea_k;
  c6_v_y = 0.0098 * c6_n_b;
  c6_b_A = c6_v_y;
  c6_c_B = c6_m2_k;
  c6_g_x = c6_b_A;
  c6_w_y = c6_c_B;
  c6_h_x = c6_g_x;
  c6_x_y = c6_w_y;
  c6_y_y = c6_h_x / c6_x_y;
  c6_d_a = c6_y_y;
  for (c6_i68 = 0; c6_i68 < 6; c6_i68++) {
    c6_h_hoistedGlobal[c6_i68] = c6_eta_k[c6_i68];
  }

  for (c6_i69 = 0; c6_i69 < 6; c6_i69++) {
    c6_h_hoistedGlobal[c6_i69] *= c6_d_a;
  }

  for (c6_i70 = 0; c6_i70 < 6; c6_i70++) {
    chartInstance->c6_theta_k[c6_i70] = c6_f_hoistedGlobal[c6_i70] -
      c6_h_hoistedGlobal[c6_i70];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 294);
  for (c6_i71 = 0; c6_i71 < 6; c6_i71++) {
    c6_theta_O[c6_i71] = chartInstance->c6_theta_k[c6_i71];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 297);
  c6_t_hoistedGlobal = chartInstance->c6_rho_k;
  c6_o_b = c6_ea_k;
  c6_ab_y = 0.99 * c6_o_b;
  c6_e_a = c6_ab_y;
  c6_p_b = c6_e2_k;
  c6_bb_y = c6_e_a * c6_p_b;
  c6_c_A = c6_bb_y;
  c6_d_B = c6_m2_k;
  c6_i_x = c6_c_A;
  c6_cb_y = c6_d_B;
  c6_j_x = c6_i_x;
  c6_db_y = c6_cb_y;
  c6_eb_y = c6_j_x / c6_db_y;
  chartInstance->c6_rho_k = c6_t_hoistedGlobal - c6_eb_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 299);
  if (CV_EML_IF(0, 1, 24, c6_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 300);
    c6_u_hoistedGlobal = chartInstance->c6_m2;
    c6_q_b = c6_u_hoistedGlobal - 1.0;
    c6_fb_y = 0.8 * c6_q_b;
    chartInstance->c6_m2 = ((c6_fb_y + c6_abs(chartInstance, c6_u_k)) + c6_abs
      (chartInstance, c6_i2_k)) + 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 302);
    c6_v_hoistedGlobal = chartInstance->c6_m2;
    c6_r_b = c6_v_hoistedGlobal - 1.0;
    c6_gb_y = 0.8 * c6_r_b;
    chartInstance->c6_m2 = ((c6_gb_y + c6_abs(chartInstance, c6_u_k)) + c6_abs
      (chartInstance, c6_i2_k)) + 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 305);
  for (c6_i72 = 0; c6_i72 < 6; c6_i72++) {
    chartInstance->c6_omega_k_3[c6_i72] = chartInstance->c6_omega_k_2[c6_i72];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 306);
  for (c6_i73 = 0; c6_i73 < 6; c6_i73++) {
    chartInstance->c6_omega_k_2[c6_i73] = chartInstance->c6_omega_k_1[c6_i73];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 307);
  for (c6_i74 = 0; c6_i74 < 6; c6_i74++) {
    chartInstance->c6_omega_k_1[c6_i74] = chartInstance->c6_omega_k[c6_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 309);
  for (c6_i75 = 0; c6_i75 < 6; c6_i75++) {
    c6_f_hoistedGlobal[c6_i75] = chartInstance->c6_omega_k[c6_i75];
  }

  c6_s_b = c6_f_hoistedGlobal[0];
  c6_hb_y = 0.0 * c6_s_b;
  c6_t_b = c6_u_k;
  c6_ib_y = c6_t_b;
  chartInstance->c6_omega_k[0] = c6_hb_y + c6_ib_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 310);
  for (c6_i76 = 0; c6_i76 < 6; c6_i76++) {
    c6_f_hoistedGlobal[c6_i76] = chartInstance->c6_omega_k[c6_i76];
  }

  c6_u_b = c6_f_hoistedGlobal[1];
  c6_jb_y = 0.0 * c6_u_b;
  c6_v_b = c6_i2_k;
  c6_kb_y = c6_v_b;
  chartInstance->c6_omega_k[1] = c6_jb_y + c6_kb_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 312);
  for (c6_i77 = 0; c6_i77 < 6; c6_i77++) {
    chartInstance->c6_eta_k_3[c6_i77] = chartInstance->c6_eta_k_2[c6_i77];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 313);
  for (c6_i78 = 0; c6_i78 < 6; c6_i78++) {
    chartInstance->c6_eta_k_2[c6_i78] = chartInstance->c6_eta_k_1[c6_i78];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 314);
  for (c6_i79 = 0; c6_i79 < 6; c6_i79++) {
    chartInstance->c6_eta_k_1[c6_i79] = c6_eta_k[c6_i79];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 316);
  chartInstance->c6_i2ref_k_3 = chartInstance->c6_i2ref_k_2;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 317);
  chartInstance->c6_i2ref_k_2 = chartInstance->c6_i2ref_k_1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 318);
  chartInstance->c6_i2ref_k_1 = c6_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 320);
  chartInstance->c6_i2m_k_3 = chartInstance->c6_i2m_k_2;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 321);
  chartInstance->c6_i2m_k_2 = chartInstance->c6_i2m_k_1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 322);
  chartInstance->c6_i2m_k_1 = c6_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 324);
  chartInstance->c6_v_k_3 = chartInstance->c6_v_k_2;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 325);
  chartInstance->c6_v_k_2 = chartInstance->c6_v_k_1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 326);
  chartInstance->c6_v_k_1 = c6_v_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 328);
  chartInstance->c6_u_k_2 = chartInstance->c6_u_k_1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 329);
  chartInstance->c6_u_k_1 = c6_u_k;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -329);
  sf_debug_symbol_scope_pop();
  *c6_b_up_0 = c6_up_0;
  for (c6_i80 = 0; c6_i80 < 6; c6_i80++) {
    (*c6_b_theta_O)[c6_i80] = c6_theta_O[c6_i80];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_iC_3ph_MR2(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_gama2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_gama2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_gama2), &c6_thisId);
  sf_mex_destroy(&c6_b_gama2);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_gama2_not_empty = FALSE;
  } else {
    chartInstance->c6_gama2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d0;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_gama2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_gama2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_gama2), &c6_thisId);
  sf_mex_destroy(&c6_b_gama2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i81;
  int32_T c6_i82;
  int32_T c6_i83;
  real_T c6_b_inData[36];
  int32_T c6_i84;
  int32_T c6_i85;
  int32_T c6_i86;
  real_T c6_u[36];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i81 = 0;
  for (c6_i82 = 0; c6_i82 < 6; c6_i82++) {
    for (c6_i83 = 0; c6_i83 < 6; c6_i83++) {
      c6_b_inData[c6_i83 + c6_i81] = (*(real_T (*)[36])c6_inData)[c6_i83 +
        c6_i81];
    }

    c6_i81 += 6;
  }

  c6_i84 = 0;
  for (c6_i85 = 0; c6_i85 < 6; c6_i85++) {
    for (c6_i86 = 0; c6_i86 < 6; c6_i86++) {
      c6_u[c6_i86 + c6_i84] = c6_b_inData[c6_i86 + c6_i84];
    }

    c6_i84 += 6;
  }

  c6_y = NULL;
  if (!chartInstance->c6_P_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_P, const char_T *c6_identifier, real_T c6_y[36])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_P), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_P);
}

static void c6_d_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[36])
{
  real_T c6_dv12[36];
  int32_T c6_i87;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_P_not_empty = FALSE;
  } else {
    chartInstance->c6_P_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv12, 1, 0, 0U, 1, 0U, 2, 6,
                  6);
    for (c6_i87 = 0; c6_i87 < 36; c6_i87++) {
      c6_y[c6_i87] = c6_dv12[c6_i87];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_P;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[36];
  int32_T c6_i88;
  int32_T c6_i89;
  int32_T c6_i90;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_P = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_P), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_P);
  c6_i88 = 0;
  for (c6_i89 = 0; c6_i89 < 6; c6_i89++) {
    for (c6_i90 = 0; c6_i90 < 6; c6_i90++) {
      (*(real_T (*)[36])c6_outData)[c6_i90 + c6_i88] = c6_y[c6_i90 + c6_i88];
    }

    c6_i88 += 6;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_u_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_e_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_u_k_2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_u_k_2), &c6_thisId);
  sf_mex_destroy(&c6_b_u_k_2);
  return c6_y;
}

static real_T c6_f_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d1;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_u_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_u_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d1, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d1;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_u_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_u_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_u_k_2), &c6_thisId);
  sf_mex_destroy(&c6_b_u_k_2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_u_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_g_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_u_k_1, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_u_k_1), &c6_thisId);
  sf_mex_destroy(&c6_b_u_k_1);
  return c6_y;
}

static real_T c6_h_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d2;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_u_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_u_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d2, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d2;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_u_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_u_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_u_k_1), &c6_thisId);
  sf_mex_destroy(&c6_b_u_k_1);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_m2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_i_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_m2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_m2), &c6_thisId);
  sf_mex_destroy(&c6_b_m2);
  return c6_y;
}

static real_T c6_j_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d3;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_m2_not_empty = FALSE;
  } else {
    chartInstance->c6_m2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d3, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d3;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_m2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_m2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_m2), &c6_thisId);
  sf_mex_destroy(&c6_b_m2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_rho_k_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_k_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_rho_k, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_rho_k), &c6_thisId);
  sf_mex_destroy(&c6_b_rho_k);
  return c6_y;
}

static real_T c6_l_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d4;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_rho_k_not_empty = FALSE;
  } else {
    chartInstance->c6_rho_k_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d4, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d4;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_rho_k;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_rho_k = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_rho_k), &c6_thisId);
  sf_mex_destroy(&c6_b_rho_k);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_v_k_3_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_m_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_3, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_3), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_3);
  return c6_y;
}

static real_T c6_n_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d5;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_v_k_3_not_empty = FALSE;
  } else {
    chartInstance->c6_v_k_3_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d5, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d5;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_v_k_3;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_v_k_3 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_3), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_3);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_v_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_o_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_2), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_2);
  return c6_y;
}

static real_T c6_p_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d6;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_v_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_v_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d6, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d6;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_v_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_v_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_2), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_v_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_q_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_v_k_1, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_1), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_1);
  return c6_y;
}

static real_T c6_r_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d7;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_v_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_v_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d7, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d7;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_v_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_v_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_v_k_1), &c6_thisId);
  sf_mex_destroy(&c6_b_v_k_1);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2ref_k_3_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_s_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_3, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_3),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_3);
  return c6_y;
}

static real_T c6_t_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d8;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2ref_k_3_not_empty = FALSE;
  } else {
    chartInstance->c6_i2ref_k_3_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d8, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d8;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2ref_k_3;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2ref_k_3 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_3),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_3);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2ref_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_u_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_2),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_2);
  return c6_y;
}

static real_T c6_v_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d9;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2ref_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_i2ref_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d9, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d9;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2ref_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2ref_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_2),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2ref_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_w_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2ref_k_1, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_1);
  return c6_y;
}

static real_T c6_x_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d10;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2ref_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_i2ref_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d10, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d10;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2ref_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2ref_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2ref_k_1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2ref_k_1);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_m_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2m_k_3_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_y_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_i2m_k_3, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_3),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_3);
  return c6_y;
}

static real_T c6_ab_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d11;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2m_k_3_not_empty = FALSE;
  } else {
    chartInstance->c6_i2m_k_3_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d11, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d11;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2m_k_3;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2m_k_3 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_3),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_3);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_n_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2m_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_bb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_i2m_k_2, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_2),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_2);
  return c6_y;
}

static real_T c6_cb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d12;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2m_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_i2m_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d12, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d12;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2m_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2m_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_2),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_o_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  if (!chartInstance->c6_i2m_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_db_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_i2m_k_1, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_1);
  return c6_y;
}

static real_T c6_eb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d13;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_i2m_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_i2m_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d13, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d13;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_i2m_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_i2m_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_i2m_k_1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_i2m_k_1);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_p_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i91;
  real_T c6_b_inData[6];
  int32_T c6_i92;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i91 = 0; c6_i91 < 6; c6_i91++) {
    c6_b_inData[c6_i91] = (*(real_T (*)[6])c6_inData)[c6_i91];
  }

  for (c6_i92 = 0; c6_i92 < 6; c6_i92++) {
    c6_u[c6_i92] = c6_b_inData[c6_i92];
  }

  c6_y = NULL;
  if (!chartInstance->c6_eta_k_3_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_fb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_3, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_3), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_3);
}

static void c6_gb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv13[6];
  int32_T c6_i93;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_eta_k_3_not_empty = FALSE;
  } else {
    chartInstance->c6_eta_k_3_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv13, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i93 = 0; c6_i93 < 6; c6_i93++) {
      c6_y[c6_i93] = c6_dv13[c6_i93];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_eta_k_3;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i94;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_eta_k_3 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_3), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_3);
  for (c6_i94 = 0; c6_i94 < 6; c6_i94++) {
    (*(real_T (*)[6])c6_outData)[c6_i94] = c6_y[c6_i94];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_q_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i95;
  real_T c6_b_inData[6];
  int32_T c6_i96;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i95 = 0; c6_i95 < 6; c6_i95++) {
    c6_b_inData[c6_i95] = (*(real_T (*)[6])c6_inData)[c6_i95];
  }

  for (c6_i96 = 0; c6_i96 < 6; c6_i96++) {
    c6_u[c6_i96] = c6_b_inData[c6_i96];
  }

  c6_y = NULL;
  if (!chartInstance->c6_eta_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_hb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_2, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_2), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_2);
}

static void c6_ib_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv14[6];
  int32_T c6_i97;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_eta_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_eta_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv14, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i97 = 0; c6_i97 < 6; c6_i97++) {
      c6_y[c6_i97] = c6_dv14[c6_i97];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_eta_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i98;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_eta_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_2), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_2);
  for (c6_i98 = 0; c6_i98 < 6; c6_i98++) {
    (*(real_T (*)[6])c6_outData)[c6_i98] = c6_y[c6_i98];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_r_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i99;
  real_T c6_b_inData[6];
  int32_T c6_i100;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i99 = 0; c6_i99 < 6; c6_i99++) {
    c6_b_inData[c6_i99] = (*(real_T (*)[6])c6_inData)[c6_i99];
  }

  for (c6_i100 = 0; c6_i100 < 6; c6_i100++) {
    c6_u[c6_i100] = c6_b_inData[c6_i100];
  }

  c6_y = NULL;
  if (!chartInstance->c6_eta_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_jb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_eta_k_1, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_1), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_1);
}

static void c6_kb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv15[6];
  int32_T c6_i101;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_eta_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_eta_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv15, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i101 = 0; c6_i101 < 6; c6_i101++) {
      c6_y[c6_i101] = c6_dv15[c6_i101];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_eta_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i102;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_eta_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_eta_k_1), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_eta_k_1);
  for (c6_i102 = 0; c6_i102 < 6; c6_i102++) {
    (*(real_T (*)[6])c6_outData)[c6_i102] = c6_y[c6_i102];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_s_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i103;
  real_T c6_b_inData[6];
  int32_T c6_i104;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i103 = 0; c6_i103 < 6; c6_i103++) {
    c6_b_inData[c6_i103] = (*(real_T (*)[6])c6_inData)[c6_i103];
  }

  for (c6_i104 = 0; c6_i104 < 6; c6_i104++) {
    c6_u[c6_i104] = c6_b_inData[c6_i104];
  }

  c6_y = NULL;
  if (!chartInstance->c6_omega_k_3_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_lb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_3, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_3), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_3);
}

static void c6_mb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv16[6];
  int32_T c6_i105;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_omega_k_3_not_empty = FALSE;
  } else {
    chartInstance->c6_omega_k_3_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv16, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i105 = 0; c6_i105 < 6; c6_i105++) {
      c6_y[c6_i105] = c6_dv16[c6_i105];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_omega_k_3;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i106;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_omega_k_3 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_3), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_3);
  for (c6_i106 = 0; c6_i106 < 6; c6_i106++) {
    (*(real_T (*)[6])c6_outData)[c6_i106] = c6_y[c6_i106];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_t_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i107;
  real_T c6_b_inData[6];
  int32_T c6_i108;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i107 = 0; c6_i107 < 6; c6_i107++) {
    c6_b_inData[c6_i107] = (*(real_T (*)[6])c6_inData)[c6_i107];
  }

  for (c6_i108 = 0; c6_i108 < 6; c6_i108++) {
    c6_u[c6_i108] = c6_b_inData[c6_i108];
  }

  c6_y = NULL;
  if (!chartInstance->c6_omega_k_2_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_nb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_2, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_2), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_2);
}

static void c6_ob_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv17[6];
  int32_T c6_i109;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_omega_k_2_not_empty = FALSE;
  } else {
    chartInstance->c6_omega_k_2_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv17, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i109 = 0; c6_i109 < 6; c6_i109++) {
      c6_y[c6_i109] = c6_dv17[c6_i109];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_omega_k_2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i110;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_omega_k_2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_2), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_2);
  for (c6_i110 = 0; c6_i110 < 6; c6_i110++) {
    (*(real_T (*)[6])c6_outData)[c6_i110] = c6_y[c6_i110];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_u_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i111;
  real_T c6_b_inData[6];
  int32_T c6_i112;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i111 = 0; c6_i111 < 6; c6_i111++) {
    c6_b_inData[c6_i111] = (*(real_T (*)[6])c6_inData)[c6_i111];
  }

  for (c6_i112 = 0; c6_i112 < 6; c6_i112++) {
    c6_u[c6_i112] = c6_b_inData[c6_i112];
  }

  c6_y = NULL;
  if (!chartInstance->c6_omega_k_1_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_pb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k_1, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_1), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_1);
}

static void c6_qb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv18[6];
  int32_T c6_i113;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_omega_k_1_not_empty = FALSE;
  } else {
    chartInstance->c6_omega_k_1_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv18, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i113 = 0; c6_i113 < 6; c6_i113++) {
      c6_y[c6_i113] = c6_dv18[c6_i113];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_omega_k_1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i114;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_omega_k_1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k_1), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k_1);
  for (c6_i114 = 0; c6_i114 < 6; c6_i114++) {
    (*(real_T (*)[6])c6_outData)[c6_i114] = c6_y[c6_i114];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_v_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i115;
  real_T c6_b_inData[6];
  int32_T c6_i116;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i115 = 0; c6_i115 < 6; c6_i115++) {
    c6_b_inData[c6_i115] = (*(real_T (*)[6])c6_inData)[c6_i115];
  }

  for (c6_i116 = 0; c6_i116 < 6; c6_i116++) {
    c6_u[c6_i116] = c6_b_inData[c6_i116];
  }

  c6_y = NULL;
  if (!chartInstance->c6_omega_k_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_rb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_omega_k, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k);
}

static void c6_sb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv19[6];
  int32_T c6_i117;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_omega_k_not_empty = FALSE;
  } else {
    chartInstance->c6_omega_k_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv19, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i117 = 0; c6_i117 < 6; c6_i117++) {
      c6_y[c6_i117] = c6_dv19[c6_i117];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_omega_k;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i118;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_omega_k = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_omega_k), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_omega_k);
  for (c6_i118 = 0; c6_i118 < 6; c6_i118++) {
    (*(real_T (*)[6])c6_outData)[c6_i118] = c6_y[c6_i118];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_w_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i119;
  real_T c6_b_inData[6];
  int32_T c6_i120;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i119 = 0; c6_i119 < 6; c6_i119++) {
    c6_b_inData[c6_i119] = (*(real_T (*)[6])c6_inData)[c6_i119];
  }

  for (c6_i120 = 0; c6_i120 < 6; c6_i120++) {
    c6_u[c6_i120] = c6_b_inData[c6_i120];
  }

  c6_y = NULL;
  if (!chartInstance->c6_theta_k_not_empty) {
    sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_tb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_b_theta_k, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_theta_k), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_theta_k);
}

static void c6_ub_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv20[6];
  int32_T c6_i121;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_theta_k_not_empty = FALSE;
  } else {
    chartInstance->c6_theta_k_not_empty = TRUE;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv20, 1, 0, 0U, 1, 0U, 1, 6);
    for (c6_i121 = 0; c6_i121 < 6; c6_i121++) {
      c6_y[c6_i121] = c6_dv20[c6_i121];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_theta_k;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i122;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_theta_k = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_theta_k), &c6_thisId,
    c6_y);
  sf_mex_destroy(&c6_b_theta_k);
  for (c6_i122 = 0; c6_i122 < 6; c6_i122++) {
    (*(real_T (*)[6])c6_outData)[c6_i122] = c6_y[c6_i122];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_x_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i123;
  real_T c6_b_inData[6];
  int32_T c6_i124;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i123 = 0; c6_i123 < 6; c6_i123++) {
    c6_b_inData[c6_i123] = (*(real_T (*)[6])c6_inData)[c6_i123];
  }

  for (c6_i124 = 0; c6_i124 < 6; c6_i124++) {
    c6_u[c6_i124] = c6_b_inData[c6_i124];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_vb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_theta_O, const char_T *c6_identifier, real_T c6_y[6])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta_O), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_theta_O);
}

static void c6_wb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[6])
{
  real_T c6_dv21[6];
  int32_T c6_i125;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv21, 1, 0, 0U, 1, 0U, 1, 6);
  for (c6_i125 = 0; c6_i125 < 6; c6_i125++) {
    c6_y[c6_i125] = c6_dv21[c6_i125];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_theta_O;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i126;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_theta_O = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta_O), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_theta_O);
  for (c6_i126 = 0; c6_i126 < 6; c6_i126++) {
    (*(real_T (*)[6])c6_outData)[c6_i126] = c6_y[c6_i126];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_y_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_xb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_up_0, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_up_0), &c6_thisId);
  sf_mex_destroy(&c6_up_0);
  return c6_y;
}

static real_T c6_yb_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d14;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d14, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d14;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_up_0;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_up_0 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_up_0), &c6_thisId);
  sf_mex_destroy(&c6_up_0);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_iC_3ph_MR2_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[56];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i127;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 56), FALSE);
  for (c6_i127 = 0; c6_i127 < 56; c6_i127++) {
    c6_r0 = &c6_info[c6_i127];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i127);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i127);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[56])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289523292U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "mrdivide";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[1].fileTimeLo = 1325127738U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 1319737166U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[2].name = "rdivide";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[2].fileTimeLo = 1286826044U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[3].name = "eml_div";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[3].fileTimeLo = 1313355010U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context = "";
  c6_info[4].name = "sqrt";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[4].fileTimeLo = 1286825952U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[5].name = "eml_error";
  c6_info[5].dominantType = "char";
  c6_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[5].fileTimeLo = 1305325200U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[6].name = "eml_scalar_sqrt";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c6_info[6].fileTimeLo = 1286825938U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context = "";
  c6_info[7].name = "eye";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m";
  c6_info[7].fileTimeLo = 1286825888U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[8].name = "eml_assert_valid_size_arg";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[8].fileTimeLo = 1286825894U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[9].name = "isinf";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[9].fileTimeLo = 1286825960U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c6_info[10].name = "mtimes";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[10].fileTimeLo = 1289523292U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[11].name = "eml_index_class";
  c6_info[11].dominantType = "";
  c6_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[11].fileTimeLo = 1286825978U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[12].name = "intmax";
  c6_info[12].dominantType = "char";
  c6_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[12].fileTimeLo = 1311262516U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[13].name = "eml_is_float_class";
  c6_info[13].dominantType = "char";
  c6_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[13].fileTimeLo = 1286825982U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[14].name = "min";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[14].fileTimeLo = 1311262518U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[15].name = "eml_min_or_max";
  c6_info[15].dominantType = "char";
  c6_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[15].fileTimeLo = 1303153412U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[16].name = "eml_scalar_eg";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[16].fileTimeLo = 1286825996U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[17].name = "eml_scalexp_alloc";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[17].fileTimeLo = 1286825996U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[18].name = "eml_index_class";
  c6_info[18].dominantType = "";
  c6_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[18].fileTimeLo = 1286825978U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c6_info[19].name = "eml_scalar_eg";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[19].fileTimeLo = 1286825996U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[20].name = "eml_index_class";
  c6_info[20].dominantType = "";
  c6_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[20].fileTimeLo = 1286825978U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[21].name = "eml_int_forloop_overflow_check";
  c6_info[21].dominantType = "";
  c6_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[21].fileTimeLo = 1311262516U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c6_info[22].name = "intmax";
  c6_info[22].dominantType = "char";
  c6_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[22].fileTimeLo = 1311262516U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context = "";
  c6_info[23].name = "sin";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[23].fileTimeLo = 1286825950U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[24].name = "eml_scalar_sin";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[24].fileTimeLo = 1286825936U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
  c6_info[25].context = "";
  c6_info[25].name = "cos";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[25].fileTimeLo = 1286825906U;
  c6_info[25].fileTimeHi = 0U;
  c6_info[25].mFileTimeLo = 0U;
  c6_info[25].mFileTimeHi = 0U;
  c6_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[26].name = "eml_scalar_cos";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[26].fileTimeLo = 1286825922U;
  c6_info[26].fileTimeHi = 0U;
  c6_info[26].mFileTimeLo = 0U;
  c6_info[26].mFileTimeHi = 0U;
  c6_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[27].name = "eml_index_class";
  c6_info[27].dominantType = "";
  c6_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[27].fileTimeLo = 1286825978U;
  c6_info[27].fileTimeHi = 0U;
  c6_info[27].mFileTimeLo = 0U;
  c6_info[27].mFileTimeHi = 0U;
  c6_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[28].name = "eml_scalar_eg";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[28].fileTimeLo = 1286825996U;
  c6_info[28].fileTimeHi = 0U;
  c6_info[28].mFileTimeLo = 0U;
  c6_info[28].mFileTimeHi = 0U;
  c6_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[29].name = "eml_xdotu";
  c6_info[29].dominantType = "int32";
  c6_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c6_info[29].fileTimeLo = 1299080372U;
  c6_info[29].fileTimeHi = 0U;
  c6_info[29].mFileTimeLo = 0U;
  c6_info[29].mFileTimeHi = 0U;
  c6_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c6_info[30].name = "eml_blas_inline";
  c6_info[30].dominantType = "";
  c6_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[30].fileTimeLo = 1299080368U;
  c6_info[30].fileTimeHi = 0U;
  c6_info[30].mFileTimeLo = 0U;
  c6_info[30].mFileTimeHi = 0U;
  c6_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c6_info[31].name = "eml_xdot";
  c6_info[31].dominantType = "int32";
  c6_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c6_info[31].fileTimeLo = 1299080372U;
  c6_info[31].fileTimeHi = 0U;
  c6_info[31].mFileTimeLo = 0U;
  c6_info[31].mFileTimeHi = 0U;
  c6_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c6_info[32].name = "eml_blas_inline";
  c6_info[32].dominantType = "";
  c6_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[32].fileTimeLo = 1299080368U;
  c6_info[32].fileTimeHi = 0U;
  c6_info[32].mFileTimeLo = 0U;
  c6_info[32].mFileTimeHi = 0U;
  c6_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c6_info[33].name = "eml_refblas_xdot";
  c6_info[33].dominantType = "int32";
  c6_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[33].fileTimeLo = 1299080372U;
  c6_info[33].fileTimeHi = 0U;
  c6_info[33].mFileTimeLo = 0U;
  c6_info[33].mFileTimeHi = 0U;
  c6_info[34].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[34].name = "eml_refblas_xdotx";
  c6_info[34].dominantType = "int32";
  c6_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[34].fileTimeLo = 1299080374U;
  c6_info[34].fileTimeHi = 0U;
  c6_info[34].mFileTimeLo = 0U;
  c6_info[34].mFileTimeHi = 0U;
  c6_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[35].name = "eml_scalar_eg";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[35].fileTimeLo = 1286825996U;
  c6_info[35].fileTimeHi = 0U;
  c6_info[35].mFileTimeLo = 0U;
  c6_info[35].mFileTimeHi = 0U;
  c6_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[36].name = "eml_index_class";
  c6_info[36].dominantType = "";
  c6_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[36].fileTimeLo = 1286825978U;
  c6_info[36].fileTimeHi = 0U;
  c6_info[36].mFileTimeLo = 0U;
  c6_info[36].mFileTimeHi = 0U;
  c6_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[37].name = "eml_index_minus";
  c6_info[37].dominantType = "int32";
  c6_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[37].fileTimeLo = 1286825978U;
  c6_info[37].fileTimeHi = 0U;
  c6_info[37].mFileTimeLo = 0U;
  c6_info[37].mFileTimeHi = 0U;
  c6_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[38].name = "eml_index_class";
  c6_info[38].dominantType = "";
  c6_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[38].fileTimeLo = 1286825978U;
  c6_info[38].fileTimeHi = 0U;
  c6_info[38].mFileTimeLo = 0U;
  c6_info[38].mFileTimeHi = 0U;
  c6_info[39].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[39].name = "eml_index_times";
  c6_info[39].dominantType = "int32";
  c6_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[39].fileTimeLo = 1286825980U;
  c6_info[39].fileTimeHi = 0U;
  c6_info[39].mFileTimeLo = 0U;
  c6_info[39].mFileTimeHi = 0U;
  c6_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[40].name = "eml_index_class";
  c6_info[40].dominantType = "";
  c6_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[40].fileTimeLo = 1286825978U;
  c6_info[40].fileTimeHi = 0U;
  c6_info[40].mFileTimeLo = 0U;
  c6_info[40].mFileTimeHi = 0U;
  c6_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[41].name = "eml_index_plus";
  c6_info[41].dominantType = "int32";
  c6_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[41].fileTimeLo = 1286825978U;
  c6_info[41].fileTimeHi = 0U;
  c6_info[41].mFileTimeLo = 0U;
  c6_info[41].mFileTimeHi = 0U;
  c6_info[42].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[42].name = "eml_index_class";
  c6_info[42].dominantType = "";
  c6_info[42].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[42].fileTimeLo = 1286825978U;
  c6_info[42].fileTimeHi = 0U;
  c6_info[42].mFileTimeLo = 0U;
  c6_info[42].mFileTimeHi = 0U;
  c6_info[43].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[43].name = "eml_int_forloop_overflow_check";
  c6_info[43].dominantType = "";
  c6_info[43].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[43].fileTimeLo = 1311262516U;
  c6_info[43].fileTimeHi = 0U;
  c6_info[43].mFileTimeLo = 0U;
  c6_info[43].mFileTimeHi = 0U;
  c6_info[44].context = "";
  c6_info[44].name = "mpower";
  c6_info[44].dominantType = "double";
  c6_info[44].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[44].fileTimeLo = 1286826042U;
  c6_info[44].fileTimeHi = 0U;
  c6_info[44].mFileTimeLo = 0U;
  c6_info[44].mFileTimeHi = 0U;
  c6_info[45].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[45].name = "power";
  c6_info[45].dominantType = "double";
  c6_info[45].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[45].fileTimeLo = 1307658440U;
  c6_info[45].fileTimeHi = 0U;
  c6_info[45].mFileTimeLo = 0U;
  c6_info[45].mFileTimeHi = 0U;
  c6_info[46].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[46].name = "eml_scalar_eg";
  c6_info[46].dominantType = "double";
  c6_info[46].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[46].fileTimeLo = 1286825996U;
  c6_info[46].fileTimeHi = 0U;
  c6_info[46].mFileTimeLo = 0U;
  c6_info[46].mFileTimeHi = 0U;
  c6_info[47].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[47].name = "eml_scalexp_alloc";
  c6_info[47].dominantType = "double";
  c6_info[47].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[47].fileTimeLo = 1286825996U;
  c6_info[47].fileTimeHi = 0U;
  c6_info[47].mFileTimeLo = 0U;
  c6_info[47].mFileTimeHi = 0U;
  c6_info[48].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[48].name = "eml_scalar_floor";
  c6_info[48].dominantType = "double";
  c6_info[48].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[48].fileTimeLo = 1286825926U;
  c6_info[48].fileTimeHi = 0U;
  c6_info[48].mFileTimeLo = 0U;
  c6_info[48].mFileTimeHi = 0U;
  c6_info[49].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[49].name = "eml_xgemm";
  c6_info[49].dominantType = "int32";
  c6_info[49].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[49].fileTimeLo = 1299080372U;
  c6_info[49].fileTimeHi = 0U;
  c6_info[49].mFileTimeLo = 0U;
  c6_info[49].mFileTimeHi = 0U;
  c6_info[50].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[50].name = "eml_blas_inline";
  c6_info[50].dominantType = "";
  c6_info[50].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[50].fileTimeLo = 1299080368U;
  c6_info[50].fileTimeHi = 0U;
  c6_info[50].mFileTimeLo = 0U;
  c6_info[50].mFileTimeHi = 0U;
  c6_info[51].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[51].name = "mtimes";
  c6_info[51].dominantType = "double";
  c6_info[51].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[51].fileTimeLo = 1289523292U;
  c6_info[51].fileTimeHi = 0U;
  c6_info[51].mFileTimeLo = 0U;
  c6_info[51].mFileTimeHi = 0U;
  c6_info[52].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[52].name = "eml_scalar_eg";
  c6_info[52].dominantType = "double";
  c6_info[52].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[52].fileTimeLo = 1286825996U;
  c6_info[52].fileTimeHi = 0U;
  c6_info[52].mFileTimeLo = 0U;
  c6_info[52].mFileTimeHi = 0U;
  c6_info[53].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[53].name = "eml_refblas_xgemm";
  c6_info[53].dominantType = "int32";
  c6_info[53].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[53].fileTimeLo = 1299080374U;
  c6_info[53].fileTimeHi = 0U;
  c6_info[53].mFileTimeLo = 0U;
  c6_info[53].mFileTimeHi = 0U;
  c6_info[54].context = "";
  c6_info[54].name = "abs";
  c6_info[54].dominantType = "double";
  c6_info[54].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[54].fileTimeLo = 1286825894U;
  c6_info[54].fileTimeHi = 0U;
  c6_info[54].mFileTimeLo = 0U;
  c6_info[54].mFileTimeHi = 0U;
  c6_info[55].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[55].name = "eml_scalar_abs";
  c6_info[55].dominantType = "double";
  c6_info[55].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[55].fileTimeLo = 1286825912U;
  c6_info[55].fileTimeHi = 0U;
  c6_info[55].mFileTimeLo = 0U;
  c6_info[55].mFileTimeHi = 0U;
}

static real_T c6_sqrt(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  c6_b_sqrt(chartInstance, &c6_b_x);
  return c6_b_x;
}

static void c6_eml_error(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
  int32_T c6_i128;
  static char_T c6_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  for (c6_i128 = 0; c6_i128 < 30; c6_i128++) {
    c6_u[c6_i128] = c6_varargin_1[c6_i128];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static void c6_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void c6_eml_int_forloop_overflow_check(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c6_mpower(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T
  c6_a)
{
  real_T c6_b_a;
  real_T c6_ak;
  c6_b_a = c6_a;
  c6_eml_scalar_eg(chartInstance);
  c6_ak = c6_b_a;
  return muDoubleScalarPower(c6_ak, 2.0);
}

static void c6_c_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static void c6_d_eml_scalar_eg(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c6_abs(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  return muDoubleScalarAbs(c6_b_x);
}

static const mxArray *c6_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_ac_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i129;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i129, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i129;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_bc_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_iC_3ph_MR2, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_cc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_iC_3ph_MR2), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_iC_3ph_MR2);
  return c6_y;
}

static uint8_T c6_cc_emlrt_marshallIn(SFc6_iC_3ph_MR2InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sqrt(SFc6_iC_3ph_MR2InstanceStruct *chartInstance, real_T *c6_x)
{
  if (*c6_x < 0.0) {
    c6_eml_error(chartInstance);
  }

  *c6_x = muDoubleScalarSqrt(*c6_x);
}

static void init_dsm_address_info(SFc6_iC_3ph_MR2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_iC_3ph_MR2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2722938419U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1393264597U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(627063970U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1551279329U);
}

mxArray *sf_c6_iC_3ph_MR2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nM2585MgrfETqMboaxHPg");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c6_iC_3ph_MR2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[16],T\"theta_O\",},{M[1],M[5],T\"up_0\",},{M[4],M[0],T\"P\",S'l','i','p'{{M1x2[3317 3318],M[0],}}},{M[4],M[0],T\"eta_k_1\",S'l','i','p'{{M1x2[2299 2306],M[0],}}},{M[4],M[0],T\"eta_k_2\",S'l','i','p'{{M1x2[2388 2395],M[0],}}},{M[4],M[0],T\"eta_k_3\",S'l','i','p'{{M1x2[2477 2484],M[0],}}},{M[4],M[0],T\"gama2\",S'l','i','p'{{M1x2[4520 4525],M[0],}}},{M[4],M[0],T\"i2m_k_1\",S'l','i','p'{{M1x2[2566 2573],M[0],}}},{M[4],M[0],T\"i2m_k_2\",S'l','i','p'{{M1x2[2626 2633],M[0],}}},{M[4],M[0],T\"i2m_k_3\",S'l','i','p'{{M1x2[2686 2693],M[0],}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"i2ref_k_1\",S'l','i','p'{{M1x2[2746 2755],M[0],}}},{M[4],M[0],T\"i2ref_k_2\",S'l','i','p'{{M1x2[2812 2821],M[0],}}},{M[4],M[0],T\"i2ref_k_3\",S'l','i','p'{{M1x2[2878 2887],M[0],}}},{M[4],M[0],T\"m2\",S'l','i','p'{{M1x2[3164 3166],M[0],}}},{M[4],M[0],T\"omega_k\",S'l','i','p'{{M1x2[1925 1932],M[0],}}},{M[4],M[0],T\"omega_k_1\",S'l','i','p'{{M1x2[2014 2023],M[0],}}},{M[4],M[0],T\"omega_k_2\",S'l','i','p'{{M1x2[2109 2118],M[0],}}},{M[4],M[0],T\"omega_k_3\",S'l','i','p'{{M1x2[2204 2213],M[0],}}},{M[4],M[0],T\"rho_k\",S'l','i','p'{{M1x2[3106 3111],M[0],}}},{M[4],M[0],T\"theta_k\",S'l','i','p'{{M1x2[1201 1208],M[0],}}}}",
    "100 S1x6'type','srcId','name','auxInfo'{{M[4],M[0],T\"u_k_1\",S'l','i','p'{{M1x2[3209 3214],M[0],}}},{M[4],M[0],T\"u_k_2\",S'l','i','p'{{M1x2[3263 3268],M[0],}}},{M[4],M[0],T\"v_k_1\",S'l','i','p'{{M1x2[2944 2949],M[0],}}},{M[4],M[0],T\"v_k_2\",S'l','i','p'{{M1x2[2998 3003],M[0],}}},{M[4],M[0],T\"v_k_3\",S'l','i','p'{{M1x2[3052 3057],M[0],}}},{M[8],M[0],T\"is_active_c6_iC_3ph_MR2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 26, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_iC_3ph_MR2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
    chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_iC_3ph_MR2MachineNumber_,
           6,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"i2ref_k");
          _SFD_SET_DATA_PROPS(1,2,0,1,"up_0");
          _SFD_SET_DATA_PROPS(2,1,1,0,"i2_k");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ic_k");
          _SFD_SET_DATA_PROPS(4,1,1,0,"flag");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t");
          _SFD_SET_DATA_PROPS(6,2,0,1,"theta_O");
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
        _SFD_CV_INIT_EML(0,1,1,25,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,7043);
        _SFD_CV_INIT_EML_IF(0,1,0,1210,1229,-1,1912);
        _SFD_CV_INIT_EML_IF(0,1,1,1934,1953,-1,2001);
        _SFD_CV_INIT_EML_IF(0,1,2,2025,2046,-1,2096);
        _SFD_CV_INIT_EML_IF(0,1,3,2120,2141,-1,2191);
        _SFD_CV_INIT_EML_IF(0,1,4,2215,2236,-1,2286);
        _SFD_CV_INIT_EML_IF(0,1,5,2308,2327,-1,2375);
        _SFD_CV_INIT_EML_IF(0,1,6,2397,2416,-1,2464);
        _SFD_CV_INIT_EML_IF(0,1,7,2486,2505,-1,2553);
        _SFD_CV_INIT_EML_IF(0,1,8,2575,2594,-1,2613);
        _SFD_CV_INIT_EML_IF(0,1,9,2635,2654,-1,2673);
        _SFD_CV_INIT_EML_IF(0,1,10,2695,2714,-1,2733);
        _SFD_CV_INIT_EML_IF(0,1,11,2757,2778,-1,2799);
        _SFD_CV_INIT_EML_IF(0,1,12,2823,2844,-1,2865);
        _SFD_CV_INIT_EML_IF(0,1,13,2889,2910,-1,2931);
        _SFD_CV_INIT_EML_IF(0,1,14,2951,2968,-1,2985);
        _SFD_CV_INIT_EML_IF(0,1,15,3005,3022,-1,3039);
        _SFD_CV_INIT_EML_IF(0,1,16,3059,3076,-1,3093);
        _SFD_CV_INIT_EML_IF(0,1,17,3113,3130,-1,3151);
        _SFD_CV_INIT_EML_IF(0,1,18,3168,3182,-1,3196);
        _SFD_CV_INIT_EML_IF(0,1,19,3216,3233,-1,3250);
        _SFD_CV_INIT_EML_IF(0,1,20,3270,3287,-1,3304);
        _SFD_CV_INIT_EML_IF(0,1,21,3320,3333,-1,4507);
        _SFD_CV_INIT_EML_IF(0,1,22,4527,4544,-1,4594);
        _SFD_CV_INIT_EML_IF(0,1,23,5861,5871,5914,5965);
        _SFD_CV_INIT_EML_IF(0,1,24,6316,6326,6380,6441);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)c6_y_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_y_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_x_sf_marshallOut,(MexInFcnForType)
            c6_x_sf_marshallIn);
        }

        {
          real_T *c6_i2ref_k;
          real_T *c6_up_0;
          real_T *c6_i2_k;
          real_T *c6_ic_k;
          real_T *c6_flag;
          real_T *c6_t;
          real_T (*c6_theta_O)[6];
          c6_theta_O = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
          c6_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c6_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_ic_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_up_0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_i2ref_k);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_up_0);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_i2_k);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_ic_k);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_flag);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_t);
          _SFD_SET_DATA_VALUE_PTR(6U, *c6_theta_O);
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
  return "EFhZqfXJFjYyEz0JjFzy0";
}

static void sf_opaque_initialize_c6_iC_3ph_MR2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*)
    chartInstanceVar);
  initialize_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_iC_3ph_MR2(void *chartInstanceVar)
{
  enable_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_iC_3ph_MR2(void *chartInstanceVar)
{
  disable_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_iC_3ph_MR2(void *chartInstanceVar)
{
  sf_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_iC_3ph_MR2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_iC_3ph_MR2
    ((SFc6_iC_3ph_MR2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_iC_3ph_MR2();/* state var info */
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

extern void sf_internal_set_sim_state_c6_iC_3ph_MR2(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_iC_3ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_iC_3ph_MR2(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_iC_3ph_MR2(S);
}

static void sf_opaque_set_sim_state_c6_iC_3ph_MR2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_iC_3ph_MR2(S, st);
}

static void sf_opaque_terminate_c6_iC_3ph_MR2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_iC_3ph_MR2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_iC_3ph_MR2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_iC_3ph_MR2((SFc6_iC_3ph_MR2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_iC_3ph_MR2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4136195088U));
  ssSetChecksum1(S,(418677156U));
  ssSetChecksum2(S,(3764153526U));
  ssSetChecksum3(S,(3547319595U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_iC_3ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_iC_3ph_MR2(SimStruct *S)
{
  SFc6_iC_3ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc6_iC_3ph_MR2InstanceStruct *)malloc(sizeof
    (SFc6_iC_3ph_MR2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_iC_3ph_MR2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_iC_3ph_MR2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_iC_3ph_MR2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_iC_3ph_MR2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_iC_3ph_MR2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_iC_3ph_MR2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_iC_3ph_MR2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_iC_3ph_MR2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_iC_3ph_MR2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_iC_3ph_MR2;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_iC_3ph_MR2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_iC_3ph_MR2;
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

void c6_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_iC_3ph_MR2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_iC_3ph_MR2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_iC_3ph_MR2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
