class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // handle edge cases

        // count nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }
        k = k % count;
        if (k == 0) return head;

        // move to (count-k-1)-th node
        temp = head;
        int steps = count - k - 1;
        while (steps--) {
            temp = temp->next;
        }

        // Step 4: rearrange pointers
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};
