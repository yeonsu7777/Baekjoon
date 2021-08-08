#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;
int selfnumber[10000] = { 0, };

void getselfnumber(void)
{
	int seed = 1;
	int dn;
	int lastdn;

	while (seed < 10000)
	{
		if (selfnumber[seed])
		{
			seed++;
			continue;
		}
		else
		{
			dn = lastdn = seed;
			while (true)
			{
				while (lastdn > 0)
				{
					dn += lastdn % 10;
					lastdn /= 10;
				}
				if (dn <= 10000)
				{
					selfnumber[dn] = 1;
					lastdn = dn;
				}
				else
					break;
			}
			seed++;
		}
	}
}

void solve(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		if (selfnumber[i])
			continue;
		else
			printf("%d\n", i);
	}
}

int main()
{
	getselfnumber();
	solve();

	return 0;
}