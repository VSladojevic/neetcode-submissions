class Solution {
public:

string minWindow( string s, string t ) {
    int n = s.length();
    unordered_map<char, int> freqT;
    int required = 0;
    for( char c : t ) {
        if (freqT[c] == 0) required++;
        freqT[c]++; 
    }

    unordered_map<char, int> freq;
    int formed = 0;
    int minWin = 1000001;
    int minL = 0, minR = 0;
    int l = 0, r = 0;

    while( r < n )
    {
        char c = s[r];
        freq[c]++;
        if (freqT.count(c) && freq[c] == freqT[c]) {
            formed++;
        }

        while (l <= r && formed == required) {
            if (r - l + 1 < minWin) {
                minWin = r - l + 1;
                minL = l; minR = r + 1;
            }
            
            char leftChar = s[l];
            freq[leftChar]--;
            if (freqT.count(leftChar) && freq[leftChar] < freqT[leftChar]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    return minWin == 1000001 ? "" : s.substr( minL, minR - minL );
}
};