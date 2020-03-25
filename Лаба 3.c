#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>
     
 
int main()
{
    int** mas, i, j, n;
    printf("The size of your latin square is ");
    scanf_s("%d", &n);

    mas = (int**)calloc(n, sizeof(int*));
      for (i = 0; i < n; i++)
        mas[i] = (int*)calloc(n, sizeof(int));

    srand(time(NULL));
    int num = rand() % n;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            if (num >= n)
            {
                num = 0;
            }
            mas[i][j] = num;
            num++;

        }
            num--;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", mas[i][j]);
            printf("\n");
    }
    return 0;

}
