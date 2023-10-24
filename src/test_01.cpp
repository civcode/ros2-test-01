#include "rclcpp/rclcpp.hpp"

#include <cstdio>
#include <memory>

//#include "rclcpp/qos.hpp"
#include "std_msgs/msg/string.hpp"

rclcpp::Node::SharedPtr g_node = nullptr;

void subscription_callback(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "subscription_callback");  
  std::cout << "test" << std::endl;
}

int main(int argc, char ** argv)
{
  // (void) argc;
  // (void) argv;

  printf("hello world test_pkg_01 package\n");

  rclcpp::init(argc, argv);
  //std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test_01");
  g_node = rclcpp::Node::make_shared("test_01");

  //auto qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
  //auto qos = rclcpp::QoS(rclcpp::QoS::best_effort());
  auto qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
  //node->create_subscription("/can0/tx/trajectory_data", rclcpp::QoS::best_effort(), )
  //node->create_subscription<std_msgs::msg::String>("/topic", qos, subscription_callback);
  //node->create_subscription<std_msgs::msg::String>("/topic", 10, subscription_callback);
  g_node->create_subscription<std_msgs::msg::String>("topic", 10, subscription_callback);

  //node->create_sub

  rclcpp::spin(g_node);
  rclcpp::shutdown();

  return 0;
}