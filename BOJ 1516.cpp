#include <iostream>
#include <vector>
using namespace std;

int plan[501][2]; //result, time
vector<int> buildFirst[501];

int solve(int house)
{
	if (!plan[house][0])
	{
		int maxTime = 0;
		for (int i = 0; i < buildFirst[house].size(); i++)
		{
			maxTime = max(maxTime, solve(buildFirst[house][i]));
		}
		plan[house][0] = maxTime + plan[house][1];
	}
	return plan[house][0];
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int place;
		scanf("%d %d", &plan[i][1], &place);
		if (place == -1)
			plan[i][0] = plan[i][1];
		else
		{
			buildFirst[i].push_back(place);
			while (true)
			{
				scanf("%d", &place);
				if (place == -1)
					break;
				else
					buildFirst[i].push_back(place);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		printf("%d\n", solve(i));
}
