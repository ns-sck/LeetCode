/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define node ListNode
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios::sync_with_stdio(0);
        
        node* ans = new node(-1);
        node* temp = ans;
        priority_queue<pair<int, node*>, vector<pair<int, node*>>, greater<>> pq;
        for (auto& h : lists) if (h) pq.push({h->val, h});
        while (pq.size()) {
            auto [v, ptr] = pq.top();
            pq.pop();
            temp->next = new node(v);
            temp = temp->next;
            if (ptr->next) pq.push({ptr->next->val, ptr->next});
        }
        return ans->next;
    }
};