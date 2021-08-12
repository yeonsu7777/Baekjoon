//2021.08.12
//백준 2231번: 분해합
#include <iostream>
#include <string>
using namespace std;

int getplus(int num)
{
	int plus=0;
	while (num > 0)
	{
		plus += num % 10;
		num /= 10;
	}
	return plus;
}

int main()
{
	int N;
	int tmp;
	int loop = 0;
	int index = 0;
	int plus;
	int result = 0;

	scanf("%d", &N);
	tmp = N;
	while (tmp > 9)
	{
		tmp /= 10;
		loop += 9;
	}
	loop += tmp;

	for (int i = N - loop; i < N; i++)
	{
		plus = getplus(i);
		if (i + plus == N)
		{
			result = i;
			break;
		}
	}
	printf("%d", result);
}