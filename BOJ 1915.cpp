#include <iostream>
using namespace std;

int N, M;
char square[1001][1001];
int dp[1001][1001];
int result = 0;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", square[i]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (square[i - 1][j - 1] == '0')
				dp[i][j] = 0;
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}

	printf("%d", result * result);
}