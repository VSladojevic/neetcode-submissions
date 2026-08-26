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

        map<int, vector<int>> allNodes;
        for( int i = 0; i < lists.size(); i++ )
        {
            ListNode* curr = lists[i];
            while( curr )
            {
                allNodes[curr->val].push_back( i );
                curr = curr->next;
            }
        }

        ListNode* mergedHead = nullptr;
        ListNode* merged = nullptr;


        for( const auto& [key, value] : allNodes )
        {
            for( int x : value )
            {
                // add k-th list node to merged
                if( mergedHead == nullptr )
                {
                    mergedHead = lists[x];
                    merged = mergedHead;
                    lists[x] = lists[x]->next;
                }
                else
                {
                    merged->next = lists[x];
                    lists[x] = lists[x]->next;
                    merged = merged->next;
                }
                merged->next = nullptr;
            }
        }


        return mergedHead;
    }
};
