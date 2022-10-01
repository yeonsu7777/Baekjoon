#include <iostream>
using namespace std;

int N, M;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };	//ºÏµ¿³²¼­
bool clean[50][50] = { 0, };
int room[50][50];
int r, c, d;
int result = 0;

void solution()
{
	int turn;
	while (true)
	{
		if (!clean[r][c])
		{
			clean[r][c] = true;
			result++;
		}
		for (turn = 0; turn < 4; turn++)
		{
			if (d == 0)
				d = 3;
			else
				d--;
			int nextR = r + dir[d][0];
			int nextC = c + dir[d][1];
			if (!room[nextR][nextC] && !clean[nextR][nextC])
			{
				r = nextR;
				c = nextC;
				break;
			}
		}
		if (turn == 4)
		{
			int backR = r - dir[d][0];
			int backC = c - dir[d][1];

			if (!room[backR][backC])
			{
				r = backR;
				c = backC;
			}
			else
				break;
		}
	}
	printf("%d", result);
}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &room[i][j]);

	solution();
}