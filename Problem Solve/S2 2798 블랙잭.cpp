//2021.08.12
//백준 2798번: 블랙잭
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int i, j, k;
	int cards[100];
	int select;
	int result = 0;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &cards[i]);
	}

	for (i = 0; i < N - 2; i++)
	{
		for (j = i + 1; j < N - 1; j++)
		{
			for (k = j + 1; k < N; k++)
			{
				select = cards[i] + cards[j] + cards[k];
				if (select > M)
					continue;
				if (select > result)
					result = select;
			}
			if (result == M)
				break;
		}
		if (result == M)
			break;
	}
	printf("%d", result);
}