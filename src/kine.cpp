#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

double w = 0;
double v = 1;

void callback(const geometry_msgs::TwistConstPtr &msg)
{
    
    w = msg->angular.z;
    v = msg->linear.x;
    
    
}

int main(int argc, char **argv)
{
    ros::init(argc,argv, "kine");
    ros::NodeHandle node;
    ros::Publisher pub_left = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorLeftSpeed", 1);
    ros::Publisher pub_right = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorRightSpeed", 1);
    ros::Rate loop_rate(60);
    
    ros::Subscriber sub = node.subscribe("obstacle/twist", 1, callback);
     
            
    
     std_msgs::Float64 wr,wl;    
        while(ros::ok())
        {
            
        wr.data  = (v +(0.175*w))/0.1;
        wl.data  = (v - (0.175*w))/0.1;
            
            
            pub_left.publish(wl);
            pub_right.publish(wr);
            
            ros::spinOnce();
            loop_rate.sleep();
        }
    
    
    
}