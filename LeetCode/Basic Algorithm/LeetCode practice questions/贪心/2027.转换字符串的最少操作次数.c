int minimumMoves(char* s) {
    int covered=-1,res=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='X'&&i>covered)
        {
            res+=1;
            covered=i+2;
        }
    }
    return res;
}
