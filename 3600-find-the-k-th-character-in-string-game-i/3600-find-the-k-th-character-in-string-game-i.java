class Solution {
    public char kthCharacter(int k) {
        String word="a";

        while(word.length()<k){
            String temp=word;
            String add="";
            for(int i=0;i<word.length();i++){
                add+=(word.charAt(i)=='z')? 'a' : (char)(word.charAt(i)+1);
            }
            temp+=add;
            word=temp;
        }
        return word.charAt(k-1);
    }
}