#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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


void zadacha2()
{
 printf("ENTER X = ");
 double x = get_valid_double();
 if(x<0){double t =2*abs(x)-1; printf("Result f(x) = %5.2lf",t);}
 else if(x==0){printf("Result f(x) = 0");}
 else if(x>0){double t = (2*x-10); printf("Result f(x) = %5.2lf",t);}
}

void zadacha3()
{
    printf("ENTER N = ");
    int n = (int)get_valid_double();
    printf("ENTER K = ");
    int k = (int)get_valid_double();
    if(n%k==0){printf("N divisible K!");}
    else {printf("N is not divisible K!");}
}


void zadacha4()
{
    printf("Введите сумму покупки: ");
    double s = get_valid_double();
    if(s<1000&&s>500)
    {
         printf("Ваша скидка составила 3%%\n");
         printf("Итоговая сумма покупки составила %5.2lf\n",0.97*s);
    }
    else if(s>999)
    {
        printf("Ваша скидка составила 5%%\n");
        printf("Итоговая сумма покупки составила %5.2lf\n",0.95*s);
    }
    else if(s<501&&s>0)
    {
         printf("скидка не предоставляется!\n");
    }
    else
    {
         printf("Это что получается, мы вам должны?!\n");
    }
}

void zadacha5()
{
	printf("Введите дату основания города Санкт-Петербург: ");
	int d = (int)get_valid_double();
	if(d==1703)
	{
		printf("ВЕРНО! Дата основания города Санкт-Петербург: %i год\n",d);
	}
	else
	{
		printf("НЕВЕРНО! Дата основания города Санкт-Петербург: 1703 год \n");
	}
}

void zadacha6()
{
	printf("Введите число: ");
	int i = (int)get_valid_double();
	i%2? printf("%i - нечетное",i):printf("%i - четное",i);
}

void zadacha7()
{
	printf("Введите рост (в см): ");
	int h = (int)get_valid_double();
	printf("Введите массу тела: ");
	int w = (int)get_valid_double();
	if(w>h-100)
	{
		printf("Надо похудеть на %i kg",w-(h-100));
	}
	else
	{
		printf("Надо поправиться на %i kg",(h-100)-w);
	}
}



int main()
{
int n = 999;
while(n!=0)
{
	printf("*************************************\n");
	printf("Введите номер задания (0 - выход, 1-7): ");
	n = (int)get_valid_double();
	switch(n)
	{
	case 1: zadacha1();break;
	case 2: zadacha2();break;
	case 3: zadacha3();break;
	case 4: zadacha4();break;
	case 5: zadacha5();break;
	case 6: zadacha6();break;
	case 7: zadacha7();break;
	case 0: printf("Выхожу....\n");break;
	default: printf("Неверный номер!\n");break;
	}
}


}
