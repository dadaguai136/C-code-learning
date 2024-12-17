/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* getDistances(int* arr, int arrSize, int* returnSize){
    int max = 0;
    //�������������ֵ������������Ԫ��ֵ�����С�����ֵΪ100000
    for(int i = 0;i < arrSize;i++) {
        max = fmax(max, arr[i]);
    }

    //��ʼ��
    long long* res = (long long*)calloc(arrSize, sizeof(long long)); // ÿ��Ԫ������ͬԪ�ؼ��֮��
    long long* total = (long long*)calloc(max+1,sizeof(long long)); // ÿ����ֵ�����±�֮��
    long long* cnt = (long long*)calloc(max+1,sizeof(long long));// ÿ����ֵ���ִ���
   
    for(int i = 0;i < arrSize;i++) {
        res[i] = cnt[arr[i]] * i - total[arr[i]];
        total[arr[i]] += i;//��ӦԪ�������͸���
        cnt[arr[i]]++;//����Ƶ�ʼ�1
    }
    // ��ձ�������������������ͳ�Ʊ��Լ����֮������
    for(int i = 0;i < max + 1;i++)
        cnt[i] = total[i] = 0;

    for(int i = arrSize - 1;i >= 0;i--) {
        res[i] += total[arr[i]] - cnt[arr[i]] * i;
        total[arr[i]] += i;
        cnt[arr[i]]++;
    }
    *returnSize = arrSize;
    return res;
}
