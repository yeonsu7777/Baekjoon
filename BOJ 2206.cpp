#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[1005][1005];
int visit[1005][1005][2] = {0,};
int result = -1;
queue<pair<pair<int, int>, int>> q;

int bfs()
{
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	visit[1][1][1] = 1;
	q.push({ { 1, 1 }, 1 });

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int breakWall = q.front().second;
		q.pop();

		if (x == N && y == M)
		{
			return visit[x][y][breakWall];
		}

		for (int i = 0; i < 4; i++)
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];

			if (map[nextx][nexty])
			{
				if (map[nextx][nexty] == '1' && breakWall)
				{
					q.push({ {nextx, nexty}, 0 });
					visit[nextx][nexty][0] = visit[x][y][1] + 1;
				}

				else if (map[nextx][nexty] == '0' && !visit[nextx][nexty][breakWall])
				{
					q.push({ {nextx, nexty}, breakWall });
					visit[nextx][nexty][breakWall] = visit[x][y][breakWall] + 1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%s", &map[i][1]);

	result = bfs();
	printf("%d", result);
}