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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL and root->right == NULL) return 1;
        int sum = INT_MAX;
        if (root->left != NULL) sum = min(sum, minDepth(root->left));
        if (root->right != NULL) sum = min(sum, minDepth(root->right));
        return sum + 1;
    }
};