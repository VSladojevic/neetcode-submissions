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
    // Recursive solution
    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        return ( p && q && p->val == q->val && isSameTree( p->left, q->left ) && isSameTree( p->right, q->right ) );
    }
    */

    // BFS solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // queue or stack
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);

        while(!queue1.empty())
        {
            TreeNode* node1 = queue1.front();
            queue1.pop();
            
            if(queue2.empty()) return false;
            TreeNode* node2 = queue2.front();
            queue2.pop();

            if(node1==nullptr && node2==nullptr) continue;
            if(node1==nullptr && node2!=nullptr) return false;
            if(node1!=nullptr && node2==nullptr) return false;
            if(node1->val != node2->val) return false;
            

            // push even if nullptr
            queue1.push(node1->left);
            queue1.push(node1->right);
            queue2.push(node2->left);
            queue2.push(node2->right);
        }

        if(!queue2.empty()) return false;

        return true;
    }
};
