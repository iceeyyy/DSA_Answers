class Solution {
    int n;
    vector<vector<int>> t;

public:

    //Can only move diagonally
    int child1Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;
            t[i][i] = 0;
        }
        return ans;
    }

    int child2Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        
        //can't go beyond diagonal or left to diagonal (only have n-1 moves)
        if (i == j || i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner = grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = max({middle, rightcorner, leftcorner});
    }

    int child3Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        //can't go beyond diagonal or right to diagonal (only have n-1 moves)
        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int topcorner   = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right       = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = max({right, rightcorner, topcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        t.resize(n, vector<int>(n, -1));

        // First child
        int firstChildScore = child1Collect(grid);

        // Second child
        int secondChildScore = child2Collect(0, n - 1, grid);

        // Third child
        int thirdChildScore  = child3Collect(n - 1, 0, grid);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }    
};