#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto& t: nums) sum ^= t;
        sum = sum & (-sum);
        vector<int> ans(2, 0);
        for (auto& t: nums) 
            if ((t & sum) == 0) ans[0] ^= t;
            else ans[1] ^= t;
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> nums = {2,1,2,3,4,1};
    vector<int> v = s->singleNumber(nums);
    for (int i = 0; i < 2; i++) cout << v[i] << endl;
    return 0;
}