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
    ListNode* doubleIt(ListNode* head) {
        node* tmp = head;
        int f = head->val;
        while (tmp) {
            int v = tmp->val;
            v *= 2; if (v>=10) v %= 10;
            if (tmp->next && tmp->next->val >= 5) ++v;
            tmp->val = v;
            tmp = tmp->next;
        }
        tmp = head;
        if (f >= 5) {
            head = new node(1);
            head->next = tmp;
        }
        return head;
    }
};