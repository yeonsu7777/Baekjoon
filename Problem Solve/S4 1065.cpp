#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;
int hansu[50];

void gethansu(void)
{
	int a;
	int index = 0;
	int newhansu;

	for (int i = 1; i < 10; i++)
	{
		a = (-1) * i / 2;
		for (int j = 0; j < 5; j++)
		{
			newhansu = i * 100 + (i + a) * 10 + i + a + a;
			hansu[index++] = newhansu;
			a++;
		}
	}
	hansu[index] = 1111;
}

void solve(void)
{
	int N; //1~1000

	scanf("%d", &N);
	if (N < 100)
		printf("%d", N);
	else
	{
		for (int i = 0;;i++)
		{
			if (N < hansu[i])
			{
				printf("%d", 99 + i);
				break;
			}
		}
	}
}

int main()
{
	gethansu();
	solve();

	return 0;
}