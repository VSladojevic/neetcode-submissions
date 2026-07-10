class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lp=1, rp=1;
        int n = nums.size();

        vector<int> left;
        for(int i=0;i<n;i++)
        {
            lp*=nums[i];
            left.push_back(lp);
        }

        vector<int> right;
        for(int j=n-1;j>=0;j--)
        {
            rp*=nums[j];
            right.insert(right.begin(), rp);
        }

        vector<int> prod;
        for(int i=0;i<n;i++)
        {
            if(i>0 && i<n-1)
                prod.push_back(right[i+1]*left[i-1]);
            else if(i==0)
                prod.push_back(right[i+1]);
            else if(i==n-1)
                prod.push_back(left[i-1]);
        }

        return prod;
    }
};
