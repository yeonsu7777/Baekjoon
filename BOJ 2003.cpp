#include <iostream>
using namespace std;

int dp[10001] = { 0, };

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &dp[i]);
		dp[i] += dp[i - 1];
	}

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dp[i] < M)
			continue;
		for (int j = 0; j < i; j++)
		{
			if (dp[i] - dp[j] == M)
			{
				result++;
			}
			if (dp[i] - dp[j] < M)
				continue;
		}
	}
	printf("%d", result);
}