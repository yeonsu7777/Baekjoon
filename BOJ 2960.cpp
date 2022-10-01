#include <iostream>
using namespace std;

int main()
{
	int result;
	int N, K;
	scanf("%d %d", &N, &K);

	bool prime[1000];
	for (int i = 0; i <= N; i++)
	{
		prime[i] = true;
	}
	int remove = 1;
	prime[0] = prime[1] = false;
	
	while (K)
	{
		while (!prime[remove])
			remove++;

		for (int i = remove; i <= N; i += remove)
		{
			if (prime[i])
			{
				prime[i] = false;
				K--;
			}
			if (K == 0)
			{
				result = i;
				break;
			}
		}
	}

	printf("%d", result);
}