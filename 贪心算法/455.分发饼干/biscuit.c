//比较函数
int comp(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    //对g、s数组进行排序，从小到大
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);
    //计算几个小孩满足条件
    int i = 0, j = 0;
    for(; i < gSize && j < sSize;){
        //如果满足条件，下一个小孩和饼干
        if(g[i] <= s[j]){
            i++;
            j++;
        }
        //否则，下一块饼干
        else{
            j++;
        }
    }
    return i;
}
