#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define DISCIPLINES 5


int get_valid_int()
{
	int result = 0;
	int err = scanf("%i",&result);
	while(err!=1||getchar()!=10)
	{
		printf("INPUT ERROR! REPEAT: ");
		while(getchar()!=10){}
		err = scanf("%i",&result);
	}
	fflush(stdin);
	return result;
}

struct STUDENT
{
	char name[64];
	int group;
	int academic_performance[DISCIPLINES];
};

void input_manually(struct STUDENT *arr)
{
	for(int i = 0; i<SIZE; i++)
	{
		printf("Input NAME(%d): ",i+1);
		gets(arr[i].name);
		printf("Input GROUP: ");
		arr[i].group = get_valid_int();
		printf("Input ACADEMIC PERFORMANCE: \n");
		for(int j = 0; j<DISCIPLINES;j++)
		{
			printf("\tDISCIPLINCE №%d: ",j+1);
			arr[i].academic_performance[j] = get_valid_int();
		}
	}
}


double avarage_mark( int *academic_performance)
{
	double result = 0;
	for(int i = 0;i<DISCIPLINES;i++)
	{
		result+=academic_performance[i];
	}
	return (double)(result/DISCIPLINES);
}

int have_2(int *academic_performance)
{
	for(int i = 0;i<DISCIPLINES;i++)
	{
		if(academic_performance[i]==2)
		{
			return 1;
		}
	}
	return 0;
}

int have_4_5(int *academic_performance)
{
	for(int i = 0;i<DISCIPLINES;i++)
	{
		if(academic_performance[i]<4)
		{
			return 0;
		}
	}
	return 1;
}


void show(struct STUDENT *arr)
{
	printf("\n1 - Show students with only 4 and 5 marks\n");
	printf("2 - Show students with ""2"" mark\n");
	printf("3 - Show students with avarage acad.perf. more than 4.0\n");
	printf("4 - Show ALL students with avarage acad.perf. ---> ");
	
	int ch = get_valid_int();
	int count = 0;
	switch(ch)
	{
		case 1:
				
				for(int i = 0; i<SIZE; i++)
				{
					if(have_4_5(arr[i].academic_performance))
					{
						printf("*%2d* NAME: %15s\t\t(GROUP %2d)\tAVARAGE MARK %2.1lf \n",i+1,arr[i].name,arr[i].group,avarage_mark(arr[i].academic_performance));
						count++;
					}
				}
				if(count==0){printf("NOBODY!!!");}
				break;
		case 2:
				
				for(int i = 0; i<SIZE; i++)
				{
					if(have_2(arr[i].academic_performance))
					{
						printf("*%2d* NAME: %15s\t\t(GROUP %2d)\tAVARAGE MARK %2.1lf \n",i+1,arr[i].name,arr[i].group,avarage_mark(arr[i].academic_performance));
						count++;
					}
				}
				if(count==0){printf("NOBODY!!!");}
				break;
		case 3:
				for(int i = 0; i<SIZE; i++)
				{
					if(avarage_mark(arr[i].academic_performance)>4.0)
					{
						printf("*%2d* NAME: %15s\t\t(GROUP %2d)\tAVARAGE MARK %2.1lf \n",i+1,arr[i].name,arr[i].group,avarage_mark(arr[i].academic_performance));
						count++;
					}
				}
				if(count==0){printf("NOBODY!!!");}
				break;
		case 4:
				for(int i = 0; i<SIZE; i++)
				{
					printf("*%2d* NAME: %15s\t\t(GROUP %2d)\tAVARAGE MARK %2.1lf \n",i+1,arr[i].name,arr[i].group,avarage_mark(arr[i].academic_performance));
				}
				break;
		default:printf("WRONG CHOICE!"); break;
	}

}

int main()
{
	FILE *file;
	struct STUDENT *arr = (struct STUDENT*)malloc(SIZE*sizeof(struct STUDENT));
	int ch = 0;
	printf("Load data from file(1) or input manually(2)? ");
	ch = get_valid_int();
	switch(ch)
	{
		case 1:
				if((file=fopen("data.bin","r+b"))==NULL)
				{
					printf("FILE OPENNING ERROR!");
					return 1;
				}
				int err = fread(arr,sizeof(struct STUDENT),SIZE,file);
				printf("Количество прочитанных данных = %d\n", err); break;

				break;
		case 2:
				if((file=fopen("data.bin","w+b"))==NULL)
				{
					printf("FILE OPENNING ERROR!");
					return 1;
				}
				input_manually(arr);
				fwrite(arr,sizeof(struct STUDENT),SIZE,file);
				break;
		default:printf("WRONG CHOICE!"); break;
	}
	
	show(arr);
	free(arr);
	fclose(file);
	return 0;
}