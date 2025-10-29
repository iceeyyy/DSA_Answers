class Solution {
    public boolean isValid(String s){
        for(char ch:s.toCharArray()){
            if(ch=='0') return false;
        }
        return true;
    }
    public String binary(int n){
        String bi="";

        while(n>0){
            int digit=n%2;
            String dig = String.valueOf(digit);
            bi+=dig;
            n/=2;
        }
        bi = new StringBuilder(bi).reverse().toString();

        return bi;
    }
    public int smallestNumber(int n) {
        for(int i=n;i<100000;i++){
            String bi=binary(i);
            if(isValid(bi)) return i;
        }
        return -1;
    }
}