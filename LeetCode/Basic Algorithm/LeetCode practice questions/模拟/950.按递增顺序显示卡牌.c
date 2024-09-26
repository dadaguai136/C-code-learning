/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    int* ans=(int*)malloc(deckSize*sizeof(int));
    *returnSize=deckSize;
    qsort(deck,deckSize,sizeof(int),cmp);
    int idx[10000];
    for(int i=0;i<deckSize;++i){
        idx[i]=i;
    } 
    int dqf=0,dqr=deckSize-1;
    for(int i=0;i<deckSize;++i){
        ans[idx[dqf]]=deck[i];
        if(dqf<dqr){
            idx[++dqr]=idx[dqf+1];
            dqf+=2;
        }
    }
    return ans;
}
