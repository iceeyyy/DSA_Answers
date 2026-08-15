function longestSubsequence(nums: number[]): number {
    let ans=0;
    let n=nums.length;
    let allZero=true;
    let resXor=0;

    for(let i=0;i<n;i++){
        resXor=resXor^nums[i];
        if(nums[i]!==0){
            allZero=false;
        }
    }

    if(allZero) return 0;

    return (resXor==0)?n-1:n;
};