// #include <stdio.h>

char lololo(int pp)
{
   return 'a';
}

enum Test
{
   lol1,
   lol3
};

struct Poop
{
   int a;
   double b;
};

union Poop2 {
   int a;
   double b;
};
int main()
{
   struct Poop hello = {5, 6.9};
   struct
   {
      int a[3], b;
   } w[] = {{1}, 2};

   short q[4][3][2] = {
       {1},
       {2, 3},
       {4, 5, 6}};

   int zzz = 3;
   int i = 2;
   int result = i + zzz;
   char kkkkk = 'kkkkkkkkkkk';
   int aaao[6] = {1, 3, 5, 5, 5, 6};
   double weirdarray[3];
   for (i = 0; i < 50; i++)
   {
      zzz++;
      if (i > 5)
      {
         break;
      }
      i++;
   }

   do
   {
      i++;
   } while (i < 5);

   float (*op[42])(float, float); //this gets converted to 1 vardecl node

   {
      int z;
      z = 3;
      z++;
      {
         if (z < 4)
         {
            int b = 4;
            b += 4;
            b >>= 6;
         }
         else if (z < 3)
         {
            int a = 2;
         }

         if (z > 5)
         {
            z--;
         }
         else
         {
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