int addDigits(int num) {
    while(1)
    {
        int ans=0;
        while(num)
        {
            ans+=num%10;
            num=num/10;
        }
        if(ans<10)
        {
            return ans;
        }
        else
        {
            num=ans;
        }
    }
}
