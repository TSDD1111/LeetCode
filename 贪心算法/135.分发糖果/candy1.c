int candy(int* ratings, int ratingsSize){
    //存放糖果总数和每个小孩的糖果数
    int sum = 0;
    int candy[ratingsSize];
    //从前向后遍历，如果比前一个小孩评分高，则多给一颗糖果,不然就1颗糖
    for(int i = 0; i < ratingsSize; i++){
        if(i > 0 && ratings[i] > ratings[i - 1]){
            candy[i] = candy[i - 1] + 1;
        }
        else{
            candy[i] = 1;
        }
    }
    //从后向前遍历，避免影响已经遍历过的孩子。如果比后一个小孩评分高，原本的糖果数和比后一个孩子多一颗糖果数，两者取大。
    for(int i = ratingsSize - 2; i >= 0; i--){
        if(ratings[i] > ratings[i + 1]){
            if(candy[i] < candy[i + 1] + 1){
                candy[i] = candy[i + 1] + 1;
            }
        }
        //求和
        sum += candy[i];
    }
    sum = sum + candy[ratingsSize - 1];
    return sum;
}
