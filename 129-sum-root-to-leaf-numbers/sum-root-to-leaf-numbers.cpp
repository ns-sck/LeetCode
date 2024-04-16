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
    int sumNumbers(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            TreeNode* ptr = q.front().first;
            int v = q.front().second * 10 + ptr->val;
            q.pop();
            if (!ptr->left && !ptr->right) {
                ans += v;
                cout << v << '\n';
                continue;
            }
            if (ptr->left) {
                q.push({ptr->left, v});
            }
            if (ptr->right) {
                q.push({ptr->right, v});
            }
        }
        return ans;
    }
};