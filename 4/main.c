#include <stdio.h>
#include <stdlib.h>

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



int main()
{
	FILE *file;
	if(fopen("text.txt","rt")==NULL)
	{
		printf("Файл text.txt не открылся!\n");
		exit(EXIT_FAILURE);
	}
	mark:
	printf("Данные из файла вывести на экран(1-да, 0-нет)?");
	int ch = get_valid_int();
	char chr[128] = {'\0'};
	switch(ch)
	{
		case 1:
		while(!feof(file))
		{
			fscanf(file,"%s",chr);
			printf("%s",chr);
			if(feof(file)){break;}
		}
		break;
		case 2:
		while(!feof(file))
		{
			char chr = fgetc(file);
			printf("%c",chr);
		}
		break;
		default: goto mark;break;
	}
	
	fclose (file);
	
}