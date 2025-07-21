class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans=new StringBuilder();
        int cnt=1;
        ans.append(s.charAt(0));
        for(int i=1;i<s.length();i++){
            if(s.charAt(i-1)==s.charAt(i)) cnt++;
            else{
                cnt=1;
            }
            if(cnt<3){
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}