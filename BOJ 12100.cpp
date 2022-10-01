#include <iostream>
using namespace std;

int N;
int board[6][20][20];
int result;

void get_result()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (result < board[5][i][j])
				result = board[5][i][j];
	return;
}

void init_board(int b)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[b][i][j] = 0;
}

void swipe(int dir, int lvl)
{
	int i = 0;
	int j = 0;

	int saved = 0;

	int last, curr;
	if (dir == 0)
	{
		for (i = 0; i < N; i++)
		{
			saved = 0;
			last = 0;
			for (j = 0; j < N; j++)
			{
				curr = board[lvl][j][i];
				if (curr == 0)
					continue;
				if (last == 0)
					last = curr;
				else
				{
					if (last == curr)
					{
						board[lvl + 1][saved][i] = curr * 2;
						last = 0;
					}
					else
					{
						board[lvl + 1][saved][i] = last;
						last = curr;
					}
					saved++;
				}
			}
			if (last)
				board[lvl + 1][saved][i] = last;
		}
	}
	else if (dir == 1)
	{
		for (i = 0; i < N; i++)
		{
			saved = 0;
			last = 0;
			for (j = 0; j < N; j++)
			{
				curr = board[lvl][N-1 -j][i];
				if (curr == 0)
					continue;
				if (last == 0)
					last = curr;
				else
				{
					if (last == curr)
					{
						board[lvl + 1][N-1-saved][i] = curr * 2;
						last = 0;
					}
					else
					{
						board[lvl + 1][N-1-saved][i] = last;
						last = curr;
					}
					saved++;
				}
			}
			if (last)
				board[lvl + 1][N-1-saved][i] = last;
		}
	}
	else if (dir == 2)
	{
		for (i = 0; i < N; i++)
		{
			saved = 0;
			last = 0;
			for (j = 0; j < N; j++)
			{
				curr = board[lvl][i][j];
				if (curr == 0)
					continue;
				if (last == 0)
					last = curr;
				else
				{
					if (last == curr)
					{
						board[lvl + 1][i][saved] = curr * 2;
						last = 0;
					}
					else
					{
						board[lvl + 1][i][saved] = last;
						last = curr;
					}
					saved++;
				}
			}
			if (last)
				board[lvl + 1][i][saved] = last;
		}
	}
	else if (dir == 3)
	{
		for (i = 0; i < N; i++)
		{
			saved = 0;
			last = 0;
			for (j = 0; j < N; j++)
			{
				curr = board[lvl][i][N - 1 - j];
				if (curr == 0)
					continue;
				if (last == 0)
					last = curr;
				else
				{
					if (last == curr)
					{
						board[lvl + 1][i][N - 1 - saved] = curr * 2;
						last = 0;
					}
					else
					{
						board[lvl + 1][i][N - 1 - saved] = last;
						last = curr;
					}
					saved++;
				}
			}
			if (last)
				board[lvl + 1][i][N - 1 - saved] = last;
		}
	}
}

void move(int lvl)
{
	if (lvl == 5)
	{
		get_result();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		init_board(lvl + 1);
		swipe(i, lvl);
		move(lvl + 1);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[0][i][j]);

	move(0);
	printf("%d", result);
}