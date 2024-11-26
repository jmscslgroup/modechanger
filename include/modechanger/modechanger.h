/*
 * modechanger.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modechanger".
 *
 * Model version              : 6.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Nov 26 17:27:31 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modechanger_h_
#define RTW_HEADER_modechanger_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "modechanger_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
struct B_modechanger_T {
  SL_Bus_modechanger_std_msgs_Float64 In1;/* '<S5>/In1' */
  int8_T publishPops;                  /* '<Root>/Chart' */
  int8_T pops;                         /* '<Root>/Chart' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_modechanger_T {
  ros_slros_internal_block_GetP_T obj; /* '<Root>/waitTime' */
  ros_slros_internal_block_GetP_T obj_d;/* '<Root>/lowDurationParam' */
  ros_slros_internal_block_GetP_T obj_f;/* '<Root>/highDurationParam' */
  ros_slroscpp_internal_block_P_T obj_n;/* '<S2>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_dw;/* '<S3>/SourceBlock' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_c3_modechanger;           /* '<Root>/Chart' */
  uint8_T is_active_c3_modechanger;    /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<Root>/waitTime' */
  boolean_T objisempty_j;              /* '<Root>/lowDurationParam' */
  boolean_T objisempty_p;              /* '<Root>/highDurationParam' */
  boolean_T objisempty_jw;             /* '<S3>/SourceBlock' */
  boolean_T objisempty_k;              /* '<S2>/SinkBlock' */
};

/* Parameters (default storage) */
struct P_modechanger_T_ {
  SL_Bus_modechanger_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                               * Referenced by: '<S5>/Out1'
                                               */
  SL_Bus_modechanger_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                      * Referenced by: '<S3>/Constant'
                                                      */
  SL_Bus_modechanger_std_msgs_Int8 Constant_Value_b;/* Computed Parameter: Constant_Value_b
                                                     * Referenced by: '<S4>/Constant'
                                                     */
  int8_T NoChange_Value;               /* Computed Parameter: NoChange_Value
                                        * Referenced by: '<Root>/NoChange'
                                        */
  int8_T Next_Value;                   /* Computed Parameter: Next_Value
                                        * Referenced by: '<Root>/Next'
                                        */
  int8_T Previous_Value;               /* Computed Parameter: Previous_Value
                                        * Referenced by: '<Root>/Previous'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_modechanger_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_modechanger_T modechanger_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_modechanger_T modechanger_B;

#ifdef __cplusplus

}

#endif

/* Block states (default storage) */
extern struct DW_modechanger_T modechanger_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void modechanger_initialize(void);
  extern void modechanger_step(void);
  extern void modechanger_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_modechanger_T *const modechanger_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'modechanger'
 * '<S1>'   : 'modechanger/Chart'
 * '<S2>'   : 'modechanger/Publish'
 * '<S3>'   : 'modechanger/Subscribe2'
 * '<S4>'   : 'modechanger/modeInput'
 * '<S5>'   : 'modechanger/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_modechanger_h_ */
