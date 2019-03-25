int array_nested_write(int array[4][4]);

int main()
{
    int array[4][4] = {
        { 10, 20, 30, 40 },
        { 11, 21, 31, 41 },
        { 12, 22, 32, 42 }
        ,{ 13, 23, 33, 43 }
    };
    array_nested_write(array);
    return !(array[1][0] + array[3][2] == 15);
}