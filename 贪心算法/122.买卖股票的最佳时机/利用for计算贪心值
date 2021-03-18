//只需计算相邻两天存在的利润即可

int maxProfit(int* prices, int pricesSize){
    int priceSum = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] > prices[i - 1]){
            priceSum  += (prices[i] - prices[i - 1]);
        }
    }
    return priceSum;
}
