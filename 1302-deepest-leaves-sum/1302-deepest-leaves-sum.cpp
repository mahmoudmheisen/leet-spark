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
    int height(TreeNode* root) {
        if(!root) return 0;
        
        int hl = height(root->left);
        int hr = height(root->right);
        
        return max(hl, hr) + 1;
    }
    
    void solve(TreeNode* root, int& sum, int height, int level) {
        if(!root) return;
        
        if(level == height && !root->left && !root->right) sum += root->val;
        
        solve(root->left, sum, height, level+1);
        solve(root->right, sum, height, level+1);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int h = height(root);
        solve(root, sum, h, 1);
        
        cout << sum << endl;
        
        return sum;
    }
};
