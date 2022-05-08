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
public:
    // inorder traverse should return sorted data
    bool isBST(TreeNode* root, TreeNode*& prev) {
      if (!root) return true;
            
      // if (root->left && root->left->val >= root->val) return false;
      if (!isBST(root->left, prev)) return false;
      // if(prev)cout << prev->val <<endl;
      // here it will print sorted array and we need prev node
      if (prev && root->val <= prev->val) return false;
      
      prev = root;
      return isBST(root->right, prev); // when u go right, the prev is the root
    }
  
    bool isValidBST(TreeNode* root) {
      if (!root) return true;
      TreeNode *prev = NULL;
      return isBST(root, prev);
    }
};