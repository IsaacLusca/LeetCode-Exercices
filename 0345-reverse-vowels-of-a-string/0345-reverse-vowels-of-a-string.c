bool checarVogal(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    return false;
}

char* reverseVowels(char* s) {
    int n = strlen(s);
    char *vogais = malloc(n * sizeof(char));
    int count  = 0;

    for (int i = 0; i < n; i++)
    {
        if (checarVogal(s[i]))
        {
            vogais[count] = s[i];
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (checarVogal(s[i]))
        {
            count--;
            s[i] = vogais[count];
        }
    }
    free(vogais);
    return s;
}