class Solution {
    public int possibleStringCount(String word) {
        int cnt=1; //at least we will consider the default word to be added in possibilites
        for(int i=1;i<word.length();i++){
            if(word.charAt(i-1)==word.charAt(i)) cnt++;  
        }
        return cnt;
    }
}
