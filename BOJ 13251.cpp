#include <iostream>
using namespace std;

int main()
{
	int color[50];
	int M, K;
	int N = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &color[i]);
		N += color[i];
	}
	scanf("%d", &K);

	double answer = 0;
	for (int i = 0; i < M; i++)
	{
		double tmp;
		if (color[i] >= K)
		{
			tmp = 1.0;
			for (int j = 0; j < K; j++)
				tmp *= color[i] - j;
			answer += tmp;
		}
	}
	double tmp = 1.0;
	for (int j = 0; j < K; j++)
		tmp *= N - j;

	answer /= tmp;

	printf("%.15f", answer);
}