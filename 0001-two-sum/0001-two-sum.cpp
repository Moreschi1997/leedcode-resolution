class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = target - nums[i];
            if(hash.find(sum) != hash.end()){
                return {hash[sum], i};
            }
            hash[nums[i]] = i;    
        }
        return{};
    }
};