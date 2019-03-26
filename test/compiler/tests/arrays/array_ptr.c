int x[5];

int *get_ptr()
{
    return &x[3];
}

int array_ptr()
{
    int* ptr = get_ptr();
    *ptr = 10;

    return x[3];
}