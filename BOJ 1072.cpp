#include <iostream>
using namespace std;

long long solve(long long X, long long Y)
{
	long long Z = 100 * Y / X;
	if (Z >= 99)
		return -1;

	long long left = 99 - Z;
	long long right = (Z + 1) * (X - Y);

	long long result = right / left;
	if (right % left)
		return result - Y + 1;
	else
		return result - Y;
}

int main()
{
	long long X, Y;
	scanf("%lld %lld", &X, &Y);

	printf("%lld", solve(X, Y));
}