class WordDictionary {
public:
    // 26 characters 'a'-'z'

    struct Node {
        vector<Node*> key;
        bool isLeaf = false;
        Node() : key( 26, nullptr ) {}
    };

    Node* root;
    WordDictionary() {
        root = new Node();
    }

    void addWord( string word ) {
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

    bool search( string word, Node* c=nullptr ) {
        Node* curr = (c == nullptr) ? root : c;
        int ind = -1;
        for( char& c : word )
        {
            if( c == '.' )
            {
                for( char a = 'a'; a <= 'z'; a++ )
                {
                    if( curr->key[a - 'a'] == nullptr ) continue;
                    bool res = search( word.substr( &c - &word[0] + 1 ), curr->key[a - 'a']);
                    if( res ) return true;
                }
                return false;
            }
            else
            {
                ind = c - 'a';
                if( curr->key[ind] == nullptr ) return false;
                curr = curr->key[ind];
            }
        }

        return curr->isLeaf;
    }
};