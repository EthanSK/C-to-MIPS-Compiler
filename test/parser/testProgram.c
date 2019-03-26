int sizeof_array_local()
{
    int x[5];
    return sizeof(x[3]);
}