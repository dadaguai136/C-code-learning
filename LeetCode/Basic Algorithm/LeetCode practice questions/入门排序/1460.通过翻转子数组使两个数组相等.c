void bubbleSort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if(targetSize!=arrSize)
    {
        return false;
    }
    bubbleSort(target,targetSize);
    bubbleSort(arr,arrSize);
    for(int i=0;i<targetSize;i++)
    {
        if(target[i]!=arr[i])
        {
            return false;
        }
    }
    return true;
}





bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int hash1[1001];
    int hash2[1001];
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    for(int i=0;i<targetSize;i++)
    {
        hash1[target[i]]++;
        hash2[arr[i]]++;
    }
    for(int i=1;i<1001;i++)
    {
        if(hash1[i]!=hash2[i])
        {
            return false;
        }
    }
    return true;
}
