int function(int a, int b)
{
    if(a<b){
        a=a-1;
        if(b<a){
            b=b+3;
            if(a==b){
                return a*b;
            }
        }
        return b;
    }
    return 13;
}

int main()
{
    return function(0,0)+function(1,2)+function(4,3)+function(6,7);
}

