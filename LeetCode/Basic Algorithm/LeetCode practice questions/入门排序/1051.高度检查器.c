int heightChecker(int* heights, int heightsSize) {
    int n=heightsSize;
    int *ret=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        ret[i]=heights[i];
    }
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(heights[i]>heights[j])
            {
                temp=heights[i];
                heights[i]=heights[j];
                heights[j]=temp;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(ret[i]!=heights[i])
        {
            count++;
        }
    }
    return count;
}
