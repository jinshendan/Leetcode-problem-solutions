class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream iss(sentence);
        string s;
        unordered_set<string> q(dict.begin(), dict.end());
        string ans;
        
        while(iss >> s){
            int ok = 0;
            for (int i = 1; i <= s.length(); i++)
                if (q.find(s.substr(0, i)) != q.end()) {
                    ok = 1;
                    ans += s.substr(0, i) + " ";
                    break;
                }
            if (!ok) ans += s + " ";
        }
        return ans.substr(0, ans.length()-1);
    }
};