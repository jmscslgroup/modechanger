/*
 * modeChanger.cpp
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

#include "modeChanger.h"
#include "modeChanger_private.h"

/* Named constants for Chart: '<Root>/Chart' */
const uint8_T modeChanger_IN_Debounce = 1U;
const uint8_T modeChanger_IN_HeldIn = 2U;
const uint8_T modeChanger_IN_High = 3U;
const uint8_T modeChanger_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T modeChanger_IN_Pop = 4U;
const uint8_T modeChanger_IN_Reset = 5U;
const uint8_T modeChanger_IN_ResetPops = 6U;
const uint8_T modeChanger_IN_idle = 7U;
const uint8_T modeChanger_IN_initialize = 8U;

/* Block signals (default storage) */
B_modeChanger_T modeChanger_B;

/* Block states (default storage) */
DW_modeChanger_T modeChanger_DW;

/* Real-time model */
RT_MODEL_modeChanger_T modeChanger_M_ = RT_MODEL_modeChanger_T();
RT_MODEL_modeChanger_T *const modeChanger_M = &modeChanger_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_GetP_T *obj);
static void matlabCodegenHandle_matlab_ktm2(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabC_ktm(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_GetP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlab_ktm2(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabC_ktm(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void modeChanger_step(void)
{
  /* local block i/o variables */
  real_T rtb_X;
  int8_T rtb_modechanger;
  real_T value;
  real_T value_0;
  boolean_T b_varargout_1;
  SL_Bus_modeChanger_std_msgs_Int8 rtb_BusAssignment;
  int32_T tmp;
  boolean_T guard1 = false;

  /* MATLABSystem: '<Root>/lowDurationParam' */
  ParamGet_modeChanger_56.get_parameter(&value);

  /* MATLABSystem: '<Root>/highDurationParam' */
  ParamGet_modeChanger_59.get_parameter(&value);

  /* MATLABSystem: '<Root>/lowDurationParam1' */
  ParamGet_modeChanger_60.get_parameter(&value_0);

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
  /* MATLABSystem: '<S3>/SourceBlock' incorporates:
   *  Inport: '<S5>/In1'
   */
  b_varargout_1 = Sub_modeChanger_49.getLatestMessage
    (&modeChanger_B.b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (b_varargout_1) {
    modeChanger_B.In1 = modeChanger_B.b_varargout_2;
  }

  /* End of MATLABSystem: '<S3>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

  /* SignalConversion generated from: '<Root>/Bus Selector1' */
  rtb_X = modeChanger_B.In1.Linear.X;

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/highDurationParam'
   *  MATLABSystem: '<Root>/lowDurationParam1'
   */
  if (modeChanger_DW.temporalCounter_i1 < MAX_uint32_T) {
    modeChanger_DW.temporalCounter_i1++;
  }

  if (modeChanger_DW.is_active_c3_modeChanger == 0U) {
    modeChanger_DW.is_active_c3_modeChanger = 1U;
    modeChanger_DW.is_c3_modeChanger = modeChanger_IN_initialize;
    modeChanger_B.pops = 0;
  } else {
    guard1 = false;
    switch (modeChanger_DW.is_c3_modeChanger) {
     case modeChanger_IN_Debounce:
      if (modeChanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
           (value_0 * 100.0))) {
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_HeldIn;
      } else {
        if (rtb_X == 0.0) {
          modeChanger_DW.is_c3_modeChanger = modeChanger_IN_Pop;
          tmp = modeChanger_B.pops + 1;
          if (tmp > 127) {
            tmp = 127;
          }

          modeChanger_B.pops = static_cast<int8_T>(tmp);
        }
      }
      break;

     case modeChanger_IN_HeldIn:
      if (rtb_X == 0.0) {
        modeChanger_B.pops = 0;
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_idle;
        modeChanger_DW.temporalCounter_i1 = 0U;
      }
      break;

     case modeChanger_IN_High:
      if (rtb_X == 0.0) {
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_idle;
        modeChanger_DW.temporalCounter_i1 = 0U;
      } else {
        if (modeChanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
             (value * 100.0))) {
          modeChanger_DW.is_c3_modeChanger = modeChanger_IN_Debounce;
          modeChanger_DW.temporalCounter_i1 = 0U;
        }
      }
      break;

     case modeChanger_IN_Pop:
      if (modeChanger_B.pops <= 3) {
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_idle;
        modeChanger_DW.temporalCounter_i1 = 0U;
      } else {
        if (modeChanger_B.pops > 3) {
          modeChanger_DW.is_c3_modeChanger = modeChanger_IN_HeldIn;
        }
      }
      break;

     case modeChanger_IN_Reset:
      if (modeChanger_B.pops > 1) {
        modeChanger_B.publishPops = modeChanger_B.pops;
        guard1 = true;
      } else {
        if (modeChanger_B.pops <= 1) {
          guard1 = true;
        }
      }
      break;

     case modeChanger_IN_ResetPops:
      if (modeChanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
           (value_0 * 100.0))) {
        modeChanger_B.publishPops = 0;
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_idle;
        modeChanger_DW.temporalCounter_i1 = 0U;
      }
      break;

     case modeChanger_IN_idle:
      if (rtb_X > 0.0) {
        modeChanger_B.publishPops = 0;
        modeChanger_DW.is_c3_modeChanger = modeChanger_IN_High;
        modeChanger_DW.temporalCounter_i1 = 0U;
      } else {
        if (modeChanger_DW.temporalCounter_i1 >= static_cast<uint32_T>(ceil
             (value_0 * 100.0))) {
          modeChanger_DW.is_c3_modeChanger = modeChanger_IN_Reset;
        }
      }
      break;

     default:
      /* case IN_initialize: */
      modeChanger_DW.is_c3_modeChanger = modeChanger_IN_idle;
      modeChanger_DW.temporalCounter_i1 = 0U;
      break;
    }

    if (guard1) {
      modeChanger_DW.is_c3_modeChanger = modeChanger_IN_ResetPops;
      modeChanger_DW.temporalCounter_i1 = 0U;
      modeChanger_B.pops = 0;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Next'
   *  Constant: '<Root>/NoChange'
   *  Constant: '<Root>/Previous'
   */
  switch (modeChanger_B.publishPops) {
   case 0:
    rtb_modechanger = modeChanger_P.NoChange_Value;
    break;

   case 2:
    rtb_modechanger = modeChanger_P.Next_Value;
    break;

   default:
    rtb_modechanger = modeChanger_P.Previous_Value;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = rtb_modechanger;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S2>/SinkBlock' */
  Pub_modeChanger_36.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
}

/* Model initialize function */
void modeChanger_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&modeChanger_B)), 0,
                sizeof(B_modeChanger_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&modeChanger_DW), 0,
                sizeof(DW_modeChanger_T));

  {
    char_T tmp[13];
    char_T tmp_0[14];
    char_T tmp_1[10];
    char_T tmp_2[11];
    int32_T i;
    static const char_T tmp_3[12] = { '/', 'l', 'o', 'w', 'D', 'u', 'r', 'a',
      't', 'i', 'o', 'n' };

    static const char_T tmp_4[13] = { '/', 'h', 'i', 'g', 'h', 'D', 'u', 'r',
      'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_5[9] = { '/', 'w', 'a', 'i', 't', 'T', 'i', 'm', 'e'
    };

    static const char_T tmp_6[10] = { '/', 'h', 'i', 'g', 'h', 'b', 'e', 'a',
      'm', 's' };

    static const char_T tmp_7[12] = { '/', 'm', 'o', 'd', 'e', 'C', 'h', 'a',
      'n', 'g', 'e', 'r' };

    /* Start for MATLABSystem: '<Root>/lowDurationParam' */
    modeChanger_DW.obj.matlabCodegenIsDeleted = false;
    modeChanger_DW.objisempty_j = true;
    modeChanger_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp[i] = tmp_3[i];
    }

    tmp[12] = '\x00';
    ParamGet_modeChanger_56.initialize(tmp);
    ParamGet_modeChanger_56.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modeChanger_56.set_initial_value(0.02);
    modeChanger_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/lowDurationParam' */

    /* Start for MATLABSystem: '<Root>/highDurationParam' */
    modeChanger_DW.obj_f.matlabCodegenIsDeleted = false;
    modeChanger_DW.objisempty_p = true;
    modeChanger_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_0[i] = tmp_4[i];
    }

    tmp_0[13] = '\x00';
    ParamGet_modeChanger_59.initialize(tmp_0);
    ParamGet_modeChanger_59.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modeChanger_59.set_initial_value(0.02);
    modeChanger_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/highDurationParam' */

    /* Start for MATLABSystem: '<Root>/lowDurationParam1' */
    modeChanger_DW.obj_l.matlabCodegenIsDeleted = false;
    modeChanger_DW.objisempty_kg = true;
    modeChanger_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_1[i] = tmp_5[i];
    }

    tmp_1[9] = '\x00';
    ParamGet_modeChanger_60.initialize(tmp_1);
    ParamGet_modeChanger_60.initialize_error_codes(0, 1, 2, 3);
    ParamGet_modeChanger_60.set_initial_value(0.7);
    modeChanger_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/lowDurationParam1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    modeChanger_DW.obj_d.matlabCodegenIsDeleted = false;
    modeChanger_DW.objisempty = true;
    modeChanger_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp_2[i] = tmp_6[i];
    }

    tmp_2[10] = '\x00';
    Sub_modeChanger_49.createSubscriber(tmp_2, 1);
    modeChanger_DW.obj_d.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S2>/SinkBlock' */
    modeChanger_DW.obj_n.matlabCodegenIsDeleted = false;
    modeChanger_DW.objisempty_k = true;
    modeChanger_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp[i] = tmp_7[i];
    }

    tmp[12] = '\x00';
    Pub_modeChanger_36.createPublisher(tmp, 1);
    modeChanger_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S5>/Out1' */
  modeChanger_B.In1 = modeChanger_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Chart: '<Root>/Chart' */
  modeChanger_DW.temporalCounter_i1 = 0U;
  modeChanger_DW.is_active_c3_modeChanger = 0U;
  modeChanger_DW.is_c3_modeChanger = modeChanger_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void modeChanger_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/lowDurationParam' */
  matlabCodegenHandle_matlabCodeg(&modeChanger_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/highDurationParam' */
  matlabCodegenHandle_matlabCodeg(&modeChanger_DW.obj_f);

  /* Terminate for MATLABSystem: '<Root>/lowDurationParam1' */
  matlabCodegenHandle_matlabCodeg(&modeChanger_DW.obj_l);

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  matlabCodegenHandle_matlab_ktm2(&modeChanger_DW.obj_d);

  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S2>/SinkBlock' */
  matlabCodegenHandle_matlabC_ktm(&modeChanger_DW.obj_n);

  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
