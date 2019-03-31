class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0 or N == 1) return to_string(N);
        return baseNeg2(-(N >> 1)) + to_string(N & 1);
    }
};