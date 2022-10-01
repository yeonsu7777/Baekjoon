#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
int leftnum[10];
bool solved = false;
vector<pair<int, int>> hole;

bool okay(int a, int b, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != b && board[a][i] == num)
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != a && board[i][b] == num)
			return false;
	}

	int blocka = a - a % 3;
	int blockb = b - b % 3;
	for (int i = blocka; i < blocka + 3; i++)
		for (int j = blockb; j < blockb + 3; j++)
		{
			if (i == a && j == b)
				continue;
			if (board[i][j] == num)
				return false;
		}

	return true;
}

void sudoku(int level)
{
	if (level == leftnum[0] || solved)
	{
		solved = true;
		return;
	}
	else
	{
		int a = hole[level].first;
		int b = hole[level].second;
		for (int i = 1; i <= 9; i++)
		{
			if (leftnum[i] == 0)
				continue;
			board[a][b] = i;
			if (okay(a, b, i))
			{
				leftnum[i]--;
				sudoku(level + 1);
				if (solved)
					break;
				leftnum[i]++;
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= 9; i++)
		leftnum[i] = 9;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &board[i][j]);
			leftnum[board[i][j]]--;
			if (board[i][j] == 0)
				hole.push_back({ i, j });
		}
	}
	
	leftnum[0] *= -1;
	sudoku(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}