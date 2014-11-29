/* Include files */

#include "iC_1ph_MR2_sfun.h"
#include "c2_iC_1ph_MR2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _iC_1ph_MR2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void iC_1ph_MR2_initializer(void)
{
}

void iC_1ph_MR2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_iC_1ph_MR2_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_iC_1ph_MR2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_iC_1ph_MR2_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1919804754U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(299655550U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2673392248U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4073223793U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1978075402U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(128737156U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4005989325U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(578505971U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_iC_1ph_MR2_get_check_sum(mxArray *plhs[]);
          sf_c2_iC_1ph_MR2_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(341111055U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(853001485U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(451369174U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(949154429U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_iC_1ph_MR2_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
     case 2:
      {
        if (strcmp(aiChksum, "JQmg9mpFb9klQ4INppfON") == 0) {
          extern mxArray *sf_c2_iC_1ph_MR2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_iC_1ph_MR2_get_autoinheritance_info();
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

unsigned int sf_iC_1ph_MR2_get_eml_resolved_functions_info( int nlhs, mxArray *
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
     case 2:
      {
        extern const mxArray *sf_c2_iC_1ph_MR2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_iC_1ph_MR2_get_eml_resolved_functions_info();
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

void iC_1ph_MR2_debug_initialize(void)
{
  _iC_1ph_MR2MachineNumber_ = sf_debug_initialize_machine("iC_1ph_MR2","sfun",0,
    1,0,0,0);
  sf_debug_set_machine_event_thresholds(_iC_1ph_MR2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_iC_1ph_MR2MachineNumber_,0);
}

void iC_1ph_MR2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_iC_1ph_MR2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("iC_1ph_MR2",
      "iC_1ph_MR2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_iC_1ph_MR2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
