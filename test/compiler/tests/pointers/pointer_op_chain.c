int pointer_op_chain()
{
    int x = 5;
    return *&*&*&*&x;
}