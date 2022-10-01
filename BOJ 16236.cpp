#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct fish {
	int x;
	int y;
	int dist = 0;

	bool operator < (const fish& ref) const
	{
		if (this->dist == ref.dist)
		{
			if (this->x == ref.x)
				return this->y < ref.y;
			else
				return this->x < ref.x;
		}
		else
			return this->dist < ref.dist;
	}
};

int N;
int ocean[20][20];

fish shark;
int sh_size = 2;
int eaten = 0;
int levelup = 2;

fish nextFish;
vector<fish> V;

void get_input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &ocean[i][j]);
			if (ocean[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				ocean[i][j] = 0;
			}
		}
}

bool avail(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	if (sh_size < ocean[x][y])
		return false;
	return true;
}

void BFS()
{
	queue<fish> Q;
	Q.push({ shark.x, shark.y, 0 });
	int visit[20][20] = { 0, };
	int dx[4] = { -1, 0, 0, 1 };
	int dy[4] = { 0, -1, 1, 0 };
	visit[shark.x][shark.y] = 1;

	while (!Q.empty())
	{
		int curX = Q.front().x;
		int curY = Q.front().y;
		int curD = Q.front().dist;
		Q.pop();

		if (ocean[curX][curY] > 0 && ocean[curX][curY] < sh_size)
		{
			V.push_back({ curX, curY, curD });
		}

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (avail(nextX, nextY))
			{
				if (!visit[nextX][nextY])
				{
					Q.push({ nextX, nextY, curD + 1 });
					visit[nextX][nextY] = 1;
				}
			}
		}
	}
}

void solve()
{
	while (true)
	{
		V.clear();
		BFS();
		sort(V.begin(), V.end());
		if (V.size() == 0)
			break;
		
		shark.x = V[0].x;
		shark.y = V[0].y;
		shark.dist += V[0].dist;
		ocean[shark.x][shark.y] = 0;

		eaten++;
		if (eaten == levelup)
		{
			sh_size++;
			levelup += sh_size;
		}
	}

	printf("%d", shark.dist);
}

int main()
{
	get_input();
	solve();

	return 0;
}