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
// function for reverse the list
    ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l1;
    if (!l2) return l2;
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int carry = 0;

    // add digit by digit
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // reverse result to restore forward order
    return reverse(head);
        
    }
};