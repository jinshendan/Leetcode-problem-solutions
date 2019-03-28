class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, int>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            pq.push(make_pair(-matrix[i][0], i));
        }
        
        vector<int> v(n, 0);    
        int val = -1;
        int i;
        for (int j = 0; j < k; j++){
            val = -pq.top().first;
            i = pq.top().second;
            pq.pop();
            if (v[i] < n-1)         
                pq.push(make_pair(-matrix[i][++v[i]], i));
        }
        return val; 
    }
};