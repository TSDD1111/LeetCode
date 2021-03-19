bool canJump(int* nums, int numsSize){
    //记录在每个点所能继续前进的步数，取最大值即可
    int max = 0;
    for(int i = 0; i < numsSize - 1; i++, max--){
        //如果到一个点的nums大于剩余的步数，则取大者
        if(max < nums[i]){
            max = nums[i];
        }
        //若步数小于0，则说明无法继续前进，此时若i小于numsSize-1，则未到达终点且到不了
        if(max <= 0){
            return false;
        }
    }
    //判断到达终点时剩余步数即可判断能否到达，只需大于0即可
    return max >= 0;
}
