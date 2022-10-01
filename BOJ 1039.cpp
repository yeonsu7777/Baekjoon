#include <iostream>
#include <queue>
using namespace std;

int k;
int length = 0;
int result = -1;
queue<pair<int, int>> q;

int makeNum(int numbers[])
{
	int num = 0;
	for (int i = 0; i < length; i++)
		num = num * 10 + numbers[i];

	return num;
}

void bfs()
{
	while (!q.empty())
	{
		int current = q.front().first;
		int level = q.front().second;
		q.pop();

		if (level == k)
			result = current > result ? current : result;

		else
		{
			int numbers[7];
			for (int i = 1; i <= length; i++)
			{
				numbers[length - i] = current % 10;
				current /= 10;
			}
			for (int i = 0; i < length; i++)
				for (int j = i + 1; j < length; j++)
				{
					if ((i == 0 && numbers[j] == 0) || numbers[i] == numbers[j])
						continue;
					else
					{
						int tmp = numbers[i];
						numbers[i] = numbers[j];
						numbers[j] = tmp;
						q.push({ makeNum(numbers), level + 1 });
						numbers[j] = numbers[i];
						numbers[i] = tmp;
					}
				}
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	int tmp = N;

	while (tmp > 0)
	{
		tmp /= 10;
		length++;
	}

	scanf("%d", &k);

	q.push({ N, 0 });
	bfs();
	printf("%d", result);

	return 0;
}