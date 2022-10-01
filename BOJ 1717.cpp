#include <iostream>
using namespace std;

int parent[1000005];

void initialize(int N)
{
	for (int i = 0; i <= N; i++)
		parent[i] = i;
}

int find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
	return a;
}

bool check(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	return aRoot == bRoot;
}

void union_set(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);
	parent[aRoot] = bRoot;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	initialize(N);

	char answer[2][5] = { {"NO"}, {"YES"} };
	for (int i = 0; i < M; i++)
	{
		int order, a, b;
		scanf("%d %d %d", &order, &a, &b);
		if (order)
			printf("%s\n", answer[check(a, b)]);
		else
			union_set(a, b);
	}
}