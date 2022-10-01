#include <iostream>
using namespace std;

long long A, B;
long long one[55];
long long two[55];
long long result;
int A_idx, B_idx;

void get_input()
{
	one[0] = 1;
	two[0] = 1;
	A = 1;
	for (int i = 1; i < 55; i++)
	{
		B = A;
		A *= 2;
		one[i] = A + i * B;
		two[i] = A;
	}

	scanf("%lld %lld", &A, &B);

	for (int i = 0; i < 54; i++)
	{
		if (two[i] <= A && A < two[i + 1])
		{
			A_idx = i;
			break;
		}
	}

	for (int i = 0; i < 54; i++)
	{
		if (two[i] <= B && B < two[i + 1])
		{
			B_idx = i;
			break;
		}
	}
}

long long rest(long long a, long long b)
{
	if (a == b)
		return 1;

	long long start = 0;
	long long end = b - a;

	long long tmpresult = 0;

	for (int i = 0; i < 54; i++)
	{
		if (end < two[i + 1])
		{
			tmpresult += rest(two[i], end);
			break;
		}
		tmpresult += one[i];
	}
	return end + 1 + tmpresult;
}

int main()
{	
	get_input();
	for (int i = A_idx; i < B_idx; i++)
		result += one[i];

	if(two[A_idx]<A)
		result -= rest(two[A_idx], A-1);
	result += rest(two[B_idx], B);
	printf("%lld", result);
	return 0;
}