int ptr_arithmetic();

int main()
{
    const int index = 2;
    int x[] = { 10, 20, 30, 40 };
    int *y = ptr_arithmetic(&x, index);
    return !(x[index] == *y);
}