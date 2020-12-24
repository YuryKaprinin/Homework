
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

void randArray(int A[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		A[i] = rand() % (b - a) + a;
}
void print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int Slianie(int* B, int mid, int l, int r, int* nc, int* nsw)
{
	int i = l;
	int j = mid + 1;
	int s = 0;
	int g = r - l + 1;
	int* k;
	k = (int*)malloc(sizeof(int) * g);
	while (i <= mid && j <= r)
	{
		if (B[i] < B[j])
		{
			k[s] = B[i];
			s++;
			i++;
			(*nsw)++;
		}
		else
		{
			k[s] = B[j];
			s++;
			j++;
			(*nsw)++;
		}
	}
	(*nc)++;
	while (i <= mid)
	{
		k[s] = B[i];
		s++;
		i++;
		(*nsw)++;
	}
	while (j <= r)
	{
		k[s] = B[j];
		s++;
		j++;
		(*nsw)++;
	}
	for (s = 0; s < g; s++)
	{
		B[l + s] = k[s];
	}
	free(k);
}
int Slianie1(int* B, int l, int r, int* nc, int* nsw)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		Slianie1(B, l, mid, &(*nc), &(*nsw));
		Slianie1(B, mid + 1, r, &(*nc), &(*nsw));
		Slianie(B, mid, l, r, &(*nc), &(*nsw));
	}
	(*nc)++;
}
int BubbleSort(int* B, int n, int* nc, int* nsw)
{
	int i, tmp, j;
	int max = n - 1;
	int min = 0;
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		(*nc)++;
		for (j = min; j < max; j++)
		{
			(*nc)++;
			if (B[j] > B[j + 1])
			{
				tmp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = tmp;
				(*nsw)++;
			}
		}
		tmp = 0;
		for (j = max; j > min; j--)
		{
			(*nc)++;
			if (B[j] < B[j - 1])
			{
				tmp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = tmp;
				(*nsw)++;
			}
		}
	}
}
void menu()
{
	printf("\nMENU:\n");
	printf("1. Create array\n");
	printf("2. Print array\n");
	printf("3. BubbleSort\n");
	printf("4. Slianie\n");
	printf("0. Exit\n");
}
void main()
{ 
	int A[100];
	int n = 10;
	int t = 10;
	srand(100);
	
	while (t != 0)
	{

		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			randArray(A, n, -5, 5);
			break;
		}
		case 2:
		{
			print(A, n);
			break;
		}
		case 3:
		{
				int sr = 0, pr = 0;
				BubbleSort(A, n, &sr, &pr);
				print(A, n);

				
			break;
		}
		
		case 4:
		{
			
				int sr = 0, pr = 0;
				Slianie1(A, 0, n - 1, &sr, &pr);
				print(A, n);
				
			}
			
		
		

}
}

}