#include <iostream>
#include <vector>
using namespace std;

int N, K;
int stamp[100010];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < 100001; i++)
		stamp[i] = -1;

	stamp[N] = 0;
	int curT = 0;

	vector<int> temp[2];
	temp[0].push_back(N);

	while (stamp[K] == -1)
	{
		for (int i = 0; i < temp[curT % 2].size(); i++)
		{
			int nextN = temp[curT % 2][i] * 2;
			if (nextN == K)
			{
				stamp[nextN] = curT;
				break;
			}
			if (nextN < K + 2)
			{
				if (stamp[nextN] == -1)
				{
					temp[curT % 2].push_back(nextN);
					stamp[nextN] = curT;
				}
			}
		}

		temp[1 - curT % 2].clear();
		for (int i = 0; i < temp[curT % 2].size(); i++)
		{
			int nextN = temp[curT % 2][i];
			if (nextN > 0)
				if (stamp[nextN - 1] == -1)
				{
					stamp[nextN - 1] = curT + 1;
					temp[1 - curT % 2].push_back(nextN - 1);
				}
			if (temp[curT % 2][i] < K)
				if (stamp[nextN + 1] == -1)
				{
					stamp[nextN + 1] = curT + 1;
					temp[1 - curT % 2].push_back(nextN + 1);
				}
		}
		curT++;
	}

	printf("%d", stamp[K]);
	return 0;
}