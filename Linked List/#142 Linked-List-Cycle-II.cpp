/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd's Cycle Detection Method
        ListNode * slow = head; // 1 steps
        ListNode * fast = head; // 2 steps

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // cycle detected
            {
                slow = head; // reset slow
                while(slow !=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // cycle start node
            } 
        }
        return nullptr; // no cycle
    }
};
