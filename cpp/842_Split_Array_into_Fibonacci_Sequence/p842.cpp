#include <bits/stdc++.h>
using namespace std;

class Solution {    
public:
    long long get_number(string s){
        long long ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans = ans * 10 + (s[i] - '0');
        return ans;
    }
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 0; i < S.length(); i++){
            long long a = get_number(S.substr(0, i+1));
            if (a > INT_MAX or (S[0] == '0' and a > 0)) break;
            
            for (int j = i + 1; j < S.length(); j++){
                long long b = get_number(S.substr(i+1, j-i));
                if (b > INT_MAX or (S[i+1] == '0' and b > 0)) break;
                string t = S.substr(0, j+1);
                vector<int> v = {int(a), int(b)};
                
                long long c;
                long long ta = a;
                long long tb = b;
                while(1){
                    c = ta + tb;
                    if (c > INT_MAX) break;
                    
                    t += to_string(c);
                    v.push_back(c);
                    if (t.length() >= S.length()) break;
                    ta = tb;
                    tb = c;
                }
                if (c < INT_MAX and t.length() == S.length() and t == S) return v;
            }
        }
        return vector<int>();
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> v = s->splitIntoFibonacci("0123");
    for (auto& x: v) cout << x << " ";
    cout << endl;
    return 0;
}