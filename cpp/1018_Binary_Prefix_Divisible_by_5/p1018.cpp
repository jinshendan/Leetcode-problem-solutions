class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> ans(n);
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum = (sum * 2 + A[i]) % 5;
            ans[i] = (sum == 0);
        }
        return ans;
    }
};