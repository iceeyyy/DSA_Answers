
function maxProfit(prices: number[]): number {
    let n:number = prices.length;

    let dp:number[][][][] = Array.from({length:n+1},()=>{
        return Array.from({length:2},()=>{
            return Array.from({length:2},()=>{
                return Array.from({length:3},()=> 0);
            })
        })
    });
    //edge case 1: when count is 2
    for(let i=0;i<n;i++){
        for(let buy=0;buy<2;buy++){
            for(let sell=0;sell<2;sell++){
                dp[i][buy][sell][2]=0;
            }
        }
    }
    //edge case 2:when index is n
    for(let buy=0;buy<2;buy++){
        for(let sell=0;sell<2;sell++){
            for(let count=0;count<3;count++){
                dp[n][buy][sell][count]=0;
            }
        }
    }


    for(let i:number=n-1;i>=0;i--){
        for(let buy:number=0;buy<2;buy++){
            for(let sell:number=0;sell<2;sell++){
                for(let count:number=0;count<3;count++){
                    if(buy===sell) continue;
                    if(buy===1){
                        dp[i][buy][sell][count]=Math.max(-prices[i]+dp[i+1][0][1][count],dp[i+1][1][0][count]);
                    }
                    else{
                        if(count<2){
                            dp[i][buy][sell][count]=Math.max(prices[i]+dp[i+1][1][0][count+1],dp[i+1][0][1][count]);
                        }
                    }
                }
            }
        }
    }
    

    return dp[0][1][0][0];
};