#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

void solve(void)
{
	int N, M;
	char board[51][51];
	int i, j, k;
	char pattern[8] = { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' };
	int BW[50][50] = { 0, };
	int correct;
	int minchange;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			for (k = 0; k < 8; k++)
			{
				if (board[i][j + k] == pattern[k])
					BW[i][j]++;
			}
		}
	}

	minchange = 64;
	for (i = 0; i < N - 7; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			correct = 32;
			for (k = 0; k < 8; k++)
			{
				//correct = BW[0] + BW[2] + BW[4] + BW[6] + 32 - (BW[1] + BW[3] + BW[5] + BW[7]);
				if (k % 2)
					correct += BW[i + k][j];
				else
					correct -= BW[i + k][j];
			}
			if (correct > 32)
				correct = 64 - correct;
			if (correct < minchange)
				minchange = correct;
		}
	}

	printf("%d", minchange);
}

int main()
{
	freopen("input.txt", "r", stdin);
	solve();

	return 0;
}