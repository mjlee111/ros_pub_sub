#include <ros/ros.h>                  // roscpp 기본 헤더파일
#include "ros_pub_sub/myCustomMsg.h"  // myCustomMsg 메시지 파일 헤더(빌드시 자동생성)

// Callback 함수 선언
void msgCallback(const ros_pub_sub::myCustomMsg::ConstPtr& msg)
{
  ROS_INFO("Subscribed Messages. Published Time = %d.%d", msg->stamp.sec, msg->stamp.nsec);
  ROS_INFO("Subscribed Messages. Published Data = %ld", msg->data);
  ROS_INFO("Subscribed Messages. Published Message = %s", msg->message.c_str());
}

int main(int argc, char** argv)  // node 메인 함수
{
  ros::init(argc, argv, "simple_ros_subscriber");  // 노드명 초기화
  ros::NodeHandle nh;                              // ROS 시스템과의 통신을 위한 NodeHandle 선언

  // 서브스크라이버 선언 -> simple_sub
  // 토픽명 -> "/ros_pub_test"
  // 서브스크라이버 큐 사이즈 -> 10
  ros::Subscriber simple_sub =
      nh.subscribe("/ros_pub_test", 10, msgCallback);  // msgCallback -> topic을 서브스크라이브 할 때마다 실행되는 함수.

  ros::Rate loop_rate(10);  // ROS Node 의 루프 주기 설정. 숫자 -> Hz. 현재 10 Hz.

  // ROS 가 실행된 상태일때
  while (ros::ok())
  {
    loop_rate.sleep();
  }
  return 0;
}