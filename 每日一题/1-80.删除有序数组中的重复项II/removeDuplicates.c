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

//修改后的更简洁的代码
//直接根据修改后的index前的数字判断是否存在重复即可

// int removeDuplicates(int* nums, int numsSize){
//     int index = 0;
//     for(int i = 0; i < numsSize; i++){
//         if(index < 2 || nums[i] != nums[index - 2]){
//             nums[index++] = nums[i];
//         }
//     }
//     return index;
// }
