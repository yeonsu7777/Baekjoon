//2021.08.13
//���� 10989��: �� �����ϱ� 3
#include <iostream>
#include <algorithm>
using namespace std;

int numcount[10001] = { 0, };

int main()
{
	int N;
	int num;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		numcount[num]++;
	}
	
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < numcount[i]; j++)
			printf("%d\n", i);
}