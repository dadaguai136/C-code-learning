int wateringPlants(int* plants, int n, int c) {
    int ans = 0, remain = c;
    for(int i = -1; i < n - 1; i++){
        if(remain >= plants[i + 1]){
            remain -= plants[i + 1];
            ans += 1;
        }
        else{
            remain = c - plants[i + 1];
            ans += ((i + 1) << 1) + 1;
        }
    }
    return ans;
}
