function maximumProduct(nums: number[]): number {
    nums.sort((a,b)=>a-b);
    let n=nums.length;
    return Math.max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
};