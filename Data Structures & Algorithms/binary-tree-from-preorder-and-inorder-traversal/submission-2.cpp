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
    TreeNode* buildTree( vector<int>& preorder, vector<int>& inorder ) {
        int pPRE = 0, pIN = 0;      // "pointers"
        int n = preorder.size();
        
        TreeNode* root = nullptr;
        TreeNode* last = nullptr;
        // if( n == 0 ) return root;
        stack<TreeNode*> nodes;
        int last_pPRE;
        
        while( pPRE < n )
        {
            last_pPRE = pPRE;
            while( preorder[pPRE] != inorder[pIN] )
            {
                pPRE++;
            }
            // preorder[pIN..pPRE]
            for( int i = last_pPRE; i <= pPRE; i++ )
            {
                if( i == last_pPRE )
                {
                    if( root != nullptr )
                    {
                        last->right = new TreeNode( preorder[i] );
                        last = last->right;
                    }
                    else
                    {
                        root = new TreeNode( preorder[i] );
                        last = root;
                    }
                }
                else
                {
                    last->left = new TreeNode( preorder[i] );
                    last = last->left;
                }

                nodes.push( last );
            }

            // move pIN
            while( !nodes.empty() && nodes.top()->val == inorder[pIN] )
            {
                last = nodes.top();
                nodes.pop();
                pIN++;
            }

            pPRE++;
        }
        


        return root;
    }
};
