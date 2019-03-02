#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int best;
    int n;
    int obj;
    struct T{
        int x, dep, id; 
        T(int x, int dep, int id):x(x),dep(dep),id(id){} 
    };
    
    int vis[15][5000];
    
    void bfs(int s, vector<vector<int>>& graph){
        queue<T> q;
        q.push(T(s, 0, 1<<s));
        memset(vis, 0, sizeof(vis));
        while (!q.empty()){
            auto x = q.front().x;
            auto dep = q.front().dep;
            auto id = q.front().id;
            q.pop();
            if (dep + 1 > best) continue;
            for (auto& y: graph[x]) {
                int new_id = id | (1 << y);
                if (new_id == obj){
                    best = min(best, dep + 1);
                    return;
                }
                if (!vis[y][new_id]) {
                    vis[y][new_id] = 1;
                    q.push(T(y, dep+1, new_id));
                }
            }
        }
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        best = 2*(n-1);
        obj = (1 << n) - 1;
        for (int i = 0; i < n; i++)
           bfs(i, graph);
        return best;
    }
};

int main(){
    Solution* s = new Solution();
    // vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};

    // vector<vector<int>> graph = {{1},{0,2,4},{1,3,4},{2},{1,2}};

    vector<vector<int>> graph = {{7},{3},{3,9},{1,2,4,5,7,11},{3},{3},{9},{3,10,8,0},{7},{11,6,2},{7},{3,9}};
    cout << s->shortestPathLength(graph) << endl;
    return 0;
}