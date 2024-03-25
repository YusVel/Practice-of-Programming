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
	char str1[] = "All that I have is all that you've given me Did you never worry that I'd come to depend on you...!";
	char str2[] = "Aaeyuioj\n";
	printf("%s\n",str1);
	printf("Длина строки: %d\n",strlen(str1));
	
	for(int i = 0;i<strlen(str1);i++)
	{
		memmove(str1+i,str1+(i++),(strlen(str1)-i));
	}
	printf("%s\n",str1);

	//memorymove();
	return 0;
}