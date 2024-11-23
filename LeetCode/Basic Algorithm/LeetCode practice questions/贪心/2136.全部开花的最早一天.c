typedef struct  {
    int p, g;
}Pair;

int cmp(const void *a, const void *b) {
    Pair * pa = (Pair *)a;
    Pair * pb = (Pair *)b;
    return (pb->g)-(pa->g);
}

int earliestFullBloom(int* plantTime, int n, int* growTime, int growTimeSize){
    Pair P[100005];
    int i;
    int cur = 0;
    int max = 0;
    for(i = 0; i < n; ++i) {
        P[i].p = plantTime[i];
        P[i].g = growTime[i];
    }
    qsort(P, n, sizeof(Pair), cmp);
    for(i = 0; i < n; ++i) {
        cur += P[i].p;
        if(cur + P[i].g > max) {
            max = cur + P[i].g;
        }
    }
    return max;
}





typedef struct {
    int plant;
    int flower;
} Grass;

int Compare(void *a, void *b)
{
    Grass *aa = (Grass *)a;
    Grass *bb = (Grass *)b;
    return bb->flower - aa->flower; 
}

int earliestFullBloom(int* plantTime, int plantTimeSize, int* growTime, int growTimeSize){
    Grass *data = (Grass *)calloc(plantTimeSize, sizeof(Grass));
    for (int i = 0; i < plantTimeSize; i++) {
        data[i].plant = plantTime[i];
        data[i].flower = growTime[i];
    }

    qsort(data, plantTimeSize, sizeof(Grass), Compare);

    int ans = 0;
    int time = 0;
    for (int i = 0; i < plantTimeSize; i++) {
        ans = fmax(ans, time + data[i].plant + data[i].flower + 1);
        time += data[i].plant;
    }
    return ans - 1;
}
