long cmp(const void *pa,const void *pb)
{
    int a=*(int *)pa;
    int b=*(int *)pb;
    unsigned long ax=10,bx=10;
    while(ax<=a)
    {
        ax*=10;
    }
    while(bx<=b)
    {
        bx*=10;
    }
    return ax*b+a-(bx*a+b);
}
char* largestNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    if(nums[0]==0)
    {
        char *ret=malloc(sizeof(char)*2);
        ret[0]='0';
        ret[1]='\0';
        return "0";
    }
    char *ret=malloc(sizeof(char)*1000);
    char *p=ret;
    for(int i=0;i<numsSize;i++)
    {
        sprintf(p,"%d",nums[i]);
        p+=strlen(p);
    }
    return ret;
}
