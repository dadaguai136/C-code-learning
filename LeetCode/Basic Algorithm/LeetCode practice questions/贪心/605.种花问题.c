bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int prev=-1,max=0;
    for(int i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==1)
        {
            if(prev<0)
            {
                max+=i/2;
            }
            else
            {
                max+=(i-prev-2)/2;
            }
            prev=i;
        }
    }
    if(prev<0)
    {
        max+=(flowerbedSize+1)/2;
    }
    else
    {
        max+=(flowerbedSize-prev-1)/2;
    }
    return max>=n;
}





bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count=0,p=0;
    for(int i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==1)
        {
            if(p)
            {
                count--;
                p=0;
            }
            p=1;
        }
        else
        {
            if(p==0)
            {
                count++;
                p=1;
            }
            else
            {
                p=0;
            }
        }
    }
    return count>=n;
}
