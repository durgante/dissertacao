/* Include files */

#include "iC_3ph_MR2_sfun.h"
#include "c1_iC_3ph_MR2.h"
#include "c2_iC_3ph_MR2.h"
#include "c3_iC_3ph_MR2.h"
#include "c4_iC_3ph_MR2.h"
#include "c5_iC_3ph_MR2.h"
#include "c6_iC_3ph_MR2.h"
#include "c7_iC_3ph_MR2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _iC_3ph_MR2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void iC_3ph_MR2_initializer(void)
{
}

void iC_3ph_MR2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_iC_3ph_MR2_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_iC_3ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_iC_3ph_MR2_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2146508398U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3734447673U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2746163743U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(204159870U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(702055893U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(214393946U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(682751024U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2523567514U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c1_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c2_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c3_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c4_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c5_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c6_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_iC_3ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c7_iC_3ph_MR2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2258810623U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(298339321U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2587732746U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4083304268U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1717028011U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2984422664U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2891564106U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4106878657U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_iC_3ph_MR2_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "8hV5QJTCR1J7adL00wtm0G") == 0) {
          extern mxArray *sf_c1_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "y4p94yN24bdgsTRYBGK2SH") == 0) {
          extern mxArray *sf_c2_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "3zL14pFcFSfhfFeWqhw6x") == 0) {
          extern mxArray *sf_c3_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "wC0aoH41z4Hf04oPhwme1B") == 0) {
          extern mxArray *sf_c4_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c4_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "aPsK6paOiX6oBwvGnqv8GG") == 0) {
          extern mxArray *sf_c5_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c5_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "nM2585MgrfETqMboaxHPg") == 0) {
          extern mxArray *sf_c6_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c6_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "1i3xevnbVGVuyl2s7HesvD") == 0) {
          extern mxArray *sf_c7_iC_3ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c7_iC_3ph_MR2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_iC_3ph_MR2_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_iC_3ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_iC_3ph_MR2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void iC_3ph_MR2_debug_initialize(void)
{
  _iC_3ph_MR2MachineNumber_ = sf_debug_initialize_machine("iC_3ph_MR2","sfun",0,
    7,0,0,0);
  sf_debug_set_machine_event_thresholds(_iC_3ph_MR2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_iC_3ph_MR2MachineNumber_,0);
}

void iC_3ph_MR2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_iC_3ph_MR2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("iC_3ph_MR2",
      "iC_3ph_MR2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_iC_3ph_MR2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}