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
    ListNode* removeNodes(ListNode* head) {
        ios::sync_with_stdio;
        stack<node*> st;
        node* t = head;
        while (t->next) {
            st.push(t);
            t = t->next;
        }
        int v = t->val;
        node* last = t;
    
        while (st.size()) {
            node* t2 = st.top();
            st.pop();
            if (t2->val < v) continue;
            t2->next = t;
            t = t2;
            v = t2->val;
            last = t2;
        }
        if (head->val < v) head = last;
        return head;
    }
};