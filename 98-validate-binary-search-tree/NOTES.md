class Solution {
bool recursive(TreeNode root, TreeNode lowerBound, TreeNode upperBound) {
if (!root) {
return true;
}
if (lowerBound && root->val <= lowerBound->val) {
return false;
}
if (upperBound && root->val >= upperBound->val) {
return false;
}
return recursive(root->left, lowerBound, root) &&
recursive(root->right, root, upperBound);
}
public:
bool isValidBST(TreeNode root) {
return recursive(root, NULL, NULL);
}
};**