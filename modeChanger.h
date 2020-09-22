/*
 * modeChanger.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modeChanger".
 *
 * Model version              : 1.41
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Sep 22 09:39:19 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modeChanger_h_
#define RTW_HEADER_modeChanger_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "modeChanger_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  SL_Bus_modeChanger_geometry_msgs_Twist In1;/* '<S5>/In1' */
  SL_Bus_modeChanger_geometry_msgs_Twist b_varargout_2;
  int8_T publishPops;                  /* '<Root>/Chart' */
  int8_T pops;                         /* '<Root>/Chart' */
} B_modeChanger_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ros_slros_internal_block_GetP_T obj; /* '<Root>/lowDurationParam' */
  ros_slros_internal_block_GetP_T obj_f;/* '<Root>/highDurationParam' */
  ros_slros_internal_block_GetP_T obj_l;/* '<Root>/lowDurationParam1' */
  ros_slros_internal_block_Publ_T obj_n;/* '<S2>/SinkBlock' */
  ros_slros_internal_block_Subs_T obj_d;/* '<S3>/SourceBlock' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_modeChanger;    /* '<Root>/Chart' */
  uint8_T is_c3_modeChanger;           /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<S3>/SourceBlock' */
  boolean_T objisempty_k;              /* '<S2>/SinkBlock' */
  boolean_T objisempty_j;              /* '<Root>/lowDurationParam' */
  boolean_T objisempty_p;              /* '<Root>/highDurationParam' */
  boolean_T objisempty_kg;             /* '<Root>/lowDurationParam1' */
} DW_modeChanger_T;

/* Parameters (default storage) */
struct P_modeChanger_T_ {
  SL_Bus_modeChanger_geometry_msgs_Twist Out1_Y0;/* Computed Parameter: Out1_Y0
                                                  * Referenced by: '<S5>/Out1'
                                                  */
  SL_Bus_modeChanger_geometry_msgs_Twist Constant_Value;/* Computed Parameter: Constant_Value
                                                         * Referenced by: '<S3>/Constant'
                                                         */
  SL_Bus_modeChanger_std_msgs_Int8 Constant_Value_b;/* Computed Parameter: Constant_Value_b
                                                     * Referenced by: '<S4>/Constant'
                                                     */
  int8_T Previous_Value;               /* Computed Parameter: Previous_Value
                                        * Referenced by: '<Root>/Previous'
                                        */
  int8_T Next_Value;                   /* Computed Parameter: Next_Value
                                        * Referenced by: '<Root>/Next'
                                        */
  int8_T NoChange_Value;               /* Computed Parameter: NoChange_Value
                                        * Referenced by: '<Root>/NoChange'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_modeChanger_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_modeChanger_T modeChanger_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern B_modeChanger_T modeChanger_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern DW_modeChanger_T modeChanger_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void modeChanger_initialize(void);
  extern void modeChanger_step(void);
  extern void modeChanger_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_modeChanger_T *const modeChanger_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'modeChanger'
 * '<S1>'   : 'modeChanger/Chart'
 * '<S2>'   : 'modeChanger/Publish'
 * '<S3>'   : 'modeChanger/Subscribe2'
 * '<S4>'   : 'modeChanger/modeInput'
 * '<S5>'   : 'modeChanger/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_modeChanger_h_ */
