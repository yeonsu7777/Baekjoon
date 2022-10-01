#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2000000000;

int V, E, Start;
struct e_t
{
	int node;
	int cost;
	e_t(int _node, int _cost) : node(_node), cost(_cost) {} //생성자
	bool operator<(const e_t& ref) const
	{
		return this -> cost > ref.cost;
	}
};
vector<e_t> AL[20001];

int Visited[20001];

int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &Start);
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		AL[a].push_back(e_t(b, c));
	}

	for (int i = 1; i <= V; i++)
		Visited[i] = INF;
	
	priority_queue<e_t> PQ; //min heap 형태로 동작해야 하므로
	Visited[Start] = 0;
	PQ.push(e_t(Start, 0));

	while (!PQ.empty())
	{
		e_t curr = PQ.top();
		PQ.pop();
		for (e_t next : AL[curr.node])
		{
			int cost = curr.cost + next.cost;
			if (cost < Visited[next.node])
			{
				Visited[next.node] = cost;
				PQ.push(e_t(next.node, cost));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (Visited[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", Visited[i]);
	}

	return 0;
}