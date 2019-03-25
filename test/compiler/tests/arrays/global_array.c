int array[32];

void set_array()
{
    int i;
    for (i = 0; i < 32; ++i) { array[i] = i; }
}

int global_array()
{
    int result = 0;

    int i;
    for (i = 0; i < 32; ++i) { result += array[i]; }

    return result;
}