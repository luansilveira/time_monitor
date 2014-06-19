#include "time_monitor.h"

TimeMonitor::TimeMonitor()
{
}


void TimeMonitor::start()
{
    s_ros_ = ros::WallTime::now();
    gettimeofday(&s_get_, NULL);

}

void TimeMonitor::finish()
{
    e_ros_ = ros::WallTime::now();
    gettimeofday(&e_get_, NULL);

}

double TimeMonitor::getROSDuration()
{
    return (e_ros_-s_ros_).toSec();
}

std::ostream & operator <<(std::ostream &os, TimeMonitor &time)
{
    os << "Elapsed time = " << time.getDuration();
}

double TimeMonitor::getTvDuration()
{
    double dur_tv = (e_get_.tv_sec + e_get_.tv_usec*1e-6) -
                      (s_get_.tv_sec + s_get_.tv_usec*1e-6);

    return dur_tv;
}

double TimeMonitor::getDuration()
{
    return getROSDuration();
}

void TimeMonitor::print(std::string name)
{
    ROS_DEBUG_STREAM(name << " " << "ROS: " << getDuration() << " s");
}
