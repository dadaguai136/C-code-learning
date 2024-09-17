int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < arr1Size; i++) {
        cnt = 0;
        for (int j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) > d) {
                cnt++;
            } 
            else 
            {
                break;
            }
        }
        if (cnt == arr2Size) {
            idx++;
        }
    }
    return idx;
}
