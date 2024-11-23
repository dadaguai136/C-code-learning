
int cmp(int* a,int* b){
    return *b-*a;
}
int halfQuestions(int* questions, int questionsSize){
    int app[1000]={0};
    for(int i=0;i<questionsSize;i++){
        app[questions[i]-1]++;
    }
    qsort(app,1000,sizeof(int),cmp);
    int num=0,i=0,peo=questionsSize/2;
    while(peo>0&&i<1000){
        peo -= app[i++];
        num++;
    }
    return num;
}
