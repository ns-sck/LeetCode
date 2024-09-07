class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios::sync_with_stdio(0);
        queue<pair<TreeNode*, vector<int>>> q;
        vector<int> list;
        while (head) list.push_back(head->val), head = head->next;
        q.push({root, {root->val}});
        while (q.size()) {
            auto [t, v] = q.front();
            q.pop();
            if (v.size() >= list.size()) {
                int i = list.size() - 1, j = v.size() - 1;
                while (~i) {
                    if (i == 0 && list[i] == v[j]) return 1;
                    if (list[i] == v[j]) {
                        --i, --j;
                    } else break;
                }
            }
            if (t->left) {
                v.push_back(t->left->val);
                q.push({t->left, v});
                v.pop_back();
            }
            if (t->right) {
                v.push_back(t->right->val);
                q.push({t->right, v});
            }
        }
        return 0;
    }
};