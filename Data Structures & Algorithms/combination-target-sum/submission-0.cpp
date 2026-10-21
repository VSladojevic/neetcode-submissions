class Solution {
public:
    vector<vector<int>> results;

    void combine( vector<int>& nums, int target, vector<int>& current, int i )
    {
        if( target < 0 || i >= nums.size() ) return;

        if( target == 0 )
        {
            results.push_back( current );
            return;
        }

        current.push_back( nums[i] );
        combine( nums, target - nums[i], current, i );
        current.pop_back();
        combine( nums, target, current, i + 1 );
    }

    vector<vector<int>> combinationSum( vector<int>& nums, int target ) {
        vector<int> current;
        combine( nums, target, current, 0 );

        return results;
    }
};
