/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int hash[10001];
int get(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
int cmp(const void *pa,const void *pb)
{
    int x=*(int *)pa;
    int y=*(int *)pb;
    return hash[x]==hash[y]?x-y:hash[x]-hash[y];
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<arrSize;i++)
    {
        hash[arr[i]]=get(arr[i]);
    }
    qsort(arr,arrSize,sizeof(int),cmp);
    *returnSize=arrSize;
    return arr;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int bit[10001];
 int cmp(const void *pa,const void *pb)
 {
    int x=*(int *)pa;
    int y=*(int *)pb;
    return bit[x]==bit[y]?x-y:bit[x]-bit[y];
 }
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    memset(bit,0,sizeof(bit));
    for(int i=0;i<10001;i++)
    {
        bit[i]=bit[i>>1]+(i&1);
    }
    qsort(arr,arrSize,sizeof(int),cmp);
    *returnSize=arrSize;
    return arr;
}
