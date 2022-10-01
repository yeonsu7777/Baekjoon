#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int son1, mom1, son2, mom2;

	scanf("%d %d %d %d", &son1, &mom1, &son2, &mom2);

	int momgcd = gcd(mom1, mom2);
	int sonsum = son1 * mom2 / momgcd + son2 * mom1 / momgcd;
	int momsum = mom1 * mom2 / momgcd;

	int lastgcd = gcd(sonsum, momsum);
	printf("%d %d", sonsum / lastgcd, momsum / lastgcd);
}