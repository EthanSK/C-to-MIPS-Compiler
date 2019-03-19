int factorial(int n)
{
    if (n == 0) { return 1; }
    else { return n * factorial(n - 1); }
}

int main()
{
    int x;
    int y = factorial(5);

    x = y;
    return x;
}
