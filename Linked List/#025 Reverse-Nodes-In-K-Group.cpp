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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Count nodes
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // If fewer than k nodes, no reversal
        if (count < k) return head;

        // Reverse first k nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int steps = k;

        while (steps-- && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect the rest
        // head is now the tail of reversed part
        head->next = reverseKGroup(curr, k);

        // prev is new head of reversed segment
        return prev;
    } 
};