class Solution {
public:
    class PrefixTree {
    public:
        // 26 characters 'a'-'z'

        struct Node {
            vector<Node*> key;
            bool isLeaf = false;
            Node() : key( 26, nullptr ) {}
        };

        Node* root;
        PrefixTree() {
            root = new Node();
        }

        void insert( string word ) {
            if( search( word ) ) return;
            
            Node* curr = root;
            for( int i = 0; i < word.size(); i++ )
            {
                char c = word[i] - 'a';
                
                if( curr->key[c] == nullptr )
                {
                    curr->key[c] = new Node();
                }
                curr = curr->key[c];
                
                if( i == word.size() - 1 )
                {
                    curr->isLeaf = true;
                }
            }

            return;
        }

        bool search( string word ) {
            Node* curr = root;
            int ind = -1;
            for( char& c : word )
            {
                ind = c - 'a';
                if( curr->key[ind] == nullptr ) return false;
                curr = curr->key[ind];
            }

            return curr->isLeaf;
        }

        bool startsWith( string prefix ) {
            Node* curr = root;
            int ind = -1;
            for( char& c : prefix )
            {
                ind = c - 'a';
                if( curr->key[ind] == nullptr ) return false;
                curr = curr->key[ind];
            }

            return true;
        }

            void remove( string word ) {
        removeHelper( root, word, 0 );
    }

        // Returns true if the child node can be deleted by its parent
        // (it is no longer a word end and has no remaining children).
        bool removeHelper( Node* curr, const string& word, int i ) {
            if( curr == nullptr ) return false;

            if( i == word.size() )
            {
                // Word not present if this node isn't a leaf; nothing to remove.
                if( !curr->isLeaf ) return false;
                curr->isLeaf = false;
            }
            else
            {
                int c = word[i] - 'a';
                Node* child = curr->key[c];
                if( child == nullptr ) return false; // word not present

                if( removeHelper( child, word, i + 1 ) )
                {
                    delete child;
                    curr->key[c] = nullptr;
                }
            }

            if( curr->isLeaf ) return false;
            for( Node* child : curr->key )
            {
                if( child != nullptr ) return false;
            }
            return curr != root;
        }
    };



void spreadAndFind( string& soFar, int j, int i, vector<vector<char>>& board, PrefixTree& tree, set<string>& found, set<pair<int, int>>& visited )
{
    if( tree.search( soFar ) )
    {
        found.insert( soFar );
        tree.remove( soFar );
    }
    visited.insert( { j,i } );

    string tmp = "";
    // for each neighbor
    if( i + 1 < board[0].size() && visited.find( { j,i + 1 } ) == visited.end() )
    {
        tmp = soFar + board[j][i + 1];
        if( tree.startsWith( tmp ) )
        {
            set<pair<int, int>> visitedCopy = visited;
            spreadAndFind( tmp, j, i + 1, board, tree, found, visitedCopy );
        }
    }
    if( i - 1 >= 0 && visited.find( { j,i - 1 } ) == visited.end() )
    {
        tmp = soFar + board[j][i - 1];
        if( tree.startsWith( tmp ) )
        {
            set<pair<int, int>> visitedCopy = visited;
            spreadAndFind( tmp, j, i - 1, board, tree, found, visitedCopy );
        }
    }
    if( j + 1 < board.size() && visited.find( { j + 1,i } ) == visited.end() )
    {
        tmp = soFar + board[j + 1][i];
        if( tree.startsWith( tmp ) )
        {
            set<pair<int, int>> visitedCopy = visited;
            spreadAndFind( tmp, j + 1, i, board, tree, found, visitedCopy );
        }
    }
    if( j - 1 >= 0 && visited.find( { j - 1,i } ) == visited.end() )
    {
        tmp = soFar + board[j - 1][i];
        if( tree.startsWith( tmp ) )
        {
            set<pair<int, int>> visitedCopy = visited;
            spreadAndFind( tmp, j - 1, i, board, tree, found, visitedCopy );
        }
    }

}

vector<string> findWords( vector<vector<char>>& board, vector<string>& words ) {
    PrefixTree tree = PrefixTree();
    for( auto& word : words )
    {
        tree.insert( word );
    }

    int x = board[0].size();
    int y = board.size();

    set<string> found;
    for( int j = 0; j < y; j++ )
    {
        for( int i = 0; i < x; i++ )
        {
            string s = "";
            s = board[j][i];
            if( tree.startsWith( s ) )
            {
                set<pair<int, int>> visited;
                spreadAndFind( s, j, i, board, tree, found, visited );
            }
        }
    }

    vector<string> v( found.begin(), found.end() );
    return v;
}
};
