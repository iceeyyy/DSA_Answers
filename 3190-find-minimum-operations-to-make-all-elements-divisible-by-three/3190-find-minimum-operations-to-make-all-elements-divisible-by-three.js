/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let cnt=0;

    for(let i=0;i<nums.length;i++){
        if(nums[i]%3==0) continue;
        else if(nums[i]%3==1){
            nums[i]--;
            cnt++;
        }
        else if(nums[i]%3==2){
            nums[i]++;
            cnt++;
        }
    }
    
    return cnt;
};