// strcat - usado para conCATenar strings - juntar - 
// strncpy - 
char* reverseWords(char* s) {
    int n = strlen(s);
    char *troca = malloc((n + 1) * sizeof(char));
    char *palavra[n];
    
    // Para esse problema, é util saber o inicio e fim de uma palavra e contar quantas palavras há
    int inicio = 0, fim  = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        // ignora espaço em branco
        if (s[i] == ' ')
        {
            continue;
        }

        // enquanto for menor que n e for uma letra.
        inicio = i;
        while (i < n && (s[i] != ' '))
        {
            i++;
        }
        fim = i;

        // Com o inicio e fim, pode calcular o comprimento e alocar o valor adequado
        int len = fim - inicio;
        palavra[count] = malloc((len + 1) * sizeof(char));
        strncpy(palavra[count], s + inicio, len);
        palavra[count][len] = '\0';
        count++;

    }
    
    troca[0] = '\0';
    for (int i = count - 1; i >= 0; i--)
    {
        strcat(troca, palavra[i]);
        if (i > 0)
        {
            strcat(troca, " ");
        }
        free(palavra[i]);
    }
    return troca;
}