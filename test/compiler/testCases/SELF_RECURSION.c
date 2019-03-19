int SELF_RECURSION(int r) /*r is number of times to recurse */
{
    if (r == 0)
    {
        return 12345;
    }
    return SELF_RECURSION(r - 1);
}