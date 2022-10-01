#include <iostream>
#include <vector>
using namespace std;

int n;
int result;
int tmpresult;
vector<pair<int, int>> A_L[100001];
bool visit[100001];

void getInput()
{
	scanf("%d", &n);

	int lineNum = 0;
	int a, w;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &lineNum);
		scanf("%d", &a);
		while (a != -1)
		{
			scanf("%d", &w);
			A_L[lineNum].push_back({ a, w});
			scanf("%d", &a);
		}
	}
}

void dfs(int a)
{
	visit[a] = true;
	for (int i = 0; i < A_L[a].size(); i++)
	{
		if (!visit[A_L[a][i].first])
		{
			tmpresult += A_L[a][i].second;
			dfs(A_L[a][i].first);
			tmpresult -= A_L[a][i].second;
		}
	}
	visit[a] = false;
	if (tmpresult > result)
		result = tmpresult;
}

int main()
{
	getInput();
	for (int i = 1; i <= n; i++)
	{
		tmpresult = 0;
		dfs(i);
	}
	printf("%d", result);
	return 0;
}