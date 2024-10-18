int searchInsert(int* nums, int numsSize, int target) {
    int sort = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (target > nums[i])
        {
            sort++;
        }
        else
        {
            return sort;
        }
        if (nums[i] == target)
        {
            return i;
        }
    }
    return sort;
}