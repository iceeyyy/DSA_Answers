class Solution {
    public boolean hasSameDigits(String s) {

        while(s.length()!=2){
            String ss="";
            for(int i=1;i<s.length();i++){
                int a = s.charAt(i-1)-'0';
                int b = s.charAt(i)-'0';
                int c = (a+b) % 10;
                ss+=String.valueOf(c);
            }
            s=ss;
        }
        
        return s.charAt(0)==s.charAt(1);
    }
}