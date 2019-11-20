/*
  * Problem Description: https://www.hackerrank.com/challenges/functional-programming-warmups-in-recursion---fibonacci-numbers/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n){
  if (n == 1){
    return 0;
  } else if (n == 2){
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main(){
  int n, x;
  cin >> n;
  for (int i = 0; i<n; i++){
    cin >> x;
    int answer = fibonacci(x);
    cout << answer << "\n";
  }
  return 0;
}
