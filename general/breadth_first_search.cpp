/*
  * Problem Description: https://www.hackerrank.com/challenges/bfsshortreach/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// ofstream fout(getenv("OUTPUT_PATH"));

class Node {
    public:
        int id;
        int distance;
        vector<Node *> adjacent;
        Node(int identity){
            this->id = identity;
            this->distance = 0;
        }
};

// class Node1 {
//     public:
//         int id;
//         int distance;
//         vector<shared_ptr<Node>> adjacent;
//         Node(int identity){
//             this->id = identity;
//             this->distance = 0;
//         }
// };

// Complete the bfs function below.
// n: no. of nodes
// m: no. of edges
// s: starting node
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> results(n-1, -1);
    vector<Node *> nodes;

    // akdd nodes
    for (int i = 0; i<n; i++){
        Node * newNode = new Node(i+1);
        nodes.push_back(newNode);
        // cout << "adding node: " << i+1 << "\n";
    }

    // add links
    for (int i = 0; i<m ; i++){
        int from_id = edges[i][0];
        int to_id = edges[i][1];
        // cout << "add edge from:" << from_id << " to: " << to_id << "\n";
        nodes.at(from_id-1)->adjacent.push_back(nodes[to_id-1]);
    }

    // bfs
    queue<Node *> q;
    q.push(nodes[s-1]);
    while(!q.empty()){
        Node * curr_node = q.front();
        // cout << "checking current node: " << curr_node->id << "\n";
        for (int i = 0; i<curr_node->adjacent.size(); i++){
            Node * check_node = curr_node->adjacent[i];
            // cout << "against node: " << check_node->id << "\n";
            check_node->distance = curr_node->distance + 6;
            // cout << "added a distance of " << check_node->distance << "\n";
            if (check_node->adjacent.size() < 1){
                // cout << "Not adding to queue.\n";
                results[check_node->id - 2] = check_node->distance;
            } else {
                // cout << "adding to queue...\n";
                q.push(check_node);
                results[check_node->id - 2] = check_node->distance;
            }
        }
        q.pop();
    }
    return results;
}

// vector<int> bfs1(int n, int m, vector<vector<int>> edges, int s) {
//     vector<int> results(n-1, -1);
//     vector<shared_ptr<Node>> nodes;
//
//     // akdd nodes
//     for (int i = 0; i<n; i++){
//         shared_ptr<Node> newNode = make_shared<Node>(i+1);
//         nodes.push_back(newNode);
//         // cout << "adding node: " << i+1 << "\n";
//     }
//
//     // add links
//     for (int i = 0; i<m ; i++){
//         int from_id = edges[i][0];
//         int to_id = edges[i][1];
//         // cout << "add edge from:" << from_id << " to: " << to_id << "\n";
//         nodes.at(from_id-1)->adjacent.push_back(nodes[to_id-1]);
//     }
//
//     // bfs
//     queue<shared_ptr<Node>> q;
//     q.push(nodes[s-1]);
//     while(!q.empty()){
//         shared_ptr<Node> curr_node = q.front();
//         // cout << "checking current node: " << curr_node->id << "\n";
//         for (int i = 0; i<curr_node->adjacent.size(); i++){
//             shared_ptr<Node> check_node = curr_node->adjacent[i];
//             // cout << "against node: " << check_node->id << "\n";
//             check_node->distance = curr_node->distance + 6;
//             // cout << "added a distance of " << check_node->distance << "\n";
//             if (check_node->adjacent.size() < 1){
//                 // cout << "Not adding to queue.\n";
//                 results[check_node->id - 2] = check_node->distance;
//             } else {
//                 // cout << "adding to queue...\n";
//                 q.push(check_node);
//                 results[check_node->id - 2] = check_node->distance;
//             }
//         }
//         q.pop();
//     }
//     return results;
// }

int main()
{

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    // fout.close();

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
