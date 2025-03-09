#   A robot starts at x=0;y=0 with heading facing North and takes a 1-D input of
#   commands z such that:
#   if z[i]=-2: The robot is commanded to turn left by PI/2
#   if z[i]=-1: The robot is commanded to turn right by PI/2
#   if z[i]>=0: The robot is commanded to move z[i] units along the current
#   heading

#   Your objective is to write a function that does the following:
#   1. Process the commands and output the final position {x_final, y_final}
#   2. Process the commands and output the maximum distance and its coordinates in
#   the trajectory from the start point.

#   Example-1:
#   Input: {1, 2, 3, -2, 4}
#   Outputs: Final position={-4, 6}; Max distance: sqrt(52) @ {-4, 6}

#   Example-2:
#   Input: {5, -2, 3, -1, 4, -1, 6, -1, 2}
#   Outputs: Final position={3, 7}; Max distance: sqrt(90) @ {-3, 9}

import math
import numpy as np


class Robot:
    def __init__(self):
        self.x_r = 0
        self.y_r = 0
        self.theta_r = np.pi / 2
        self.farther_pose = [0, 0, 0]  # store [x,y, max_dist] for max distance

    def get_farther_pose(self):
        return self.farther_pose

    def move(self, i):
        if i == -1:
            self.theta_r += np.pi / 2
        elif i == -2:
            self.theta_r -= np.pi / 2
        elif i > 0:
            self.x_r += i * math.cos(self.theta_r)
            self.y_r += i * math.sin(self.theta_r)
            d = math.sqrt(self.x_r * self.x_r + self.y_r * self.y_r)
            if d > self.farther_pose[2]:
                # print(
                #     f"setting farthest point to [{self.x_r}, {self.y_r}, {d}]")
                self.farther_pose[0] = self.x_r
                self.farther_pose[1] = self.y_r
                self.farther_pose[2] = d
        else:
            print(f"ERROR - invalid input: {i}. Skipping")


def main(input):
    print("Running Robot simulation with input: ", input)
    robot = Robot()
    for i in input:
        robot.move(i)
        # print(i)
    fartest_pose = robot.get_farther_pose()
    print(
        f"max distance is {fartest_pose[2]} at location [{fartest_pose[0]}, {fartest_pose[1]}]")

    print("Done robot simulation")


if __name__ == "__main__":
    input1 = [1, 2, 3, -2, 4]
    input2 = [5, -2, 3, -1, 4, -1, 6, -1, 2]
    main(input1)
    main(input2)
