#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "modeChanger";

// For Block modeChanger/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_modeChanger_geometry_msgs_Twist> Sub_modeChanger_49;

// For Block modeChanger/Publish
SimulinkPublisher<std_msgs::Int8, SL_Bus_modeChanger_std_msgs_Int8> Pub_modeChanger_36;

// For Block modeChanger/highDurationParam
SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_59;

// For Block modeChanger/lowDurationParam
SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_56;

// For Block modeChanger/lowDurationParam1
SimulinkParameterGetter<real64_T, double> ParamGet_modeChanger_60;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

