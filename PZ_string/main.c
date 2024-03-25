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
	char *str1 = "Вышел ёжик их тумана!";
	char *str2 = "уеыаоэяию\n";
	printf("%s\n",str1);
	printf("Длина строки: %d\n",strlen(str1));
	memmove(str1+3,str1+6,1);
	printf("%s\n",str1);
	
	
	/*
	for(int i = 0;i<strlen(str1);i++)
	{
		memmove(str1+i,str1+i+1,(strlen(str1)-i-2));
		printf("%s\n",str1);
	}
	printf("%s\n",str1);
*/
	//memorymove();
	return 0;
}