int minDeletion(int* nums, int numsSize){
    int l = 0, r = 1, cnt = 0;
    while (r < numsSize)
        if (nums[ l ] != nums[ r ++ ]) {
            cnt += r - l - 2;
            l = r ++;
        }
    return cnt + ( l < numsSize ? r - l : 0 );
}



int minDeletion(int* nums, int numsSize) {
    int ans=0;
    bool check=true;
    for(int i=0;i+1<numsSize;i++)
    {
        if(nums[i]==nums[i+1]&&check)
        {
            ans++;
        }
        else
        {
            check=!check;
        }
    }
    if((numsSize-ans)%2!=0)
    {
        ans++;
    }
    return ans;
}




int minDeletion(int* nums, int numsSize) {
    int count=0;
    int id=0;
    if(numsSize==1){
        return 1;
    }
    int flag=0;
    int i=1;
    while(i<numsSize){
        if(id%2==0){
            if(i<numsSize){
                if(nums[flag]==nums[i]&&i<numsSize){
                    i++;
                    count++;
                }else{
                    id++;
                    flag=i;
                    i++;
                }
            }
        }else{
            id++;
            flag++;
            i++;
        }
    }
    if((numsSize-count)%2==1){
        count++;
    }
    return count;
}
