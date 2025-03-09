/*
  A robot starts at x=0;y=0 with heading facing North and takes a 1-D input of
  commands z such that:
  if z[i]=-2: The robot is commanded to turn left by PI/2
  if z[i]=-1: The robot is commanded to turn right by PI/2
  if z[i]>=0: The robot is commanded to move z[i] units along the current
  heading

  Your objective is to write a function that does the following:
  1. Process the commands and output the final position {x_final, y_final}
  2. Process the commands and output the maximum distance and its coordinates in
  the trajectory from the start point.

  Example-1:
  Input: {1, 2, 3, -2, 4}
  Outputs: Final position={-4, 6}; Max distance: sqrt(52) @ {-4, 6}

  Example-2:
  Input: {5, -2, 3, -1, 4, -1, 6, -1, 2}
  Outputs: Final position={3, 7}; Max distance: sqrt(90) @ {-3, 9}
*/

#include <cassert>
#include <iostream>
#include <math.h>
#include <vector>

/*
  Notes and Assumptions:

  - To get final position as well as max distance, we'll incrementally calculate
  distances at each step and store them This isn't the most memory or efficient,
  though, could only track the max at each timestep
  - For example 1:
    max distance = sqrt(4x4 + 6x6) = sqrt(16 + 36) = sqrt(52)
  - Update equation for case z[i] > 0
    x' = x + i * cos(theta)
    y' = y + i * sin(theta)
  - Assume North is along y axis
*/

// using namespace std;

struct FarthestPoint {
  double max_distance{0};
  double x{0};
  double y{0};

  void print() {
    std::cout << "Farthest point:\nmax_distance: " << max_distance
              << "\nposition: [" << x << ", " << y << "]\n";
  }
};

class Robot {
public:
  Robot() = default;

  void move(int input) {
    if (input == -2) {
      theta_current_ += M_PI / 2;
    } else if (input == -1) {
      theta_current_ -= M_PI / 2;
    } else if (input > 0) {
      x_cur_ += input * cos(theta_current_);
      y_cur_ += input * sin(theta_current_);
      double d = sqrt(x_cur_ * x_cur_ + y_cur_ * y_cur_);
      if (d > farthest_point_.max_distance) {
        farthest_point_.max_distance = d;
        farthest_point_.x = x_cur_;
        farthest_point_.y = y_cur_;
      }
    } else {
      std::cout << "INVALID INPUT (" << input << ")! Not moving...\n";
    }
  }

  FarthestPoint getFarthestPoint() { return farthest_point_; }

  void outputFarthestPoint() { return farthest_point_.print(); }

private:
  FarthestPoint farthest_point_;
  double x_cur_{0};
  double y_cur_{0};
  double theta_current_{M_PI / 2};
};

int main() {
  std::vector<int> inputs1 = {1, 2, 3, -2, 4};
  std::vector<int> inputs2 = {5, -2, 3, -1, 4, -1, 6, -1, 2};

  {
    Robot robot;
    for (int i : inputs1) { robot.move(i); }
    robot.outputFarthestPoint();
    assert(abs(robot.getFarthestPoint().max_distance - sqrt(52)) < 0.0001);
  }

  {
    Robot robot;
    for (int i : inputs2) { robot.move(i); }
    robot.outputFarthestPoint();
    assert(abs(robot.getFarthestPoint().max_distance - sqrt(90)) < 0.0001);
  }

  return 0;
}