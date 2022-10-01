#include <iostream>
using namespace std;

int N;
int a_matrix[100][100];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &a_matrix[i][j]);

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a_matrix[i][j] |= a_matrix[i][k] & a_matrix[k][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", a_matrix[i][j]);
		printf("\n");
	}

	return 0;
}