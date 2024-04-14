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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,bool>> q;
        q.push({root, 0});
        while (q.size()) {
            TreeNode* nd = q.front().first;
            bool b = q.front().second;
            q.pop();
            if (!nd->left && !nd->right && b) ans += nd->val;
            if (nd->left) q.push({nd->left, 1});
            if (nd->right) q.push({nd->right, 0});
        }
        return ans;
    }
};