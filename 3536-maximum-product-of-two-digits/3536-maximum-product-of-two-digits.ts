function maxProduct(n: number): number {
    let num:string[]=n.toString().split("");
    let nums:number[]=num.map((x)=>Number(x));

    nums.sort((a,b)=>a-b); //ascending order

    return nums[nums.length-1]*nums[nums.length-2];
};