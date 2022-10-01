#include <iostream>
using namespace std;

int N;
int map[105][105] = { 0, };
bool visit[105][105] = { 0, };
bool height[105] = { 0, };
int result;

void getInput()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			height[map[i][j]] = true;
		}
}

void dfs(int x, int y, int h)
{
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (map[nextx][nexty] > h && !visit[nextx][nexty])
		{
			dfs(nextx, nexty, h);
		}
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void initVisit()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;
}
void solution(int h)
{
	int safe = 0;
	initVisit();
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] > h && !visit[i][j])
			{
				safe++;
				dfs(i, j, h);
			}
		}
	result = max(result, safe);
}

int main()
{
	scanf("%d", &N);
	getInput();
	result = 1;
	for (int i = 1; i <= 100; i++)
		if (height[i])
			solution(i);
	printf("%d", result);
}