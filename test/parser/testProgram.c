int factorial1(int n)
{
    if (n == 0) { return 1; }
    else { return n * factorial2(n - 1); }
}

int factorial2(int n)
{
    if (n == 0) { return 1; }
    else { return n * factorial1(n - 1); }
}

int mutual_recursion()
{
    return factorial1(5);
}