/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Como há 2 elementos no array 
    int *saida = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                saida[0] = i;
                saida[1] = j;
                *returnSize = 2;
                return saida;
            }
        }
    }
    free(saida);
    return NULL;
}