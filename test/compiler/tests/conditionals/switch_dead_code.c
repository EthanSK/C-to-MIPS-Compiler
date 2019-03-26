int switch_dead_code()
{
    int a = 0;
    switch (1)
    {
        a += 39;
    case 1:
        a += 8;
    }
    return a;
}
