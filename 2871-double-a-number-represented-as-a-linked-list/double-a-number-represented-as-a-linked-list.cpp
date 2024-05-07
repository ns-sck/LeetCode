class Solution {
public:
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; 
    }
    
    ListNode* doubleIt(ListNode* head) {
    if (!head) return head; // Handle empty list

    head = reverse(head); // Reverse the list

    ListNode* temp = head;
    int carry = 0;
    while (temp != nullptr) {
        temp->val = (temp->val * 2) + carry;
        carry = temp->val / 10;
        temp->val %= 10;
        temp = temp->next;
    }
    
    if (carry > 0) {
       
        ListNode* newNode = new ListNode(carry);
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return reverse(head); // Reverse the list back to its original order
}
};