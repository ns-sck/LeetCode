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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios::sync_with_stdio(0);
        node* ans = new node();
        node* tmp = ans;
        int c = 0;
        while (l1 && l2) {
            int t = l1->val + l2->val + c;
            tmp->next = new node(t%10);
            c = t / 10;
            tmp = tmp->next, l1 = l1->next, l2 = l2->next;
        }
        node* r = l1 ? l1 : l2;
        while (r) {
            int t = r->val + c;
            tmp->next = new node(t%10);
            c = t / 10;
            tmp = tmp->next, r = r->next;
        }
        if (c) tmp->next = new node(1);
        return ans->next;
    }   
};