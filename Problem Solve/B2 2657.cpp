#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

void solve(int test_case)
{
	int R;
	char word[21];

	scanf("%d %s", &R, word);

	for (int i = 0; word[i]; i++)
	{
		for (int j = 0; j < R; j++)
		{
			printf("%c", word[i]);
		}
	}
	printf("\n");
}

int main()
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);
	}\
	return 0;
}