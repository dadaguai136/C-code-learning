/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* memLeak(int memory1, int memory2, int* returnSize) {
    int *res=(int *)malloc(sizeof(int)*3);
    int i=1;
    while(memory1>=i||memory2>=i)
    {
        if(memory1>=memory2)
        {
            memory1-=i;
        }
        else
        {
            memory2-=i;
        }
        i++;
    }
    res[0]=i;
    res[1]=memory1;
    res[2]=memory2;
    *returnSize=3;
    return res;
}
