int romanToInt(char* s) {
    int comp = strlen(s);
    int soma = 0;
    
    for(int i = 0; i < comp; i++)
    {
        if (s[i] == 'I')
        {
            if (i + 1 < comp && s[i + 1] == 'V')
            {
                soma += 4;
                i++;
            }
            else if (i + 1 < comp && s[i + 1] == 'X')
            {
                soma += 9;
                i++;
            }
            else
            {
                soma += 1;
            }
        }
        else if (s[i] == 'V')
        {
            soma += 5;
        }
        else if (s[i] == 'X')
        {
            if (i + 1 < comp && s[i + 1] == 'L')
            {
                soma += 40;
                i++;
            }
            else if (i + 1 < comp && s[i + 1] == 'C')
            {
                soma += 90;
                i++;
            }
            else
            {
                soma += 10;
            }
        }
        else if (s[i] == 'L')
        {
            soma += 50;
        }
        else if (s[i] == 'C')
        {
            if (i + 1 < comp && s[i + 1] == 'D')
            {
                soma += 400;
                i++;
            }
            else if (i + 1 < comp && s[i + 1] == 'M')
            {
                soma += 900;
                i++;
            }
            else
            {
                soma += 100;
            }
        }
        else if (s[i] == 'D')
        {
            soma += 500;
        }
        else if (s[i] == 'M')
        {
            soma += 1000;
        }
    }
    return soma;
}
