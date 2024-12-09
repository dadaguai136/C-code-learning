char * minWindow(char * s, char * t){
    assert(s != NULL);
    assert(t != NULL);
    //s�ĳ���С��t�ĳ��ȿ϶�������
    if(strlen(s)<strlen(t)){
        return "";
    }
    //�����������ߵ�ָ��
    int left=0,right=0;
    int left_last=0,right_last=0;

    //����cha_num������¼t�е���ĸ����ĸ��Ӧ�ĳ��ִ���
    int cha_num[58]={0};
    
    //��ǰt����ĸ��s���Ѿ�������count��
    int count=0;
    
    //�Ӵ����� 
    int len_min=strlen(s);

    //���ؽ����־���ñ�־��ʾs���Ƿ���ڰ���t�����ַ������ַ���
    //���ڣ�ret_flag=1
    //�����ڣ�ret_flag=0
    int ret_flag = 0;

    int j=left_last;


    //����һ���洢�Ӵ��Ŀռ�
    char *ret=(char*)malloc(sizeof(char)*strlen(s)+1);

    //��������cha_num
    for(int i=0;i<strlen(t);++i){
        ++cha_num[t[i]-'A'];
    }

    //������ָ�룬ɨ��s
    for(right=0;right<strlen(s);right++){

        //��ָ��ָ�����ĸ�����t�г��ֹ�����count++
        --cha_num[s[right]-'A'];
        if(cha_num[s[right]-'A']>=0){
            count++;
        }   

        //left��rightȷ�����Ӵ�����t��������ĸ
        if(count == strlen(t)){

            //���ؽ����־��1����ʾs�д��ڰ���t������ĸ�����ַ���
            ret_flag=1;

            //�����ǰleft��ָ����ĸ����t����ĸ����������ָ��left��ָ�����ĸ          
            //��t�г��ֵ���ĸ
            while(cha_num[s[left]-'A'] < 0){
                ++cha_num[s[left]-'A'];
                ++left;
            }   
         
            //�����ǰ�����������Ӵ����ȱ���һ�������������Ӵ����ȸ��̣�
            //���¼ά���Ӵ�����,��¼�Ӵ���ʼ����left�ͽ�β����right
            if(right-left+1 <= len_min){
                len_min = right-left+1;
                left_last = left;
                right_last =right;
            }

            // ����left,ͬʱcount��һ          
            ++cha_num[s[left]-'A'];
            ++left;
            --count;           
        }    
    }

    //��������������������ַ������򷵻ظ��ַ���,���򷵻ؿ��ַ���
    if(ret_flag){         
        //���������������������������
        for( j=left_last;j<=right_last;++j){
            ret[j-left_last]=s[j];
        }
        ret[j-left_last]='\0';
    }else{
        return "";
    }
    
    return ret;
}





#define MAX_STR_SIZE 128

char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int right = 0;
    int left = 0;
    int start = 0;
    int len = INT_MAX;
    int tLen = strlen(t);
    int vailed = 0;
    int need[MAX_STR_SIZE] = { 0 };
    int needNum = 0;
    int window[MAX_STR_SIZE] = { 0 };
    for (int i = 0; i < tLen; i++) {
        need[t[i]]++;
        if (need[t[i]] == 1) {
            needNum++;
        }
    }
    while (right < sLen) {
        char srcData = s[right];
        right++;
        if (need[srcData]) {
            window[srcData]++;
            if (window[srcData] == need[srcData])
                vailed++;
        }
        while (vailed == needNum) {
            char delData = s[left];
            
            if (need[delData]) {
                if (window[delData] == need[delData]) {
                    vailed--;
                    if (right - left < len) {
                        start = left;
                        len = right - left;
                    }
                }
                window[delData]--;
            }
            left++;
        }
    }
    if (len != INT_MAX) {
        char *destStr = malloc(len + 1);
        if (destStr != NULL) {
            memcpy(destStr, s + start, len);
            destStr[len] = '\0';
            return destStr;
        } else {
            return "";
        }
    }
    return "";
}





int getMin(int a,int b)
{
    return a>=b?b:a;
}
char * minWindow(char * s, char * t){
    int debetLength=strlen(t);
    int arrlength=strlen(s);
    int *debet=(int *)malloc(sizeof(int)*256);
    for(int i=0;i<256;i++)
    {
        debet[i]=0;     //��ʼ��
    }
    for(int i=0;i<debetLength;i++)
    {
        debet[t[i]]--;//�ҵ�Ƿծ��
    }
    int l=0;
    int r=0;
    int start=0;
    int min=INT_MAX;
    while(r<arrlength)
    {
        if(debet[s[r]]<0)
        {
            debet[s[r]]++;
            debetLength--;
        }
        else
        {
            debet[s[r]]++;
        }
        if(debetLength==0)//��ʱ����Ҫ����minwindow���Լ�start
        {
            while(debet[s[l]]>0)
            {
                debet[s[l]]--;
                l++;
            }
			if (r - l + 1 <= min) {
                min = r - l + 1;
                start = l;
            }
        }
        r++;
    }
    if(min==INT_MAX)
    {
        return "";
    }
	char *res = (char *)malloc((min + 1) * sizeof(char));
    strncpy(res, s + start, min);
    res[min] = '\0'; // ����ַ���������

    free(debet); // �ͷŶ�̬������ڴ�
    return res;
}






char * minWindow(char * s, char * t){
    int debetLength=strlen(t);
    int arrlength=strlen(s);
    int *debet=(int *)malloc(sizeof(int)*256);
    for(int i=0;i<256;i++)
    {
        debet[i]=0;     //��ʼ��
    }
    for(int i=0;i<debetLength;i++)
    {
        debet[t[i]]--;//�ҵ�Ƿծ��
    }
    int l=0;
    int r=0;
    int start=0;
    int min=INT_MAX;
    while(r<arrlength)
    {
        if(debet[s[r]]<0)
        {
            debet[s[r]]++;
            debetLength--;
        }
        else
        {
            debet[s[r]]++;
        }
        if(debetLength==0)//��ʱ����Ҫ����minwindow���Լ�start
        {
            while(debet[s[l]]>0)
            {
                debet[s[l]]--;
                l++;
            }
			if (r - l + 1 <= min) {
                min = r - l + 1;
                start = l;
            }
        }
        r++;
    }
    if(min==INT_MAX)
    {
        return "";
    }
	char *res = (char *)malloc((min + 1) * sizeof(char));
    strncpy(res, s + start, min);
    res[min] = '\0'; // ����ַ���������

    free(debet); // �ͷŶ�̬������ڴ�
    return res;
}






char * minWindow(char * s, char * t){
    int tLen=strlen(t);
    int sLen=strlen(s);
    int *hash=(int *)malloc(sizeof(int)*256);
    for(int i=0;i<256;i++)
    {
		hash[i]=0;
	}
    for(int i=0;i<tLen;i++)
    {
        hash[t[i]]--;//�ҵ�Ƿծ��
    }
    int l=0;
    int r=0;
    int start=0;
    int min=INT_MAX;
    while(r<sLen)
    {
        if(hash[s[r]]<0)
        {
            hash[s[r]]++;
            tLen--;
        }
        else
        {
            hash[s[r]]++;
        }
        if(tLen==0)//��ʱ����Ҫ����minwindow���Լ�start
        {
            while(hash[s[l]]>0)
            {
                hash[s[l]]--;
                l++;
            }
			if (r - l + 1 <= min) {
                min = r - l + 1;
                start = l;
            }
        }
        r++;
    }
    if(min==INT_MAX)
    {
        return "";
    }
	char *res = (char *)malloc((min + 1) * sizeof(char));
    strncpy(res, s + start, min);
    res[min] = '\0'; // ����ַ���������

    free(hash); // �ͷŶ�̬������ڴ�
    return res;
}
