int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
    {
        return 0;
    }
    // Como o primeiro elemento estará correto, vamos contar a partir do segundo
    int array = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[array] = nums[i];
            array++;
        }
    }
    return array;
}