class NumArray {
private:
    vector<int> SegmentTree;
    int n;

    void build(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            SegmentTree[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);
        SegmentTree[i] = SegmentTree[2 * i + 1] + SegmentTree[2 * i + 2];
    }

    int sum(int left, int right, int i, int l, int r) {
        // no overlap
        if (right < l || left > r) return 0;
        // total overlap
        if (left <= l && r <= right) return SegmentTree[i];
        // partial overlap
        int mid = (l + r) / 2;
        return sum(left, right, 2 * i + 1, l, mid) +
               sum(left, right, 2 * i + 2, mid + 1, r);
    }
    void updateTree(int i,int l ,int r ,int idx,int val){
        if(l==r){
            SegmentTree[i]=val;
            return;
        }
        int mid = (l+r)/2;

        if(idx<=mid){//left side
            updateTree(2*i+1,l,mid,idx,val);
        }
        else{
            updateTree(2*i+2,mid+1,r,idx,val);
        }
        SegmentTree[i]=SegmentTree[2*i+1] + SegmentTree[2*i+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        SegmentTree.resize(4*n,0);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sum(left, right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */