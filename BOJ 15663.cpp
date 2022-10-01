#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
int counted[8][2] = { 0, };
int numofnum = 0;
int picked[8] = { 0, };

void solve(int level)
{
	if (level == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", picked[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i <= numofnum; i++)
		{
			if (counted[i][0])
			{
				counted[i][0]--;
				picked[level] = counted[i][1];
				solve(level + 1);
				counted[i][0]++;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d", &input);
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());
	counted[0][0] = 1;
	counted[0][1] = nums[0];

	for (int i = 1; i < N; i++)
	{
		if (counted[numofnum][1] != nums[i])
		{
			numofnum++;
			counted[numofnum][1] = nums[i];
		}
		counted[numofnum][0]++;

	}
	solve(0);
}