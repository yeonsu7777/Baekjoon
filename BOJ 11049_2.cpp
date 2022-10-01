#include <iostream>
using namespace std;

int N;
int r[505], c[505];
int dp[505][505];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &r[i], &c[i]);

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N - i + 1; j++)
		{
			int tmp = (1 << 31) - 1;
			for (int k = 0; k < i; k++)
			{
				tmp = min(tmp, dp[j][k] + dp[j + k + 1][i - k - 1] + r[j] * r[j + k + 1] * c[j + i]);
			}
			dp[j][i] = tmp;
		}
	}

	printf("%d", dp[1][N - 1]);
	return 0;
}