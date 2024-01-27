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

void zadacha1()
{
FILE *file;
	if((file=fopen("text.txt","rt"))==NULL)
	{
		printf("Файл text.txt не открылся!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	printf("File is opened\n");
	}
	mark:
	printf("Данные из файла вывести на экран(1-да, 0-нет)?");
	int choice = get_valid_int();
	char chr= '0';
	switch(choice)
	{
		case 1:

		while(fscanf(file,"%c",&chr)==1)
		{
			printf("%c",chr);
		}
		break;
		////////////////////////////////////////
		case 2:
		FILE* file2;
		if((file2 = fopen("text_out.txt","wt"))==NULL)
		{
		printf("Файл ext_out.txt не открылся!\n");
		exit(EXIT_FAILURE);
		}
		while(fscanf(file,"%c",&chr)==1)
		{
		fprintf(file2,"%c",chr);
		}
		fclose(file2);
		printf("Written to text_out.txt\n");
		break;
		////////////////////////////////////////
		default: goto mark;break;
	}
	
	fclose (file);
}

void zadacha2()
{
printf("Вводите данные: ");

FILE *file;
if((file = fopen("text_out.txt","wt"))==NULL)
{
	printf("Файл text_out.txt не открылся!\n");
	exit(EXIT_FAILURE);
}
char ch = '0';

while(ch!=27)
{
ch = getchar();
fprintf(file,"%c",ch);
}
fclose(file);

}


void zadacha3()
{
FILE *file;
	if((file=fopen("text.txt","rt"))==NULL)
	{
		printf("Файл text.txt не открылся!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	printf("File is opened\n");
	}
int max= 0;
while(!feof(file))
{
int tmp = 0;
fscanf(file,"%i",&tmp);
if(tmp>max){max=tmp;}
}
printf("Maximum = %i",max);
}

void zadacha4()
{
FILE *file;
	if((file=fopen("text.txt","rt"))==NULL)
	{
		printf("Файл text.txt не открылся!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	printf("File is opened\n");
	}
int count = 0; 
while(!feof(file))
{
char tmp = '0';
fscanf(file,"%c",&tmp);
if(tmp=='\n'){count++;}
if(feof(file)){break;}
}
printf("Count of raws = %i\n",count);
}
