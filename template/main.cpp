#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    vector<vector<int>> graph(10,vector<int>{});
    graph[0].push_back(1);
    return 0;
}
