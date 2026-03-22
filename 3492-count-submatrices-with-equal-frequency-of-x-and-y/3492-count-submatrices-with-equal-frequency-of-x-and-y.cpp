class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> counterX(n + 1,  vector<int>(m + 1, 0));
        vector<vector<int>> counterY(n + 1,  vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
               int isX = (grid[i][j] == 'X');
               int isY = (grid[i][j] == 'Y');

               counterX[i + 1][j + 1] = counterX[i + 1][j] + counterX[i][j + 1] - counterX[i][j] + isX;
               counterY[i + 1][j + 1] = counterY[i + 1][j] + counterY[i][j + 1] - counterY[i][j] + isY;

               if(counterX[i+1][j+1] > 0 && counterX[i+1][j+1] == counterY[i+1][j+1])
               {
                ans++;
               }
            }
        }
        return ans;
    }
};