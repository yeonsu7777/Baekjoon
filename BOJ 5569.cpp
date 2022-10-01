#include <iostream>
using namespace std;

int dp[100][100][4];

int main()
{
	int w, h;
	scanf("%d %d", &w, &h);

	for (int i = 0; i < w; i++)
		dp[i][0][3] = 1;
	for (int j = 0; j < h; j++)
		dp[0][j][0] = 1;

	for (int i = 1; i < w; i++)
	{
		for (int j = 1; j < h; j++)
		{
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][0];
			dp[i][j][2] = dp[i][j - 1][3];
			dp[i][j][3] = dp[i - 1][j][1] + dp[i - 1][j][3];
			for (int k = 0; k < 4; k++)
				if (dp[i][j][k] > 100000)
					dp[i][j][k] %= 100000;
		}
	}
	
	int result = dp[w - 1][h - 1][0] + dp[w - 1][h - 1][1] + dp[w - 1][h - 1][2] + dp[w - 1][h - 1][3];
	printf("%d", result %= 100000);
}