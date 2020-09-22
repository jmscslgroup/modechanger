#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block modeChanger/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_modeChanger_geometry_msgs_Twist> Sub_modeChanger_49;

// For Block modeChanger/Publish
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_modeChanger_std_msgs_Int8> Pub_modeChanger_36;

// For Block modeChanger/highDurationParam
extern SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_59;

// For Block modeChanger/lowDurationParam
extern SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_56;

// For Block modeChanger/lowDurationParam1
extern SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_60;

void slros_node_init(int argc, char** argv);

#endif
