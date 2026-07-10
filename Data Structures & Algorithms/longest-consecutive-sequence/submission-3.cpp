class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> hashmap;
        for(int& x:nums) hashmap[x]=1;

        int curr=0, max=0;
        int prev = hashmap.begin()->first - 1;
        for(auto const& [key, val]: hashmap)
        {
            if(key==prev+1) curr++;
            else
            {
                if(curr>max) max=curr;
                curr=1;
            }
            prev=key;
        }        

        if(curr>max) max=curr;

        return max;
    }
};
