class Solution {
public:
    bool check(int a, int b, vector<vector<int>>& grid){
        set<int> s;
        for (int i = a; i < a + 3; i++){
            int sum_row = 0;
            for (int j = b; j < b + 3; j++){
                sum_row += grid[i][j];
                if (grid[i][j] < 0 or grid[i][j] > 9) return false;
                s.insert(grid[i][j]);
            }
            if (sum_row != 15) return false;
        }
        if (s.size() != 9) return false;
        
        for (int j = b; j < b+3; j++){
            int sum_column = 0;
            for (int i = a; i < a + 3; i++)
                sum_column += grid[i][j];
            if (sum_column != 15) return false;
        }
        if (grid[a][b] + grid[a+1][b+1] + grid[a+2][b+2] != 15) return false;
        if (grid[a][b+2] + grid[a+1][b+1] + grid[a+2][b] != 15) return false;
        return true;
    }
        
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for (int i = 0; i < n - 2; i++) 
            for (int j = 0; j < m - 2; j++)
                if (check(i, j, grid)) sum++;
        return sum;
    }
};