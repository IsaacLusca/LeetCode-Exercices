/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {

    bool *result = malloc(candiesSize * sizeof(bool));

    int maior = candies[0];

    for (int i = 0; i < candiesSize; i++)
    {
        maior = (maior < candies[i]) ? candies[i]:maior;
        // if (maior < candies[i])
        // {
        //     maior = candies[i];
        // }
    }
    for (int i = 0; i < candiesSize; i++)
    {
        int total = candies[i] + extraCandies;

        result[i] = (total >= maior)?true:false;
        // if (total >= maior)
        // {
        //     result[i] = true;
        // }
        // else
        // {
        //     result[i] = false;
        // }
    }
    *returnSize = candiesSize;
    return result;
}