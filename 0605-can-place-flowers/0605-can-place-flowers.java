class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int sizee=flowerbed.length;
        
        //check for left and right flowerbed
        for(int i=0;i<sizee;i++){
            boolean prev = i == 0 || flowerbed[i - 1] == 0;
            boolean fut = i == sizee - 1 || flowerbed[i + 1] == 0;

            if (prev && fut && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return (n>=1)?false:true;
    }
}