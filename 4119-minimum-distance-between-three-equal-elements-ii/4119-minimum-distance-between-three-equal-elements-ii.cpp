class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = -1;
        unordered_map<int, vector<int>> hashTable;

        for(int i = 0; i < n; i++)
        {
            vector<int>& vec = hashTable[nums[i]];
            hashTable[nums[i]].push_back(i);
            if(vec.size() >= 3)
            {
                int dist = (vec.back() - vec[vec.size() - 3]) * 2;

                if(min_dist == -1 || dist < min_dist)
                {
                    min_dist = dist;
                }
            }
        }
    return min_dist;
    }
};