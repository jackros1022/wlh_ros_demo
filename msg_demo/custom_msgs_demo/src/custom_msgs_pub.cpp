#include "ros/ros.h"
#include "custom_msgs_demo/can_data.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "custom_msgs_talker");

  ros::NodeHandle nh;

//-----------define custom messages Publisher--------------
  ros::Publisher pub_can_data = nh.advertise<custom_msgs_demo::can_data>("can_data", 10);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
//----------initialize custom messages and publish---------
    custom_msgs_demo::can_data output;
    
    output.header.seq = count;
    output.header.stamp = ros::Time::now();
    output.header.frame_id = "can_data";
    output.id = 0x101;
    output.len = 2;
    output.data[0] = 10;
    output.data[1] = 20;
    output.data[2] = 30;
    output.data[3] = 40;
    
    pub_can_data.publish(output);
	

    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }


  return 0;
}
