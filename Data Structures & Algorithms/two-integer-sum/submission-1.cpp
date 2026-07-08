class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numPos;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            numPos[nums[i]]=i;
        }        

        for(int i=0;i<n;i++)
        {
            int rest = target-nums[i];
            if(numPos.find(rest)!=numPos.end() && numPos[rest]!=i)
            {
                return {i,numPos[rest]};
            }
        }
    }
};
