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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        long long width = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            int levelSize = q.size();

            long long lIdx = q.front().second;
            long long rIdx = q.back().second;
            width = max(width, rIdx - lIdx + 1);

            for (int i = 0; i < levelSize; i++) {
                pair<TreeNode*, long long> pair = q.front();
                TreeNode* node = pair.first;
                long long j = pair.second - lIdx;
                q.pop();

                if (node->left)
                    q.push(make_pair(node->left, 2 * j + 1));
                if (node->right)
                    q.push(make_pair(node->right, 2 * j + 2));
            }
        }

        return width;
    }
};