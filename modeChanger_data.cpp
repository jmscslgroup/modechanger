/*
 * modeChanger_data.cpp
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

/* Block parameters (default storage) */
P_modeChanger_T modeChanger_P = {
  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S5>/Out1'
   */
  {
    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    },                                 /* Linear */

    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    }                                  /* Angular */
  },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S3>/Constant'
   */
  {
    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    },                                 /* Linear */

    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    }                                  /* Angular */
  },

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S4>/Constant'
   */
  {
    0                                  /* Data */
  },

  /* Computed Parameter: Previous_Value
   * Referenced by: '<Root>/Previous'
   */
  -1,

  /* Computed Parameter: Next_Value
   * Referenced by: '<Root>/Next'
   */
  1,

  /* Computed Parameter: NoChange_Value
   * Referenced by: '<Root>/NoChange'
   */
  0
};
