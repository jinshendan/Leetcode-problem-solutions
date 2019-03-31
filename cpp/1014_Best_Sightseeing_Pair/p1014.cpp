class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++)
            A[i] += i;
        int maxv = A[0];
        int ans = 0;
        for (int j = 1; j < n; j++){
            if (A[j] + maxv - 2 * j > ans)
                ans = A[j] + maxv - 2*j;
            if (A[j] > maxv) maxv = A[j];
        }
        return ans;
    }
};