int cmp_up(const void *a, const void *b)
{
    return (*(int *)a -*(int *)b );
}
int maxCoins(int* piles, int pilesSize){
    int res=0;
    qsort(piles, pilesSize, sizeof(int), cmp_up);
    for(int i=pilesSize/3;i<pilesSize;i+=2){
        res+=piles[i];
    }
    return res;
}
