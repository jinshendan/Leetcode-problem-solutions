class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for (auto& x: nums) f[x]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto& x: f){
            pq.push(make_pair(x.second, x.first));
        }
        
        vector<int> ans;
        for (int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};