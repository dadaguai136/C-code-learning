/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int hash[101];
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]++;
    }
    int n=0;
    for(int i=1;i<101;i++)
    {
        if(i==target)
        {
            n=hash[i];
        }
    }
    int size=0;
    for(int i=1;i<101;i++)
    {
        while(hash[i])
        {
            nums[size++]=i;
            hash[i]--;
        }
    }
    int *ret=malloc(sizeof(int)*n);
    int x=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            ret[x++]=i;
        }
    }
    *returnSize=n;
    return ret;
    
    
    
    
    
    /**
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
	    int number=0,sign=0,ansSize=0;
	    for(int i=0;i < numsSize;i++)
	    {
	        if(nums[i] < target)
	            sign++;
	        else if(nums[i] == target)
	            ansSize++;
	    }
	
	    *returnSize=ansSize;
	    int *ans=(int*)malloc(sizeof(int)*ansSize);
	    for(int i=0;i <ansSize;i++)
	        ans[i]=sign++;
	    
	    return ans;
	}
}
