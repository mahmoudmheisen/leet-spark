/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int sum = 0;
    void traverse(TreeNode* root, int low, int high) {
        if(!root) return;
        if(root->val >= low && root->val <= high) sum += root->val;
        if(root->left) traverse(root->left, low, high);
        if(root->right) traverse(root->right, low, high);
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root, low, high);
        
        return sum;
    }
};