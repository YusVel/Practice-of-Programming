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



int main()
{ 
	FILE *file = NULL;
	
	if (fopen_s(&file, "Data.txt", "r")!=0)
	{
		printf("The openning is failed");
	}
	
	double size = 0;
	char t = 'r';
	while (fscanf_s(file, "%c", &t)!=EOF)
	{
		size++;
	}
	printf("VOLUM = %5.0lf baits\n", size);
	fseek(file, NULL, SEEK_SET);

	char* str1 =(char*)malloc(size);

	int i = 0;
	while (fscanf_s(file, "%c", &t) != EOF)
	{
		str1[i++] = t;
	}

	printf("%s\n\n", str1);
	printf("%d", strlen(str1));
	
	char str2[] = " ";
	printf("%s\n",str1);
	printf("Length str: %d\n",strlen(str1));
	
	for(int i = strcspn(str1, str2);i<strlen(str1)-1;)
	{
		memmove(str1+i,str1+i+1,(strlen(str1)-i));
		i = strcspn(str1, str2); 

	}
	printf("%s\n", str1);
	printf("%d", strlen(str1));

	//free(str1);
	fclose(file);
	return 0;
}