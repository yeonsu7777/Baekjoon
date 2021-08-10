//2021.08.10
//백준 1978번: 소수 찾기
#include <iostream>
using namespace std;

bool primeNum[1001];

void prime(void)
{
	int i, j;

	for (i = 0; i <= 1000; i++)
		primeNum[i] = true;

	primeNum[0] = primeNum[1] = false;
	i = 2;
	while (i < 1000)
	{
		if (primeNum[i]) //index가 소수인 경우
		{
			j = i * 2;
			while (j <= 1000)
			{
				primeNum[j] = false;
				j += i;
			}
		}
		i++;
	}
}

int main()
{
	int N;
	int numToFind;
	int result = 0;

	prime();

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &numToFind);
		if (primeNum[numToFind])
			result++;
	}
	printf("%d", result);
}