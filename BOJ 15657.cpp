#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> numbers;
int chosen[8];
int last = 0;

void choose(int level)
{
	if (level == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", numbers[chosen[i]]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (i >= last)
			{
				int save = last;
				chosen[level] = i;
				last = i;
				choose(level + 1);
				last = save;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());

	choose(0);
}