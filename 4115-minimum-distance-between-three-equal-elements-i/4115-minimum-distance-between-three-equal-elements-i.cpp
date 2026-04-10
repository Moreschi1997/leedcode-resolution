class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> n_table;
        int min_dist = - 1;
            for(int i = 0; i < n; i++)
            {
                vector<int>& vec = n_table[nums[i]];
                    n_table[nums[i]].push_back(i);
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