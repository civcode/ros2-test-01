#include "rclcpp/rclcpp.hpp"

#include <cstdio>
#include <memory>

int main(int argc, char ** argv)
{
  // (void) argc;
  // (void) argv;

  printf("hello world test_pkg_01 package\n");

  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test_01");

  //node->create_sub

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}