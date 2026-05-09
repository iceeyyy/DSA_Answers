class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int layers=min(m/2,n/2);

        for(int layer=0;layer<layers;layer++){
            vector<int> nums;
            int top=layer;
            int bottom=n-layer-1;
            int left=layer;
            int right=m-layer-1;
            //top row
            for(int i=left;i<=right;i++){
                nums.push_back(grid[top][i]);
            }
            //right col
            for(int i=top+1;i<=bottom-1;i++){
                nums.push_back(grid[i][right]);
            }
            //bottom row
            for(int i=right;i>=left;i--){
                nums.push_back(grid[bottom][i]);
            }
            //left col
            for(int i=bottom-1;i>=top+1;i--){
                nums.push_back(grid[i][left]);
            }
            int len=nums.size();
            int normK=k%len;

            int idx=0;
            rotate(nums.begin(),nums.begin()+normK,nums.end());

            for(int i=left;i<=right;i++){
                grid[top][i]=nums[idx++];
            }
            for(int i=top+1;i<=bottom-1;i++){
                grid[i][right]=nums[idx++];
            }
            for(int i=right;i>=left;i--){
                grid[bottom][i]=nums[idx++];
            }
            for(int i=bottom-1;i>=top+1;i--){
                grid[i][left]=nums[idx++];
            }
        }

        return grid;
    }
};