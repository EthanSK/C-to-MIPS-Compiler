int x = 5;

int global_min()
{
    return *&x;
}