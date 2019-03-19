int SELF_RECURSION(int r);

int main()
{
    return !(SELF_RECURSION(5) == 12345);
}