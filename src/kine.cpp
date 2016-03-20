#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc,argv, "kine");
    ros::NodeHandle node;
    ros::Publisher pub_left = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorLeftSpeed", 1);
    ros::Publisher pub_right = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorRightSpeed", 1);
    ros::Rate loop_rate(60);
     
    
     std_msgs::Float64 wr,wl;    
        while(ros::ok())
        {
            wl.data = 5;
            wr.data = 5;
            pub_left.publish(wl);
            pub_right.publish(wr);
            
            ros::spinOnce();
            loop_rate.sleep();
        }
    
    
    
}