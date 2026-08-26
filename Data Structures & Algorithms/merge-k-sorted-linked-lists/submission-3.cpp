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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
                priority_queue<pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>> minHeap;

        int k = lists.size();
        ListNode* mergedHead = nullptr, * merged = nullptr;
        for( int i = 0; i < k; i++ )
        {
            if(lists[i])
                minHeap.push( make_pair( lists[i]->val, lists[i] ) );
        }

        while( !minHeap.empty() )
        {
            pair<int, ListNode*> top = minHeap.top();
            minHeap.pop();

            
            if( mergedHead == nullptr )
            {
                mergedHead = top.second;
                merged = mergedHead;
            }
            else
            {
                merged->next = top.second;
                merged = merged->next;
            }
            

            ListNode* curr = top.second;
            if( curr->next )
            {
                pair<int, ListNode*> next = make_pair( curr->next->val, curr->next );
                minHeap.push( next );
                curr->next = nullptr;
            }
            
        }

        return mergedHead;
    }
};
