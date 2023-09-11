## cmake 버전 설정
cmake_minimum_required(VERSION 3.5)

## 패키지 명
project(ros_pub_sub)

## 의존성 패키지 추가
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

# 메시지 선언
add_message_files(FILES myCustomMsg.msg)
# 의존성 메시지 설정
generate_messages(DEPENDENCIES std_msgs)


# catkin 패키지 옵션으로 라이브러리, catkin 빌드 의존성, 시스템 의존 패키지 기술
catkin_package(
  LIBRARIES ros_pub_sub
  CATKIN_DEPENDS std_msgs roscpp
)

# include 경로 설정
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# publisher 노드 빌드옵션
# 실행 파일, 타깃 링크 라이브러리, 추가 의존성 설정.
add_executable(pub src/pub.cpp)
add_dependencies(
  pub ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(pub ${catkin_LIBRARIES})

# subscriber 노드 빌드옵션
# 실행 파일, 타깃 링크 라이브러리, 추가 의존성 설정.
add_executable(sub src/sub.cpp)
add_dependencies(
  sub ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(sub ${catkin_LIBRARIES})