class Solution {
public:
    vector<int> parent;

    int find(int x)
    {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if(root_j != root_i)
        {
            parent[root_i] = root_j;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for(int i = 0; i < allowedSwaps.size(); i++)
        {
            unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        unordered_map<int, unordered_map<int, int>> counts;

        for(int i = 0; i < n; i++)
        {
            counts[find(i)][source[i]]++;
        }

        int distance = 0;
        for(int i = 0; i < n; i++)
        {
            int root = find(i);
            int num = target[i];

            if(counts[root][num] > 0)
            {
                counts[root][num]--;
            }
            else
            {
                distance++;
            }
        }
    return distance;
    }
};