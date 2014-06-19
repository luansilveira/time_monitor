#ifndef EXECUTION_TIME_MONITOR_H
#define EXECUTION_TIME_MONITOR_H

#include <ros/ros.h>

#include <string>

class TimeMonitor
{
public:
    TimeMonitor();

    void start();
    void finish();

    double getDuration();

    void print(std::string name = "Duration");

    double getTvDuration();
    double getROSDuration();

    friend std::ostream & operator<<(std::ostream & os, TimeMonitor &time);
private:


    struct timeval s_get_, e_get_;

    ros::WallTime s_ros_, e_ros_;
};



#endif // EXECUTION_TIME_MONITOR_H
