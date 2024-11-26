#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "modechanger_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block modechanger/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_modechanger_std_msgs_Float64> Sub_modechanger_49;

// For Block modechanger/Publish
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_modechanger_std_msgs_Int8> Pub_modechanger_66;

// For Block modechanger/highDurationParam
extern SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_59;

// For Block modechanger/lowDurationParam
extern SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_56;

// For Block modechanger/waitTime
extern SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_60;

void slros_node_init(int argc, char** argv);

#endif
