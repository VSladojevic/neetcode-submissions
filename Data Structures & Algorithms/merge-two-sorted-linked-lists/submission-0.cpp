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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* merged, *mergedHead;
        if(list1->val<list2->val) 
        {
            merged = list1;
            list1=list1->next;
        }
        else
        {
            merged = list2;
            list2=list2->next;
        }
        mergedHead = merged;

        ListNode* tmp;
        while(list1 && list2)
        {

            if( list1->val < list2->val )
            {
                tmp = list1;
                list1 = list1->next;
                merged->next = tmp;
                merged = merged->next;
            }
            else
            {
                tmp = list2;
                list2 = list2->next;
                merged->next = tmp;
                merged = merged->next;
            }
        }

        if(!list1)
        {
            merged->next = list2;
        }
        else // if !list2
        {
            merged->next = list1;
        }

        return mergedHead;
    }
};
