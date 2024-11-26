#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "modechanger";

// For Block modechanger/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_modechanger_std_msgs_Float64> Sub_modechanger_49;

// For Block modechanger/Publish
SimulinkPublisher<std_msgs::Int8, SL_Bus_modechanger_std_msgs_Int8> Pub_modechanger_66;

// For Block modechanger/highDurationParam
SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_59;

// For Block modechanger/lowDurationParam
SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_56;

// For Block modechanger/waitTime
SimulinkParameterGetter<real64_T, double> ParamGet_modechanger_60;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

