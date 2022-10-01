#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> numbers;
int chosen[8];
bool picked[8] = { 0, };

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
			if (!picked[i])
			{
				chosen[level] = i;
				picked[i] = true;
				choose(level + 1);
				picked[i] = false;
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

/*
3 1
4 5 2

4 2
9 8 7 1

4 4
1231 1232 1233 1234
*/