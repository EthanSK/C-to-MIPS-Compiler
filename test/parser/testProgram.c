int while_continue()
{
    int sum1 = 0;
    int sum2 = 0;
    while (sum1 < 30)
    {
        sum1++;
        if (sum1 > 15)
        {
            continue;
        }
        sum2++;
    }

    return sum1 + sum2;
}