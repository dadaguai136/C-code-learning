//

// int minPartitions(char* n) {
//     int ans=0;
//     for(int i=0;i<strlen(n);i++){
//         ans=fmax(ans,n[i]-'0');
//     }
//     return ans;
// }

int minPartitions(char* n) {
    int size=strlen(n);
    int max=0;
    for(int i=0;i<size;i++){
        if(n[i]>max){
            max=n[i];
        }
    }
    return max-'0';
}
