bool canThreePartsEqualSum(int* arr, int arrSize) {
    int sum=0;
    for(int i=0;i<arrSize;i++)
    {
        sum+=arr[i];
    }
    if(sum%3!=0)
    {
        return false;
    }
    int n=0,flag=0;
    for(int i=0;i<arrSize;i++)
    {
        if(flag>=2)
        {
            return true;
        }
        n+=arr[i];
        if(n==(sum/3))
        {
            n=0;
            flag++;
        }
    }
    return false;
}
