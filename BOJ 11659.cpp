#include <iostream>
using namespace std;

int N, M;
long long dp[100001];
long long a;
int b, c;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &a);
		dp[i] = dp[i - 1] + a;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &b, &c);
		printf("%lld\n", dp[c] - dp[b - 1]);
	}

	return 0;
}