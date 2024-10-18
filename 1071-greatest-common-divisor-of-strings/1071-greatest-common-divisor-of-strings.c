#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int mdc = gcd(len1, len2);

    char *divisor = malloc((mdc + 1) * sizeof(char));

    strncpy(divisor, str1, mdc);
    divisor[mdc] = '\0';
    
    int i = 0;
    while (i < len1)
    {
        if(strncmp(divisor, &str1[i], mdc) != 0)
        {
            free(divisor);
            return "";
        }
        i += mdc;
    }
    
    i = 0;
    while(i < len2)
    {
        if(strncmp(divisor, &str2[i], mdc) != 0)
        {
            free(divisor);
            return "";
        }
        i += mdc;
    }
    return divisor;
}