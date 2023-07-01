#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

const double eps = 1.0E-16;

// функция обмена переменных
void swap(double* a, double* b)
{
	double c = *a;
	*a = *b;
	*b = c;
}
//перестановка строк матрицы Matrix, а также элементов массива L, если значения v и u не равны i.
int matrix(int m, int n, double** Matrix, int* L)
{
	int i = 0;
	int r, p, v, u;
	if ((n - 1) < m) 
		r = n - 1;
	else 
		r = m;
	double c;

	while (i < r)
	{
		v = i; u = i;
		for (int j = i; j < m; j++)
		{
			for (int k = i; k < n - 1; k++)
			{
				if (abs(Matrix[j][k]) > abs(Matrix[v][u]))
				{
					v = j;
					u = k;
				}
			}
		}

		if (abs(Matrix[v][u]) < eps) 
			r = i;
		else
		{
			if (v != i)
			{
				for (int j = i; j < n; j++)
				{
					swap(Matrix[i][j], Matrix[v][j]);
				}
			}

			c = Matrix[i][i];
			for (int j = i; j < n; j++) 
				Matrix[i][j] /= c;

			for (int k = 0; k < m; k++)
			{
				if (k != i)
				{
					c = Matrix[k][i];
					for (int j = i; j < n; j++) 
						Matrix[k][j] -= c * Matrix[i][j];
				}
			}

			i++;
		}
	}
	return r;
}

int main()
{
	int M, N;

	FILE* f, * Answ;
	f = fopen("input.txt", "rt");
	fscanf(f, "%d", &M);
	fscanf(f, "%d", &N);

	double** Matrix = new double* [M];
	double* Answer = new double[N];
	int* L = new int[N];
	//Строится ступенчатый вид
	for (int i = 0; i < M; i++) 
		Matrix[i] = new double[N + 1];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			fscanf(f, "%lf", &Matrix[i][j]);
		}
	}
	for (int i = 0; i < N; i++) 
		L[i] = i;

	int r;
	r = matrix(M, N + 1, Matrix, L);

	Answ = fopen("answers.txt", "wt");
	fprintf(Answ, "Пошаговый вид матрицы: \n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			fprintf(Answ, "%3.3f   ", Matrix[i][j]);
		}
		fprintf(Answ, "\n");
	}

	int i;
	i = r;
	while ((i < M) && (abs(Matrix[i][N]) < eps)) 
		i++;
	if (i < M) 
		fprintf(Answ, "Система несовместима");
	else 
		if (r == N) //Проверка на совместность и нахождение решения
		{
			fprintf(Answ, "Система определена \n");
			for (int j = 0; j < N; j++)
			{
				Answer[L[j]] = Matrix[j][N];
			}
			for (int j = 0; j < N; j++) 
				fprintf(Answ, "x%d=%3.3f; ", j + 1, Answer[j]);
		}
		else
		{
			printf("Система не определена, введите значение свободной переменной: \n");
			for (int j = r; j < N; j++)
			{
				printf("x%d=", L[j] + 1);
				scanf("%lf", &Answer[L[j]]);
				fprintf(Answ, "x%d - is free; ", L[j] + 1);
			}
			for (int j = 0; j < r; j++)
			{
				Answer[L[j]] = Matrix[j][N];
				for (int k = r; k < N; k++)
				{
					Answer[L[j]] -= Matrix[j][k] * Answer[L[k]];
				}
			}
			for (int j = 0; j < N; j++) 
				fprintf(Answ, "x%d=%lf; ", j + 1, Answer[j]);
		}

	fclose(Answ);
	fclose(f);

	printf("Ответы записываются в файл \"answers.txt\"");
	printf("\n");
}