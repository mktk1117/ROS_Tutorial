#pragma once

#include "ros/ros.h"
#include "nodelet/nodelet.h"
#include <pluginlib/class_list_macros.h>

namespace nodelet_tutorial
{

class Talker : public nodelet::Nodelet
{
public:
  Talker();
  ~Talker();

private:
  virtual void onInit();

  void timerCallback(const ros::TimerEvent& event);
  ros::Publisher pub_;
  ros::Timer timer_;
};

} // namespace nodelet_tutorial
