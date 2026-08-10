class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_map<char, int> charCount;
        int l=0, r=1;
        int n=s.length();
        charCount[s[l]] = 1;
        int maxL = r-l;
        char left, right;
        while(r<n)
        {
            left = s[l];
            right = s[r];
            // want to include char[r]
            if(charCount.count(right) && charCount[right] > 0 )
            {
                // we can't add, need to move l until this char is dropped
                charCount[left] = charCount[left] - 1; 
                l++;
            }
            else
            {
                charCount[right] = 1;
                r++;
                maxL = max(maxL, r-l);
            }
        }

        return maxL;
    }
};
