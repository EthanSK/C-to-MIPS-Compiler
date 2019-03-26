int *a;
int **b;
int ***c;

int func(int *ptr)
{
    return *ptr;
}

int ptr_chain_mini()
{
    int x = 30;
    return func(&x);
}