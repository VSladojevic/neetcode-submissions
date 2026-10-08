class Solution {
public:
bool backtrack( vector<vector<char>>& board, int r, int c, string& word, int i ) {
    if( i == word.length() ) return true;
    if( r < 0 || c < 0 || r >= board.size() ||
        c >= board[0].size() || board[r][c] != word[i] )
        return false;

    board[r][c] = '*';
    bool ret = backtrack( board, r + 1, c, word, i + 1 ) ||
        backtrack( board, r - 1, c, word, i + 1 ) ||
        backtrack( board, r, c + 1, word, i + 1 ) ||
        backtrack( board, r, c - 1, word, i + 1 );
    board[r][c] = word[i];
    return ret;
}

/// Backtracking

bool exist( vector<vector<char>>& board, string word ) {
    int x = board.size();
    int y = board[0].size();
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < y; j++ )
        {
            if( board[i][j] != word[0] ) continue;
            // first letter ok, start backtracking
            bool found = backtrack( board,i,j, word, 0 );
            if( found ) return true;
        }
    }

    return false;
}
};
