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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            node* r = new node(val);
            r->left = root;
            return r; 
        }
        queue<pair<node*, int>> q;
        q.push({root, 1});
        while (q.size()) {
            node* ptr = q.front().first;
            int d = q.front().second;
            q.pop();
            if (!ptr) continue;
            if (depth - d == 1) {
                node* temp = ptr->left;
                ptr->left = new node(val);
                ptr->left->left = temp;
                temp = ptr->right;
                ptr->right = new node(val);
                ptr->right->right = temp;
                continue;
            }
            q.push({ptr->left, d+1});
            q.push({ptr->right, d+1});
        }
        return root;
    }
};