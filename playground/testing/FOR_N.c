int FOR_N(){
    int i;
    for(i = 0; i < 5; ++i) /* spec says must execute *more* than one iteration. */
    {
        
    }
    return i; /*should equal 1*/
}

int main(){
    return FOR_N();
}