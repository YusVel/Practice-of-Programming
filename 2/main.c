#include <stdio.h>
#include <stdlib.h>

void zadanie6_1()
{
	for(int i = 0;i<100;i+=10)
	{
		for(int j = 0;j<10;j++)
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
		}
		printf("\n");
	}
}

void zadanie6_2()
{
	int i = 0;
	while(i<100)
	{
		int j = 0;
		while(j<10)
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}
		printf("\n");
		i+=10;
	}
}

void zadanie6_3()
{
	int i = 0;
	do
	{
		int j = 0;
		do
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}while(j<10);
		printf("\n");
		i+=10;
	}while(i<100);
}

void zadanie6_4()
{
	int i = 0;
	point1:
	{
		int j = 0;
		point2:
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}if(j<10){goto point2;}
		printf("\n");
		i+=10;
	}if(i<100){goto point1;}
}

void printer(int j, int i)
{
	if(j>9){return;}
	else
	{
		if(((i+j)%10)<i/10+1)
		{
			printf("%2i ",i+j);
		}
		return printer(++j,i);
	}
}

void zadanie6_5(int i)
{
	if(i>99){return ;}
	else 
	{
		int j = 0;
		printer(j,i);
		printf("\n");
		i+=10;
		return zadanie6_5(i);
	}
}


int main()
{	
	printf("***Цикл For***\n");
	zadanie6_1();
	printf("***Цикл While***\n");
	zadanie6_2();
	printf("***Цикл Do-While***\n");
	zadanie6_3();
	printf("***Использование goto***\n");
	zadanie6_4();
	printf("***Рекурсия!!!***\n");
	zadanie6_5(0);
}