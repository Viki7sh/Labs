// Лаба 2 (2.2.6).c : Этот файл содержит функцию "main".
/*#include <iostream>
#include<stdio.h>
#include<math.h>

void execute(int n, int t) {
	int fact, f, i = 1;
	double x, y, s;
	int k = 0;
	while (k < t) {
		printf ("\nx=");
		scanf_s("%ld", &x);
		y = sin(x);
		printf("y= %lf", y);
		for (f = 1; f <= n; f++)
		{
			{
				fact = 2 * n - 1;
				fact *= n;
				for (i = 1; i <= n; i++)
				{
					s = 0;
					s += (pow(-1, (n - 1)) * pow(x, (2 * n) - 1)) / fact;
				}
			}
		}
		printf ("\ns= %lf", s);
		k++;
	}
}
int main() {
	int n, t;
	printf ("Amount of row numbers =");
	scanf_s("%d", &n);
	printf ("Amount of numbers =");
	scanf_s("%d", &t);;
	void execute(n, t);
	return 0;
}*/
#include <stdio.h>
#include <math.h>
#include <locale.h>


int dec(double x, double e);
long long fact(long long n);

int main(int argc, const char* argv[]) {
	double x, e;
	int n;
	setlocale(LC_ALL, "Russian");

	printf("Введите допустимую погрешность e: ");
	scanf_s("%lf", &e);
	printf("Введите x: ");
	scanf_s("%lf", &x);
	n = dec(x, e);
	printf("%s%d%s", "При n = ", n, " будет достигнута желаемая точность\n");

	return 0;
}

int dec(double x, double e) {
	double sum = x, n = 1;

	while (fabs(sin(x) - sum) >= e) {
		sum += pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
		n++;
	}
	return n;
}

long long fact(long long n) {
	if (n <= 1) {
		return 1;
	}
	else return n * fact(n - 1);
}
