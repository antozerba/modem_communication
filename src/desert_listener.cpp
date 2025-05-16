#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <memory>
using std::placeholders::_1;

class DesertSubscriber : public rclcpp::Node
{
    public:
    DesertSubscriber() : Node("desert_subscriber")
    {
        subscription_ = this -> create_subscription<std_msgs::msg::String>
        ("/destination", 10, std::bind(&DesertSubscriber::callback, this, _1));
        RCLCPP_INFO(this -> get_logger(), "CREATO SUB");
    }

    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    
    void callback(const std_msgs::msg::String::SharedPtr message) const 
    {
        RCLCPP_INFO(this -> get_logger(), "Data: %s", message ->data.c_str());
    }
};
int main(int argc, char * argv[])
{
     // Imposta le variabili d'ambiente
    setenv("RMW_IMPLEMENTATION", "rmw_desert", 1);
    setenv("DESERT_PORT", "4000", 1);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DesertSubscriber>());
  rclcpp::shutdown();
  return 0;
}

