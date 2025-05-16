#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class DesertPublisher : public rclcpp::Node
{
public:
    DesertPublisher() : Node("desert_publisher")
    {
        //creo pub
        publisher_ = this -> create_publisher<std_msgs::msg::String>("/destination", 10);

        timer_ = this -> create_wall_timer(
            std::chrono::seconds(3),
            std::bind(&DesertPublisher::publish_data, this)
        );
    }
private:
    void publish_data()
    {
        auto message = std_msgs::msg::String();
        message.data = "ciao";
        publisher_ -> publish(message);
        RCLCPP_INFO(this->get_logger(), "Sto pubbliscando: %s", message.data.c_str());
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char * argv[]){
    setenv("RMW_IMPLEMENTATION", "rmw_desert", 1);
    setenv("DESERT_PORT", "4000", 1);

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DesertPublisher>());
    rclcpp::shutdown();
    return 0;
}