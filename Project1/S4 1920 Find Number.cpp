//2021.08.21
//https://www.acmicpc.net/problem/1920
//Baekjoon 1920 Find Number
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int numbers[100000];

int find(int num)
{
	int start = 0;
	int end = N - 1;
	int middle = (start + end) / 2;

	while (true)
	{
		if (num == numbers[middle] || num == numbers[start] || num == numbers[end])
			return 1;
		if (start == middle)
			return 0;
		if (num < numbers[middle])
		{
			end = middle;
			middle = (start + end) / 2;
		}
		else
		{
			start = middle;
			middle = (start + end) / 2;
		}
	}
}

int main()
{
	int M;
	int numtofind;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);
	sort(numbers, numbers + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &numtofind);
		printf("%d\n", find(numtofind));
	}
}