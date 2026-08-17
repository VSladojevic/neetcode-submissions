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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *curr, *next;
        curr=head;
        next=curr->next;
        curr->next = nullptr;
        while(next)
        {
            ListNode* tmp = curr;
            curr=next;
            next=next->next;
            curr->next=tmp;
        }

        // curr is new head
        return curr;
    }
};
