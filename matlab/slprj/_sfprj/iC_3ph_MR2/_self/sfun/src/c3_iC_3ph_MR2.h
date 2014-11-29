#ifndef __c3_iC_3ph_MR2_h__
#define __c3_iC_3ph_MR2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c3_ResolvedFunctionInfo;

typedef struct {
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_iC_3ph_MR2;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c3_theta_k[6];
  boolean_T c3_theta_k_not_empty;
  real_T c3_omega_k[6];
  boolean_T c3_omega_k_not_empty;
  real_T c3_omega_k_1[6];
  boolean_T c3_omega_k_1_not_empty;
  real_T c3_omega_k_2[6];
  boolean_T c3_omega_k_2_not_empty;
  real_T c3_eta_k_1[6];
  boolean_T c3_eta_k_1_not_empty;
  real_T c3_eta_k_2[6];
  boolean_T c3_eta_k_2_not_empty;
  real_T c3_i2m_k_1;
  boolean_T c3_i2m_k_1_not_empty;
  real_T c3_i2m_k_2;
  boolean_T c3_i2m_k_2_not_empty;
  real_T c3_i2ref_k_1;
  boolean_T c3_i2ref_k_1_not_empty;
  real_T c3_i2ref_k_2;
  boolean_T c3_i2ref_k_2_not_empty;
  real_T c3_v_k_1;
  boolean_T c3_v_k_1_not_empty;
  real_T c3_v_k_2;
  boolean_T c3_v_k_2_not_empty;
  real_T c3_rho_k;
  boolean_T c3_rho_k_not_empty;
  real_T c3_m2;
  boolean_T c3_m2_not_empty;
  real_T c3_u_k_1;
  boolean_T c3_u_k_1_not_empty;
  real_T c3_u_k_2;
  boolean_T c3_u_k_2_not_empty;
} SFc3_iC_3ph_MR2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_iC_3ph_MR2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
extern void c3_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
