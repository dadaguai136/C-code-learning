bool isP(char*s,int left,int right){
    while(left<right){
        if(s[left]!=s[right])return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char * s){
    int left=0;
    int right=strlen(s)-1;
    while(s[left]==s[right]){
        if(left>=right)
            return true;
        left++;
        right--;
    }
    return isP(s,left+1,right)||isP(s,left,right-1);
    
}



bool dfs(char * s, int l, int r, bool fl) {
    if (l >= r) return true;
    if (s[l] == s[r]) return dfs(s, l + 1, r - 1, fl);
    if (fl) return false;
    return dfs(s, l + 1, r, true) || dfs(s, l, r - 1, true);
}
bool validPalindrome(char * s){
    return dfs(s, 0, strlen(s) - 1, false);
}
