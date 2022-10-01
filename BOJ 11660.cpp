#include <iostream>
using namespace std;

int dp[1030][1030] = { 0, };

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int inputnum;
			scanf("%d", &inputnum);
			dp[i][j] = inputnum + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		printf("%d\n", result);
	}
}