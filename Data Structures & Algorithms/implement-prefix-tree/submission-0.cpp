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
};
