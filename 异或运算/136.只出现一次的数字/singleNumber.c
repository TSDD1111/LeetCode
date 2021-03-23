//利用异或运算的特点，直接对数组所有值进行异或运算。
//同时也可以使用别的做法，比如直接使用qsort来排序，两两比对，找到单个值即可。

int singleNumber(int* nums, int numsSize){
    int number = nums[0];
    for(int i = 1; i < numsSize; i++){
        number = number ^ nums[i];
    }
    return number;
}
