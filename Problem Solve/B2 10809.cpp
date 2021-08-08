#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

void solve(void)
{
	char word[101];
	int alphabet[26];
	int i;

	scanf("%s", word);

	for (i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}

	for (i = 0; word[i]; i++)
	{
		if (alphabet[word[i] - 'a'] != -1)
			continue;
		else
			alphabet[word[i] - 'a'] = i;
	}

	for (i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
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