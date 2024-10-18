int removeElement(int* nums, int numsSize, int val) {
    int novo = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[novo] = nums[i];
            novo++;
        }
    }
    return novo;
}