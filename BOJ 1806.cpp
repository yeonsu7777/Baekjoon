#include <iostream>
using namespace std;

int N, S;
int num[100000];
int result = 100010;

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	int lidx = 0;
	int ridx = 0;
	int sum = 0;

	while (ridx <= N)
	{
		if (sum < S)
		{
			if (ridx == N)
				break;
			sum += num[ridx];
			ridx++;
		}
		else
		{
			if (result > ridx - lidx)
				result = ridx - lidx;
			sum -= num[lidx];
			lidx++;
		}
	}

	if (result == 100010)
		printf("0");
	else
		printf("%d", result);

	return 0;
}