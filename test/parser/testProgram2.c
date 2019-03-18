int x = 5;
int a1, a2, a3;
int* yy;
auto int a12;
extern auto int a15;
extern a20;
register a50;

double a = 5.5f;

int getNum();
int factorial(int num);
getBigNum();
dumbFactoria(int num);

int main()
{
    if (2 > 1)
    {

    }

    if (3 > 2)
    {
        int xxx = 10;
    }
    return 0;
}

int getNum() { return 10; }

int factorial(int num)
{
    if (num == 0) { return 1; }
    else { return num * factorial(num - 1); }
}

getBigNum() { return 100; }
dumbFactorial(int num)
{
    return num == 0 ? 1 : num * dumbFactorial(num - 1);
}