#include<stdio.h>

int r_fact(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n * r_fact(n-1);
}
int main()
{
    int num = r_fact(5);

    printf("%d",num);
    return 0;
}