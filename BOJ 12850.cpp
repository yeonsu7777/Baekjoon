#include <iostream>
#include <stack>
#define TOOBIG 1000000007
#define ll long long
using namespace std;

ll route[8][8] = {
	{0, 1, 0, 1, 0, 0, 0, 0},	//13
	{1, 0, 1, 1, 0, 0, 0, 0},	//023
	{0, 1, 0, 1, 1, 1, 0, 0},	//1345
	{1, 1, 1, 0, 0, 1, 0, 0},	//0125
	{0, 0, 1, 0, 0, 1, 1, 0},	//256
	{0, 0, 1, 1, 1, 0, 0, 1},	//2347
	{0, 0, 0, 0, 1, 0, 0, 1},	//47
	{0, 0, 0, 0, 0, 1, 1, 0} };	//56

ll result[8][8];
ll tmp[8][8];
stack<int> mtype;

void solve()
{
	while (!mtype.empty())
	{
		if (mtype.top() == 0) //result * result
		{
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
				{
					tmp[i][j] = result[i][j];
					result[i][j] = 0;
				}

			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					for (int k = 0; k < 8; k++)
					{
						result[i][j] += tmp[i][k] * tmp[k][j];
						if (result[i][j] > TOOBIG)
							result[i][j] %= TOOBIG;
					}
		}
		else
		{
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
				{
					tmp[i][j] = result[i][j];
					result[i][j] = 0;
				}

			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					for (int k = 0; k < 8; k++)
					{
						result[i][j] += tmp[i][k] * route[k][j];
						if (result[i][j] > TOOBIG)
							result[i][j] %= TOOBIG;
					}
		}
		mtype.pop();
	}
}

int main()
{
	int D;
	scanf("%d", &D);

	int tmpD = D;

	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			result[i][j] = route[i][j];
		}
	while (tmpD > 1)
	{
		if (tmpD % 2)
		{
			mtype.push(1);
			tmpD--;
		}
		else
		{
			mtype.push(0);
			tmpD /= 2;
		}
	}

	solve();

	printf("%lld", result[0][0]);
	return 0;
}