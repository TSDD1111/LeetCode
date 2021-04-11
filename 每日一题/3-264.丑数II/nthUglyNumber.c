//使用三指针思想，即可简单完成
//分别用一个指针index2、3、5指向丑数数组首位下标，
//用2、3、5分别乘以对应下标的值，最小值放入丑数数组，相同的值下标加1
int min(int a, int b){
    return a > b ? b : a;
}
int nthUglyNumber(int n){
    int ugly[n];
    int index2 = 0, index3 = 0, index5 = 0;
    ugly[0] = 1;
    for(int i = 1; i < n; i++){
        ugly[i] = min(min(2 * ugly[index2], 3 * ugly[index3]), 5 * ugly[index5]);
        if(ugly[i] == 2 * ugly[index2]) index2++;
        if(ugly[i] == 3 * ugly[index3]) index3++;
        if(ugly[i] == 5 * ugly[index5]) index5++;
    }
    return ugly[n - 1];
}
