#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

void main()
{
	int n, m;

	/* УПРАЖНЕНИЕ 1 */
	FILE* file0;
	file0 = fopen("test.txt", "rt");
	fscanf(file0, "%d%d", &n, &m);
	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		Matrix[i] = new int[n];
		for (int j = 0;j < n;j++)
		{
			Matrix[i][j] = 0;
		}
	}
	int i, j;
	for (int k = 0; k < m;k++)
	{
		fscanf(file0, "%d%d", &i, &j);
		i--, j--;
		Matrix[i][j] = 1;
		Matrix[j][i] = 1;
	}

	/* вывод в файл */
	FILE* fAnswer1;
	fAnswer1 = fopen("answer1.txt", "wt");
	fprintf(fAnswer1, "peaks and edges :\n");
	fprintf(fAnswer1, "%d %d\n", n, m);
	fprintf(fAnswer1, "Adjacency matrix\n");
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			fprintf(fAnswer1, "%d ", Matrix[i][j]);
		}
		fprintf(fAnswer1, "\n");
	}
	fclose(file0);
	fclose(fAnswer1);


	/* УПРАЖНЕНИЕ 2 */
	FILE* file1;
	file1 = fopen("answer1.txt", "rt");
	char* str[500];
	fscanf(file1, "%s", &str);
	fscanf(file1, "%s", &str);
	fscanf(file1, "%s", &str);
	fscanf(file1, "%s", &str);
	//printf("%s", str);
	n = 0;
	m = 0;
	fscanf(file1, "%d %d", &n, &m);
	/*printf("\nn=%d,m=%d\n", n, m);*/
	fscanf(file1, "%s", &str);
	fscanf(file1, "%s", &str);
	int** Matrix1 = new int* [n];
	for (int i = 0;i < n;i++) Matrix1[i] = new int[n];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			fscanf(file1, "%d ", &Matrix1[i][j]);
		}
	}

	int * D, * S, * L;
	D = new int[m + m];
	S = new int[n];
	L = new int[n];
	for (int i = 0;i < n;i++) L[i] = 0;
	int k = 0;
	S[0] = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (Matrix1[i][j] == 1)
			{
				D[k] = j;
				L[i]++;
				k++;
			}
		}
		S[i+1] = k;
	}

	for (int i = 0;i < n;i++) printf("%d ",L[i]);
	printf("\n");
	for (int i = 0;i < n;i++) printf("%d ", S[i]+1);
	printf("\n");
	for (int i = 0;i < m+m;i++) printf("%d ", D[i]+1);
	printf("\n");


	//int* v1, * v2, * D, * S, * L, * U;
	//v1 = new int[m];
	//v2 = new int[m];
	//int *R = new int[n];
	//for (int i = 0;i < n;i++) R[i] = 0;
	//int kol = 0;
	//for (int i = 0; i < n;i++)
	//{
	//	R[i] = 1;
	//	for (int j = 0; j < n;j++)
	//	{
	//		if ((Matrix[i][j] == 1) && (R[j] == 0))
	//		{
	//			v1[kol] = i;
	//			v2[kol] = j;
	//			kol++;
	//		}
	//	}
	//}

	//D = new int[m + m];
	//S = new int[n];
	//L = new int[n];
	//U = new int[n];
	//for (int i = 0;i < n;i++) L[i] = 0;
	//for (int i = 0;i < m;i++)
	//{
	//	L[v1[i]]++;
	//	L[v2[i]]++;
	//}
	//S[0] = 0;
	//for (int i = 1; i < n;i++) S[i] = S[i - 1] + L[i - 1];
	//for (int i = 0; i < n;i++) U[i] = S[i];
	//int k;
	//for (int i = 0;i < m;i++)
	//{
	//	k = v1[i]; D[U[k]] = v2[i]; U[k]++;
	//	k = v2[i]; D[U[k]] = v1[i]; U[k]++;
	//}

	/* вывод в файл */
	//FILE* fAnswer2;
	//fAnswer2 = fopen("answer2.txt", "wt");
	//fprintf(fAnswer1, "вершины и ребра:\n");
	//fprintf(fAnswer1, "%d %d\n", n, m);
	//fprintf(fAnswer2, "Массив номеров соседних вершин:\n");
	//for (int i = 0; i < m + m; i++) fprintf(fAnswer2, "%d ", D[i]+1);
	//fprintf(fAnswer2, "\nArray of list lengths:\n");
	//for (int i = 0; i < n; i++) fprintf(fAnswer2, "%d ", L[i]);
	//fprintf(fAnswer2, "\nНачальные индексы для каждого списка:\n");
	//for (int i = 0; i < n; i++) fprintf(fAnswer2, "%d ", S[i]+1);
	//fclose(file1);
	//fclose(fAnswer2);


	///* УПРАЖНЕНИЕ 3 */
	//FILE* file2;
	//file2 = fopen("answer2.txt", "rt");
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//n = 0;
	//m = 0;
	//fscanf(file2, "%d %d", &n, &m);
	////printf("%d %d", n, m);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	////printf("%s", str);
	//int * D1, * S1, * L1, * U1;
	//D1 = new int[m + m];
	//S1 = new int[n];
	//L1 = new int[n];
	//U1 = new int[n];
	//for (int i = 0;i < m + m;i++) fscanf(file2, "%d ", &D1[i]);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//for (int i = 0;i < n;i++) fscanf(file2, "%d ", &L1[i]);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//fscanf(file2, "%s", &str);
	//for (int i = 0;i < n;i++) fscanf(file2, "%d ", &S1[i]);

	////printf("\n");
	////for (int i = 0;i < m + m;i++) printf("%d ", D1[i]);
	////printf("\n");
	////for (int i = 0;i < n;i++) printf("%d ", L1[i]);
	////printf("\n");
	////for (int i = 0;i < n;i++) printf("%d ", S1[i]);

	///* вывод в файл */
	//FILE* fAnswer3;
	//fAnswer3 = fopen("answer3.txt", "wt");
	//fprintf(fAnswer3, "Последовательность ребер: ");
	//for (int i = 0; i < n;i++)
	//{
	//	for (int j = i + 1;j < n;j++)
	//	{
	//		for (int l = S1[i]-1;l < S1[i]-1 + L1[i];l++)
	//		{
	//			if (D1[l]-1 == j) fprintf(fAnswer3, " %d-%d ", i+1, j+1);
	//		}
	//	}
	//}
	//fclose(file2);
	//fclose(fAnswer3);

	printf("Ответы записываются в файл \"answer1.txt\",\"answer2.txt\",\"answer3.txt\".\n");
}