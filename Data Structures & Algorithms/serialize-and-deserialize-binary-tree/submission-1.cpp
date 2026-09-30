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

class Codec {
public:

    std::vector<int> split( const std::string& s, char delim = ',' ) {
        std::vector<int> parts;
        std::stringstream ss( s );
        std::string token;
        while( std::getline( ss, token, delim ) ) {
            parts.push_back( std::stoi( token ) );
        }
        return parts;
    }


    // Encodes a tree to a single string.
    string serialize( TreeNode* root ) {
        queue<TreeNode*> queue;
        vector<int> array;

        if( root == nullptr ) return "";
        queue.push( root );
        array.push_back( root->val );

        while( !queue.empty() )
        {
            TreeNode* tmp = queue.front();
            queue.pop();

            if( tmp->left == nullptr )
            {
                array.push_back( INT_MAX );
            }
            else
            {
                array.push_back( tmp->left->val );
                queue.push( tmp->left );
            }

            if( tmp->right == nullptr )
            {
                array.push_back( INT_MAX );
            }
            else
            {
                array.push_back( tmp->right->val );
                queue.push( tmp->right );
            }
        }

        string s = "";
        for( int i = 0; i < array.size(); i++ )
        {
            s += to_string( array[i] );
            if( i != array.size() - 1 ) s += ",";
        }

        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize( string data ) {
        if( data == "" ) return nullptr;
        
        vector<int> array = split( data );
        TreeNode* root = new TreeNode( array[0] );
        
        TreeNode* curr = root;
        queue<TreeNode*> queue;
        queue.push( curr );
        int i = 1;
        while( i < array.size() )
        {
            curr = queue.front();
            queue.pop();
            int val = array[i];
            if( val == INT_MAX ) curr->left = nullptr;
            else
            {
                curr->left = new TreeNode( val );
                queue.push( curr->left );
            }
            i++;

            val = array[i];
            if( val == INT_MAX ) curr->right = nullptr;
            else
            {
                curr->right = new TreeNode( val );
                queue.push( curr->right );
            }
            i++;
        }

        return root;
    }

};
