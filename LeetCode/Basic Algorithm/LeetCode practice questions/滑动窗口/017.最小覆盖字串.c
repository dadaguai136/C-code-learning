char * minWindow(char * s, char * t){
    assert(s != NULL);
    assert(t != NULL);
    //s的长度小于t的长度肯定不包含
    if(strlen(s)<strlen(t)){
        return "";
    }
    //定义左右两边的指针
    int left=0,right=0;
    int left_last=0,right_last=0;

    //数组cha_num用来记录t中的字母及字母对应的出现次数
    int cha_num[58]={0};
    
    //当前t中字母在s中已经出现了count个
    int count=0;
    
    //子串长度 
    int len_min=strlen(s);

    //返回结果标志，该标志表示s中是否存在包含t所有字符的子字符串
    //存在：ret_flag=1
    //不存在：ret_flag=0
    int ret_flag = 0;

    int j=left_last;


    //申请一个存储子串的空间
    char *ret=(char*)malloc(sizeof(char)*strlen(s)+1);

    //遍历建立cha_num
    for(int i=0;i<strlen(t);++i){
        ++cha_num[t[i]-'A'];
    }

    //右移右指针，扫描s
    for(right=0;right<strlen(s);right++){

        //右指针指向的字母如果在t中出现过，则count++
        --cha_num[s[right]-'A'];
        if(cha_num[s[right]-'A']>=0){
            count++;
        }   

        //left和right确定的子串包含t中所有字母
        if(count == strlen(t)){

            //返回结果标志置1，表示s中存在包含t所有字母的子字符串
            ret_flag=1;

            //如果当前left所指的字母不是t中字母，则右移左指针left至指向的字母          
            //是t中出现的字母
            while(cha_num[s[left]-'A'] < 0){
                ++cha_num[s[left]-'A'];
                ++left;
            }   
         
            //如果当前符合条件的子串长度比上一个符合条件的子串长度更短，
            //则记录维护子串长度,记录子串起始坐标left和结尾坐标right
            if(right-left+1 <= len_min){
                len_min = right-left+1;
                left_last = left;
                right_last =right;
            }

            // 右移left,同时count减一          
            ++cha_num[s[left]-'A'];
            ++left;
            --count;           
        }    
    }

    //如果存在满足条件的子字符串，则返回该字符串,否则返回空字符串
    if(ret_flag){         
        //符合条件的最短数组存入输出数组
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
        debet[i]=0;     //初始化
    }
    for(int i=0;i<debetLength;i++)
    {
        debet[t[i]]--;//我的欠债表
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
        if(debetLength==0)//此时我需要更新minwindow，以及start
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
    res[min] = '\0'; // 添加字符串结束符

    free(debet); // 释放动态分配的内存
    return res;
}






char * minWindow(char * s, char * t){
    int debetLength=strlen(t);
    int arrlength=strlen(s);
    int *debet=(int *)malloc(sizeof(int)*256);
    for(int i=0;i<256;i++)
    {
        debet[i]=0;     //初始化
    }
    for(int i=0;i<debetLength;i++)
    {
        debet[t[i]]--;//我的欠债表
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
        if(debetLength==0)//此时我需要更新minwindow，以及start
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
    res[min] = '\0'; // 添加字符串结束符

    free(debet); // 释放动态分配的内存
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
        hash[t[i]]--;//我的欠债表
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
        if(tLen==0)//此时我需要更新minwindow，以及start
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
    res[min] = '\0'; // 添加字符串结束符

    free(hash); // 释放动态分配的内存
    return res;
}
