bool parseComplexNumber(const char * num, int * real, int * image) {
    char *token = strtok(num, "+");
    *real = atoi(token);
    token = strtok(NULL, "i");
    *image = atoi(token);
    return true;
};

char * complexNumberMultiply(char * num1, char * num2){
    int real1 = 0, imag1 = 0;
    int real2 = 0, imag2 = 0;
    char * res = (char *)malloc(sizeof(char) * 20);
    parseComplexNumber(num1, &real1, &imag1);
    parseComplexNumber(num2, &real2, &imag2);
    snprintf(res, 20, "%d+%di", real1 * real2 - imag1 * imag2, real1 * imag2 + imag1 * real2);
    return res;
}
