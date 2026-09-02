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

    void IN( TreeNode* root, vector<int>& nodes )
    {
        if( root->left )
            IN( root->left, nodes );
        nodes.push_back( root->val );
        if( root->right )
            IN( root->right, nodes );
    }

    bool isAscending( vector<int>& vec )
    {
        for( int i = 1; i < vec.size(); i++ )
        {
            if( vec[i] <= vec[i - 1] ) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {

        // In-order traversal
        vector<int> inOrder;
        IN( root, inOrder );

        return isAscending( inOrder );
    }
};
