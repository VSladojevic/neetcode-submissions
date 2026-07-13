class Solution {
public:
    bool isPalindrome(string s) {

        string lowerCaseConcatenated;
        for(char& c:s)
        {
            if(c>='A' && c<='Z') lowerCaseConcatenated += c+'a'-'A';
            else if((c>='a' && c<='z') || (c>='0' && c<='9')) lowerCaseConcatenated += c;
        }

        cout << lowerCaseConcatenated;

        int i=0, n=lowerCaseConcatenated.size();
        for(i;i<n/2;i++)
        {
            if(lowerCaseConcatenated[i]!=lowerCaseConcatenated[n-1-i]) return false;
        }
        return true;
    }
};
