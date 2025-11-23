/**
 * @param {number[]} nums
 * @return {number}
 */
var solve=function(i,rem,nums,dp){
    if(i>=nums.length){
        if(rem==0) return 0;
        return -Infinity;
    }
    if(dp[i][rem]!=-1) return dp[i][rem];

    let take = nums[i]+solve(i+1,((rem+nums[i])%3),nums,dp);
    let notTake = solve(i+1,rem,nums,dp);

    dp[i][rem]=Math.max(take,notTake);

    return dp[i][rem];
}
var maxSumDivThree = function(nums) {
    let n = nums.length;
    let dp =[];

    for(let i=0;i<n;i++){
        dp[i]=[];
        for(let j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }

    return solve(0,0,nums,dp);

};