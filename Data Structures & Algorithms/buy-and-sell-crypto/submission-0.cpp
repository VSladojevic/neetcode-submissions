class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0;
        int r=1;
        int maxP=0;
        while(r<n)
        {
            if(prices[r]>prices[l])
            {
                maxP=max(maxP, prices[r]-prices[l]);
            }
            else
            {
                l=r;
            }
            r++;
        }

        return maxP;
    }
};
