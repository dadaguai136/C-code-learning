char* decodeCiphertext(char* encodedText, int rows) {
    int codeLen = strlen(encodedText);
    int columns = codeLen / rows;
    int index = 0;
    char *decodeStr = malloc(sizeof(char) * (codeLen + 1));
    for (int i = 0; i < columns; i++) {
        for (int j = i; j < codeLen; j += columns + 1) {
            // printf("%c\n",encodedText[j]);
            decodeStr[index++] = encodedText[j];
        }
    }
    decodeStr[index] = '\0';
    for (int k = index; k >= 0; k--) {
        if (decodeStr[k] == ' ' || decodeStr[k] == '\0') {
            decodeStr[k] = '\0';
        } else {
            return decodeStr;
        }
    }
    return decodeStr;
}
