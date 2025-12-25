/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function(s) {
    let ans=0;

    for(let i=0;i<s.length;i++){
        let mp = new Map();
        for(let j=i;j<s.length;j++){
            mp.set(s[j],(mp.get(s[j])||0)+1);
            let maxi=-Infinity;
            let mini=Infinity;
            for(let [a,b] of mp){
                maxi=Math.max(maxi,b);
                mini=Math.min(mini,b);
            }
            ans+=maxi-mini;
        }
    }
    return ans;
};