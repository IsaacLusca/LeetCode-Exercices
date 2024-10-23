#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char caractere;
    struct no *prox;
}No;

No *empilhar(No *topo, char caract)
{
    No *novo = malloc(sizeof(No));
    if (!novo)
    {
        printf("Deu ruim!\n");
        return NULL;
    }
    novo->caractere = caract;
    novo->prox = topo;
    topo = novo;
    return topo;

}

No *desempilhar(No *topo)
{
    if (!topo)
    {
        return NULL;
    }
    No *remover = topo;
    topo = topo->prox;
    free(remover);
    return topo;
}

bool isValid(char* s) {
    int n = strlen(s);
    No *topo = NULL;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            topo = empilhar(topo, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (topo == NULL)
            {
                return false;
            }
            char check = topo->caractere;
            topo = desempilhar(topo);
            if (s[i] == ')' && check != '(' || s[i] == ']' && check != '[' || s[i] == '}' && check != '{')
            {
                return false;
            }
        }
    }
    
    if (topo == NULL)
    {
        return true;
    }
    return false;
}