function minFlips(s: string): number {
    //optimized
    let n:number=s.length;

    let ans:number=Infinity;

    let flip1:number=0;
    let flip2:number=0;

    let i:number=0;
    let j:number=0;

    while(j<2*n){
        let expChar1=j%2?'1':'0';
        let expChar2=j%2?'0':'1';

        if(s[j%n]!==expChar1) flip1++;

        if(s[j%n]!==expChar2) flip2++;

        if(j-i+1>n){
            expChar1=i%2?'1':'0';
            expChar2=i%2?'0':'1';

            if(s[i%n]!==expChar1) flip1--;
            if(s[i%n]!==expChar2) flip2--;
            
            i++;
        }

        if(j-i+1===n){
            ans=Math.min(ans,flip1,flip2);
        }

        j++;
    }

    return ans;
};