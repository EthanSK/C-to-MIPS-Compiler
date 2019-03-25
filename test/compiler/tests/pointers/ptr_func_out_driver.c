int* getPtr();
int getVal();

int main()
{
    const int a = 20;
    int *ptr = getPtr();
    *ptr = a;
    return !(getVal() == a);
}