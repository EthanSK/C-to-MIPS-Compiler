int shadowing()
{
    int x = 1;
    int y = 0;
    {
        int x = 2;
        {
            int x = 3;
            {
                int x = 4;
                {
                    int x = 5;
                    y += x;
                }
                y += x;
            }
            y += x;
        }
        y += x;
    }
    y += x;

    return y;
}