#include <time.h>

typedef struct {
    int *array;
    int *origin;
    int size;
} Solution;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int randomInt(int min, int max){
    int ret = rand() % (max - min + 1) + min;
    return ret;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *new = malloc(sizeof(Solution));
    new->size = numsSize;
    new->array = malloc(sizeof(int) * numsSize);
    new->origin = malloc(sizeof(int) * numsSize);
    for(int i = 0; i <  numsSize; i++){
        new->array[i] = nums[i];
        new->origin[i] = nums[i];
    }
    return new;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;
    for(int i = 0; i < *retSize; i++){
        obj->array[i] = obj->origin[i];
    }
    return obj->array;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->size;
    int swapIndex;
    //srand(time(NULL));
    for(int i = 0; i < *retSize; i++){
        swapIndex = randomInt(i, *retSize - 1);
        swap(&(obj->array[i]), &(obj->array[swapIndex]));
    }
    return obj->array;
}

void solutionFree(Solution* obj) {
    free(obj->array);
    free(obj->origin);
    free(obj);
    return;
}
/*˼·��
��array��Ҫ���ϴ�Ƶ����飬origin���ʼ���������ڸ�λ
��������[min,max]��������� rand()%(max - min + 1) + min
��ע�⣬������srand(time(NULL))�Ļ����ܵõ�ȫ���еġ����ȡ�����������Բ��ã�
ϴ�ƣ��������飬�ڵ�ǰԪ��(������ǰ)����������������һ���͵�ǰԪ�ؽ���
��λ����arrayѭ����ֵ�ָ�Ϊorigin
*/

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/
