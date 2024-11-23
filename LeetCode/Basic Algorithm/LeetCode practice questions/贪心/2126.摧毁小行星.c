int cmpfunc(const void* a, const void* b){
    return (*((int*)a)) - (*((int*)b));
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){
    //��ѵ�˳�򣬻��ǿ������Ժ�һ������������
    qsort(asteroids, asteroidsSize, sizeof(int), cmpfunc);
    if(mass < asteroids[0]){
        return false;
    }
    if(mass > asteroids[asteroidsSize - 1]){
        return true;
    }
    //ǰ�����жϣ���Լʱ��
    int ans = mass;
    int i;
    for(i = 0; i < asteroidsSize; i++){
        if(ans < asteroids[i]){
            return false;
        }
        if(ans >= INT_MAX - asteroids[i]){//������ans+ asteroids[i],���ܳ���int
            return true;
        }
        ans += asteroids[i];
    }
    return true;
}
