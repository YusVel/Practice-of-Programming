#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int get_valid_int()
{
	int result = 0;
	int err = scanf("%d",&result);
	while(err!=1||getchar()!=10)
	{
		printf("INPUT ERROR! REPEAT! ");
		while(getchar()!=10){}
		err = scanf("%d",&result);
	}
	return result;
}

int sum_num(int num)
{
	if(num==0)
	{
		return 0;
	}
	else 
	{
		return num%10+sum_num((num -( num%10))/10);
	}
}


int from_write_to_left(int num)
{
	if(num==0)
	{
		return 0;
	}
	else 
	{
		printf("%d ",num%10);
		return from_write_to_left((num -( num%10))/10);
	}
}



int from_left_to_write(int num)
{
	int temp = 1;
	while(num/temp>9)
	{
		temp*=10;
	}
	//printf("**TEMP = %d**\n",temp);
	if(num<10)
	{
		printf("%d",num);
	}
	else 
	{
		printf("%d ",num/temp);
		return from_left_to_write(num-((int)(num/temp)*temp));
	}
}

int main()
{
	printf("Введите целочисленное значение: ");
	int  num = get_valid_int();
	printf("СУММА ЦИФР = %d\n",sum_num(abs(num)));
	printf("Последовательность цифр справа налево: ");
	from_write_to_left(abs(num));
	printf("\nПоследовательность цифр слева направо: ");
	from_left_to_write(abs(num));
	return 0;
}