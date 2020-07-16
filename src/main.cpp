/**
 * @ Copyright 2020
 */

#include <stdio.h>
#include <ros/ros.h>

#include <string>

#include "sweep_control.hpp"
#include "serial_communication.hpp"


int main(int argc, char **argv) {
    ros::init(argc, argv, "node");
    ros::NodeHandle nh;
    std::string action_name;
    std::string mensagem = "mensagem";
    char mensagem2[100] = "\n";
    ros::param::get("~/action_name", action_name);
    laser_behavior::SweepControl sweep(&nh, action_name);
    communication::SerialCommunication serial;
    // serial.send_msg(mensagem.c_str());
    // serial.send_msg(mensagem2);
    // serial.send_msg("1234567890123456789");
    // while (ros::ok()) {
    //   mensagem = serial.receive_msg();
    //   ROS_INFO("Recebido %s", mensagem.data());
    //   serial.send_msg(mensagem);
    // }
    ros::spin();
}
