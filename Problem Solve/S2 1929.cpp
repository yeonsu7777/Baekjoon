//2021.08.10
//���� 1978��: �Ҽ� ���ϱ�
#include <iostream>
using namespace std;

bool primeNum[1000001];

void prime(void)
{
	int i, j;

	for (i = 0; i <= 1000000; i++)
		primeNum[i] = true;

	primeNum[0] = primeNum[1] = false;
	i = 2;
	while (i < 1000000)
	{
		if (primeNum[i]) //index�� �Ҽ��� ���
		{
			j = i * 2;
			while (j <= 1000000)
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
	int M, N;

	prime();

	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++)
	{
		if (primeNum[i])
			printf("%d\n", i);
	}
}