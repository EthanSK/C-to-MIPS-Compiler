int func(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9 ,int x10)
{
    return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10;
}

int fcall10()
{
    int x = 1, y = 2, z = 6, k = 10;
    return func(x, y, 3, 4, 5, z, 7, 8, 9, k);
}