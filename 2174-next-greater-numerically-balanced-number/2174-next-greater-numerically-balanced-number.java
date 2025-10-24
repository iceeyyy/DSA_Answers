class Solution {
    public static boolean balanced(int digit){
        int [] count=new int [10];

        while(digit>0){
            int d=digit%10;
            count[d]++;
            digit/=10;
        }

        for(int i=0;i<10;i++){
            if(count[i]!=0 && count[i]!=i) return false; 
        }

        return true;
    }
    public int nextBeautifulNumber(int n) {
        //biggest number is 1e6 and the number possible for it is 1224444
        for(int i=n+1;i<=1224444;i++){ //wrong for loop
            if(balanced(i)) return i;
        }
        return -1;
    }
}