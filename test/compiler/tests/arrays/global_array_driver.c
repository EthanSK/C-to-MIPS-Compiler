int global_array();
void set_array();

int main()
{
    set_array();
    return !(global_array() == 496);
}