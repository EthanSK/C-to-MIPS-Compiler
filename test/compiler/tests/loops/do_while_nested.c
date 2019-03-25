int do_while_nested()
{
    int x = 0;
    int z = 0;
    do
    {
        int y = 0;
        x++;
        do
        {
            y++;
            z++;
        } while (y < 10);
    } while (x < 10);

    return z;
}