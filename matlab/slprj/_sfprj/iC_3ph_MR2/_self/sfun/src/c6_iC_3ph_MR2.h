#ifndef __c6_iC_3ph_MR2_h__
#define __c6_iC_3ph_MR2_h__

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
} c6_ResolvedFunctionInfo;

typedef struct {
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_iC_3ph_MR2;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c6_theta_k[6];
  boolean_T c6_theta_k_not_empty;
  real_T c6_omega_k[6];
  boolean_T c6_omega_k_not_empty;
  real_T c6_omega_k_1[6];
  boolean_T c6_omega_k_1_not_empty;
  real_T c6_omega_k_2[6];
  boolean_T c6_omega_k_2_not_empty;
  real_T c6_eta_k_1[6];
  boolean_T c6_eta_k_1_not_empty;
  real_T c6_eta_k_2[6];
  boolean_T c6_eta_k_2_not_empty;
  real_T c6_i2m_k_1;
  boolean_T c6_i2m_k_1_not_empty;
  real_T c6_i2m_k_2;
  boolean_T c6_i2m_k_2_not_empty;
  real_T c6_i2ref_k_1;
  boolean_T c6_i2ref_k_1_not_empty;
  real_T c6_i2ref_k_2;
  boolean_T c6_i2ref_k_2_not_empty;
  real_T c6_v_k_1;
  boolean_T c6_v_k_1_not_empty;
  real_T c6_v_k_2;
  boolean_T c6_v_k_2_not_empty;
  real_T c6_rho_k;
  boolean_T c6_rho_k_not_empty;
  real_T c6_m2;
  boolean_T c6_m2_not_empty;
  real_T c6_u_k_1;
  boolean_T c6_u_k_1_not_empty;
  real_T c6_u_k_2;
  boolean_T c6_u_k_2_not_empty;
} SFc6_iC_3ph_MR2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_iC_3ph_MR2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
extern void c6_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
