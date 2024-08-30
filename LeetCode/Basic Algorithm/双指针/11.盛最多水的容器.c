
int min(int a,int b)
{
   return a>b?b:a;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int maxArea(int* height, int n) {
    int ret=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=min(height[i],height[j])*(j-i);
            ret=max(ret,ans);
        }
    }
    return ret;
}
int min(int a,int b)
{
   return a>b?b:a;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int maxArea(int* height, int n) {//ÓÅ»¯
    int l=0,r=n-1;
    int ans,ret=0;
    while(l<r)
    {
        ans=min(height[l],height[r])*(r-l);
        ret=max(ret,ans);
        if(height[l]<height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return ret;
}
