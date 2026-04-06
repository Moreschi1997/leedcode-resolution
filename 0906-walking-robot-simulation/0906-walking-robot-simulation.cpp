class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int n = commands.size();

        set<pair<int, int>> obsSet;
        for(int i = 0; i < obstacles.size(); i++)
        {
            obsSet.insert({obstacles[i][0], obstacles[i][1]});
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int x = 0, y = 0, d = 0;
        int maxDist = 0;

        for(int i = 0; i < n; i++)
        {
            int cmd = commands[i];
            if(cmd == -1)
            {
                d = (d + 1) % 4;
            }
            else if(cmd == -2)
            {
                d = (d + 3) % 4;
            }
            else
            {
                for (int j = 0; j < cmd; j++) {
                    int nextX = x + dx[d];
                    int nextY = y + dy[d];
                    
                    if (obsSet.count({nextX, nextY})) break;
                    
                    x = nextX;
                    y = nextY;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
    return maxDist;
    }
};