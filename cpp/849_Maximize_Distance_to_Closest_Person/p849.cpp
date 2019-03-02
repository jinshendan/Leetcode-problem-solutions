#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
            if(seats[i]) v.push_back(i);
        int ans = max(v[0] - 0, n-1-v[v.size()-1]);
        for (int i = 0; i < v.size()-1; i++){
            int p = (v[i] + v[i+1]) / 2;
            ans = max(ans, min(p-v[i], v[i+1] - p));
        }
        return ans;
        
    }
};