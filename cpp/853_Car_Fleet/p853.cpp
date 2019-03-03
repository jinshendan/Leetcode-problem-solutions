class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        int n = position.size();
        for (int i = 0; i < n; i++) 
            m[-position[i]] = 1.0 * (target - position[i]) / speed[i];
        int ans = 0;
        double max_time = 0;
        for (auto& t : m) if (t.second > max_time) {
            max_time = t.second;
            ans++;
        } 
        return ans;
    }
};