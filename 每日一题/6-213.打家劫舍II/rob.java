class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0){   //没有数字返回0
            return 0;
        }
        else if(nums.length == 1){   //只有一个数字返回该数字
            return nums[0];
        } 
        //由于首尾不能连接，分成两个数列0-n-1和1-n，取最大的一个
        return Math.max(findMax(nums, 0), findMax(nums, 1));
    }
    //计算start开始的n-1个数字里的最大值
    public int findMax(int[] nums, int start){
        int[] value = new int[nums.length - 1];
        for(int i = 0; i < nums.length - 1; i++, start++){
            if(i == 0){
                value[i] = nums[start];
            }
            else if(i == 1){
                value[i] = Math.max(value[i - 1], nums[start]);
            }
            else{
                value[i] = Math.max(value[i - 1], value[i - 2] + nums[start]);
            }
        }
        return value[nums.length - 2];
    }
}
