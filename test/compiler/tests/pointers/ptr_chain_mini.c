int *a;

int func(int **ptr)
{
    return **ptr;
}

int ptr_chain_mini()
{
    int x = 30;
    a = &x;
    return func(&a);
}