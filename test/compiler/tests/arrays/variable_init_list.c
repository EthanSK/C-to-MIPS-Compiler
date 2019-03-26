int variable_init_list()
{
    int x = 1;
    int array[] = { x, x * 3, x + 4, 7 };
    int acc = 0;

    int i;
    for (i = 0; i < 4; ++i) { acc += array[i]; }

    return acc;
}