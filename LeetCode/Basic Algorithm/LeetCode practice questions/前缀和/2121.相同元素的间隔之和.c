/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* getDistances(int* arr, int arrSize, int* returnSize){
    int max = 0;
    //求出数组中最大的值，方便后面根据元素值分配大小，最大值为100000
    for(int i = 0;i < arrSize;i++) {
        max = fmax(max, arr[i]);
    }

    //初始化
    long long* res = (long long*)calloc(arrSize, sizeof(long long)); // 每个元素与相同元素间隔之和
    long long* total = (long long*)calloc(max+1,sizeof(long long)); // 每个数值出现下标之和
    long long* cnt = (long long*)calloc(max+1,sizeof(long long));// 每个数值出现次数
   
    for(int i = 0;i < arrSize;i++) {
        res[i] = cnt[arr[i]] * i - total[arr[i]];
        total[arr[i]] += i;//对应元素索引和更新
        cnt[arr[i]]++;//出现频率加1
    }
    // 清空表项，反向遍历并更新两个统计表以及间隔之和数组
    for(int i = 0;i < max + 1;i++)
        cnt[i] = total[i] = 0;

    for(int i = arrSize - 1;i >= 0;i--) {
        res[i] += total[arr[i]] - cnt[arr[i]] * i;
        total[arr[i]] += i;
        cnt[arr[i]]++;
    }
    *returnSize = arrSize;
    return res;
}
