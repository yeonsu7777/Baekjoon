#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int a, b, w;
	bool operator < (const node& ref) const {
		return this->w < ref.w;
	}
};

int V, E;
int result;
int set[10001];
node graph[100000];

void get_input()
{
	int a, b, c;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph[i].a = a;
		graph[i].b = b;
		graph[i].w = c;
	}
	for (int i = 1; i <= V; i++)
		set[i] = i;
}

int find_set(int a)
{
	if (a == set[a])
		return a;
	else
		return set[a] = find_set(set[a]);
}

bool linked(node curr)
{
	return find_set(curr.a) == find_set(curr.b);
}

void union_set(node curr)
{
	int small = curr.a < curr.b ? curr.a : curr.b;
	int big = curr.a + curr.b - small;
	set[find_set(big)] = find_set(small);
}

void solve()
{
	int chosen = 0;
	int gidx = 0;
	node curr;

	while (chosen < V - 1)
	{
		curr = graph[gidx];
		if (!linked(curr))
		{
			result += curr.w;
			chosen++;
			union_set(curr);
		}
		gidx++;
	}
}

int main()
{
	get_input();
	sort(graph, graph + E);

	solve();
	printf("%d", result);
	return 0;
}