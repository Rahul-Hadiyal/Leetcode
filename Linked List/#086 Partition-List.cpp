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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode * smallhead = nullptr;
        ListNode * bighead = nullptr;
        ListNode * small = nullptr;
        ListNode * big = nullptr;
        ListNode * temp = head;
        while(temp)
        {
            ListNode * nextNode = temp->next;
            temp->next = nullptr;
            if(temp->val < x)
            {
                if(!smallhead)
                {
                    smallhead = temp;
                    small = temp;
                }
                else
                {
                    small->next = temp;
                    small = small->next;
                }
            }
            else
            {
                if(!bighead)
                {
                    bighead = temp;
                    big = temp;
                }
                else
                {
                    big->next = temp;
                    big = big->next;
                }
            }
            temp = nextNode;
        } 
        if(small)
        {
            small->next = bighead;
            return smallhead;
        }
        else
        {
            return bighead;
        }
        return head;
        
    }
};