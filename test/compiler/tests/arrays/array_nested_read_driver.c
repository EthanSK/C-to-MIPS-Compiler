int array_nested_read(int array[4][4]);

int main()
{
    int array[4][4] = {
        { 10, 20, 30, 40 },
        { 11, 21, 31, 41 },
        { 12, 22, 32, 42 }
        ,{ 13, 23, 33, 43 }
    };
    return !(array_nested_read(array) == 44);
}