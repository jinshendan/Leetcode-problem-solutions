class Solution {
public:
    bool isValid(string S) {
        
        while (S.find("abc") != string::npos){
            S.replace(S.find("abc"), 3, "");
        }
        return S == "";
    }
};