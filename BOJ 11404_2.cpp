#include <iostream>
using namespace std;

const int INF = 100000000;	//10^8
int N, M;
int AM[101][101]; //adjacent matrix

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
				AM[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		AM[a][b] = c < AM[a][b] ? c : AM[a][b];
	}

	//플로이드 워셜
	for (int k = 1; k <= N; k++)	// k: 경유지
	{
		for (int i = 1; i <= N; i++)	// i: 출발지
		{
			for (int j = 1; j <= N; j++)	// j: 도착지
			{
				if (AM[i][j] > AM[i][k] + AM[k][j])
					AM[i][j] = AM[i][k] + AM[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (AM[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", AM[i][j]);
		}
		printf("\n");
	}
}