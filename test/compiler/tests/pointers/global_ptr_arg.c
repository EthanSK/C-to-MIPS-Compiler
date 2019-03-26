int x = 30;

int func(int *ptr)
{
    return *ptr;
}

int global_ptr_arg()
{
    return func(&x);
}