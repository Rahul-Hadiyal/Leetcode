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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n==0) return head;
        // for count
        int count = 0;
        struct ListNode* temp = head;
        while (temp)
        {
            temp = temp->next ;
            count ++;
        }
        // traverse from 0 to count - n
        temp = head;
        int space = count - n-1;

        if (count == n)
        {
            struct ListNode * newHead = head->next;
            delete(head);
            return newHead;
        } 
        while (space--)
        {
            temp = temp->next;
        }
        struct ListNode *post = temp->next;
        temp->next = post->next;
        delete(post);
        return head;  
    }
};