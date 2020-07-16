/**
 * @ Copyright 2020
 */

#ifndef SERIAL_COMMUNICATION_HPP_
#define SERIAL_COMMUNICATION_HPP_

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <ros/ros.h>

#include <string>
#include <iostream>

namespace communication {

class SerialCommunication {
 public:
  SerialCommunication();
  ~SerialCommunication();
  void send_msg(const char *msg);
  std::string receive_msg();

 private:
  int fd_serial_port_;  // File descriptor for the port
  int n_;
};

}  // namespace communication

#endif  // SERIAL_COMMUNICATION_HPP_
