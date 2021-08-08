#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

int apart[15][15] = { 0, };

void getarr(void)
{	
	int i, j;

	for (i = 1; i <= 14; i++)
	{
		apart[0][i] = i;
	}

	for (i = 1; i <= 14; i++)
	{
		for (j = 1; j <= 14; j++)
		{
			apart[j][i] = apart[j][i - 1] + apart[j - 1][i];
		}
	}
}

int main()
{
	int T;
	int test_case;
	int k, n;

	scanf("%d", &T);

	getarr();

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &k, &n);
		printf("%d\n", apart[k][n]);
	}	

	return 0;
}