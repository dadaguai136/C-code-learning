int maxDistance(int* colors, int colorsSize) {
    int maximumDistance = 0;
    for (int i = 0; i < colorsSize; i++) {
        for (int j = i + 1; j < colorsSize; j++) {
            if (colors[i] != colors[j]) {
                maximumDistance = fmax(maximumDistance, j - i);
            }
        }
    }
    return maximumDistance;
}
