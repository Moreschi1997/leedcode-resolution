class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        int maxDist = 0;
        for(int i = 0, j = 0; i < n && j < m; j++)
        {
          if(nums1[i] <= nums2[j])
          {
            int currentDist = j - i;
            if(currentDist > maxDist)
            {
                maxDist = currentDist;
            }
          }
          else
          {
            i++;
          }  
        }
    return maxDist;
    }
};