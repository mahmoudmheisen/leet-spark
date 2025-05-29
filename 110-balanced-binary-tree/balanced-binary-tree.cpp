/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) { 
        return treeHeight(root) != -1; 
    }

    int treeHeight(TreeNode* root) {
        if (!root)
            return 0;

        int leftH = treeHeight(root->left);
        int rightH = treeHeight(root->right);

        if (leftH == -1 || rightH == -1)
            return -1;
        if (abs(leftH - rightH) > 1)
            return -1;

        return 1 + max(leftH, rightH);
    }
};
