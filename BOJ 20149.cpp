#include <iostream>
#define ll long long
using namespace std;

ll x[4], y[4];
ll dx[4][2], dy[4][2];
ll calc[4];

ll cross(ll line, ll dot)
{
	ll a = x[line];
	ll b = y[line];
	ll c = x[line + 1];
	ll d = y[line + 1];

	ll nX = x[dot];
	ll nY = y[dot];

	ll calcu = (d - b) * (nX - a) - (c - a) * (nY - b);

	if (calcu > 0)
		return 1;
	else if (calcu == 0)
		return 0;
	else
		return -1;
}

bool parallel(ll arr[][2]) //평행한지 확인
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			if (arr[i][j] != 0)
				return false;
	return true;
}

void overlap()
{
	int line[4][2] = { {2, 3}, {2, 3}, {0, 1}, {0, 1} };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dx[i][j] = x[i] - x[line[i][j]];
			dy[i][j] = y[i] - y[line[i][j]];
		}
	}

	if (!parallel(dx)) //x축이 평행하지 않을 때
	{
		//x들로 비교
		for (int i = 0; i < 4; i++)
		{
			if (dx[i][0] * dx[i][1] > 0)
				calc[i] = 1;
			else if (dx[i][0] * dx[i][1] == 0)
				calc[i] = 0;
			else
				calc[i] = -1;
		}
	}
	else //x축이 평행할 때
	{
		//y들로 비교
		for (int i = 0; i < 4; i++)
		{
			if (dy[i][0] * dy[i][1] > 0)
				calc[i] = 1;
			else if (dy[i][0] * dy[i][1] == 0)
				calc[i] = 0;
			else
				calc[i] = -1;
		}
	}

	if (calc[0] * calc[1] == 0) //똑같은 좌표가 있는 경우
	{
		printf("1\n");
		if (calc[0] == 0 && calc[1] == 0) //선분이 완전 똑같은 경우
			return;
		else
		{
			ll tmp = 1;
			for (int i = 0; i < 4; i++)
			{
				if (calc[i] == 0)
					continue;
				else
					tmp *= calc[i];
			}
			if (tmp == -1) //한 선분이 다른 선분 위에 겹쳐진 경우
				return;
			else //한 점에서만 만난 경우
			{
				if (calc[0] == 0)
					printf("%d %d", x[0], y[0]);
				else
					printf("%d %d", x[1], y[1]);
			}
		}
	}

	else if (calc[0] == 1 && calc[1] == 1 && calc[2] == 1 && calc[3] == 1)
	{
		printf("0");
	}
	else
		printf("1");

	return;
}

int main()
{
	for (int i = 0; i < 4; i++)
		scanf("%lld %lld", &x[i], &y[i]);

	ll a = cross(2, 0);
	ll b = cross(2, 1);
	ll c = cross(0, 2);
	ll d = cross(0, 3);

	ll result[4] = { a, b, c, d };

	if (a * b == 1 || c * d == 1)	// 전혀 만나지 않는 경우
		printf("0");

	else if (a * b == 0 || c * d == 0)
	{
		if (a == 0 && b == 0)	// 직선이 완전 겹치는 경우
		{
			overlap();
		}
		else //한 점이 겹치는 경우
		{
			printf("1\n");
			for (int i = 0; i < 4; i++)
				if (result[i] == 0)
				{
					printf("%d %d", x[i], y[i]);
					break;
				}
		}
	}
	else //완전히 한 점에서 만나는 경우
	{
		printf("1\n");
		double a0 = y[1] - y[0];
		double a1 = y[3] - y[2];

		double b0 = x[0] - x[1];
		double b1 = x[2] - x[3];

		double c0 = a0 * x[0] + b0 * y[0];
		double c1 = a1 * x[2] + b1 * y[2];

		double determ = a0 * b1 - a1 * b0;
		double resultX = (c0 * b1 - c1 * b0) / determ;
		double resultY = (c1 * a0 - c0 * a1) / determ;

		printf("%.12g %.12g", resultX, resultY);
	}

	return 0;
}