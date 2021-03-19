//通过贪心计算，计算从初始点开始以后能到达的最远距离，永远选取最远距离。

bool canJump(int* nums, int numsSize){
    for(int i = 0; i < numsSize;){
        //已经能直接到达终点，则返回true
        if(i + nums[i] >= numsSize - 1){
            return true;
        }
        //若步数为0，且没到达终点，则不能继续前进，返回false
        else if(nums[i] == 0){
            return false;
        }
        else{
            i++;
            int max = i + nums[i - 1];  //获取每次移动可能的最大值
            //计算可能到达的最大值里面的加上该点以后的最大值
            for(int j = i + 1; j < max; j++){
                //选择能到达的最长距离，例如4,2,0,0,1,1...2+1<1+4，显然从4到1更好而不是2
                if(nums[i] + i <= nums[j] + j){
                    i = j;
                }
            }
        }
    }
    return false;
}
