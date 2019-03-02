#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_next(string S, int last){
        int ignore = 0;
        for(int i = last; i>=0; i--){
            if (S[i] == '#') ignore ++;
            else if (ignore) ignore --;
            else return i;
        }
        return -1;
    }
    
    bool backspaceCompare(string S, string T) {
        int last_S = S.length() - 1;
        int last_T = T.length() - 1;
        while(1){
            int s = get_next(S, last_S);
            int t = get_next(T, last_T);
            if (s < 0 and t >= 0) return false;
            if (t < 0 and s >= 0) return false;
            if (s < 0 and t < 0) return true;
            if (S[s] != T[t]) return false;
            last_S = s - 1;
            last_T = t - 1;
        }
        return true;
    }
};

int main() {
    Solution* s = new Solution();
    cout << s->backspaceCompare("a#c##b", "b") << endl;
    return 0;
}