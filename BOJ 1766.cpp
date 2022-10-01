#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int problem[32001];
vector<int> prior[32001];
vector<priority_queue<int>> pq[32001];

void getInput()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		problem[i] = true;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		prior[B].push_back(A);
	}
}

int main()
{
	getInput();
	for (int i = 1; i <= N; i++)
	{
		if (problem[i])
		{

		}
	}
	return 0;
}