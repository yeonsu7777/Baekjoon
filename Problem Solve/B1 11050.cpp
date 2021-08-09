//2021.08.09
//백준 11050번: 이항 계수 1
#include <iostream>
using namespace std;

int binomialCoef(int a, int b)
{
	int result = 1;
	int mult, div;

	if (b == 0)
		return 1;

	mult = a;
	div = 1;
	for (int i = 0; i < b; i++)
	{
		result = result * (mult--) / (div++);
	}

	return result;
}

int main()
{
	int N, K;
	int result;

	scanf("%d %d", &N, &K);
	if (N - K >= K)
		result = binomialCoef(N, K);
	else
		result = binomialCoef(N, N - K);

	printf("%d", result);
}