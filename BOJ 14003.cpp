#include <iostream>
using namespace std;

int N;
int arr[3][1000001];
int resultIDX = 1;
int resultL = 1;

void result(int idx)
{
	if (idx == -1)
		return;
	result(arr[2][idx]);
	printf("%d ", arr[0][idx]);
}

int main()
{
	scanf("%d", &N);
	arr[0][0] = -1000000002;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[0][i]);
		arr[2][i] = -1;
	}

	int p_dp;
	for (int i = 1; i <= N; i++)
	{
		p_dp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[0][i]>arr[0][j] &&arr[1][j]>p_dp)
			{
				p_dp = arr[1][j];
				arr[2][i] = j;
			}
		}
		arr[1][i] = p_dp + 1;
		if (resultL <= arr[1][i])
		{
			resultL = arr[1][i];
			resultIDX = i;
		}
	}

	printf("%d\n", arr[1][resultIDX]);
	result(resultIDX);

	return 0;
}