#include <iostream>
using namespace std;
#define CANDYMAX 1000000000

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long ext_gcd(long long A, long long B)
{
	long long r, q, tmpA = A, t, t1 = 0, t2 = 1;

	while (B != 0)
	{
		q = A / B;
		r = A % B;
		t = t1 - q * t2;
		A = B;
		B = r;
		t1 = t2;
		t2 = t;
	}

	while (t1 < 0)
		t1 += tmpA;
	return t1;
}

void euclidean(long long nums[][3])
{
	long long newNum[3];
	long long q = 0;
	if (nums[0][2] > nums[1][2])
		q = nums[0][2] / nums[1][2];
	for (int i = 0; i < 3; i++)
	{
		newNum[i] = nums[0][i] - q * nums[1][i];
		nums[0][i] = nums[1][i];
		nums[1][i] = newNum[i];
	}
}

void solve()
{
	int people, candy;
	scanf("%d %d", &people, &candy);
	

	/*
	long long nums[2][3] = { {1, 0, candy}, {0, -1, people} };
	while (nums[1][2] > 1)
	{
		euclidean(nums);
	}
	if (nums[1][2] == 1)
	{
		long long answer = nums[1][0] > 0 ? nums[1][0] : people + nums[1][0];
		if(answer>CANDYMAX)
			printf("IMPOSSIBLE\n");
		else
			printf("%lld\n", answer);
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}*/
	if (candy == 1)
	{
		if (people + 1 > CANDYMAX)
			printf("IMPOSSIBLE\n");
		else
			printf("%lld\n", people + 1);
	}
	else if (people == 1)
		printf("1\n");
	else if (gcd(people, candy) != 1)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		long long answer = ext_gcd((long long)people, (long long)candy);
		if (answer > CANDYMAX)
			printf("IMPOSSIBLE\n");
		else
			printf("%lld\n", answer);
	}
}
int main()
{
	int testcase;
	scanf("%d", &testcase);
	
	while (testcase)
	{
		solve();
		testcase--;
	}
}