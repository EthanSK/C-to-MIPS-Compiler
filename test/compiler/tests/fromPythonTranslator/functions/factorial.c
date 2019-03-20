int factorial(int n)
{
    if (n == 0) { return 1; }
    else { return n * factorial(n - 1); }
}

int MAIN_FUNCTION_factorial()
{
    return factorial(5);
}
