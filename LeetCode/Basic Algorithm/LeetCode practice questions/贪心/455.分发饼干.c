int cmp(int *a,int *b)
{
    return *a-*b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g,gSize,sizeof(int),cmp);
    qsort(s,sSize,sizeof(int),cmp);
    int m=gSize,n=sSize;
    int count=0;
    for(int i=0,j=0;i<m&&j<n;i++,j++)
    {
        while(j<n&&g[i]>s[j])
        {
            j++;
        }
        if(j<n)
        {
            count++;
        }
    }
    return count;
}
