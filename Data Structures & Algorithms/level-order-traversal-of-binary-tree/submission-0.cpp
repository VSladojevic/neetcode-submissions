/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS
        if(root==nullptr) return {};
        vector<vector<int>> nodesByLevels;
        int currentLevel = 0;
        int currentIndex = -1;

        queue<pair<TreeNode*,int>> bfs;
        bfs.push( make_pair(root,1) );

        while( !bfs.empty() )
        {
            pair<TreeNode*,int> tmp = bfs.front();
            bfs.pop();
            int nodeLvl = tmp.second;
            if( nodeLvl > currentLevel )
            {
                nodesByLevels.push_back( vector<int>{ tmp.first->val } );
                currentLevel = nodeLvl;
                currentIndex++;
            }
            else
            {
                nodesByLevels[currentIndex].push_back( tmp.first->val );
            }

            if( tmp.first->left )
                bfs.push( make_pair( tmp.first->left, tmp.second + 1 ) );
            if( tmp.first->right )
                bfs.push( make_pair( tmp.first->right, tmp.second + 1 ) );
            

        }

        return nodesByLevels;       
    }
};
