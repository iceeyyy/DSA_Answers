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

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        SegmentTree.resize(4 * n, 0); // declared globally and resized inside the function 
        build(0, 0, n - 1, nums);
    }

    int sumRange(int left, int right) {
        return sum(left, right, 0, 0, n - 1);
    }
};
