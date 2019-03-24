class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        vector<int> dict(256, 0);
        int counter = 0;
        for (auto & c : t) {
            if (++dict[c] == 1)
                counter ++;
        }
        
        int l = 0, r = 0;
        int len = INT_MAX, first = -1;
        while (r < n){
            if (dict[s[r++]]-- == 1) counter--;
            while(counter == 0){
                if (r - l < len){
                    len = r - l;
                    first = l;
                }
                if(dict[s[l++]]++ == 0) counter ++; 
            }
        }
        return (len == INT_MAX)?"":s.substr(first, len);
    }
};