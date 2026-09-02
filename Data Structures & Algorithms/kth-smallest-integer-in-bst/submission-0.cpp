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

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        IN( root, inOrder );

        return inOrder[k-1];
    }
};
