/*
  * Problem Description: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
  * Note: Using a different solution approach (std::queue)
  * Author: Nick Charron
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_queries;
    cin >> num_queries;
    queue<int> q;
    for (int i = 0; i < num_queries; i++){
      int type, value;
      cin >> type;
      switch(type){
        case 1:
          cin >> value;
          q.push(value);
          break;
        case 2:
          q.pop();
          break;
        case 3:
          cout << q.front() << "\n";
          break;
      }
    }
    return 0;
}
