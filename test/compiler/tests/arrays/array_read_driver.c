int array_read(int array[]);

int main()
{
    int array[] = { 10, 20, 30, 40 };
    return !(array_read(array) == 40);
}