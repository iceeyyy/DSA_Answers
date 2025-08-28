class Solution {
public:
    int n;
    
    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
        vector<int> vec; //diagonal elements starting from [r][c]

        int i = r;
        int j = c;

        while(i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) {
            sort(begin(vec), end(vec));
        } else {
            sort(rbegin(vec), rend(vec));
        }

        i = r;
        j = c;
        for(int &val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        //Bottom Left - Non-Increasing Order
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }


        //Top Right - Non-Decreasing Order
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};