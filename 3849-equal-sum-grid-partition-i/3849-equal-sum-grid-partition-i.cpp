class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       long long sum = 0;
            for(int i = 0; i < n; i++)
            {
                    for(int j = 0; j < m; j++)
                    {
                        sum += grid[i][j];
                    }
            }
        if(sum % 2 != 0)
        {
            return false;
        }
        long long totalSum =  sum / 2;
        long long currentHorizontalSum = 0;
        long long currentVerticalSum = 0;
        for(int i = 0; i < n - 1; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    currentHorizontalSum += grid[i][j];
                }
                if(currentHorizontalSum == totalSum)
                {
                    return true;
                }
            }

        for(int j = 0; j < m - 1; j++)
            {
                for(int i = 0; i < n; i++)
                {
                    currentVerticalSum += grid[i][j];
                }
                if(currentVerticalSum == totalSum)
                {
                    return true;
                }
            }
    return false;
    }
};