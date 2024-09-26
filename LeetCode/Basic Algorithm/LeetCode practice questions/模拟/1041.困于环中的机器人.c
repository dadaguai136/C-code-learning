bool isRobotBounded(char * instructions) {
    int direc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direcIndex = 0;
    int x = 0, y = 0;
    int n = strlen(instructions);
    for (int i = 0; i < n; i++) {
        char instruction = instructions[i];
        if (instruction == 'G') {
            x += direc[direcIndex][0];
            y += direc[direcIndex][1];
        } else if (instruction == 'L') {
            direcIndex += 3;
            direcIndex %= 4;
        } else {
            direcIndex++;
            direcIndex %= 4;
        }
    }
    return direcIndex != 0 || (x == 0 && y == 0);
}
