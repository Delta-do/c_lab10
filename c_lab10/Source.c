#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double f1(double x)
{
	double y;

	if (x <= 3)
		y = pow(x, 2) - 3 * x + 9;
	else
		y = 1. / (pow(x, 3) + 3);

	return y;
}

double f2(double x)
{
	double y;

	y = x * exp(sin(pow(x, 2)));

	return y;
}

int t1()
{
	double x, y1, y2;

	puts("Введите x ");
	scanf("%lf", &x);

	y1 = f1(x);
	y2 = f2(x);
	
	printf("f1(%.3lf) = %.5f \nf2(%.3lf) = %.3lf\n", x, y1, x, y2);
	printf("Произведение значений функций: %.3lf\n", y1 * y2);
	printf("Разность квадратов значений функций : %.3lf\n", pow(y1, 2) - pow(y2, 2));
	printf("Удвоенная сумма значений функций: %.3lf\n", 2 * (y1 + y2));

	return 0;
}

int factorial(int n)
{
	int p = 1;
	for (int i = 2; i <= n; i++)
	{
		p *= i;
	}
	return p;
}

double sin_n(double x, int n)
{
	double y = 0;
	for (int i = 1; i <= n; i++)
	{
		y += pow(-1, i - 1) * (pow(x, 2 * i - 1)) / (factorial(2 * i - 1));
	}
	return y;
}

double sin_eps(double x, double eps)
{
	int k;
	double s, at;
	
	at = x;// нулевой член ряда
	s = at; // суммируем нулевой член
	k = 1; // следуюший член первый
	while (fabs(at) >= eps)
	{
		at *= - x * x / (2 * k) / (2 * k + 1); // пересчитываем следующий член ряда через предыдущий
		s += at; // суммируем
		k++; // переходим к следующему члену
	}
	return s;
}

int t2()
{
	double x;
	double eps;
	puts("Введите значение x");
	scanf("%lf", &x);

	printf("Функция стандартной библиотеки: sin(%.2lf) = %lf\n", x, sin(x));
	printf("Собственная функция как сумма ряда: sin(%.2lf) = %lf\n", x, sin_n(x, 10));

	puts("С какой точностью вычислить? (ввод в формате 0,001) ");
	scanf("%lf", &eps);
	printf("Собственная функция через ряд Маклорена с заданной точностью: sin(%.2lf) = %lf\n", x, sin_eps(x, eps));
	return 0;
}

float area_triangle(float a, float b, float c)
{
	float p;
	p = (a + b + c) / 2.;
	return pow(p * (p - a) * (p - b) * (p - c), 0.5);
}

int print_cycle(int kol, char c, char c_end)
{
	for (int i = 0; i < kol; i++)
	{
		printf("%c", c);
	}
	printf("%c", c_end);

	return 0;
}

void draw_triangle(int a, char c)
{
	a--;

	print_cycle(a / 2 + 3, ' ', c); //первая строка
	puts("");

	for (int i = 0; i <= a / 2; i++) //середина
	{
		print_cycle(a / 2 - i + 1, ' ', c);
		print_cycle(i * 2 + 3, ' ', c);
		puts("");
	}

	for (int i = 0; i < 4 + (a / 2); i++) //последняя строка
	{
		printf("%c", c);
		printf("%c", ' ');
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	//t1();

	//t2();

	//домашнее задание
	int z;

	puts("Что вы хотите сделать с треугольником?");
	puts(" 1 - рассчитать площадь");
	puts(" 2 - вывести определение");
	puts(" 3 - нарисовать");
	printf("> ");
	scanf("%d", &z);

	switch (z)
	{
	case 1:
	{
		float a, b, c;
		printf("Введите стороны треугольника ");
		scanf("%f %f %f", &a, &b, &c);
		printf("%f", area_triangle(a, b, c));
		break;
	}
	case 2:
	{
		puts("Треугольник - это геометрическая фигура, образованная тремя отрезками,");
		puts("которые соединяют три точки, не лежащие на одной прямой.");
		break;
	}
	case 3:
	{
		char c;
		int a;
		fseek(stdin, 0, SEEK_END);
		printf("Введите символ, из которого будет строиться равносторонний треугольник ");
		scanf("%c", &c);
		printf("Введите сторону ");
		scanf("%d", &a);
		draw_triangle(a, c);
		break;
	}
	}

	return 0;
}