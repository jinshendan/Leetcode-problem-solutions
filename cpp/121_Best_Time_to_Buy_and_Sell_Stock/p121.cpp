class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int biggest = prices[n-1];
        int best = 0;
        for (int i = n - 2 ; i >= 0; i--) {
            best = max(best, biggest - prices[i]);
            biggest = max(biggest, prices[i]);
        }
        return best;
    }
};