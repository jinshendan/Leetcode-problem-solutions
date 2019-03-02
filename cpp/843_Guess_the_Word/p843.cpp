/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int common(string s, string t){
        int num = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == t[i])
                num++;
        return num;
    }
    
    string pick_one(vector<string>& list){
        int best = 10000;
        string best_string;
        for (int i = 0; i < list.size(); i++){
            vector<int> len(7, 0);
            for (int j = 0; j < list.size(); j++)
                len[common(list[i], list[j])]++;
            int m = 0;
            for (auto& x: len) m = max(m, x);
            if (m < best) {
                best = m;
                best_string = list[i];
            }
        }
        return best_string;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> u = wordlist;
        for (int i = 0; i < 10; i++){
            string s = pick_one(u);
            int m = master.guess(s);
            vector<string> v;
            for (auto& x: u) if (common(x, s) == m) v.push_back(x);
            u = v;
        }
    }
};