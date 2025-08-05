#pragma once

#include <rclcpp/rclcpp.hpp>
#include <fairino_action_manager/controller/controller.hpp>
#include <Eigen/Dense>
#include <map>
#include <fstream>
#include <string>
#include <memory>

// DEBUG_FILE macro remains the same
#define DEBUG_FILE(text) \
if(debug_file_.is_open()) \
{ \
  debug_file_ << text << std::endl;\
}

class ActionServerBase
{
protected:
    rclcpp::Node::SharedPtr node_; // Changed from NodeHandle&
    std::string action_name_;
    rclcpp::Time start_time_;      // Changed from ros::Time
    bool control_running_ {false}; 
    bool mode_change_ {false};     // Assuming this is for internal logic state
    
    std::ofstream debug_file_;
    // Assuming RobotController::FairinoWrapper is ROS-agnostic or ROS 2 compatible
    std::shared_ptr<RobotController::FairinoWrapper> mu_;
       
    // Constructor updated for rclcpp::Node::SharedPtr
    ActionServerBase(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu) :
        node_(node), action_name_(name), mu_(mu)  {}

public:
    virtual ~ActionServerBase() = default; // Good practice to have a virtual destructor

    bool isrunning() const { // made const, common C++ practice for getters
        return control_running_;
    }

    // compute signature updated for rclcpp::Time
    // This function will be called by an external entity (e.g., a control manager or timer)
    virtual bool compute(const rclcpp::Time& current_time) = 0;
    
protected:
    int iter_per_print_ {10};
    int print_count_ {0};
};