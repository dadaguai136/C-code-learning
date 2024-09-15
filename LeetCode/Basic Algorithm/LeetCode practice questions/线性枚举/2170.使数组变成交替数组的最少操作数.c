
int hash1[100001];
int hash2[100001];

int minimumOperations(int* nums, int numsSize){
    //if(numsSize < 3) return 0;
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    int count_max1 = 0;
    int count_max2 = 0;
    int element_max1 = 0;
    int element_max2 = 0;
    for(int i= 0;i<numsSize;i+=2)
    {
        hash1[nums[i]]++;
        if(hash1[nums[i]] > count_max1)
        {
            count_max1 = hash1[nums[i]];
            element_max1 = nums[i];
        }
    }

    for(int i =1;i<numsSize;i+=2)
    {
        hash2[nums[i]]++;
        if(hash2[nums[i]] > count_max2 && nums[i]!= element_max1)
        {
            count_max2 = hash2[nums[i]];
            element_max2 = nums[i];
        }
    }
    int ret1= numsSize -count_max1 -count_max2;

    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    count_max1 = 0;
    count_max2 = 0;
    element_max1 = 0;
    element_max2 = 0;
    for(int i =1;i<numsSize;i+=2)
    {
        hash2[nums[i]]++;
        if(hash2[nums[i]] > count_max2)
        {
            count_max2 = hash2[nums[i]];
            element_max2 = nums[i];
        }
    }
    for(int i= 0;i<numsSize;i+=2)
    {
        hash1[nums[i]]++;
        if(hash1[nums[i]] > count_max1 && nums[i] != element_max2)
        {
            count_max1 = hash1[nums[i]];
            element_max1 = nums[i];
        }
    }
    int ret2= numsSize -count_max1 -count_max2;
    return ret1<ret2?ret1:ret2;
}
