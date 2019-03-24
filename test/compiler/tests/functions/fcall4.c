int func(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int fcall4()
{
    int x = 1, y = 2;
    return func(x, y, 3, 2 + 2);
}