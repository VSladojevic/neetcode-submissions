class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;

        while( l <= r )
        {
            mid = l + ( r - l ) / 2;
            if( target == nums[mid] ) return mid;
            if( nums[mid] < nums[r] )
            {
                if( target > nums[mid] && target <= nums[r] )
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                // l to mid is ascending
                if( target >= nums[l] && target < nums[mid] )
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
