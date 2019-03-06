class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> ltime(n, 0), rtime(n, 0);
        int last = -1;
        for (int i = 0; i < n; i++)
            if (dominoes[i] == 'R')
                last = i;
            else if (dominoes[i] == '.'){
                if (last == -1)
                    rtime[i] = INT_MAX;
                else
                    rtime[i] = i - last;
            }
            else last = -1;
                
        last = -1;
        for (int i = n-1; i>=0; i--)
            if (dominoes[i] == 'L')
                last = i;
            else if (dominoes[i] == '.'){
                if (last == -1)
                    ltime[i] = INT_MAX;
                else ltime[i] = last - i;
            }
        else last = -1;
        
        for (int i = 0; i < n; i++){
            if (dominoes[i] == '.'){
                if (ltime[i] < rtime[i]) dominoes[i] = 'L';
                else if (ltime[i] > rtime[i]) dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};