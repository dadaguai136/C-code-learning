int min(char a,char b){//����min���ã������ַ�a���ַ�b������ľ���
    if(a>b){//a>b��������
        if(a-b<(b-a+26))//˳ʱ�����ʱ������
            return a-b;//˳ʱ�벽��
        else//��ʱ�벽�������Դ�������������y��b
            return b-a+26;
    }else{//b>a������������aͬ��
        if(b-a<(a-b+26))
            return b-a;
        else
            return a-b+26;
    }
}
int minTimeToType(char * word){
    int time=0,i=0;
    char pre='a';//��ʼʱ��ָ��a��
    for(i=0;i<strlen(word);i++){
        if(pre!=word[i]){//��һ���ַ���Ŀǰ��Ҫת�����ַ������
            time+=min(pre,word[i]);//ͳ����Ҫת������С����
            pre=word[i];
            time++;//����Ҫ��ӡ���ķ�һʱ��
        }else{//���ֻ��Ҫ��ӡ
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
