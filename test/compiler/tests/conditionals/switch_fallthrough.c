int switch_fallthrough()
{
    int a = 234;
    int y = 10;
    switch (a)
    {
    case 69:
        y += 10;
    case 234:
        y += 20;
    case 713:
        y += 30;
        return y;
    case 100:
        y += 55;
    }
    return 80;
}
