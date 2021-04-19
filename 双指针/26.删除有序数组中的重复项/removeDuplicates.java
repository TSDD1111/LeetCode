//利用双指针，一个指向原数组判断是否重复，一个用于存放新数组内容

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length ==  0){
            return 0;
        }
        int index = 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] != nums[index]){
                nums[index + 1] = nums[i];
                index++;
            }
        }
        return index + 1;
    }
}
