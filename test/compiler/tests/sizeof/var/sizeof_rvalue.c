int rvalue()
{
    return 10 >> 2 / 3 + 5;
}

int sizeof_rvalue()
{
    return sizeof(rvalue());
}