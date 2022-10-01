#include <iostream>
using namespace std;
#define MILLION 1000000
#define THOUSAND 1000
int prime[80000];
bool check[MILLION + 1];
int save = 0;

void getPrime()
{
	for (int i = 0; i <= MILLION; i++)
		check[i] = true;
	check[0] = check[1] = false;

	for (int i = 2; i < THOUSAND; i++)
	{
		if (check[i])
		{
			prime[save] = i;
			save++;

			for (int remove = i + i; remove <= MILLION; remove += i)
				check[remove] = false;
		}
	}
	for (int i = THOUSAND; i <= MILLION; i++)
		if (check[i])
		{
			prime[save] = i;
			save++;
		}
}

bool mod(char num[], int primeNum)
{
	int number = 0;
	int idx = 0;
	while (num[idx])
	{
		number = number*10 + num[idx] - '0';
		number %= primeNum;
		idx++;
	}

	if (number)
		return false;
	else
		return true;
}

int main()
{
	int result = 0;
	getPrime();

	char num[105];
	int K;
	scanf("%s %d", num, &K);

	int idx = 0;
	while (prime[idx] < K && idx < save)
	{
		if (mod(num, prime[idx]))
		{
			result = prime[idx];
			break;
		}
		idx++;
	}
	if (result)
		printf("BAD %d", result);
	else
		printf("GOOD");
}