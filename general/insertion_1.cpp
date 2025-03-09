/*
  * Problem Description: https://www.hackerrank.com/challenges/insertionsort1/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
ofstream fout(getenv("OUTPUT_PATH"));
void outputArray(const vector<int> &arr){
    for (int i = 0; i<arr.size(); i++){
        fout << arr[i] << " ";
    }
    fout << endl;
}

// Complete the insertionSort1 function below.
void insertionSort1(int n, vector<int> arr) {
    bool continue_searching = true;
    int num = arr[arr.size()-1];
    int iter = arr.size()-2;
    while(continue_searching){
        if(arr[iter] < num){
            arr[iter+1] = num;
            continue_searching = false;
        } else {
            arr[iter+1] = arr[iter];
        }
        outputArray(arr);
        if(iter == 0 && continue_searching){
            arr[iter] = num;
            continue_searching = false;
        } else {
            iter--;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
