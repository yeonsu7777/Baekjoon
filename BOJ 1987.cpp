#include <iostream>
using namespace std;

char board[22][22] = { 0, };
int alpha[26] = { 0, };
int R, C;
int result;

void dfs(int x, int y, int level)
{
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	result = level > result ? level : result;

	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (board[nextx][nexty])
		{
			if (!alpha[board[nextx][nexty] - 'A'])
			{
				alpha[board[nextx][nexty] - 'A'] = 1;
				dfs(nextx, nexty, level + 1);
				alpha[board[nextx][nexty] - 'A'] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		getchar();
		scanf("%s", &board[i][1]);
	}
	alpha[board[1][1] - 'A'] = 1;
	dfs(1, 1, 1);
	printf("%d", result);
}