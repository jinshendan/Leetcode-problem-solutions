class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.length();
        int num = 0;
        string ans = S;
        for (int i = n - 1; i >= 0; i--){
            num  = (num + shifts[i]) % 26;
            ans[i] = ((S[i] + num) - 'a') % 26 + 'a';
        }
        return ans;
    }
};