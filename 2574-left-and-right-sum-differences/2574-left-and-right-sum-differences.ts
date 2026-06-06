function leftRightDifference(nums: number[]): number[] {
    let n=nums.length;

    let leftSum=Array.from({length:n},()=>0);
    let rightSum=Array.from({length:n},()=>0);
    let ans=Array.from({length:n},()=>0);

    for(let i=0;i<n;i++){
        let lSum=0;
        for(let j=0;j<i;j++){
            lSum+=nums[j];
        }
        leftSum[i]=lSum;
    }

    for(let i=0;i<n;i++){
        let rSum=0;
        for(let j=i+1;j<n;j++){
            rSum+=nums[j];
        }
        rightSum[i]=rSum;
    }

    for(let i=0;i<n;i++){
        ans[i]=Math.abs(leftSum[i]-rightSum[i]);
    }

    return ans;
    
};