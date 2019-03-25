int while_break_nested()
{
    int x = 100;
    int z = 100;
    while (x > 0)
    {
        int trash;
        int y = 35;

        while (z > 0)
        {
            int trash;
            int y = 15;
            if (z == y) { break; }
            --z;
            trash = x + y + 10 * 25 - z;
        }
        if (--x == y) { break; }
        trash = x + y + 10 * 25 - z;
    }

    return x + z;
}