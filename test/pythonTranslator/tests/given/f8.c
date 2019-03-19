int x;

int f()
{
    x=x+1;
    return x;
}

int main()
{
    return f()+f();
}

