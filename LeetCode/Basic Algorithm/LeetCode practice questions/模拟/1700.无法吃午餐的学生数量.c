int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int s1 = 0;
    for (int i = 0; i < studentsSize; i++) {
        s1 += students[i];
    }
    int s0 = studentsSize - s1;
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0 && s0 > 0) {
            s0--;
        } else if (sandwiches[i] == 1 && s1 > 0) {
            s1--;
        } else {
            break;
        }
    }
    return s0 + s1;
}
