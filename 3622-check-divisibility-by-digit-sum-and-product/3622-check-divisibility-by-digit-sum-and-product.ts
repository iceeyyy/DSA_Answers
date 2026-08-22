function checkDivisibility(n: number): boolean {
    let num=n;
    let prod=1;
    let sum=0;

    while(num){
        let digit=num%10;
        num=Math.floor(num/10);
        prod*=digit;
        sum+=digit;
    }

    return  n % (sum + prod) === 0;
};