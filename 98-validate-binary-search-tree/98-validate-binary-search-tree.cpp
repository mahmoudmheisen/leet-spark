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
    TreeNode* prev = nullptr;
  
  public:
    // inorder traverse should return sorted data
    bool isValidBST(TreeNode* root) {
      if (!root) return true;
      
      if (!isValidBST(root->left)) return false;
      
      // here it will print sorted array and we need prev node
      if (prev && root->val <= prev->val) return false;

      prev = root;
      return isValidBST(root->right); // when u go right, the prev is the root
    }
};