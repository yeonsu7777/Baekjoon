#include <iostream>
using namespace std;

int costs[1005];
int dp[1005] = { 0, };

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &costs[i]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + costs[j]);
		}
	}
	printf("%d", dp[N]);
}