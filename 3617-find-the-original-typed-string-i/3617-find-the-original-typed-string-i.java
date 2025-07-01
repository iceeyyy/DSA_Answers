class Solution {
    public int possibleStringCount(String word) {
        int cnt=1; // atleast we will consider the word to be default
        for(int i=1;i<word.length();i++){
            if(word.charAt(i-1)==word.charAt(i)) cnt++;  
        }
        return cnt;
    }
}