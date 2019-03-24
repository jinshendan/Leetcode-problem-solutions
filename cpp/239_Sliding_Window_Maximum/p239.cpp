class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0) return res;
        deque<int> q;
        for (int i =0 ; i < nums.size(); i++){
            while (!q.empty() and q.front() <= i - k)
                q.pop_front();
            while(!q.empty() and nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};