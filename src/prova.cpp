#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>

class ProvaPublisher : public rclcpp::Node
{
public:
    ProvaPublisher() : Node("desert_publisher")
    {
        //creo pub
        publisher_ = this -> create_publisher<std_msgs::msg::Float32>("/bluerov2/cmd_thruster1", 10);

        timer_ = this -> create_wall_timer(
            std::chrono::seconds(3),
            std::bind(&ProvaPublisher::publish_data, this)
        );
    }

private:
    void publish_data()
    {
        auto message = std_msgs::msg::Float32();
        message.data =14.4;
        publisher_ -> publish(message);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.data);
    }
    rclcpp::Publisher<std_msgs::msg::Float32> ::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char * argv[]){
    setenv("RMW_IMPLEMENTATION", "rmw_desert", 1);
    setenv("DESERT_PORT", "5000", 1);

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ProvaPublisher>());
    rclcpp::shutdown();
    return 0;
}