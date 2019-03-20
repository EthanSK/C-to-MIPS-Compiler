int a = 1, b = 2, c = 3, d = 4;

void set()
{
    b = 4;
    c = 10;
}

int MAIN_FUNCTION_var_global_multi()
{
    set();
    return a + b + c + d;
}
