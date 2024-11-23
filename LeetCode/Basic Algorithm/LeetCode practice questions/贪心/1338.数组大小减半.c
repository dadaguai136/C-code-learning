int compare(const void *pa,const void *pb)
{
    return *(int *)pb-*(int *)pa;
}
int minSetSize(int* arr, int arrSize) {
    int hashSet[100001]={0};
    for(int i=0;i<arrSize;i++)
    {
        hashSet[arr[i]]++;
    }
    qsort(hashSet,100001,sizeof(int),compare);
    int count=0;
    int arrCount=0;
    int targetCount=arrSize/2;
    for(int i=0;i<100001;i++)
    {
        arrCount+=hashSet[i];
        count++;
        if(arrCount>=targetCount)
        {
            break;
        }
    }
    return count;
}
