#include <iostream>
using namespace std;

int N, M;
char board[51][51];
bool visit[51][51];
int dp[51][51];

int stoi(char num)
{
	return num - '0';
}

bool valid(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
		if (board[x][y] != 'H')
			return true;
	return false;
}

int dfs(int x, int y)
{
	if (!valid(x, y))
		return 0;
	
	if (visit[x][y] == true)
	{
		printf("-1");
		exit(0);
	}

	if (dp[x][y] != -1)
		return dp[x][y];

	visit[x][y] = true;
	dp[x][y] = true;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	int dist = stoi(board[x][y]);

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i] * dist;
		int nextY = y + dy[i] * dist;

		int DFS = dfs(nextX, nextY) + 1;
		dp[x][y] = dp[x][y] > DFS ? dp[x][y] : DFS;
	}

	visit[x][y] = false;

	return dp[x][y];
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
		for (int j = 0; j < M; j++)
			dp[i][j] = -1;
	}
	
	int answer = dfs(0, 0);
	printf("%d", answer);
}