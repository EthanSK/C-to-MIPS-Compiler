int array_write(int array[]);

int main()
{
    int array[] = { 10, 20, 30, 40 };
    array_write(array);
    return !(array[0] + array[2] == 15);
}