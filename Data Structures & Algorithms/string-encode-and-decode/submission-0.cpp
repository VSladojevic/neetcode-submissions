class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string &s:strs)
        {
            res+=s+"|||";
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string curr="";
        while(s.size()>0)
        {
            int pos = s.find("|||");
            curr = s.substr(0, pos);
            strs.push_back(curr);
            s=s.substr(pos + 3);
        }
        return strs;
    }
};
