#include <iostream>
using namespace std;

char video[64][65];

bool oneColor(int x, int y, int size)
{
	char color = video[x][y];
	bool result = true;
	int curX, curY;
	curX = x + size - 1;
	while (result && curX >= x)
	{
		curY = y + size - 1;
		while (result && curY >= y)
		{
			if (color != video[curX][curY])
				result = false;
			curY--;
		}
		curX--;
	}
	
	return result;
}

void quad(int x, int y, int size)
{
	printf("(");

	int dx[4] = { x, x, x + size, x + size };
	int dy[4] = { y, y + size, y, y + size };

	for (int i = 0; i < 4; i++)
	{
		int nextx = dx[i];
		int nexty = dy[i];
		if (oneColor(nextx, nexty, size))
			printf("%c", video[nextx][nexty]);
		else
			quad(nextx, nexty, size / 2);
	}

	printf(")");
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();
		scanf("%s", &video[i]);
	}

	if (!oneColor(0, 0, N))
		quad(0, 0, N / 2);
	else
		printf("%c", video[0][0]);
}