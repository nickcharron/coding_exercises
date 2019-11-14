/*
  * Problem Description: https://www.hackerrank.com/challenges/quicksort2/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>
using namespace std;
using vecIt = vector<int>::iterator;
ofstream fout(getenv("OUTPUT_PATH"));

void outputArray(const vector<int> &arr){
    for (int i = 0; i<arr.size(); i++){
        fout << arr[i] << " ";
    }
    fout << endl;
}

vector<int> quickSort(vector <int> &arr) {
    if(arr.size() < 2){
        return arr;
    }
	vector<int> arr_sorted, right, left;
    int p = arr[0];
    for (vecIt it = arr.begin()+1; it != arr.end(); it++){
        if (*it >= p){
            right.push_back(*it);
        } else {
            left.push_back(*it);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    for (vecIt it = left.begin(); it != left.end(); it++){
        arr_sorted.push_back(*it);
    }
    arr_sorted.push_back(p);
    for (vecIt it = right.begin(); it != right.end(); it++){
        arr_sorted.push_back(*it);
    }
    outputArray(arr_sorted);
    return arr_sorted;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    vector<int> arr_s = quickSort(arr);

    return 0;
}
