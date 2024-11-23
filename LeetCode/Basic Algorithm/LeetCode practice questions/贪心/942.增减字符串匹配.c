int* diStringMatch(char * s, int* returnSize) {
    int n = strlen(s), lo = 0, hi = n;
    int *perm = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; ++i) {
        perm[i] = s[i] == 'I' ? lo++ : hi--;
    }
    perm[n] = lo; // 最后剩下一个数，此时 lo == hi
    *returnSize = n + 1;
    return perm;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
   int len = strlen(s);
  int *result;
  result = (int *)malloc((len+1) * sizeof(int));

  // result[0] = s[0] == 'I' ? 0 : len;  
//   printf("length %d.",len);
  int max = len , min = 0;

  for (int i = 0; i < len; i++)
  {
    if (s[i] == 'I')
    {
      result[i] = min;
      min++;
    }
    else
    {
      result[i] = max;
      max--;
    }
  }
  result[len] = s[len-1]=='I'?max:min;



  *returnSize = len+1;
  return result ;
}
