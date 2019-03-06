class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto& v: rooms[u])
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (vis[i]) sum++;
        return sum == n;
    }
};