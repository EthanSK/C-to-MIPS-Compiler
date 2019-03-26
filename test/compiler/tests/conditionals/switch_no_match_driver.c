int switch_no_match();

int main()
{
    return !(switch_no_match() == 80); /*should not enter switch as no matches*/
}