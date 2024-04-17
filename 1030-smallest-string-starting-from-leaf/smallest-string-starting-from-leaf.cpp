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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<node*, string>> q;
        string ans = "";
        ans += root->val + 'a';
        q.push({root, ans});
        char c = 'z';
        ++c;
        ans = c;
        while (q.size()) {
            node* ptr = q.front().first;
            string s = q.front().second;
            q.pop();
            if (!ptr->left && !ptr->right) {
                reverse(s.begin(), s.end());
                cout << s << '\n';
                ans = min({ans, s});
                continue;
            }
            if (ptr->left) {
                string n = s;
                n += ptr->left->val + 'a';
                q.push({ptr->left, n});
            }
            if (ptr->right) {
                s += ptr->right->val + 'a';
                q.push({ptr->right, s});
            }
        }
        return ans;
    }
};