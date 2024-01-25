///////////////6-е задание///////////////
void zadanie6_1()
{
	for(int i = 0;i<100;i+=10)
	{
		for(int j = 0;j<10;j++)
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
		}
		printf("\n");
	}
}

void zadanie6_2()
{
	int i = 0;
	while(i<100)
	{
		int j = 0;
		while(j<10)
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}
		printf("\n");
		i+=10;
	}
}

void zadanie6_3()
{
	int i = 0;
	do
	{
		int j = 0;
		do
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}while(j<10);
		printf("\n");
		i+=10;
	}while(i<100);
}

void zadanie6_4()
{
	int i = 0;
	point1:
	{
		int j = 0;
		point2:
		{
			if(((i+j)%10)<i/10+1)
			{
				printf("%2i ",i+j);
			}
			j++;
		}if(j<10){goto point2;}
		printf("\n");
		i+=10;
	}if(i<100){goto point1;}
}

void printer6(int j, int i)
{
	if(j>9){return;}
	else
	{
		if(((i+j)%10)<i/10+1)
		{
			printf("%2i ",i+j);
		}
		return printer6(++j,i);
	}
}

void zadanie6_5(int i)
{
	if(i>99){return ;}
	else 
	{
		int j = 0;
		printer6(j,i);
		printf("\n");
		i+=10;
		return zadanie6_5(i);
	}
}
///////////////5-задание//////////////////////
void zadanie5_1()
{
	for(int i = 0;i<100;i+=10)
	{
		for(int j = 0;j<10;j++)
		{
			
			printf("%2i ",i+j);
		}
		printf("\n");
	}
}

void zadanie5_2()
{
	int i = 0;
	while(i<100)
	{
		int j = 0;
		while(j<10)
		{
			printf("%2i ",i+j);
			j++;
		}
		printf("\n");
		i+=10;
	}
}

void zadanie5_3()
{
	int i = 0;
	do
	{
		int j = 0;
		do
		{
			printf("%2i ",i+j);
			j++;
		}while(j<10);
		printf("\n");
		i+=10;
	}while(i<100);
}

void zadanie5_4()
{
	int i = 0;
	point1:
	{
		int j = 0;
		point2:
		{
			printf("%2i ",i+j);
			j++;
		}if(j<10){goto point2;}
		printf("\n");
		i+=10;
	}if(i<100){goto point1;}
}

void printer5(int j, int i)
{
	if(j>9){return;}
	else
	{
		printf("%2i ",i+j);
		return printer5(++j,i);
	}
}

void zadanie5_5(int i)
{
	if(i>99){return ;}
	else 
	{
		int j = 0;
		printer5(j,i);
		printf("\n");
		i+=10;
		return zadanie5_5(i);
	}
}

///////////////7-е задание///////////////
void zadanie7_1()
{
	for(int i = 0;i<100;i+=10)
	{
		for(int j = 0;j<10;j++)
		{
			if(((i+j)%10)!=8&&((i+j)%10)!=5)
			{
				printf("%2i ",i+j);
			}
		}
		printf("\n");
	}
}

void zadanie7_2()
{
	int i = 0;
	while(i<100)
	{
		int j = 0;
		while(j<10)
		{
			if(((i+j)%10)!=8&&((i+j)%10)!=5)
			{
				printf("%2i ",i+j);
			}
			j++;
		}
		printf("\n");
		i+=10;
	}
}

void zadanie7_3()
{
	int i = 0;
	do
	{
		int j = 0;
		do
		{
			if(((i+j)%10)!=8&&((i+j)%10)!=5)
			{
				printf("%2i ",i+j);
			}
			j++;
		}while(j<10);
		printf("\n");
		i+=10;
	}while(i<100);
}

void zadanie7_4()
{
	int i = 0;
	point1:
	{
		int j = 0;
		point2:
		{
			if(((i+j)%10)!=8&&((i+j)%10)!=5)
			{
				printf("%2i ",i+j);
			}
			j++;
		}if(j<10){goto point2;}
		printf("\n");
		i+=10;
	}if(i<100){goto point1;}
}

void printer7(int j, int i)
{
	if(j>9){return;}
	else
	{
		if(((i+j)%10)!=8&&((i+j)%10)!=5)
		{
			printf("%2i ",i+j);
		}
		return printer7(++j,i);
	}
}

void zadanie7_5(int i)
{
	if(i>99){return ;}
	else 
	{
		int j = 0;
		printer7(j,i);
		printf("\n");
		i+=10;
		return zadanie7_5(i);
	}
}