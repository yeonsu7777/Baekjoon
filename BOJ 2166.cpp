#include <iostream>
#define ll long long
using namespace std;

int N;
ll x[10001], y[10001];
ll result;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &x[i], &y[i]);
	}
	x[N] = x[0];
	y[N] = y[0];

	for (int i = 0; i < N; i++)
	{
		result += x[i] * y[i + 1];
		result -= x[i + 1] * y[i];
	}
	
	if (result < 0)
		result *= -1;

	printf("%lld", result / 2);
	if (result % 2)
		printf(".5");
	else
		printf(".0");

	return 0;
}