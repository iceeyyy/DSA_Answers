class Solution {
    public boolean doesAliceWin(String s) {
        return s.chars().anyMatch(ch->"aeiou".indexOf(ch)>=0);
    }
}