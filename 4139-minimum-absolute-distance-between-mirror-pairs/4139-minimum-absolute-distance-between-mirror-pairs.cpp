class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int minDistance = INT_MAX;
        std::unordered_map<int, int> lastSeen;
        int n = nums.size();
    
            for(int i = 0; i < n; i++)
            {
                long long x = nums[i];
                long long reverseNum = 0;
                while(x > 0)
                {
                    reverseNum = (reverseNum * 10) + (x % 10);
                    x /= 10;
                }
                if(lastSeen.count(nums[i]))
                {
                    int distance = i - lastSeen[nums[i]];
                    if(distance < minDistance)
                    {
                        minDistance = distance;
                    }
                }
            lastSeen[reverseNum] = i;
            }
    return (minDistance == INT_MAX) ? -1 : minDistance; 
    }
};