#pragma once

#include "ros/ros.h"
#include "nodelet/nodelet.h"
#include <pluginlib/class_list_macros.h>
#include "std_msgs/String.h"

namespace nodelet_tutorial
{

class Listener : public nodelet::Nodelet
{
public:
  Listener();
  ~Listener();

private:
  virtual void onInit();

  ros::Subscriber sub_;
  void listenerCallback(const std_msgs::StringConstPtr message);
};

} // namespace nodelet_tutorial
