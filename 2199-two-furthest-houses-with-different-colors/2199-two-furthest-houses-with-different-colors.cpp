class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDis = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(colors[i] != colors[j])
                {
                    int distance = abs(i - j);
                    if(distance > maxDis)
                    {
                        maxDis = distance;
                    }
                }
            }
        }
        return maxDis;    
    }
};