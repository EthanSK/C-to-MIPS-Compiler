int main()
{
    int x = 5;
    *&x = 10;
    return x;
}