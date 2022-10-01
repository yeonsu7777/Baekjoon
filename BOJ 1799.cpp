#include <iostream>
using namespace std;

int N;
int board[10][10];
int diagu[20], diagd[20];
int result[2];

void bishop(int x, int y, int cnt)
{
	if (y >= N)
	{
		x++;
		y = 1 - y % 2;
	}
	if (x == N)
	{
		result[y] = result[y] < cnt ? cnt : result[y];
		return;
	}

	if (board[x][y]==1 && !diagu[x + y] && !diagd[N - x + y])
	{
		diagu[x + y] = 1;
		diagd[N - x + y] = 1;
		board[x][y] = cnt + 100;
		bishop(x, y + 2, cnt + 1);
		board[x][y] = 1;
		diagu[x + y] = 0;
		diagd[N - x + y] = 0;
	}
	bishop(x, y + 2, cnt);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	bishop(0, 0, 0);
	bishop(0, 1, 0);

	printf("%d", result[0] + result[1]);

	return 0;
}