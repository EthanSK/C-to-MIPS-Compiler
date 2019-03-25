int local_ptr_lvalue()
{
    int x = 5;
    *&x = 10;
    return x;
}