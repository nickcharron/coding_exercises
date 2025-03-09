/*
  * Problem Description: https://www.facebook.com/careers/life/sample_interview_questions
  * Author: Nick Charron

  PROBLEM DESCRIPTION:
  Find the pattern and complete the function:
  int[][] spiral(int n);
  where n is the size of the 2D array.
  Sample Result
  input = 3
  123
  894
  765

  input = 4
  01 02 03 04
  12 13 14 05
  11 16 15 06
  10 09 08 07

  input = 8
  1 2 3 4 5 6 7 8
  28 29 30 31 32 33 34 9
  27 48 49 50 51 52 35 10
  26 47 60 61 62 53 36 11
  25 46 59 64 63 54 37 12
  24 45 58 57 56 55 38 13
  23 44 43 42 41 40 39 14
  22 21 20 19 18 17 16 15
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    int n;
    cin >> n;
    // vector<std::vector<int>> arr;
    int arr[n][n] = {};
    int e_count = 1, s_count = 0;

    // build array
    while(e_count < n*n+1){
      for(int c = s_count; c < n - s_count; c++){
        arr[s_count][c] = e_count;
        e_count++;
      }
      for(int r = s_count; r < n - s_count -1; r++){
        arr[r+1][n-1-s_count] = e_count;
        e_count++;
      }
      for(int c_inv = s_count+1; c_inv < n - s_count; c_inv++){
        int c = n - 1 - c_inv;
        arr[n-1-s_count][c] = e_count;
        e_count++;
      }
      for(int r_inv = s_count + 1; r_inv < n-1-s_count; r_inv++){
        int r = n - 1 - r_inv;
        arr[r][s_count] = e_count;
        e_count++;
      }
      s_count++;
    }

    // output array
    cout << "\n";
    for (int i = 0; i<n; i++){
      for (int j=0; j<n; j++){
          cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
}
