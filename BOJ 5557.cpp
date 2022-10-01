#include <iostream>
using namespace std;

int main()
{
	int inputs[100];
	int N;
	long long result[2][21] = { 0, };

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &inputs[i]);

	result[0][inputs[0]] = 1;
	for (int i = 1; i < N - 1; i++)
	{
		int turn = i % 2;
		for (int j = 0; j <= 20; j++)
			result[turn][j] = 0;
		for (int j = 0; j <= 20; j++)
		{
			long long tmp = result[1 - turn][j];
			if (tmp)
			{
				if (j - inputs[i] >= 0)
					result[turn][j - inputs[i]] += tmp;
				if (j + inputs[i] <= 20)
					result[turn][j + inputs[i]] += tmp;
			}
		}
	}
	printf("%lld", result[N % 2][inputs[N - 1]]);
}