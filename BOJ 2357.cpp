#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N, M;
int a, b;
ll arr[1000001];
vector<pair<ll, ll>> ST;
ll minResult, maxResult;

void getInput()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
}

void insertST(int idx, int l, int r)
{
	if (l == r)
	{
		ST[idx].first = ST[idx].second = arr[l];
		return;
	}

	int mid = l + (r - l) / 2;
	insertST(idx * 2, l, mid);
	insertST(idx * 2 + 1, mid + 1, r);

	ST[idx].first = min(ST[idx * 2].first, ST[idx * 2 + 1].first);
	ST[idx].second = max(ST[idx * 2].second, ST[idx * 2 + 1].second);
}

void makeST()
{
	int lvl = 0;
	while (N > (1 << lvl))
		lvl++;

	for (int i = 0; i < (1 << (lvl + 1)); i++)
	{
		ST.push_back({ 0,0 });
	}

	insertST(1, 0, N - 1);
	return;
}

void getResult(int idx, int l, int r) //l과r은 ST의 범위, b와c가 찾는 범위
{
	if (a <= l && r <= b)
	{
		minResult = min(minResult, ST[idx].first);
		maxResult = max(maxResult, ST[idx].second);
		return;
	}

	int mid = l + (r - l) / 2;
	if (mid >= a)
		getResult(idx * 2, l, mid);
	if (mid + 1 <= b)
		getResult(idx * 2 + 1, mid + 1, r);
}

int main()
{
	getInput();
	makeST();

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		maxResult = 0;
		minResult = 1000000001;
		a--;
		b--;
		getResult(1, 0, N-1);
		printf("%lld %lld\n", minResult, maxResult);
	}

	return 0;
}