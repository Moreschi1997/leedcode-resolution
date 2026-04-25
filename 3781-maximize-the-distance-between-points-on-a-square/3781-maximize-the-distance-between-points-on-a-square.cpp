class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> p(n);
        long long perimeter = 4LL * side;

        // 1. ConversÃ£o ultra-rÃ¡pida
        for (int i = 0; i < n; ++i) {
            long long x = points[i][0], y = points[i][1];
            if (y == 0) p[i] = x;
            else if (x == side) p[i] = side + y;
            else if (y == side) p[i] = 2LL * side + (side - x);
            else p[i] = 3LL * side + (side - y);
        }

        sort(p.begin(), p.end());

        // 2. DuplicaÃ§Ã£o seletiva (ou apenas tratar com mÃ³dulo, mas duplicar Ã© mais rÃ¡pido para o cache)
        for (int i = 0; i < n; ++i) {
            p.push_back(p[i] + perimeter);
        }

        // 3. Busca BinÃ¡ria Otimizada
        long long low = 1, high = perimeter / k, ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            bool possible = false;

            // OTIMIZAÃÃO CRÃTICA: 
            // SÃ³ testamos pontos de partida no primeiro intervalo 'mid'. 
            // Se nÃ£o conseguirmos comeÃ§ar aqui, nÃ£o conseguiremos em lugar nenhum.
            for (int i = 0; i < n; ++i) {
                if (p[i] > p[0] + mid) break; 

                int count = 1;
                long long last = p[i];
                int curr = i;

                for (int j = 1; j < k; ++j) {
                    // Usamos lower_bound mas com um 'hint' de busca mais prÃ³ximo
                    auto it = lower_bound(p.begin() + curr + 1, p.begin() + i + n, last + mid);
                    if (it == p.begin() + i + n) {
                        count = -1;
                        break;
                    }
                    last = *it;
                    curr = distance(p.begin(), it);
                    count++;
                }

                if (count == k && (p[i] + perimeter - last >= mid)) {
                    possible = true;
                    break;
                }
            }

            if (possible) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};