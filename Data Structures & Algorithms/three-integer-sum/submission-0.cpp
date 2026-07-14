class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> valInd;
        for(int i=0;i<nums.size();i++)
        {
            valInd[nums[i]] = i;
        }

        set<vector<int>> triplets;
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
            {
                int curr = nums[i]+nums[j];
                int target = 0-curr;
                if(valInd[target] && valInd[target]!=i && valInd[target]!=j)
                {
                    vector<int> v = {nums[i],nums[j],target};
                    sort(v.begin(), v.end());
                    triplets.insert( v );
                }
            }

        vector<vector<int>> tripletsVec;
        for(auto& a:triplets)
        {
            tripletsVec.push_back(a);
        }
        return tripletsVec;

    }
};
