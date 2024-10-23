typedef struct no{
    char elem;
    struct pilha *prox;
}No;

No *add(No *topo, char caract)
{
    No *novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        return NULL;
    }
    novo->elem = caract;
    novo->prox = topo;
    topo = novo;

    return topo;
}

No *rem(No *topo)
{
    if (topo == NULL)
    {
        printf("Sem valor para desempilhar/n");
        return NULL;
    }
    No *remover = topo;
    topo = topo->prox;
    free(remover);
    return topo;
}

bool isValid(char* s) {
    No *topo = NULL;
    int n = strlen(s);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            topo = add(topo, s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (topo == NULL)
            {
                return false;
            }
            char topChar = topo->elem;
            topo = rem(topo);
            if (s[i] == ')' && topChar != '(' ||
                s[i] == ']' && topChar != '[' ||
                s[i] == '}' && topChar != '{'
            )
            {
                return false;
            }
        }
        i++;
    }
    if (topo == NULL)
    {
        return true;
    } 
    return false;
}