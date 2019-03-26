int local_init_list()
{
    int array[4] = { 1, 3, 5, 7 };
    int acc = 0;

    int i;
    for (i = 0; i < 4; ++i) { acc += array[i]; }

    return acc;
}