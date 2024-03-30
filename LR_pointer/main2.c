#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double get_valid_double()
{
	double result = 0;
	int err = scanf("%lf",&result);
	while(err!=1||getchar()!=10)
	{
		printf("INPUT ERROR! REAPEAT: ");
		while(getchar()!=10){}
		err = scanf("%lf",&result);
	}
	return result;
}

char get_valid_action()
{
	char result = getchar();
	//printf("КОД СИМВОЛА %с = %d\n",result,result);
	while((result>47||result<42)||result==44||result==46||getchar()!=10)
	{
		printf("INPUT ERROR! REAPEAT: ");
		while(getchar()!=10){}
		result = getchar();
	}

	return result;
}


double do_math(double x,double y, char action)
{
	switch(action)
	{
		case '+':return x+y;break;
		case '-':return x-y;break;
		case '*':return x*y;break;
		case '/': 
			if(y==0)
			{
				printf("На ноль делить нельзя, если мы не говорим о пределе! ");
			}
			else
			{
				return x/y;break;
			}
			
	}
	return INFINITY;
}


int main()
{
	printf("УКАЗАТЕЛИ!\n");
	double num = 99;
	double (*foo1)(void) = get_valid_double;
	double (*foo2)(double x,double y,char action) = do_math;
	char (*foo3)(void) = get_valid_action;
	while(num!=0)
	{
		printf("Введите Х: ");
		double x = foo1();
		printf("Введите математическое(/,*,-,+) действие: ");
		char action = foo3();
		printf("Введите Y: ");
		double y = foo1();
		
		double result = foo2(x,y,action);
		printf("RESULT: %5.2lf %c%5.2lf = %5.2lf\n",x,action,y,result);
		
		printf("Продолжим(0/1)? ");
		num = get_valid_double();
	}	
	
	return 0;
}