#include <iostream>
#define PAPERSIZE 2187
using namespace std;

int N;
int paper[PAPERSIZE][PAPERSIZE];
int result[3];

void check_p(int x, int y, int size)
{
	int num = paper[x][y];
	bool sameP = true;

	if (size == 1)
	{
		result[num]++;
		return;
	}

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (num != paper[i][j])
			{
				sameP = false;
				break;
			}
		}
		if (!sameP)
			break;
	}

	if (!sameP)
	{
		int next_size = size / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				check_p(x + next_size * i, y + next_size * j, next_size);
			}
		}
	}
	else
	{
		result[num]++;
		return;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &paper[i][j]);
			paper[i][j]++;
		}
	
	check_p(0, 0, N);

	printf("%d\n", result[0]);
	printf("%d\n", result[1]);
	printf("%d\n", result[2]);
	return 0;
}