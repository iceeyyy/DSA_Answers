function solve(x:number,y:number,coins:number[][],neutralize:number,dp:number[][][]):number{
    let n=coins.length;
    let m=coins[0].length;

    if(x >= n || y >= m) return -Infinity; //out of bonds

    if(x===n-1 && y===m-1) { //base case 
        if (coins[x][y]>=0) return coins[x][y];
        else return neutralize > 0 ? 0 : coins[x][y];
    }
    if(dp[x][y][neutralize]!=null) return dp[x][y][neutralize];

    if(coins[x][y]>=0){
        let down=coins[x][y]+solve(x+1,y,coins,neutralize,dp);
        let right=coins[x][y]+solve(x,y+1,coins,neutralize,dp);
        return dp[x][y][neutralize]=Math.max(down,right);
    }
    else if(coins[x][y]<0){
        let takeDown=coins[x][y]+solve(x+1,y,coins,neutralize,dp);
        let takeRight=coins[x][y]+solve(x,y+1,coins,neutralize,dp);

        let skipDown = -Infinity;
        let skipRight = -Infinity;

        if(neutralize>0){
            skipDown=solve(x+1,y,coins,neutralize-1,dp);
            skipRight=solve(x,y+1,coins,neutralize-1,dp);
        }
        return dp[x][y][neutralize]=Math.max(takeDown,takeRight,skipDown,skipRight);
    }
}
function maximumAmount(coins: number[][]): number {
    let n=coins.length;
    let m=coins[0].length;

    let dp:number[][][] = Array.from({length:n},()=>{
        return Array.from({length:m},()=>{
            return Array.from({length:3},()=>null);
        })
    });

    return solve(0,0,coins,2,dp);
};