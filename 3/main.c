#include <stdio.h>
#include <stdlib.h>
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

double dolay(const char *str, const char ch)
{
	int count = 0;
	int str_len = 0;
	for(int i= 0; str[i]!='\0';i++)
	{
		if(str[i]=='\0'){break;}
		if(str[i]==ch){count++;}
		str_len++;
	}
	printf("Число симв = %i, размер строки = %i\n",count,str_len);
	return (double)count/(double)str_len;
}



int main()
{
	while(1)
	{
		printf("****************************************\n");
		printf("Ввелите номер задания (1-5, 0 - выход): ");
		int choice = get_valid_int();
		switch(choice)
		{
		case 1:
		printf("Enter N (int): ");
		int n = get_valid_int();
		printf("Простое ли число N? Ответ: %i\n",is_simple(n));
		break;
		case 2:
		printf("Enter N (int): ");
		int i = get_valid_int();
		printf("Enter M (int): ");
		int j = get_valid_int();
		printf("NOD(%i, %i) = %i\n",i,j,NOD(i,j));
		break;
		case 3:
		printf("Enter N (int): ");
		int k = get_valid_int();
		printf("Является ди число квадратом другого целого числа ? Ответ: %i\n",is_square(k));
		break;
		case 4:
		printf("Enter N (int): ");
		int t = get_valid_int();
		printf("Сумма натуральных чисел от 0 до %i: %2.0lf\n",t,sum(t));
		printf("Сумма(рекурсивно) натуральных чисел от 0 до %i: %i\n",t,recsum(t));
		break;
		case 5:
		printf("Enter string: ");
		char str[256] = {'\0'};
		scanf("%s",str);
		printf("Enter char: ");
		char ch = '0';
		getchar();
		scanf("%c",&ch);
		printf("Доля символа '%c' в строке  %s  равна: %2.2lf\n",ch,str,dolay(str,ch));
		case 0: exit(1);
		default: break;
		}
	}
	return 0;
}	