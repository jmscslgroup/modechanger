/*
 * modechanger_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modechanger".
 *
 * Model version              : 6.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Nov 26 17:52:44 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modechanger_types_h_
#define RTW_HEADER_modechanger_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_modechanger_std_msgs_Int8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_modechanger_std_msgs_Int8_

struct SL_Bus_modechanger_std_msgs_Int8
{
  int8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_modechanger_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_modechanger_std_msgs_Float64_

struct SL_Bus_modechanger_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_P_T */

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_S_T */

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                              /* struct_f_robotics_slcore_internal_bl_T */

#ifndef struct_ros_slros_internal_block_GetP_T
#define struct_ros_slros_internal_block_GetP_T

struct ros_slros_internal_block_GetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                              /* struct_ros_slros_internal_block_GetP_T */

/* Parameters (default storage) */
typedef struct P_modechanger_T_ P_modechanger_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_modechanger_T RT_MODEL_modechanger_T;

#endif                                 /* RTW_HEADER_modechanger_types_h_ */
