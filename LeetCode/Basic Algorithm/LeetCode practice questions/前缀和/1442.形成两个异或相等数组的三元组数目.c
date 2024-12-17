struct HashTable {
    int val, key;
    UT_hash_handle hh;
};

bool count(struct HashTable* hashTable, int x) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashTable, &x, tmp);
    return tmp != NULL;
}

int getValue(struct HashTable* hashTable, int x) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashTable, &x, tmp);
    return tmp == NULL ? 0 : tmp->val;
}

void addValue(struct HashTable** hashTable, int x, int y) {
    struct HashTable* tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = x;
        tmp->val = y;
        HASH_ADD_INT(*hashTable, key, tmp);
    } else {
        tmp->val += y;
    }
}

int countTriplets(int* arr, int arrSize) {
    int n = arrSize;
    struct HashTable *cnt = NULL, *total = NULL;
    int ans = 0, s = 0;
    for (int k = 0; k < n; ++k) {
        int val = arr[k];
        if (count(cnt, s ^ val)) {
            ans += getValue(cnt, s ^ val) * k - getValue(total, s ^ val);
        }
        addValue(&cnt, s, 1);
        addValue(&total, s, k);
        s ^= val;
    }
    return ans;
}




struct HashTable {
    int val, key;
    UT_hash_handle hh;
};

bool count(struct HashTable* hashTable, int x) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashTable, &x, tmp);
    return tmp != NULL;
}

int getValue(struct HashTable* hashTable, int x) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashTable, &x, tmp);
    return tmp == NULL ? 0 : tmp->val;
}

void addValue(struct HashTable** hashTable, int x, int y) {
    struct HashTable* tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = x;
        tmp->val = y;
        HASH_ADD_INT(*hashTable, key, tmp);
    } else {
        tmp->val += y;
    }
}

int countTriplets(int* arr, int arrSize) {
    int n = arrSize;
    int s[n + 1];
    s[0] = 0;
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    struct HashTable *cnt = NULL, *total = NULL;
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        if (count(cnt, s[k + 1])) {
            ans += getValue(cnt, s[k + 1]) * k - getValue(total, s[k + 1]);
        }
        addValue(&cnt, s[k], 1);
        addValue(&total, s[k], k);
    }
    return ans;
}




int countTriplets(int* arr, int arrSize) {
    int n = arrSize;
    int s[n + 1];
    s[0] = 0;
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            if (s[i] == s[k + 1]) {
                ans += k - i;
            }
        }
    }
    return ans;
}




int countTriplets(int* arr, int arrSize) {
    int n=arrSize;
    int s[n+1];
    s[0]=0;
    for(int i=0;i<n;i++)
    {
        s[i+1]=s[i]^arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j;k<n;k++)
            {
                if(s[i]==s[k+1])
                {
                    ++ans;
                }
            }
        }
    }
    return ans;
}
