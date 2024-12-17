/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define max 30001
 int xor[max];
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize=queriesSize;
    int *ret=(int *)malloc(sizeof(int)*queriesSize);
    xor[0]=arr[0];
    for(int i=1;i<arrSize;i++)
    {
        xor[i]=xor[i-1]^arr[i];
    }
    for(int i=0;i<queriesSize;i++)
    {
        int l=queries[i][0];
        int r=queries[i][1];
        if(l==0)
        {
            ret[i]=xor[r];
        }
        else
        {
            ret[i]=xor[r]^xor[l-1];
        }
    }
    return ret;
}
