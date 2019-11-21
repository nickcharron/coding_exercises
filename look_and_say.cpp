/*
  * Problem Description: https://www.facebook.com/careers/life/sample_interview_questions
  * Author: Nick Charron

  PROBLEM DESCRIPTION:
  Implement a function that outputs the Look and Say sequence:
  1
  11
  21
  1211
  111221
  312211
  13112221
  1113213211
  31131211131221
  13211311123113112211

  Follow up questions:
  How does the ouput length scale?
    - approximately linear with n (number of output lines)
  What is the max single digit that can exist in the output?
    - 9
  What is the only starting sequence that never grows in length?
    - 1 0
*/

#include <iostream>
#include <vector>

using namespace std;

void outputVector(vector<int> &v){
  for (int i : v){
    cout << i << " ";
  }
  cout << "\n";
}
int main(){
  int n;
  cin >> n;
  vector<int> last{1}, current;
  int count, val;
  cout << "1\n";

  for (int i = 1; i<n; i++){

    current.clear();
    count = 1;
    val = last[0];

    if(last.size() == 1){
      current.push_back(count);
      current.push_back(val);
      last = current;
      outputVector(current);
      continue;
    }

    for (int iter = 1; iter<last.size(); iter++){
      if(val == last[iter]){
        count++;
      } else {
        current.push_back(count);
        current.push_back(val);
        count = 1;
        val = last[iter];
      }
      if(iter == last.size()-1){
        current.push_back(count);
        current.push_back(val);
      }
    }
    last = current;
    outputVector(current);
  }
  return 0;
}
