class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string t;
        while(iss >> t) {}
        return t.length();
    }
};