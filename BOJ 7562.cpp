#include <iostream>
#include <queue>
using namespace std;

int board;
int goalX, goalY;
bool visit[300][300] = { 0, };
queue<pair<pair<int, int>, int>> q;

bool valid(int x, int y)
{
	if (x >= 0 && x < board && y >= 0 && y < board)
		return true;
	return false;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int level = q.front().second;
		q.pop();

		if (x == goalX && y == goalY)
		{
			printf("%d\n", level);
			break;
		}

		int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
		int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

		for (int i = 0; i < 8; i++)
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (valid(nextx, nexty))
			{
				if (!visit[nextx][nexty])
				{
					visit[nextx][nexty] = true;
					q.push({ {nextx, nexty}, level + 1 });
				}
			}
		}
	}
}

void solution()
{
	scanf("%d", &board);
	int startX, startY;
	scanf("%d %d", &startX, &startY);
	scanf("%d %d", &goalX, &goalY);

	while (!q.empty())
		q.pop();
	for (int i = 0; i < board; i++)
		for (int j = 0; j < board; j++)
			visit[i][j] = false;

	visit[startX][startY] = true;
	q.push({ {startX, startY}, 0 });
	bfs();
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++)
		solution();
}