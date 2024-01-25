#include <stdio.h>
#include <math.h>


int get_valid_int()
{

int num = 0;
int good_read =scanf("%d",&num);
while(good_read!=1||getchar()!=10)
{
printf("INPUT ERROR! ENTER INT AGAIN!!! ");
	
	while (getchar()!=10)
	{	
		good_read = 0;
	}
	good_read = scanf("%d",&num);
}
return num;
}

int is_simple(int n)
{
	int devisors = 0;
	for(int i = 1;i<=n;i++)
	{
		if(n%i==0){devisors++;}
		if (devisors>2){return 0;}
	}
	if(devisors==2){return 1;}
	else{return 0;}
}

int NOD( int m, int n)
{
	if(m>n)
	{
		if(m%n==0){return n;}
		else {return NOD(n,(m%n));}
	}
	else
	{
		if(n%m==0){return m;}
		else {return NOD(m,(n%m));}
	}
}

int is_square( double n)
{
	double temp = sqrt(n);
	printf("Корень N = %5.5lf\n",temp);
	int i = (int)temp;
	if(i*10000==(int)(temp*10000)){return 1;}
	else {return 0;}
}


int recsum(int i)
{
	if(i==0){return 0;}
	else if(i<0){return -1;}
	else
	{
		return i +recsum(i-1);
	}
}

double sum(int i)
{
	return ((double)i/2)*((double)(i+1));
}

int main()
{
	/*
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("Простое ли число N? Ответ: %i\n",is_simple(n));
	*/
	/*
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("Enter M (int): ");
	int m = get_valid_int();
	printf("NOD(%i, %i) = %i\n",n,m,NOD(n,m));
	*/
	/*
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("Является ди число квадратом другого целого числа ? Ответ: %i\n",is_square(n));
	*/
	
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("Сумма натуральных чисел от 0 до %i: %16.0lf\n",n,sum(n));
	printf("Сумма(рекурсивно) натуральных чисел от 0 до %i: %i\n",n,recsum(n));
	return 0;
}	