#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "");
    int S = 0;
    int N = 5;
    srand(time(NULL));

    int arr[5][5];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 51 - 25;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    int t1[100] = { 0 }, t2[100] = { 0 };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            t1[i] += arr[i + j][j];
            t2[i] += arr[j][i + j];
        }
    }
    printf("\n");
    printf("Сумма диагоналей под главной диагональю: ");
    for (int i = 1; i < N; ++i)
    {
        printf("%d ", t1[i]);
    }
    printf("\n");
    printf("Сумма диагоналей над главной диагональю: ");
    for (int i = 1; i < N; ++i)
    {
        printf("%d ", t2[i]);
    }

    return 0;
}