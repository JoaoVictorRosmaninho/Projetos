#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    int num;
} Datatype;

typedef struct node
{
    Datatype data;
    struct node *next;
} Pilha;

enum states {FAILED, SUCCESS};

/* headers */
static Pilha *makenode(Datatype data);
int push(Pilha **ptr, Datatype data);
void print(Pilha *ptr);
/* headers */

static Pilha *makenode(Datatype data)
{
    Pilha *tmp;
    if((tmp = (Pilha *) malloc(sizeof(Pilha))) == NULL)
    {
        fprintf(stderr, "%s\n", "Memoria Insuficiente");
        exit(FAILED);
    }
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

int push(Pilha **ptr, Datatype data)
{
    Pilha *tmp = makenode(data);
    if(*ptr == NULL)
    {
        *ptr = tmp;
        return SUCCESS;
    }
    tmp->next = *ptr;
    *ptr = tmp;
    return SUCCESS;
}

void print(Pilha *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data.num);
        ptr = ptr->next;
    }
    putchar('\n');
}

Datatype pop(Pilha **ptr)
{
    if(*ptr == NULL)
    {
        fprintf(stderr, "%s\n", "A pilha ja está vazia");
        exit(FAILED);
    }
    Pilha *tmp = *ptr;
    Datatype aux = tmp->data; 
    *ptr = (*ptr)->next;
    free(tmp);
    return aux;
}