class Solution:
    def possibleStringCount(self, word: str) -> int:
        cnt = 1 
        for i in range(1,len(word)):
            if word[i-1]==word[i]:
                cnt+=1
        return cnt