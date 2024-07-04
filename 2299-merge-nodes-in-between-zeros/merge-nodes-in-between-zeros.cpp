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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(0);
        node* p = head;
        node* ans = new node();
        node* p2 = ans;
        int t = 0;
        while (p) {
            t += p->val;
            if (p->val == 0 && t) {
                p2->next = new node(t);
                p2 = p2->next;
                t = 0;
            }
            p = p->next;
        }
        return ans->next;
    }
};