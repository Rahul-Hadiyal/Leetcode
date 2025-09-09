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
ListNode * reverselist(ListNode * head)
{
    ListNode * prev = nullptr;
    ListNode * curr = head;
    while (curr)
    {
        ListNode * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    
}
    ListNode* doubleIt(ListNode* head) {
        head = reverselist(head);
        int carry = 0;
        ListNode * curr = head;
        while (curr)
        {
            int newVal = curr->val*2 + carry;
            curr->val = newVal%10;
            carry = newVal/10;
            if(!curr->next && carry > 0)
            {
                curr->next = new ListNode(carry);
                break;
            }
            curr = curr->next;
        }
        return reverselist(head);   
    }
};