#include <iostream>
using namespace std;

int N, M;
int height[501][501];

int main()
{
	scanf("%d %d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		height[a][b] = 1;
		height[b][a] = -1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					continue;
				if (height[i][k] && height[i][k] == height[k][j])
					height[i][j] = height[i][k];
			}
		}
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		int know = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i != j && height[i][j])
				know++;
		}
		if (know == N - 1)
			result++;
	}

	printf("%d", result);
	return 0;
}