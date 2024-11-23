int min(char a,char b){//函数min作用，返回字符a和字符b在最近的距离
    if(a>b){//a>b两种条件
        if(a-b<(b-a+26))//顺时针比逆时针距离近
            return a-b;//顺时针步数
        else//逆时针步数，可以代入特例，比如y和b
            return b-a+26;
    }else{//b>a两种条件，和a同理
        if(b-a<(a-b+26))
            return b-a;
        else
            return a-b+26;
    }
}
int minTimeToType(char * word){
    int time=0,i=0;
    char pre='a';//开始时是指向a的
    for(i=0;i<strlen(word);i++){
        if(pre!=word[i]){//上一个字符与目前将要转到的字符不相等
            time+=min(pre,word[i]);//统计需要转动的最小步数
            pre=word[i];
            time++;//还需要打印，耗费一时间
        }else{//相等只需要打印
            time++;
        }
    }
    return time;
}



int minTimeToType(char* word) {
    int res=0;
    int prev=0;
    for(int i=0;word[i];i++)
    {
        int curr=word[i]-'a';
        res+=1+fmin(abs(curr-prev),26-abs(curr-prev));
        prev=curr;
    }
    return res;
}
