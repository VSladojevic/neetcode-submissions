class Solution {
public:
    string minWindow( string s, string t ) {
        unordered_map<char, int> letters;
        int lWin = -1, rWin = -1;
        int cntWindow = 0;

        for( char& c : t )
        {
            if( letters.find( c ) != letters.end() ) letters[c] = letters[c] + 1;
            else letters[c] = 1;
        }

        int i = 0;
        while( i < s.size() && letters.find( s[i] ) == letters.end() ) i++;
        if( i == s.size() ) return "";

        // letters.find(s[i]) != letters.end()
        lWin = i;
        letters[s[i]] = letters[s[i]] - 1;
        cntWindow++;
        i++;
        while( i < s.size() && cntWindow != t.size() )
        {
            if( letters.find( s[i] ) != letters.end() )
            {
                if( letters[s[i]] > 0 )
                {
                    letters[s[i]] = letters[s[i]] - 1;
                    cntWindow++;
                }
            }
            i++;
        }

        if( cntWindow < t.size() && i == s.size() ) return "";

        // try to make lWin better
        for( auto& pair : letters ) {
            pair.second = 0;
        }
        for( char& c : t )
        {
            if( letters.find( c ) != letters.end() ) letters[c] = letters[c] + 1;
            else letters[c] = 1;
        }

        cntWindow = 0;
        int j;
        for( j = i - 1; j >= 0 && cntWindow<t.size(); j-- )
        {
            if( letters.find( s[j] ) != letters.end() )
            {
                if( letters[s[j]] > 0 )
                {
                    letters[s[j]] = letters[s[j]] - 1;
                    cntWindow++;
                }
            }
        }

        if( j >= lWin )
        {
            lWin = j + 1;
        }

        for( auto& pair : letters ) {
            pair.second = 0;
        }
        for( int k = lWin; k < i; k++ )
        {
            if( letters.find( s[k] ) != letters.end() )
            {
                letters[s[k]] = letters[s[k]] + 1;
            }
        }
        for( char& c : t )
        {
            letters[c] = letters[c] - 1;
        }
    

        // rWin points to element just after window
        rWin = i;
        int min = rWin - lWin;
        int minL = lWin;

        while(i<s.size())
        {
            char leftCh = s[lWin];
            while( i < s.size() )
            {
                if( s[i] == leftCh )
                {
                    rWin = ++i;
                    lWin++;
                    while( lWin < s.size() )
                    {
                        if( letters.find( s[lWin] ) != letters.end() )
                        {
                            if( letters[s[lWin]] > 0 ) letters[s[lWin]] = letters[s[lWin]] - 1;
                            else
                            {
                                // stop
                                int currMin = rWin - lWin;
                                if( currMin < min )
                                {
                                    min = currMin;
                                    minL = lWin;
                                }
                                leftCh = s[lWin];
                                break;
                            }
                        }
                        lWin++;
                    }
                }
                else
                {
                    if( letters.find( s[i] ) != letters.end() )
                    {
                        letters[s[i]] = letters[s[i]] + 1;
                    }
                    i++;
                }
            }
        }


        return s.substr( minL, min );
    }
};