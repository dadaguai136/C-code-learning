int minimumRefill(int* plants, int n, int A, int B) {
    int ans = 0;
    int l = 0, r = n - 1;
    int ra = A, rb = B;
    while(l < r){
        if(ra >= plants[l]){
            ra -= plants[l];
        }
        else{
            ans++;
            ra = A - plants[l];
        }
        if(rb >= plants[r]){
            rb -= plants[r];
        }
        else{
            ans++;
            rb = B - plants[r];
        }
        l++, r--;
    }
    if(l == r) ans += (fmax(ra, rb) < plants[r]);
    return ans;
}
