int while_break()
{
    int x = 100;
    while (x > 0)
    {
        int trash;
        int y = 50;
        if (--x == y) { break; }
        trash = x + y + 10 * 25;
    }

    return x;
}