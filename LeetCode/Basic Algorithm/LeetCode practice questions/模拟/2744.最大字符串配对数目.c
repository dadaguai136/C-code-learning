int maximumNumberOfStringPairs(char ** words, int wordsSize){
    int ans=0;
    for(int i=0;i<wordsSize;i++)
    {
        for(int j=i+1;j<wordsSize;j++)
        {
            if(words[i][0]==words[j][1]&&words[i][1]==words[j][0])
            {
                ans++;
            }
        }
    }
    return ans;
}




int maximumNumberOfStringPairs(char ** words, int wordsSize){
    int ans = 0;
    bool seen[26][26] = {};
    for(int i = 0; i < wordsSize; i ++ ){
        char *word = words[i];
        int x = word[0] - 'a';
        int y = word[1] - 'a';
        if(seen[y][x]){
            ans ++ ;
        }
        else{
            seen[x][y] = true;
        }
    }
    return ans;
}
