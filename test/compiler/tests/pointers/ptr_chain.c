int *a;
int **b;
int ***c;

int func(int ****ptr)
{
    return ****ptr;
}

int ptr_chain()
{
    int x = 30;
    a = &x;
    b = &a;
    c = &b;
    return func(&c);
}