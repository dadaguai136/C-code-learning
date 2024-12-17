#define Max(a,b) ((a)>(b)?(a):(b))

int encrypt(char a){
  if(a=='a') return 1;
  if(a=='e') return 2;
  if(a=='i') return 4;
  if(a=='o') return 8;
  if(a=='u') return 16;
  return 0;
}

int popcount(int num){
  int ret = 0;
  while(num > 0){
    ret += (num & 1);
    num >>= 1;
  }
  return ret;
}

int findTheLongestSubstring(char* s) {
  int state = 0, ans = 0;
  int iHateHashMap[32] = {0};
  for(int i = 1; i < 32; i++){
    iHateHashMap[i] = -1;
  }
  for(int i = 0; s[i]; i++){
    state ^= encrypt(s[i]);
    if(iHateHashMap[state] >= 0){
      ans = Max(ans, i + 1 -iHateHashMap[state]);
    }
    else{
      iHateHashMap[state] = i + 1;
    }
  }
  return ans;
}




int move(char cha){
    switch(cha){
        case 'a' : return 0;
        case 'e' : return 1;
        case 'i' : return 2;
        case 'o' : return 3;
        case 'u' : return 4;
        default: return -1;
    }
}
int findTheLongestSubstring(char* s) {
    int n = strlen(s);
    int* map = (int *)malloc(sizeof(int) * 32);
    for(int i = 0;i < 32;i++){
        //-2 ->没出现过
        map[i] = -2;
    }
    //0 : 00000
    //    uoiea
    map[0] = -1;
    int ans = 0;
    for(int i = 0,status = 0,m;i < n;i++){
        m = move(s[i]);
        if(m != -1){
            status ^= 1 << m;
        }
        //!= -2 代表出现过
        if(map[status] != -2){
            ans = fmax(ans,i - map[status]);
        }else{
            map[status] = i;
        }
    }
    return ans;
}
