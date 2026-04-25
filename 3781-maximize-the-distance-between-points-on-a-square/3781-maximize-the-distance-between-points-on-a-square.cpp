class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> linearPoints;
        for (int i = 0; i < points.size(); i++) {
            long long p1 = points[i][0];
            long long p2 = points[i][1];
            long long pos = 0;

            if (p2 == 0) pos = p1;
            else if (p1 == side) pos = (long long)side + p2;
            else if (p2 == side) pos = 2LL * side + (side - p1);
            else pos = 3LL * side + (side - p2);
            
            linearPoints.push_back(pos);
        }

        long long perimeter = 4LL * side;
        sort(linearPoints.begin(), linearPoints.end());
        int n = linearPoints.size();
        for (int i = 0; i < n; i++) {
            linearPoints.push_back(linearPoints[i] + perimeter);
        }

        long long low = 1, high = perimeter / k;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            bool possivel = false;

            
            for (int i = 0; i < n; i++) {
            
                if (linearPoints[i] > linearPoints[0] + mid) break;

                int count = 1;
                long long lastPos = linearPoints[i];

                for (int j = 1; j < k; j++) {
                    auto it = lower_bound(linearPoints.begin() + i + 1, 
                                          linearPoints.begin() + i + n, 
                                          lastPos + mid);
                    
                    if (it == linearPoints.begin() + i + n) {
                        count = -1;
                        break;
                    }
                    lastPos = *it;
                    count++;
                }

                if (count == k && (linearPoints[i] + perimeter - lastPos >= mid)) {
                    possivel = true;
                    break;
                }
            }

            if (possivel) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};