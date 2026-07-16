class Solution {
public:
    int calcSize(vector<int>& heights, int l, int r)
    {
        int min = heights[l]<heights[r]?heights[l]:heights[r];
        return (r-l) * min;
    }

    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        
        int curr=0, max=0;
        max = calcSize(heights, l, r);
        while(l<r)
        {
            if( heights[l]<=heights[r] ) l++;
            else r--;
            curr = calcSize(heights, l,r);
            if(curr>max) max=curr;
        }

        return max;
    }
};
