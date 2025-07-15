class Solution {
    public boolean isValid(String word) {
        if(word.length()<3) return false;

        boolean hasVowel=false;
        boolean hasCons=false;

        for(int i=0;i<word.length();i++){
            if(!Character.isLetterOrDigit(word.charAt(i))){
                return false;
            }
            if(Character.isLetter(word.charAt(i))){
                char ch = Character.toLowerCase(word.charAt(i));
                if(ch=='a'|| ch=='e'|| ch=='i'||ch=='o'||ch=='u'){
                    hasVowel=true;
                }
                else{
                    hasCons=true;
                }
            }
        }

        return (hasVowel && hasCons)?true: false;
    }
}