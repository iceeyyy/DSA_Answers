function waviness(num:string){
    let n=num.length;
    let cnt=0;
    if(n<3) return 0;

    for(let i=1;i<n-1;i++){
        if(num[i]>num[i-1] && num[i]>num[i+1]) cnt++; //peak
        if(num[i]<num[i-1] && num[i]<num[i+1]) cnt++; //valley
    }

    return cnt;
}
function totalWaviness(num1: number, num2: number): number {
    let ans=0;
    for(let num=num1;num<=num2;num++){
        let s = num.toString();
        ans+=waviness(s);
    }
    return ans;
};