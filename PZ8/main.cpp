#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10
#define OK 2 //Делитель
#define RD_const 500

void show_2arr (int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
				printf("%5d",arr[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
}

void random_arr(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = rand() % RD_const - RD_const/2;
		}
	}
}

void z1(int arr[SIZE][SIZE])
{
	int min = 9999999;
	for (int i = 0; i < SIZE; i++)
	{
		int temp = 0;
		for (int j = 0; j < SIZE; j++)
		{
			temp += arr[i][j];
		}
		if (min > temp) { min = temp; }
	}
	printf("1) Minimum sum element = %d\n",min);
}

int z2(int arr[SIZE][SIZE])
{
	int avarage = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			avarage += arr[i][j];
		}
	}
	avarage /= (SIZE * SIZE);
	printf("2) AVARAGE element = %d.", avarage);

	int result = 0;
	int x = 0, y =0;
	int dispersia = 1000;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == avarage)
			{
				printf("%d(%d, %d)\n", arr[i][j],i,j);
				return 0;
			}
			else
			{
				if (dispersia > abs(arr[i][j] - avarage))
				{
					dispersia = abs(arr[i][j] - avarage);
					result = arr[i][j];
					x = i;
					y = j;
				}
			}
		}
	}
	printf("The nearest element = %d(%d, %d)\n", result, x, y);
	return 0;
}



int check_el_in_arr(int* arr, int last_el, int num)
{
	for (int i = 0; i < last_el; i++)
	{
		if (num == arr[i])
		{
			return 1;
		}
	}
	return 0;
}


void z3(int arr[SIZE][SIZE])
{
	printf("3) Repeated elements: \n");
	int* massiv = &arr[0][0];
	int temp_arr[SIZE * SIZE]{0};
	int temp_index = 0;
	for (int i = 0; i < SIZE * SIZE; i++)
	{

		if (check_el_in_arr(temp_arr, temp_index, massiv[i]))
		{
			continue;
		}
		int el = massiv[i];
		int count = 0;
		for (int j = i; j < SIZE * SIZE; j++)
		{
			if (el == massiv[j])
			{ 
				count++; 
			}
		}
		if (count > 1) { printf("\tThe element  %d repeats %d times\n", el, count); temp_arr[temp_index] = el; temp_index++; }
	}
}

void z4(int arr[SIZE][SIZE])
{
	int row = 0;
	int max = 0;
	for (int i = 0; i < SIZE; i++)
	{
		int count_OK = 0;
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] % OK == 0)
			{
				count_OK++;
			}
		}
		if (max < count_OK) { max = count_OK; row = i; }
	}
	printf("4) The row with maximun elements(%d) miltiply %d is %d: ",max,OK,row);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[row][i]);
	}
	printf("\n");
}

int z5(int arr[SIZE][SIZE])
{

	for (int i = 0; i < SIZE; i++)
	{
		int positiv = 0;
		int negativ = 0;
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[j][i] < 0) { negativ++; }
			else { positiv++; }
		}
		if (positiv == negativ)
		{
			printf("5) The quantity of negativ and positive elements are equal in the column %d. \n",i);
			return 1;
		}
	}
	printf("5) There ara no columns with equal quantity of negativ and positive elements.\n");
	return 0;
}


int z6(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i+1; j < SIZE; j++)
		{
			if (arr[i][j] != arr[j][i])
			{
				printf("6) There is NO symmetry regatding main diagonal.\n");
				return 0;
			}
		}

	}
	printf("6) There is symmetry regatding main diagonal.\n");
	return 1;
}

void z7(int arr[SIZE][SIZE])
{
	int sum = 0;
	for (int i = 0; i < SIZE/2; i++)
	{
		for (int j = i + 1; j < SIZE-i; j++)
		{
			sum += arr[i][j];
		}

	}
	printf("7) The Sum of the upper quarter = %d.\n",sum);
}

void z8(int arr[SIZE][SIZE])
{


	for (int i = 0; i < SIZE / 2; i++)
	{
		int x_n = 0;
		int y_n = 0;
		int bolean = 0;

		int x_0 = 0;
		int y_0 = 0;
		for (int j = i + 1; j < SIZE - i; j++)
		{
			if (arr[j][i] < 0 && bolean == 0)
			{
				x_n = j;
				y_n = i;
				bolean = 1;
			}
			if (arr[j][i] == 0)
			{
				x_0 = j;
				y_0 = i;
			}
		}
		int temp = arr[x_n][y_n];
		arr[x_n][y_n] = arr[x_0][y_0];
		arr[x_0][y_0] = temp;
	}
	printf("8) Your modify array:\n");
	show_2arr(arr);
}

void z9(int arr[SIZE][SIZE], int *n_arr)
{
	printf("9) NEW array: ");
	for (int i = 0; i < SIZE ; i++)
	{
		n_arr[i] = arr[i][SIZE - i - 1];
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", n_arr[i]);
	}
	printf("\n");
}

void z10(int arr[SIZE][SIZE])
{
	int sum2col = 0;
	int count = 0;
	int min = 9999999;
	int col = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			sum2col +=arr[j][i];
		}
		count++;
		if (count == 2)
		{
			if (min > sum2col) { min = sum2col; col = i; }
			sum2col = 0;
			i--;
			count = 0;
		}
	}
	printf("10) Minimun sum of elements of the nearest two cols (%d and %d):\n",col-1,col);
}

int z11(int arr[SIZE][SIZE], int num)
{
	if(num>9||num<0)
	{
		printf("11) NUM have to randge from 0 to 9!!! Retern error(0).\n");
		return 0;
	}
	for (int i = 0; i < SIZE; i++)
	{
		int count = 0;
		for (int j = 0; j < SIZE; j++)
		{
			if((abs(arr[i][j])%10)==num)
			{
				count++;
			}				
		}
		printf("11) Quantity of elements in the row(%d) with last figure(%d) = %d. \n",i,num,count);
	}
	return 1;
}

int z12(int arr[SIZE][SIZE])
{
	int d1 = 0;
	int d2 = 0;
	int sum_row = 0;
	
	for(int i = 0; i<SIZE;i++)
	{
		sum_row+=arr[0][i];
		d1+=arr[i][i];
		d2+=arr[SIZE-i-1][SIZE-i-1];
	}

	if(sum_row!=d1||sum_row!=d2)
	{
		printf("12) The matrix is NOT magic squer!\n");
		return 0;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		int sum_r = 0;
		int sum_c = 0;
		for (int j = 0; j < SIZE; j++)
		{
				sum_r +=arr[i][j];
				sum_c+=arr[j][i];
		}
		if(sum_row!=sum_r||sum_row!=sum_c)
		{
			printf("12) The matrix is NOT magic squer!\n");
			return 0;
		}

	}
	printf("The matrix is magic squer!\n");
	return 1;
}

int main()
{
	srand(time(NULL));
	int n_arr[SIZE] = { 0 };

	int arr[SIZE][SIZE] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	random_arr(arr);
	printf("Your source array:\n");
	show_2arr(arr);
	z1(arr);
	z2(arr);
	z3(arr);
	z4(arr);
	z5(arr);
	z6(arr);
	z7(arr);
	z8(arr);
	z9(arr,n_arr);
	z10(arr);
	z11(arr,9);
	z12(arr);
	return 0;
}