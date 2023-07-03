#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

const double eps = 0.00001;
double dots[6];
bool doublecheck = true;

bool ans(int N, int M, double** A) {
	int* check;
	check = new int[N];
	for (int i = 0; i < M; i++) {
		for (int k = 0; k <= N; k++) {
			if (A[i][k] == 1) {
				check[k] = 1;
			}
			else check[k] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		if (check[i] != check[i + 1]) return true;
	}
	return false;
}

void swap(double* a, double* b)
{
	double c = *a;
	*a = *b;
	*b = c;
}

int StepMatrix(int m, int n, double** Matrix, int* L)
{
	int i = 0;
	int r, p, v, u;
	if ((n - 1) < m) r = n - 1;
	else r = m;
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

		if (abs(Matrix[v][u]) < eps) r = i;
		else
		{

			/* смена столбцов */
			if (v != i)
			{
				for (int j = i; j < n; j++)
				{
					swap(Matrix[i][j], Matrix[v][j]);
				}
			}

			/* к 1-ой */
			c = Matrix[i][i];
			for (int j = i; j < n; j++) Matrix[i][j] /= c;

			/* вычитание */
			for (int k = 0; k < m; k++)
			{
				if (k != i)
				{
					c = Matrix[k][i];
					for (int j = i; j < n; j++) Matrix[k][j] -= c * Matrix[i][j];
				}
			}

			i++;
		}
	}
	return r;
}

void lines(int m, double** Matrix) {
	int j = 0;
	double k, b;
	for (int i = 0; i < m; i++) {
		k = (Matrix[i][j] / Matrix[i][j + 1]) * -1;
		b = Matrix[i][j + 2] / Matrix[i][j + 1];
		cout << "k" << i + 1 << " = " << k << endl << "b" << i + 1 << " = " << b << endl;
	}
}

bool DotsTri(int m, int n, double ** Matrix, int* L, int k, FILE *f) {
	bool check;
	for (int i = 0; i < n; i++) L[i] = i;
	double buff[10];
	int v = 0, c = k;
	double** TempMatrix = new double* [m-1];
	for (int i = 0; i < m; i++) TempMatrix[i] = new double[n+1];
	if (k == 2) {
		while (v < 6) {
			for (int j = 0; j <= n; j++) {
				buff[v] = Matrix[c][j];
				v++;
			}
			c = 0;
		}
	}
	else {
		while (v < 6 && c < 3) {
			for (int j = 0; j <= n; j++) {
				buff[v] = Matrix[c][j];
				v++;
			}
			c++;
		}
		DotsTri(m, n, Matrix, L, k + 1, f);
	}
	int r = 0, j = 0, h = 3;
	while (j < 3 && h < 6 && r < 2) {
		for (int i = 0; i <= n; i++) {
			TempMatrix[r][i] = buff[j];
			j++;
		}
		r++;
		for (int i = 0; i <= n; i++) {
			TempMatrix[r][i] = buff[h];
			h++;
		}
	}
	StepMatrix(m-1, n + 1, TempMatrix, L);
	check = ans(n, m-1, TempMatrix);
	if (check != true) {
		doublecheck = false;
		return false;
	}
	if (check == true && doublecheck == true) {
		if (k == 0) {
			fprintf(f, "%3.3lf %3.3lf", TempMatrix[0][2], TempMatrix[1][2]);
			fprintf(f, "\n");
		}
		if (k == 1) {
			fprintf(f, "%3.3lf %3.3lf", TempMatrix[1][2], TempMatrix[0][2]);
			fprintf(f, "\n");
		}
		if (k == 2) {
			fprintf(f, "%3.3lf %3.3lf", TempMatrix[0][2], TempMatrix[1][2]);
			fprintf(f, "\n");
		}
		return true;
	}
}

void main()
{
	int M, N;
	/*работа с файлами */
	FILE* f, * Answ;
	f = fopen("input.txt", "rt");
	fscanf(f, "%d", &M);
	fscanf(f, "%d", &N);

	/* Матрица и векторы */
	double** Matrix = new double* [M];
	double** Matrix1 = new double* [M];
	double* Answer = new double[N];
	int* L = new int[N];
	for (int i = 0; i < M; i++) Matrix[i] = new double[N + 1];
	for (int i = 0; i < M; i++) Matrix1[i] = new double[N + 1];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			fscanf(f, "%lf", &Matrix[i][j]);
			Matrix1[i][j] = Matrix[i][j];
		}
	}
	for (int i = 0; i < N; i++) L[i] = i;

	/* пошаговый просмотр + возвращаемый ранг основной матрицы  */
	int r;
	r = StepMatrix(M, N + 1, Matrix, L);

	/* вывод пошагового представления в файл */
	Answ = fopen("output.txt", "wt");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			fprintf(Answ, "%3.3f   ", Matrix[i][j]);
		}
		fprintf(Answ, "\n");
	}

	//111
	int i;
	i = r;
	while ((i < M) && (abs(Matrix[i][N]) < eps)) i++;
	if (i < M) fprintf(Answ, "Система не совместна");
	else if (r == N)
	{
		fprintf(Answ, "Решение есть\n");
		for (int j = 0; j < N; j++)
		{
			Answer[L[j]] = Matrix[j][N];
		}
		for (int j = 0; j < N; j++) fprintf(Answ, "x%d=%3.3f; ", j + 1, Answer[j]);
	}
	else
	{
		printf("Система имеет свободные члены.\n");
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
		for (int j = 0; j < N; j++) fprintf(Answ, "x%d=%lf; ", j + 1, Answer[j]);
	}

	/*for (int i = 0; i < N; i++) fprintf(Answ, "%d ", L[i]);*/

	fclose(Answ);
	fclose(f);

	delete[] Answer;
	for (int i = 0; i < M; i++) delete[] Matrix[i];
	delete[] Matrix;

	printf("Результат записан в файл.");
	printf("\n");

	double nums[6], S;
	bool z;
	int check, q = 0;
	FILE* tri;
	cout << "0 - общее решение и пересечение плоскостей" << endl;
	cout << "1 - точка пересечения двух линий" << endl;
	cout << "2 - площадь треугольника" << endl;
	cout << "Открыть файл с рисованием графиков?: ";
	cin >> check;
	int j = 0;
	if (check == 1) {
		lines(M, Matrix1);
		system("project1.exe");
	}
	if (check == 2) {
		tri = fopen("triangle dots.txt", "w");
		z = DotsTri(M, N, Matrix1, L, 0, tri);
		fclose(tri);
		if (z == true) {
			tri = fopen("triangle dots.txt", "r");
			int g = 0;
			while (g < 6) {
				fscanf(tri, "%lf %lf", &nums[g], &nums[g + 1]);
				g = g + 2;
			}
			S = abs(((nums[2] - nums[0]) * (nums[5] - nums[1]) - (nums[4] - nums[0]) * (nums[3] - nums[1])) / 2);
			cout << "\nS = " << S << endl << endl;
			fclose(tri);
		}
		else cout << "\nТакого треугольника не существует!\n" << endl;
		lines(M, Matrix1);
		system("project1.exe");
		}
	}