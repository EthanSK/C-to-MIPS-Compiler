extern int someInt[2 * 5];
int a1 = 1, a2 = 2, a3 = 3;

int factorial(int n)
{
    if (n < 1) { return 1; }
    else { return n * factorial(n - 1); }
}

int main()
{
    return 0;
}
