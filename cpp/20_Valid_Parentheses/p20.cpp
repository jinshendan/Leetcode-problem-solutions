class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& c: s){
            if (c == '(' or c == '[' or c == '{')
                st.push(c);
            else{
                if (st.size() == 0) return false;
                char t = st.top();
                st.pop();
                if (c == ')' and t != '(') return false;
                if (c == ']' and t != '[') return false;
                if (c == '}' and t != '{') return false;
            }
        }
        return st.size() == 0;
    }
};