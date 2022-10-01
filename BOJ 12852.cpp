#include <iostream>
#define NLIMIT 1000001
using namespace std;

int N;
int dp[NLIMIT];
int prior[NLIMIT];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		dp[i] = NLIMIT;
	}
	dp[1] = 0;
	for (int i = 1; i < N; i++)
	{
		if (dp[i + 1] > dp[i] + 1)
		{
			dp[i + 1] = dp[i] + 1;
			prior[i + 1] = i;
		}
		if (i * 2 <= N)
		{
			if (dp[i * 2] > dp[i] + 1)
			{
				dp[i * 2] = dp[i] + 1;
				prior[i * 2] = i;
			}
		}
		if (i * 3 <= N)
		{
			if (dp[i * 3] > dp[i] + 1)
			{
				dp[i * 3] = dp[i] + 1;
				prior[i * 3] = i;
			}
		}
	}
	printf("%d\n", dp[N]);
	int pidx = N;
	printf("%d ", N);
	while (pidx > 1)
	{
		printf("%d ", prior[pidx]);
		pidx = prior[pidx];
	}
	return 0;
}