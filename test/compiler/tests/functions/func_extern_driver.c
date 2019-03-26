int func_extern();
int x = 10;
int get_num() { return x; }

int main()
{
    return !(func_extern() == x); /*exit code 0 means success */
}