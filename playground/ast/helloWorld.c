// #include <stdio.h>
int main()
{
{
   int z;
   z = 3;
   z++;
   {
      if (z < 4) {
         int b = 4;
         b += 4;
         b >>= 6; 
      } else if (z < 3){
         int a = 2;
      }

      if ( z > 5) {
         z--;
      }else{
         z = 1;
      }
      
   }
}

   int a = 5;
   a++;
   int b = 6;
   b = a + 2;
   return 0;
}