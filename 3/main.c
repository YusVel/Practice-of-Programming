#include <stdio.h>


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


int main()
{
	/*
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("%i",is_simple(n));
	*/
	/*
	printf("Enter N (int): ");
	int n = get_valid_int();
	printf("Enter M (int): ");
	int m = get_valid_int();
	printf("NOD(%i, %i) = %i",n,m,NOD(n,m));
	*/
	return 0;
}	