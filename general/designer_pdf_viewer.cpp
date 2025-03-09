/*
  * Problem Description: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
string alpha = "abcdefghijklmnopqrstuvwxyz";

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    unordered_map<char, int> lookup_map;
    int max_height = 0;
    for (int i = 0; i < 26; i++){
        pair<char, int> element(alpha[i], h[i]);
        lookup_map.insert(element);
    }
    for (int i = 0; i < word.size(); i++){
        unordered_map<char, int>::const_iterator it = lookup_map.find(word[i]);
        if(it == lookup_map.end()){
            cout << "Not found" << endl;
            break;
        }
        int height = it->second;
        if (height > max_height){
            max_height = height;
        }
    }
    cout << "Result: " << max_height * word.size() << "\n";
    return max_height * word.size();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    fout << result << "\n";

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
