/**
 * MIT License
 *
 * Copyright (c) 2018 Ashish Patel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/**
 * @file       obstacleDetection.hpp
 * @version    0.1
 * @author     Ashish Patel
 * @brief      ObstacleDetection class header file
 * @date       12-15-2018
 */

#ifndef INCLUDE_OBSTACLEDETECTION_HPP_
#define INCLUDE_OBSTACLEDETECTION_HPP_

// including ROS Header files
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @brief ObstacleDetection class handles determining if the vehicle is going
 *        to collide using laser scans data
 */
class ObstacleDetection {
 public:
  /**
   * @brief ObstacleDetection class overloaded constructor
   * @param distThreshold of type double
   * @return none
   */
  explicit ObstacleDetection(double distThreshold);

  /**
   * @brief ObstacleDetection class destructor
   * @param none
   * @return none
   */
  ~ObstacleDetection();

  /**
   * @brief Detects the Obstacle in front of the robot
   * @param a reference to a variable of type sensor_msgs::LaserScan
   * @return true, if obstacle is detected 
   *         false, if obstacle is not detected
   */
  bool detectObstacle(const sensor_msgs::LaserScan::ConstPtr& msg);

  /**
   * @brief set distThreshold value
   * @param threshold of type double
   * @return none
   */
  void setDistThreshold(double threshold);

  /**
   * @brief get distThreshold value
   * @param none
   * @return distThreshold of type double
   */
  double getDistThreshold();

 private:
  /**
   * @brief declare a container to determine how close the robot should get to
   *        an object
   */
  double distThreshold_{0.0};
};

#endif  // INCLUDE_OBSTACLEDETECTION_HPP_
