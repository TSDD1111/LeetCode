//获取两个数较小的一个数
int min(int a, int b){
    return a < b ? a : b;
}
//获取两个数较大的一个
int max(int a, int b){
    return a > b ? a : b;
}
//本方法通过设置前后两个指针，依次向内推进，当底变小时，需找到更大的高，此时保留左右更高的一条边，缩进另一边来判断。
int maxArea(int* height, int heightSize){
    int area = 0;
    //从左右两边向里面判断
    int left = 0, right = heightSize - 1;
    //一直判断到左右指针相等
    while(left < right){
        area = max(area, (right - left) * min(height[left], height[right]));  //计算最大面积
        if(height[left] > height[right]){
            right--;
        }
        else{
            left++;
        }
    }
    return area;
}
