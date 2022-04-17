//
// Created by 向新亮 on 2022/4/17.
//
#include <vector>
using namespace std;
class Solution {
public:
    bool ok = true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,0);
        vector<vector<int>> graph(n+1);
        // 将图转换为邻接表
        for(vector<int> &edge:dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]) continue;
            color[i] = 1;
            dfs(graph,color,i);
        }
        //dfs(dislikes,color);
        return ok;
    }
    void dfs(vector<vector<int>>& graph,vector<int>& color,int v){
        if(!ok) return;
        for(int neighbor: graph[v]){
            if(!color[neighbor]){
                // 未染色
                color[neighbor] = 3 - color[v];
                dfs(graph,color,neighbor);
            }else if(color[v]==color[neighbor]){
                ok = false;
            }
        }
    }
};

int main(){
    Solution obj;
    vector<vector<int>> dislikes{{1,2},{1,3},{2,4}};
    obj.possibleBipartition(4,dislikes);
    return 0;
}