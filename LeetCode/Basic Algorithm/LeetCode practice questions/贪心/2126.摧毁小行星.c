int cmpfunc(const void* a, const void* b){
    return (*((int*)a)) - (*((int*)b));
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){
    //最佳的顺序，还是快排了以后一个个慢慢吞噬
    qsort(asteroids, asteroidsSize, sizeof(int), cmpfunc);
    if(mass < asteroids[0]){
        return false;
    }
    if(mass > asteroids[asteroidsSize - 1]){
        return true;
    }
    //前置性判断，节约时间
    int ans = mass;
    int i;
    for(i = 0; i < asteroidsSize; i++){
        if(ans < asteroids[i]){
            return false;
        }
        if(ans >= INT_MAX - asteroids[i]){//不能用ans+ asteroids[i],可能超过int
            return true;
        }
        ans += asteroids[i];
    }
    return true;
}
