class Solution {
public:
    int smallestRepunitDivByK(int K) {
        vector<int> s(K, 0);
        int num = 1;
        int i = 1;
        while(1){
            if (num % K == 0) return i;
            s[num] = 1;
            num = (num * 10 + 1) % K;
            if (s[num]) return -1;
            i++;
        }
    }
};