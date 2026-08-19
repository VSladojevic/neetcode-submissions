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

    void reorderList(ListNode* head) {
        /*
            Split into two lists, first half and second half
            reverse second half and then reconnect second half
            to the first half
        */

        ListNode *slow, *fast;
        slow=fast=head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split unitl slow
        ListNode* firstList = head;
        ListNode* secondList = head;
        while(secondList!=slow)
        {
            secondList = secondList->next;
        }

        // move past slow
        secondList = secondList->next;
        slow->next = nullptr;

        // reverse second half
        secondList = reverseList(secondList);
        

        // now reconnect
        while(firstList)
        {
            ListNode* prev = firstList;
            firstList = firstList->next;
            prev->next = secondList;
            ListNode* prev2 = secondList;
            if(secondList)
            {
                secondList = secondList->next;
                prev2->next = firstList; // firstList is nullptr
            }
        }


    }
};
