#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> lines;
int dp[100];

void solution()
{
	int maxline = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (lines[i].second > lines[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxline = max(maxline, dp[i]);
	}
	printf("%d", N - maxline);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		lines.push_back({ A, B });
	}

	sort(lines.begin(), lines.end());

	solution();
}