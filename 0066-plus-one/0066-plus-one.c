/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int z = digitsSize - 1;
    int count = z;

    if (digits[z] == 9)
    {
        while (digits[z] == 9)
        {
            digits[z] = 0;
            z--;
            count--;

            if (count == -1)
            {
                int *novo = malloc((digitsSize + 1) * sizeof(int));
                if (novo == NULL)
                {
                    return NULL;
                }
                novo[0] = 1;
                for(int i = 1; i < digitsSize + 1; i++)
                {
                    novo[i] = 0;
                }
                *returnSize = digitsSize + 1;
                return novo;
            }
        }

        if (digits[z] != 9)
        {
            digits[z] += 1;
        }
    }
    else
    {
        digits[z] += 1;
    }

    *returnSize = digitsSize;
    return digits;
}