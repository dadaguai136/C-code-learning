/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int hash[101];
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<nums1Size;i++)
    {
        hash[nums1[i]]|=1;
    }
    for(int i=0;i<nums2Size;i++)
    {
        hash[nums2[i]]|=2;
    }
    for(int i=0;i<nums3Size;i++)
    {
        hash[nums3[i]]|=4;
    }
    int *ret=malloc(sizeof(int)*100);
    int size=0;
    for(int i=1;i<101;i++)
    {
        if(hash[i]==0||hash[i]==1||hash[i]==2||hash[i]==4)
        {
            continue;
        }
        ret[size++]=i;
    }
    *returnSize=size;
    return ret;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int hash[101];
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<nums1Size;i++)
    {
        hash[nums1[i]]|=1;
    }
    for(int i=0;i<nums2Size;i++)
    {
        hash[nums2[i]]|=2;
    }
    for(int i=0;i<nums3Size;i++)
    {
        hash[nums3[i]]|=4;
    }
    int *ret=malloc(sizeof(int)*100);
    int size=0;
    for(int i=1;i<101;i++)
    {
        if(hash[i]&(hash[i]-1))
        {
            ret[size++]=i;
        }
    }
    *returnSize=size;
    return ret;
}
