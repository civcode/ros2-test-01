#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

rclcpp::Node::SharedPtr g_node = nullptr;

void subscription_callback(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "subscription_callback");  
  //RCLCPP_INFO(g_node->get_logger(), "subscription_callback");  
  std::cout << "test" << std::endl;
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  //std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test_01");
  g_node = rclcpp::Node::make_shared("test_01");

  //auto qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
  //auto qos = rclcpp::QoS(rclcpp::QoS::best_effort());
  auto qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
  //node->create_subscription("/can0/tx/trajectory_data", rclcpp::QoS::best_effort(), )
  //node->create_subscription<std_msgs::msg::String>("/topic", qos, subscription_callback);
  //node->create_subscription<std_msgs::msg::String>("/topic", 10, subscription_callback);
  auto subscription = g_node->create_subscription<std_msgs::msg::String>("/topic", qos, subscription_callback);

  //node->create_sub

  rclcpp::spin(g_node);
  rclcpp::shutdown();
  subscription = nullptr;
  g_node = nullptr;

  return 0;
}