#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tree[100005];
bool visit[100005] = { 0, };
vector<int> v[100005];

void dfs(int num)
{
	visit[num] = true;
	for (int i = 0; i < v[num].size(); i++)
	{
		int next = v[num][i];
		if (!visit[next])
		{
			tree[next] = num;
			dfs(next);
		}
	}
}

int main()
{
	int num;
	scanf("%d", &num);

	queue < pair<int, int>> inputs;

	tree[1] = 1;
	for (int i = 0; i < num - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= num; i++)
	{
		printf("%d\n", tree[i]);
	}
}
/*
7
1 6
6 3
3 5
4 1
2 4
4 7

12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12
*/