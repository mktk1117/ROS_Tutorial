#include "ros/ros.h"
#include "nodelet_tutorial/talker.h"
#include "std_msgs/String.h"

namespace nodelet_tutorial
{

Talker::Talker()
{
  ROS_INFO("Talker nodelet constructor");
}

Talker::~Talker()
{
  ROS_INFO("Talker nodelet destructor");
}

void Talker::onInit()
{
  ros::NodeHandle& private_nh = getPrivateNodeHandle();
  pub_ = private_nh.advertise<std_msgs::String>("chatter", 10);
  timer_ = private_nh.createTimer(ros::Duration(1.0), boost::bind(& Talker::timerCallback, this, _1));
}

void Talker::timerCallback(const ros::TimerEvent& event){
// Using timers is the preferred 'ROS way' to manual threading
  NODELET_INFO_STREAM("The time is now " << event.current_real);
  pub_.publish(std::string("Hello nodelet"));
}

} //namespace nodelet_tutorial

PLUGINLIB_EXPORT_CLASS(nodelet_tutorial::Talker, nodelet::Nodelet)
