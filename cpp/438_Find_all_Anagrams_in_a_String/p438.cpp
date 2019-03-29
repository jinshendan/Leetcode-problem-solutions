class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26, 0);
        int diff = 0;
        for(auto& c: p) {
            count[c - 'a']++;
            diff ++;
        }
        int n = s.length();
        int m = p.length();
     
        vector<int> ans;
        if (n < m) return ans;
        for (int i = 0; i < m; i++){
            if(count[s[i] - 'a']-- > 0) 
                diff --;
        }
        
       
        
        if (diff == 0) ans.push_back(0);
        
        for (int i = m; i < n; i++){
            if(++count[s[i-m] - 'a']> 0) diff++;
            if (count[s[i] - 'a']-- >0) diff--;
            if (diff == 0) ans.push_back(i-m+1);
        }
        return ans;
    }
};