int countOperations(int num1, int num2) {
    int count = 0;
    while(num1 != 0 && num2 != 0){
        if(num1 >= num2) {
            num1 = num1 - num2;count++;
        }
        else {
            num2 = num2 - num1;count++;
        }
    }
    return count;
}


int countOperations(int num1, int num2){
    int cnt = 0;
    while (num1 && num2)
        if (num1 >= num2){
            cnt += num1 / num2;
            num1 %= num2;
        }
        else{
            cnt += num2 / num1;
            num2 %= num1;           
        }
    return cnt;
}
