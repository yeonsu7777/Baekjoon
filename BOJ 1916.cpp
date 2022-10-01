#include <iostream>
#include <vector>
#define INTMAX 200000000
using namespace std;

int city, bus;
vector<vector<pair<int, int>>> route;

void getInput()
{
	for (int i = 0; i <= city; i++)
	{
		vector<pair<int, int>> tmp;
		route.push_back(tmp);
	}

	for (int i = 0; i < bus; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);

		route[from].push_back({ to, cost });
	}
}

int minDist(vector<int>& dist, vector<bool>& sptSet)
{
	int min = INTMAX;
	int min_idx;

	for (int i = 1; i <= city; i++)
		if (!sptSet[i] && dist[i] <= min)
		{
			min = dist[i];
			min_idx = i;
		}

	return min_idx;
}

void dijkstra(int start, int arrive)
{
	vector<int> dist(city + 1, INTMAX);
	vector<bool> sptSet(city + 1, false);

	dist[start] = 0;

	for (int i = 1; i < city; i++)	//모든 도시에 대해 거리를 측정해야 함, 마지막 도시는 측정 필요 없음
	{
		int u = minDist(dist, sptSet);	//가장 거리가 짧은 도시 선택
		sptSet[u] = true;
		if (dist[u] == INTMAX)
			continue;
		for (int j = 0; j < route[u].size(); j++)
		{
			int next = route[u][j].first;
			int cost = route[u][j].second;
			if (!sptSet[next])
			{
				if (dist[u] + cost < dist[next])
					dist[next] = dist[u] + cost;
			}
		}
	}

	printf("%d", dist[arrive]);
}

int main()
{
	scanf("%d", &city); //get number of city
	scanf("%d", &bus); //get number of bus
	getInput();

	int start, arrive;
	scanf("%d %d", &start, &arrive);

	dijkstra(start, arrive);
}