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
private:
    TreeNode* lca;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);

        return lca;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        bool isPQ = root == p || root == q;

        bool leftPQ = dfs(root->left, p, q);
        bool rightPQ = dfs(root->right, p, q);

        if(isPQ+leftPQ+rightPQ >= 2) lca = root;

        return isPQ || leftPQ || rightPQ;
    }
};