class Solution {
    public String largestNumber(int[] nums) {
        //判断是否都为0,都为0返回字符串"0"
        int judge = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                judge = 1;
                break;
            }
        }
        if(judge == 0){
            return "0";
        }
        //用于存放返回的数组结果
        String value = "";
        //冒泡排序，排序逻辑:例如3、32两个数字,通过组合332和323来比较哪一个更大，选更大的组合
        for(int i = 0; i < nums.length - 1; i++){
            for(int j = i + 1; j < nums.length; j++){
                if((String.valueOf(nums[i]) + String.valueOf(nums[j])).compareTo(String.valueOf(nums[j]) + String.valueOf(nums[i])) < 0){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        //所有数字已经按照从大到小排序，只需组合即可
        for(int i = 0; i < nums.length; i++){
            value += String.valueOf(nums[i]);
        }
        return value;
    }
}
