//2021.08.10
//���� 2751��: �� �����ϱ� 2
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int numbers[1000000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);
	sort(numbers, numbers + N);
	
	for (int i = 0; i < N; i++)
		printf("%d\n", numbers[i]);
}