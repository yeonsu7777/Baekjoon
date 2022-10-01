#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; //N: 노드 수, M: 질문 수
int a, b;

vector<int> AL[100001];
int Depth[100001];
int Parent[18][100001]; // 1<<17 = 131072

int LCA(int a, int b)
{
	if (Depth[a] < Depth[b])
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int diff = Depth[a] - Depth[b];
	for (int r = 0; diff; r++)
	{
		if (diff & 1)
		{
			a = Parent[r][a];
		}
		diff >>= 1;
	}

	while (a != b)
	{
		int r;
		for (r = 0; r < 18; r++)
		{
			if (Parent[r][a] == Parent[r][b])
				break;
		}
		if (r > 0)
			--r;
		a = Parent[r][a], b = Parent[r][b];
	}
	return a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		AL[a].push_back(b);
		AL[b].push_back(a);
	}

	//BFS를 이용한 depth 구하기
	for (int i = 1; i <= N; i++)
		Depth[i] = -1;
	queue<int> q;
	q.push(1);
	Depth[1] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int next : AL[curr])
		{
			if (Depth[next] == -1) //미방문시
			{
				q.push(next);
				Depth[next] = Depth[curr] + 1;
				Parent[0][next] = curr;
			}
		}
	}

	// 점핑 테이블 만들기
	for (int r = 1; r < 18; r++)
	{
		for (int i = 1; i <= N; i++)
		{
			Parent[r][i] = Parent[r - 1][Parent[r - 1][i]];
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}