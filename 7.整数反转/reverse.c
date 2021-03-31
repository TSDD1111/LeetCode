int reverse(int x){
    long num = 0;
    while(x != 0){
        num = num * 10 + x % 10;
        x = x / 10;
    }
    return (int)num == num ? num : 0;
}
