#include <iostream>
using namespace std;

int dp[10002] = { 0, };
int coins[100];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}
	printf("%d", dp[k]);
}