#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> m;
        for (auto& t: barcodes) m[t]++;

        priority_queue<pair<int, int>> pq;
        for (auto & t: m) pq.emplace(t.second, t.first);

        vector<int> ans;
        while(!pq.empty()){
            auto t1 = pq.top();
            pq.pop();

            if (ans.empty() or ans.back() != t1.second or pq.empty()){
                ans.push_back(t1.second);
                if (--t1.first) pq.push(t1);
            }
            else {
                auto t2 = pq.top(); pq.pop(); pq.push(t1);
                ans.push_back(t2.second);
                if (--t2.first) pq.push(t2);
            }
        }
        return ans;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> barcodes = {7,7,7,8,5,7,5,5,5,8};
    vector<int> ans = sol->rearrangeBarcodes(barcodes);
    for (auto t: ans) cout << t << " ";
    cout << endl;
    return 0;
}