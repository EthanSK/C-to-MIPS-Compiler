int ptr_func_in();

int main()
{
    int x;
    ptr_func_in(&x, 20);
    return !(x == 20);
}