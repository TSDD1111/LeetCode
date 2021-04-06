//设置一个下标index用于随时修改数组内容，删除重复数字
//逐个遍历，count判断重复个数，

int removeDuplicates(int* nums, int numsSize){
    int count = 1, index = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            if(count < 2){
                nums[index] = nums[i];
                index++;
                count++;
            }
        }
        else{
            nums[index] = nums[i];
            index++;
            count = 1;
        }
    }
    return index;
}
