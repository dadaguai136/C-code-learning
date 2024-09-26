#define MAX_EXPRESSION_LEN 32

char * solveEquation(char * equation) {
    int factor = 0, val = 0;
    int index = 0, n = strlen(equation), sign1 = 1; // ��ʽ���Ĭ��ϵ��Ϊ��
    while (index < n) {
        if (equation[index] == '=') {
            sign1 = -1; // ��ʽ�ұ�Ĭ��ϵ��Ϊ��
            index++;
            continue;
        }

        int sign2 = sign1, number = 0;
        bool valid = false; // ��¼ number �Ƿ���Ч
        if (equation[index] == '-' || equation[index] == '+') { // ȥ��ǰ��ķ���
            sign2 = (equation[index] == '-') ? -sign1 : sign1;
            index++;
        }
        while (index < n && isdigit(equation[index])) {
            number = number * 10 + (equation[index] - '0');
            index++;
            valid = true;
        }

        if (index < n && equation[index] == 'x') { // ����
            factor += valid ? sign2 * number : sign2;
            index++;
        } else { // ��ֵ
            val += sign2 * number;
        }
    }

    if (factor == 0) {
        return val == 0 ? "Infinite solutions" : "No solution";
    }
    char *ans = (char *)malloc(sizeof(char) * MAX_EXPRESSION_LEN);
    sprintf(ans, "x=%d", -val / factor);
    return ans;
}
