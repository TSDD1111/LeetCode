//通过贪心，去寻找每次跳跃的最大值，计算跳跃次数即可

int jump(int* nums, int numsSize){
    //记录跳跃次数
    int times = 0;
    for(int i = 0; i < numsSize - 1;){
        //当在本节点跳跃能到达终点时，直接跳跃并返回
        if(i + nums[i] >= numsSize - 1){
            return times + 1;
        }
        //否则，判断下一次跳跃的位置，寻找能跳跃最远距离的位置
        int max = i + 1;
        for(int j = i + 2; j < i + 1 + nums[i] && j < numsSize; j++){
            if(nums[max] + max <= nums[j] + j){
                max = j;
            }
        }
        i = max;
        times++;
    }
    return times;
}
