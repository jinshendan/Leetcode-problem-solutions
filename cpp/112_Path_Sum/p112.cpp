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
    bool hasPathSum(TreeNode* root, int sum) {
       if (root == NULL) return false;
       if (root->left == NULL and root->right == NULL) return (sum == root->val);
       bool ok = false;
       if (root->left != NULL) ok = ok or hasPathSum(root->left, sum - root->val);
       if (root->right != NULL) ok = ok or hasPathSum(root->right, sum - root->val);
       return ok;
    }
};