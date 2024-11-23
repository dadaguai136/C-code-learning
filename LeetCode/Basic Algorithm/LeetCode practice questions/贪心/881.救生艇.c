int cmp(const void *a,const void *b)
{
    int vala=*(int *)a;
    int valb=*(int *)b;
    return vala>valb?1:-1;
}
int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people,peopleSize,sizeof(int),cmp);
    int r=0;
    int l=peopleSize-1;
    int ans=0;
    while(r<=l)
    {
        if(r==l)
        {
            ans+=1;
            return ans;
        }
        if(people[r]+people[l]<=limit)
        {
            ans+=1;
            r++;
            l--;
        }
        else
        {
            ans+=1;
            l--;
        }
    }
    return ans;
}
