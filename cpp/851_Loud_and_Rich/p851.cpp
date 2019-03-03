#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> f;
    vector<vector<int>> e;
    
    pair<int, int> calc(int x, vector<int>& quiet){
        if (f[x].first != -1) return f[x];
        int q = quiet[x]; 
        int who = x; 
        for (auto& y: e[x]){
            auto tmp = calc(y, quiet);
            if (tmp.first < q) {
                q = tmp.first;
                who = tmp.second;
            }
        }
        f[x] = make_pair(q, who);
        return f[x];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        e.resize(n);
        for (auto& r: richer){
            e[r[1]].push_back(r[0]);
        }
        
        f.resize(n);
        for (int i = 0; i < n; i++) f[i] = make_pair(-1, -1);
        
        vector<int> ans;
        for (int i = 0; i < n; i++){
            ans.push_back(calc(i, quiet).second);
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<vector<int>> richer = {{1,0}, {2,1}, {3,1}, {3,7}, {4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    vector<int> ans =s->loudAndRich(richer, quiet);
    for(auto & t: ans) cout << t << " ";
    cout << endl;
    return 0;
}