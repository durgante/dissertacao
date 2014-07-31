/* Include files */

#include "blascompat32.h"
#include "vC_1ph_MR2_sfun.h"
#include "c2_vC_1ph_MR2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "vC_1ph_MR2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[81] = { "L1ideal", "L2ideal",
  "Lgideal", "Cideal", "R1ideal", "R2ideal", "Rgideal", "errL1", "errL2",
  "errLg", "errC", "errR1", "errR2", "errRg", "deltaL1", "deltaL2", "deltaLg",
  "deltaC", "deltaR1", "deltaR2", "deltaRg", "L1", "L2", "C", "R1", "R2", "Ts",
  "w", "kp_kd", "Kp", "p1", "p2", "km", "gamaD", "gama", "delta0", "u_k",
  "eta_k", "i2m_k", "e1_k", "v_k", "q_k", "e2_k", "ea_k", "eta2_k", "m2_k",
  "nargin", "nargout", "i2ref_k", "i2_k", "vc_k", "flag", "t", "up_alpha",
  "theta_alpha", "m", "theta_k", "omega_k", "omega_k_1", "omega_k_2",
  "omega_k_3", "eta_k_1", "eta_k_2", "eta_k_3", "i2m_k_1", "i2m_k_2", "i2m_k_3",
  "i2ref_k_1", "i2ref_k_2", "i2ref_k_3", "v_k_1", "v_k_2", "v_k_3", "rho_k",
  "m2", "vc_k_1", "vc_k_2", "u_k_1", "u_k_2", "P", "gama2" };

/* Function Declarations */
static void initialize_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static void initialize_params_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static void enable_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void disable_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *
  chartInstance);
static void set_sim_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void sf_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void c2_chartstep_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static void initSimStructsc2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_gama2, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_P, const char_T *c2_identifier, real_T c2_y[36]);
static void c2_d_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[36]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_u_k_2, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_u_k_1, const char_T *c2_identifier);
static real_T c2_h_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_i_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_vc_k_2, const char_T *c2_identifier);
static real_T c2_j_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_k_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_vc_k_1, const char_T *c2_identifier);
static real_T c2_l_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_m_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_m2, const char_T *c2_identifier);
static real_T c2_n_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_o_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_rho_k, const char_T *c2_identifier);
static real_T c2_p_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_q_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_3, const char_T *c2_identifier);
static real_T c2_r_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_s_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_2, const char_T *c2_identifier);
static real_T c2_t_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_u_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_1, const char_T *c2_identifier);
static real_T c2_v_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_w_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_i2ref_k_3, const char_T *c2_identifier);
static real_T c2_x_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_y_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_i2ref_k_2, const char_T *c2_identifier);
static real_T c2_ab_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_bb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2ref_k_1, const char_T *c2_identifier);
static real_T c2_cb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_db_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_3, const char_T *c2_identifier);
static real_T c2_eb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_fb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_2, const char_T *c2_identifier);
static real_T c2_gb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_hb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_1, const char_T *c2_identifier);
static real_T c2_ib_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_jb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_3, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_kb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_lb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_2, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_mb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_nb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_1, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_ob_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_pb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_3, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_qb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_rb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_2, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_sb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_w_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_tb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_1, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_ub_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_x_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_vb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_wb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_y_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_xb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_theta_k, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_yb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_ac_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_m, const char_T *c2_identifier);
static real_T c2_bc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_cc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_theta_alpha, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_dc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[52]);
static real_T c2_sqrt(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T c2_x);
static void c2_eml_error(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void c2_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void c2_eml_int_forloop_overflow_check(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static real_T c2_mpower(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T
  c2_a);
static void c2_c_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static void c2_d_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);
static real_T c2_abs(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T c2_x);
static const mxArray *c2_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_ec_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_cb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_fc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_vC_1ph_MR2, const char_T
  *c2_identifier);
static uint8_T c2_gc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T *c2_x);
static void init_dsm_address_info(SFc2_vC_1ph_MR2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_theta_k_not_empty = FALSE;
  chartInstance->c2_omega_k_not_empty = FALSE;
  chartInstance->c2_omega_k_1_not_empty = FALSE;
  chartInstance->c2_omega_k_2_not_empty = FALSE;
  chartInstance->c2_omega_k_3_not_empty = FALSE;
  chartInstance->c2_eta_k_1_not_empty = FALSE;
  chartInstance->c2_eta_k_2_not_empty = FALSE;
  chartInstance->c2_eta_k_3_not_empty = FALSE;
  chartInstance->c2_i2m_k_1_not_empty = FALSE;
  chartInstance->c2_i2m_k_2_not_empty = FALSE;
  chartInstance->c2_i2m_k_3_not_empty = FALSE;
  chartInstance->c2_i2ref_k_1_not_empty = FALSE;
  chartInstance->c2_i2ref_k_2_not_empty = FALSE;
  chartInstance->c2_i2ref_k_3_not_empty = FALSE;
  chartInstance->c2_v_k_1_not_empty = FALSE;
  chartInstance->c2_v_k_2_not_empty = FALSE;
  chartInstance->c2_v_k_3_not_empty = FALSE;
  chartInstance->c2_rho_k_not_empty = FALSE;
  chartInstance->c2_m2_not_empty = FALSE;
  chartInstance->c2_vc_k_1_not_empty = FALSE;
  chartInstance->c2_vc_k_2_not_empty = FALSE;
  chartInstance->c2_u_k_1_not_empty = FALSE;
  chartInstance->c2_u_k_2_not_empty = FALSE;
  chartInstance->c2_P_not_empty = FALSE;
  chartInstance->c2_gama2_not_empty = FALSE;
  chartInstance->c2_is_active_c2_vC_1ph_MR2 = 0U;
}

static void initialize_params_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
}

static void enable_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i0;
  real_T c2_b_u[6];
  const mxArray *c2_c_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i1;
  real_T c2_d_u[36];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i2;
  real_T c2_e_u[6];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i3;
  real_T c2_f_u[6];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i4;
  real_T c2_g_u[6];
  const mxArray *c2_h_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_n_u;
  const mxArray *c2_o_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_o_u;
  const mxArray *c2_p_y = NULL;
  int32_T c2_i5;
  real_T c2_p_u[6];
  const mxArray *c2_q_y = NULL;
  int32_T c2_i6;
  real_T c2_q_u[6];
  const mxArray *c2_r_y = NULL;
  int32_T c2_i7;
  real_T c2_r_u[6];
  const mxArray *c2_s_y = NULL;
  int32_T c2_i8;
  real_T c2_s_u[6];
  const mxArray *c2_t_y = NULL;
  real_T c2_k_hoistedGlobal;
  real_T c2_t_u;
  const mxArray *c2_u_y = NULL;
  int32_T c2_i9;
  real_T c2_u_u[6];
  const mxArray *c2_v_y = NULL;
  real_T c2_l_hoistedGlobal;
  real_T c2_v_u;
  const mxArray *c2_w_y = NULL;
  real_T c2_m_hoistedGlobal;
  real_T c2_w_u;
  const mxArray *c2_x_y = NULL;
  real_T c2_n_hoistedGlobal;
  real_T c2_x_u;
  const mxArray *c2_y_y = NULL;
  real_T c2_o_hoistedGlobal;
  real_T c2_y_u;
  const mxArray *c2_ab_y = NULL;
  real_T c2_p_hoistedGlobal;
  real_T c2_ab_u;
  const mxArray *c2_bb_y = NULL;
  real_T c2_q_hoistedGlobal;
  real_T c2_bb_u;
  const mxArray *c2_cb_y = NULL;
  real_T c2_r_hoistedGlobal;
  real_T c2_cb_u;
  const mxArray *c2_db_y = NULL;
  uint8_T c2_s_hoistedGlobal;
  uint8_T c2_db_u;
  const mxArray *c2_eb_y = NULL;
  real_T *c2_m;
  real_T *c2_up_alpha;
  real_T (*c2_theta_alpha)[6];
  c2_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta_alpha = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_up_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(29), FALSE);
  c2_hoistedGlobal = *c2_m;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_b_u[c2_i0] = (*c2_theta_alpha)[c2_i0];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = *c2_up_alpha;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i1 = 0; c2_i1 < 36; c2_i1++) {
    c2_d_u[c2_i1] = chartInstance->c2_P[c2_i1];
  }

  c2_e_y = NULL;
  if (!chartInstance->c2_P_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 2, 6, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    c2_e_u[c2_i2] = chartInstance->c2_eta_k_1[c2_i2];
  }

  c2_f_y = NULL;
  if (!chartInstance->c2_eta_k_1_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    c2_f_u[c2_i3] = chartInstance->c2_eta_k_2[c2_i3];
  }

  c2_g_y = NULL;
  if (!chartInstance->c2_eta_k_2_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    c2_g_u[c2_i4] = chartInstance->c2_eta_k_3[c2_i4];
  }

  c2_h_y = NULL;
  if (!chartInstance->c2_eta_k_3_not_empty) {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_c_hoistedGlobal = chartInstance->c2_gama2;
  c2_h_u = c2_c_hoistedGlobal;
  c2_i_y = NULL;
  if (!chartInstance->c2_gama2_not_empty) {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_d_hoistedGlobal = chartInstance->c2_i2m_k_1;
  c2_i_u = c2_d_hoistedGlobal;
  c2_j_y = NULL;
  if (!chartInstance->c2_i2m_k_1_not_empty) {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_e_hoistedGlobal = chartInstance->c2_i2m_k_2;
  c2_j_u = c2_e_hoistedGlobal;
  c2_k_y = NULL;
  if (!chartInstance->c2_i2m_k_2_not_empty) {
    sf_mex_assign(&c2_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_f_hoistedGlobal = chartInstance->c2_i2m_k_3;
  c2_k_u = c2_f_hoistedGlobal;
  c2_l_y = NULL;
  if (!chartInstance->c2_i2m_k_3_not_empty) {
    sf_mex_assign(&c2_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_g_hoistedGlobal = chartInstance->c2_i2ref_k_1;
  c2_l_u = c2_g_hoistedGlobal;
  c2_m_y = NULL;
  if (!chartInstance->c2_i2ref_k_1_not_empty) {
    sf_mex_assign(&c2_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_h_hoistedGlobal = chartInstance->c2_i2ref_k_2;
  c2_m_u = c2_h_hoistedGlobal;
  c2_n_y = NULL;
  if (!chartInstance->c2_i2ref_k_2_not_empty) {
    sf_mex_assign(&c2_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_i_hoistedGlobal = chartInstance->c2_i2ref_k_3;
  c2_n_u = c2_i_hoistedGlobal;
  c2_o_y = NULL;
  if (!chartInstance->c2_i2ref_k_3_not_empty) {
    sf_mex_assign(&c2_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_j_hoistedGlobal = chartInstance->c2_m2;
  c2_o_u = c2_j_hoistedGlobal;
  c2_p_y = NULL;
  if (!chartInstance->c2_m2_not_empty) {
    sf_mex_assign(&c2_p_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 14, c2_p_y);
  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    c2_p_u[c2_i5] = chartInstance->c2_omega_k[c2_i5];
  }

  c2_q_y = NULL;
  if (!chartInstance->c2_omega_k_not_empty) {
    sf_mex_assign(&c2_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_p_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 15, c2_q_y);
  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    c2_q_u[c2_i6] = chartInstance->c2_omega_k_1[c2_i6];
  }

  c2_r_y = NULL;
  if (!chartInstance->c2_omega_k_1_not_empty) {
    sf_mex_assign(&c2_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_q_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 16, c2_r_y);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    c2_r_u[c2_i7] = chartInstance->c2_omega_k_2[c2_i7];
  }

  c2_s_y = NULL;
  if (!chartInstance->c2_omega_k_2_not_empty) {
    sf_mex_assign(&c2_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_r_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 17, c2_s_y);
  for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
    c2_s_u[c2_i8] = chartInstance->c2_omega_k_3[c2_i8];
  }

  c2_t_y = NULL;
  if (!chartInstance->c2_omega_k_3_not_empty) {
    sf_mex_assign(&c2_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_s_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 18, c2_t_y);
  c2_k_hoistedGlobal = chartInstance->c2_rho_k;
  c2_t_u = c2_k_hoistedGlobal;
  c2_u_y = NULL;
  if (!chartInstance->c2_rho_k_not_empty) {
    sf_mex_assign(&c2_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 19, c2_u_y);
  for (c2_i9 = 0; c2_i9 < 6; c2_i9++) {
    c2_u_u[c2_i9] = chartInstance->c2_theta_k[c2_i9];
  }

  c2_v_y = NULL;
  if (!chartInstance->c2_theta_k_not_empty) {
    sf_mex_assign(&c2_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_u_u, 0, 0U, 1U, 0U, 1, 6),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 20, c2_v_y);
  c2_l_hoistedGlobal = chartInstance->c2_u_k_1;
  c2_v_u = c2_l_hoistedGlobal;
  c2_w_y = NULL;
  if (!chartInstance->c2_u_k_1_not_empty) {
    sf_mex_assign(&c2_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 21, c2_w_y);
  c2_m_hoistedGlobal = chartInstance->c2_u_k_2;
  c2_w_u = c2_m_hoistedGlobal;
  c2_x_y = NULL;
  if (!chartInstance->c2_u_k_2_not_empty) {
    sf_mex_assign(&c2_x_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 22, c2_x_y);
  c2_n_hoistedGlobal = chartInstance->c2_v_k_1;
  c2_x_u = c2_n_hoistedGlobal;
  c2_y_y = NULL;
  if (!chartInstance->c2_v_k_1_not_empty) {
    sf_mex_assign(&c2_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 23, c2_y_y);
  c2_o_hoistedGlobal = chartInstance->c2_v_k_2;
  c2_y_u = c2_o_hoistedGlobal;
  c2_ab_y = NULL;
  if (!chartInstance->c2_v_k_2_not_empty) {
    sf_mex_assign(&c2_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 24, c2_ab_y);
  c2_p_hoistedGlobal = chartInstance->c2_v_k_3;
  c2_ab_u = c2_p_hoistedGlobal;
  c2_bb_y = NULL;
  if (!chartInstance->c2_v_k_3_not_empty) {
    sf_mex_assign(&c2_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_bb_y, sf_mex_create("y", &c2_ab_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 25, c2_bb_y);
  c2_q_hoistedGlobal = chartInstance->c2_vc_k_1;
  c2_bb_u = c2_q_hoistedGlobal;
  c2_cb_y = NULL;
  if (!chartInstance->c2_vc_k_1_not_empty) {
    sf_mex_assign(&c2_cb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_bb_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 26, c2_cb_y);
  c2_r_hoistedGlobal = chartInstance->c2_vc_k_2;
  c2_cb_u = c2_r_hoistedGlobal;
  c2_db_y = NULL;
  if (!chartInstance->c2_vc_k_2_not_empty) {
    sf_mex_assign(&c2_db_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_db_y, sf_mex_create("y", &c2_cb_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 27, c2_db_y);
  c2_s_hoistedGlobal = chartInstance->c2_is_active_c2_vC_1ph_MR2;
  c2_db_u = c2_s_hoistedGlobal;
  c2_eb_y = NULL;
  sf_mex_assign(&c2_eb_y, sf_mex_create("y", &c2_db_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 28, c2_eb_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i10;
  real_T c2_dv1[36];
  int32_T c2_i11;
  real_T c2_dv2[6];
  int32_T c2_i12;
  real_T c2_dv3[6];
  int32_T c2_i13;
  real_T c2_dv4[6];
  int32_T c2_i14;
  real_T c2_dv5[6];
  int32_T c2_i15;
  real_T c2_dv6[6];
  int32_T c2_i16;
  real_T c2_dv7[6];
  int32_T c2_i17;
  real_T c2_dv8[6];
  int32_T c2_i18;
  real_T c2_dv9[6];
  int32_T c2_i19;
  real_T *c2_m;
  real_T *c2_up_alpha;
  real_T (*c2_theta_alpha)[6];
  c2_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta_alpha = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_up_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_m = c2_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "m");
  c2_cc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "theta_alpha", c2_dv0);
  for (c2_i10 = 0; c2_i10 < 6; c2_i10++) {
    (*c2_theta_alpha)[c2_i10] = c2_dv0[c2_i10];
  }

  *c2_up_alpha = c2_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "up_alpha");
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)), "P",
                        c2_dv1);
  for (c2_i11 = 0; c2_i11 < 36; c2_i11++) {
    chartInstance->c2_P[c2_i11] = c2_dv1[c2_i11];
  }

  c2_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "eta_k_1", c2_dv2);
  for (c2_i12 = 0; c2_i12 < 6; c2_i12++) {
    chartInstance->c2_eta_k_1[c2_i12] = c2_dv2[c2_i12];
  }

  c2_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
    "eta_k_2", c2_dv3);
  for (c2_i13 = 0; c2_i13 < 6; c2_i13++) {
    chartInstance->c2_eta_k_2[c2_i13] = c2_dv3[c2_i13];
  }

  c2_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
    "eta_k_3", c2_dv4);
  for (c2_i14 = 0; c2_i14 < 6; c2_i14++) {
    chartInstance->c2_eta_k_3[c2_i14] = c2_dv4[c2_i14];
  }

  chartInstance->c2_gama2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 7)), "gama2");
  chartInstance->c2_i2m_k_1 = c2_hb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "i2m_k_1");
  chartInstance->c2_i2m_k_2 = c2_fb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 9)), "i2m_k_2");
  chartInstance->c2_i2m_k_3 = c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 10)), "i2m_k_3");
  chartInstance->c2_i2ref_k_1 = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 11)), "i2ref_k_1");
  chartInstance->c2_i2ref_k_2 = c2_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 12)), "i2ref_k_2");
  chartInstance->c2_i2ref_k_3 = c2_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 13)), "i2ref_k_3");
  chartInstance->c2_m2 = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 14)), "m2");
  c2_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 15)),
    "omega_k", c2_dv5);
  for (c2_i15 = 0; c2_i15 < 6; c2_i15++) {
    chartInstance->c2_omega_k[c2_i15] = c2_dv5[c2_i15];
  }

  c2_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 16)),
    "omega_k_1", c2_dv6);
  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    chartInstance->c2_omega_k_1[c2_i16] = c2_dv6[c2_i16];
  }

  c2_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 17)),
    "omega_k_2", c2_dv7);
  for (c2_i17 = 0; c2_i17 < 6; c2_i17++) {
    chartInstance->c2_omega_k_2[c2_i17] = c2_dv7[c2_i17];
  }

  c2_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 18)),
    "omega_k_3", c2_dv8);
  for (c2_i18 = 0; c2_i18 < 6; c2_i18++) {
    chartInstance->c2_omega_k_3[c2_i18] = c2_dv8[c2_i18];
  }

  chartInstance->c2_rho_k = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 19)), "rho_k");
  c2_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 20)),
    "theta_k", c2_dv9);
  for (c2_i19 = 0; c2_i19 < 6; c2_i19++) {
    chartInstance->c2_theta_k[c2_i19] = c2_dv9[c2_i19];
  }

  chartInstance->c2_u_k_1 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 21)), "u_k_1");
  chartInstance->c2_u_k_2 = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 22)), "u_k_2");
  chartInstance->c2_v_k_1 = c2_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 23)), "v_k_1");
  chartInstance->c2_v_k_2 = c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 24)), "v_k_2");
  chartInstance->c2_v_k_3 = c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 25)), "v_k_3");
  chartInstance->c2_vc_k_1 = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 26)), "vc_k_1");
  chartInstance->c2_vc_k_2 = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 27)), "vc_k_2");
  chartInstance->c2_is_active_c2_vC_1ph_MR2 = c2_fc_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 28)),
     "is_active_c2_vC_1ph_MR2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_vC_1ph_MR2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

static void sf_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
  int32_T c2_i20;
  real_T *c2_i2ref_k;
  real_T *c2_up_alpha;
  real_T *c2_i2_k;
  real_T *c2_vc_k;
  real_T *c2_flag;
  real_T *c2_t;
  real_T *c2_m;
  real_T (*c2_theta_alpha)[6];
  c2_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta_alpha = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_up_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_i2ref_k, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_up_alpha, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_i2_k, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_vc_k, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_flag, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_t, 5U);
  for (c2_i20 = 0; c2_i20 < 6; c2_i20++) {
    _SFD_DATA_RANGE_CHECK((*c2_theta_alpha)[c2_i20], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_m, 7U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_vC_1ph_MR2(chartInstance);
  sf_debug_check_for_state_inconsistency(_vC_1ph_MR2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_i2ref_k;
  real_T c2_i2_k;
  real_T c2_vc_k;
  real_T c2_flag;
  real_T c2_t;
  uint32_T c2_debug_family_var_map[81];
  real_T c2_L1ideal;
  real_T c2_L2ideal;
  real_T c2_Lgideal;
  real_T c2_Cideal;
  real_T c2_R1ideal;
  real_T c2_R2ideal;
  real_T c2_Rgideal;
  real_T c2_errL1;
  real_T c2_errL2;
  real_T c2_errLg;
  real_T c2_errC;
  real_T c2_errR1;
  real_T c2_errR2;
  real_T c2_errRg;
  real_T c2_deltaL1;
  real_T c2_deltaL2;
  real_T c2_deltaLg;
  real_T c2_deltaC;
  real_T c2_deltaR1;
  real_T c2_deltaR2;
  real_T c2_deltaRg;
  real_T c2_L1;
  real_T c2_L2;
  real_T c2_C;
  real_T c2_R1;
  real_T c2_R2;
  real_T c2_Ts;
  real_T c2_w;
  real_T c2_kp_kd;
  real_T c2_Kp;
  real_T c2_p1;
  real_T c2_p2;
  real_T c2_km;
  real_T c2_gamaD;
  real_T c2_gama;
  real_T c2_delta0;
  real_T c2_u_k;
  real_T c2_eta_k[6];
  real_T c2_i2m_k;
  real_T c2_e1_k;
  real_T c2_v_k;
  real_T c2_q_k;
  real_T c2_e2_k;
  real_T c2_ea_k;
  real_T c2_eta2_k[6];
  real_T c2_m2_k;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 3.0;
  real_T c2_up_alpha;
  real_T c2_theta_alpha[6];
  real_T c2_m;
  int32_T c2_i21;
  static real_T c2_dv10[6] = { 0.4226, -3.4222, -0.2133, 12.7376, 0.0, 0.0 };

  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  static real_T c2_dv11[36] = { 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0098 };

  int32_T c2_i30;
  real_T c2_f_hoistedGlobal[6];
  int32_T c2_i31;
  real_T c2_g_hoistedGlobal[6];
  int32_T c2_i32;
  real_T c2_a[6];
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_b;
  real_T c2_y;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_hoistedGlobal;
  real_T c2_b_b;
  real_T c2_b_y;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_j_hoistedGlobal[6];
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_k_hoistedGlobal;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_l_hoistedGlobal;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_m_hoistedGlobal;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_n_hoistedGlobal;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_o_hoistedGlobal;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_p_hoistedGlobal;
  real_T c2_h_b;
  real_T c2_h_y;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_c_k;
  int32_T c2_d_k;
  real_T c2_q_hoistedGlobal;
  real_T c2_b_a;
  real_T c2_i_b;
  real_T c2_i_y;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  real_T c2_j_y;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  real_T c2_k_y;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i50;
  real_T c2_r_hoistedGlobal[36];
  int32_T c2_i51;
  real_T c2_s_hoistedGlobal[36];
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  real_T c2_l_y[36];
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_m_y[36];
  int32_T c2_i64;
  int32_T c2_i65;
  real_T c2_B;
  real_T c2_n_y;
  real_T c2_o_y;
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_t_hoistedGlobal;
  real_T c2_u_hoistedGlobal;
  real_T c2_c_a;
  real_T c2_j_b;
  real_T c2_p_y;
  real_T c2_A;
  real_T c2_b_B;
  real_T c2_x;
  real_T c2_q_y;
  real_T c2_b_x;
  real_T c2_r_y;
  real_T c2_s_y;
  int32_T c2_i68;
  real_T c2_k_b;
  real_T c2_t_y;
  real_T c2_b_A;
  real_T c2_c_B;
  real_T c2_c_x;
  real_T c2_u_y;
  real_T c2_d_x;
  real_T c2_v_y;
  real_T c2_w_y;
  real_T c2_d_a;
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_v_hoistedGlobal;
  real_T c2_l_b;
  real_T c2_x_y;
  real_T c2_e_a;
  real_T c2_m_b;
  real_T c2_y_y;
  real_T c2_c_A;
  real_T c2_d_B;
  real_T c2_e_x;
  real_T c2_ab_y;
  real_T c2_f_x;
  real_T c2_bb_y;
  real_T c2_cb_y;
  real_T c2_w_hoistedGlobal;
  real_T c2_n_b;
  real_T c2_db_y;
  real_T c2_x_hoistedGlobal;
  real_T c2_o_b;
  real_T c2_eb_y;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  real_T c2_p_b;
  real_T c2_fb_y;
  real_T c2_q_b;
  real_T c2_gb_y;
  int32_T c2_i77;
  real_T c2_r_b;
  real_T c2_hb_y;
  real_T c2_s_b;
  real_T c2_ib_y;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  real_T *c2_b_i2ref_k;
  real_T *c2_b_i2_k;
  real_T *c2_b_vc_k;
  real_T *c2_b_flag;
  real_T *c2_b_t;
  real_T *c2_b_up_alpha;
  real_T *c2_b_m;
  real_T (*c2_b_theta_alpha)[6];
  c2_b_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_theta_alpha = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_up_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_i2ref_k;
  c2_b_hoistedGlobal = *c2_b_i2_k;
  c2_c_hoistedGlobal = *c2_b_vc_k;
  c2_d_hoistedGlobal = *c2_b_flag;
  c2_e_hoistedGlobal = *c2_b_t;
  c2_i2ref_k = c2_hoistedGlobal;
  c2_i2_k = c2_b_hoistedGlobal;
  c2_vc_k = c2_c_hoistedGlobal;
  c2_flag = c2_d_hoistedGlobal;
  c2_t = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 81U, 81U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_L1ideal, 0U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_L2ideal, 1U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Lgideal, 2U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Cideal, 3U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_R1ideal, 4U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_R2ideal, 5U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Rgideal, 6U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errL1, 7U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errL2, 8U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errLg, 9U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errC, 10U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errR1, 11U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errR2, 12U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_errRg, 13U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_deltaL1, 14U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_deltaL2, 15U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_deltaLg, 16U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_deltaC, 17U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_deltaR1, 18U,
    c2_ab_sf_marshallOut, c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_deltaR2, 19U,
    c2_ab_sf_marshallOut, c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_deltaRg, 20U,
    c2_ab_sf_marshallOut, c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_L1, 21U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_L2, 22U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_C, 23U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_R1, 24U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_R2, 25U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Ts, 26U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_w, 27U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_kp_kd, 28U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Kp, 29U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_p1, 30U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_p2, 31U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_km, 32U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_gamaD, 33U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_gama, 34U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_delta0, 35U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_u_k, 36U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_eta_k, 37U, c2_bb_sf_marshallOut,
    c2_bb_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_i2m_k, 38U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_e1_k, 39U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_v_k, 40U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q_k, 41U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_e2_k, 42U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ea_k, 43U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_eta2_k, 44U, c2_bb_sf_marshallOut,
    c2_bb_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_m2_k, 45U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 46U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 47U,
    c2_ab_sf_marshallOut, c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_i2ref_k, 48U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_i2_k, 49U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_vc_k, 50U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_flag, 51U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_t, 52U, c2_ab_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_up_alpha, 53U,
    c2_ab_sf_marshallOut, c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_theta_alpha, 54U,
    c2_bb_sf_marshallOut, c2_bb_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_m, 55U, c2_ab_sf_marshallOut,
    c2_ab_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_theta_k, 56U,
    c2_y_sf_marshallOut, c2_y_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_omega_k, 57U,
    c2_x_sf_marshallOut, c2_x_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_omega_k_1, 58U,
    c2_w_sf_marshallOut, c2_w_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_omega_k_2, 59U,
    c2_v_sf_marshallOut, c2_v_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_omega_k_3, 60U,
    c2_u_sf_marshallOut, c2_u_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_eta_k_1, 61U,
    c2_t_sf_marshallOut, c2_t_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_eta_k_2, 62U,
    c2_s_sf_marshallOut, c2_s_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_eta_k_3, 63U,
    c2_r_sf_marshallOut, c2_r_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2m_k_1, 64U,
    c2_q_sf_marshallOut, c2_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2m_k_2, 65U,
    c2_p_sf_marshallOut, c2_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2m_k_3, 66U,
    c2_o_sf_marshallOut, c2_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2ref_k_1, 67U,
    c2_n_sf_marshallOut, c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2ref_k_2, 68U,
    c2_m_sf_marshallOut, c2_m_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_i2ref_k_3, 69U,
    c2_l_sf_marshallOut, c2_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_v_k_1, 70U,
    c2_k_sf_marshallOut, c2_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_v_k_2, 71U,
    c2_j_sf_marshallOut, c2_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_v_k_3, 72U,
    c2_i_sf_marshallOut, c2_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_rho_k, 73U,
    c2_h_sf_marshallOut, c2_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_m2, 74U,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_vc_k_1, 75U,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_vc_k_2, 76U,
    c2_e_sf_marshallOut, c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_u_k_1, 77U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_u_k_2, 78U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_P, 79U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_gama2, 80U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_L1ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_L2ideal = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_Lgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_Cideal = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_R1ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_R2ideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_Rgideal = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_errL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_errL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_errLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_errC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_errR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_errR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_errRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_deltaL1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_deltaL2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_deltaLg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_deltaC = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_deltaR1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_deltaR2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_deltaRg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_L1 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_L2 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_C = 4.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_R1 = c2_R1ideal + c2_deltaR1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_R2 = ((c2_R2ideal + c2_deltaR2) + c2_Rgideal) + c2_deltaRg;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_Ts = 8.3333333333333331E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_w = 2.4999999999999996E+7;
  c2_b_sqrt(chartInstance, &c2_w);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_kp_kd = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_Kp = 0.001792815465831;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_p1 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_p2 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_km = 0.64000000000000012;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_gamaD = 0.0098;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_gama = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
  c2_delta0 = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_theta_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    for (c2_i21 = 0; c2_i21 < 6; c2_i21++) {
      chartInstance->c2_theta_k[c2_i21] = c2_dv10[c2_i21];
    }

    chartInstance->c2_theta_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c2_omega_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    for (c2_i22 = 0; c2_i22 < 6; c2_i22++) {
      chartInstance->c2_omega_k[c2_i22] = 0.0;
    }

    chartInstance->c2_omega_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c2_omega_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
    for (c2_i23 = 0; c2_i23 < 6; c2_i23++) {
      chartInstance->c2_omega_k_1[c2_i23] = 0.0;
    }

    chartInstance->c2_omega_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c2_omega_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
    for (c2_i24 = 0; c2_i24 < 6; c2_i24++) {
      chartInstance->c2_omega_k_2[c2_i24] = 0.0;
    }

    chartInstance->c2_omega_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c2_omega_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    for (c2_i25 = 0; c2_i25 < 6; c2_i25++) {
      chartInstance->c2_omega_k_3[c2_i25] = 0.0;
    }

    chartInstance->c2_omega_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c2_eta_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 103);
    for (c2_i26 = 0; c2_i26 < 6; c2_i26++) {
      chartInstance->c2_eta_k_1[c2_i26] = 0.0;
    }

    chartInstance->c2_eta_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c2_eta_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 109);
    for (c2_i27 = 0; c2_i27 < 6; c2_i27++) {
      chartInstance->c2_eta_k_2[c2_i27] = 0.0;
    }

    chartInstance->c2_eta_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
  if (CV_EML_IF(0, 1, 7, !chartInstance->c2_eta_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 115);
    for (c2_i28 = 0; c2_i28 < 6; c2_i28++) {
      chartInstance->c2_eta_k_3[c2_i28] = 0.0;
    }

    chartInstance->c2_eta_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 119);
  if (CV_EML_IF(0, 1, 8, !chartInstance->c2_i2m_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
    chartInstance->c2_i2m_k_1 = 0.0;
    chartInstance->c2_i2m_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 124);
  if (CV_EML_IF(0, 1, 9, !chartInstance->c2_i2m_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 125);
    chartInstance->c2_i2m_k_2 = 0.0;
    chartInstance->c2_i2m_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 129U);
  if (CV_EML_IF(0, 1, 10, !chartInstance->c2_i2m_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 130U);
    chartInstance->c2_i2m_k_3 = 0.0;
    chartInstance->c2_i2m_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 134U);
  if (CV_EML_IF(0, 1, 11, !chartInstance->c2_i2ref_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 135U);
    chartInstance->c2_i2ref_k_1 = 0.0;
    chartInstance->c2_i2ref_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 139U);
  if (CV_EML_IF(0, 1, 12, !chartInstance->c2_i2ref_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 140U);
    chartInstance->c2_i2ref_k_2 = 0.0;
    chartInstance->c2_i2ref_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 144U);
  if (CV_EML_IF(0, 1, 13, !chartInstance->c2_i2ref_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 145U);
    chartInstance->c2_i2ref_k_3 = 0.0;
    chartInstance->c2_i2ref_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 149U);
  if (CV_EML_IF(0, 1, 14, !chartInstance->c2_v_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 150U);
    chartInstance->c2_v_k_1 = 0.0;
    chartInstance->c2_v_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 154U);
  if (CV_EML_IF(0, 1, 15, !chartInstance->c2_v_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 155U);
    chartInstance->c2_v_k_2 = 0.0;
    chartInstance->c2_v_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 159U);
  if (CV_EML_IF(0, 1, 16, !chartInstance->c2_v_k_3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 160U);
    chartInstance->c2_v_k_3 = 0.0;
    chartInstance->c2_v_k_3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 164U);
  if (CV_EML_IF(0, 1, 17, !chartInstance->c2_rho_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 165U);
    chartInstance->c2_rho_k = 0.002801274165360937;
    chartInstance->c2_rho_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 169U);
  if (CV_EML_IF(0, 1, 18, !chartInstance->c2_m2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 170U);
    chartInstance->c2_m2 = 1.0;
    chartInstance->c2_m2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 174U);
  if (CV_EML_IF(0, 1, 19, !chartInstance->c2_vc_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 175U);
    chartInstance->c2_vc_k_1 = 0.0;
    chartInstance->c2_vc_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 179U);
  if (CV_EML_IF(0, 1, 20, !chartInstance->c2_vc_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 180U);
    chartInstance->c2_vc_k_2 = 0.0;
    chartInstance->c2_vc_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 184U);
  if (CV_EML_IF(0, 1, 21, !chartInstance->c2_u_k_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 185U);
    chartInstance->c2_u_k_1 = 0.0;
    chartInstance->c2_u_k_1_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 189U);
  if (CV_EML_IF(0, 1, 22, !chartInstance->c2_u_k_2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 190U);
    chartInstance->c2_u_k_2 = 0.0;
    chartInstance->c2_u_k_2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 194U);
  if (CV_EML_IF(0, 1, 23, !chartInstance->c2_P_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 206U);
    for (c2_i29 = 0; c2_i29 < 36; c2_i29++) {
      chartInstance->c2_P[c2_i29] = c2_dv11[c2_i29];
    }

    chartInstance->c2_P_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 210U);
  if (CV_EML_IF(0, 1, 24, !chartInstance->c2_gama2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 212U);
    chartInstance->c2_gama2 = c2_gama;
    chartInstance->c2_gama2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 219U);
  chartInstance->c2_omega_k[2] = c2_i2_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 220U);
  chartInstance->c2_omega_k[3] = c2_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 225U);
  chartInstance->c2_omega_k[4] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 226U);
  chartInstance->c2_omega_k[5] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 228U);
  for (c2_i30 = 0; c2_i30 < 6; c2_i30++) {
    c2_f_hoistedGlobal[c2_i30] = chartInstance->c2_theta_k[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 6; c2_i31++) {
    c2_g_hoistedGlobal[c2_i31] = chartInstance->c2_omega_k[c2_i31];
  }

  for (c2_i32 = 0; c2_i32 < 6; c2_i32++) {
    c2_a[c2_i32] = c2_f_hoistedGlobal[c2_i32];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_u_k = 0.0;
  c2_eml_int_forloop_overflow_check(chartInstance);
  for (c2_k = 1; c2_k < 7; c2_k++) {
    c2_b_k = c2_k;
    c2_u_k += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c2_b_k), 1, 6, 1, 0) - 1] *
      c2_g_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 231U);
  c2_b = c2_u_k - c2_vc_k;
  c2_y = 3.0 * c2_b;
  c2_h_hoistedGlobal = chartInstance->c2_u_k_1;
  c2_i_hoistedGlobal = chartInstance->c2_vc_k_1;
  c2_b_b = c2_h_hoistedGlobal - c2_i_hoistedGlobal;
  c2_b_y = 3.0 * c2_b_b;
  c2_up_alpha = c2_y - c2_b_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 233U);
  for (c2_i33 = 0; c2_i33 < 6; c2_i33++) {
    c2_f_hoistedGlobal[c2_i33] = chartInstance->c2_eta_k_1[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 6; c2_i34++) {
    c2_f_hoistedGlobal[c2_i34] *= 0.4;
  }

  for (c2_i35 = 0; c2_i35 < 6; c2_i35++) {
    c2_g_hoistedGlobal[c2_i35] = chartInstance->c2_eta_k_2[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 6; c2_i36++) {
    c2_g_hoistedGlobal[c2_i36] *= 0.040000000000000008;
  }

  for (c2_i37 = 0; c2_i37 < 6; c2_i37++) {
    c2_j_hoistedGlobal[c2_i37] = chartInstance->c2_omega_k_2[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 6; c2_i38++) {
    c2_j_hoistedGlobal[c2_i38] *= 0.64000000000000012;
  }

  for (c2_i39 = 0; c2_i39 < 6; c2_i39++) {
    c2_eta_k[c2_i39] = (c2_f_hoistedGlobal[c2_i39] - c2_g_hoistedGlobal[c2_i39])
      + c2_j_hoistedGlobal[c2_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 235U);
  c2_k_hoistedGlobal = chartInstance->c2_i2m_k_1;
  c2_c_b = c2_k_hoistedGlobal;
  c2_c_y = 0.4 * c2_c_b;
  c2_l_hoistedGlobal = chartInstance->c2_i2m_k_2;
  c2_d_b = c2_l_hoistedGlobal;
  c2_d_y = 0.040000000000000008 * c2_d_b;
  c2_m_hoistedGlobal = chartInstance->c2_i2ref_k_2;
  c2_e_b = c2_m_hoistedGlobal;
  c2_e_y = 0.64000000000000012 * c2_e_b;
  c2_i2m_k = (c2_c_y - c2_d_y) + c2_e_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 237U);
  c2_e1_k = c2_i2_k - c2_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 239U);
  c2_n_hoistedGlobal = chartInstance->c2_v_k_1;
  c2_f_b = c2_n_hoistedGlobal;
  c2_f_y = 0.4 * c2_f_b;
  c2_o_hoistedGlobal = chartInstance->c2_v_k_2;
  c2_g_b = c2_o_hoistedGlobal;
  c2_g_y = 0.040000000000000008 * c2_g_b;
  c2_p_hoistedGlobal = chartInstance->c2_u_k_2;
  c2_h_b = c2_p_hoistedGlobal;
  c2_h_y = 0.64000000000000012 * c2_h_b;
  c2_v_k = (c2_f_y - c2_g_y) + c2_h_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 241U);
  for (c2_i40 = 0; c2_i40 < 6; c2_i40++) {
    c2_f_hoistedGlobal[c2_i40] = chartInstance->c2_theta_k[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 6; c2_i41++) {
    c2_a[c2_i41] = c2_f_hoistedGlobal[c2_i41];
  }

  for (c2_i42 = 0; c2_i42 < 6; c2_i42++) {
    c2_j_hoistedGlobal[c2_i42] = c2_eta_k[c2_i42];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_q_k = 0.0;
  c2_eml_int_forloop_overflow_check(chartInstance);
  for (c2_c_k = 1; c2_c_k < 7; c2_c_k++) {
    c2_d_k = c2_c_k;
    c2_q_k += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c2_d_k), 1, 6, 1, 0) - 1] *
      c2_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_d_k), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 243U);
  c2_e2_k = -c2_v_k + c2_q_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 245U);
  c2_q_hoistedGlobal = chartInstance->c2_rho_k;
  c2_b_a = c2_q_hoistedGlobal;
  c2_i_b = c2_e2_k;
  c2_i_y = c2_b_a * c2_i_b;
  c2_ea_k = c2_e1_k + c2_i_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 247U);
  for (c2_i43 = 0; c2_i43 < 6; c2_i43++) {
    c2_eta2_k[c2_i43] = c2_eta_k[c2_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 248U);
  c2_eta2_k[4] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 249U);
  c2_eta2_k[5] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 251U);
  if (CV_EML_IF(0, 1, 25, c2_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 253U);
    for (c2_i44 = 0; c2_i44 < 6; c2_i44++) {
      c2_a[c2_i44] = c2_eta2_k[c2_i44];
    }

    for (c2_i45 = 0; c2_i45 < 6; c2_i45++) {
      c2_a[c2_i45] *= 0.1;
    }

    for (c2_i46 = 0; c2_i46 < 6; c2_i46++) {
      c2_j_hoistedGlobal[c2_i46] = c2_eta2_k[c2_i46];
    }

    c2_b_eml_scalar_eg(chartInstance);
    c2_b_eml_scalar_eg(chartInstance);
    c2_j_y = 0.0;
    c2_eml_int_forloop_overflow_check(chartInstance);
    for (c2_e_k = 1; c2_e_k < 7; c2_e_k++) {
      c2_f_k = c2_e_k;
      c2_j_y += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_f_k), 1, 6, 1, 0) - 1] *
        c2_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_f_k), 1, 6, 1, 0) - 1];
    }

    c2_m2_k = (c2_j_y + c2_mpower(chartInstance, c2_e2_k)) +
      chartInstance->c2_m2;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 256);
    for (c2_i47 = 0; c2_i47 < 6; c2_i47++) {
      c2_a[c2_i47] = c2_eta2_k[c2_i47];
    }

    for (c2_i48 = 0; c2_i48 < 6; c2_i48++) {
      c2_a[c2_i48] *= 0.01;
    }

    for (c2_i49 = 0; c2_i49 < 6; c2_i49++) {
      c2_j_hoistedGlobal[c2_i49] = c2_eta2_k[c2_i49];
    }

    c2_b_eml_scalar_eg(chartInstance);
    c2_b_eml_scalar_eg(chartInstance);
    c2_k_y = 0.0;
    c2_eml_int_forloop_overflow_check(chartInstance);
    for (c2_g_k = 1; c2_g_k < 7; c2_g_k++) {
      c2_h_k = c2_g_k;
      c2_k_y += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_h_k), 1, 6, 1, 0) - 1] *
        c2_j_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_h_k), 1, 6, 1, 0) - 1];
    }

    c2_m2_k = (c2_k_y + c2_mpower(chartInstance, c2_e2_k)) +
      chartInstance->c2_m2;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 259);
  c2_m = c2_m2_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 261);
  for (c2_i50 = 0; c2_i50 < 36; c2_i50++) {
    c2_r_hoistedGlobal[c2_i50] = chartInstance->c2_P[c2_i50];
  }

  for (c2_i51 = 0; c2_i51 < 36; c2_i51++) {
    c2_s_hoistedGlobal[c2_i51] = chartInstance->c2_P[c2_i51];
  }

  for (c2_i52 = 0; c2_i52 < 6; c2_i52++) {
    c2_j_hoistedGlobal[c2_i52] = c2_eta_k[c2_i52];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i53 = 0; c2_i53 < 6; c2_i53++) {
    c2_g_hoistedGlobal[c2_i53] = 0.0;
    c2_i54 = 0;
    for (c2_i55 = 0; c2_i55 < 6; c2_i55++) {
      c2_g_hoistedGlobal[c2_i53] += c2_s_hoistedGlobal[c2_i54 + c2_i53] *
        c2_j_hoistedGlobal[c2_i55];
      c2_i54 += 6;
    }
  }

  for (c2_i56 = 0; c2_i56 < 6; c2_i56++) {
    c2_a[c2_i56] = c2_eta_k[c2_i56];
  }

  c2_i57 = 0;
  for (c2_i58 = 0; c2_i58 < 6; c2_i58++) {
    for (c2_i59 = 0; c2_i59 < 6; c2_i59++) {
      c2_l_y[c2_i59 + c2_i57] = c2_g_hoistedGlobal[c2_i59] * c2_a[c2_i58];
    }

    c2_i57 += 6;
  }

  for (c2_i60 = 0; c2_i60 < 36; c2_i60++) {
    c2_s_hoistedGlobal[c2_i60] = chartInstance->c2_P[c2_i60];
  }

  c2_d_eml_scalar_eg(chartInstance);
  c2_d_eml_scalar_eg(chartInstance);
  for (c2_i61 = 0; c2_i61 < 6; c2_i61++) {
    c2_i62 = 0;
    for (c2_i63 = 0; c2_i63 < 6; c2_i63++) {
      c2_m_y[c2_i62 + c2_i61] = 0.0;
      c2_i64 = 0;
      for (c2_i65 = 0; c2_i65 < 6; c2_i65++) {
        c2_m_y[c2_i62 + c2_i61] += c2_l_y[c2_i64 + c2_i61] *
          c2_s_hoistedGlobal[c2_i65 + c2_i62];
        c2_i64 += 6;
      }

      c2_i62 += 6;
    }
  }

  c2_B = c2_m2_k;
  c2_n_y = c2_B;
  c2_o_y = c2_n_y;
  for (c2_i66 = 0; c2_i66 < 36; c2_i66++) {
    c2_m_y[c2_i66] /= c2_o_y;
  }

  for (c2_i67 = 0; c2_i67 < 36; c2_i67++) {
    chartInstance->c2_P[c2_i67] = c2_r_hoistedGlobal[c2_i67] - c2_m_y[c2_i67];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 262);
  c2_t_hoistedGlobal = chartInstance->c2_gama2;
  c2_u_hoistedGlobal = chartInstance->c2_gama2;
  c2_c_a = c2_mpower(chartInstance, c2_u_hoistedGlobal);
  c2_j_b = c2_mpower(chartInstance, c2_e2_k);
  c2_p_y = c2_c_a * c2_j_b;
  c2_A = c2_p_y;
  c2_b_B = c2_mpower(chartInstance, c2_m2_k);
  c2_x = c2_A;
  c2_q_y = c2_b_B;
  c2_b_x = c2_x;
  c2_r_y = c2_q_y;
  c2_s_y = c2_b_x / c2_r_y;
  chartInstance->c2_gama2 = c2_t_hoistedGlobal - c2_s_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 270);
  for (c2_i68 = 0; c2_i68 < 6; c2_i68++) {
    c2_f_hoistedGlobal[c2_i68] = chartInstance->c2_theta_k[c2_i68];
  }

  c2_k_b = c2_ea_k;
  c2_t_y = 0.0098 * c2_k_b;
  c2_b_A = c2_t_y;
  c2_c_B = c2_m2_k;
  c2_c_x = c2_b_A;
  c2_u_y = c2_c_B;
  c2_d_x = c2_c_x;
  c2_v_y = c2_u_y;
  c2_w_y = c2_d_x / c2_v_y;
  c2_d_a = c2_w_y;
  for (c2_i69 = 0; c2_i69 < 6; c2_i69++) {
    c2_j_hoistedGlobal[c2_i69] = c2_eta_k[c2_i69];
  }

  for (c2_i70 = 0; c2_i70 < 6; c2_i70++) {
    c2_j_hoistedGlobal[c2_i70] *= c2_d_a;
  }

  for (c2_i71 = 0; c2_i71 < 6; c2_i71++) {
    chartInstance->c2_theta_k[c2_i71] = c2_f_hoistedGlobal[c2_i71] -
      c2_j_hoistedGlobal[c2_i71];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 272);
  for (c2_i72 = 0; c2_i72 < 6; c2_i72++) {
    c2_theta_alpha[c2_i72] = chartInstance->c2_theta_k[c2_i72];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 275);
  c2_v_hoistedGlobal = chartInstance->c2_rho_k;
  c2_l_b = c2_ea_k;
  c2_x_y = 0.99 * c2_l_b;
  c2_e_a = c2_x_y;
  c2_m_b = c2_e2_k;
  c2_y_y = c2_e_a * c2_m_b;
  c2_c_A = c2_y_y;
  c2_d_B = c2_m2_k;
  c2_e_x = c2_c_A;
  c2_ab_y = c2_d_B;
  c2_f_x = c2_e_x;
  c2_bb_y = c2_ab_y;
  c2_cb_y = c2_f_x / c2_bb_y;
  chartInstance->c2_rho_k = c2_v_hoistedGlobal - c2_cb_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 277);
  if (CV_EML_IF(0, 1, 26, c2_flag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 279);
    c2_w_hoistedGlobal = chartInstance->c2_m2;
    c2_n_b = c2_w_hoistedGlobal - 1.0;
    c2_db_y = 0.99 * c2_n_b;
    chartInstance->c2_m2 = ((c2_db_y + c2_abs(chartInstance, c2_u_k)) + c2_abs
      (chartInstance, c2_i2_k)) + 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 282);
    c2_x_hoistedGlobal = chartInstance->c2_m2;
    c2_o_b = c2_x_hoistedGlobal - 1.0;
    c2_eb_y = 0.99 * c2_o_b;
    chartInstance->c2_m2 = ((c2_eb_y + c2_abs(chartInstance, c2_u_k)) + c2_abs
      (chartInstance, c2_i2_k)) + 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 285);
  for (c2_i73 = 0; c2_i73 < 6; c2_i73++) {
    chartInstance->c2_omega_k_3[c2_i73] = chartInstance->c2_omega_k_2[c2_i73];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 286);
  for (c2_i74 = 0; c2_i74 < 6; c2_i74++) {
    chartInstance->c2_omega_k_2[c2_i74] = chartInstance->c2_omega_k_1[c2_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 287);
  for (c2_i75 = 0; c2_i75 < 6; c2_i75++) {
    chartInstance->c2_omega_k_1[c2_i75] = chartInstance->c2_omega_k[c2_i75];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 289);
  for (c2_i76 = 0; c2_i76 < 6; c2_i76++) {
    c2_f_hoistedGlobal[c2_i76] = chartInstance->c2_omega_k[c2_i76];
  }

  c2_p_b = c2_f_hoistedGlobal[0];
  c2_fb_y = 0.0 * c2_p_b;
  c2_q_b = c2_u_k;
  c2_gb_y = c2_q_b;
  chartInstance->c2_omega_k[0] = c2_fb_y + c2_gb_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 290);
  for (c2_i77 = 0; c2_i77 < 6; c2_i77++) {
    c2_f_hoistedGlobal[c2_i77] = chartInstance->c2_omega_k[c2_i77];
  }

  c2_r_b = c2_f_hoistedGlobal[1];
  c2_hb_y = 0.0 * c2_r_b;
  c2_s_b = c2_i2_k;
  c2_ib_y = c2_s_b;
  chartInstance->c2_omega_k[1] = c2_hb_y + c2_ib_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 292);
  for (c2_i78 = 0; c2_i78 < 6; c2_i78++) {
    chartInstance->c2_eta_k_3[c2_i78] = chartInstance->c2_eta_k_2[c2_i78];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 293);
  for (c2_i79 = 0; c2_i79 < 6; c2_i79++) {
    chartInstance->c2_eta_k_2[c2_i79] = chartInstance->c2_eta_k_1[c2_i79];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 294);
  for (c2_i80 = 0; c2_i80 < 6; c2_i80++) {
    chartInstance->c2_eta_k_1[c2_i80] = c2_eta_k[c2_i80];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 296);
  chartInstance->c2_i2ref_k_3 = chartInstance->c2_i2ref_k_2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 297);
  chartInstance->c2_i2ref_k_2 = chartInstance->c2_i2ref_k_1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 298);
  chartInstance->c2_i2ref_k_1 = c2_i2ref_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 300);
  chartInstance->c2_i2m_k_3 = chartInstance->c2_i2m_k_2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 301);
  chartInstance->c2_i2m_k_2 = chartInstance->c2_i2m_k_1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 302);
  chartInstance->c2_i2m_k_1 = c2_i2m_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 304);
  chartInstance->c2_v_k_3 = chartInstance->c2_v_k_2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 305);
  chartInstance->c2_v_k_2 = chartInstance->c2_v_k_1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 306);
  chartInstance->c2_v_k_1 = c2_v_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 308);
  chartInstance->c2_u_k_2 = chartInstance->c2_u_k_1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 309);
  chartInstance->c2_u_k_1 = c2_u_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 311);
  chartInstance->c2_vc_k_2 = chartInstance->c2_vc_k_1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 312);
  chartInstance->c2_vc_k_1 = c2_vc_k;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -312);
  sf_debug_symbol_scope_pop();
  *c2_b_up_alpha = c2_up_alpha;
  for (c2_i81 = 0; c2_i81 < 6; c2_i81++) {
    (*c2_b_theta_alpha)[c2_i81] = c2_theta_alpha[c2_i81];
  }

  *c2_b_m = c2_m;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_vC_1ph_MR2(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_gama2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_gama2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_gama2), &c2_thisId);
  sf_mex_destroy(&c2_b_gama2);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_gama2_not_empty = FALSE;
  } else {
    chartInstance->c2_gama2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_gama2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_gama2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_gama2), &c2_thisId);
  sf_mex_destroy(&c2_b_gama2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  real_T c2_b_inData[36];
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  real_T c2_u[36];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i82 = 0;
  for (c2_i83 = 0; c2_i83 < 6; c2_i83++) {
    for (c2_i84 = 0; c2_i84 < 6; c2_i84++) {
      c2_b_inData[c2_i84 + c2_i82] = (*(real_T (*)[36])c2_inData)[c2_i84 +
        c2_i82];
    }

    c2_i82 += 6;
  }

  c2_i85 = 0;
  for (c2_i86 = 0; c2_i86 < 6; c2_i86++) {
    for (c2_i87 = 0; c2_i87 < 6; c2_i87++) {
      c2_u[c2_i87 + c2_i85] = c2_b_inData[c2_i87 + c2_i85];
    }

    c2_i85 += 6;
  }

  c2_y = NULL;
  if (!chartInstance->c2_P_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_P, const char_T *c2_identifier, real_T c2_y[36])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_P);
}

static void c2_d_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[36])
{
  real_T c2_dv12[36];
  int32_T c2_i88;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_P_not_empty = FALSE;
  } else {
    chartInstance->c2_P_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 2, 6,
                  6);
    for (c2_i88 = 0; c2_i88 < 36; c2_i88++) {
      c2_y[c2_i88] = c2_dv12[c2_i88];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[36];
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_P);
  c2_i89 = 0;
  for (c2_i90 = 0; c2_i90 < 6; c2_i90++) {
    for (c2_i91 = 0; c2_i91 < 6; c2_i91++) {
      (*(real_T (*)[36])c2_outData)[c2_i91 + c2_i89] = c2_y[c2_i91 + c2_i89];
    }

    c2_i89 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_u_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_u_k_2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u_k_2), &c2_thisId);
  sf_mex_destroy(&c2_b_u_k_2);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_u_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_u_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_u_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u_k_2), &c2_thisId);
  sf_mex_destroy(&c2_b_u_k_2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_u_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_u_k_1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u_k_1), &c2_thisId);
  sf_mex_destroy(&c2_b_u_k_1);
  return c2_y;
}

static real_T c2_h_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_u_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_u_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_u_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u_k_1), &c2_thisId);
  sf_mex_destroy(&c2_b_u_k_1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_vc_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_i_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_vc_k_2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vc_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vc_k_2);
  return c2_y;
}

static real_T c2_j_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_vc_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_vc_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d3;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_vc_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_vc_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vc_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vc_k_2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_vc_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_k_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_vc_k_1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vc_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vc_k_1);
  return c2_y;
}

static real_T c2_l_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_vc_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_vc_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d4;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_vc_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_vc_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vc_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vc_k_1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_m2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_m_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_m2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_m2), &c2_thisId);
  sf_mex_destroy(&c2_b_m2);
  return c2_y;
}

static real_T c2_n_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d5;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_m2_not_empty = FALSE;
  } else {
    chartInstance->c2_m2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d5, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d5;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_m2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_m2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_m2), &c2_thisId);
  sf_mex_destroy(&c2_b_m2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_rho_k_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_o_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_rho_k, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rho_k), &c2_thisId);
  sf_mex_destroy(&c2_b_rho_k);
  return c2_y;
}

static real_T c2_p_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d6;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_rho_k_not_empty = FALSE;
  } else {
    chartInstance->c2_rho_k_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d6, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d6;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_rho_k;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_rho_k = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rho_k), &c2_thisId);
  sf_mex_destroy(&c2_b_rho_k);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_v_k_3_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_q_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_3, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_3), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_3);
  return c2_y;
}

static real_T c2_r_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d7;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_v_k_3_not_empty = FALSE;
  } else {
    chartInstance->c2_v_k_3_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d7, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d7;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_v_k_3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_v_k_3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_3), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_3);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_v_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_s_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_2), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_2);
  return c2_y;
}

static real_T c2_t_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d8;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_v_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_v_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d8, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d8;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_v_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_v_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_2), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_v_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_u_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_v_k_1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_1), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_1);
  return c2_y;
}

static real_T c2_v_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d9;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_v_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_v_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d9, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d9;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_v_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_v_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_v_k_1), &c2_thisId);
  sf_mex_destroy(&c2_b_v_k_1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2ref_k_3_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_w_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_i2ref_k_3, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_3),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_3);
  return c2_y;
}

static real_T c2_x_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d10;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2ref_k_3_not_empty = FALSE;
  } else {
    chartInstance->c2_i2ref_k_3_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d10, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d10;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2ref_k_3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2ref_k_3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_3),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_3);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2ref_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_y_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_i2ref_k_2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_2);
  return c2_y;
}

static real_T c2_ab_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d11;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2ref_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_i2ref_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d11, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d11;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2ref_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2ref_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2ref_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_bb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2ref_k_1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_1);
  return c2_y;
}

static real_T c2_cb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d12;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2ref_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_i2ref_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d12, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d12;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2ref_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2ref_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2ref_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2ref_k_1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2m_k_3_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_db_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_3, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_3),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_3);
  return c2_y;
}

static real_T c2_eb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d13;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2m_k_3_not_empty = FALSE;
  } else {
    chartInstance->c2_i2m_k_3_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d13, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d13;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2m_k_3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2m_k_3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_3),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_3);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2m_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_fb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_2);
  return c2_y;
}

static real_T c2_gb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d14;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2m_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_i2m_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d14, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d14;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2m_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2m_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i2m_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_hb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_i2m_k_1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_1);
  return c2_y;
}

static real_T c2_ib_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d15;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i2m_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_i2m_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d15, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d15;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i2m_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_i2m_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i2m_k_1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_i2m_k_1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i92;
  real_T c2_b_inData[6];
  int32_T c2_i93;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i92 = 0; c2_i92 < 6; c2_i92++) {
    c2_b_inData[c2_i92] = (*(real_T (*)[6])c2_inData)[c2_i92];
  }

  for (c2_i93 = 0; c2_i93 < 6; c2_i93++) {
    c2_u[c2_i93] = c2_b_inData[c2_i93];
  }

  c2_y = NULL;
  if (!chartInstance->c2_eta_k_3_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_jb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_3, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_3), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_3);
}

static void c2_kb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv13[6];
  int32_T c2_i94;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_eta_k_3_not_empty = FALSE;
  } else {
    chartInstance->c2_eta_k_3_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv13, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i94 = 0; c2_i94 < 6; c2_i94++) {
      c2_y[c2_i94] = c2_dv13[c2_i94];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_eta_k_3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i95;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_eta_k_3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_3), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_3);
  for (c2_i95 = 0; c2_i95 < 6; c2_i95++) {
    (*(real_T (*)[6])c2_outData)[c2_i95] = c2_y[c2_i95];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i96;
  real_T c2_b_inData[6];
  int32_T c2_i97;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i96 = 0; c2_i96 < 6; c2_i96++) {
    c2_b_inData[c2_i96] = (*(real_T (*)[6])c2_inData)[c2_i96];
  }

  for (c2_i97 = 0; c2_i97 < 6; c2_i97++) {
    c2_u[c2_i97] = c2_b_inData[c2_i97];
  }

  c2_y = NULL;
  if (!chartInstance->c2_eta_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_lb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_2, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_2), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_2);
}

static void c2_mb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv14[6];
  int32_T c2_i98;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_eta_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_eta_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv14, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i98 = 0; c2_i98 < 6; c2_i98++) {
      c2_y[c2_i98] = c2_dv14[c2_i98];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_eta_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i99;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_eta_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_2), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_2);
  for (c2_i99 = 0; c2_i99 < 6; c2_i99++) {
    (*(real_T (*)[6])c2_outData)[c2_i99] = c2_y[c2_i99];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i100;
  real_T c2_b_inData[6];
  int32_T c2_i101;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i100 = 0; c2_i100 < 6; c2_i100++) {
    c2_b_inData[c2_i100] = (*(real_T (*)[6])c2_inData)[c2_i100];
  }

  for (c2_i101 = 0; c2_i101 < 6; c2_i101++) {
    c2_u[c2_i101] = c2_b_inData[c2_i101];
  }

  c2_y = NULL;
  if (!chartInstance->c2_eta_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_nb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_eta_k_1, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_1), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_1);
}

static void c2_ob_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv15[6];
  int32_T c2_i102;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_eta_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_eta_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv15, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i102 = 0; c2_i102 < 6; c2_i102++) {
      c2_y[c2_i102] = c2_dv15[c2_i102];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_eta_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i103;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_eta_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_eta_k_1), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_eta_k_1);
  for (c2_i103 = 0; c2_i103 < 6; c2_i103++) {
    (*(real_T (*)[6])c2_outData)[c2_i103] = c2_y[c2_i103];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i104;
  real_T c2_b_inData[6];
  int32_T c2_i105;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i104 = 0; c2_i104 < 6; c2_i104++) {
    c2_b_inData[c2_i104] = (*(real_T (*)[6])c2_inData)[c2_i104];
  }

  for (c2_i105 = 0; c2_i105 < 6; c2_i105++) {
    c2_u[c2_i105] = c2_b_inData[c2_i105];
  }

  c2_y = NULL;
  if (!chartInstance->c2_omega_k_3_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_pb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_3, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_3), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_3);
}

static void c2_qb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv16[6];
  int32_T c2_i106;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_omega_k_3_not_empty = FALSE;
  } else {
    chartInstance->c2_omega_k_3_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv16, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i106 = 0; c2_i106 < 6; c2_i106++) {
      c2_y[c2_i106] = c2_dv16[c2_i106];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_omega_k_3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i107;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_omega_k_3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_3), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_3);
  for (c2_i107 = 0; c2_i107 < 6; c2_i107++) {
    (*(real_T (*)[6])c2_outData)[c2_i107] = c2_y[c2_i107];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i108;
  real_T c2_b_inData[6];
  int32_T c2_i109;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i108 = 0; c2_i108 < 6; c2_i108++) {
    c2_b_inData[c2_i108] = (*(real_T (*)[6])c2_inData)[c2_i108];
  }

  for (c2_i109 = 0; c2_i109 < 6; c2_i109++) {
    c2_u[c2_i109] = c2_b_inData[c2_i109];
  }

  c2_y = NULL;
  if (!chartInstance->c2_omega_k_2_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_rb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_2, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_2), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_2);
}

static void c2_sb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv17[6];
  int32_T c2_i110;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_omega_k_2_not_empty = FALSE;
  } else {
    chartInstance->c2_omega_k_2_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv17, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i110 = 0; c2_i110 < 6; c2_i110++) {
      c2_y[c2_i110] = c2_dv17[c2_i110];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_omega_k_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i111;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_omega_k_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_2), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_2);
  for (c2_i111 = 0; c2_i111 < 6; c2_i111++) {
    (*(real_T (*)[6])c2_outData)[c2_i111] = c2_y[c2_i111];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_w_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i112;
  real_T c2_b_inData[6];
  int32_T c2_i113;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i112 = 0; c2_i112 < 6; c2_i112++) {
    c2_b_inData[c2_i112] = (*(real_T (*)[6])c2_inData)[c2_i112];
  }

  for (c2_i113 = 0; c2_i113 < 6; c2_i113++) {
    c2_u[c2_i113] = c2_b_inData[c2_i113];
  }

  c2_y = NULL;
  if (!chartInstance->c2_omega_k_1_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_tb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k_1, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_1), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_1);
}

static void c2_ub_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv18[6];
  int32_T c2_i114;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_omega_k_1_not_empty = FALSE;
  } else {
    chartInstance->c2_omega_k_1_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv18, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i114 = 0; c2_i114 < 6; c2_i114++) {
      c2_y[c2_i114] = c2_dv18[c2_i114];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_omega_k_1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i115;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_omega_k_1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k_1), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k_1);
  for (c2_i115 = 0; c2_i115 < 6; c2_i115++) {
    (*(real_T (*)[6])c2_outData)[c2_i115] = c2_y[c2_i115];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_x_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i116;
  real_T c2_b_inData[6];
  int32_T c2_i117;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i116 = 0; c2_i116 < 6; c2_i116++) {
    c2_b_inData[c2_i116] = (*(real_T (*)[6])c2_inData)[c2_i116];
  }

  for (c2_i117 = 0; c2_i117 < 6; c2_i117++) {
    c2_u[c2_i117] = c2_b_inData[c2_i117];
  }

  c2_y = NULL;
  if (!chartInstance->c2_omega_k_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_vb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_omega_k, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k);
}

static void c2_wb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv19[6];
  int32_T c2_i118;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_omega_k_not_empty = FALSE;
  } else {
    chartInstance->c2_omega_k_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv19, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i118 = 0; c2_i118 < 6; c2_i118++) {
      c2_y[c2_i118] = c2_dv19[c2_i118];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_omega_k;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i119;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_omega_k = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega_k), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_omega_k);
  for (c2_i119 = 0; c2_i119 < 6; c2_i119++) {
    (*(real_T (*)[6])c2_outData)[c2_i119] = c2_y[c2_i119];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_y_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i120;
  real_T c2_b_inData[6];
  int32_T c2_i121;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i120 = 0; c2_i120 < 6; c2_i120++) {
    c2_b_inData[c2_i120] = (*(real_T (*)[6])c2_inData)[c2_i120];
  }

  for (c2_i121 = 0; c2_i121 < 6; c2_i121++) {
    c2_u[c2_i121] = c2_b_inData[c2_i121];
  }

  c2_y = NULL;
  if (!chartInstance->c2_theta_k_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_xb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_b_theta_k, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_theta_k), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_theta_k);
}

static void c2_yb_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv20[6];
  int32_T c2_i122;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_theta_k_not_empty = FALSE;
  } else {
    chartInstance->c2_theta_k_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv20, 1, 0, 0U, 1, 0U, 1, 6);
    for (c2_i122 = 0; c2_i122 < 6; c2_i122++) {
      c2_y[c2_i122] = c2_dv20[c2_i122];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_theta_k;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i123;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_theta_k = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_theta_k), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_b_theta_k);
  for (c2_i123 = 0; c2_i123 < 6; c2_i123++) {
    (*(real_T (*)[6])c2_outData)[c2_i123] = c2_y[c2_i123];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_ac_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_m, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_m), &c2_thisId);
  sf_mex_destroy(&c2_m);
  return c2_y;
}

static real_T c2_bc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d16;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d16, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d16;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_m;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_m = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_m), &c2_thisId);
  sf_mex_destroy(&c2_m);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i124;
  real_T c2_b_inData[6];
  int32_T c2_i125;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i124 = 0; c2_i124 < 6; c2_i124++) {
    c2_b_inData[c2_i124] = (*(real_T (*)[6])c2_inData)[c2_i124];
  }

  for (c2_i125 = 0; c2_i125 < 6; c2_i125++) {
    c2_u[c2_i125] = c2_b_inData[c2_i125];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_cc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_theta_alpha, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_dc_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta_alpha), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_theta_alpha);
}

static void c2_dc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv21[6];
  int32_T c2_i126;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv21, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i126 = 0; c2_i126 < 6; c2_i126++) {
    c2_y[c2_i126] = c2_dv21[c2_i126];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_theta_alpha;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i127;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_theta_alpha = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_dc_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta_alpha), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_theta_alpha);
  for (c2_i127 = 0; c2_i127 < 6; c2_i127++) {
    (*(real_T (*)[6])c2_outData)[c2_i127] = c2_y[c2_i127];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_vC_1ph_MR2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[52];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i128;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52), FALSE);
  for (c2_i128 = 0; c2_i128 < 52; c2_i128++) {
    c2_r0 = &c2_info[c2_i128];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i128);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i128);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[52])
{
  c2_info[0].context = "";
  c2_info[0].name = "mtimes";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[0].fileTimeLo = 1289523292U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "mrdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].fileTimeLo = 1325127738U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 1319737166U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[2].name = "rdivide";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].fileTimeLo = 1286826044U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[3].name = "eml_div";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[3].fileTimeLo = 1313355010U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "sqrt";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[4].fileTimeLo = 1286825952U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[5].name = "eml_error";
  c2_info[5].dominantType = "char";
  c2_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[5].fileTimeLo = 1305325200U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[6].name = "eml_scalar_sqrt";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[6].fileTimeLo = 1286825938U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "eye";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m";
  c2_info[7].fileTimeLo = 1286825888U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[8].name = "eml_assert_valid_size_arg";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[8].fileTimeLo = 1286825894U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[9].name = "isinf";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[9].fileTimeLo = 1286825960U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c2_info[10].name = "mtimes";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].fileTimeLo = 1289523292U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[11].name = "eml_index_class";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[11].fileTimeLo = 1286825978U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[12].name = "intmax";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[12].fileTimeLo = 1311262516U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[13].name = "eml_is_float_class";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[13].fileTimeLo = 1286825982U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[14].name = "min";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[14].fileTimeLo = 1311262518U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[15].name = "eml_min_or_max";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[15].fileTimeLo = 1303153412U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileTimeLo = 1286825996U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[17].name = "eml_scalexp_alloc";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[17].fileTimeLo = 1286825996U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[18].name = "eml_index_class";
  c2_info[18].dominantType = "";
  c2_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[18].fileTimeLo = 1286825978U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[19].name = "eml_scalar_eg";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[19].fileTimeLo = 1286825996U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[20].name = "eml_index_class";
  c2_info[20].dominantType = "";
  c2_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[20].fileTimeLo = 1286825978U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[21].name = "eml_int_forloop_overflow_check";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[21].fileTimeLo = 1311262516U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[22].name = "intmax";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[22].fileTimeLo = 1311262516U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[23].name = "eml_index_class";
  c2_info[23].dominantType = "";
  c2_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[23].fileTimeLo = 1286825978U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[24].name = "eml_scalar_eg";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[24].fileTimeLo = 1286825996U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[25].name = "eml_xdotu";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[25].fileTimeLo = 1299080372U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[26].name = "eml_blas_inline";
  c2_info[26].dominantType = "";
  c2_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[26].fileTimeLo = 1299080368U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[27].name = "eml_xdot";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[27].fileTimeLo = 1299080372U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[28].name = "eml_blas_inline";
  c2_info[28].dominantType = "";
  c2_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[28].fileTimeLo = 1299080368U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[29].name = "eml_refblas_xdot";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[29].fileTimeLo = 1299080372U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[30].name = "eml_refblas_xdotx";
  c2_info[30].dominantType = "int32";
  c2_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[30].fileTimeLo = 1299080374U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[31].name = "eml_scalar_eg";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[31].fileTimeLo = 1286825996U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[32].name = "eml_index_class";
  c2_info[32].dominantType = "";
  c2_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[32].fileTimeLo = 1286825978U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[33].name = "eml_index_minus";
  c2_info[33].dominantType = "int32";
  c2_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[33].fileTimeLo = 1286825978U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[34].name = "eml_index_class";
  c2_info[34].dominantType = "";
  c2_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[34].fileTimeLo = 1286825978U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[35].name = "eml_index_times";
  c2_info[35].dominantType = "int32";
  c2_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[35].fileTimeLo = 1286825980U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[36].name = "eml_index_class";
  c2_info[36].dominantType = "";
  c2_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[36].fileTimeLo = 1286825978U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[37].name = "eml_index_plus";
  c2_info[37].dominantType = "int32";
  c2_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[37].fileTimeLo = 1286825978U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[38].name = "eml_index_class";
  c2_info[38].dominantType = "";
  c2_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[38].fileTimeLo = 1286825978U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[39].name = "eml_int_forloop_overflow_check";
  c2_info[39].dominantType = "";
  c2_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[39].fileTimeLo = 1311262516U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context = "";
  c2_info[40].name = "mpower";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[40].fileTimeLo = 1286826042U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[41].name = "power";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[41].fileTimeLo = 1307658440U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[42].name = "eml_scalar_eg";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[42].fileTimeLo = 1286825996U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[43].name = "eml_scalexp_alloc";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[43].fileTimeLo = 1286825996U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[44].name = "eml_scalar_floor";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[44].fileTimeLo = 1286825926U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[45].name = "eml_xgemm";
  c2_info[45].dominantType = "int32";
  c2_info[45].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[45].fileTimeLo = 1299080372U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[46].name = "eml_blas_inline";
  c2_info[46].dominantType = "";
  c2_info[46].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[46].fileTimeLo = 1299080368U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[47].name = "mtimes";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[47].fileTimeLo = 1289523292U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[48].name = "eml_scalar_eg";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[48].fileTimeLo = 1286825996U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[49].name = "eml_refblas_xgemm";
  c2_info[49].dominantType = "int32";
  c2_info[49].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[49].fileTimeLo = 1299080374U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context = "";
  c2_info[50].name = "abs";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[50].fileTimeLo = 1286825894U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[51].name = "eml_scalar_abs";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[51].fileTimeLo = 1286825912U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
}

static real_T c2_sqrt(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
  int32_T c2_i129;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i129 = 0; c2_i129 < 30; c2_i129++) {
    c2_u[c2_i129] = c2_varargin_1[c2_i129];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

static void c2_eml_int_forloop_overflow_check(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c2_mpower(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_c_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

static void c2_d_eml_scalar_eg(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

static real_T c2_abs(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static const mxArray *c2_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_ec_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i130;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i130, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i130;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_cb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ec_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_fc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_vC_1ph_MR2, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_gc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_vC_1ph_MR2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_vC_1ph_MR2);
  return c2_y;
}

static uint8_T c2_gc_emlrt_marshallIn(SFc2_vC_1ph_MR2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_vC_1ph_MR2InstanceStruct *chartInstance, real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void init_dsm_address_info(SFc2_vC_1ph_MR2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_vC_1ph_MR2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1896012224U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1434100887U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3154831389U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3285679117U);
}

mxArray *sf_c2_vC_1ph_MR2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("h8hq034zOMKrOHwl3TViz");
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

static const mxArray *sf_get_sim_state_info_c2_vC_1ph_MR2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[17],T\"m\",},{M[1],M[16],T\"theta_alpha\",},{M[1],M[5],T\"up_alpha\",},{M[4],M[0],T\"P\",S'l','i','p'{{M1x2[3461 3462],M[0],}}},{M[4],M[0],T\"eta_k_1\",S'l','i','p'{{M1x2[2329 2336],M[0],}}},{M[4],M[0],T\"eta_k_2\",S'l','i','p'{{M1x2[2418 2425],M[0],}}},{M[4],M[0],T\"eta_k_3\",S'l','i','p'{{M1x2[2507 2514],M[0],}}},{M[4],M[0],T\"gama2\",S'l','i','p'{{M1x2[4664 4669],M[0],}}},{M[4],M[0],T\"i2m_k_1\",S'l','i','p'{{M1x2[2596 2603],M[0],}}},{M[4],M[0],T\"i2m_k_2\",S'l','i','p'{{M1x2[2656 2663],M[0],}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"i2m_k_3\",S'l','i','p'{{M1x2[2716 2723],M[0],}}},{M[4],M[0],T\"i2ref_k_1\",S'l','i','p'{{M1x2[2776 2785],M[0],}}},{M[4],M[0],T\"i2ref_k_2\",S'l','i','p'{{M1x2[2842 2851],M[0],}}},{M[4],M[0],T\"i2ref_k_3\",S'l','i','p'{{M1x2[2908 2917],M[0],}}},{M[4],M[0],T\"m2\",S'l','i','p'{{M1x2[3194 3196],M[0],}}},{M[4],M[0],T\"omega_k\",S'l','i','p'{{M1x2[1955 1962],M[0],}}},{M[4],M[0],T\"omega_k_1\",S'l','i','p'{{M1x2[2044 2053],M[0],}}},{M[4],M[0],T\"omega_k_2\",S'l','i','p'{{M1x2[2139 2148],M[0],}}},{M[4],M[0],T\"omega_k_3\",S'l','i','p'{{M1x2[2234 2243],M[0],}}},{M[4],M[0],T\"rho_k\",S'l','i','p'{{M1x2[3136 3141],M[0],}}}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[4],M[0],T\"theta_k\",S'l','i','p'{{M1x2[1185 1192],M[0],}}},{M[4],M[0],T\"u_k_1\",S'l','i','p'{{M1x2[3353 3358],M[0],}}},{M[4],M[0],T\"u_k_2\",S'l','i','p'{{M1x2[3407 3412],M[0],}}},{M[4],M[0],T\"v_k_1\",S'l','i','p'{{M1x2[2974 2979],M[0],}}},{M[4],M[0],T\"v_k_2\",S'l','i','p'{{M1x2[3028 3033],M[0],}}},{M[4],M[0],T\"v_k_3\",S'l','i','p'{{M1x2[3082 3087],M[0],}}},{M[4],M[0],T\"vc_k_1\",S'l','i','p'{{M1x2[3239 3245],M[0],}}},{M[4],M[0],T\"vc_k_2\",S'l','i','p'{{M1x2[3296 3302],M[0],}}},{M[8],M[0],T\"is_active_c2_vC_1ph_MR2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 29, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_vC_1ph_MR2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
    chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_vC_1ph_MR2MachineNumber_,
           2,
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
          init_script_number_translation(_vC_1ph_MR2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_vC_1ph_MR2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_vC_1ph_MR2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"i2ref_k");
          _SFD_SET_DATA_PROPS(1,2,0,1,"up_alpha");
          _SFD_SET_DATA_PROPS(2,1,1,0,"i2_k");
          _SFD_SET_DATA_PROPS(3,1,1,0,"vc_k");
          _SFD_SET_DATA_PROPS(4,1,1,0,"flag");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t");
          _SFD_SET_DATA_PROPS(6,2,0,1,"theta_alpha");
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
        _SFD_CV_INIT_EML(0,1,1,27,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6568);
        _SFD_CV_INIT_EML_IF(0,1,0,1194,1213,-1,1942);
        _SFD_CV_INIT_EML_IF(0,1,1,1964,1983,-1,2031);
        _SFD_CV_INIT_EML_IF(0,1,2,2055,2076,-1,2126);
        _SFD_CV_INIT_EML_IF(0,1,3,2150,2171,-1,2221);
        _SFD_CV_INIT_EML_IF(0,1,4,2245,2266,-1,2316);
        _SFD_CV_INIT_EML_IF(0,1,5,2338,2357,-1,2405);
        _SFD_CV_INIT_EML_IF(0,1,6,2427,2446,-1,2494);
        _SFD_CV_INIT_EML_IF(0,1,7,2516,2535,-1,2583);
        _SFD_CV_INIT_EML_IF(0,1,8,2605,2624,-1,2643);
        _SFD_CV_INIT_EML_IF(0,1,9,2665,2684,-1,2703);
        _SFD_CV_INIT_EML_IF(0,1,10,2725,2744,-1,2763);
        _SFD_CV_INIT_EML_IF(0,1,11,2787,2808,-1,2829);
        _SFD_CV_INIT_EML_IF(0,1,12,2853,2874,-1,2895);
        _SFD_CV_INIT_EML_IF(0,1,13,2919,2940,-1,2961);
        _SFD_CV_INIT_EML_IF(0,1,14,2981,2998,-1,3015);
        _SFD_CV_INIT_EML_IF(0,1,15,3035,3052,-1,3069);
        _SFD_CV_INIT_EML_IF(0,1,16,3089,3106,-1,3123);
        _SFD_CV_INIT_EML_IF(0,1,17,3143,3160,-1,3181);
        _SFD_CV_INIT_EML_IF(0,1,18,3198,3212,-1,3226);
        _SFD_CV_INIT_EML_IF(0,1,19,3247,3265,-1,3283);
        _SFD_CV_INIT_EML_IF(0,1,20,3304,3322,-1,3340);
        _SFD_CV_INIT_EML_IF(0,1,21,3360,3377,-1,3394);
        _SFD_CV_INIT_EML_IF(0,1,22,3414,3431,-1,3448);
        _SFD_CV_INIT_EML_IF(0,1,23,3464,3477,-1,4651);
        _SFD_CV_INIT_EML_IF(0,1,24,4671,4688,-1,4738);
        _SFD_CV_INIT_EML_IF(0,1,25,5380,5390,5479,5571);
        _SFD_CV_INIT_EML_IF(0,1,26,5936,5946,6054,6173);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)
          c2_ab_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_bb_sf_marshallOut,(MexInFcnForType)
            c2_bb_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ab_sf_marshallOut,(MexInFcnForType)
          c2_ab_sf_marshallIn);

        {
          real_T *c2_i2ref_k;
          real_T *c2_up_alpha;
          real_T *c2_i2_k;
          real_T *c2_vc_k;
          real_T *c2_flag;
          real_T *c2_t;
          real_T *c2_m;
          real_T (*c2_theta_alpha)[6];
          c2_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_theta_alpha = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            2);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_vc_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_i2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_up_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_i2ref_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_i2ref_k);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_up_alpha);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_i2_k);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_vc_k);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_flag);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_theta_alpha);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_vC_1ph_MR2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "VKoK5L1VxRifGkn416PjxC";
}

static void sf_opaque_initialize_c2_vC_1ph_MR2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_vC_1ph_MR2(void *chartInstanceVar)
{
  enable_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_vC_1ph_MR2(void *chartInstanceVar)
{
  disable_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_vC_1ph_MR2(void *chartInstanceVar)
{
  sf_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_vC_1ph_MR2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_vC_1ph_MR2
    ((SFc2_vC_1ph_MR2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_vC_1ph_MR2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_vC_1ph_MR2(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_vC_1ph_MR2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_vC_1ph_MR2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_vC_1ph_MR2(S);
}

static void sf_opaque_set_sim_state_c2_vC_1ph_MR2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_vC_1ph_MR2(S, st);
}

static void sf_opaque_terminate_c2_vC_1ph_MR2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_vC_1ph_MR2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_vC_1ph_MR2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_vC_1ph_MR2((SFc2_vC_1ph_MR2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_vC_1ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vC_1ph_MR2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3849793501U));
  ssSetChecksum1(S,(3757179208U));
  ssSetChecksum2(S,(848639644U));
  ssSetChecksum3(S,(4206460344U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_vC_1ph_MR2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_vC_1ph_MR2(SimStruct *S)
{
  SFc2_vC_1ph_MR2InstanceStruct *chartInstance;
  chartInstance = (SFc2_vC_1ph_MR2InstanceStruct *)malloc(sizeof
    (SFc2_vC_1ph_MR2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_vC_1ph_MR2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_vC_1ph_MR2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_vC_1ph_MR2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_vC_1ph_MR2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_vC_1ph_MR2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_vC_1ph_MR2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_vC_1ph_MR2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_vC_1ph_MR2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_vC_1ph_MR2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_vC_1ph_MR2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_vC_1ph_MR2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_vC_1ph_MR2;
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

void c2_vC_1ph_MR2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_vC_1ph_MR2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_vC_1ph_MR2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_vC_1ph_MR2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_vC_1ph_MR2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
