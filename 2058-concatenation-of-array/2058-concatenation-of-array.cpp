class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(nums.size() * 2);
        int nums_found;
        for(int i = 0; i < n; i++)
        {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
    return ans;   
    }
};