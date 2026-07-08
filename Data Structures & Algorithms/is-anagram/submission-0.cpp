class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> chars1, chars2;
        for(char c: s) chars1[c]=chars1[c]+1;
        for(char c: t) chars2[c]=chars2[c]+1;
        return chars1==chars2;
    }
};
