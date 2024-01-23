#include <stdio.h>

double get_valid_double()
{
    double tmp;
    int status = scanf("%lf",&tmp);
    while(status!=1||getchar()!=10)
    {
        printf("INPUT ERROR! ENTER DOUBLE!\n");

       while(getchar()!=10)
       {
           status = 0;
       }
        status = scanf("%lf",&tmp);
    }
    return tmp;
}


void zadacha1 ()
{
    double x1,x2,x3;
 printf("ENTER first num: ");
 x1 = get_valid_double();
  printf("ENTER second num: ");
 x2 = get_valid_double();
  printf("ENTER third num: ");
 x3 = get_valid_double();
 x1>x2? (x1>x3? printf("Max = %5.2lf\n",x1):printf("Max = %5.2lf\n",x3)):(x2>x3 ? printf("Max = %5.2lf\n",x2):printf("Max = %5.2lf\n",x3));
}

int main()
{
zadacha1();
}
