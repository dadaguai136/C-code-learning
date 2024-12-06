int cmp(const void *pa,const void *pb)
{
	return *(int *)pa-*(int *)pb;
}
int threeSumClosest(int *nums,int numsSize,int target)
{
	qsort(nums, numsSize,sizeof(int),cmp);
	int ans,sum;
	int min=INT_MAX;
	for(int i=0;i<numsSize-2;i++)
	{
		int x=nums[i];
		if(i>0&&x==nums[i-1])
		{
			continue;
		}
		sum=x+nums[i+1]+nums[i+2];
		if(sum>target)
		{
			if(sum-target<min)
			{
				ans=sum;
				break;
			}
		}
		sum=x+nums[numsSize-1]+nums[numsSize-2];
		if(sum<target)
		{
			if(target-sum<min)
			{
				min=target-sum;
				ans=sum;
			}
			continue;
		}
		int j=i+1,k=numsSize-1;
		while(j<k)
		{
			sum=x+nums[j]+nums[k];
			if(sum<target)
			{
				if(target-sum<min)
				{
					min=target-sum;
					ans=sum;
				}
				j++;
			}
			else if(sum>target)
			{
				if(sum-target<min)
				{
					min=sum-target;
					ans=sum;
				}
				k--;
			}
			else
			{
				return target;
			}
		}
	}
	return ans;
}




int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int n=numsSize;
    qsort(nums,n,sizeof(int),cmp);
    int best=1e7;
    for(int i=0;i<n;i++)
    {
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        int j=i+1,k=n-1;
        while(j<k)
        {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==target)
            {
                return target;
            }
            if(abs(sum-target)<abs(best-target))
            {
                best=sum;
            }
            if(sum>target)
            {
                int k0=k-1;
                while(j<k0&&nums[k0]==nums[k])
                {
                    --k0;
                }
                k=k0;
            }
            else
            {
                int j0=j+1;
                while(j0<k&&nums[j0]==nums[j])
                {
                    ++j0;
                }j=j0;
            }
        }
    }
    return best;
}
