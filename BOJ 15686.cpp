#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int village[50][50];
int chicken[13][2];
int house[30][2];
int ci, hi;
int picked[13];
bool check[13];
int result = 10000000;

void getInput()
{
	scanf("%d %d", &N, &M);
	ci = hi = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &village[i][j]);
			if (village[i][j] == 2)
			{
				chicken[ci][0] = i;
				chicken[ci][1] = j;
				ci++;
			}
			else if (village[i][j] == 1)
			{
				house[hi][0] = i;
				house[hi][1] = j;
				hi++;
			}
		}
	}
}

int getD(int hidx, int cidx)
{
	return (abs(house[hidx][0] - chicken[picked[cidx]][0]) + abs(house[hidx][1] - chicken[picked[cidx]][1]));
}

void solve()
{
	int tmpresult = 0;
	for (int i = 0; i < hi; i++)
	{
		int dist = 10000000;
		for (int j = 0; j < M; j++)
		{
			if (dist > getD(i, j))
				dist = getD(i, j);
		}
		tmpresult += dist;
	}

	if (tmpresult < result)
		result = tmpresult;
}

void combine(int cidx, int cnt)
{
	if (cnt == M)
	{
		solve();
	}
	else
	{
		for (int i = cidx; i < ci; i++)
		{
			if (check[i])
				continue;
			
			check[i] = true;
			picked[cnt] = i;
			combine(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	getInput();
	combine(0, 0);
	printf("%d", result);
}