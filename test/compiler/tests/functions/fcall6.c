int func(int a, int b, int c, int d, int e, int f)
{
    return a + b + c + d + e + f;
}

int fcall6()
{
    int x = 1, y = 2, z = 6;
    return func(x, y, 3, 4, 2 + 3, z);
}