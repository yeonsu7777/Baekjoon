#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int set[1001];
vector<vector<int>> lines;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a[2] < b[2];
}

void init_set(int N)
{
	for (int i = 1; i <= N; i++)
		set[i] = i;
}

int find_set(int a)
{
	if (set[a] == a)
		return a;
	else
		return set[a] = find_set(set[a]);
}

void union_set(int a, int b)
{
	int aRoot = find_set(a);
	int bRoot = find_set(b);
	set[aRoot] = bRoot;
}

bool check(int a, int b)
{
	return find_set(a) == find_set(b);
}

int main()
{
	int N, M;
	int result = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		vector<int> tmp;
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tmp = { a, b, c };
		lines.push_back(tmp);
	}

	sort(lines.begin(), lines.end(), cmp);

	init_set(N);

	for (int i = 0; i < M; i++)
	{
		if (check(lines[i][0], lines[i][1]))
			continue;
		else
		{
			union_set(lines[i][0], lines[i][1]);
			result += lines[i][2];
		}
	}

	printf("%d", result);
}