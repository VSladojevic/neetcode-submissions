class Solution {
public:
    unordered_map<char,int> charsWord(string& str)
    {
        unordered_map<char, int> chars;
        for(char c: str) chars[c] = chars[c]+1;
        return chars;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char,int>> listChars;
        for(string& s: strs)
        {
            listChars.push_back(charsWord(s));
        }

        vector<vector<string>> groups;
        vector<string> currentGroup;
        vector<bool> visited(strs.size(), 0);

        int curr = 0;
        while(curr<strs.size())
        {
            if(visited[curr])
            {
                curr++;
                continue;
            }
            
            visited[curr] = 1;
            currentGroup.push_back(strs[curr]);
            for(int i=0;i<strs.size();i++)
            {
                if(i!=curr && !visited[i])
                {
                    if(listChars[i]==listChars[curr])
                    {
                        currentGroup.push_back(strs[i]);
                        visited[i]=1;
                    }
                }
            }
            groups.push_back(currentGroup);
            curr++;
            currentGroup.clear();
        }

        return groups;
        
    }
};
