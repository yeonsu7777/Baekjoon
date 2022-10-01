#include <iostream>
#include <vector>
using namespace std;

char string1[4005], string2[4005];
int DP[4005][4005];
vector<int> alp[26];

int main()
{
	scanf("%s %s", string1, string2);

	for (int i = 0; i < 4005; i++)
	{
		if (string1[i] == 0)
			break;
		alp[string1[i] - 'A'].push_back(i);
	}

	int result = 0;
	for (int i = 0; i < 4005; i++)
	{
		if (string2[i] == 0)
			break;
		int curr = string2[i] - 'A';
		for (int j = 0; j < alp[curr].size(); j++)
		{
			DP[i + 1][alp[curr][j] + 1] = DP[i][alp[curr][j]] + 1;
			result = max(result, DP[i + 1][alp[curr][j] + 1]);
		}
	}

	printf("%d", result);
	return 0;
}