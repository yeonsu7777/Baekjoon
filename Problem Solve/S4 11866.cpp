//2021.08.09
//백준 11866번: 요세푸스 문제 0
#include <iostream>
using namespace std;

int main()
{
	int N, K;
	bool onTable[1000];
	int result[1000];
	int leave, index, order;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		onTable[i] = true;

	leave = index = 0;
	order = 1;
	while (leave < N)
	{
		if (onTable[index])
		{
			if (order == K)
			{
				onTable[index] = false;
				order = 1;
				result[leave] = index + 1;
				leave++;
			}
			else
			{
				order++;
			}
		}

		if (index == N - 1)
			index = 0;
		else
			index++;
	}

	printf("<");
	for (int i = 0; i < N - 1; i++)
		printf("%d, ", result[i]);
	printf("%d>", result[N-1]);
}