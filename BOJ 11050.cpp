#include <iostream>
using namespace std;

int dp[11][11];

int nck(int N, int K)
{
	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= K; j++)
		{
			if (j > i)
				break;
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	return dp[N][K];
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	printf("%d", nck(N, K));
}