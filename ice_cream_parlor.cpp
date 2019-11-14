/*
  * Problem Description: https://www.hackerrank.com/challenges/icecream-parlor/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the icecreamParlor function below.
vector<int> icecreamParlorSlow(int m, vector<int> arr) {
    for(int i = 0; i<arr.size(); i++){
        for (int j = i+1; j<arr.size(); j++){
            if (arr[i] + arr[j] == m){
                vector<int>  result = {i+1, j+1};
                return result;
            }
        }
    }
    vector<int> result_failed = {0,0};
    return result_failed;
}

vector<int> icecreamParlorFast(int m, vector<int> arr) {
    map<int, int> map_;
    for(int iter = 0; iter<arr.size(); iter++){
      int i = arr.size() - iter - 1;
      map<int, int>::iterator it;
      it = map_.find(m-arr[i]);
      if(it != map_.end()){
        int j = it->second;
        vector<int> result = {i+1, j+1};
        return result;
      } else {
        pair<int, int> new_value(arr[i], i);
        map_.insert(new_value);
      }
    }
    vector<int> result_failed = {0,0};
    return result_failed;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

        // vector<int> result = icecreamParlorSlow(m, arr);
        vector<int> result = icecreamParlorFast(m, arr);

        for (int i = 0; i < result.size(); i++) {
            // fout << result[i];
            cout << result[i];

            if (i != result.size() - 1) {
                // fout << " ";
                cout << " ";
            }
        }

        // fout << "\n";
        cout << "\n";
    }

    fout.close();

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
