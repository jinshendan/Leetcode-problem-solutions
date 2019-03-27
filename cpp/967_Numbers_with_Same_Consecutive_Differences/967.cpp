class Solution {
public:
    vector<int> ans;
    void dfs(int N, int K, int i, int x, vector<int>& ans){        
        if (i == N){
            ans.push_back(x);
            return;
        }
        
        if (i < N){
            int last  = x % 10;
            if (last + K < 10) dfs(N, K, i+1, x * 10 + (last + K), ans);
            
            if (K != 0 and last - K >= 0) dfs(N, K, i+1, x * 10 + (last - K) , ans);
        }   
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if (N == 1) ans.push_back(0);
        for (int x = 1; x < 10; x++)
            dfs(N,K, 1, x, ans);  
        return ans;
    }
}; 