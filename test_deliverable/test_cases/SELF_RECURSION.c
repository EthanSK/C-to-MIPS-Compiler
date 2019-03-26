int SELF_RECURSION(int r)
{
    if (r == 0)
    {
        return 12345;
    }
    return SELF_RECURSION(0);
}