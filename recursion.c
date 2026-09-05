#include<stdio.h>
#include<stdlib.h>

    typedef struct Vector
    { 
        int capacity ;
        struct core * c;
        struct Vector * next;
    }Vector;

    struct core
    {
        int x;
        int y;
    };

int r_fact(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n * r_fact(n-1);
}

int r_febi(int n)
{
    if(n<=0)
    {
        return 0;
    }
    return (n + r_febi(n-1));
}

void r_f()
{
    int num = r_fact(5);
    int sum = r_febi(100);
    printf("%d\n",num);
    printf("%d\n",sum);
}

int main()
{
    struct core c1 = {4,8};
    struct core c2 = {5,9};
    struct core c3 = {6,10};
    struct core c4 = {7,11};

    Vector* v1 = (Vector *) malloc(sizeof(Vector));
    Vector* v2 = (Vector *) malloc(sizeof(Vector));
    Vector* v3 = (Vector *) malloc(sizeof(Vector));
    Vector* v4 = (Vector *) malloc(sizeof(Vector));

    v1->c = &c1;
    v2->c = &c2;
    v3->c = &c3;
    v4->c = &c4;

    v1->next = v2;
    v2->next = v3;
    v3->next = v4;
    v4->next = NULL;


    printf("%d ,", v1->c->x);
    printf("%d\n", v1->c->y); 
    
    if(v1->next != NULL)
    {
        printf("%d ,", v1->next->c->x);
        printf("%d\n", v1->next->c->y);

    }
    if(v2->next != NULL)
    {
        printf("%d ,", v2->next->c->x);
        printf("%d\n", v2->next->c->y);

    }
    if(v3->next != NULL)
    {
        printf("%d ,", v3->next->c->x);
        printf("%d\n", v3->next->c->y);

    }
    free(v1);
    return 0;
}

