int x = 5;

int global_ptr_lvalue()
{
    *&x = 10;
    return x;
}