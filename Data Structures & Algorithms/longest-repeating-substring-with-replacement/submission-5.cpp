class Solution {
public:
    int characterReplacement(string s, int k) {
    int n = s.length();
    int l = 0, r = 0;

    unordered_map<char, int> counts;
    char currMaxChar = -1;
    int currMaxCount = 0;
    int countRest = 0;

    char curr = -1;
    int maxInt = 0;
    while( r < n )
    {
        curr = s[r];
        int currCount = counts.count( curr ) ? counts[curr] : 0;
        int newMax = max( currMaxCount, currCount + 1 );
        if( currMaxChar == -1 || ( r - l + 1 ) - newMax <= k )
        {
            // include s[r]
            counts[curr]++;
            if( counts[curr] > currMaxCount )
            {
                currMaxCount = counts[curr];
                currMaxChar = curr;
                // recalculate countRest
                countRest = 0;
                for( const auto& [key, value] : counts )
                    if( key != curr )
                        countRest += value;
            }
            else
            {
                countRest++;
            }

            r++;
        }
        else
        {
            // drop s[l]
            maxInt = max( maxInt, r - l );
            curr = s[l];
            counts[curr]--;
            if( currMaxChar == curr ) currMaxCount--;
            // recalculate countRest and maybe currMaxChar/Count
            int sum = 0;
            for( const auto& [key, value] : counts )
            {
                sum += value;
                if( value > currMaxCount )
                {
                    currMaxCount = value;
                    currMaxChar = key;
                    // there will be no more values > (this new) currMaxCount
                    break;
                }
            }
            if( currMaxCount == 0 ) currMaxChar = -1;
            countRest = sum - counts[currMaxChar];
            
            l++;
        }
    }

    maxInt = max( maxInt, r - l );
    return maxInt;
    }
};
