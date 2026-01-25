function minimumDifference(nums: number[], k: number): number {
    nums.sort((a,b)=>a-b);
    let i:number=0;
    let j:number=i+k-1;
    
    let ans:number=Infinity;
    while(j<nums.length){
        ans=Math.min(ans,nums[j]-nums[i]);
        i++;
        j++;
    }

    return ans;
};