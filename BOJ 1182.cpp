#include <iostream>
using namespace std;

int saved[1 << 20] = { 0, };
int inputs[20];

int main()
{
	int N, S;
	int result = 0;
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &inputs[i]);

		int minus = 1 << i;
		for (int j = (1 << i); j < (1 << (i + 1)); j++)
		{
			saved[j] = saved[j - minus] + inputs[i];
			if (saved[j] == S)
				result++;
		}
	}
	printf("%d", result);
}