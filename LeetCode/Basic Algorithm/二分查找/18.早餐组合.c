int isGreen(int idx,int *a,int x)
{
    return a[idx]>x;
}
int binarySearch(int l,int r,int *a,int x)
{
    while(l+1<r)
    {
        int mid=l+(r-l)/2;
        if(isGreen(mid,a,x))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
int cmp(const void *a,const void *b)
{
    return *(int *)a<*(int *)b?-1:1;
}
int count(int *drinks,int val,int l,int r)
{
    int idx=binarySearch(l-1,r+1,drinks,val);
    return idx;
}
int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x){
    qsort(drinks,drinksSize,sizeof(int),cmp);
    int ans=0;
    int mod=1000000007;
    for(int i=0;i<stapleSize;i++)
    {
        //staple[i]+drinks[j]<=x;
        //drinks[j]<=x-staple[i];
        ans+=count(drinks,x-staple[i],0,drinksSize-1);
        if(ans>=mod)
        {
            ans-=mod;
        }
    }
    return ans;
}
