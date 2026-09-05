#include<stdio.h>
#include<stdlib.h>

    typedef struct Vector
    { 
        int capacity;
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
    struct core v = {4,5};
    Vector* v1 = (Vector *) malloc(sizeof(Vector));
    v1->c = &v;
    v1->next = NULL;

    printf("%d\n", v1->c->x);
    printf("%d\n", v1->c->y); 
 

    free(v1);
    return 0;
}

