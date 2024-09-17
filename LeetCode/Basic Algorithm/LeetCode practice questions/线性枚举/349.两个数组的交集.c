/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int nums1Cnt[1001]={0};
    int lessSize=nums1Size<nums2Size?nums1Size:nums2Size;
    int *result=(int *)malloc(lessSize*sizeof(int));
    int resultIndex=0;
    int *tempNums;
    for(int i=0;i<nums1Size;i++)
    {
        nums1Cnt[nums1[i]]++;
    }
    for(int i=0;i<nums2Size;i++)
    {
        if(nums1Cnt[nums2[i]]>0)
        {
            result[resultIndex]=nums2[i];
            resultIndex++;
            nums1Cnt[nums2[i]]=0;
        }
    }
    *returnSize=resultIndex;
    return result;
}
