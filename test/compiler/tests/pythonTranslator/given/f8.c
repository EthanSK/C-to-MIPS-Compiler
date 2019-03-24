int x;

int f()
{
    x=x+1;
    return x;
}

int MAIN_FUNCTION_f8()
{
    return f()+f();
}

