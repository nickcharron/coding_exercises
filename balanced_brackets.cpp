/*
  * Problem Description: https://www.hackerrank.com/challenges/balanced-brackets/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;
ofstream fout(getenv("OUTPUT_PATH"));

// Complete the isBalanced function below.
string isBalanced(string s) {
    map<char, char> bracket_map;
    bracket_map[')'] = '(';
    bracket_map[']'] = '[';
    bracket_map['}'] = '{';

    stack<char> open_brackets;
    for (int i = 0; i<s.size(); i++){
        if(s[i] == '(' ||s[i] == '{' || s[i] == '['){
            // fout << "Push: " << s[i] << "\n";
            open_brackets.push(s[i]);
        } else {
            // fout << "s[i]: " << s[i] << "\n";
            // fout << "bracket_map[s[i]]: " << bracket_map[s[i]] << "\n";
            if (open_brackets.top() == bracket_map[s[i]]){
                // fout << "pop: " << open_brackets.top() << "\n";
                open_brackets.pop();
            } else {
                return "NO";
            }
        }
    }
    if (open_brackets.size() == 0){
        return "YES";
    } else {
        return "NO";
    }

}

int main()
{


    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
