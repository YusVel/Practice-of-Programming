#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int get_valid_int()
{
	int num;
	int goodread = scanf("%i",&num);
	while(goodread!=1||getchar()!=10)
	{
		printf("INTUT ERROR, ENTER CORRECT INT: ");
		
		while(getchar()!=10){}
		goodread = scanf("%i",&num);
	}
	return num;
}

double get_valid_double()
{

double num = 0;
int goodread = scanf("%lf",&num);
while(goodread!=1||getchar()!=10)
{
		printf("INTUT ERROR, ENTER CORRECT INT: ");
		
		while(getchar()!=10){}
		goodread = scanf("%lf",&num);
}

return num;
}

void random_arr(double arr[])
{
	for(int i = 0;i<SIZE;i++)
	{
		*(arr+i) = ((double)(rand()%2000))/100-10;
	}
}

void show_arr(double arr[])
{
	for(int i = 0;i<SIZE;i++)
	{
		printf("%3.2lf ",*(arr+i));
	}
	printf("\n");
}

void get_arr_from_file(double arr[])
{
FILE *file;
	if((file=fopen("data.txt","rt"))==NULL)
	{
		printf("Невозможно прочитать файл!\n"); exit(EXIT_FAILURE);
	}
int i = 0;
double tmp = 0;

	while(fscanf(file,"%lf",&tmp)==1)
	{
		*(arr+i)=tmp;
		i++;
	}
	if(i!=SIZE){printf("В файле существует ошибка вещественного числа!\n");fclose(file); exit(EXIT_FAILURE);}
	
fclose(file);
}

double multiply_arr(double arr[])
{
double result = 1;
	for (int i = 0;i<SIZE;i++)
	{
	result*=*(arr+i);
	}
	return result;
}

void input_arr_from_console(double arr[])
{
printf("Введите %i элемента(ов) массива: \n",SIZE);
for(int i = 0;i<SIZE;i++)
{
	double tmp;
	printf("%i - элемент = ",i);
	tmp = get_valid_double();
	*(arr+i) = tmp;
}
}

int get_min_index_from_arr(double arr[])
{
	double min = *arr;
	int index = 0;
	for(int i = 1;i<SIZE;i++)
	{
	if(min>*(arr+i)){min=*(arr+i); index = i;}
	}
	return index;
}

int get_max_index_from_arr(double arr[])
{
	double max = *arr;
	int index = 0;
	for(int i = 1;i<SIZE;i++)
	{
	if(max<*(arr+i)){max=*(arr+i); index = i;}
	}
	return index;
}


double multiply_betwin_min_max_of_arr(double arr[])
{
	int min = get_min_index_from_arr(arr);
	int max = get_max_index_from_arr(arr);
	double result = 1;
	if(min<max)
	{
		for(int i = min+1; i<max;i++)
		{
			result*=*(arr+i);
		}
	}
	else
	{
		for(int i = max+1; i<min;i++)
		{
			result*=*(arr+i);
		}
	
	}
	return result;
}

void export_arr(double arr[])
{

	printf("Массив и результат вычисления выводим на экран(1) или в фаил(any number): ");
	int choice = get_valid_int();
	if(choice ==1)
	{	
		show_arr(arr);
		printf("Произведение элементов массива: %lf\n",multiply_arr(arr));
		printf("Произвед. эл. массива между мин и макс эл. : %lf\n",multiply_betwin_min_max_of_arr(arr));
	}
	else
	{
		FILE *file;
		if((file=fopen("data_out.txt","wt"))==NULL)
		{
			printf("Невозможно записать в файл!\n"); exit(EXIT_FAILURE);
		}
		for(int i = 0;i<SIZE;i++)
		{
			fprintf(file,"%5.2lf ",*(arr+i));
		}
		fprintf(file,"\n");
		fprintf(file,"Произведение элементов массива: %lf\n",multiply_arr(arr));
		fprintf(file,"Произвед. эл. массива между мин и макс эл. : %lf\n",multiply_betwin_min_max_of_arr(arr));
		fclose(file);
	}
	
}



















