/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define ABS(a) ((a)>0?(a):(-(a)))
 int cmp(const void *a,const void *b)
 {
    return *(int*)a-*(int*)b;
 }
int* getStrongest(int* arr, int arrSize, int k, int* returnSize) {
    qsort(arr,arrSize,sizeof(int),cmp);
    int m=arr[(arrSize-1)/2],mid=(arrSize-1)/2;
    int *p = (int*)malloc(sizeof(int)*k);
    *returnSize = k;
    int count=0;
    int left=0,right=arrSize-1;
    while(count<k)
    {
        if(left<mid && right>=mid)
        {
            if(ABS(arr[right]-m)>=ABS(arr[left]-m))
                {
                    p[count++]=arr[right--];
                }
                else
                {
                    p[count++]=arr[left++];
                }
        }else if(left>=mid)
        {
            p[count++]=arr[right--];
        }
        else{
        p[count++]=arr[left++];
        }
    }
    return p;
}




int g_m; // 中位数全局变量

// 升序 比较函数
int cmp_up(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// 比较函数 最强值排序规则
int cmp(const void *a, const void *b)
{
    int *p = (int *)a;
    int *q = (int *)b;

    if (abs(*p - g_m) != abs(*q - g_m)) {
        return abs(*q - g_m) - abs(*p - g_m);
    } else {
        return *q - *p;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getStrongest(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), cmp_up);
    g_m = (arrSize - 1) / 2;
    g_m = arr[g_m];
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;
    return arr;
}
