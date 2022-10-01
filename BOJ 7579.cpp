#include <iostream>
#include <algorithm>
using namespace std;

struct app
{
	int memory;
	int cost;

	inline bool operator < (const app& ref) const {
		return this->cost < ref.cost;
	}
};

int N, M;
app acting[100];
int DP[101][10005];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &acting[i].memory);
	for (int i = 0; i < N; i++)
		scanf("%d", &acting[i].cost);

	sort(acting, acting + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < acting[i].cost; j++)
			DP[i+1][j] = DP[i][j];
		for (int j = acting[i].cost; j < 10005; j++)
		{
			DP[i+1][j] = max(DP[i][j], DP[i][j - acting[i].cost] + acting[i].memory);
		}
	}

	//DP[N]에서 M보다 크거나 같은 값의 index 찾기

	for(int i=0; i<10005; i++)
		if (DP[N][i] >= M)
		{
			printf("%d", i);
			break;
		}
	return 0;
}