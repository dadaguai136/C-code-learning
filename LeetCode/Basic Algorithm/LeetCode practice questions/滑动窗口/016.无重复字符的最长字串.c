int lengthOfLongestSubstring(char *s)
{
    int res=0;
    int hash[500];
    memset(hash,0,sizeof(hash));
    int len=strlen(s);
    if(len==0) return 0;
    for(int i=0,j=0;j<len;j++)
    {
        hash[s[j]]++;
        if(hash[s[j]]==2)
        {
            res=fmax(res,j-i);
            while(hash[s[j]]!=1)
            {
                hash[s[i]]--;
                i++;
            }
        }
        res=fmax(res,j-i+1);
    }
    return res;
}




int lengthOfLongestSubstring(char * s){
    int map[128] = {0};
    memset(map,-1,sizeof(int)*128);
    int left = -1;//��¼�������ظ������߽硣Ϊʲô��-1����Ϊ���ֻ��һ���ַ���Ӧ����0-(-1)Ӧ����1
    int max = 0;//��¼���Ĳ��ظ��Ӵ��ĳ��ȡ�
    for(int i = 0; s[i]!='\0';i++){//�����ַ�����
        if(map[s[i]]  == -1){//����ַ�û�г��ֹ���
            map[s[i]] = i;
        }else{ //���ֹ�������left
            left = left < map[s[i]]?map[s[i]]:left;
            map[s[i]] = i;//��������ַ����ֵ���λ��
        }
        int len = i - left;
        max = max<len?len:max;
    }
    return max;
}
