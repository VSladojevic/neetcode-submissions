class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> distinct;
        for( int x: nums)
        // or & for the actual nums element
        // for(int& x: nums)
        {
            if(distinct.find(x)!=distinct.end())
            {
                // Found
                return true;
            }
            else
            {
                distinct.insert(x);
            }
        }

        return false;
    }
};