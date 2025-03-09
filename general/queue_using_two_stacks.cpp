/*
  * Problem Description: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
  * Author: Nick Charron
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void outputStack(stack<int> stack_in){
  int size_ = stack_in.size();
  for (int i = 0; i<size_; i++){
    cout << stack_in.top() << endl;
    stack_in.pop();
  }
}

stack<int> invertStack(stack<int> stack){
  // cout << "stack_in: \n";
  // outputStack(stack);
  std::stack<int> stack_out, stack_in;
  stack_in = stack;
  for(int i = 0; i < stack.size(); i++){
    int value = stack_in.top();
    stack_in.pop();
    stack_out.push(value);
  }
  // cout << "stack_out: \n";
  // outputStack(stack_out);
  return stack_out;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_queries;
    cin >> num_queries;
    stack<int> stack_, queue_;
    for (int i = 0; i < num_queries; i++){
      int type, value;
      cin >> type;
      switch(type){
        case 1:
          cin >> value;
          stack_.push(value);
          // cout << "-------\n";
          // cout << "stack: \n";
          // outputStack(stack_);
          // cout << "-------\n";
          break;
        case 2:
          queue_ = invertStack(stack_);
          queue_.pop();
          stack_ = invertStack(queue_);
          // cout << "-------\n";
          // cout << "stack: \n";
          // outputStack(stack_);
          // cout << "queue: \n";
          // outputStack(queue_);
          // cout << "-------\n";
          break;
        case 3:
          queue_ = invertStack(stack_);
          cout << queue_.top() << "\n";
          // cout << "-------\n";
          // cout << "stack: \n";
          // outputStack(stack_);
          // cout << "queue: \n";
          // outputStack(queue_);
          // cout << "-------\n";
          break;
      }
    }
    return 0;
}
