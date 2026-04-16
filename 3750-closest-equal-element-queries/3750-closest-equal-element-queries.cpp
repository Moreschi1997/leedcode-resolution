class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> answer;
        std::unordered_map<int, vector<int>> numsPos;
        for(int i = 0; i < n; i++)
        {
            numsPos[nums[i]].push_back(i);
        }

        for(int i = 0; i < m; i++)
        {
            int index = queries[i];
            int valuer = nums[index];

            const vector<int>& position = numsPos[valuer];

            if(position.size() == 1)
            {
                answer.push_back(-1);
                continue;
            }

            auto it = lower_bound(position.begin(), position.end(), index);
            int p = distance(position.begin(), it);

            int checkLeft;
            if(p == 0)
            {
                checkLeft = position.back();
            }
            else
            {
                checkLeft = position[p - 1];
            }

            int checkRight;
            if (p == position.size() - 1) 
            {
                checkRight = position[0];
            } 
            else 
            {
                checkRight = position[p + 1];
            }

            int calculationDis1 = abs(index - checkLeft);
            int distL = min(calculationDis1, n - calculationDis1);

            int calculationDis3 = abs(index - checkRight);
            int distR = min(calculationDis3, n - calculationDis3);

            int res = min(distL, distR);
            answer.push_back(res);
        }
    return answer;
    }
};