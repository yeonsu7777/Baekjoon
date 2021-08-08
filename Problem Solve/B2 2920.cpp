#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

void solve(void)
{
	int scale[8];
	int i;

	for (i = 0; i < 8; i++)
	{
		scanf("%d", &scale[i]);
	}

	if (scale[0] == 1)
	{
		for (i = 1; i < 8; i++)
		{
			if (scale[i] != scale[i - 1] + 1)
				break;
		}
		if (i == 8)
			printf("ascending");
		else
			printf("mixed");
	}
	else if (scale[0] == 8)
	{
		for (i = 1; i < 8; i++)
		{
			if (scale[i] != scale[i - 1] - 1)
				break;
		}
		if (i == 8)
			printf("descending");
		else
			printf("mixed");
	}
	else
		printf("mixed");

}

int main()
{
	//int test_case;
	//int T;

	//freopen("input.txt", "r", stdin);
	//cin >> T;

	solve();
	return 0;
}