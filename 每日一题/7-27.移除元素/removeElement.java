//只需新增一个指针用于指向最终数组即可，值相同则继续判断下一个元素，不同则放入新数组

class Solution {
    public int removeElement(int[] nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
