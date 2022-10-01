#include <iostream>
#define BACONMAX 5005
using namespace std;

int N, M;
int friends[101][101];
int result[101];
int totalResult;
int bacon;

void get_input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			friends[i][j] = BACONMAX;
			if (i == j)
				friends[i][j] = 0;
		}
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		friends[a][b] = 1;
		friends[b][a] = 1;
	}
}
int main()
{
	get_input();

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (k == i)
				continue;
			for (int j = 1; j <= N; j++)
			{
				if (j == k || j == i)
					continue;
				if (friends[i][j] > friends[i][k] + friends[k][j])
					friends[i][j] = friends[i][k] + friends[k][j];
			}
		}
	}

	totalResult = BACONMAX;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			result[i] += friends[i][j];
		if (totalResult > result[i])
		{
			totalResult = result[i];
			bacon = i;
		}
	}
	printf("%d", bacon);
	return 0;
}