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
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios::sync_with_stdio(0);
        ListNode* t = head;
        while (t->next) {
            int x = t->val, y = t->next->val;
            ListNode* n = new ListNode(gcd(x, y));
            n->next = t->next;
            t->next = n;
            t = n->next;
        }
        return head;
    }
};