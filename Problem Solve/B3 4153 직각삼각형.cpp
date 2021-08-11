//2021.08.11
//백준 4153번: 직각삼각형
#include <iostream>
using namespace std;

int pow(int a)
{
	return a * a;
}

int main()
{
	int m1, m2, m3;
	
	while (true)
	{
		scanf("%d %d %d", &m1, &m2, &m3);
		if (m1 + m2 + m3 == 0)
			return 0;

		if ((pow(m1) + pow(m2) == pow(m3)) || (pow(m3) + pow(m2) == pow(m1)) || (pow(m1) + pow(m3) == pow(m2)))
			printf("right\n");
		else
			printf("wrong\n");
	}
}