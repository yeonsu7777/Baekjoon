//2021.08.16
//백준 1676번: 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int zeroNum[101];

void fives(void)
{
	int num = 5;
	int tmp;

	zeroNum[0] = 0;
	for (int i = 1; i <= 100; i++)
	{
		tmp = num;
		zeroNum[i] = zeroNum[i - 1];
		while (tmp%5==0)
		{
			zeroNum[i]++;
			tmp /= 5;
		}
		num += 5;
	}
}

int main()
{
	int N;

	fives();
	scanf("%d", &N);
	printf("%d", zeroNum[N / 5]);
}