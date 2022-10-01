#include <iostream>
using namespace std;

int N;
int rc[505][2];
int dp[505][505];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &rc[i][0], &rc[i][1]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			int tmp = (1 << 31) - 1;
			for (int k = j; k <= j + i; k++)
			{
				tmp = min(tmp, dp[j][k] + dp[k + 1][j + i + 1] + rc[j][0] * rc[k][1] * rc[j + i + 1][1]);
			}
			dp[j][j + i + 1] = tmp;
		}
	}

	printf("%d", dp[0][N - 1]);
	return 0;
}