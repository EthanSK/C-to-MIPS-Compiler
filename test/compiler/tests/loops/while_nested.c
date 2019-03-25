int while_nested()
{
    int x = 0;
    int z = 0;
    while (x < 10)
    {
        int y = 0;
        x++;
        while (y < 10)
        {
            y++;
            z++;
        }
    }

    return z;
}