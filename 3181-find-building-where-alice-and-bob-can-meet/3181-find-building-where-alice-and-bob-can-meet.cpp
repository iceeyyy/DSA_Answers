class Solution {
public:
    void buildTree(int i ,int l ,int r,vector<int>& SegmentTree, vector<int>& input){
    if(l==r){
        SegmentTree[i] = r;
        return;
    }

    int mid=l+(r-l)/2;
    buildTree(2*i+1,l,mid,SegmentTree,input);
    buildTree(2*i+2,mid+1,r,SegmentTree,input);

    int leftIdx=SegmentTree[2*i+1];
    int rightIdx=SegmentTree[2*i+2];

    SegmentTree[i] = (input[leftIdx]>=input[rightIdx])? leftIdx : rightIdx;
    
    }

    int RMIQ(int i,int l,int r,int a,int b,vector<int>& SegmentTree,vector<int>& heights ){
        if(l > b || r < a){
            return -1; // Out of bounds
        }
        if(l >= a && r <= b) {
            return SegmentTree[i]; // Fully within range
        }
        int mid=l+(r-l)/2;
        int leftIdx=RMIQ(2*i+1,l,mid,a,b,SegmentTree,heights);
        int rightIdx=RMIQ(2*i+2,mid+1,r,a,b,SegmentTree,heights);

        if(leftIdx==-1) return rightIdx;
        else if(rightIdx==-1){
            return leftIdx;
        }

        return (heights[leftIdx]>=heights[rightIdx])? leftIdx : rightIdx;

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        size_t n=heights.size();
        vector<int> SegmentTree(4*n);
        buildTree(0,0,n-1,SegmentTree,heights);
        vector<int> res;

        for(auto query:queries){
            int minIdx=min(query[0],query[1]);
            int maxIdx=max(query[0],query[1]);

            if(query[0]==query[1]){
                //standing at same idx
                res.push_back(query[0]);
                continue;
            }
            else if (heights[maxIdx]>heights[minIdx]){
                res.push_back(maxIdx);
                continue;
            }

            int l=maxIdx+1;
            int r=n-1;
            int result_idx=INT_MAX;

            while(l<=r){
                int mid=l+(r-l)/2;
                int idx=RMIQ(0,0,n-1,l,mid,SegmentTree,heights);

                if(heights[idx]>max(heights[maxIdx],heights[minIdx])){
                    result_idx=min(result_idx,idx);
                    
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }

            }
            if(result_idx==INT_MAX) res.push_back(-1); //not possible
            else{
                res.push_back(result_idx);
            }

            
        }
        return res;
    }
};