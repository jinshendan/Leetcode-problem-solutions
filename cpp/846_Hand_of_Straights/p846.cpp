#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        
        if (n % W != 0) return false;
        map<int, int> num;
        for (auto& x: hand) num[x] ++;
        sort(hand.begin(), hand.end());
        
        int i = 0;

        while(i < n){
            int t = num[hand[i]];
            num[hand[i]] = 0;
            for (int j = hand[i]+1; j < hand[i]+W; j++)
                if (num[j] < t) return false;
                else num[j] -= t;
            
            while(i < n and num[hand[i]] == 0) i++;
        }
            
        return true;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> hand = {1,1,2,2,3,3};
    int w = 3;
    cout << s->isNStraightHand(hand, w) << endl;
}