#include <stdio.h>
#include <stdlib.h>

#include "foo.c"



int main()
{	
char ch = '1';
while(ch!='0')
{
printf("##########Введите номер задания (5,6 или 7, 0 - выход): ");
scanf("%c",&ch);
printf("Введен символ (%c)\n",ch);
if(ch=='5')
{
	printf("***Цикл For***\n");
	zadanie5_1();
	printf("***Цикл While***\n");
	zadanie5_2();
	printf("***Цикл Do-While***\n");
	zadanie5_3();
	printf("***Использование goto***\n");
	zadanie5_4();
	printf("***Рекурсия!!!***\n");
	zadanie5_5(0);
}
else if(ch=='6')
{
	printf("***Цикл For***\n");
	zadanie6_1();
	printf("***Цикл While***\n");
	zadanie6_2();
	printf("***Цикл Do-While***\n");
	zadanie6_3();
	printf("***Использование goto***\n");
	zadanie6_4();
	printf("***Рекурсия!!!***\n");
	zadanie6_5(0);
}
else if(ch=='7')
{
	printf("***Цикл For***\n");
	zadanie7_1();
	printf("***Цикл While***\n");
	zadanie7_2();
	printf("***Цикл Do-While***\n");
	zadanie7_3();
	printf("***Использование goto***\n");
	zadanie7_4();
	printf("***Рекурсия!!!***\n");
	zadanie7_5(0);
}
else
{
	printf("Error!\n");
}
while(getchar()!='\n');
}


	
}