#include <iostream>
using namespace std;

int board[9][9];
int row[10][9]; //row[i][j] - i(1~9)가 j(0~8)열에 있는지 확인
int col[10][9]; //col[i][j] - i(1~9)가 j(0~8)행에 있는지 확인
int block[10][9]; //block[i][j] - i(1~9)가 j(0~8)번 블럭에 있는지 확인
bool solved;

int blocknum(int i, int j)
{
	return ((i / 3) * 3 + j / 3);
}

void getInput()
{
	char inputstr[10];
	for (int i = 0; i < 9; i++)
	{
		scanf("%s", inputstr);
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = inputstr[j] - '0';
			if (board[i][j] > 0)
			{
				row[board[i][j]][i] = 1;
				col[board[i][j]][j] = 1;
				block[board[i][j]][blocknum(i, j)] = 1;
			}
		}
	}
}

void solution(int a)
{
	for (int i = a; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				for (int k = 1; k <= 9; k++)
				{
					if (!row[k][i] && !col[k][j] && !block[k][blocknum(i, j)])
					{
						board[i][j] = k;
						row[board[i][j]][i] = 1;
						col[board[i][j]][j] = 1;
						block[board[i][j]][blocknum(i, j)] = 1;

						solution(i);
						if (solved)
							return;

						row[board[i][j]][i] = 0;
						col[board[i][j]][j] = 0;
						block[board[i][j]][blocknum(i, j)] = 0;
						board[i][j] = 0;
					}
					if (k == 9)
						return;
				}
			}
			else if(i == 8 && j == 8)
			{
				solved = true;
				return;
			}
		}
	}
}

int main()
{
	getInput();

	solved = false;
	solution(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d", board[i][j]);
		printf("\n");
	}

	return 0;
}