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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        curr = reverseList(curr);

        ListNode* start = curr;
        
        int i=1;
        ListNode* prev = nullptr;
        while(i++<n)
        {
            prev = curr;
            curr = curr->next;
        }

        if(prev)
        {
            prev->next = curr->next;
            curr->next = nullptr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            prev->next = nullptr;
        }

        if(n==1) start=curr;
        start = reverseList(start);

        return start;

    }
};
