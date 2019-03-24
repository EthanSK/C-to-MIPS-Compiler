int x;
int foo(int addr, int ret)
{
    x += addr;
    return ret;
}

int shortcircuit_or()
{
    x = 0;
    foo(1, 1) || foo(2, 1);
    foo(3, 1) || foo(4, 0);
    foo(5, 0) || foo(6, 1);
    foo(7, 0) || foo(8, 0);
    return x;
}