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
	printf("КЛАССИКА!\n");
	double num = 99;

	while(num!=0)
	{
		printf("Введите Х: ");
		double x = get_valid_double();
		printf("Введите математическое(/,*,-,+) действие: ");
		char action = get_valid_action();
		printf("Введите Y: ");
		double y = get_valid_double();
		
		double result = do_math(x,y,action);
		printf("RESULT: %5.2lf %c%5.2lf = %5.2lf\n",x,action,y,result);
		
		printf("Продолжим(0/1)? ");
		num = get_valid_double();
	}	
	
	return 0;
}