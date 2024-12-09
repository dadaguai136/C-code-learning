/**
 * Note: The returned array must be malloced, assume caller calls free().
 */





int* shortestSeq(int* big, int bigSize, int* small, int smallSize, int* returnSize){


int left = 0;
int right = 0;

int hash[1000000] = {0};

int i;
int cnt = 0;
int max = 0x7fffffff;

int *ret = (int *)calloc(2, sizeof(int));

if(smallSize > bigSize)
{
    *returnSize = 0;
    return ret;
}


for(i=0; i<smallSize; i++)
{
    hash[small[i]]++;
    cnt++;
}

//printf("%d\n", cnt);

while(right < bigSize)
{
    hash[big[right]]--;
    if(hash[big[right]] == 0)
    {
        cnt--;
    }


while(cnt == 0)
{
    hash[big[left]]++;
    if(hash[big[left]] > 0)
    {
        cnt++;
        if((right - left) < max)
        {
            max = right - left;
            ret[0] = left;
            ret[1] = right;
        }
        //max = (right - left) < max ? (right - left) : max;

    }

    left++;
}

right++;
}

//int *ret = (int *)calloc(2, sizeof(int));
//ret[0] = left;
//ret[1] = right;

*returnSize = max != 0x7fffffff ? 2 : 0;
return ret;
}




int* shortestSeq(int* big, int bigSize, int* small, int smallSize, int* returnSize){
    int pleft,pright;
    int left=0,right=0;
    int min=bigSize+1;
    int temp;
    int count=smallSize;

    if(smallSize>bigSize){
        *returnSize=0;
        return NULL;
    }

    int hash[1000001]={0};

    for(int i=0;i<smallSize;i++)
        hash[small[i]]++;

    while(left<bigSize){
        while(count>0&&right<bigSize)
            if(--hash[big[right++]]>=0)
                count--;

        if(count==0){
            temp=right-left;
            if(min>temp){
                min=temp;
                pleft=left;
                pright=right-1;
            }
        }

        if(++hash[big[left++]]>0)
            count++;
    }

    if(min==bigSize+1){
        *returnSize=0;
        return NULL;
    }

    *returnSize=2;
    int* a=(int*)malloc(sizeof(int)*2);
    a[0]=pleft;
    a[1]=pright;
    return a;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestSeq(int* big, int bigSize, int* small, int smallSize, int* returnSize) {
    int left=0,right=0;
    int hash[1000000];
    memset(hash,0,sizeof(hash));
    int *ret=(int *)malloc(sizeof(int)*2);
    if(smallSize>bigSize)
    {
        *returnSize=0;
        return ret;
    }
    int cnt=0;
    int max=INT_MAX;
    for(int i=0;i<smallSize;i++)
    {
        hash[small[i]]++;
        cnt++;
    }
    while(right<bigSize)
    {
        hash[big[right]]--;
        if(hash[big[right]]==0)
        {
            cnt--;
        }
        while(cnt==0)
        {
            hash[big[left]]++;
            if(hash[big[left]]>0)
            {
                cnt++;
                if((right-left)<max)
                {
                    max=right-left;
                    ret[0]=left;
                    ret[1]=right;
                }
            }
            left++;
        }
        right++;
    }
    *returnSize=max!=INT_MAX?2:0;
    return ret;
}
