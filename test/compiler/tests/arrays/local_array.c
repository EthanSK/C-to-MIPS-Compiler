int local_array()
{
    int array[32];
    int result = 0;

    int i;
    for (i = 0; i < 32; ++i) { array[i] = i; }
    for (i = 0; i < 32; ++i) { result += array[i]; }

    return result;
}