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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
    int pos = 1;
    ListNode * curr = head;
    ListNode * prev = nullptr;
    ListNode * temp = head;
        while (pos < left){
        prev = temp;
        temp = temp->next;
        pos++;
    }
    ListNode * leftprev = prev;
    ListNode * leftNode = temp;
    ListNode * prevnew = nullptr;
        ListNode * next = nullptr;
    while(pos<=right){
        next = temp->next;
        temp->next = prevnew;
        prevnew = temp;
        temp = next;
        pos++;

    }
    if (leftprev != nullptr){
        leftprev->next = prevnew;
    }
    else {
        head = prevnew;
    }
    leftNode->next = temp;
    return head ;
    }
};