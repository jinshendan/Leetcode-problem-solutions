/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(int sum, TreeNode* t, int tot, vector<int>& sol, vector<vector<int>>& ans){
        if (t -> left == NULL and t->right == NULL){
            if (sum == tot){
                ans.push_back(sol);
            }
            return;
        }     
        
        sol.push_back(-1);
        if (t->left != NULL) {
            sol[sol.size() - 1] = t->left->val;
            dfs(sum, t->left, tot+t->left->val, sol, ans);
        }
        if (t->right != NULL){
            sol[sol.size() - 1] = t->right->val;
            dfs(sum, t->right, tot+t->right->val, sol, ans);
        }
        sol.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> sol;
        sol.push_back(root->val);
        dfs(sum, root, root->val, sol, ans);
        return ans;
    }
};