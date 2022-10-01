#include <iostream>
using namespace std;
#define MILLION 1000000
#define THOUSAND 1000
int prime[50000];
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
	for (int i = THOUSAND; i <= MILLION / 2; i++)
		if (check[i])
		{
			prime[save] = i;
			save++;
		}
}

void solve(int num)
{
	for (int i = 0; i < save; i++)
	{
		if (prime[i] > num)
			return;
		if (check[num - prime[i]])
		{
			printf("%d = %d + %d\n", num, prime[i], num - prime[i]);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

int main()
{
	getPrime();
	while (true)
	{
		int num;
		scanf("%d", &num);
		if (num == 0)
			break;
		solve(num);
	}
}