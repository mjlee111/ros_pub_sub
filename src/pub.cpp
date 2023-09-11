#include <ros/ros.h>                  // roscpp 기본 헤더파일
#include "ros_pub_sub/myCustomMsg.h"  // myCustomMsg 메시지 파일 헤더(빌드시 자동생성)

int main(int argc, char** argv)  // node 메인 함수
{
  ros::init(argc, argv, "simple_ros_publisher");  // 노드명 초기화
  ros::NodeHandle nh;                             // ROS 시스템과의 통신을 위한 NodeHandle 선언

  // 퍼블리셔 선언 -> simple_pub
  // 토픽명 -> "/ros_pub_test"
  // 퍼블리셔 큐 사이즈 -> 10
  ros::Publisher simple_pub = nh.advertise<ros_pub_sub::myCustomMsg>("/ros_pub_test", 10);

  ros::Rate loop_rate(10);  // ROS Node 의 루프 주기 설정. 숫자 -> Hz. 현재 10 Hz.

  // 메시지 선언
  ros_pub_sub::myCustomMsg msg;

  int cnt = 0;

  // ROS 가 실행된 상태일때
  while (ros::ok())
  {
    msg.stamp = ros::Time::now();         // msg 의 stamp에 현재 시간
    msg.data = cnt;                       // msg 의 data 에 cnt
    msg.message = "RO:BIT tutorials ! ";  // msg 의 message 에 string

    // 메시지 내용 출력
    ROS_INFO("-------------------------------------------------------------------------");
    ROS_INFO("Publishing Messages. Current Time = %d.%d", msg.stamp.sec, msg.stamp.nsec);
    ROS_INFO("Publishing Messages. Current Data = %ld", msg.data);
    ROS_INFO("Publishing Messages. Current Message = %s", msg.message.c_str());

    // 메시지 퍼블리시
    simple_pub.publish(msg);

    cnt++;
    loop_rate.sleep();
  }
  return 0;
}