#include "foo.c"


int main()
{
srand(time(NULL));

double arr[SIZE] = {0};

beg:///////метка///////
printf("Задача 11. Группа ПИБ 32з - ВЕЛИМЕТОВ Ю.К.\n");

printf("1 - С КОНСОЛИ\n");
printf("2 - ИЗ ФАЙЛА data.txt\n");
printf("3 - РАНДОМНО ГЕНЕРИРОВАТЬ\n");
mark:///////метка///////
printf("Выберите способ ввода данных: ");

int choice = get_valid_int();

switch(choice)
{
case 1:
input_arr_from_console(arr);
export_arr(arr);
break;
/////////////////////////////////
case 2:
get_arr_from_file(arr);
export_arr(arr);
break;
//////////////////////////////
case 3: 
random_arr(arr);
export_arr(arr);
break;
default:  printf("INPUT ERROR!\n");goto mark;break;
}

printf("Продолжим (1-да/любой другое число-нет)? ");
choice = get_valid_int();
if(choice==1){goto beg;}

return 0;
}


