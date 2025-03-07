/*
 * Problem Description:
 * https://www.hackerrank.com/challenges/functional-programming-warmups-in-recursion---fibonacci-numbers/problem
 * Author: Nick Charron
 */

#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int x;
  cout << "Input Nth number to return\n";
  cin >> x;
  cout << "Input received: " << x << "\n";
  int answer = fibonacci(x);
  cout << "answer: " << answer << "\n";
  return 0;
}
