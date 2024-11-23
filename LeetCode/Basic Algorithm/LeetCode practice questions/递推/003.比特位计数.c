

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *bits=(int *)malloc(sizeof(int)*(n+1));
    *returnSize=n+1;
    bits[0]=0;
    for(int i=1;i<=n;i++)
    {
        bist[i]=bits[i>>1]+(i&1);
    }
    return bits;
}






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int CountOnes(int n)
 {
    int ones=0;
    while(n>0)
    {
        n=n&(n-1);
        ones++;
    }
    return ones;
 }
int* countBits(int n, int* returnSize){
    *returnSize=n+1;
    int *ret=(int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++)
    {
        ret[i]=CountOnes(i);
    }
    return ret;
}
