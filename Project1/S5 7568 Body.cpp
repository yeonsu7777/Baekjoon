//2021.08.21
//https://www.acmicpc.net/problem/197568
//Baekjoon 7568 Body
#include <iostream>
using namespace std;

int main()
{
	int body[50][2];
	int N;
	int result;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &body[i][0], &body[i][1]);
	}

	for (int i = 0; i < N; i++)
	{
		result = 1;
		for (int j = 0; j < N; j++)
		{
			if (body[i][0] < body[j][0] && body[i][1] < body[j][1])
				result++;
		}
		printf("%d\n", result);
	}
}