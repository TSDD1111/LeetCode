//直接利用贪心，可以种花就记1个位置。

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
