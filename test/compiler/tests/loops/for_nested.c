int for_nested()
{
    int sum = 0;
    int i;
    for (i = 0; i < 4; ++i) 
    {
        int j;
        for(j = 0; j < 5; j++)
        {
            sum++;
        }
    }
    return sum; 
}