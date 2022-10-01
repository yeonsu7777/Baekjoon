#include <iostream>
using namespace std;

int power[5][5] = {
	{1, 2, 2, 2, 2},
	{2, 1, 3, 4, 3},
	{2, 3, 1, 3, 4},
	{2, 4, 3, 1, 3},
	{2, 3, 4, 3, 1} };

int oldidx, newidx;
int DDR[2][5][5];
int step;

void initDDR()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			DDR[newidx][i][j] = 0;
}

void solve()
{
	initDDR();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (DDR[oldidx][i][j])
			{
				if (DDR[newidx][step][j] == 0)
					DDR[newidx][step][j] = DDR[oldidx][i][j] + power[i][step];
				else if (DDR[newidx][step][j] > DDR[oldidx][i][j] + power[i][step])
					DDR[newidx][step][j] = DDR[oldidx][i][j] + power[i][step];

				if (DDR[newidx][j][step] == 0)
					DDR[newidx][j][step] = DDR[oldidx][j][i] + power[step][i];
				else if (DDR[newidx][j][step] > DDR[oldidx][j][i] + power[step][i])
					DDR[newidx][j][step] = DDR[oldidx][j][i] + power[step][i];
			}
		}
	}

	oldidx = newidx;
	newidx = 1 - oldidx;
}
int main()
{
	scanf("%d", &step);
	DDR[0][0][step] = 2;
	DDR[0][step][0] = 2;
	oldidx = 0;
	newidx = 1;

	scanf("%d", &step);
	while (step != 0)
	{
		solve();
		scanf("%d", &step);
	}

	int result = 400000;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			if (DDR[oldidx][i][j])
				if (result > DDR[oldidx][i][j])
					result = DDR[oldidx][i][j];
	}
	printf("%d", result);
	return 0;
}