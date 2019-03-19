int FOR_N()
{
    int i;
    for (i = 0; i < 1; ++i) /* spec says must execute *more* than one iteration. */
    {
    }
    return i; /*should equal 1*/
}