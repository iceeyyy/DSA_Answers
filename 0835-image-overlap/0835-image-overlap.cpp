class Solution {
public:
    int countOverLaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int col_offset,int row_offset){
        int n=img1.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int img2I=i+row_offset;
                int img2J=j+col_offset;
                if(img2I<0||img2I>=n||img2J<0||img2J>=n) continue;
                if(img1[i][j]==1 && img2[img2I][img2J]==1) count++;
            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int n=img1.size();

        for(int rowOff=-n+1;rowOff<n;rowOff++){
            for(int colOff=-n+1;colOff<n;colOff++){
                int cnt=countOverLaps(img1,img2,rowOff,colOff);
                ans=max(ans,cnt);
            }
        }

        return ans;
    }
};