#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

void memorymove()
{
	char arr[] ="Hello!";
	printf("Длина строки: %d\n",strlen(arr));
	
	memmove(arr,arr+1,strlen(arr)-1);

	for(int i = 0;i<SIZE;i++)
	{
		printf("%c",arr[i]);
	}
}


//Поиск и удаление символов в строке 
int main()
{ 
	FILE *file;
	
	if ((file=fopen( "Data.txt", "r"))==NULL)
	{
		printf("The openning is failed");
		return 0;
	}
	
	double size = 0;
	char t = 'r';
	while (fscanf(file, "%c", &t)!=EOF)
	{
		size++;
	}
	printf("VOLUM = %5.0lf baits\n", size);
	fseek(file, 0, SEEK_SET);

	char* str1 =(char*)malloc(size);

	int i = 0;
	while (fscanf(file, "%c", &t) != EOF)
	{
		str1[i++] = t;
	}

	printf("%s\n\n", str1);
		
	char str2[] = "qwerty";
	printf("%s\n",str2);
	printf("Length str: %d\n",strlen(str1));
	
	for(int i = strcspn(str1, str2);i<strlen(str1)-1;)
	{
		memmove(str1+i,str1+i+1,(strlen(str1)-i));
		i = strcspn(str1, str2); 
	}
	printf("%s\n", str1);
	printf("VOLUM = %5.0d baits\n", strlen(str1));

	//free(str1);
	fclose(file);
	return 0;
}