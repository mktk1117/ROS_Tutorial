#include "ros/ros.h"
#include "nodelet_tutorial/listener.h"

namespace nodelet_tutorial
{

Listener::Listener()
{
  ROS_INFO("Listener nodelet constructor");
}

Listener::~Listener()
{
  ROS_INFO("Listener nodelet destructor");
}

void Listener::onInit()
{
  ros::NodeHandle& private_nh = getPrivateNodeHandle();
  ros::NodeHandle& nh = getNodeHandle();
  sub_ = nh.subscribe("nodelet_tutorial_Talker/chatter", 10, &Listener::listenerCallback, this);
}

void Listener::listenerCallback(const std_msgs::StringConstPtr message){
// Using timers is the preferred 'ROS way' to manual threading
  NODELET_INFO_STREAM("Got message " << message->data);
}

} //namespace nodelet_tutorial

PLUGINLIB_EXPORT_CLASS(nodelet_tutorial::Listener, nodelet::Nodelet)
