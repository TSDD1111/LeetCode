int cmp(void* _a, void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[1] < b[1] ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    //区间没有气球
    if (pointsSize == 0) {
        return 0;
    }
    //对气球排序,按每个气球的结束坐标排序
    qsort(points, pointsSize, sizeof(int*), cmp);
    //设置弓箭的最远距离
    int pos = points[0][1];
    int ans = 1;
    for (int i = 0; i < pointsSize; ++i) {
        //如果气球的开始距离超过了弓箭的最远距离，则需要一只新的弓箭
        if (points[i][0] > pos) {
            //更新弓箭的最远距离
            pos = points[i][1];
            ++ans;
        }
    }
    return ans;
}
