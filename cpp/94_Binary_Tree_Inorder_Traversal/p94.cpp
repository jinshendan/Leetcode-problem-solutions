class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root == NULL) return ans;
        auto r = root;
        while(r->left != NULL) {
            st.push(r);
            r = r->left;
        }
        st.push(r);
        
        while (!st.empty()){
            auto cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            auto r = cur->right;
            if (r != NULL){
                while(r ->left != NULL){
                    st.push(r);
                    r = r->left;
                }
                st.push(r);
            }
        }
        return ans;
    }
};