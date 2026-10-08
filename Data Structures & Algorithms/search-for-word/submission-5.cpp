class Solution {
public:
bool backtrack( int i, int j, vector<vector<char>>& board, string& word, int wordInd )
{
    if( wordInd == word.size() - 1 ) return true;
    board[i][j] = '*';

    if( i - 1 >= 0 && board[i - 1][j] == word[wordInd + 1] )
    {
        if( backtrack( i - 1, j, board, word, wordInd + 1 ) ) return true;
    }

    if( i + 1 < board.size() && board[i + 1][j] == word[wordInd + 1] )
    {
        if( backtrack( i + 1, j, board, word, wordInd + 1 ) ) return true;
    }

    if( j - 1 >= 0 && board[i][j - 1] == word[wordInd + 1] )
    {
        if( backtrack( i, j - 1, board, word, wordInd + 1 ) ) return true;
    }

    if( j + 1 < board[0].size() && board[i][j + 1] == word[wordInd + 1] )
    {
        if( backtrack( i, j + 1, board, word, wordInd + 1 ) ) return true;
    }
    
    board[i][j] = word[wordInd];

    return false;
}



bool exist( vector<vector<char>>& board, string word ) {
    int x = board.size();
    int y = board[0].size();
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < y; j++ )
        {
            if( board[i][j] != word[0] ) continue;
            // first letter ok, start backtracking
            vector<vector<char>> boardCopy = board;
            bool found = backtrack( i, j, boardCopy, word, 0);
            if( found ) return true;
        }
    }

    return false;
}
};
