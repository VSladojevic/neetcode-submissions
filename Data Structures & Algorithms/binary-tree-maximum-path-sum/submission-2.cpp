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
    int maxPathSumIncludingRoot( TreeNode* root, int& max )
    {
        int right = root->right == nullptr ? 0 : maxPathSumIncludingRoot( root->right, max );
        int left = root->left == nullptr ? 0 : maxPathSumIncludingRoot( root->left, max );

        // must include root node
        int curr = root->val;

        max = std::max( { curr, curr + left, curr + right,curr + left + right, max } );
        return std::max( { curr, curr + left, curr + right, 0 } );
    }

    int maxPathSum( TreeNode* root ) {
        int max = INT_MIN;
        maxPathSumIncludingRoot( root, max );
        return max;
    }
};
