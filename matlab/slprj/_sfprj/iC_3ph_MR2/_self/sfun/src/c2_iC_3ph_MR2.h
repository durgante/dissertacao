#ifndef __c2_iC_3ph_MR2_h__
#define __c2_iC_3ph_MR2_h__

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
} c2_ResolvedFunctionInfo;

typedef struct {
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_iC_3ph_MR2;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c2_theta_k[6];
  boolean_T c2_theta_k_not_empty;
  real_T c2_omega_k[6];
  boolean_T c2_omega_k_not_empty;
  real_T c2_omega_k_1[6];
  boolean_T c2_omega_k_1_not_empty;
  real_T c2_omega_k_2[6];
  boolean_T c2_omega_k_2_not_empty;
  real_T c2_eta_k_1[6];
  boolean_T c2_eta_k_1_not_empty;
  real_T c2_eta_k_2[6];
  boolean_T c2_eta_k_2_not_empty;
  real_T c2_i2m_k_1;
  boolean_T c2_i2m_k_1_not_empty;
  real_T c2_i2m_k_2;
  boolean_T c2_i2m_k_2_not_empty;
  real_T c2_i2ref_k_1;
  boolean_T c2_i2ref_k_1_not_empty;
  real_T c2_i2ref_k_2;
  boolean_T c2_i2ref_k_2_not_empty;
  real_T c2_v_k_1;
  boolean_T c2_v_k_1_not_empty;
  real_T c2_v_k_2;
  boolean_T c2_v_k_2_not_empty;
  real_T c2_rho_k;
  boolean_T c2_rho_k_not_empty;
  real_T c2_m2;
  boolean_T c2_m2_not_empty;
  real_T c2_u_k_1;
  boolean_T c2_u_k_1_not_empty;
  real_T c2_u_k_2;
  boolean_T c2_u_k_2_not_empty;
} SFc2_iC_3ph_MR2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_iC_3ph_MR2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
extern void c2_iC_3ph_MR2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
