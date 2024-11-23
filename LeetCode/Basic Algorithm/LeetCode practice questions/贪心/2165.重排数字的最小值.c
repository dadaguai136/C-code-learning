long long smallestNumber(long long num) {
    int ns[10] = {0};
    
    long long tmp = num;

    if (num < 0)
        num = num*-1;

    while (num) {
        ns[num%10]++;
        num /= 10;
    }

    long long res = 0;

    if (tmp > 0) {
        if (ns[0] != 0) {
            int f = 0;
            for (int i = 1;i < 10; i++) {
                while (ns[i]) {
                    res = res*10+i;
                    ns[i]--;
                    if (res > 0 && f == 0) {
                        while(ns[0]) {
                            res = res*10;
                            ns[0]--;
                        }
                        f = 1;
                    }
                }
            } 
        } else {
            for (int i = 1;i < 10; i++) {
                while (ns[i]) {
                    res = res*10+i;
                    ns[i]--;
                }
            }
        }
    } else if (tmp < 0) {
        for (int i = 9;i >= 0; i--) {
            while (ns[i]) {
                res = res*10+i;
                ns[i]--;
            }
        }
        res = res*-1;
    } 

    return res;
}






int comparePositiveFunc(void *a,void *b)
{
    if(*(int *)a >= *(int *)b )
    {
        return 1;
    }
    return -1;
}

int   compareNegativeFunc(void *a,void *b)
{
    if(*(int *)a <= *(int *)b )
    {
        return 1;
    }
    return -1;
}

long long smallestNumber(long long num)
{
    //10^15
    int i;    
    if(num == 0)
    {
        return num;
    }
    
    int   nums[16];//全部遍历出来
    bool  isNegative = false;
    
    if(num < 0)
    {
        isNegative = true;
        num = 0 -  num ;
    }
    int count = 0;
    while(num)
    {
        nums[count] = num %10;
        count++;
        num/= 10;
        
    }
    if(isNegative)
    {
        //从大到小
        qsort(nums,count,sizeof(int),compareNegativeFunc);
    }
    else
    {
        //从小到大
        qsort(nums,count,sizeof(int),comparePositiveFunc);
        
        if(nums[0] == 0)
        {               
            for(i = 0; i < count; i++)
            { 
                //找一个非零的值
                if(nums[i])
                {
                    int temp = nums[i];
                    nums[i] = nums[0];
                    nums[0] = temp;
                    break;
                }
            }
        }
    }
    long long returnNum = 0;
    for(i =0; i < count; i ++)
    {
        returnNum = returnNum*10 + nums[i];
    }
    if(isNegative)
        returnNum = 0 - returnNum;
    return returnNum;
    
}
