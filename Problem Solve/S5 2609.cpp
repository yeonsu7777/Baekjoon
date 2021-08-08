//2021.08.08
//백준 2609번: 최대공약수와 최소공배수
#include <iostream>

//최대공약수
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//최소공배수
int lcm(int a, int b, int g)
{
	return a * b / g;
}

int main()
{
	int a, b;
	int greatcd;
	int leastcm;

	scanf("%d %d", &a, &b);
	greatcd = gcd(a, b);
	leastcm = lcm(a, b, greatcd);
	printf("%d\n%d\n", greatcd, leastcm);
}