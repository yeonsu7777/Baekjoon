#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N, M, K;
ll a, b, c;
ll arr[1000001];
int arrIdx[1000001];
vector<ll> ST;
ll result;

void getInput()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
}

void insertST(int idx, int l, int r)
{
	if (l == r)
	{
		ST[idx] = arr[l];
		arrIdx[l] = idx;
		return;
	}

	int mid = l + (r - l) / 2;
	insertST(idx * 2, l, mid);
	insertST(idx * 2 + 1, mid + 1, r);
	
	ST[idx] = ST[idx * 2] + ST[idx * 2 + 1];
}

void makeST()
{
	int lvl = 0;
	while (N > (1 << lvl))
		lvl++;

	for (int i = 0; i < (1 << (lvl + 1)); i++)
	{
		ST.push_back(0);
	}

	insertST(1, 0, N - 1);
	return;
}

void getSum(int idx, int l, int r) //l과r은 ST의 범위, b와c가 찾는 범위
{
	if (b <= l && r <= c)
	{
		result += ST[idx];
		return;
	}

	int mid = l + (r - l) / 2;
	if (mid >= b)
		getSum(idx * 2, l, mid);
	if (mid+1 <= c)
		getSum(idx * 2 + 1, mid + 1, r);
}

int main()
{
	getInput();
	makeST();

	for (int i = 0; i < (M + K); i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
		{
			int updateIdx = arrIdx[b - 1];
			ll diff = c - ST[updateIdx];
			// update
			while (updateIdx > 0)
			{
				ST[updateIdx] += diff;
				updateIdx /= 2;
			}
		}
		else
		{
			// getSum
			result = 0;
			b--;
			c--;
			getSum(1, 0, N - 1);
			printf("%lld\n", result);
		}
	}

	return 0;
}