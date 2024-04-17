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
#define node TreeNode
class Solution {
public:

    string ans = "";
    void dfs(node* ptr, string s) {
        if (!ptr) return;
        s += ('a' + ptr->val);
        if (!ptr->left && !ptr->right) {
            reverse(s.begin(), s.end());
            ans = min(ans, s);
        } else {
            dfs(ptr->left, s);
            dfs(ptr->right, s);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        char c = 'z' + 1;
        ans += c;
        dfs(root, "");
        return ans;
    }
};