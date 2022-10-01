#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int degree[32001];
vector<int> behind[32001];

int main()
{
	//input
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		degree[b]++;
		behind[a].push_back(b);
	}

	//solution
	queue<int> waiting;
	for (int i = 1; i <= N; i++)
		if (!degree[i])
			waiting.push(i);

	while (!waiting.empty())
	{
		int student = waiting.front();
		waiting.pop();
		printf("%d ", student);

		for (int i = 0; i < behind[student].size(); i++)
			if (!(--degree[behind[student][i]]))
			{
				waiting.push(behind[student][i]);
			}
	}
}