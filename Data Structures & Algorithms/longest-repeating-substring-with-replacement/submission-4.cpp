class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_map<char, int> counts;
    int n = s.length();
    int l = 0;
    int maxFreq = 0;
    int maxInt = 0;

    for( int r = 0; r < n; r++ )
    {
        counts[s[r]]++;
        maxFreq = max( maxFreq, counts[s[r]] );   // never decreased

        // shrink only while the window is invalid
        while( ( r - l + 1 ) - maxFreq > k )
        {
            counts[s[l]]--;
            l++;
        }

        maxInt = max( maxInt, r - l + 1 );
    }

    return maxInt;
    }
};
