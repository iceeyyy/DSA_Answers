function solve(i:number,target:number,nums:number[],dp:number[][],sum:number):number{
    if (target < -sum || target > sum) return 0; //out of bonds
    if(i===nums.length){
        if(target===0) return 1;
        return 0;
    } 
    if(dp[i][target+sum]!==-1) return dp[i][target+sum];
    let ways=0;

    ways=solve(i+1,target+nums[i],nums,dp,sum)+solve(i+1,target-nums[i],nums,dp,sum);

    return dp[i][target+sum]=ways;
}
function findTargetSumWays(nums: number[], target: number): number {
    let n:number = nums.length;
    let totalSum:number = nums.reduce((a,b)=>a+b,0);
    let dp:number[][] =  Array.from({length:n+1},()=>{
       return Array.from({length:2*totalSum+1},()=> -1);
    });
    return solve(0,target,nums,dp,totalSum);
};