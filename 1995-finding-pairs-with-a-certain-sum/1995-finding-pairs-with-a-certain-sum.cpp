class FindSumPairs {
public:
    vector<int> arr1,arr2;
    unordered_map<int,int>mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(auto it:nums2){
            mp[it]++;   //insert freq of elements in map
        }
    }
    
    void add(int index, int val) {
        mp[arr2[index]]--;
        arr2[index]+=val;
        mp[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;

        for(int i=0;i<arr1.size();i++){

            if(mp.find(tot-arr1[i]) != mp.end()){
                cnt+=mp[tot-arr1[i]]; //add freq of element to count
            }
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */