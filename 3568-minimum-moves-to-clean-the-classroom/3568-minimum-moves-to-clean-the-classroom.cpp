class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int, int>> litter;
        int sr = 0, sc = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } 
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; ++i) {
            auto [r, c] = litter[i];
            id[r][c] = i;
        }

        int totalMask = 1 << k;
        int cells = m * n;

        vector<int> best(totalMask * cells, -1);

        struct State {
            int r, c, mask, e;
        };

        queue<State> q;

        int startPos = sr * n + sc;
        best[startPos] = energy;

        q.push({sr, sc, 0, energy});

        int moves = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == totalMask - 1)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (id[nr][nc] != -1)
                        nmask |= (1 << id[nr][nc]);

                    int pos = nr * n + nc;
                    int idx = nmask * cells + pos;

                    if (best[idx] >= ne)
                        continue;

                    best[idx] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }
            ++moves;
        }
        return -1;
    }
};