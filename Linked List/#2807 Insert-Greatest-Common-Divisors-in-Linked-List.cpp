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
    int gcd(int a ,int b)
    {
        a = abs(a);
        b = abs(b);
        while(b!=0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
    return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
            ListNode * prev = head;
            ListNode * curr = prev->next;
            while(curr)
            {
                ListNode * gcdNode = new ListNode(gcd(prev->val,curr->val));
                gcdNode->next = prev->next;
                prev->next = gcdNode;
                prev = curr ;
                curr = prev->next;
            }
        return head;
    }
};