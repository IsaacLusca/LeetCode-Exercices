#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2)
{
    char *merged = malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
    int i = 0, j = 0, k = 0;

    while (word1[i] != '\0' || word2[j] != '\0')
    {
        if (word1[i] != '\0')
        {
            merged[k] = word1[i];
            k++;
            i++;
        }
        if (word2[j] != '\0')
        {
            merged[k] = word2[j];
            k++;
            j++;
        }
    }
    merged[k] = '\0';
    printf("%s\n", merged);
    return merged;
}
