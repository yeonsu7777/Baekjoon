#include <iostream>
using namespace std;

long long dp[201][101];
int lastK[201] = { 0, };
int A, Z, look;
bool result[201] = { 0, };

long long ext_gcd(int n, int k)
{
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
		int jUntil = i < k ? i : k;
		for (int j = lastK[i] + 1; j <= jUntil; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
		if (lastK[i] < k)
			lastK[i] = k;
	}

	return dp[n][k];
}

bool solve()
{
	long long start = 0;
	int checked = 0;
	while (checked < Z)
	{
		int curZ = A + checked + 1;
		int n, k;
		n = (A + Z) - curZ;
		k = 0;
		long long end = start;

		while (end < look && curZ > 0)
		{
			start = end;
			end = start + ext_gcd(n, k);
			n++;
			k++;
			curZ--;
		}

		if (end < look)
		{
			printf("-1");
			return false;
		}
		result[curZ + 1] = true;

		checked++;
	}
	return true;
}

int main()
{
	scanf("%d %d %d", &A, &Z, &look);
	if (solve())
	{
		for (int i = 1; i <= (A + Z); i++)
		{
			if (result[i])
				printf("z");
			else
				printf("a");
		}
	}
}