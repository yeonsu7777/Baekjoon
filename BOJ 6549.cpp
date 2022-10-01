#include <iostream>
#include <vector>
#define ll long long
#define MAXH 1000000005
using namespace std;
/*
int N, M, K;
ll a, b, c;
ll arr[1000001];
int arrIdx[1000001];
vector<ll> ST;
ll result;
*/
int n;
ll arr[100001];
vector<ll> ST;
ll result;

void insertST(int idx, int l, int r)
{
	if (l == r)
	{
		ST[idx] = arr[l];
		return;
	}

	int mid = l + (r - l) / 2;
	insertST(idx * 2, l, mid);
	insertST(idx * 2 + 1, mid + 1, r);

	ST[idx] = ST[idx * 2] < ST[idx * 2 + 1] ? ST[idx * 2] : ST[idx * 2 + 1];
}

void makeST()
{
	int lvl = 0;
	while (n > (1 << lvl))
		lvl++;

	for (int i = 0; i < (1 << (lvl + 1)); i++)
	{
		ST.push_back(MAXH);
	}

	insertST(1, 0, n - 1);
	return;
}

ll getW(int idx, int f, int l, int r)
{
	if (arr[f] == ST[idx])
	{
		return (r - l + 1);
	}

	int mid = l + (r - l) / 2;
	if (f <= mid)
		return getW(idx * 2, f, l, mid);
	else
		return getW(idx * 2 + 1, f, mid + 1, r);
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	makeST();

	for (int i = 0; i < n; i++)
	{
		arr[i] *= getW(1, i, 0, n - 1);
		result = result > arr[i] ? result : arr[i];
	}

	printf("%lld\n", result);
}

int main()
{
	scanf("%d", &n);
	while (n != 0)
	{
		ST.clear();
		result = 0;
		solve();
		scanf("%lld", &n);
	}
}