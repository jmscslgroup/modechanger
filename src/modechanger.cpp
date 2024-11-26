/*
 * modechanger.cpp
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

#include "modechanger.h"
#include "rtwtypes.h"
#include <math.h>
#include "modechanger_types.h"
#include <cstring>

/* Named constants for Chart: '<Root>/Chart' */
const uint8_T modechanger_IN_Debounce = 1U;
const uint8_T modechanger_IN_HeldIn = 2U;
const uint8_T modechanger_IN_High = 3U;
const uint8_T modechanger_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T modechanger_IN_Pop = 4U;
const uint8_T modechanger_IN_Reset = 5U;
const uint8_T modechanger_IN_ResetPops = 6U;
const uint8_T modechanger_IN_idle = 7U;
const uint8_T modechanger_IN_initialize = 8U;

/* Block signals (default storage) */
B_modechanger_T modechanger_B;

/* Block states (default storage) */
DW_modechanger_T modechanger_DW;

/* Real-time model */
RT_MODEL_modechanger_T modechanger_M_ = RT_MODEL_modechanger_T();
RT_MODEL_modechanger_T *const modechanger_M = &modechanger_M_;

/* Model step function */
void modechanger_step(void)
{
  SL_Bus_modechanger_std_msgs_Float64 b_varargout_2;
  SL_Bus_modechanger_std_msgs_Int8 rtb_BusAssignment;
  real_T rtb_Data;
  real_T value;
  real_T value_0;
  int8_T rtb_modechanger;
  boolean_T b_varargout_1;

  /* MATLABSystem: '<Root>/lowDurationParam' */
  ParamGet_modechanger_56.get_parameter(&value);

  /* MATLABSystem: '<Root>/highDurationParam' */
  ParamGet_modechanger_59.get_parameter(&value);

  /* MATLABSystem: '<Root>/waitTime' */
  ParamGet_modechanger_60.get_parameter(&value_0);

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
  /* MATLABSystem: '<S3>/SourceBlock' */
  b_varargout_1 = Sub_modechanger_49.getLatestMessage(&b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (b_varargout_1) {
    /* SignalConversion generated from: '<S5>/In1' */
    modechanger_B.In1 = b_varargout_2;
  }

  /* End of MATLABSystem: '<S3>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

  /* SignalConversion generated from: '<Root>/Bus Selector1' */
  rtb_Data = modechanger_B.In1.Data;

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/highDurationParam'
   *  MATLABSystem: '<Root>/waitTime'
   */
  if (modechanger_DW.temporalCounter_i1 < MAX_uint32_T) {
    modechanger_DW.temporalCounter_i1++;
  }

  if (modechanger_DW.is_active_c3_modechanger == 0U) {
    modechanger_DW.is_active_c3_modechanger = 1U;
    modechanger_DW.is_c3_modechanger = modechanger_IN_initialize;
    modechanger_B.pops = 0;
  } else {
    boolean_T guard1 = false;
    guard1 = false;
    switch (modechanger_DW.is_c3_modechanger) {
     case modechanger_IN_Debounce:
      {
        if (modechanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
             (value_0 * 100.0))) {
          modechanger_DW.is_c3_modechanger = modechanger_IN_HeldIn;
        } else if (rtb_Data == 0.0) {
          int32_T tmp;
          modechanger_DW.is_c3_modechanger = modechanger_IN_Pop;
          tmp = modechanger_B.pops + 1;
          if (modechanger_B.pops + 1 > 127) {
            tmp = 127;
          }

          modechanger_B.pops = static_cast<int8_T>(tmp);
        }
      }
      break;

     case modechanger_IN_HeldIn:
      if (rtb_Data == 0.0) {
        modechanger_B.pops = 0;
        modechanger_DW.is_c3_modechanger = modechanger_IN_idle;
        modechanger_DW.temporalCounter_i1 = 0U;
      }
      break;

     case modechanger_IN_High:
      if (rtb_Data == 0.0) {
        modechanger_DW.is_c3_modechanger = modechanger_IN_idle;
        modechanger_DW.temporalCounter_i1 = 0U;
      } else if (modechanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
                  (value * 100.0))) {
        modechanger_DW.is_c3_modechanger = modechanger_IN_Debounce;
        modechanger_DW.temporalCounter_i1 = 0U;
      }
      break;

     case modechanger_IN_Pop:
      if (modechanger_B.pops <= 3) {
        modechanger_DW.is_c3_modechanger = modechanger_IN_idle;
        modechanger_DW.temporalCounter_i1 = 0U;
      } else if (modechanger_B.pops > 3) {
        modechanger_DW.is_c3_modechanger = modechanger_IN_HeldIn;
      }
      break;

     case modechanger_IN_Reset:
      if (modechanger_B.pops > 1) {
        modechanger_B.publishPops = modechanger_B.pops;
        guard1 = true;
      } else if (modechanger_B.pops <= 1) {
        guard1 = true;
      }
      break;

     case modechanger_IN_ResetPops:
      if (modechanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
           (value_0 * 100.0))) {
        modechanger_B.publishPops = 0;
        modechanger_DW.is_c3_modechanger = modechanger_IN_idle;
        modechanger_DW.temporalCounter_i1 = 0U;
      }
      break;

     case modechanger_IN_idle:
      if (rtb_Data > 0.0) {
        modechanger_B.publishPops = 0;
        modechanger_DW.is_c3_modechanger = modechanger_IN_High;
        modechanger_DW.temporalCounter_i1 = 0U;
      } else if (modechanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
                  (value_0 * 100.0))) {
        modechanger_DW.is_c3_modechanger = modechanger_IN_Reset;
      }
      break;

     default:
      /* case IN_initialize: */
      modechanger_DW.is_c3_modechanger = modechanger_IN_idle;
      modechanger_DW.temporalCounter_i1 = 0U;
      break;
    }

    if (guard1) {
      modechanger_DW.is_c3_modechanger = modechanger_IN_ResetPops;
      modechanger_DW.temporalCounter_i1 = 0U;
      modechanger_B.pops = 0;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Next'
   *  Constant: '<Root>/NoChange'
   *  Constant: '<Root>/Previous'
   */
  switch (modechanger_B.publishPops) {
   case 0:
    rtb_modechanger = modechanger_P.NoChange_Value;
    break;

   case 2:
    rtb_modechanger = modechanger_P.Next_Value;
    break;

   default:
    rtb_modechanger = modechanger_P.Previous_Value;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = rtb_modechanger;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S2>/SinkBlock' */
  Pub_modechanger_36.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
}

/* Model initialize function */
void modechanger_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&modechanger_B)), 0,
                sizeof(B_modechanger_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&modechanger_DW), 0,
                sizeof(DW_modechanger_T));

  {
    char_T b_zeroDelimName_0[14];
    char_T b_zeroDelimName[13];
    char_T b_zeroDelimTopic[11];
    char_T b_zeroDelimName_1[10];
    static const char_T tmp[12] = { '/', 'l', 'o', 'w', 'D', 'u', 'r', 'a', 't',
      'i', 'o', 'n' };

    static const char_T tmp_0[13] = { '/', 'h', 'i', 'g', 'h', 'D', 'u', 'r',
      'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_1[9] = { '/', 'w', 'a', 'i', 't', 'T', 'i', 'm', 'e'
    };

    static const char_T tmp_2[10] = { '/', 'h', 'i', 'g', 'h', 'b', 'e', 'a',
      'm', 's' };

    static const char_T tmp_3[12] = { '/', 'm', 'o', 'd', 'e', 'C', 'h', 'a',
      'n', 'g', 'e', 'r' };

    /* Start for MATLABSystem: '<Root>/lowDurationParam' */
    modechanger_DW.obj_d.matlabCodegenIsDeleted = false;
    modechanger_DW.objisempty_j = true;
    modechanger_DW.obj_d.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimName[i] = tmp[i];
    }

    b_zeroDelimName[12] = '\x00';
    ParamGet_modechanger_56.initialize(&b_zeroDelimName[0]);
    ParamGet_modechanger_56.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modechanger_56.set_initial_value(0.02);
    modechanger_DW.obj_d.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/lowDurationParam' */

    /* Start for MATLABSystem: '<Root>/highDurationParam' */
    modechanger_DW.obj_f.matlabCodegenIsDeleted = false;
    modechanger_DW.objisempty_p = true;
    modechanger_DW.obj_f.isInitialized = 1;
    for (int32_T i = 0; i < 13; i++) {
      b_zeroDelimName_0[i] = tmp_0[i];
    }

    b_zeroDelimName_0[13] = '\x00';
    ParamGet_modechanger_59.initialize(&b_zeroDelimName_0[0]);
    ParamGet_modechanger_59.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modechanger_59.set_initial_value(0.05);
    modechanger_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/highDurationParam' */

    /* Start for MATLABSystem: '<Root>/waitTime' */
    modechanger_DW.obj.matlabCodegenIsDeleted = false;
    modechanger_DW.objisempty = true;
    modechanger_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimName_1[i] = tmp_1[i];
    }

    b_zeroDelimName_1[9] = '\x00';
    ParamGet_modechanger_60.initialize(&b_zeroDelimName_1[0]);
    ParamGet_modechanger_60.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modechanger_60.set_initial_value(0.3);
    modechanger_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/waitTime' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    modechanger_DW.obj_dw.matlabCodegenIsDeleted = false;
    modechanger_DW.objisempty_jw = true;
    modechanger_DW.obj_dw.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp_2[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_modechanger_49.createSubscriber(&b_zeroDelimTopic[0], 1);
    modechanger_DW.obj_dw.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S2>/SinkBlock' */
    modechanger_DW.obj_n.matlabCodegenIsDeleted = false;
    modechanger_DW.objisempty_k = true;
    modechanger_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimName[i] = tmp_3[i];
    }

    b_zeroDelimName[12] = '\x00';
    Pub_modechanger_36.createPublisher(&b_zeroDelimName[0], 1);
    modechanger_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
   *  Outport: '<S5>/Out1'
   */
  modechanger_B.In1 = modechanger_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Chart: '<Root>/Chart' */
  modechanger_DW.temporalCounter_i1 = 0U;
  modechanger_DW.is_active_c3_modechanger = 0U;
  modechanger_DW.is_c3_modechanger = modechanger_IN_NO_ACTIVE_CHILD;
  modechanger_B.publishPops = 0;
  modechanger_B.pops = 0;
}

/* Model terminate function */
void modechanger_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/lowDurationParam' */
  if (!modechanger_DW.obj_d.matlabCodegenIsDeleted) {
    modechanger_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/lowDurationParam' */

  /* Terminate for MATLABSystem: '<Root>/highDurationParam' */
  if (!modechanger_DW.obj_f.matlabCodegenIsDeleted) {
    modechanger_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/highDurationParam' */

  /* Terminate for MATLABSystem: '<Root>/waitTime' */
  if (!modechanger_DW.obj.matlabCodegenIsDeleted) {
    modechanger_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/waitTime' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  if (!modechanger_DW.obj_dw.matlabCodegenIsDeleted) {
    modechanger_DW.obj_dw.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S2>/SinkBlock' */
  if (!modechanger_DW.obj_n.matlabCodegenIsDeleted) {
    modechanger_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
