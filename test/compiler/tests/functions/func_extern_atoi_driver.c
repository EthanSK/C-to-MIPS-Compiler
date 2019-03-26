int func_extern_atoi(const char* str);
const char* str = "20";

int main()
{
    return !(func_extern_atoi(str) == 20);
}