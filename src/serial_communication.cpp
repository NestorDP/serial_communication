/**
 * @ Copyright 2020
 */

#include "serial_communication.hpp"

communication::SerialCommunication::SerialCommunication() {
  std::string port;
  ros::param::get("~/port", port);
  fd_serial_port_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd_serial_port_ == -1) {
    ROS_ERROR("Error opening port %s: %s", port.data(), strerror(errno));
  } else {
    fcntl(fd_serial_port_, F_SETFL, 0);
    ROS_INFO("Open port %s", port.data());
  }
}

communication::SerialCommunication::~SerialCommunication() {
  close(fd_serial_port_);
}

void communication::SerialCommunication::send_msg(const char *msg) {
  n_ = write(fd_serial_port_ , msg, strlen(msg));
  if (n_ < 0) {
    ROS_ERROR("Error send mensage: %s", strerror(errno));
  }
  n_ = write(fd_serial_port_ , "\n", 1);
  if (n_ < 0) {
    ROS_ERROR("Error send mensage: %s", strerror(errno));
  }
}

std::string communication::SerialCommunication::receive_msg() {
  char read_buf[200];
  std::string message;
  memset(read_buf, '\0', sizeof(read_buf));
  n_ = read(fd_serial_port_, &read_buf, sizeof(read_buf));
  message = read_buf;
  message.pop_back();
  return message;
}
