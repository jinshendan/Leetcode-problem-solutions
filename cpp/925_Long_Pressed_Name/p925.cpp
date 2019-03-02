class Solution {
public:
    vector<pair<char, int>> get_id(string s){
        char c = s[0];
        int num = 1;
        vector<pair<char,int>> ans;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == c) num++;
            else {
                ans.push_back(make_pair(c, num));
                c = s[i];
                num = 1;
            }
        }
        ans.push_back(make_pair(c, num));
        return ans;
    }
    
    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int>> u = get_id(name);
        vector<pair<char, int>> v = get_id(typed);
        if (u.size() != v.size()) return false;
        for (int i = 0; i < u.size(); i++)
            if (u[i].first != v[i].first or u[i].second > v[i].second)
                return false;
        return true;
    }
};