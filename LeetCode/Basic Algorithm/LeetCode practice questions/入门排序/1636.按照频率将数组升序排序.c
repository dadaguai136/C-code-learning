/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int a;
    int sum;
}node;
int cmp(const void *a,const void *b)
{
    node *a1=(node *)a;
    node *b1=(node *)b;
    if(a1->sum!=b1->sum)
    {
        return a1->sum-b1->sum;
    }
    return b1->a-a1->a;
}
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int hash[201];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]+100]++;
    }
    node arr[201];
    int index=0;
    for(int i=0;i<201;i++)
    {
        if(hash[i])
        {
            arr[index].a=i-100;
            arr[index].sum=hash[i];
            index++;
        }
    }
    int *ret=malloc(sizeof(int)*numsSize);
    int x=0;
    qsort(arr,index,sizeof(node),cmp);
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<arr[i].sum;j++)
        {
            ret[x++]=arr[i].a;
        }
    }
    *returnSize=numsSize;
    return ret;
}




struct number
 {
    int a;
    int sum;
 };
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    struct number hash[201];
    for(int i=0;i<=200;i++)
    {
        hash[i].a=201;
        hash[i].sum=0;
    }
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]+100].a=nums[i];
        hash[nums[i]+100].sum++;
    }
    int n=0;
    struct number arr[numsSize];
    for(int i=0;i<=200;i++)
    {
        if(hash[i].a!=201)
        {
            arr[n++]=hash[i];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i].sum>arr[j].sum)
            {
                struct number temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            else if(arr[i].sum==arr[j].sum&&arr[i].a<arr[j].a)
            {
                struct number temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int *ret=malloc(sizeof(int)*numsSize);
    int x=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].sum;j++)
        {
            ret[x++]=arr[i].a;
        }
    }
    *returnSize=numsSize;
    return ret;
}
