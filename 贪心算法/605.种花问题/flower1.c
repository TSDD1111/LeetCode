//直接利用贪心，可以种花就记1个位置。
//也可以在数组前后各加1个0，这样只需判断中间数组是否存在连续的3个0即可，判断条件更简单了。

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    for(int i = 0; i < flowerbedSize; i++){
            if(flowerbed[i] == 0
            &&(i + 1 == flowerbedSize || flowerbed[i + 1] == 0)
            &&(i == 0 || flowerbed[i - 1] == 0)){
                n--;
                i++;
            }
    }
    return n <= 0;
}
