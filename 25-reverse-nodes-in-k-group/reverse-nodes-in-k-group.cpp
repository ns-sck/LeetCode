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
    ListNode* reverseKGroup(ListNode* head, int k) {
        node* temp = head;
        node* prev = nullptr;
        node* nxt = nullptr;
        stack<node*> st;
        bool b = 0;
        while (temp) {
            for (int i = 0; i < k-1; ++i) {
                if (!temp) break;
                st.push(temp);
                temp = temp->next;
            }
            if (!temp) break;
            if (prev) prev->next = temp;
            nxt = temp->next;
            if (!b) head = temp; 
            b = 1;
            while (st.size()) {
                temp->next = st.top(); st.pop();
                temp = temp->next;
            }
            prev = temp;
            temp->next = nxt;
            temp = temp->next;
        }
        return head;
    }
};