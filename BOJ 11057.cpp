#include <iostream>
using namespace std;

int main()
{
	int dp[10][2];
	int N;
	int result = 0;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++)
		dp[i][0] = 1;

	for (int i = 1; i < N; i++)
	{
		int after = i % 2;
		int before = 1 - after;

		dp[0][after] = 0;
		for (int j = 0; j < 10; j++)
			dp[0][after] += dp[j][before];
		for (int j = 1; j < 10; j++)
		{
			dp[j][after] = dp[j - 1][after] - dp[j - 1][before];
			if (dp[j - 1][after] > 10007)
				dp[j - 1][after] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++)
		result += dp[i][1 - N % 2];

	printf("%d", result %= 10007);
}