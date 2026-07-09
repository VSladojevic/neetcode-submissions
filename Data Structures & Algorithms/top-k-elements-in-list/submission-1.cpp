class Solution {
public:
    struct Compare
    {
        bool operator()(const std::pair<int, int>& a,
                        const std::pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a hashmap
        // Sort the hashmap - instead of "sorting",
        // iterate through hashmap and add elements into priroty queue

        unordered_map<int, int> numsCount;
        for(int& x: nums) numsCount[x] = numsCount[x]+1;


        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            Compare
        > numsSorted;


        for(auto it=numsCount.begin(); it!=numsCount.end(); ++it)
        {
            numsSorted.push({it->first, it->second});
        }

        vector<int> mostFrequent;
        while(k--)
        {
            int num = numsSorted.top().first;
            numsSorted.pop();
            mostFrequent.push_back(num);
        }

        return mostFrequent;
    }
};
