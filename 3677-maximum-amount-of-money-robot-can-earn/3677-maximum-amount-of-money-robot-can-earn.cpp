class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<long long>> dp(m, vector<long long>(3, -1e17));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[j][0] = coins[i][j];
                    dp[j][1] = max(0LL, (long long)coins[i][j]);
                    dp[j][2] = max(0LL, (long long)coins[i][j]);
                    continue;
                } 
                
                vector<long long> old_up = dp[j];
                for (int k = 0; k < 3; k++) {
                    long long coming = -1e17;

                    if (i > 0) coming = max(coming, old_up[k]);
                    if (j > 0) coming = max(coming, dp[j - 1][k]);

                    
                    long long res_null = -1e17;
                    if (coming > -1e16) {
                        res_null = coming + coins[i][j];
                    }

                    long long res_power = -1e17;
                    if (k > 0 && coins[i][j] < 0) {
                        long long coming_prev = old_up[k - 1];
                        if (j > 0) coming_prev = max(coming_prev, dp[j - 1][k - 1]);

                        if (coming_prev > -1e16) {
                            res_power = coming_prev;
                        }
                    }
                    dp[j][k] = max(res_null, res_power);
                }
            }
        }
        
        long long final_res = max({dp[m - 1][0], dp[m - 1][1], dp[m - 1][2]});
        return (int)final_res;
    }
};