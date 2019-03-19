int a = 1, b = 2, c = 3, d = 4;

void set()
{
    b = 4;
    c = 10;
}

int main()
{
    set();
    return a + b + c + d;
}