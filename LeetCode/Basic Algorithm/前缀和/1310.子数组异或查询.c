#define maxn 30001
int xor[maxn];
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    xor[0]=arr[0];
    int *ret=(int *)malloc(sizeof(int)*queriesSize);
    *returnSize=queriesSize;
    for(int i=1;i<arrSize;i++)
    {
        xor[i]=xor[i-1]^arr[i];
    }
    for(int i=0;i<queriesSize;i++)
    {
        int l=queries[i][0];
        int r=queries[i][1];
        int ans;
        if(l==0)
        {
            ans=xor[r];
        }
        else
        {
            ans=xor[r]^xor[l-1];
        }
        ret[i]=ans;
    }
    return ret;
}
