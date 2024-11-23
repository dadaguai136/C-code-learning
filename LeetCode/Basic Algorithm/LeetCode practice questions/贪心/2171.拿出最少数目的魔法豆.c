int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
long long minimumRemoval(int* beans, int beansSize) {
    qsort(beans,beansSize,sizeof(int),cmp);
    long long total=0;
    for(int i=0;i<beansSize;i++)
    {
        total+=beans[i];
    }
    long long res=total;
    for(int i=0;i<beansSize;i++)
    {
        long long t=total-(long long)beans[i]*(beansSize-i);
        res=res>t?t:res;
    }
    return res;
}
