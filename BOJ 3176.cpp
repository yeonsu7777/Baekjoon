#include <iostream>
#include <vector>
#include <queue>
#define NODE 100001
#define INF 100000000005
using namespace std;

struct e_t
{
	int node;
	int cost;
	e_t(int _node, int _cost) : node(_node), cost(_cost) {}
	bool operator< (const e_t& ref)const
	{
		return this->cost > ref.cost;
	}
};

int N, K;
vector<e_t> AL[NODE];
priority_queue<e_t> PQ;
long long visited[NODE][3]; //cost, min, max

void dijkstra(int start, int end)
{
	while (!PQ.empty())
		PQ.pop();
	for (int i = 1; i <= N; i++)
	{
		visited[i][0] = visited[i][1] = INF;
		visited[i][2] = 0;
	}
	visited[start][0] = visited[start][1] = 0;
	PQ.push(e_t(start, 0));

	while (!PQ.empty())
	{
		e_t curr = PQ.top();
		PQ.pop();
		for (e_t next : AL[curr.node])
		{
			int cost = curr.cost + next.cost;
			if (cost < visited[next.node][0])
			{
				visited[next.node][0] = cost;
				if(next.cost<visited[next.node][1])
					visited[next.node][1] = next.cost;
				if (next.cost > visited[next.node][2])
					visited[next.node][2] = next.cost;
				PQ.push(e_t(next.node, cost));
			}
		}
	}


}

int main()
{
	int A, B, C;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		AL[A].push_back({ B, C });
		AL[B].push_back({ A, C });
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int D, E;
		scanf("%d %d", &D, &E);
		dijkstra(D, E);
	}
}