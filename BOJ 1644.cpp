#include <iostream>
using namespace std;
#define MILLION 4000000
#define THOUSAND 2000
long long DP[300000];
bool check[MILLION + 1];
int save = 1;

void getPrime()
{
	for (int i = 0; i <= MILLION; i++)
		check[i] = true;
	check[0] = check[1] = false;

	for (int i = 2; i < THOUSAND; i++)
	{
		if (check[i])
		{
			DP[save] = DP[save - 1] + (long long)i;
			save++;

			for (int remove = i + i; remove <= MILLION; remove += i)
				check[remove] = false;
		}
	}
	for (int i = THOUSAND; i <= MILLION; i++)
		if (check[i])
		{
			DP[save] = DP[save - 1] + (long long)i;
			save++;
		}
}

int main()
{
	int result = 0;
	getPrime();
	int num;
	scanf("%d", &num);
	int point1 = 0;
	int point2 = 1;
	while (point1 < point2)
	{
		if (DP[point2] - DP[point1] < num)
			point2++;
		else if (DP[point2] - DP[point1] == num)
		{
			result++;
			point1++;
			point2++;
		}
		else
			point1++;
	}
	printf("%d", result);
}