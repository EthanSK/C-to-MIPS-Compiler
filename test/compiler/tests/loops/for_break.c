int for_break()
{
    int i;
    for (i = 0; i < 20; ++i) 
    {
        if (i == 10)
        {
            break;
        }
    }
    return i; 
}