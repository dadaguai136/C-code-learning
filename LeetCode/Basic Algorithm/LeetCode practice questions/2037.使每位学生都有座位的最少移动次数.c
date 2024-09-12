int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats,seatsSize,sizeof(int),cmp);
    qsort(students,studentsSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<studentsSize;i++,students++,seats++)
    {
        ans+=abs(*students-*seats);
    }
    return ans;
}
