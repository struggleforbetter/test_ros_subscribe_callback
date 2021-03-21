#include "ros/ros.h"
#include <std_msgs/String.h>
#include <string> 
#include <functional>
void callback(const std_msgs::String& msg){} //right
void callback1(const std_msgs::String::ConstPtr& msg){} //right
void callback2(std_msgs::String::ConstPtr msg){} //right
std::function<void(const std_msgs::String&)> callback3; //wrong at compile,须指明subscribe 类型
std::function<void(const std_msgs::String::ConstPtr&)> callback4; //right,须指明subscribe 类型
std::function<void(std_msgs::String::ConstPtr)> callback5; //right,须指明subscribe 类型

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test");
    ros::NodeHandle nh("~");
    std::string topic_name = "haha";
    // ros::Subscriber sub = nh.subscribe<std_msgs::String>(topic_name,10,callback3);

    // lambda 表达式如下 wrong
    // ros::Subscriber sub1 = nh.subscribe<std_msgs::String>(topic_name,10,[](const std_msgs::String& msg )->void 
    //                                     {
    //                                         std::cout << "haha\n";
    //                                     });

    // lambda 表达式如下 wrong
    // ros::Subscriber sub2 = nh.subscribe<std_msgs::String>(topic_name,10,[](const std_msgs::String::ConstPtr& msg )->void 
    //                                     {
    //                                         std::cout << "haha\n";
    //                                     });
    // lambda 表达式如下 right
    // ros::Subscriber sub3 = nh.subscribe<std_msgs::String>(topic_name,10,[](std_msgs::String::ConstPtr msg )->void 
    //                                     {
    //                                         std::cout << "haha\n";
    //                                     });
    return 0;
}